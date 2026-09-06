// This file is auto-generated
#pragma once
#include <array>
#include <limits>
#include <slint.h>
#include <cmath>
static_assert(1 == SLINT_VERSION_MAJOR && 17 == SLINT_VERSION_MINOR && 0 == SLINT_VERSION_PATCH, "This file was generated with Slint compiler version 1.17.0, but the Slint library used is " SLINT_VERSION_STRING ". The version numbers must match exactly.");
class UiPackage {
    public:
    slint::SharedString name;
    slint::SharedString pretty_name;
    slint::SharedString repo;
    slint::SharedString version;
    slint::SharedString description;
    bool installed;
    slint::Image icon;
    friend auto operator== (const class UiPackage &a, const class UiPackage &b) -> bool = default;
};

class UiPackageDependency {
    public:
    slint::SharedString name;
    slint::SharedString size_str;
    bool installed;
    friend auto operator== (const class UiPackageDependency &a, const class UiPackageDependency &b) -> bool = default;
};

class UiPackageDetails {
    public:
    slint::SharedString app_size_str;
    std::shared_ptr<slint::Model<UiPackageDependency>> dependencies;
    slint::SharedString installed_deps_size_str;
    slint::SharedString new_deps_size_str;
    slint::SharedString download_size_str;
    bool is_loading;
    friend auto operator== (const class UiPackageDetails &a, const class UiPackageDetails &b) -> bool = default;
};

class MainWindow;

class SharedGlobals;

class AppCard_root_1;

class DepRow_root_14;

class SuggestionCard_root_20;

class DetailsView_root_32;

class Component_image_5 {
    public:
    slint::cbindgen_private::ItemTreeWeak self_weak;
    const class SharedGlobals* globals;
    uint32_t tree_index_of_first_child;
    uint32_t tree_index;
    vtable::VWeakMapped<slint::private_api::ItemTreeVTable, class AppCard_root_1 const> parent;
    slint::cbindgen_private::ImageItem field_image_5 = {};
    auto init (const class SharedGlobals* globals,slint::cbindgen_private::ItemTreeWeak enclosing_component,uint32_t tree_index,uint32_t tree_index_of_first_child,class AppCard_root_1 const *parent) -> void;
    auto user_init () -> void;
    auto layout_info (slint::cbindgen_private::Orientation o) const -> slint::cbindgen_private::LayoutInfo;
    auto item_geometry (uint32_t index) const -> slint::cbindgen_private::Rect;
    auto accessible_role (uint32_t index) const -> slint::cbindgen_private::AccessibleRole;
    auto accessible_string_property (uint32_t index, slint::cbindgen_private::AccessibleStringProperty what) const -> std::optional<slint::SharedString>;
    auto accessibility_action (uint32_t index, const slint::cbindgen_private::AccessibilityAction &action) const -> void;
    auto supported_accessibility_actions (uint32_t index) const -> uint32_t;
    auto element_infos (uint32_t index) const -> std::optional<slint::SharedString>;
    auto ensure_instantiated () const -> bool;
    private:
    static auto visit_children (slint::private_api::ItemTreeRef component, intptr_t index, slint::private_api::TraversalOrder order, slint::private_api::ItemVisitorRefMut visitor) -> uint64_t;
    static auto get_item_ref (slint::private_api::ItemTreeRef component, uint32_t index) -> slint::private_api::ItemRef;
    static auto get_subtree_range ([[maybe_unused]] slint::private_api::ItemTreeRef component, [[maybe_unused]] uint32_t dyn_index) -> slint::private_api::IndexRange;
    static auto get_subtree ([[maybe_unused]] slint::private_api::ItemTreeRef component, [[maybe_unused]] uint32_t dyn_index, [[maybe_unused]] uintptr_t subtree_index, [[maybe_unused]] slint::private_api::ItemTreeWeak *result) -> void;
    static auto get_item_tree (slint::private_api::ItemTreeRef) -> slint::cbindgen_private::Slice<slint::private_api::ItemTreeNode>;
    static auto parent_node ([[maybe_unused]] slint::private_api::ItemTreeRef component, [[maybe_unused]] slint::private_api::ItemWeak *result) -> void;
    static auto embed_component ([[maybe_unused]] slint::private_api::ItemTreeRef component, [[maybe_unused]] const slint::private_api::ItemTreeWeak *parent_component, [[maybe_unused]] const uint32_t parent_index) -> bool;
    static auto subtree_index ([[maybe_unused]] slint::private_api::ItemTreeRef component) -> uintptr_t;
    static auto item_tree () -> slint::cbindgen_private::Slice<slint::private_api::ItemTreeNode>;
    static auto item_array () -> const slint::private_api::ItemArray;
    static auto layout_info ([[maybe_unused]] slint::private_api::ItemTreeRef component, slint::cbindgen_private::Orientation o) -> slint::cbindgen_private::LayoutInfo;
    static auto ensure_instantiated ([[maybe_unused]] slint::private_api::ItemTreeRef component) -> bool;
    static auto item_geometry ([[maybe_unused]] slint::private_api::ItemTreeRef component, uint32_t index) -> slint::cbindgen_private::LogicalRect;
    static auto accessible_role ([[maybe_unused]] slint::private_api::ItemTreeRef component, uint32_t index) -> slint::cbindgen_private::AccessibleRole;
    static auto accessible_string_property ([[maybe_unused]] slint::private_api::ItemTreeRef component, uint32_t index, slint::cbindgen_private::AccessibleStringProperty what, slint::SharedString *result) -> bool;
    static auto accessibility_action ([[maybe_unused]] slint::private_api::ItemTreeRef component, uint32_t index, const slint::cbindgen_private::AccessibilityAction *action) -> void;
    static auto supported_accessibility_actions ([[maybe_unused]] slint::private_api::ItemTreeRef component, uint32_t index) -> uint32_t;
    static auto element_infos ([[maybe_unused]] slint::private_api::ItemTreeRef component, [[maybe_unused]] uint32_t index, [[maybe_unused]] slint::SharedString *result) -> bool;
    static auto window_adapter ([[maybe_unused]] slint::private_api::ItemTreeRef component, [[maybe_unused]] bool do_create, [[maybe_unused]] slint::cbindgen_private::Option<slint::private_api::WindowAdapterRc>* result) -> void;
    public:
    static const slint::private_api::ItemTreeVTable static_vtable;
    static auto create (class AppCard_root_1 const * parent) -> slint::ComponentHandle<Component_image_5>;
    ~Component_image_5 ();
    auto init () -> void;
    auto layout_item_info (slint::cbindgen_private::Orientation o, [[maybe_unused]] std::optional<size_t> child_index) const -> slint::cbindgen_private::LayoutItemInfo;
    auto flexbox_layout_item_info (slint::cbindgen_private::Orientation o, [[maybe_unused]] std::optional<size_t> child_index) const -> slint::cbindgen_private::FlexboxLayoutItemInfo;
    friend class vtable::VRc<slint::private_api::ItemTreeVTable, Component_image_5>;
};

class Component_rectangle_7 {
    public:
    slint::cbindgen_private::ItemTreeWeak self_weak;
    const class SharedGlobals* globals;
    uint32_t tree_index_of_first_child;
    uint32_t tree_index;
    vtable::VWeakMapped<slint::private_api::ItemTreeVTable, class AppCard_root_1 const> parent;
    slint::private_api::Property<slint::cbindgen_private::LayoutInfo> field_rectangle_7_layoutinfo_h;
    slint::private_api::Property<slint::cbindgen_private::LayoutInfo> field_rectangle_7_layoutinfo_v;
    slint::private_api::Property<float> field_rectangle_7_text_8_min_height;
    slint::private_api::Property<float> field_rectangle_7_text_8_min_width;
    slint::private_api::Property<float> field_rectangle_7_text_8_preferred_height;
    slint::private_api::Property<float> field_rectangle_7_text_8_preferred_width;
    slint::cbindgen_private::BasicBorderRectangle field_rectangle_7 = {};
    slint::cbindgen_private::SimpleText field_text_8 = {};
    auto init (const class SharedGlobals* globals,slint::cbindgen_private::ItemTreeWeak enclosing_component,uint32_t tree_index,uint32_t tree_index_of_first_child,class AppCard_root_1 const *parent) -> void;
    auto user_init () -> void;
    auto layout_info (slint::cbindgen_private::Orientation o) const -> slint::cbindgen_private::LayoutInfo;
    auto item_geometry (uint32_t index) const -> slint::cbindgen_private::Rect;
    auto accessible_role (uint32_t index) const -> slint::cbindgen_private::AccessibleRole;
    auto accessible_string_property (uint32_t index, slint::cbindgen_private::AccessibleStringProperty what) const -> std::optional<slint::SharedString>;
    auto accessibility_action (uint32_t index, const slint::cbindgen_private::AccessibilityAction &action) const -> void;
    auto supported_accessibility_actions (uint32_t index) const -> uint32_t;
    auto element_infos (uint32_t index) const -> std::optional<slint::SharedString>;
    auto ensure_instantiated () const -> bool;
    private:
    static auto visit_children (slint::private_api::ItemTreeRef component, intptr_t index, slint::private_api::TraversalOrder order, slint::private_api::ItemVisitorRefMut visitor) -> uint64_t;
    static auto get_item_ref (slint::private_api::ItemTreeRef component, uint32_t index) -> slint::private_api::ItemRef;
    static auto get_subtree_range ([[maybe_unused]] slint::private_api::ItemTreeRef component, [[maybe_unused]] uint32_t dyn_index) -> slint::private_api::IndexRange;
    static auto get_subtree ([[maybe_unused]] slint::private_api::ItemTreeRef component, [[maybe_unused]] uint32_t dyn_index, [[maybe_unused]] uintptr_t subtree_index, [[maybe_unused]] slint::private_api::ItemTreeWeak *result) -> void;
    static auto get_item_tree (slint::private_api::ItemTreeRef) -> slint::cbindgen_private::Slice<slint::private_api::ItemTreeNode>;
    static auto parent_node ([[maybe_unused]] slint::private_api::ItemTreeRef component, [[maybe_unused]] slint::private_api::ItemWeak *result) -> void;
    static auto embed_component ([[maybe_unused]] slint::private_api::ItemTreeRef component, [[maybe_unused]] const slint::private_api::ItemTreeWeak *parent_component, [[maybe_unused]] const uint32_t parent_index) -> bool;
    static auto subtree_index ([[maybe_unused]] slint::private_api::ItemTreeRef component) -> uintptr_t;
    static auto item_tree () -> slint::cbindgen_private::Slice<slint::private_api::ItemTreeNode>;
    static auto item_array () -> const slint::private_api::ItemArray;
    static auto layout_info ([[maybe_unused]] slint::private_api::ItemTreeRef component, slint::cbindgen_private::Orientation o) -> slint::cbindgen_private::LayoutInfo;
    static auto ensure_instantiated ([[maybe_unused]] slint::private_api::ItemTreeRef component) -> bool;
    static auto item_geometry ([[maybe_unused]] slint::private_api::ItemTreeRef component, uint32_t index) -> slint::cbindgen_private::LogicalRect;
    static auto accessible_role ([[maybe_unused]] slint::private_api::ItemTreeRef component, uint32_t index) -> slint::cbindgen_private::AccessibleRole;
    static auto accessible_string_property ([[maybe_unused]] slint::private_api::ItemTreeRef component, uint32_t index, slint::cbindgen_private::AccessibleStringProperty what, slint::SharedString *result) -> bool;
    static auto accessibility_action ([[maybe_unused]] slint::private_api::ItemTreeRef component, uint32_t index, const slint::cbindgen_private::AccessibilityAction *action) -> void;
    static auto supported_accessibility_actions ([[maybe_unused]] slint::private_api::ItemTreeRef component, uint32_t index) -> uint32_t;
    static auto element_infos ([[maybe_unused]] slint::private_api::ItemTreeRef component, [[maybe_unused]] uint32_t index, [[maybe_unused]] slint::SharedString *result) -> bool;
    static auto window_adapter ([[maybe_unused]] slint::private_api::ItemTreeRef component, [[maybe_unused]] bool do_create, [[maybe_unused]] slint::cbindgen_private::Option<slint::private_api::WindowAdapterRc>* result) -> void;
    public:
    static const slint::private_api::ItemTreeVTable static_vtable;
    static auto create (class AppCard_root_1 const * parent) -> slint::ComponentHandle<Component_rectangle_7>;
    ~Component_rectangle_7 ();
    auto init () -> void;
    auto layout_item_info (slint::cbindgen_private::Orientation o, [[maybe_unused]] std::optional<size_t> child_index) const -> slint::cbindgen_private::LayoutItemInfo;
    auto flexbox_layout_item_info (slint::cbindgen_private::Orientation o, [[maybe_unused]] std::optional<size_t> child_index) const -> slint::cbindgen_private::FlexboxLayoutItemInfo;
    friend class vtable::VRc<slint::private_api::ItemTreeVTable, Component_rectangle_7>;
};

class AppCard_root_1 {
    public:
    slint::cbindgen_private::ItemTreeWeak self_weak;
    const class SharedGlobals* globals;
    uint32_t tree_index_of_first_child;
    uint32_t tree_index;
    slint::private_api::Property<int> field_root_1_accent_idx;
    slint::private_api::Property<slint::SharedVector<float>> field_root_1_empty_10_layout_cache;
    slint::private_api::Property<slint::cbindgen_private::LayoutInfo> field_root_1_empty_10_layoutinfo_h;
    slint::private_api::Property<slint::cbindgen_private::LayoutInfo> field_root_1_empty_10_layoutinfo_v;
    slint::private_api::Property<slint::cbindgen_private::LayoutAlignment> field_root_1_empty_3_alignment;
    slint::private_api::Property<slint::SharedVector<float>> field_root_1_empty_3_layout_cache;
    slint::private_api::Property<slint::cbindgen_private::LayoutInfo> field_root_1_empty_3_layoutinfo_h;
    slint::private_api::Property<slint::cbindgen_private::LayoutInfo> field_root_1_empty_3_layoutinfo_v;
    slint::private_api::Property<float> field_root_1_empty_3_padding;
    slint::private_api::Property<float> field_root_1_empty_3_spacing;
    slint::private_api::Property<slint::SharedVector<float>> field_root_1_empty_4_layout_cache;
    slint::private_api::Property<slint::cbindgen_private::LayoutInfo> field_root_1_empty_4_layoutinfo_h;
    slint::private_api::Property<slint::cbindgen_private::LayoutInfo> field_root_1_empty_4_layoutinfo_v;
    slint::private_api::Property<float> field_root_1_height;
    slint::private_api::Property<UiPackage> field_root_1_pkg;
    slint::private_api::Property<float> field_root_1_width;
    slint::private_api::Property<float> field_root_1_x;
    slint::private_api::Property<float> field_root_1_y;
    slint::private_api::Callback<void()> field_root_1_clicked;
    slint::cbindgen_private::BasicBorderRectangle field_root_1 = {};
    slint::cbindgen_private::TouchArea field_ta_2 = {};
    slint::cbindgen_private::Empty field_empty_4 = {};
    slint::cbindgen_private::Empty field_empty_10 = {};
    slint::cbindgen_private::ComplexText field_text_11 = {};
    slint::cbindgen_private::ComplexText field_text_12 = {};
    slint::cbindgen_private::SimpleText field_text_13 = {};
    slint::private_api::Conditional<class Component_image_5> repeater_0;
    slint::private_api::Conditional<class Component_rectangle_7> repeater_1;
    auto fn_empty_3_layoutinfo_v_with_constraint ([[maybe_unused]] float arg_0) const -> slint::cbindgen_private::LayoutInfo;
    auto fn_empty_4_layoutinfo_v_with_constraint ([[maybe_unused]] float arg_0) const -> slint::cbindgen_private::LayoutInfo;
    auto fn_layoutinfo_v_with_constraint ([[maybe_unused]] float arg_0) const -> slint::cbindgen_private::LayoutInfo;
    auto init (const class SharedGlobals* globals,slint::cbindgen_private::ItemTreeWeak enclosing_component,uint32_t tree_index,uint32_t tree_index_of_first_child) -> void;
    auto user_init () -> void;
    auto layout_info (slint::cbindgen_private::Orientation o) const -> slint::cbindgen_private::LayoutInfo;
    auto item_geometry (uint32_t index) const -> slint::cbindgen_private::Rect;
    auto accessible_role (uint32_t index) const -> slint::cbindgen_private::AccessibleRole;
    auto accessible_string_property (uint32_t index, slint::cbindgen_private::AccessibleStringProperty what) const -> std::optional<slint::SharedString>;
    auto accessibility_action (uint32_t index, const slint::cbindgen_private::AccessibilityAction &action) const -> void;
    auto supported_accessibility_actions (uint32_t index) const -> uint32_t;
    auto element_infos (uint32_t index) const -> std::optional<slint::SharedString>;
    auto ensure_instantiated () const -> bool;
    auto visit_dynamic_children (uint32_t dyn_index, [[maybe_unused]] slint::private_api::TraversalOrder order, [[maybe_unused]] slint::private_api::ItemVisitorRefMut visitor) const -> uint64_t;
    auto subtree_range (uintptr_t dyn_index) const -> slint::private_api::IndexRange;
    auto subtree_component (uintptr_t dyn_index, [[maybe_unused]] uintptr_t subtree_index, [[maybe_unused]] slint::private_api::ItemTreeWeak *result) const -> void;
};

class DepRow_root_14 {
    public:
    slint::cbindgen_private::ItemTreeWeak self_weak;
    const class SharedGlobals* globals;
    uint32_t tree_index_of_first_child;
    uint32_t tree_index;
    slint::private_api::Property<slint::Color> field_root_14_accent;
    slint::private_api::Property<UiPackageDependency> field_root_14_dep;
    slint::private_api::Property<slint::SharedVector<float>> field_root_14_empty_15_layout_cache;
    slint::private_api::Property<slint::cbindgen_private::LayoutInfo> field_root_14_empty_15_layoutinfo_h;
    slint::private_api::Property<slint::cbindgen_private::LayoutInfo> field_root_14_empty_15_layoutinfo_v;
    slint::private_api::Property<slint::cbindgen_private::LayoutInfo> field_root_14_rectangle_16_layoutinfo_h;
    slint::private_api::Property<slint::cbindgen_private::LayoutInfo> field_root_14_rectangle_16_layoutinfo_v;
    slint::private_api::Property<float> field_root_14_text_17_min_height;
    slint::private_api::Property<float> field_root_14_text_17_min_width;
    slint::private_api::Property<float> field_root_14_text_17_preferred_height;
    slint::private_api::Property<float> field_root_14_text_17_preferred_width;
    slint::private_api::Property<float> field_root_14_width;
    slint::private_api::Property<float> field_root_14_x;
    slint::private_api::Property<float> field_root_14_y;
    slint::cbindgen_private::Empty field_root_14 = {};
    slint::cbindgen_private::BasicBorderRectangle field_rectangle_16 = {};
    slint::cbindgen_private::SimpleText field_text_17 = {};
    slint::cbindgen_private::SimpleText field_text_18 = {};
    slint::cbindgen_private::SimpleText field_text_19 = {};
    auto init (const class SharedGlobals* globals,slint::cbindgen_private::ItemTreeWeak enclosing_component,uint32_t tree_index,uint32_t tree_index_of_first_child) -> void;
    auto user_init () -> void;
    auto layout_info (slint::cbindgen_private::Orientation o) const -> slint::cbindgen_private::LayoutInfo;
    auto item_geometry (uint32_t index) const -> slint::cbindgen_private::Rect;
    auto accessible_role (uint32_t index) const -> slint::cbindgen_private::AccessibleRole;
    auto accessible_string_property (uint32_t index, slint::cbindgen_private::AccessibleStringProperty what) const -> std::optional<slint::SharedString>;
    auto accessibility_action (uint32_t index, const slint::cbindgen_private::AccessibilityAction &action) const -> void;
    auto supported_accessibility_actions (uint32_t index) const -> uint32_t;
    auto element_infos (uint32_t index) const -> std::optional<slint::SharedString>;
    auto ensure_instantiated () const -> bool;
};

class Component_image_23 {
    public:
    slint::cbindgen_private::ItemTreeWeak self_weak;
    const class SharedGlobals* globals;
    uint32_t tree_index_of_first_child;
    uint32_t tree_index;
    vtable::VWeakMapped<slint::private_api::ItemTreeVTable, class SuggestionCard_root_20 const> parent;
    slint::cbindgen_private::ClippedImage field_image_23 = {};
    auto init (const class SharedGlobals* globals,slint::cbindgen_private::ItemTreeWeak enclosing_component,uint32_t tree_index,uint32_t tree_index_of_first_child,class SuggestionCard_root_20 const *parent) -> void;
    auto user_init () -> void;
    auto layout_info (slint::cbindgen_private::Orientation o) const -> slint::cbindgen_private::LayoutInfo;
    auto item_geometry (uint32_t index) const -> slint::cbindgen_private::Rect;
    auto accessible_role (uint32_t index) const -> slint::cbindgen_private::AccessibleRole;
    auto accessible_string_property (uint32_t index, slint::cbindgen_private::AccessibleStringProperty what) const -> std::optional<slint::SharedString>;
    auto accessibility_action (uint32_t index, const slint::cbindgen_private::AccessibilityAction &action) const -> void;
    auto supported_accessibility_actions (uint32_t index) const -> uint32_t;
    auto element_infos (uint32_t index) const -> std::optional<slint::SharedString>;
    auto ensure_instantiated () const -> bool;
    private:
    static auto visit_children (slint::private_api::ItemTreeRef component, intptr_t index, slint::private_api::TraversalOrder order, slint::private_api::ItemVisitorRefMut visitor) -> uint64_t;
    static auto get_item_ref (slint::private_api::ItemTreeRef component, uint32_t index) -> slint::private_api::ItemRef;
    static auto get_subtree_range ([[maybe_unused]] slint::private_api::ItemTreeRef component, [[maybe_unused]] uint32_t dyn_index) -> slint::private_api::IndexRange;
    static auto get_subtree ([[maybe_unused]] slint::private_api::ItemTreeRef component, [[maybe_unused]] uint32_t dyn_index, [[maybe_unused]] uintptr_t subtree_index, [[maybe_unused]] slint::private_api::ItemTreeWeak *result) -> void;
    static auto get_item_tree (slint::private_api::ItemTreeRef) -> slint::cbindgen_private::Slice<slint::private_api::ItemTreeNode>;
    static auto parent_node ([[maybe_unused]] slint::private_api::ItemTreeRef component, [[maybe_unused]] slint::private_api::ItemWeak *result) -> void;
    static auto embed_component ([[maybe_unused]] slint::private_api::ItemTreeRef component, [[maybe_unused]] const slint::private_api::ItemTreeWeak *parent_component, [[maybe_unused]] const uint32_t parent_index) -> bool;
    static auto subtree_index ([[maybe_unused]] slint::private_api::ItemTreeRef component) -> uintptr_t;
    static auto item_tree () -> slint::cbindgen_private::Slice<slint::private_api::ItemTreeNode>;
    static auto item_array () -> const slint::private_api::ItemArray;
    static auto layout_info ([[maybe_unused]] slint::private_api::ItemTreeRef component, slint::cbindgen_private::Orientation o) -> slint::cbindgen_private::LayoutInfo;
    static auto ensure_instantiated ([[maybe_unused]] slint::private_api::ItemTreeRef component) -> bool;
    static auto item_geometry ([[maybe_unused]] slint::private_api::ItemTreeRef component, uint32_t index) -> slint::cbindgen_private::LogicalRect;
    static auto accessible_role ([[maybe_unused]] slint::private_api::ItemTreeRef component, uint32_t index) -> slint::cbindgen_private::AccessibleRole;
    static auto accessible_string_property ([[maybe_unused]] slint::private_api::ItemTreeRef component, uint32_t index, slint::cbindgen_private::AccessibleStringProperty what, slint::SharedString *result) -> bool;
    static auto accessibility_action ([[maybe_unused]] slint::private_api::ItemTreeRef component, uint32_t index, const slint::cbindgen_private::AccessibilityAction *action) -> void;
    static auto supported_accessibility_actions ([[maybe_unused]] slint::private_api::ItemTreeRef component, uint32_t index) -> uint32_t;
    static auto element_infos ([[maybe_unused]] slint::private_api::ItemTreeRef component, [[maybe_unused]] uint32_t index, [[maybe_unused]] slint::SharedString *result) -> bool;
    static auto window_adapter ([[maybe_unused]] slint::private_api::ItemTreeRef component, [[maybe_unused]] bool do_create, [[maybe_unused]] slint::cbindgen_private::Option<slint::private_api::WindowAdapterRc>* result) -> void;
    public:
    static const slint::private_api::ItemTreeVTable static_vtable;
    static auto create (class SuggestionCard_root_20 const * parent) -> slint::ComponentHandle<Component_image_23>;
    ~Component_image_23 ();
    auto init () -> void;
    auto layout_item_info (slint::cbindgen_private::Orientation o, [[maybe_unused]] std::optional<size_t> child_index) const -> slint::cbindgen_private::LayoutItemInfo;
    auto flexbox_layout_item_info (slint::cbindgen_private::Orientation o, [[maybe_unused]] std::optional<size_t> child_index) const -> slint::cbindgen_private::FlexboxLayoutItemInfo;
    friend class vtable::VRc<slint::private_api::ItemTreeVTable, Component_image_23>;
};

class Component_rectangle_25 {
    public:
    slint::cbindgen_private::ItemTreeWeak self_weak;
    const class SharedGlobals* globals;
    uint32_t tree_index_of_first_child;
    uint32_t tree_index;
    vtable::VWeakMapped<slint::private_api::ItemTreeVTable, class SuggestionCard_root_20 const> parent;
    slint::cbindgen_private::BasicBorderRectangle field_rectangle_25 = {};
    auto init (const class SharedGlobals* globals,slint::cbindgen_private::ItemTreeWeak enclosing_component,uint32_t tree_index,uint32_t tree_index_of_first_child,class SuggestionCard_root_20 const *parent) -> void;
    auto user_init () -> void;
    auto layout_info (slint::cbindgen_private::Orientation o) const -> slint::cbindgen_private::LayoutInfo;
    auto item_geometry (uint32_t index) const -> slint::cbindgen_private::Rect;
    auto accessible_role (uint32_t index) const -> slint::cbindgen_private::AccessibleRole;
    auto accessible_string_property (uint32_t index, slint::cbindgen_private::AccessibleStringProperty what) const -> std::optional<slint::SharedString>;
    auto accessibility_action (uint32_t index, const slint::cbindgen_private::AccessibilityAction &action) const -> void;
    auto supported_accessibility_actions (uint32_t index) const -> uint32_t;
    auto element_infos (uint32_t index) const -> std::optional<slint::SharedString>;
    auto ensure_instantiated () const -> bool;
    private:
    static auto visit_children (slint::private_api::ItemTreeRef component, intptr_t index, slint::private_api::TraversalOrder order, slint::private_api::ItemVisitorRefMut visitor) -> uint64_t;
    static auto get_item_ref (slint::private_api::ItemTreeRef component, uint32_t index) -> slint::private_api::ItemRef;
    static auto get_subtree_range ([[maybe_unused]] slint::private_api::ItemTreeRef component, [[maybe_unused]] uint32_t dyn_index) -> slint::private_api::IndexRange;
    static auto get_subtree ([[maybe_unused]] slint::private_api::ItemTreeRef component, [[maybe_unused]] uint32_t dyn_index, [[maybe_unused]] uintptr_t subtree_index, [[maybe_unused]] slint::private_api::ItemTreeWeak *result) -> void;
    static auto get_item_tree (slint::private_api::ItemTreeRef) -> slint::cbindgen_private::Slice<slint::private_api::ItemTreeNode>;
    static auto parent_node ([[maybe_unused]] slint::private_api::ItemTreeRef component, [[maybe_unused]] slint::private_api::ItemWeak *result) -> void;
    static auto embed_component ([[maybe_unused]] slint::private_api::ItemTreeRef component, [[maybe_unused]] const slint::private_api::ItemTreeWeak *parent_component, [[maybe_unused]] const uint32_t parent_index) -> bool;
    static auto subtree_index ([[maybe_unused]] slint::private_api::ItemTreeRef component) -> uintptr_t;
    static auto item_tree () -> slint::cbindgen_private::Slice<slint::private_api::ItemTreeNode>;
    static auto item_array () -> const slint::private_api::ItemArray;
    static auto layout_info ([[maybe_unused]] slint::private_api::ItemTreeRef component, slint::cbindgen_private::Orientation o) -> slint::cbindgen_private::LayoutInfo;
    static auto ensure_instantiated ([[maybe_unused]] slint::private_api::ItemTreeRef component) -> bool;
    static auto item_geometry ([[maybe_unused]] slint::private_api::ItemTreeRef component, uint32_t index) -> slint::cbindgen_private::LogicalRect;
    static auto accessible_role ([[maybe_unused]] slint::private_api::ItemTreeRef component, uint32_t index) -> slint::cbindgen_private::AccessibleRole;
    static auto accessible_string_property ([[maybe_unused]] slint::private_api::ItemTreeRef component, uint32_t index, slint::cbindgen_private::AccessibleStringProperty what, slint::SharedString *result) -> bool;
    static auto accessibility_action ([[maybe_unused]] slint::private_api::ItemTreeRef component, uint32_t index, const slint::cbindgen_private::AccessibilityAction *action) -> void;
    static auto supported_accessibility_actions ([[maybe_unused]] slint::private_api::ItemTreeRef component, uint32_t index) -> uint32_t;
    static auto element_infos ([[maybe_unused]] slint::private_api::ItemTreeRef component, [[maybe_unused]] uint32_t index, [[maybe_unused]] slint::SharedString *result) -> bool;
    static auto window_adapter ([[maybe_unused]] slint::private_api::ItemTreeRef component, [[maybe_unused]] bool do_create, [[maybe_unused]] slint::cbindgen_private::Option<slint::private_api::WindowAdapterRc>* result) -> void;
    public:
    static const slint::private_api::ItemTreeVTable static_vtable;
    static auto create (class SuggestionCard_root_20 const * parent) -> slint::ComponentHandle<Component_rectangle_25>;
    ~Component_rectangle_25 ();
    auto init () -> void;
    auto layout_item_info (slint::cbindgen_private::Orientation o, [[maybe_unused]] std::optional<size_t> child_index) const -> slint::cbindgen_private::LayoutItemInfo;
    auto flexbox_layout_item_info (slint::cbindgen_private::Orientation o, [[maybe_unused]] std::optional<size_t> child_index) const -> slint::cbindgen_private::FlexboxLayoutItemInfo;
    friend class vtable::VRc<slint::private_api::ItemTreeVTable, Component_rectangle_25>;
};

class SuggestionCard_root_20 {
    public:
    slint::cbindgen_private::ItemTreeWeak self_weak;
    const class SharedGlobals* globals;
    uint32_t tree_index_of_first_child;
    uint32_t tree_index;
    slint::private_api::Property<int> field_root_20_accent_idx;
    slint::private_api::Property<slint::cbindgen_private::LayoutAlignment> field_root_20_empty_22_alignment;
    slint::private_api::Property<slint::SharedVector<float>> field_root_20_empty_22_layout_cache;
    slint::private_api::Property<slint::cbindgen_private::LayoutInfo> field_root_20_empty_22_layoutinfo_h;
    slint::private_api::Property<slint::cbindgen_private::LayoutInfo> field_root_20_empty_22_layoutinfo_v;
    slint::private_api::Property<float> field_root_20_empty_22_padding;
    slint::private_api::Property<float> field_root_20_empty_22_spacing;
    slint::private_api::Property<slint::SharedVector<float>> field_root_20_empty_27_layout_cache;
    slint::private_api::Property<slint::cbindgen_private::LayoutInfo> field_root_20_empty_27_layoutinfo_h;
    slint::private_api::Property<slint::cbindgen_private::LayoutInfo> field_root_20_empty_27_layoutinfo_v;
    slint::private_api::Property<UiPackage> field_root_20_pkg;
    slint::private_api::Property<float> field_root_20_rectangle_30_vertical_stretch;
    slint::private_api::Property<float> field_root_20_x;
    slint::private_api::Callback<void()> field_root_20_clicked;
    slint::cbindgen_private::BasicBorderRectangle field_root_20 = {};
    slint::cbindgen_private::TouchArea field_sta_21 = {};
    slint::cbindgen_private::Empty field_empty_27 = {};
    slint::cbindgen_private::ComplexText field_text_28 = {};
    slint::cbindgen_private::ComplexText field_text_29 = {};
    slint::cbindgen_private::Empty field_rectangle_30 = {};
    slint::cbindgen_private::SimpleText field_text_31 = {};
    slint::private_api::Conditional<class Component_image_23> repeater_0;
    slint::private_api::Conditional<class Component_rectangle_25> repeater_1;
    auto fn_empty_22_layoutinfo_v_with_constraint ([[maybe_unused]] float arg_0) const -> slint::cbindgen_private::LayoutInfo;
    auto fn_layoutinfo_v_with_constraint ([[maybe_unused]] float arg_0) const -> slint::cbindgen_private::LayoutInfo;
    auto init (const class SharedGlobals* globals,slint::cbindgen_private::ItemTreeWeak enclosing_component,uint32_t tree_index,uint32_t tree_index_of_first_child) -> void;
    auto user_init () -> void;
    auto layout_info (slint::cbindgen_private::Orientation o) const -> slint::cbindgen_private::LayoutInfo;
    auto item_geometry (uint32_t index) const -> slint::cbindgen_private::Rect;
    auto accessible_role (uint32_t index) const -> slint::cbindgen_private::AccessibleRole;
    auto accessible_string_property (uint32_t index, slint::cbindgen_private::AccessibleStringProperty what) const -> std::optional<slint::SharedString>;
    auto accessibility_action (uint32_t index, const slint::cbindgen_private::AccessibilityAction &action) const -> void;
    auto supported_accessibility_actions (uint32_t index) const -> uint32_t;
    auto element_infos (uint32_t index) const -> std::optional<slint::SharedString>;
    auto ensure_instantiated () const -> bool;
    auto visit_dynamic_children (uint32_t dyn_index, [[maybe_unused]] slint::private_api::TraversalOrder order, [[maybe_unused]] slint::private_api::ItemVisitorRefMut visitor) const -> uint64_t;
    auto subtree_range (uintptr_t dyn_index) const -> slint::private_api::IndexRange;
    auto subtree_component (uintptr_t dyn_index, [[maybe_unused]] uintptr_t subtree_index, [[maybe_unused]] slint::private_api::ItemTreeWeak *result) const -> void;
};

class Component_image_37 {
    public:
    slint::cbindgen_private::ItemTreeWeak self_weak;
    const class SharedGlobals* globals;
    uint32_t tree_index_of_first_child;
    uint32_t tree_index;
    vtable::VWeakMapped<slint::private_api::ItemTreeVTable, class DetailsView_root_32 const> parent;
    slint::cbindgen_private::ImageItem field_image_37 = {};
    auto init (const class SharedGlobals* globals,slint::cbindgen_private::ItemTreeWeak enclosing_component,uint32_t tree_index,uint32_t tree_index_of_first_child,class DetailsView_root_32 const *parent) -> void;
    auto user_init () -> void;
    auto layout_info (slint::cbindgen_private::Orientation o) const -> slint::cbindgen_private::LayoutInfo;
    auto item_geometry (uint32_t index) const -> slint::cbindgen_private::Rect;
    auto accessible_role (uint32_t index) const -> slint::cbindgen_private::AccessibleRole;
    auto accessible_string_property (uint32_t index, slint::cbindgen_private::AccessibleStringProperty what) const -> std::optional<slint::SharedString>;
    auto accessibility_action (uint32_t index, const slint::cbindgen_private::AccessibilityAction &action) const -> void;
    auto supported_accessibility_actions (uint32_t index) const -> uint32_t;
    auto element_infos (uint32_t index) const -> std::optional<slint::SharedString>;
    auto ensure_instantiated () const -> bool;
    private:
    static auto visit_children (slint::private_api::ItemTreeRef component, intptr_t index, slint::private_api::TraversalOrder order, slint::private_api::ItemVisitorRefMut visitor) -> uint64_t;
    static auto get_item_ref (slint::private_api::ItemTreeRef component, uint32_t index) -> slint::private_api::ItemRef;
    static auto get_subtree_range ([[maybe_unused]] slint::private_api::ItemTreeRef component, [[maybe_unused]] uint32_t dyn_index) -> slint::private_api::IndexRange;
    static auto get_subtree ([[maybe_unused]] slint::private_api::ItemTreeRef component, [[maybe_unused]] uint32_t dyn_index, [[maybe_unused]] uintptr_t subtree_index, [[maybe_unused]] slint::private_api::ItemTreeWeak *result) -> void;
    static auto get_item_tree (slint::private_api::ItemTreeRef) -> slint::cbindgen_private::Slice<slint::private_api::ItemTreeNode>;
    static auto parent_node ([[maybe_unused]] slint::private_api::ItemTreeRef component, [[maybe_unused]] slint::private_api::ItemWeak *result) -> void;
    static auto embed_component ([[maybe_unused]] slint::private_api::ItemTreeRef component, [[maybe_unused]] const slint::private_api::ItemTreeWeak *parent_component, [[maybe_unused]] const uint32_t parent_index) -> bool;
    static auto subtree_index ([[maybe_unused]] slint::private_api::ItemTreeRef component) -> uintptr_t;
    static auto item_tree () -> slint::cbindgen_private::Slice<slint::private_api::ItemTreeNode>;
    static auto item_array () -> const slint::private_api::ItemArray;
    static auto layout_info ([[maybe_unused]] slint::private_api::ItemTreeRef component, slint::cbindgen_private::Orientation o) -> slint::cbindgen_private::LayoutInfo;
    static auto ensure_instantiated ([[maybe_unused]] slint::private_api::ItemTreeRef component) -> bool;
    static auto item_geometry ([[maybe_unused]] slint::private_api::ItemTreeRef component, uint32_t index) -> slint::cbindgen_private::LogicalRect;
    static auto accessible_role ([[maybe_unused]] slint::private_api::ItemTreeRef component, uint32_t index) -> slint::cbindgen_private::AccessibleRole;
    static auto accessible_string_property ([[maybe_unused]] slint::private_api::ItemTreeRef component, uint32_t index, slint::cbindgen_private::AccessibleStringProperty what, slint::SharedString *result) -> bool;
    static auto accessibility_action ([[maybe_unused]] slint::private_api::ItemTreeRef component, uint32_t index, const slint::cbindgen_private::AccessibilityAction *action) -> void;
    static auto supported_accessibility_actions ([[maybe_unused]] slint::private_api::ItemTreeRef component, uint32_t index) -> uint32_t;
    static auto element_infos ([[maybe_unused]] slint::private_api::ItemTreeRef component, [[maybe_unused]] uint32_t index, [[maybe_unused]] slint::SharedString *result) -> bool;
    static auto window_adapter ([[maybe_unused]] slint::private_api::ItemTreeRef component, [[maybe_unused]] bool do_create, [[maybe_unused]] slint::cbindgen_private::Option<slint::private_api::WindowAdapterRc>* result) -> void;
    public:
    static const slint::private_api::ItemTreeVTable static_vtable;
    static auto create (class DetailsView_root_32 const * parent) -> slint::ComponentHandle<Component_image_37>;
    ~Component_image_37 ();
    auto init () -> void;
    auto layout_item_info (slint::cbindgen_private::Orientation o, [[maybe_unused]] std::optional<size_t> child_index) const -> slint::cbindgen_private::LayoutItemInfo;
    auto flexbox_layout_item_info (slint::cbindgen_private::Orientation o, [[maybe_unused]] std::optional<size_t> child_index) const -> slint::cbindgen_private::FlexboxLayoutItemInfo;
    friend class vtable::VRc<slint::private_api::ItemTreeVTable, Component_image_37>;
};

class Component_rectangle_39 {
    public:
    slint::cbindgen_private::ItemTreeWeak self_weak;
    const class SharedGlobals* globals;
    uint32_t tree_index_of_first_child;
    uint32_t tree_index;
    vtable::VWeakMapped<slint::private_api::ItemTreeVTable, class DetailsView_root_32 const> parent;
    slint::cbindgen_private::BasicBorderRectangle field_rectangle_39 = {};
    auto init (const class SharedGlobals* globals,slint::cbindgen_private::ItemTreeWeak enclosing_component,uint32_t tree_index,uint32_t tree_index_of_first_child,class DetailsView_root_32 const *parent) -> void;
    auto user_init () -> void;
    auto layout_info (slint::cbindgen_private::Orientation o) const -> slint::cbindgen_private::LayoutInfo;
    auto item_geometry (uint32_t index) const -> slint::cbindgen_private::Rect;
    auto accessible_role (uint32_t index) const -> slint::cbindgen_private::AccessibleRole;
    auto accessible_string_property (uint32_t index, slint::cbindgen_private::AccessibleStringProperty what) const -> std::optional<slint::SharedString>;
    auto accessibility_action (uint32_t index, const slint::cbindgen_private::AccessibilityAction &action) const -> void;
    auto supported_accessibility_actions (uint32_t index) const -> uint32_t;
    auto element_infos (uint32_t index) const -> std::optional<slint::SharedString>;
    auto ensure_instantiated () const -> bool;
    private:
    static auto visit_children (slint::private_api::ItemTreeRef component, intptr_t index, slint::private_api::TraversalOrder order, slint::private_api::ItemVisitorRefMut visitor) -> uint64_t;
    static auto get_item_ref (slint::private_api::ItemTreeRef component, uint32_t index) -> slint::private_api::ItemRef;
    static auto get_subtree_range ([[maybe_unused]] slint::private_api::ItemTreeRef component, [[maybe_unused]] uint32_t dyn_index) -> slint::private_api::IndexRange;
    static auto get_subtree ([[maybe_unused]] slint::private_api::ItemTreeRef component, [[maybe_unused]] uint32_t dyn_index, [[maybe_unused]] uintptr_t subtree_index, [[maybe_unused]] slint::private_api::ItemTreeWeak *result) -> void;
    static auto get_item_tree (slint::private_api::ItemTreeRef) -> slint::cbindgen_private::Slice<slint::private_api::ItemTreeNode>;
    static auto parent_node ([[maybe_unused]] slint::private_api::ItemTreeRef component, [[maybe_unused]] slint::private_api::ItemWeak *result) -> void;
    static auto embed_component ([[maybe_unused]] slint::private_api::ItemTreeRef component, [[maybe_unused]] const slint::private_api::ItemTreeWeak *parent_component, [[maybe_unused]] const uint32_t parent_index) -> bool;
    static auto subtree_index ([[maybe_unused]] slint::private_api::ItemTreeRef component) -> uintptr_t;
    static auto item_tree () -> slint::cbindgen_private::Slice<slint::private_api::ItemTreeNode>;
    static auto item_array () -> const slint::private_api::ItemArray;
    static auto layout_info ([[maybe_unused]] slint::private_api::ItemTreeRef component, slint::cbindgen_private::Orientation o) -> slint::cbindgen_private::LayoutInfo;
    static auto ensure_instantiated ([[maybe_unused]] slint::private_api::ItemTreeRef component) -> bool;
    static auto item_geometry ([[maybe_unused]] slint::private_api::ItemTreeRef component, uint32_t index) -> slint::cbindgen_private::LogicalRect;
    static auto accessible_role ([[maybe_unused]] slint::private_api::ItemTreeRef component, uint32_t index) -> slint::cbindgen_private::AccessibleRole;
    static auto accessible_string_property ([[maybe_unused]] slint::private_api::ItemTreeRef component, uint32_t index, slint::cbindgen_private::AccessibleStringProperty what, slint::SharedString *result) -> bool;
    static auto accessibility_action ([[maybe_unused]] slint::private_api::ItemTreeRef component, uint32_t index, const slint::cbindgen_private::AccessibilityAction *action) -> void;
    static auto supported_accessibility_actions ([[maybe_unused]] slint::private_api::ItemTreeRef component, uint32_t index) -> uint32_t;
    static auto element_infos ([[maybe_unused]] slint::private_api::ItemTreeRef component, [[maybe_unused]] uint32_t index, [[maybe_unused]] slint::SharedString *result) -> bool;
    static auto window_adapter ([[maybe_unused]] slint::private_api::ItemTreeRef component, [[maybe_unused]] bool do_create, [[maybe_unused]] slint::cbindgen_private::Option<slint::private_api::WindowAdapterRc>* result) -> void;
    public:
    static const slint::private_api::ItemTreeVTable static_vtable;
    static auto create (class DetailsView_root_32 const * parent) -> slint::ComponentHandle<Component_rectangle_39>;
    ~Component_rectangle_39 ();
    auto init () -> void;
    auto layout_item_info (slint::cbindgen_private::Orientation o, [[maybe_unused]] std::optional<size_t> child_index) const -> slint::cbindgen_private::LayoutItemInfo;
    auto flexbox_layout_item_info (slint::cbindgen_private::Orientation o, [[maybe_unused]] std::optional<size_t> child_index) const -> slint::cbindgen_private::FlexboxLayoutItemInfo;
    friend class vtable::VRc<slint::private_api::ItemTreeVTable, Component_rectangle_39>;
};

class Component_text_56 {
    public:
    slint::cbindgen_private::ItemTreeWeak self_weak;
    const class SharedGlobals* globals;
    uint32_t tree_index_of_first_child;
    uint32_t tree_index;
    vtable::VWeakMapped<slint::private_api::ItemTreeVTable, class DetailsView_root_32 const> parent;
    slint::cbindgen_private::SimpleText field_text_56 = {};
    auto init (const class SharedGlobals* globals,slint::cbindgen_private::ItemTreeWeak enclosing_component,uint32_t tree_index,uint32_t tree_index_of_first_child,class DetailsView_root_32 const *parent) -> void;
    auto user_init () -> void;
    auto layout_info (slint::cbindgen_private::Orientation o) const -> slint::cbindgen_private::LayoutInfo;
    auto item_geometry (uint32_t index) const -> slint::cbindgen_private::Rect;
    auto accessible_role (uint32_t index) const -> slint::cbindgen_private::AccessibleRole;
    auto accessible_string_property (uint32_t index, slint::cbindgen_private::AccessibleStringProperty what) const -> std::optional<slint::SharedString>;
    auto accessibility_action (uint32_t index, const slint::cbindgen_private::AccessibilityAction &action) const -> void;
    auto supported_accessibility_actions (uint32_t index) const -> uint32_t;
    auto element_infos (uint32_t index) const -> std::optional<slint::SharedString>;
    auto ensure_instantiated () const -> bool;
    private:
    static auto visit_children (slint::private_api::ItemTreeRef component, intptr_t index, slint::private_api::TraversalOrder order, slint::private_api::ItemVisitorRefMut visitor) -> uint64_t;
    static auto get_item_ref (slint::private_api::ItemTreeRef component, uint32_t index) -> slint::private_api::ItemRef;
    static auto get_subtree_range ([[maybe_unused]] slint::private_api::ItemTreeRef component, [[maybe_unused]] uint32_t dyn_index) -> slint::private_api::IndexRange;
    static auto get_subtree ([[maybe_unused]] slint::private_api::ItemTreeRef component, [[maybe_unused]] uint32_t dyn_index, [[maybe_unused]] uintptr_t subtree_index, [[maybe_unused]] slint::private_api::ItemTreeWeak *result) -> void;
    static auto get_item_tree (slint::private_api::ItemTreeRef) -> slint::cbindgen_private::Slice<slint::private_api::ItemTreeNode>;
    static auto parent_node ([[maybe_unused]] slint::private_api::ItemTreeRef component, [[maybe_unused]] slint::private_api::ItemWeak *result) -> void;
    static auto embed_component ([[maybe_unused]] slint::private_api::ItemTreeRef component, [[maybe_unused]] const slint::private_api::ItemTreeWeak *parent_component, [[maybe_unused]] const uint32_t parent_index) -> bool;
    static auto subtree_index ([[maybe_unused]] slint::private_api::ItemTreeRef component) -> uintptr_t;
    static auto item_tree () -> slint::cbindgen_private::Slice<slint::private_api::ItemTreeNode>;
    static auto item_array () -> const slint::private_api::ItemArray;
    static auto layout_info ([[maybe_unused]] slint::private_api::ItemTreeRef component, slint::cbindgen_private::Orientation o) -> slint::cbindgen_private::LayoutInfo;
    static auto ensure_instantiated ([[maybe_unused]] slint::private_api::ItemTreeRef component) -> bool;
    static auto item_geometry ([[maybe_unused]] slint::private_api::ItemTreeRef component, uint32_t index) -> slint::cbindgen_private::LogicalRect;
    static auto accessible_role ([[maybe_unused]] slint::private_api::ItemTreeRef component, uint32_t index) -> slint::cbindgen_private::AccessibleRole;
    static auto accessible_string_property ([[maybe_unused]] slint::private_api::ItemTreeRef component, uint32_t index, slint::cbindgen_private::AccessibleStringProperty what, slint::SharedString *result) -> bool;
    static auto accessibility_action ([[maybe_unused]] slint::private_api::ItemTreeRef component, uint32_t index, const slint::cbindgen_private::AccessibilityAction *action) -> void;
    static auto supported_accessibility_actions ([[maybe_unused]] slint::private_api::ItemTreeRef component, uint32_t index) -> uint32_t;
    static auto element_infos ([[maybe_unused]] slint::private_api::ItemTreeRef component, [[maybe_unused]] uint32_t index, [[maybe_unused]] slint::SharedString *result) -> bool;
    static auto window_adapter ([[maybe_unused]] slint::private_api::ItemTreeRef component, [[maybe_unused]] bool do_create, [[maybe_unused]] slint::cbindgen_private::Option<slint::private_api::WindowAdapterRc>* result) -> void;
    public:
    static const slint::private_api::ItemTreeVTable static_vtable;
    static auto create (class DetailsView_root_32 const * parent) -> slint::ComponentHandle<Component_text_56>;
    ~Component_text_56 ();
    auto init () -> void;
    auto layout_item_info (slint::cbindgen_private::Orientation o, [[maybe_unused]] std::optional<size_t> child_index) const -> slint::cbindgen_private::LayoutItemInfo;
    auto flexbox_layout_item_info (slint::cbindgen_private::Orientation o, [[maybe_unused]] std::optional<size_t> child_index) const -> slint::cbindgen_private::FlexboxLayoutItemInfo;
    friend class vtable::VRc<slint::private_api::ItemTreeVTable, Component_text_56>;
};

class Component_text_58 {
    public:
    slint::cbindgen_private::ItemTreeWeak self_weak;
    const class SharedGlobals* globals;
    uint32_t tree_index_of_first_child;
    uint32_t tree_index;
    vtable::VWeakMapped<slint::private_api::ItemTreeVTable, class DetailsView_root_32 const> parent;
    slint::cbindgen_private::SimpleText field_text_58 = {};
    auto init (const class SharedGlobals* globals,slint::cbindgen_private::ItemTreeWeak enclosing_component,uint32_t tree_index,uint32_t tree_index_of_first_child,class DetailsView_root_32 const *parent) -> void;
    auto user_init () -> void;
    auto layout_info (slint::cbindgen_private::Orientation o) const -> slint::cbindgen_private::LayoutInfo;
    auto item_geometry (uint32_t index) const -> slint::cbindgen_private::Rect;
    auto accessible_role (uint32_t index) const -> slint::cbindgen_private::AccessibleRole;
    auto accessible_string_property (uint32_t index, slint::cbindgen_private::AccessibleStringProperty what) const -> std::optional<slint::SharedString>;
    auto accessibility_action (uint32_t index, const slint::cbindgen_private::AccessibilityAction &action) const -> void;
    auto supported_accessibility_actions (uint32_t index) const -> uint32_t;
    auto element_infos (uint32_t index) const -> std::optional<slint::SharedString>;
    auto ensure_instantiated () const -> bool;
    private:
    static auto visit_children (slint::private_api::ItemTreeRef component, intptr_t index, slint::private_api::TraversalOrder order, slint::private_api::ItemVisitorRefMut visitor) -> uint64_t;
    static auto get_item_ref (slint::private_api::ItemTreeRef component, uint32_t index) -> slint::private_api::ItemRef;
    static auto get_subtree_range ([[maybe_unused]] slint::private_api::ItemTreeRef component, [[maybe_unused]] uint32_t dyn_index) -> slint::private_api::IndexRange;
    static auto get_subtree ([[maybe_unused]] slint::private_api::ItemTreeRef component, [[maybe_unused]] uint32_t dyn_index, [[maybe_unused]] uintptr_t subtree_index, [[maybe_unused]] slint::private_api::ItemTreeWeak *result) -> void;
    static auto get_item_tree (slint::private_api::ItemTreeRef) -> slint::cbindgen_private::Slice<slint::private_api::ItemTreeNode>;
    static auto parent_node ([[maybe_unused]] slint::private_api::ItemTreeRef component, [[maybe_unused]] slint::private_api::ItemWeak *result) -> void;
    static auto embed_component ([[maybe_unused]] slint::private_api::ItemTreeRef component, [[maybe_unused]] const slint::private_api::ItemTreeWeak *parent_component, [[maybe_unused]] const uint32_t parent_index) -> bool;
    static auto subtree_index ([[maybe_unused]] slint::private_api::ItemTreeRef component) -> uintptr_t;
    static auto item_tree () -> slint::cbindgen_private::Slice<slint::private_api::ItemTreeNode>;
    static auto item_array () -> const slint::private_api::ItemArray;
    static auto layout_info ([[maybe_unused]] slint::private_api::ItemTreeRef component, slint::cbindgen_private::Orientation o) -> slint::cbindgen_private::LayoutInfo;
    static auto ensure_instantiated ([[maybe_unused]] slint::private_api::ItemTreeRef component) -> bool;
    static auto item_geometry ([[maybe_unused]] slint::private_api::ItemTreeRef component, uint32_t index) -> slint::cbindgen_private::LogicalRect;
    static auto accessible_role ([[maybe_unused]] slint::private_api::ItemTreeRef component, uint32_t index) -> slint::cbindgen_private::AccessibleRole;
    static auto accessible_string_property ([[maybe_unused]] slint::private_api::ItemTreeRef component, uint32_t index, slint::cbindgen_private::AccessibleStringProperty what, slint::SharedString *result) -> bool;
    static auto accessibility_action ([[maybe_unused]] slint::private_api::ItemTreeRef component, uint32_t index, const slint::cbindgen_private::AccessibilityAction *action) -> void;
    static auto supported_accessibility_actions ([[maybe_unused]] slint::private_api::ItemTreeRef component, uint32_t index) -> uint32_t;
    static auto element_infos ([[maybe_unused]] slint::private_api::ItemTreeRef component, [[maybe_unused]] uint32_t index, [[maybe_unused]] slint::SharedString *result) -> bool;
    static auto window_adapter ([[maybe_unused]] slint::private_api::ItemTreeRef component, [[maybe_unused]] bool do_create, [[maybe_unused]] slint::cbindgen_private::Option<slint::private_api::WindowAdapterRc>* result) -> void;
    public:
    static const slint::private_api::ItemTreeVTable static_vtable;
    static auto create (class DetailsView_root_32 const * parent) -> slint::ComponentHandle<Component_text_58>;
    ~Component_text_58 ();
    auto init () -> void;
    auto layout_item_info (slint::cbindgen_private::Orientation o, [[maybe_unused]] std::optional<size_t> child_index) const -> slint::cbindgen_private::LayoutItemInfo;
    auto flexbox_layout_item_info (slint::cbindgen_private::Orientation o, [[maybe_unused]] std::optional<size_t> child_index) const -> slint::cbindgen_private::FlexboxLayoutItemInfo;
    friend class vtable::VRc<slint::private_api::ItemTreeVTable, Component_text_58>;
};

class Component_empty_60 {
    public:
    slint::cbindgen_private::ItemTreeWeak self_weak;
    const class SharedGlobals* globals;
    uint32_t tree_index_of_first_child;
    uint32_t tree_index;
    vtable::VWeakMapped<slint::private_api::ItemTreeVTable, class DetailsView_root_32 const> parent;
    slint::private_api::Property<slint::SharedVector<float>> field_empty_60_empty_63_layout_cache;
    slint::private_api::Property<slint::cbindgen_private::LayoutInfo> field_empty_60_empty_63_layoutinfo_h;
    slint::private_api::Property<slint::cbindgen_private::LayoutInfo> field_empty_60_empty_63_layoutinfo_v;
    slint::private_api::Property<slint::SharedVector<float>> field_empty_60_empty_66_layout_cache;
    slint::private_api::Property<slint::cbindgen_private::LayoutInfo> field_empty_60_empty_66_layoutinfo_h;
    slint::private_api::Property<slint::cbindgen_private::LayoutInfo> field_empty_60_empty_66_layoutinfo_v;
    slint::private_api::Property<slint::SharedVector<float>> field_empty_60_empty_67_layout_cache;
    slint::private_api::Property<slint::cbindgen_private::LayoutInfo> field_empty_60_empty_67_layoutinfo_h;
    slint::private_api::Property<slint::cbindgen_private::LayoutInfo> field_empty_60_empty_67_layoutinfo_v;
    slint::private_api::Property<slint::SharedVector<float>> field_empty_60_empty_70_layout_cache;
    slint::private_api::Property<slint::cbindgen_private::LayoutInfo> field_empty_60_empty_70_layoutinfo_h;
    slint::private_api::Property<slint::cbindgen_private::LayoutInfo> field_empty_60_empty_70_layoutinfo_v;
    slint::private_api::Property<slint::SharedVector<float>> field_empty_60_empty_73_layout_cache;
    slint::private_api::Property<slint::cbindgen_private::LayoutInfo> field_empty_60_empty_73_layoutinfo_h;
    slint::private_api::Property<slint::cbindgen_private::LayoutInfo> field_empty_60_empty_73_layoutinfo_v;
    slint::private_api::Property<slint::SharedVector<float>> field_empty_60_layout_cache;
    slint::private_api::Property<slint::cbindgen_private::LayoutInfo> field_empty_60_layoutinfo_h;
    slint::private_api::Property<slint::cbindgen_private::LayoutInfo> field_empty_60_layoutinfo_v;
    slint::private_api::Property<float> field_empty_60_rectangle_61_width;
    slint::private_api::Property<float> field_empty_60_width;
    slint::cbindgen_private::Empty field_empty_60 = {};
    slint::cbindgen_private::BasicBorderRectangle field_rectangle_61 = {};
    slint::cbindgen_private::Clip field__clip_62 = {};
    slint::cbindgen_private::Rectangle field_rectangle_64 = {};
    slint::cbindgen_private::Rectangle field_rectangle_65 = {};
    slint::cbindgen_private::Empty field_empty_66 = {};
    slint::cbindgen_private::Empty field_empty_67 = {};
    slint::cbindgen_private::BasicBorderRectangle field_rectangle_68 = {};
    slint::cbindgen_private::SimpleText field_text_69 = {};
    slint::cbindgen_private::Empty field_empty_70 = {};
    slint::cbindgen_private::BasicBorderRectangle field_rectangle_71 = {};
    slint::cbindgen_private::SimpleText field_text_72 = {};
    slint::cbindgen_private::Empty field_empty_73 = {};
    slint::cbindgen_private::SimpleText field_text_74 = {};
    auto init (const class SharedGlobals* globals,slint::cbindgen_private::ItemTreeWeak enclosing_component,uint32_t tree_index,uint32_t tree_index_of_first_child,class DetailsView_root_32 const *parent) -> void;
    auto user_init () -> void;
    auto layout_info (slint::cbindgen_private::Orientation o) const -> slint::cbindgen_private::LayoutInfo;
    auto item_geometry (uint32_t index) const -> slint::cbindgen_private::Rect;
    auto accessible_role (uint32_t index) const -> slint::cbindgen_private::AccessibleRole;
    auto accessible_string_property (uint32_t index, slint::cbindgen_private::AccessibleStringProperty what) const -> std::optional<slint::SharedString>;
    auto accessibility_action (uint32_t index, const slint::cbindgen_private::AccessibilityAction &action) const -> void;
    auto supported_accessibility_actions (uint32_t index) const -> uint32_t;
    auto element_infos (uint32_t index) const -> std::optional<slint::SharedString>;
    auto ensure_instantiated () const -> bool;
    private:
    static auto visit_children (slint::private_api::ItemTreeRef component, intptr_t index, slint::private_api::TraversalOrder order, slint::private_api::ItemVisitorRefMut visitor) -> uint64_t;
    static auto get_item_ref (slint::private_api::ItemTreeRef component, uint32_t index) -> slint::private_api::ItemRef;
    static auto get_subtree_range ([[maybe_unused]] slint::private_api::ItemTreeRef component, [[maybe_unused]] uint32_t dyn_index) -> slint::private_api::IndexRange;
    static auto get_subtree ([[maybe_unused]] slint::private_api::ItemTreeRef component, [[maybe_unused]] uint32_t dyn_index, [[maybe_unused]] uintptr_t subtree_index, [[maybe_unused]] slint::private_api::ItemTreeWeak *result) -> void;
    static auto get_item_tree (slint::private_api::ItemTreeRef) -> slint::cbindgen_private::Slice<slint::private_api::ItemTreeNode>;
    static auto parent_node ([[maybe_unused]] slint::private_api::ItemTreeRef component, [[maybe_unused]] slint::private_api::ItemWeak *result) -> void;
    static auto embed_component ([[maybe_unused]] slint::private_api::ItemTreeRef component, [[maybe_unused]] const slint::private_api::ItemTreeWeak *parent_component, [[maybe_unused]] const uint32_t parent_index) -> bool;
    static auto subtree_index ([[maybe_unused]] slint::private_api::ItemTreeRef component) -> uintptr_t;
    static auto item_tree () -> slint::cbindgen_private::Slice<slint::private_api::ItemTreeNode>;
    static auto item_array () -> const slint::private_api::ItemArray;
    static auto layout_info ([[maybe_unused]] slint::private_api::ItemTreeRef component, slint::cbindgen_private::Orientation o) -> slint::cbindgen_private::LayoutInfo;
    static auto ensure_instantiated ([[maybe_unused]] slint::private_api::ItemTreeRef component) -> bool;
    static auto item_geometry ([[maybe_unused]] slint::private_api::ItemTreeRef component, uint32_t index) -> slint::cbindgen_private::LogicalRect;
    static auto accessible_role ([[maybe_unused]] slint::private_api::ItemTreeRef component, uint32_t index) -> slint::cbindgen_private::AccessibleRole;
    static auto accessible_string_property ([[maybe_unused]] slint::private_api::ItemTreeRef component, uint32_t index, slint::cbindgen_private::AccessibleStringProperty what, slint::SharedString *result) -> bool;
    static auto accessibility_action ([[maybe_unused]] slint::private_api::ItemTreeRef component, uint32_t index, const slint::cbindgen_private::AccessibilityAction *action) -> void;
    static auto supported_accessibility_actions ([[maybe_unused]] slint::private_api::ItemTreeRef component, uint32_t index) -> uint32_t;
    static auto element_infos ([[maybe_unused]] slint::private_api::ItemTreeRef component, [[maybe_unused]] uint32_t index, [[maybe_unused]] slint::SharedString *result) -> bool;
    static auto window_adapter ([[maybe_unused]] slint::private_api::ItemTreeRef component, [[maybe_unused]] bool do_create, [[maybe_unused]] slint::cbindgen_private::Option<slint::private_api::WindowAdapterRc>* result) -> void;
    public:
    static const slint::private_api::ItemTreeVTable static_vtable;
    static auto create (class DetailsView_root_32 const * parent) -> slint::ComponentHandle<Component_empty_60>;
    ~Component_empty_60 ();
    auto init () -> void;
    auto layout_item_info (slint::cbindgen_private::Orientation o, [[maybe_unused]] std::optional<size_t> child_index) const -> slint::cbindgen_private::LayoutItemInfo;
    auto flexbox_layout_item_info (slint::cbindgen_private::Orientation o, [[maybe_unused]] std::optional<size_t> child_index) const -> slint::cbindgen_private::FlexboxLayoutItemInfo;
    friend class vtable::VRc<slint::private_api::ItemTreeVTable, Component_empty_60>;
};

class Component_deprow_80 {
    public:
    slint::cbindgen_private::ItemTreeWeak self_weak;
    const class SharedGlobals* globals;
    uint32_t tree_index_of_first_child;
    uint32_t tree_index;
    vtable::VWeakMapped<slint::private_api::ItemTreeVTable, class Component_rectangle_76 const> parent;
    slint::private_api::Property<UiPackageDependency> field_model_data;
    slint::private_api::Property<int> field_model_index;
    DepRow_root_14 field_deprow_80;
    auto init (const class SharedGlobals* globals,slint::cbindgen_private::ItemTreeWeak enclosing_component,uint32_t tree_index,uint32_t tree_index_of_first_child,class Component_rectangle_76 const *parent) -> void;
    auto user_init () -> void;
    auto layout_info (slint::cbindgen_private::Orientation o) const -> slint::cbindgen_private::LayoutInfo;
    auto item_geometry (uint32_t index) const -> slint::cbindgen_private::Rect;
    auto accessible_role (uint32_t index) const -> slint::cbindgen_private::AccessibleRole;
    auto accessible_string_property (uint32_t index, slint::cbindgen_private::AccessibleStringProperty what) const -> std::optional<slint::SharedString>;
    auto accessibility_action (uint32_t index, const slint::cbindgen_private::AccessibilityAction &action) const -> void;
    auto supported_accessibility_actions (uint32_t index) const -> uint32_t;
    auto element_infos (uint32_t index) const -> std::optional<slint::SharedString>;
    auto ensure_instantiated () const -> bool;
    private:
    static auto visit_children (slint::private_api::ItemTreeRef component, intptr_t index, slint::private_api::TraversalOrder order, slint::private_api::ItemVisitorRefMut visitor) -> uint64_t;
    static auto get_item_ref (slint::private_api::ItemTreeRef component, uint32_t index) -> slint::private_api::ItemRef;
    static auto get_subtree_range ([[maybe_unused]] slint::private_api::ItemTreeRef component, [[maybe_unused]] uint32_t dyn_index) -> slint::private_api::IndexRange;
    static auto get_subtree ([[maybe_unused]] slint::private_api::ItemTreeRef component, [[maybe_unused]] uint32_t dyn_index, [[maybe_unused]] uintptr_t subtree_index, [[maybe_unused]] slint::private_api::ItemTreeWeak *result) -> void;
    static auto get_item_tree (slint::private_api::ItemTreeRef) -> slint::cbindgen_private::Slice<slint::private_api::ItemTreeNode>;
    static auto parent_node ([[maybe_unused]] slint::private_api::ItemTreeRef component, [[maybe_unused]] slint::private_api::ItemWeak *result) -> void;
    static auto embed_component ([[maybe_unused]] slint::private_api::ItemTreeRef component, [[maybe_unused]] const slint::private_api::ItemTreeWeak *parent_component, [[maybe_unused]] const uint32_t parent_index) -> bool;
    static auto subtree_index ([[maybe_unused]] slint::private_api::ItemTreeRef component) -> uintptr_t;
    static auto item_tree () -> slint::cbindgen_private::Slice<slint::private_api::ItemTreeNode>;
    static auto item_array () -> const slint::private_api::ItemArray;
    static auto layout_info ([[maybe_unused]] slint::private_api::ItemTreeRef component, slint::cbindgen_private::Orientation o) -> slint::cbindgen_private::LayoutInfo;
    static auto ensure_instantiated ([[maybe_unused]] slint::private_api::ItemTreeRef component) -> bool;
    static auto item_geometry ([[maybe_unused]] slint::private_api::ItemTreeRef component, uint32_t index) -> slint::cbindgen_private::LogicalRect;
    static auto accessible_role ([[maybe_unused]] slint::private_api::ItemTreeRef component, uint32_t index) -> slint::cbindgen_private::AccessibleRole;
    static auto accessible_string_property ([[maybe_unused]] slint::private_api::ItemTreeRef component, uint32_t index, slint::cbindgen_private::AccessibleStringProperty what, slint::SharedString *result) -> bool;
    static auto accessibility_action ([[maybe_unused]] slint::private_api::ItemTreeRef component, uint32_t index, const slint::cbindgen_private::AccessibilityAction *action) -> void;
    static auto supported_accessibility_actions ([[maybe_unused]] slint::private_api::ItemTreeRef component, uint32_t index) -> uint32_t;
    static auto element_infos ([[maybe_unused]] slint::private_api::ItemTreeRef component, [[maybe_unused]] uint32_t index, [[maybe_unused]] slint::SharedString *result) -> bool;
    static auto window_adapter ([[maybe_unused]] slint::private_api::ItemTreeRef component, [[maybe_unused]] bool do_create, [[maybe_unused]] slint::cbindgen_private::Option<slint::private_api::WindowAdapterRc>* result) -> void;
    public:
    static const slint::private_api::ItemTreeVTable static_vtable;
    static auto create (class Component_rectangle_76 const * parent) -> slint::ComponentHandle<Component_deprow_80>;
    ~Component_deprow_80 ();
    auto update_data ([[maybe_unused]] int i, [[maybe_unused]] const UiPackageDependency &data) const -> void;
    auto init () -> void;
    auto layout_item_info (slint::cbindgen_private::Orientation o, [[maybe_unused]] std::optional<size_t> child_index) const -> slint::cbindgen_private::LayoutItemInfo;
    auto flexbox_layout_item_info (slint::cbindgen_private::Orientation o, [[maybe_unused]] std::optional<size_t> child_index) const -> slint::cbindgen_private::FlexboxLayoutItemInfo;
    friend class vtable::VRc<slint::private_api::ItemTreeVTable, Component_deprow_80>;
};

class Component_rectangle_76 {
    public:
    slint::cbindgen_private::ItemTreeWeak self_weak;
    const class SharedGlobals* globals;
    uint32_t tree_index_of_first_child;
    uint32_t tree_index;
    vtable::VWeakMapped<slint::private_api::ItemTreeVTable, class DetailsView_root_32 const> parent;
    slint::private_api::Property<slint::SharedVector<float>> field_rectangle_76_empty_77_layout_cache;
    slint::private_api::Property<slint::cbindgen_private::LayoutInfo> field_rectangle_76_empty_77_layoutinfo_h;
    slint::private_api::Property<slint::cbindgen_private::LayoutInfo> field_rectangle_76_empty_77_layoutinfo_v;
    slint::cbindgen_private::BasicBorderRectangle field_rectangle_76 = {};
    slint::cbindgen_private::SimpleText field_text_78 = {};
    slint::cbindgen_private::Empty field_rectangle_79 = {};
    slint::private_api::Repeater<class Component_deprow_80, UiPackageDependency> repeater_0;
    auto init (const class SharedGlobals* globals,slint::cbindgen_private::ItemTreeWeak enclosing_component,uint32_t tree_index,uint32_t tree_index_of_first_child,class DetailsView_root_32 const *parent) -> void;
    auto user_init () -> void;
    auto layout_info (slint::cbindgen_private::Orientation o) const -> slint::cbindgen_private::LayoutInfo;
    auto item_geometry (uint32_t index) const -> slint::cbindgen_private::Rect;
    auto accessible_role (uint32_t index) const -> slint::cbindgen_private::AccessibleRole;
    auto accessible_string_property (uint32_t index, slint::cbindgen_private::AccessibleStringProperty what) const -> std::optional<slint::SharedString>;
    auto accessibility_action (uint32_t index, const slint::cbindgen_private::AccessibilityAction &action) const -> void;
    auto supported_accessibility_actions (uint32_t index) const -> uint32_t;
    auto element_infos (uint32_t index) const -> std::optional<slint::SharedString>;
    auto ensure_instantiated () const -> bool;
    auto visit_dynamic_children (uint32_t dyn_index, [[maybe_unused]] slint::private_api::TraversalOrder order, [[maybe_unused]] slint::private_api::ItemVisitorRefMut visitor) const -> uint64_t;
    auto subtree_range (uintptr_t dyn_index) const -> slint::private_api::IndexRange;
    auto subtree_component (uintptr_t dyn_index, [[maybe_unused]] uintptr_t subtree_index, [[maybe_unused]] slint::private_api::ItemTreeWeak *result) const -> void;
    private:
    static auto visit_children (slint::private_api::ItemTreeRef component, intptr_t index, slint::private_api::TraversalOrder order, slint::private_api::ItemVisitorRefMut visitor) -> uint64_t;
    static auto get_item_ref (slint::private_api::ItemTreeRef component, uint32_t index) -> slint::private_api::ItemRef;
    static auto get_subtree_range ([[maybe_unused]] slint::private_api::ItemTreeRef component, [[maybe_unused]] uint32_t dyn_index) -> slint::private_api::IndexRange;
    static auto get_subtree ([[maybe_unused]] slint::private_api::ItemTreeRef component, [[maybe_unused]] uint32_t dyn_index, [[maybe_unused]] uintptr_t subtree_index, [[maybe_unused]] slint::private_api::ItemTreeWeak *result) -> void;
    static auto get_item_tree (slint::private_api::ItemTreeRef) -> slint::cbindgen_private::Slice<slint::private_api::ItemTreeNode>;
    static auto parent_node ([[maybe_unused]] slint::private_api::ItemTreeRef component, [[maybe_unused]] slint::private_api::ItemWeak *result) -> void;
    static auto embed_component ([[maybe_unused]] slint::private_api::ItemTreeRef component, [[maybe_unused]] const slint::private_api::ItemTreeWeak *parent_component, [[maybe_unused]] const uint32_t parent_index) -> bool;
    static auto subtree_index ([[maybe_unused]] slint::private_api::ItemTreeRef component) -> uintptr_t;
    static auto item_tree () -> slint::cbindgen_private::Slice<slint::private_api::ItemTreeNode>;
    static auto item_array () -> const slint::private_api::ItemArray;
    static auto layout_info ([[maybe_unused]] slint::private_api::ItemTreeRef component, slint::cbindgen_private::Orientation o) -> slint::cbindgen_private::LayoutInfo;
    static auto ensure_instantiated ([[maybe_unused]] slint::private_api::ItemTreeRef component) -> bool;
    static auto item_geometry ([[maybe_unused]] slint::private_api::ItemTreeRef component, uint32_t index) -> slint::cbindgen_private::LogicalRect;
    static auto accessible_role ([[maybe_unused]] slint::private_api::ItemTreeRef component, uint32_t index) -> slint::cbindgen_private::AccessibleRole;
    static auto accessible_string_property ([[maybe_unused]] slint::private_api::ItemTreeRef component, uint32_t index, slint::cbindgen_private::AccessibleStringProperty what, slint::SharedString *result) -> bool;
    static auto accessibility_action ([[maybe_unused]] slint::private_api::ItemTreeRef component, uint32_t index, const slint::cbindgen_private::AccessibilityAction *action) -> void;
    static auto supported_accessibility_actions ([[maybe_unused]] slint::private_api::ItemTreeRef component, uint32_t index) -> uint32_t;
    static auto element_infos ([[maybe_unused]] slint::private_api::ItemTreeRef component, [[maybe_unused]] uint32_t index, [[maybe_unused]] slint::SharedString *result) -> bool;
    static auto window_adapter ([[maybe_unused]] slint::private_api::ItemTreeRef component, [[maybe_unused]] bool do_create, [[maybe_unused]] slint::cbindgen_private::Option<slint::private_api::WindowAdapterRc>* result) -> void;
    public:
    static const slint::private_api::ItemTreeVTable static_vtable;
    static auto create (class DetailsView_root_32 const * parent) -> slint::ComponentHandle<Component_rectangle_76>;
    ~Component_rectangle_76 ();
    auto init () -> void;
    auto layout_item_info (slint::cbindgen_private::Orientation o, [[maybe_unused]] std::optional<size_t> child_index) const -> slint::cbindgen_private::LayoutItemInfo;
    auto flexbox_layout_item_info (slint::cbindgen_private::Orientation o, [[maybe_unused]] std::optional<size_t> child_index) const -> slint::cbindgen_private::FlexboxLayoutItemInfo;
    friend class vtable::VRc<slint::private_api::ItemTreeVTable, Component_rectangle_76>;
};

class Component_rectangle_83 {
    public:
    slint::cbindgen_private::ItemTreeWeak self_weak;
    const class SharedGlobals* globals;
    uint32_t tree_index_of_first_child;
    uint32_t tree_index;
    vtable::VWeakMapped<slint::private_api::ItemTreeVTable, class DetailsView_root_32 const> parent;
    slint::private_api::Property<slint::SharedVector<float>> field_rectangle_83_empty_84_layout_cache;
    slint::private_api::Property<slint::cbindgen_private::LayoutInfo> field_rectangle_83_empty_84_layoutinfo_h;
    slint::private_api::Property<slint::cbindgen_private::LayoutInfo> field_rectangle_83_empty_84_layoutinfo_v;
    slint::cbindgen_private::BasicBorderRectangle field_rectangle_83 = {};
    slint::cbindgen_private::SimpleText field_text_85 = {};
    auto init (const class SharedGlobals* globals,slint::cbindgen_private::ItemTreeWeak enclosing_component,uint32_t tree_index,uint32_t tree_index_of_first_child,class DetailsView_root_32 const *parent) -> void;
    auto user_init () -> void;
    auto layout_info (slint::cbindgen_private::Orientation o) const -> slint::cbindgen_private::LayoutInfo;
    auto item_geometry (uint32_t index) const -> slint::cbindgen_private::Rect;
    auto accessible_role (uint32_t index) const -> slint::cbindgen_private::AccessibleRole;
    auto accessible_string_property (uint32_t index, slint::cbindgen_private::AccessibleStringProperty what) const -> std::optional<slint::SharedString>;
    auto accessibility_action (uint32_t index, const slint::cbindgen_private::AccessibilityAction &action) const -> void;
    auto supported_accessibility_actions (uint32_t index) const -> uint32_t;
    auto element_infos (uint32_t index) const -> std::optional<slint::SharedString>;
    auto ensure_instantiated () const -> bool;
    private:
    static auto visit_children (slint::private_api::ItemTreeRef component, intptr_t index, slint::private_api::TraversalOrder order, slint::private_api::ItemVisitorRefMut visitor) -> uint64_t;
    static auto get_item_ref (slint::private_api::ItemTreeRef component, uint32_t index) -> slint::private_api::ItemRef;
    static auto get_subtree_range ([[maybe_unused]] slint::private_api::ItemTreeRef component, [[maybe_unused]] uint32_t dyn_index) -> slint::private_api::IndexRange;
    static auto get_subtree ([[maybe_unused]] slint::private_api::ItemTreeRef component, [[maybe_unused]] uint32_t dyn_index, [[maybe_unused]] uintptr_t subtree_index, [[maybe_unused]] slint::private_api::ItemTreeWeak *result) -> void;
    static auto get_item_tree (slint::private_api::ItemTreeRef) -> slint::cbindgen_private::Slice<slint::private_api::ItemTreeNode>;
    static auto parent_node ([[maybe_unused]] slint::private_api::ItemTreeRef component, [[maybe_unused]] slint::private_api::ItemWeak *result) -> void;
    static auto embed_component ([[maybe_unused]] slint::private_api::ItemTreeRef component, [[maybe_unused]] const slint::private_api::ItemTreeWeak *parent_component, [[maybe_unused]] const uint32_t parent_index) -> bool;
    static auto subtree_index ([[maybe_unused]] slint::private_api::ItemTreeRef component) -> uintptr_t;
    static auto item_tree () -> slint::cbindgen_private::Slice<slint::private_api::ItemTreeNode>;
    static auto item_array () -> const slint::private_api::ItemArray;
    static auto layout_info ([[maybe_unused]] slint::private_api::ItemTreeRef component, slint::cbindgen_private::Orientation o) -> slint::cbindgen_private::LayoutInfo;
    static auto ensure_instantiated ([[maybe_unused]] slint::private_api::ItemTreeRef component) -> bool;
    static auto item_geometry ([[maybe_unused]] slint::private_api::ItemTreeRef component, uint32_t index) -> slint::cbindgen_private::LogicalRect;
    static auto accessible_role ([[maybe_unused]] slint::private_api::ItemTreeRef component, uint32_t index) -> slint::cbindgen_private::AccessibleRole;
    static auto accessible_string_property ([[maybe_unused]] slint::private_api::ItemTreeRef component, uint32_t index, slint::cbindgen_private::AccessibleStringProperty what, slint::SharedString *result) -> bool;
    static auto accessibility_action ([[maybe_unused]] slint::private_api::ItemTreeRef component, uint32_t index, const slint::cbindgen_private::AccessibilityAction *action) -> void;
    static auto supported_accessibility_actions ([[maybe_unused]] slint::private_api::ItemTreeRef component, uint32_t index) -> uint32_t;
    static auto element_infos ([[maybe_unused]] slint::private_api::ItemTreeRef component, [[maybe_unused]] uint32_t index, [[maybe_unused]] slint::SharedString *result) -> bool;
    static auto window_adapter ([[maybe_unused]] slint::private_api::ItemTreeRef component, [[maybe_unused]] bool do_create, [[maybe_unused]] slint::cbindgen_private::Option<slint::private_api::WindowAdapterRc>* result) -> void;
    public:
    static const slint::private_api::ItemTreeVTable static_vtable;
    static auto create (class DetailsView_root_32 const * parent) -> slint::ComponentHandle<Component_rectangle_83>;
    ~Component_rectangle_83 ();
    auto init () -> void;
    auto layout_item_info (slint::cbindgen_private::Orientation o, [[maybe_unused]] std::optional<size_t> child_index) const -> slint::cbindgen_private::LayoutItemInfo;
    auto flexbox_layout_item_info (slint::cbindgen_private::Orientation o, [[maybe_unused]] std::optional<size_t> child_index) const -> slint::cbindgen_private::FlexboxLayoutItemInfo;
    friend class vtable::VRc<slint::private_api::ItemTreeVTable, Component_rectangle_83>;
};

class Component_suggestioncard_92 {
    public:
    slint::cbindgen_private::ItemTreeWeak self_weak;
    const class SharedGlobals* globals;
    uint32_t tree_index_of_first_child;
    uint32_t tree_index;
    vtable::VWeakMapped<slint::private_api::ItemTreeVTable, class Component_empty_87 const> parent;
    slint::private_api::Property<UiPackage> field_model_data;
    slint::private_api::Property<int> field_model_index;
    SuggestionCard_root_20 field_suggestioncard_92;
    auto init (const class SharedGlobals* globals,slint::cbindgen_private::ItemTreeWeak enclosing_component,uint32_t tree_index,uint32_t tree_index_of_first_child,class Component_empty_87 const *parent) -> void;
    auto user_init () -> void;
    auto layout_info (slint::cbindgen_private::Orientation o) const -> slint::cbindgen_private::LayoutInfo;
    auto item_geometry (uint32_t index) const -> slint::cbindgen_private::Rect;
    auto accessible_role (uint32_t index) const -> slint::cbindgen_private::AccessibleRole;
    auto accessible_string_property (uint32_t index, slint::cbindgen_private::AccessibleStringProperty what) const -> std::optional<slint::SharedString>;
    auto accessibility_action (uint32_t index, const slint::cbindgen_private::AccessibilityAction &action) const -> void;
    auto supported_accessibility_actions (uint32_t index) const -> uint32_t;
    auto element_infos (uint32_t index) const -> std::optional<slint::SharedString>;
    auto ensure_instantiated () const -> bool;
    auto visit_dynamic_children (uint32_t dyn_index, [[maybe_unused]] slint::private_api::TraversalOrder order, [[maybe_unused]] slint::private_api::ItemVisitorRefMut visitor) const -> uint64_t;
    auto subtree_range (uintptr_t dyn_index) const -> slint::private_api::IndexRange;
    auto subtree_component (uintptr_t dyn_index, [[maybe_unused]] uintptr_t subtree_index, [[maybe_unused]] slint::private_api::ItemTreeWeak *result) const -> void;
    private:
    static auto visit_children (slint::private_api::ItemTreeRef component, intptr_t index, slint::private_api::TraversalOrder order, slint::private_api::ItemVisitorRefMut visitor) -> uint64_t;
    static auto get_item_ref (slint::private_api::ItemTreeRef component, uint32_t index) -> slint::private_api::ItemRef;
    static auto get_subtree_range ([[maybe_unused]] slint::private_api::ItemTreeRef component, [[maybe_unused]] uint32_t dyn_index) -> slint::private_api::IndexRange;
    static auto get_subtree ([[maybe_unused]] slint::private_api::ItemTreeRef component, [[maybe_unused]] uint32_t dyn_index, [[maybe_unused]] uintptr_t subtree_index, [[maybe_unused]] slint::private_api::ItemTreeWeak *result) -> void;
    static auto get_item_tree (slint::private_api::ItemTreeRef) -> slint::cbindgen_private::Slice<slint::private_api::ItemTreeNode>;
    static auto parent_node ([[maybe_unused]] slint::private_api::ItemTreeRef component, [[maybe_unused]] slint::private_api::ItemWeak *result) -> void;
    static auto embed_component ([[maybe_unused]] slint::private_api::ItemTreeRef component, [[maybe_unused]] const slint::private_api::ItemTreeWeak *parent_component, [[maybe_unused]] const uint32_t parent_index) -> bool;
    static auto subtree_index ([[maybe_unused]] slint::private_api::ItemTreeRef component) -> uintptr_t;
    static auto item_tree () -> slint::cbindgen_private::Slice<slint::private_api::ItemTreeNode>;
    static auto item_array () -> const slint::private_api::ItemArray;
    static auto layout_info ([[maybe_unused]] slint::private_api::ItemTreeRef component, slint::cbindgen_private::Orientation o) -> slint::cbindgen_private::LayoutInfo;
    static auto ensure_instantiated ([[maybe_unused]] slint::private_api::ItemTreeRef component) -> bool;
    static auto item_geometry ([[maybe_unused]] slint::private_api::ItemTreeRef component, uint32_t index) -> slint::cbindgen_private::LogicalRect;
    static auto accessible_role ([[maybe_unused]] slint::private_api::ItemTreeRef component, uint32_t index) -> slint::cbindgen_private::AccessibleRole;
    static auto accessible_string_property ([[maybe_unused]] slint::private_api::ItemTreeRef component, uint32_t index, slint::cbindgen_private::AccessibleStringProperty what, slint::SharedString *result) -> bool;
    static auto accessibility_action ([[maybe_unused]] slint::private_api::ItemTreeRef component, uint32_t index, const slint::cbindgen_private::AccessibilityAction *action) -> void;
    static auto supported_accessibility_actions ([[maybe_unused]] slint::private_api::ItemTreeRef component, uint32_t index) -> uint32_t;
    static auto element_infos ([[maybe_unused]] slint::private_api::ItemTreeRef component, [[maybe_unused]] uint32_t index, [[maybe_unused]] slint::SharedString *result) -> bool;
    static auto window_adapter ([[maybe_unused]] slint::private_api::ItemTreeRef component, [[maybe_unused]] bool do_create, [[maybe_unused]] slint::cbindgen_private::Option<slint::private_api::WindowAdapterRc>* result) -> void;
    public:
    static const slint::private_api::ItemTreeVTable static_vtable;
    static auto create (class Component_empty_87 const * parent) -> slint::ComponentHandle<Component_suggestioncard_92>;
    ~Component_suggestioncard_92 ();
    auto update_data ([[maybe_unused]] int i, [[maybe_unused]] const UiPackage &data) const -> void;
    auto init () -> void;
    auto layout_item_info (slint::cbindgen_private::Orientation o, [[maybe_unused]] std::optional<size_t> child_index) const -> slint::cbindgen_private::LayoutItemInfo;
    auto flexbox_layout_item_info (slint::cbindgen_private::Orientation o, [[maybe_unused]] std::optional<size_t> child_index) const -> slint::cbindgen_private::FlexboxLayoutItemInfo;
    friend class vtable::VRc<slint::private_api::ItemTreeVTable, Component_suggestioncard_92>;
};

class Component_empty_87 {
    public:
    slint::cbindgen_private::ItemTreeWeak self_weak;
    const class SharedGlobals* globals;
    uint32_t tree_index_of_first_child;
    uint32_t tree_index;
    vtable::VWeakMapped<slint::private_api::ItemTreeVTable, class DetailsView_root_32 const> parent;
    slint::private_api::Property<slint::SharedVector<float>> field_empty_87_empty_91_layout_cache;
    slint::private_api::Property<slint::cbindgen_private::LayoutInfo> field_empty_87_empty_91_layoutinfo_h;
    slint::private_api::Property<slint::cbindgen_private::LayoutInfo> field_empty_87_empty_91_layoutinfo_v;
    slint::private_api::Property<float> field_empty_87_flickable_89_height;
    slint::private_api::Property<slint::SharedVector<float>> field_empty_87_layout_cache;
    slint::private_api::Property<slint::cbindgen_private::LayoutInfo> field_empty_87_layoutinfo_h;
    slint::private_api::Property<slint::cbindgen_private::LayoutInfo> field_empty_87_layoutinfo_v;
    slint::private_api::Property<float> field_empty_87_spacing;
    slint::cbindgen_private::Empty field_empty_87 = {};
    slint::cbindgen_private::SimpleText field_text_88 = {};
    slint::cbindgen_private::Flickable field_flickable_89 = {};
    slint::cbindgen_private::Empty field__viewport_90 = {};
    slint::private_api::Repeater<class Component_suggestioncard_92, UiPackage> repeater_0;
    auto fn_empty_91_layoutinfo_v_with_constraint ([[maybe_unused]] float arg_0) const -> slint::cbindgen_private::LayoutInfo;
    auto fn_layoutinfo_v_with_constraint ([[maybe_unused]] float arg_0) const -> slint::cbindgen_private::LayoutInfo;
    auto init (const class SharedGlobals* globals,slint::cbindgen_private::ItemTreeWeak enclosing_component,uint32_t tree_index,uint32_t tree_index_of_first_child,class DetailsView_root_32 const *parent) -> void;
    auto user_init () -> void;
    auto layout_info (slint::cbindgen_private::Orientation o) const -> slint::cbindgen_private::LayoutInfo;
    auto item_geometry (uint32_t index) const -> slint::cbindgen_private::Rect;
    auto accessible_role (uint32_t index) const -> slint::cbindgen_private::AccessibleRole;
    auto accessible_string_property (uint32_t index, slint::cbindgen_private::AccessibleStringProperty what) const -> std::optional<slint::SharedString>;
    auto accessibility_action (uint32_t index, const slint::cbindgen_private::AccessibilityAction &action) const -> void;
    auto supported_accessibility_actions (uint32_t index) const -> uint32_t;
    auto element_infos (uint32_t index) const -> std::optional<slint::SharedString>;
    auto ensure_instantiated () const -> bool;
    auto visit_dynamic_children (uint32_t dyn_index, [[maybe_unused]] slint::private_api::TraversalOrder order, [[maybe_unused]] slint::private_api::ItemVisitorRefMut visitor) const -> uint64_t;
    auto subtree_range (uintptr_t dyn_index) const -> slint::private_api::IndexRange;
    auto subtree_component (uintptr_t dyn_index, [[maybe_unused]] uintptr_t subtree_index, [[maybe_unused]] slint::private_api::ItemTreeWeak *result) const -> void;
    private:
    static auto visit_children (slint::private_api::ItemTreeRef component, intptr_t index, slint::private_api::TraversalOrder order, slint::private_api::ItemVisitorRefMut visitor) -> uint64_t;
    static auto get_item_ref (slint::private_api::ItemTreeRef component, uint32_t index) -> slint::private_api::ItemRef;
    static auto get_subtree_range ([[maybe_unused]] slint::private_api::ItemTreeRef component, [[maybe_unused]] uint32_t dyn_index) -> slint::private_api::IndexRange;
    static auto get_subtree ([[maybe_unused]] slint::private_api::ItemTreeRef component, [[maybe_unused]] uint32_t dyn_index, [[maybe_unused]] uintptr_t subtree_index, [[maybe_unused]] slint::private_api::ItemTreeWeak *result) -> void;
    static auto get_item_tree (slint::private_api::ItemTreeRef) -> slint::cbindgen_private::Slice<slint::private_api::ItemTreeNode>;
    static auto parent_node ([[maybe_unused]] slint::private_api::ItemTreeRef component, [[maybe_unused]] slint::private_api::ItemWeak *result) -> void;
    static auto embed_component ([[maybe_unused]] slint::private_api::ItemTreeRef component, [[maybe_unused]] const slint::private_api::ItemTreeWeak *parent_component, [[maybe_unused]] const uint32_t parent_index) -> bool;
    static auto subtree_index ([[maybe_unused]] slint::private_api::ItemTreeRef component) -> uintptr_t;
    static auto item_tree () -> slint::cbindgen_private::Slice<slint::private_api::ItemTreeNode>;
    static auto item_array () -> const slint::private_api::ItemArray;
    static auto layout_info ([[maybe_unused]] slint::private_api::ItemTreeRef component, slint::cbindgen_private::Orientation o) -> slint::cbindgen_private::LayoutInfo;
    static auto ensure_instantiated ([[maybe_unused]] slint::private_api::ItemTreeRef component) -> bool;
    static auto item_geometry ([[maybe_unused]] slint::private_api::ItemTreeRef component, uint32_t index) -> slint::cbindgen_private::LogicalRect;
    static auto accessible_role ([[maybe_unused]] slint::private_api::ItemTreeRef component, uint32_t index) -> slint::cbindgen_private::AccessibleRole;
    static auto accessible_string_property ([[maybe_unused]] slint::private_api::ItemTreeRef component, uint32_t index, slint::cbindgen_private::AccessibleStringProperty what, slint::SharedString *result) -> bool;
    static auto accessibility_action ([[maybe_unused]] slint::private_api::ItemTreeRef component, uint32_t index, const slint::cbindgen_private::AccessibilityAction *action) -> void;
    static auto supported_accessibility_actions ([[maybe_unused]] slint::private_api::ItemTreeRef component, uint32_t index) -> uint32_t;
    static auto element_infos ([[maybe_unused]] slint::private_api::ItemTreeRef component, [[maybe_unused]] uint32_t index, [[maybe_unused]] slint::SharedString *result) -> bool;
    static auto window_adapter ([[maybe_unused]] slint::private_api::ItemTreeRef component, [[maybe_unused]] bool do_create, [[maybe_unused]] slint::cbindgen_private::Option<slint::private_api::WindowAdapterRc>* result) -> void;
    public:
    static const slint::private_api::ItemTreeVTable static_vtable;
    static auto create (class DetailsView_root_32 const * parent) -> slint::ComponentHandle<Component_empty_87>;
    ~Component_empty_87 ();
    auto init () -> void;
    auto layout_item_info (slint::cbindgen_private::Orientation o, [[maybe_unused]] std::optional<size_t> child_index) const -> slint::cbindgen_private::LayoutItemInfo;
    auto flexbox_layout_item_info (slint::cbindgen_private::Orientation o, [[maybe_unused]] std::optional<size_t> child_index) const -> slint::cbindgen_private::FlexboxLayoutItemInfo;
    friend class vtable::VRc<slint::private_api::ItemTreeVTable, Component_empty_87>;
};

class DetailsView_root_32 {
    public:
    slint::cbindgen_private::ItemTreeWeak self_weak;
    const class SharedGlobals* globals;
    uint32_t tree_index_of_first_child;
    uint32_t tree_index;
    slint::private_api::Property<slint::Color> field_root_32_accent;
    slint::private_api::Property<int> field_root_32_accent_idx;
    slint::private_api::Property<UiPackageDetails> field_root_32_details;
    slint::private_api::Property<slint::cbindgen_private::LayoutAlignment> field_root_32_empty_35_alignment;
    slint::private_api::Property<slint::SharedVector<float>> field_root_32_empty_35_layout_cache;
    slint::private_api::Property<slint::cbindgen_private::LayoutInfo> field_root_32_empty_35_layoutinfo_h;
    slint::private_api::Property<slint::cbindgen_private::LayoutInfo> field_root_32_empty_35_layoutinfo_v;
    slint::private_api::Property<float> field_root_32_empty_35_padding_bottom;
    slint::private_api::Property<float> field_root_32_empty_35_padding_top;
    slint::private_api::Property<float> field_root_32_empty_35_spacing;
    slint::private_api::Property<slint::SharedVector<float>> field_root_32_empty_36_layout_cache;
    slint::private_api::Property<slint::cbindgen_private::LayoutInfo> field_root_32_empty_36_layoutinfo_h;
    slint::private_api::Property<slint::cbindgen_private::LayoutInfo> field_root_32_empty_36_layoutinfo_v;
    slint::private_api::Property<slint::cbindgen_private::LayoutAlignment> field_root_32_empty_41_alignment;
    slint::private_api::Property<slint::SharedVector<float>> field_root_32_empty_41_layout_cache;
    slint::private_api::Property<slint::cbindgen_private::LayoutInfo> field_root_32_empty_41_layoutinfo_h;
    slint::private_api::Property<slint::cbindgen_private::LayoutInfo> field_root_32_empty_41_layoutinfo_v;
    slint::private_api::Property<float> field_root_32_empty_41_spacing;
    slint::private_api::Property<float> field_root_32_empty_41_width;
    slint::private_api::Property<slint::SharedVector<float>> field_root_32_empty_42_layout_cache;
    slint::private_api::Property<slint::cbindgen_private::LayoutInfo> field_root_32_empty_42_layoutinfo_h;
    slint::private_api::Property<slint::cbindgen_private::LayoutInfo> field_root_32_empty_42_layoutinfo_v;
    slint::private_api::Property<slint::SharedVector<float>> field_root_32_empty_53_layout_cache;
    slint::private_api::Property<slint::cbindgen_private::LayoutInfo> field_root_32_empty_53_layoutinfo_h;
    slint::private_api::Property<slint::cbindgen_private::LayoutInfo> field_root_32_empty_53_layoutinfo_v;
    slint::private_api::Property<slint::SharedVector<float>> field_root_32_empty_54_layout_cache;
    slint::private_api::Property<slint::cbindgen_private::LayoutInfo> field_root_32_empty_54_layoutinfo_h;
    slint::private_api::Property<slint::cbindgen_private::LayoutInfo> field_root_32_empty_54_layoutinfo_v;
    slint::private_api::Property<float> field_root_32_flickable_33_horizontal_stretch;
    slint::private_api::Property<float> field_root_32_flickable_33_max_height;
    slint::private_api::Property<float> field_root_32_flickable_33_min_height;
    slint::private_api::Property<float> field_root_32_flickable_33_min_width;
    slint::private_api::Property<float> field_root_32_flickable_33_preferred_height;
    slint::private_api::Property<float> field_root_32_flickable_33_vertical_stretch;
    slint::private_api::Property<float> field_root_32_height;
    slint::private_api::Property<float> field_root_32_instTxt_45_min_height;
    slint::private_api::Property<float> field_root_32_instTxt_45_min_width;
    slint::private_api::Property<float> field_root_32_instTxt_45_preferred_height;
    slint::private_api::Property<float> field_root_32_instTxt_45_preferred_width;
    slint::private_api::Property<float> field_root_32_instTxt_45_x;
    slint::private_api::Property<slint::cbindgen_private::LayoutInfo> field_root_32_layoutinfo_h;
    slint::private_api::Property<slint::cbindgen_private::LayoutInfo> field_root_32_layoutinfo_v;
    slint::private_api::Property<UiPackage> field_root_32_pkg;
    slint::private_api::Property<slint::cbindgen_private::LayoutInfo> field_root_32_rectangle_44_layoutinfo_h;
    slint::private_api::Property<slint::cbindgen_private::LayoutInfo> field_root_32_rectangle_44_layoutinfo_v;
    slint::private_api::Property<float> field_root_32_rectangle_49_height;
    slint::private_api::Property<slint::cbindgen_private::LayoutInfo> field_root_32_rectangle_49_layoutinfo_h;
    slint::private_api::Property<slint::cbindgen_private::LayoutInfo> field_root_32_rectangle_49_layoutinfo_v;
    slint::private_api::Property<slint::cbindgen_private::LayoutInfo> field_root_32_rectangle_52_layoutinfo_v;
    slint::private_api::Property<std::shared_ptr<slint::Model<UiPackage>>> field_root_32_suggestions;
    slint::private_api::Property<float> field_root_32_text_51_min_height;
    slint::private_api::Property<float> field_root_32_text_51_min_width;
    slint::private_api::Property<float> field_root_32_text_51_preferred_height;
    slint::private_api::Property<float> field_root_32_text_51_preferred_width;
    slint::private_api::Property<float> field_root_32_text_97_min_height;
    slint::private_api::Property<float> field_root_32_text_97_min_width;
    slint::private_api::Property<float> field_root_32_text_97_preferred_height;
    slint::private_api::Property<float> field_root_32_text_97_preferred_width;
    slint::private_api::Property<float> field_root_32_width;
    slint::private_api::Callback<void()> field_root_32_back_clicked;
    slint::private_api::Callback<void()> field_root_32_install_clicked;
    slint::private_api::Callback<void()> field_root_32_remove_clicked;
    slint::private_api::Callback<void(UiPackage)> field_root_32_suggestion_clicked;
    slint::cbindgen_private::Rectangle field_root_32 = {};
    slint::cbindgen_private::Flickable field_flickable_33 = {};
    slint::cbindgen_private::Empty field__viewport_34 = {};
    slint::cbindgen_private::Empty field_empty_36 = {};
    slint::cbindgen_private::Empty field_empty_41 = {};
    slint::cbindgen_private::Empty field_empty_42 = {};
    slint::cbindgen_private::ComplexText field_text_43 = {};
    slint::cbindgen_private::BasicBorderRectangle field_rectangle_44 = {};
    slint::cbindgen_private::SimpleText field_instTxt_45 = {};
    slint::cbindgen_private::ComplexText field_text_46 = {};
    slint::cbindgen_private::SimpleText field_text_47 = {};
    slint::cbindgen_private::Empty field_rectangle_48 = {};
    slint::cbindgen_private::BasicBorderRectangle field_rectangle_49 = {};
    slint::cbindgen_private::TouchArea field_toucharea_50 = {};
    slint::cbindgen_private::SimpleText field_text_51 = {};
    slint::cbindgen_private::BasicBorderRectangle field_rectangle_52 = {};
    slint::cbindgen_private::Empty field_empty_54 = {};
    slint::cbindgen_private::SimpleText field_text_55 = {};
    slint::cbindgen_private::BasicBorderRectangle field_rectangle_95 = {};
    slint::cbindgen_private::TouchArea field_btn_ta_96 = {};
    slint::cbindgen_private::SimpleText field_text_97 = {};
    slint::private_api::Conditional<class Component_image_37> repeater_0;
    slint::private_api::Conditional<class Component_rectangle_39> repeater_1;
    slint::private_api::Conditional<class Component_text_56> repeater_2;
    slint::private_api::Conditional<class Component_text_58> repeater_3;
    slint::private_api::Conditional<class Component_empty_60> repeater_4;
    slint::private_api::Conditional<class Component_rectangle_76> repeater_5;
    slint::private_api::Conditional<class Component_rectangle_83> repeater_6;
    slint::private_api::Conditional<class Component_empty_87> repeater_7;
    auto fn_empty_35_layoutinfo_v_with_constraint ([[maybe_unused]] float arg_0) const -> slint::cbindgen_private::LayoutInfo;
    auto fn_empty_36_layoutinfo_v_with_constraint ([[maybe_unused]] float arg_0) const -> slint::cbindgen_private::LayoutInfo;
    auto fn_empty_41_layoutinfo_v_with_constraint ([[maybe_unused]] float arg_0) const -> slint::cbindgen_private::LayoutInfo;
    auto fn_layoutinfo_v_with_constraint ([[maybe_unused]] float arg_0) const -> slint::cbindgen_private::LayoutInfo;
    auto init (const class SharedGlobals* globals,slint::cbindgen_private::ItemTreeWeak enclosing_component,uint32_t tree_index,uint32_t tree_index_of_first_child) -> void;
    auto user_init () -> void;
    auto layout_info (slint::cbindgen_private::Orientation o) const -> slint::cbindgen_private::LayoutInfo;
    auto item_geometry (uint32_t index) const -> slint::cbindgen_private::Rect;
    auto accessible_role (uint32_t index) const -> slint::cbindgen_private::AccessibleRole;
    auto accessible_string_property (uint32_t index, slint::cbindgen_private::AccessibleStringProperty what) const -> std::optional<slint::SharedString>;
    auto accessibility_action (uint32_t index, const slint::cbindgen_private::AccessibilityAction &action) const -> void;
    auto supported_accessibility_actions (uint32_t index) const -> uint32_t;
    auto element_infos (uint32_t index) const -> std::optional<slint::SharedString>;
    auto ensure_instantiated () const -> bool;
    auto visit_dynamic_children (uint32_t dyn_index, [[maybe_unused]] slint::private_api::TraversalOrder order, [[maybe_unused]] slint::private_api::ItemVisitorRefMut visitor) const -> uint64_t;
    auto subtree_range (uintptr_t dyn_index) const -> slint::private_api::IndexRange;
    auto subtree_component (uintptr_t dyn_index, [[maybe_unused]] uintptr_t subtree_index, [[maybe_unused]] slint::private_api::ItemTreeWeak *result) const -> void;
};

class Theme_121 {
    public:
    slint::private_api::Property<std::shared_ptr<slint::Model<slint::Color>>> field_accents;
    Theme_121 (const class SharedGlobals *globals);
    private:
    auto init () -> void;
    const class SharedGlobals* globals;
    friend class SharedGlobals;
};

class FluentPalette_123 {
    public:
    slint::private_api::Property<slint::cbindgen_private::ColorScheme> field_color_scheme;
    slint::private_api::Property<bool> field_dark_color_scheme;
    slint::private_api::Property<slint::Brush> field_foreground;
    slint::private_api::Property<slint::Brush> field_selection_background;
    slint::private_api::Property<slint::Brush> field_selection_foreground;
    FluentPalette_123 (const class SharedGlobals *globals);
    private:
    auto init () -> void;
    const class SharedGlobals* globals;
    public:
    auto fn_accentify ([[maybe_unused]] slint::Color arg_0) const -> slint::Color;
    friend class SharedGlobals;
};

class SharedGlobals {
    public:
    std::optional<slint::Window> m_window;
    slint::cbindgen_private::ItemTreeWeak root_weak;
    auto window () const -> slint::Window&{
        auto self = const_cast<SharedGlobals *>(this);
        if (!self->m_window.has_value()) {
           auto &window = self->m_window.emplace(slint::private_api::WindowAdapterRc());
           window.window_handle().set_component(self->root_weak);
        }
        return *self->m_window;
    }
    std::shared_ptr<Theme_121> global_Theme_121 = std::make_shared<Theme_121>(this);
    std::shared_ptr<FluentPalette_123> global_FluentPalette_123 = std::make_shared<FluentPalette_123>(this);
    SharedGlobals (){
        global_Theme_121->init();
        global_FluentPalette_123->init();
    }
    private:
    SharedGlobals (const SharedGlobals& source, const slint::private_api::WindowAdapterRc& adapter) : root_weak(source.root_weak), global_Theme_121(source.global_Theme_121), global_FluentPalette_123(source.global_FluentPalette_123){
        m_window.emplace(adapter);
    }
    public:
    auto clone_with_window_adapter (const slint::private_api::WindowAdapterRc& adapter) const -> SharedGlobals*{
        return new SharedGlobals(*this, adapter);
    }
};

class Component_appcard_116 {
    public:
    slint::cbindgen_private::ItemTreeWeak self_weak;
    const class SharedGlobals* globals;
    uint32_t tree_index_of_first_child;
    uint32_t tree_index;
    vtable::VWeakMapped<slint::private_api::ItemTreeVTable, class Component_empty_99 const> parent;
    slint::private_api::Property<UiPackage> field_model_data;
    slint::private_api::Property<int> field_model_index;
    AppCard_root_1 field_appcard_116;
    auto init (const class SharedGlobals* globals,slint::cbindgen_private::ItemTreeWeak enclosing_component,uint32_t tree_index,uint32_t tree_index_of_first_child,class Component_empty_99 const *parent) -> void;
    auto user_init () -> void;
    auto layout_info (slint::cbindgen_private::Orientation o) const -> slint::cbindgen_private::LayoutInfo;
    auto item_geometry (uint32_t index) const -> slint::cbindgen_private::Rect;
    auto accessible_role (uint32_t index) const -> slint::cbindgen_private::AccessibleRole;
    auto accessible_string_property (uint32_t index, slint::cbindgen_private::AccessibleStringProperty what) const -> std::optional<slint::SharedString>;
    auto accessibility_action (uint32_t index, const slint::cbindgen_private::AccessibilityAction &action) const -> void;
    auto supported_accessibility_actions (uint32_t index) const -> uint32_t;
    auto element_infos (uint32_t index) const -> std::optional<slint::SharedString>;
    auto ensure_instantiated () const -> bool;
    auto visit_dynamic_children (uint32_t dyn_index, [[maybe_unused]] slint::private_api::TraversalOrder order, [[maybe_unused]] slint::private_api::ItemVisitorRefMut visitor) const -> uint64_t;
    auto subtree_range (uintptr_t dyn_index) const -> slint::private_api::IndexRange;
    auto subtree_component (uintptr_t dyn_index, [[maybe_unused]] uintptr_t subtree_index, [[maybe_unused]] slint::private_api::ItemTreeWeak *result) const -> void;
    private:
    static auto visit_children (slint::private_api::ItemTreeRef component, intptr_t index, slint::private_api::TraversalOrder order, slint::private_api::ItemVisitorRefMut visitor) -> uint64_t;
    static auto get_item_ref (slint::private_api::ItemTreeRef component, uint32_t index) -> slint::private_api::ItemRef;
    static auto get_subtree_range ([[maybe_unused]] slint::private_api::ItemTreeRef component, [[maybe_unused]] uint32_t dyn_index) -> slint::private_api::IndexRange;
    static auto get_subtree ([[maybe_unused]] slint::private_api::ItemTreeRef component, [[maybe_unused]] uint32_t dyn_index, [[maybe_unused]] uintptr_t subtree_index, [[maybe_unused]] slint::private_api::ItemTreeWeak *result) -> void;
    static auto get_item_tree (slint::private_api::ItemTreeRef) -> slint::cbindgen_private::Slice<slint::private_api::ItemTreeNode>;
    static auto parent_node ([[maybe_unused]] slint::private_api::ItemTreeRef component, [[maybe_unused]] slint::private_api::ItemWeak *result) -> void;
    static auto embed_component ([[maybe_unused]] slint::private_api::ItemTreeRef component, [[maybe_unused]] const slint::private_api::ItemTreeWeak *parent_component, [[maybe_unused]] const uint32_t parent_index) -> bool;
    static auto subtree_index ([[maybe_unused]] slint::private_api::ItemTreeRef component) -> uintptr_t;
    static auto item_tree () -> slint::cbindgen_private::Slice<slint::private_api::ItemTreeNode>;
    static auto item_array () -> const slint::private_api::ItemArray;
    static auto layout_info ([[maybe_unused]] slint::private_api::ItemTreeRef component, slint::cbindgen_private::Orientation o) -> slint::cbindgen_private::LayoutInfo;
    static auto ensure_instantiated ([[maybe_unused]] slint::private_api::ItemTreeRef component) -> bool;
    static auto item_geometry ([[maybe_unused]] slint::private_api::ItemTreeRef component, uint32_t index) -> slint::cbindgen_private::LogicalRect;
    static auto accessible_role ([[maybe_unused]] slint::private_api::ItemTreeRef component, uint32_t index) -> slint::cbindgen_private::AccessibleRole;
    static auto accessible_string_property ([[maybe_unused]] slint::private_api::ItemTreeRef component, uint32_t index, slint::cbindgen_private::AccessibleStringProperty what, slint::SharedString *result) -> bool;
    static auto accessibility_action ([[maybe_unused]] slint::private_api::ItemTreeRef component, uint32_t index, const slint::cbindgen_private::AccessibilityAction *action) -> void;
    static auto supported_accessibility_actions ([[maybe_unused]] slint::private_api::ItemTreeRef component, uint32_t index) -> uint32_t;
    static auto element_infos ([[maybe_unused]] slint::private_api::ItemTreeRef component, [[maybe_unused]] uint32_t index, [[maybe_unused]] slint::SharedString *result) -> bool;
    static auto window_adapter ([[maybe_unused]] slint::private_api::ItemTreeRef component, [[maybe_unused]] bool do_create, [[maybe_unused]] slint::cbindgen_private::Option<slint::private_api::WindowAdapterRc>* result) -> void;
    public:
    static const slint::private_api::ItemTreeVTable static_vtable;
    static auto create (class Component_empty_99 const * parent) -> slint::ComponentHandle<Component_appcard_116>;
    ~Component_appcard_116 ();
    auto update_data ([[maybe_unused]] int i, [[maybe_unused]] const UiPackage &data) const -> void;
    auto init () -> void;
    auto layout_item_info (slint::cbindgen_private::Orientation o, [[maybe_unused]] std::optional<size_t> child_index) const -> slint::cbindgen_private::LayoutItemInfo;
    auto flexbox_layout_item_info (slint::cbindgen_private::Orientation o, [[maybe_unused]] std::optional<size_t> child_index) const -> slint::cbindgen_private::FlexboxLayoutItemInfo;
    friend class vtable::VRc<slint::private_api::ItemTreeVTable, Component_appcard_116>;
};

class Component_empty_99 {
    public:
    slint::cbindgen_private::ItemTreeWeak self_weak;
    const class SharedGlobals* globals;
    uint32_t tree_index_of_first_child;
    uint32_t tree_index;
    vtable::VWeakMapped<slint::private_api::ItemTreeVTable, class MainWindow const> parent;
    slint::private_api::Property<slint::SharedVector<float>> field_empty_99_empty_101_layout_cache;
    slint::private_api::Property<slint::cbindgen_private::LayoutInfo> field_empty_99_empty_101_layoutinfo_h;
    slint::private_api::Property<slint::cbindgen_private::LayoutInfo> field_empty_99_empty_101_layoutinfo_v;
    slint::private_api::Property<slint::SharedVector<float>> field_empty_99_empty_102_layout_cache;
    slint::private_api::Property<slint::cbindgen_private::LayoutInfo> field_empty_99_empty_102_layoutinfo_h;
    slint::private_api::Property<slint::cbindgen_private::LayoutInfo> field_empty_99_empty_102_layoutinfo_v;
    slint::private_api::Property<slint::SharedVector<float>> field_empty_99_empty_104_layout_cache;
    slint::private_api::Property<slint::cbindgen_private::LayoutInfo> field_empty_99_empty_104_layoutinfo_h;
    slint::private_api::Property<slint::cbindgen_private::LayoutInfo> field_empty_99_empty_104_layoutinfo_v;
    slint::private_api::Property<slint::SharedVector<float>> field_empty_99_empty_107_layout_cache;
    slint::private_api::Property<slint::cbindgen_private::LayoutInfo> field_empty_99_empty_107_layoutinfo_h;
    slint::private_api::Property<slint::cbindgen_private::LayoutInfo> field_empty_99_empty_107_layoutinfo_v;
    slint::private_api::Property<slint::SharedVector<float>> field_empty_99_empty_112_layout_cache;
    slint::private_api::Property<slint::cbindgen_private::LayoutInfo> field_empty_99_empty_112_layoutinfo_h;
    slint::private_api::Property<slint::cbindgen_private::LayoutInfo> field_empty_99_empty_112_layoutinfo_v;
    slint::private_api::Property<int> field_empty_99_grid_area_114_total_rows;
    slint::private_api::Property<slint::SharedVector<float>> field_empty_99_layout_cache;
    slint::private_api::Property<slint::cbindgen_private::LayoutInfo> field_empty_99_layoutinfo_h;
    slint::private_api::Property<slint::cbindgen_private::LayoutInfo> field_empty_99_layoutinfo_v;
    slint::private_api::Property<float> field_empty_99_rectangle_100_height;
    slint::private_api::Property<slint::cbindgen_private::LayoutInfo> field_empty_99_rectangle_100_layoutinfo_v;
    slint::private_api::Property<float> field_empty_99_rectangle_100_width;
    slint::private_api::Property<slint::cbindgen_private::LayoutInfo> field_empty_99_rectangle_108_layoutinfo_h;
    slint::private_api::Property<slint::cbindgen_private::LayoutInfo> field_empty_99_rectangle_108_layoutinfo_v;
    slint::private_api::Property<float> field_empty_99_text_110_min_height;
    slint::private_api::Property<float> field_empty_99_text_110_min_width;
    slint::private_api::Property<float> field_empty_99_text_110_preferred_height;
    slint::private_api::Property<float> field_empty_99_text_110_preferred_width;
    slint::private_api::Property<float> field_empty_99_width;
    slint::private_api::Callback<void(slint::SharedString)> field_empty_99_textinput_113_accessible_action_set_value;
    slint::cbindgen_private::Empty field_empty_99 = {};
    slint::cbindgen_private::BasicBorderRectangle field_rectangle_100 = {};
    slint::cbindgen_private::Empty field_empty_102 = {};
    slint::cbindgen_private::SimpleText field_text_103 = {};
    slint::cbindgen_private::Empty field_empty_104 = {};
    slint::cbindgen_private::SimpleText field_text_105 = {};
    slint::cbindgen_private::SimpleText field_text_106 = {};
    slint::cbindgen_private::Empty field_empty_107 = {};
    slint::cbindgen_private::BasicBorderRectangle field_rectangle_108 = {};
    slint::cbindgen_private::TouchArea field_home_ta_109 = {};
    slint::cbindgen_private::SimpleText field_text_110 = {};
    slint::cbindgen_private::BasicBorderRectangle field_rectangle_111 = {};
    slint::cbindgen_private::TextInput field_textinput_113 = {};
    slint::cbindgen_private::Flickable field_grid_area_114 = {};
    slint::cbindgen_private::Empty field_grid_area_viewport_115 = {};
    slint::private_api::Repeater<class Component_appcard_116, UiPackage> repeater_0;
    auto fn_layoutinfo_v_with_constraint ([[maybe_unused]] float arg_0) const -> slint::cbindgen_private::LayoutInfo;
    auto init (const class SharedGlobals* globals,slint::cbindgen_private::ItemTreeWeak enclosing_component,uint32_t tree_index,uint32_t tree_index_of_first_child,class MainWindow const *parent) -> void;
    auto user_init () -> void;
    auto layout_info (slint::cbindgen_private::Orientation o) const -> slint::cbindgen_private::LayoutInfo;
    auto item_geometry (uint32_t index) const -> slint::cbindgen_private::Rect;
    auto accessible_role (uint32_t index) const -> slint::cbindgen_private::AccessibleRole;
    auto accessible_string_property (uint32_t index, slint::cbindgen_private::AccessibleStringProperty what) const -> std::optional<slint::SharedString>;
    auto accessibility_action (uint32_t index, const slint::cbindgen_private::AccessibilityAction &action) const -> void;
    auto supported_accessibility_actions (uint32_t index) const -> uint32_t;
    auto element_infos (uint32_t index) const -> std::optional<slint::SharedString>;
    auto ensure_instantiated () const -> bool;
    auto visit_dynamic_children (uint32_t dyn_index, [[maybe_unused]] slint::private_api::TraversalOrder order, [[maybe_unused]] slint::private_api::ItemVisitorRefMut visitor) const -> uint64_t;
    auto subtree_range (uintptr_t dyn_index) const -> slint::private_api::IndexRange;
    auto subtree_component (uintptr_t dyn_index, [[maybe_unused]] uintptr_t subtree_index, [[maybe_unused]] slint::private_api::ItemTreeWeak *result) const -> void;
    private:
    static auto visit_children (slint::private_api::ItemTreeRef component, intptr_t index, slint::private_api::TraversalOrder order, slint::private_api::ItemVisitorRefMut visitor) -> uint64_t;
    static auto get_item_ref (slint::private_api::ItemTreeRef component, uint32_t index) -> slint::private_api::ItemRef;
    static auto get_subtree_range ([[maybe_unused]] slint::private_api::ItemTreeRef component, [[maybe_unused]] uint32_t dyn_index) -> slint::private_api::IndexRange;
    static auto get_subtree ([[maybe_unused]] slint::private_api::ItemTreeRef component, [[maybe_unused]] uint32_t dyn_index, [[maybe_unused]] uintptr_t subtree_index, [[maybe_unused]] slint::private_api::ItemTreeWeak *result) -> void;
    static auto get_item_tree (slint::private_api::ItemTreeRef) -> slint::cbindgen_private::Slice<slint::private_api::ItemTreeNode>;
    static auto parent_node ([[maybe_unused]] slint::private_api::ItemTreeRef component, [[maybe_unused]] slint::private_api::ItemWeak *result) -> void;
    static auto embed_component ([[maybe_unused]] slint::private_api::ItemTreeRef component, [[maybe_unused]] const slint::private_api::ItemTreeWeak *parent_component, [[maybe_unused]] const uint32_t parent_index) -> bool;
    static auto subtree_index ([[maybe_unused]] slint::private_api::ItemTreeRef component) -> uintptr_t;
    static auto item_tree () -> slint::cbindgen_private::Slice<slint::private_api::ItemTreeNode>;
    static auto item_array () -> const slint::private_api::ItemArray;
    static auto layout_info ([[maybe_unused]] slint::private_api::ItemTreeRef component, slint::cbindgen_private::Orientation o) -> slint::cbindgen_private::LayoutInfo;
    static auto ensure_instantiated ([[maybe_unused]] slint::private_api::ItemTreeRef component) -> bool;
    static auto item_geometry ([[maybe_unused]] slint::private_api::ItemTreeRef component, uint32_t index) -> slint::cbindgen_private::LogicalRect;
    static auto accessible_role ([[maybe_unused]] slint::private_api::ItemTreeRef component, uint32_t index) -> slint::cbindgen_private::AccessibleRole;
    static auto accessible_string_property ([[maybe_unused]] slint::private_api::ItemTreeRef component, uint32_t index, slint::cbindgen_private::AccessibleStringProperty what, slint::SharedString *result) -> bool;
    static auto accessibility_action ([[maybe_unused]] slint::private_api::ItemTreeRef component, uint32_t index, const slint::cbindgen_private::AccessibilityAction *action) -> void;
    static auto supported_accessibility_actions ([[maybe_unused]] slint::private_api::ItemTreeRef component, uint32_t index) -> uint32_t;
    static auto element_infos ([[maybe_unused]] slint::private_api::ItemTreeRef component, [[maybe_unused]] uint32_t index, [[maybe_unused]] slint::SharedString *result) -> bool;
    static auto window_adapter ([[maybe_unused]] slint::private_api::ItemTreeRef component, [[maybe_unused]] bool do_create, [[maybe_unused]] slint::cbindgen_private::Option<slint::private_api::WindowAdapterRc>* result) -> void;
    public:
    static const slint::private_api::ItemTreeVTable static_vtable;
    static auto create (class MainWindow const * parent) -> slint::ComponentHandle<Component_empty_99>;
    ~Component_empty_99 ();
    auto init () -> void;
    auto layout_item_info (slint::cbindgen_private::Orientation o, [[maybe_unused]] std::optional<size_t> child_index) const -> slint::cbindgen_private::LayoutItemInfo;
    auto flexbox_layout_item_info (slint::cbindgen_private::Orientation o, [[maybe_unused]] std::optional<size_t> child_index) const -> slint::cbindgen_private::FlexboxLayoutItemInfo;
    friend class vtable::VRc<slint::private_api::ItemTreeVTable, Component_empty_99>;
};

class Component_detailsview_119 {
    public:
    slint::cbindgen_private::ItemTreeWeak self_weak;
    const class SharedGlobals* globals;
    uint32_t tree_index_of_first_child;
    uint32_t tree_index;
    vtable::VWeakMapped<slint::private_api::ItemTreeVTable, class MainWindow const> parent;
    DetailsView_root_32 field_detailsview_119;
    auto init (const class SharedGlobals* globals,slint::cbindgen_private::ItemTreeWeak enclosing_component,uint32_t tree_index,uint32_t tree_index_of_first_child,class MainWindow const *parent) -> void;
    auto user_init () -> void;
    auto layout_info (slint::cbindgen_private::Orientation o) const -> slint::cbindgen_private::LayoutInfo;
    auto item_geometry (uint32_t index) const -> slint::cbindgen_private::Rect;
    auto accessible_role (uint32_t index) const -> slint::cbindgen_private::AccessibleRole;
    auto accessible_string_property (uint32_t index, slint::cbindgen_private::AccessibleStringProperty what) const -> std::optional<slint::SharedString>;
    auto accessibility_action (uint32_t index, const slint::cbindgen_private::AccessibilityAction &action) const -> void;
    auto supported_accessibility_actions (uint32_t index) const -> uint32_t;
    auto element_infos (uint32_t index) const -> std::optional<slint::SharedString>;
    auto ensure_instantiated () const -> bool;
    auto visit_dynamic_children (uint32_t dyn_index, [[maybe_unused]] slint::private_api::TraversalOrder order, [[maybe_unused]] slint::private_api::ItemVisitorRefMut visitor) const -> uint64_t;
    auto subtree_range (uintptr_t dyn_index) const -> slint::private_api::IndexRange;
    auto subtree_component (uintptr_t dyn_index, [[maybe_unused]] uintptr_t subtree_index, [[maybe_unused]] slint::private_api::ItemTreeWeak *result) const -> void;
    private:
    static auto visit_children (slint::private_api::ItemTreeRef component, intptr_t index, slint::private_api::TraversalOrder order, slint::private_api::ItemVisitorRefMut visitor) -> uint64_t;
    static auto get_item_ref (slint::private_api::ItemTreeRef component, uint32_t index) -> slint::private_api::ItemRef;
    static auto get_subtree_range ([[maybe_unused]] slint::private_api::ItemTreeRef component, [[maybe_unused]] uint32_t dyn_index) -> slint::private_api::IndexRange;
    static auto get_subtree ([[maybe_unused]] slint::private_api::ItemTreeRef component, [[maybe_unused]] uint32_t dyn_index, [[maybe_unused]] uintptr_t subtree_index, [[maybe_unused]] slint::private_api::ItemTreeWeak *result) -> void;
    static auto get_item_tree (slint::private_api::ItemTreeRef) -> slint::cbindgen_private::Slice<slint::private_api::ItemTreeNode>;
    static auto parent_node ([[maybe_unused]] slint::private_api::ItemTreeRef component, [[maybe_unused]] slint::private_api::ItemWeak *result) -> void;
    static auto embed_component ([[maybe_unused]] slint::private_api::ItemTreeRef component, [[maybe_unused]] const slint::private_api::ItemTreeWeak *parent_component, [[maybe_unused]] const uint32_t parent_index) -> bool;
    static auto subtree_index ([[maybe_unused]] slint::private_api::ItemTreeRef component) -> uintptr_t;
    static auto item_tree () -> slint::cbindgen_private::Slice<slint::private_api::ItemTreeNode>;
    static auto item_array () -> const slint::private_api::ItemArray;
    static auto layout_info ([[maybe_unused]] slint::private_api::ItemTreeRef component, slint::cbindgen_private::Orientation o) -> slint::cbindgen_private::LayoutInfo;
    static auto ensure_instantiated ([[maybe_unused]] slint::private_api::ItemTreeRef component) -> bool;
    static auto item_geometry ([[maybe_unused]] slint::private_api::ItemTreeRef component, uint32_t index) -> slint::cbindgen_private::LogicalRect;
    static auto accessible_role ([[maybe_unused]] slint::private_api::ItemTreeRef component, uint32_t index) -> slint::cbindgen_private::AccessibleRole;
    static auto accessible_string_property ([[maybe_unused]] slint::private_api::ItemTreeRef component, uint32_t index, slint::cbindgen_private::AccessibleStringProperty what, slint::SharedString *result) -> bool;
    static auto accessibility_action ([[maybe_unused]] slint::private_api::ItemTreeRef component, uint32_t index, const slint::cbindgen_private::AccessibilityAction *action) -> void;
    static auto supported_accessibility_actions ([[maybe_unused]] slint::private_api::ItemTreeRef component, uint32_t index) -> uint32_t;
    static auto element_infos ([[maybe_unused]] slint::private_api::ItemTreeRef component, [[maybe_unused]] uint32_t index, [[maybe_unused]] slint::SharedString *result) -> bool;
    static auto window_adapter ([[maybe_unused]] slint::private_api::ItemTreeRef component, [[maybe_unused]] bool do_create, [[maybe_unused]] slint::cbindgen_private::Option<slint::private_api::WindowAdapterRc>* result) -> void;
    public:
    static const slint::private_api::ItemTreeVTable static_vtable;
    static auto create (class MainWindow const * parent) -> slint::ComponentHandle<Component_detailsview_119>;
    ~Component_detailsview_119 ();
    auto init () -> void;
    auto layout_item_info (slint::cbindgen_private::Orientation o, [[maybe_unused]] std::optional<size_t> child_index) const -> slint::cbindgen_private::LayoutItemInfo;
    auto flexbox_layout_item_info (slint::cbindgen_private::Orientation o, [[maybe_unused]] std::optional<size_t> child_index) const -> slint::cbindgen_private::FlexboxLayoutItemInfo;
    friend class vtable::VRc<slint::private_api::ItemTreeVTable, Component_detailsview_119>;
};

class MainWindow {
    SharedGlobals m_globals;
    public:
    slint::cbindgen_private::ItemTreeWeak self_weak;
    private:
    const class SharedGlobals* globals;
    uint32_t tree_index_of_first_child;
    uint32_t tree_index;
    slint::private_api::Property<UiPackageDetails> field_root_98_current_details;
    slint::private_api::Property<UiPackage> field_root_98_current_package;
    slint::private_api::Property<std::shared_ptr<slint::Model<UiPackage>>> field_root_98_current_suggestions;
    slint::private_api::Property<bool> field_root_98_is_showing_details;
    slint::private_api::Property<std::shared_ptr<slint::Model<UiPackage>>> field_root_98_packages;
    slint::private_api::Property<slint::SharedString> field_root_98_search_query;
    slint::private_api::Callback<void(UiPackage)> field_root_98_app_clicked;
    slint::private_api::Property<uint8_t> callback_tracker_root_98_app_clicked;
    slint::private_api::Callback<void()> field_root_98_back_clicked;
    slint::private_api::Property<uint8_t> callback_tracker_root_98_back_clicked;
    slint::private_api::Callback<void(UiPackage)> field_root_98_install_clicked;
    slint::private_api::Property<uint8_t> callback_tracker_root_98_install_clicked;
    slint::private_api::Callback<void(UiPackage)> field_root_98_remove_clicked;
    slint::private_api::Property<uint8_t> callback_tracker_root_98_remove_clicked;
    slint::private_api::Callback<void(slint::SharedString)> field_root_98_search_changed;
    slint::private_api::Property<uint8_t> callback_tracker_root_98_search_changed;
    slint::cbindgen_private::WindowItem field_root_98 = {};
    slint::private_api::Conditional<class Component_empty_99> repeater_0;
    slint::private_api::Conditional<class Component_detailsview_119> repeater_1;
    auto init (const class SharedGlobals* globals,slint::cbindgen_private::ItemTreeWeak enclosing_component,uint32_t tree_index,uint32_t tree_index_of_first_child) -> void;
    auto user_init () -> void;
    auto layout_info (slint::cbindgen_private::Orientation o) const -> slint::cbindgen_private::LayoutInfo;
    auto item_geometry (uint32_t index) const -> slint::cbindgen_private::Rect;
    auto accessible_role (uint32_t index) const -> slint::cbindgen_private::AccessibleRole;
    auto accessible_string_property (uint32_t index, slint::cbindgen_private::AccessibleStringProperty what) const -> std::optional<slint::SharedString>;
    auto accessibility_action (uint32_t index, const slint::cbindgen_private::AccessibilityAction &action) const -> void;
    auto supported_accessibility_actions (uint32_t index) const -> uint32_t;
    auto element_infos (uint32_t index) const -> std::optional<slint::SharedString>;
    auto ensure_instantiated () const -> bool;
    auto visit_dynamic_children (uint32_t dyn_index, [[maybe_unused]] slint::private_api::TraversalOrder order, [[maybe_unused]] slint::private_api::ItemVisitorRefMut visitor) const -> uint64_t;
    auto subtree_range (uintptr_t dyn_index) const -> slint::private_api::IndexRange;
    auto subtree_component (uintptr_t dyn_index, [[maybe_unused]] uintptr_t subtree_index, [[maybe_unused]] slint::private_api::ItemTreeWeak *result) const -> void;
    static auto visit_children (slint::private_api::ItemTreeRef component, intptr_t index, slint::private_api::TraversalOrder order, slint::private_api::ItemVisitorRefMut visitor) -> uint64_t;
    static auto get_item_ref (slint::private_api::ItemTreeRef component, uint32_t index) -> slint::private_api::ItemRef;
    static auto get_subtree_range ([[maybe_unused]] slint::private_api::ItemTreeRef component, [[maybe_unused]] uint32_t dyn_index) -> slint::private_api::IndexRange;
    static auto get_subtree ([[maybe_unused]] slint::private_api::ItemTreeRef component, [[maybe_unused]] uint32_t dyn_index, [[maybe_unused]] uintptr_t subtree_index, [[maybe_unused]] slint::private_api::ItemTreeWeak *result) -> void;
    static auto get_item_tree (slint::private_api::ItemTreeRef) -> slint::cbindgen_private::Slice<slint::private_api::ItemTreeNode>;
    static auto parent_node ([[maybe_unused]] slint::private_api::ItemTreeRef component, [[maybe_unused]] slint::private_api::ItemWeak *result) -> void;
    static auto embed_component ([[maybe_unused]] slint::private_api::ItemTreeRef component, [[maybe_unused]] const slint::private_api::ItemTreeWeak *parent_component, [[maybe_unused]] const uint32_t parent_index) -> bool;
    static auto subtree_index ([[maybe_unused]] slint::private_api::ItemTreeRef component) -> uintptr_t;
    static auto item_tree () -> slint::cbindgen_private::Slice<slint::private_api::ItemTreeNode>;
    static auto item_array () -> const slint::private_api::ItemArray;
    static auto layout_info ([[maybe_unused]] slint::private_api::ItemTreeRef component, slint::cbindgen_private::Orientation o) -> slint::cbindgen_private::LayoutInfo;
    static auto ensure_instantiated ([[maybe_unused]] slint::private_api::ItemTreeRef component) -> bool;
    static auto item_geometry ([[maybe_unused]] slint::private_api::ItemTreeRef component, uint32_t index) -> slint::cbindgen_private::LogicalRect;
    static auto accessible_role ([[maybe_unused]] slint::private_api::ItemTreeRef component, uint32_t index) -> slint::cbindgen_private::AccessibleRole;
    static auto accessible_string_property ([[maybe_unused]] slint::private_api::ItemTreeRef component, uint32_t index, slint::cbindgen_private::AccessibleStringProperty what, slint::SharedString *result) -> bool;
    static auto accessibility_action ([[maybe_unused]] slint::private_api::ItemTreeRef component, uint32_t index, const slint::cbindgen_private::AccessibilityAction *action) -> void;
    static auto supported_accessibility_actions ([[maybe_unused]] slint::private_api::ItemTreeRef component, uint32_t index) -> uint32_t;
    static auto element_infos ([[maybe_unused]] slint::private_api::ItemTreeRef component, [[maybe_unused]] uint32_t index, [[maybe_unused]] slint::SharedString *result) -> bool;
    static auto window_adapter ([[maybe_unused]] slint::private_api::ItemTreeRef component, [[maybe_unused]] bool do_create, [[maybe_unused]] slint::cbindgen_private::Option<slint::private_api::WindowAdapterRc>* result) -> void;
    public:
    static const slint::private_api::ItemTreeVTable static_vtable;
    static auto create () -> slint::ComponentHandle<MainWindow>;
    ~MainWindow ();
    auto invoke_app_clicked (UiPackage arg_0) const -> void;
    template<std::invocable<UiPackage> Functor> auto on_app_clicked (Functor && callback_handler) const;
    auto invoke_back_clicked () const -> void;
    template<std::invocable<> Functor> auto on_back_clicked (Functor && callback_handler) const;
    auto get_current_details () const -> UiPackageDetails;
    auto set_current_details (const UiPackageDetails &value) const -> void;
    auto get_current_package () const -> UiPackage;
    auto set_current_package (const UiPackage &value) const -> void;
    auto get_current_suggestions () const -> std::shared_ptr<slint::Model<UiPackage>>;
    auto set_current_suggestions (const std::shared_ptr<slint::Model<UiPackage>> &value) const -> void;
    auto invoke_install_clicked (UiPackage arg_0) const -> void;
    template<std::invocable<UiPackage> Functor> auto on_install_clicked (Functor && callback_handler) const;
    auto get_is_showing_details () const -> bool;
    auto set_is_showing_details (const bool &value) const -> void;
    auto get_packages () const -> std::shared_ptr<slint::Model<UiPackage>>;
    auto set_packages (const std::shared_ptr<slint::Model<UiPackage>> &value) const -> void;
    auto invoke_remove_clicked (UiPackage arg_0) const -> void;
    template<std::invocable<UiPackage> Functor> auto on_remove_clicked (Functor && callback_handler) const;
    auto invoke_search_changed (slint::SharedString arg_0) const -> void;
    template<std::invocable<slint::SharedString> Functor> auto on_search_changed (Functor && callback_handler) const;
    auto get_search_query () const -> slint::SharedString;
    auto set_search_query (const slint::SharedString &value) const -> void;
    auto show () -> void;
    auto hide () -> void;
    auto window () const -> slint::Window&;
    auto run () -> void;
    friend class Theme_121;
    friend class FluentPalette_123;
    friend class vtable::VRc<slint::private_api::ItemTreeVTable, MainWindow>;
    friend class Component_appcard_116;
    friend class Component_empty_99;
    friend class Component_detailsview_119;
    friend class slint::private_api::WindowAdapterRc;
    friend class Component_empty_99;
    friend class Component_appcard_116;
    friend class Component_detailsview_119;
};

template<std::invocable<UiPackage> Functor> inline auto MainWindow::on_app_clicked (Functor && callback_handler) const{
    slint::private_api::assert_main_thread();
    [[maybe_unused]] auto self = this;
    self->field_root_98_app_clicked.set_handler(std::forward<Functor>(callback_handler));
    self->callback_tracker_root_98_app_clicked.mark_dirty();
}

template<std::invocable<> Functor> inline auto MainWindow::on_back_clicked (Functor && callback_handler) const{
    slint::private_api::assert_main_thread();
    [[maybe_unused]] auto self = this;
    self->field_root_98_back_clicked.set_handler(std::forward<Functor>(callback_handler));
    self->callback_tracker_root_98_back_clicked.mark_dirty();
}

template<std::invocable<UiPackage> Functor> inline auto MainWindow::on_install_clicked (Functor && callback_handler) const{
    slint::private_api::assert_main_thread();
    [[maybe_unused]] auto self = this;
    self->field_root_98_install_clicked.set_handler(std::forward<Functor>(callback_handler));
    self->callback_tracker_root_98_install_clicked.mark_dirty();
}

template<std::invocable<UiPackage> Functor> inline auto MainWindow::on_remove_clicked (Functor && callback_handler) const{
    slint::private_api::assert_main_thread();
    [[maybe_unused]] auto self = this;
    self->field_root_98_remove_clicked.set_handler(std::forward<Functor>(callback_handler));
    self->callback_tracker_root_98_remove_clicked.mark_dirty();
}

template<std::invocable<slint::SharedString> Functor> inline auto MainWindow::on_search_changed (Functor && callback_handler) const{
    slint::private_api::assert_main_thread();
    [[maybe_unused]] auto self = this;
    self->field_root_98_search_changed.set_handler(std::forward<Functor>(callback_handler));
    self->callback_tracker_root_98_search_changed.mark_dirty();
}
