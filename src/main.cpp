#include "pacmanmanager.h"
#include "iconfetcher.h"
#include "installmanager.h"
#include "log.h"
#include "package.h"
#include <QGuiApplication>
#include <QStandardPaths>
#include <QDir>
#include <QFile>
#include <QHash>
#include <algorithm>
#include <random>
#include <QDesktopServices>
#include <QUrl>
#include <QtConcurrent>
#include <QFutureWatcher>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QDir>
#include <map>
#include "main.h"

struct SpecialCaseInfo {
    bool has_addons = false;
    QString type_name;
    std::vector<std::pair<QString, QString>> items;
};

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    std::map<QString, SpecialCaseInfo> packageAddons;
    std::map<QString, QString> addonToPackage;

    QDir dir("special_case_packages");
    if (dir.exists()) {
        for (const QFileInfo &fi : dir.entryInfoList({"*.json"}, QDir::Files)) {
            QFile file(fi.absoluteFilePath());
            if (file.open(QIODevice::ReadOnly)) {
                QJsonDocument doc = QJsonDocument::fromJson(file.readAll());
                if (doc.isObject()) {
                    QJsonObject obj = doc.object();
                    QString pkgName = obj.value("package").toString();
                    if (pkgName.isEmpty()) pkgName = fi.baseName();
                    
                    SpecialCaseInfo info;
                    info.has_addons = true;
                    if (obj.contains("language_packs")) {
                        info.type_name = "Language Packs";
                        QJsonObject packs = obj.value("language_packs").toObject();
                        for (auto it = packs.begin(); it != packs.end(); ++it) {
                            info.items.push_back({it.key(), it.value().toString()});
                            addonToPackage[it.value().toString()] = pkgName;
                        }
                    } else if (obj.contains("addons")) {
                        info.type_name = "Addons";
                        QJsonObject addons = obj.value("addons").toObject();
                        for (auto it = addons.begin(); it != addons.end(); ++it) {
                            info.items.push_back({it.key(), it.value().toString()});
                            addonToPackage[it.value().toString()] = pkgName;
                        }
                    }
                    packageAddons[pkgName] = info;
                }
            }
        }
    }

    QDir cacheDir(QStandardPaths::writableLocation(QStandardPaths::CacheLocation) + "/icons");
    auto *iconFetcher = new IconFetcher(cacheDir, &app);
    auto *pacman = new PacmanManager(&app);
    auto *installManager = new InstallManager(&app);

    // Kept around so the install click handler can compute per-package
    // sizes (new deps + the app itself) to weight the progress bar.
    auto lastDetails = std::make_shared<PackageDetails>();
    auto consoleLog = std::make_shared<QString>();

    auto ui = MainWindow::create();

    auto pkgModel = std::make_shared<slint::VectorModel<UiPackage>>();
    auto forYouModel = std::make_shared<slint::VectorModel<UiPackage>>();
    auto browsersModel = std::make_shared<slint::VectorModel<UiPackage>>();
    auto designModel = std::make_shared<slint::VectorModel<UiPackage>>();
    auto utilitiesModel = std::make_shared<slint::VectorModel<UiPackage>>();
    auto devModel = std::make_shared<slint::VectorModel<UiPackage>>();
    auto officeModel = std::make_shared<slint::VectorModel<UiPackage>>();
    auto communicationModel = std::make_shared<slint::VectorModel<UiPackage>>();
    
    ui->set_packages(pkgModel);
    ui->set_for_you(forYouModel);
    ui->set_browsers(browsersModel);
    ui->set_design(designModel);
    ui->set_utilities(utilitiesModel);
    ui->set_dev(devModel);
    ui->set_office(officeModel);
    ui->set_communication(communicationModel);

    auto refreshGrid = [ui, iconFetcher, cacheDir, pkgModel, forYouModel, browsersModel, designModel, utilitiesModel, devModel, officeModel, communicationModel](const QVector<Package> &pkgs) {
        while (pkgModel->row_count() > 0) pkgModel->erase(0);
        
        bool isDefault = ui->get_search_query().empty();
        if (isDefault) {
            while (forYouModel->row_count() > 0) forYouModel->erase(0);
            while (browsersModel->row_count() > 0) browsersModel->erase(0);
            while (designModel->row_count() > 0) designModel->erase(0);
            while (utilitiesModel->row_count() > 0) utilitiesModel->erase(0);
            while (devModel->row_count() > 0) devModel->erase(0);
            while (officeModel->row_count() > 0) officeModel->erase(0);
            while (communicationModel->row_count() > 0) communicationModel->erase(0);
        }

        for (const auto &p : pkgs) {
            UiPackage sp;
            sp.name = slint::SharedString(p.name.toStdString());
            sp.pretty_name = slint::SharedString(prettifyName(p.name).toStdString());
            sp.repo = slint::SharedString(p.repo.toStdString());
            sp.version = slint::SharedString(p.version.toStdString());
            sp.description = slint::SharedString(p.description.toStdString());
            sp.installed = p.installed;

            QString cachedPath = cacheDir.filePath(p.name + ".svg");
            if (!QFile::exists(cachedPath)) cachedPath = cacheDir.filePath(p.name + ".png");
            if (QFile::exists(cachedPath)) {
                sp.icon = slint::Image::load_from_path(slint::SharedString(cachedPath.toStdString()));
            } else {
                iconFetcher->request(QString::fromStdString(std::string(sp.name)), 64);
            }

            pkgModel->push_back(sp);
            
            if (isDefault) {
                QString n = p.name.toLower();
                if (n == "firefox" || n == "chromium" || n == "epiphany" || n == "falkon" || n == "qutebrowser" || n == "midori" || n == "brave-browser" || n == "torbrowser-launcher" || n == "vivaldi" || n == "opera") {
                    browsersModel->push_back(sp);
                } else if (n == "blender" || n == "gimp" || n == "kdenlive" || n == "audacity" || n == "inkscape" || n == "krita" || n == "obs-studio" || n == "vlc" || n == "shotcut" || n == "pitivi" || n == "flowblade" || n == "openshot") {
                    designModel->push_back(sp);
                } else if (n == "htop" || n == "neovim" || n == "kitty" || n == "timeshift" || n == "alacritty" || n == "bleachbit" || n == "gparted" || n == "flameshot") {
                    utilitiesModel->push_back(sp);
                } else if (n == "python" || n == "gcc" || n == "base-devel" || n == "rust" || n == "code" || n == "vscodium" || n == "nodejs" || n == "go" || n == "docker" || n == "git") {
                    devModel->push_back(sp);
                } else if (n == "libreoffice-fresh" || n == "libreoffice-still" || n == "onlyoffice-bin" || n == "abiword" || n == "gnumeric" || n == "calligra" || n == "wps-office") {
                    officeModel->push_back(sp);
                } else if (n == "telegram-desktop" || n == "discord" || n == "session-desktop" || n == "session-desktop-bin" || n == "signal-desktop" || n == "element-desktop" || n == "skypeforlinux" || n == "slack-desktop") {
                    communicationModel->push_back(sp);
                } else {
                    forYouModel->push_back(sp);
                }
            }
        }
    };

    QObject::connect(pacman, &PacmanManager::resultsReady, refreshGrid);
    pacman->fetchDefaults();

    ui->on_search_changed([ui, pacman, pkgModel](slint::SharedString q) {
        while (pkgModel->row_count() > 0) pkgModel->erase(0);
        if (q.empty()) {
            pacman->fetchDefaults();
        } else {
            pacman->search(QString::fromStdString(std::string(q)));
        }
    });

    ui->on_app_clicked([ui, pacman, pkgModel, packageAddons, addonToPackage](UiPackage p) {
        ui->set_current_package(p);
        UiPackageDetails pd;
        pd.is_loading = true;
        ui->set_current_details(pd);

        UiInstallState ist;
        ist.is_installing = false;
        ist.is_uninstalling = false;
        ist.finished = false;
        ist.success = false;
        ist.progress = 0.0f;
        ist.deps_ratio = 0.0f;
        ist.console_log = slint::SharedString("");
        ui->set_current_install(ist);

        QString pName = QString::fromStdString(std::string(p.name));
        UiSpecialCase sc;
        sc.is_special = false;
        sc.type_name = slint::SharedString("");
        sc.is_addon_for = slint::SharedString("");

        if (packageAddons.count(pName)) {
            const auto &info = packageAddons.at(pName);
            sc.is_special = true;
            sc.type_name = slint::SharedString(info.type_name.toStdString());
            std::vector<UiAddon> items;
            for (const auto &item : info.items) {
                UiAddon addon;
                addon.name = slint::SharedString(item.first.toStdString());
                addon.pkg_name = slint::SharedString(item.second.toStdString());
                items.push_back(addon);
            }
            sc.items = std::make_shared<slint::VectorModel<UiAddon>>(items);
        }

        if (addonToPackage.count(pName)) {
            sc.is_addon_for = slint::SharedString(addonToPackage.at(pName).toStdString());
        }

        ui->set_current_special_case(sc);

        // Build a small "You might also like" shelf: a random sample of
        // other packages from whatever is currently loaded in the grid,
        // excluding the package being viewed.
        std::vector<UiPackage> pool;
        for (size_t i = 0; i < pkgModel->row_count(); ++i) {
            auto candidate = pkgModel->row_data(i);
            if (candidate && candidate->name != p.name) pool.push_back(*candidate);
        }
        static std::mt19937 rng(std::random_device{}());
        std::shuffle(pool.begin(), pool.end(), rng);
        const size_t suggestionCount = std::min<size_t>(8, pool.size());
        auto suggestionsModel = std::make_shared<slint::VectorModel<UiPackage>>(
            std::vector<UiPackage>(pool.begin(), pool.begin() + suggestionCount));
        ui->set_current_suggestions(suggestionsModel);

        ui->set_is_showing_details(true);
        pacman->fetchDetails(QString::fromStdString(std::string(p.name)));
    });

    ui->on_back_clicked([ui]() {
        ui->set_is_showing_details(false);
    });

    ui->on_addon_clicked([ui, iconFetcher](slint::SharedString pkgNameStr) {
        QString pkgName = QString::fromStdString(std::string(pkgNameStr));
        QFutureWatcher<Package> *watcher = new QFutureWatcher<Package>();
        QObject::connect(watcher, &QFutureWatcher<Package>::finished, [ui, watcher, iconFetcher]() {
            Package p = watcher->result();
            UiPackage uip;
            uip.name = slint::SharedString(p.name.toStdString());
            uip.pretty_name = slint::SharedString(prettifyName(p.name).toStdString());
            uip.repo = slint::SharedString(p.repo.toStdString());
            uip.version = slint::SharedString(p.version.toStdString());
            uip.description = slint::SharedString(p.description.toStdString());
            uip.installed = p.installed;
            
            ui->invoke_app_clicked(uip);
            iconFetcher->request(p.name, 64);
            watcher->deleteLater();
        });
        watcher->setFuture(QtConcurrent::run([pkgName]() {
            return PacmanManager::getPackageExact(pkgName);
        }));
    });

    ui->on_open_url([](slint::SharedString repo_slint, slint::SharedString name_slint) {
        QString repo = QString::fromStdString(std::string(repo_slint));
        QString name = QString::fromStdString(std::string(name_slint));
        
        QString url;
        QStringList officialRepos = {"core", "extra", "multilib", "testing", "core-testing", "extra-testing", "multilib-testing"};
        
        if (officialRepos.contains(repo)) {
            url = QString("https://archlinux.org/packages/%1/x86_64/%2/").arg(repo, name);
        } else if (repo.contains("aur") || repo == "chaotic-aur") {
            url = QString("https://aur.archlinux.org/packages/%1").arg(name);
        } else {
            bool foundServer = false;
            QFile file("/etc/pacman.conf");
            if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
                QTextStream in(&file);
                bool inRepo = false;
                while (!in.atEnd()) {
                    QString line = in.readLine().trimmed();
                    if (line.startsWith("#")) continue;
                    
                    if (line.startsWith("[" + repo + "]")) {
                        inRepo = true;
                    } else if (line.startsWith("[")) {
                        inRepo = false;
                    } else if (inRepo && line.startsWith("Server")) {
                        QString server = line.section('=', 1).trimmed();
                        server.replace("$repo", repo);
                        server.replace("$arch", "x86_64");
                        url = server;
                        foundServer = true;
                        break;
                    }
                }
            }
            if (!foundServer) {
                url = QString("https://archlinux.org/packages/?q=%1").arg(name);
            }
        }
        
        QDesktopServices::openUrl(QUrl(url));
    });

    QObject::connect(pacman, &PacmanManager::detailsReady, [ui, lastDetails](::PackageDetails cxxDetails) {
        *lastDetails = cxxDetails; // remember for the install click handler

        UiPackageDetails sd;
        sd.is_loading = false;
        sd.app_size_str = slint::SharedString(formatSize(cxxDetails.appSizeBytes).toStdString());
        sd.installed_deps_size_str = slint::SharedString(formatSize(cxxDetails.installedDepsBytes).toStdString());
        sd.new_deps_size_str = slint::SharedString(formatSize(cxxDetails.newDepsBytes).toStdString());
        sd.download_size_str = slint::SharedString(formatSize(cxxDetails.downloadBytes).toStdString());

        // Mirrors pacman's own "Total Download Size / Total Installed Size /
        // Net Upgrade Size" transaction summary.
        sd.total_download_str = slint::SharedString(formatSize(cxxDetails.totalDownloadBytes).toStdString());
        sd.total_installed_str = slint::SharedString(formatSize(cxxDetails.totalInstalledBytes).toStdString());
        const QString netSign = cxxDetails.netUpgradeBytes < 0 ? QStringLiteral("-") : QStringLiteral("+");
        sd.net_upgrade_str = slint::SharedString(
            (netSign + formatSize(qAbs(cxxDetails.netUpgradeBytes))).toStdString());

        // Proportions for the 3-color breakdown bar, based on the real total
        // footprint (already-installed deps + new deps + the app itself).
        const long long total = cxxDetails.totalBytes;
        if (total > 0) {
            sd.installed_ratio = static_cast<float>(cxxDetails.installedDepsBytes) / static_cast<float>(total);
            sd.new_ratio = static_cast<float>(cxxDetails.newDepsBytes) / static_cast<float>(total);
            sd.app_ratio = static_cast<float>(cxxDetails.appSizeBytes) / static_cast<float>(total);
        } else {
            sd.installed_ratio = 0.0f;
            sd.new_ratio = 0.0f;
            sd.app_ratio = 1.0f;
        }

        std::vector<UiPackageDependency> deps;
        for (const auto &d : cxxDetails.dependencies) {
            UiPackageDependency pd;
            pd.name = slint::SharedString(d.name.toStdString());
            pd.size_str = slint::SharedString(formatSize(d.sizeBytes).toStdString());
            pd.installed = d.installed;
            deps.push_back(pd);
        }
        auto depsModel = std::make_shared<slint::VectorModel<UiPackageDependency>>(deps);
        sd.dependencies = depsModel;

        ui->set_current_details(sd);
    });

    // Icon ready -> update flat model
    QObject::connect(iconFetcher, &IconFetcher::iconReady, [ui, pkgModel](QString appName, QString diskPath) {
        auto img = slint::Image::load_from_path(slint::SharedString(diskPath.toStdString()));
        auto nameStr = slint::SharedString(appName.toStdString());

        // Update in the flat grid model
        for (size_t i = 0; i < pkgModel->row_count(); ++i) {
            auto pkg = pkgModel->row_data(i);
            if (pkg && pkg->name == nameStr) {
                auto copy = *pkg;
                copy.icon = img;
                pkgModel->set_row_data(i, copy);
                break;
            }
        }

        // Also update the current details view package if it matches
        auto current = ui->get_current_package();
        if (current.name == nameStr) {
            current.icon = img;
            ui->set_current_package(current);
        }
    });

    // ------------------------------------------------------------------
    // Install flow: pacman -S (elevated via pkexec unless already root),
    // weighted progress bar (new deps in blue, the app itself in mauve,
    // not-yet-downloaded in grey), and a raw console view.
    // ------------------------------------------------------------------
    ui->on_install_clicked([ui, installManager, lastDetails](UiPackage p) {
        if (p.installed) return;

        QHash<QString, long long> sizes;
        for (const auto &d : lastDetails->dependencies) {
            if (!d.installed) sizes.insert(d.name, d.sizeBytes);
        }
        const QString pkgName = QString::fromStdString(std::string(p.name));
        sizes.insert(pkgName, lastDetails->appSizeBytes);

        UiInstallState st = ui->get_current_install();
        st.is_installing = true;
        st.is_uninstalling = false;
        st.finished = false;
        st.success = false;
        st.progress = 0.0f;
        const long long total = lastDetails->newDepsBytes + lastDetails->appSizeBytes;
        st.deps_ratio = total > 0 ? float(double(lastDetails->newDepsBytes) / double(total)) : 0.0f;
        st.console_log = slint::SharedString("");
        ui->set_current_install(st);

        installManager->install(pkgName, sizes);
    });

    ui->on_remove_clicked([ui, installManager](UiPackage p, slint::SharedString mode) {
        if (!p.installed) return;
        
        const QString pkgName = QString::fromStdString(std::string(p.name));
        const QString modeStr = QString::fromStdString(std::string(mode));

        UiInstallState st = ui->get_current_install();
        st.is_installing = false;
        st.is_uninstalling = true;
        st.finished = false;
        st.success = false;
        st.progress = 0.0f;
        st.deps_ratio = 0.0f;
        st.console_log = slint::SharedString("");
        ui->set_current_install(st);

        installManager->uninstall(pkgName, modeStr);
    });

    QObject::connect(installManager, &InstallManager::started, [consoleLog]() {
        consoleLog->clear();
    });

    QObject::connect(installManager, &InstallManager::consoleOutput, [ui, consoleLog](QString text) {
        *consoleLog += text;
        if (consoleLog->size() > 200000) *consoleLog = consoleLog->right(200000);
        UiInstallState st = ui->get_current_install();
        st.console_log = slint::SharedString(consoleLog->toStdString());
        ui->set_current_install(st);
    });

    QObject::connect(installManager, &InstallManager::progressChanged, [ui](double frac) {
        UiInstallState st = ui->get_current_install();
        st.progress = float(frac);
        ui->set_current_install(st);
    });

    QObject::connect(installManager, &InstallManager::finished, [ui, pkgModel](bool success, int) {
        UiInstallState st = ui->get_current_install();
        bool was_uninstalling = st.is_uninstalling;
        st.is_installing = false;
        st.finished = true;
        st.success = success;
        if (success) st.progress = 1.0f;
        ui->set_current_install(st);

        if (success) {
            UiPackage cur = ui->get_current_package();
            cur.installed = !was_uninstalling;
            ui->set_current_package(cur);
            for (size_t i = 0; i < pkgModel->row_count(); ++i) {
                auto row = pkgModel->row_data(i);
                if (row && row->name == cur.name) {
                    auto copy = *row;
                    copy.installed = !was_uninstalling;
                    pkgModel->set_row_data(i, copy);
                    break;
                }
            }
        }
    });

    QStringList args = app.arguments();
    if (args.size() == 3 && args[1] == "openpackage") {
        ui->invoke_addon_clicked(slint::SharedString(args[2].toStdString()));
    }

    // Pump Qt events from within Slint's event loop
    slint::Timer t;
    t.start(slint::TimerMode::Repeated, std::chrono::milliseconds(16), []() {
        QGuiApplication::processEvents();
    });

    ui->run();
    return 0;
}