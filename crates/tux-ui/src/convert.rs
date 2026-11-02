//! Bus types → Slint structs (and back).

use crate::{UiAddon, UiPackage, UiPackageDependency, UiPackageDetails, UiSpecialCase, UiUpdate};
use slint::{Image, ModelRc, VecModel};
use tux_abi::text::{format_size, prettify_name};
use tux_abi::{Package, PackageDetails, SpecialCase, UpdateEntry};

pub fn to_ui(p: &Package, icon: Option<&Image>) -> UiPackage {
    let pretty = prettify_name(&p.name);
    UiPackage {
        name: p.name.as_str().into(),
        pretty_name: pretty.as_str().into(),
        repo: p.repo.as_str().into(),
        version: p.version.as_str().into(),
        description: p.description.as_str().into(),
        installed: p.installed,
        icon: icon.cloned().unwrap_or_default(),
        is_same_name: pretty.to_lowercase() == p.name.to_lowercase(),
    }
}

pub fn from_ui(p: &UiPackage) -> Package {
    Package {
        name: p.name.to_string(),
        repo: p.repo.to_string(),
        version: p.version.to_string(),
        description: p.description.to_string(),
        installed: p.installed,
    }
}

pub fn details(d: &PackageDetails) -> UiPackageDetails {
    let total = d.total_footprint() as f32;
    let (installed_ratio, new_ratio, app_ratio) = if total > 0.0 {
        (d.installed_deps as f32 / total, d.new_deps as f32 / total, d.app_size as f32 / total)
    } else {
        (0.0, 0.0, 1.0)
    };
    let deps: Vec<UiPackageDependency> = d
        .dependencies
        .iter()
        .map(|x| UiPackageDependency {
            name: x.name.as_str().into(),
            size_str: format_size(x.size_bytes).into(),
            installed: x.installed,
        })
        .collect();
    UiPackageDetails {
        app_size_str: format_size(d.app_size).into(),
        dependencies: ModelRc::new(VecModel::from(deps)),
        installed_deps_size_str: format_size(d.installed_deps).into(),
        new_deps_size_str: format_size(d.new_deps).into(),
        download_size_str: format_size(d.total_download).into(),
        installed_ratio,
        new_ratio,
        app_ratio,
        total_download_str: format_size(d.total_download).into(),
        total_installed_str: format_size(d.total_installed).into(),
        net_upgrade_str: if d.net_upgrade == 0 {
            "0 B".into()
        } else {
            format!("+{}", format_size(d.net_upgrade)).into()
        },
        is_loading: false,
        plan_ok: d.plan_ok,
    }
}

pub fn special(s: Option<SpecialCase>) -> UiSpecialCase {
    let Some(sc) = s else {
        return UiSpecialCase::default();
    };
    let items: Vec<UiAddon> = sc
        .items
        .iter()
        .map(|a| UiAddon { name: a.label.as_str().into(), pkg_name: a.package.as_str().into() })
        .collect();
    UiSpecialCase {
        is_special: !items.is_empty(),
        type_name: sc.kind.as_str().into(),
        items: ModelRc::new(VecModel::from(items)),
        is_addon_for: sc.addon_for.unwrap_or_default().into(),
    }
}

pub fn update(u: &UpdateEntry) -> UiUpdate {
    UiUpdate {
        name: u.name.as_str().into(),
        old_version: u.old_version.as_str().into(),
        new_version: u.new_version.as_str().into(),
    }
}
