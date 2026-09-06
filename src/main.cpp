#include "pacmanmanager.h"
#include "iconfetcher.h"
#include "log.h"
#include "package.h"
#include <QGuiApplication>
#include <QStandardPaths>
#include <QDir>
#include <QFile>
#include <algorithm>
#include <random>
#include "main.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    QDir cacheDir(QStandardPaths::writableLocation(QStandardPaths::CacheLocation) + "/icons");
    auto *iconFetcher = new IconFetcher(cacheDir, &app);
    auto *pacman = new PacmanManager(&app);

    auto ui = MainWindow::create();

    // Flat model (no more row grouping — Slint handles layout)
    auto pkgModel = std::make_shared<slint::VectorModel<UiPackage>>();
    ui->set_packages(pkgModel);

    auto refreshGrid = [ui, iconFetcher, cacheDir, pkgModel](const QVector<Package> &pkgs) {
        // Clear and rebuild
        while (pkgModel->row_count() > 0) pkgModel->erase(0);

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
        }
    };

    QObject::connect(pacman, &PacmanManager::resultsReady, refreshGrid);
    pacman->fetchDefaults();

    ui->on_search_changed([pacman](slint::SharedString q) {
        pacman->search(QString::fromStdString(std::string(q)));
    });

    ui->on_app_clicked([ui, pacman, pkgModel](UiPackage p) {
        ui->set_current_package(p);
        UiPackageDetails pd;
        pd.is_loading = true;
        ui->set_current_details(pd);

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

    QObject::connect(pacman, &PacmanManager::detailsReady, [ui](::PackageDetails cxxDetails) {
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

    // Pump Qt events from within Slint's event loop
    slint::Timer t;
    t.start(slint::TimerMode::Repeated, std::chrono::milliseconds(16), []() {
        QGuiApplication::processEvents();
    });

    ui->run();
    return 0;
}