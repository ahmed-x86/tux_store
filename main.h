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

class Component_image_49 {
    public:
    slint::cbindgen_private::ItemTreeWeak self_weak;
    const class SharedGlobals* globals;
    uint32_t tree_index_of_first_child;
    uint32_t tree_index;
    vtable::VWeakMapped<slint::private_api::ItemTreeVTable, class DetailsView_root_32 const> parent;
    slint::cbindgen_private::ImageItem field_image_49 = {};
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
    static auto create (class DetailsView_root_32 const * parent) -> slint::ComponentHandle<Component_image_49>;
    ~Component_image_49 ();
    auto init () -> void;
    auto layout_item_info (slint::cbindgen_private::Orientation o, [[maybe_unused]] std::optional<size_t> child_index) const -> slint::cbindgen_private::LayoutItemInfo;
    auto flexbox_layout_item_info (slint::cbindgen_private::Orientation o, [[maybe_unused]] std::optional<size_t> child_index) const -> slint::cbindgen_private::FlexboxLayoutItemInfo;
    friend class vtable::VRc<slint::private_api::ItemTreeVTable, Component_image_49>;
};

class Component_rectangle_51 {
    public:
    slint::cbindgen_private::ItemTreeWeak self_weak;
    const class SharedGlobals* globals;
    uint32_t tree_index_of_first_child;
    uint32_t tree_index;
    vtable::VWeakMapped<slint::private_api::ItemTreeVTable, class DetailsView_root_32 const> parent;
    slint::cbindgen_private::BasicBorderRectangle field_rectangle_51 = {};
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
    static auto create (class DetailsView_root_32 const * parent) -> slint::ComponentHandle<Component_rectangle_51>;
    ~Component_rectangle_51 ();
    auto init () -> void;
    auto layout_item_info (slint::cbindgen_private::Orientation o, [[maybe_unused]] std::optional<size_t> child_index) const -> slint::cbindgen_private::LayoutItemInfo;
    auto flexbox_layout_item_info (slint::cbindgen_private::Orientation o, [[maybe_unused]] std::optional<size_t> child_index) const -> slint::cbindgen_private::FlexboxLayoutItemInfo;
    friend class vtable::VRc<slint::private_api::ItemTreeVTable, Component_rectangle_51>;
};

class Component_text_68 {
    public:
    slint::cbindgen_private::ItemTreeWeak self_weak;
    const class SharedGlobals* globals;
    uint32_t tree_index_of_first_child;
    uint32_t tree_index;
    vtable::VWeakMapped<slint::private_api::ItemTreeVTable, class DetailsView_root_32 const> parent;
    slint::cbindgen_private::SimpleText field_text_68 = {};
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
    static auto create (class DetailsView_root_32 const * parent) -> slint::ComponentHandle<Component_text_68>;
    ~Component_text_68 ();
    auto init () -> void;
    auto layout_item_info (slint::cbindgen_private::Orientation o, [[maybe_unused]] std::optional<size_t> child_index) const -> slint::cbindgen_private::LayoutItemInfo;
    auto flexbox_layout_item_info (slint::cbindgen_private::Orientation o, [[maybe_unused]] std::optional<size_t> child_index) const -> slint::cbindgen_private::FlexboxLayoutItemInfo;
    friend class vtable::VRc<slint::private_api::ItemTreeVTable, Component_text_68>;
};

class Component_text_70 {
    public:
    slint::cbindgen_private::ItemTreeWeak self_weak;
    const class SharedGlobals* globals;
    uint32_t tree_index_of_first_child;
    uint32_t tree_index;
    vtable::VWeakMapped<slint::private_api::ItemTreeVTable, class DetailsView_root_32 const> parent;
    slint::cbindgen_private::SimpleText field_text_70 = {};
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
    static auto create (class DetailsView_root_32 const * parent) -> slint::ComponentHandle<Component_text_70>;
    ~Component_text_70 ();
    auto init () -> void;
    auto layout_item_info (slint::cbindgen_private::Orientation o, [[maybe_unused]] std::optional<size_t> child_index) const -> slint::cbindgen_private::LayoutItemInfo;
    auto flexbox_layout_item_info (slint::cbindgen_private::Orientation o, [[maybe_unused]] std::optional<size_t> child_index) const -> slint::cbindgen_private::FlexboxLayoutItemInfo;
    friend class vtable::VRc<slint::private_api::ItemTreeVTable, Component_text_70>;
};

class Component_empty_72 {
    public:
    slint::cbindgen_private::ItemTreeWeak self_weak;
    const class SharedGlobals* globals;
    uint32_t tree_index_of_first_child;
    uint32_t tree_index;
    vtable::VWeakMapped<slint::private_api::ItemTreeVTable, class DetailsView_root_32 const> parent;
    slint::private_api::Property<slint::SharedVector<float>> field_empty_72_empty_75_layout_cache;
    slint::private_api::Property<slint::cbindgen_private::LayoutInfo> field_empty_72_empty_75_layoutinfo_h;
    slint::private_api::Property<slint::cbindgen_private::LayoutInfo> field_empty_72_empty_75_layoutinfo_v;
    slint::private_api::Property<slint::SharedVector<float>> field_empty_72_empty_78_layout_cache;
    slint::private_api::Property<slint::cbindgen_private::LayoutInfo> field_empty_72_empty_78_layoutinfo_h;
    slint::private_api::Property<slint::cbindgen_private::LayoutInfo> field_empty_72_empty_78_layoutinfo_v;
    slint::private_api::Property<slint::SharedVector<float>> field_empty_72_empty_79_layout_cache;
    slint::private_api::Property<slint::cbindgen_private::LayoutInfo> field_empty_72_empty_79_layoutinfo_h;
    slint::private_api::Property<slint::cbindgen_private::LayoutInfo> field_empty_72_empty_79_layoutinfo_v;
    slint::private_api::Property<slint::SharedVector<float>> field_empty_72_empty_82_layout_cache;
    slint::private_api::Property<slint::cbindgen_private::LayoutInfo> field_empty_72_empty_82_layoutinfo_h;
    slint::private_api::Property<slint::cbindgen_private::LayoutInfo> field_empty_72_empty_82_layoutinfo_v;
    slint::private_api::Property<slint::SharedVector<float>> field_empty_72_empty_85_layout_cache;
    slint::private_api::Property<slint::cbindgen_private::LayoutInfo> field_empty_72_empty_85_layoutinfo_h;
    slint::private_api::Property<slint::cbindgen_private::LayoutInfo> field_empty_72_empty_85_layoutinfo_v;
    slint::private_api::Property<slint::SharedVector<float>> field_empty_72_layout_cache;
    slint::private_api::Property<slint::cbindgen_private::LayoutInfo> field_empty_72_layoutinfo_h;
    slint::private_api::Property<slint::cbindgen_private::LayoutInfo> field_empty_72_layoutinfo_v;
    slint::private_api::Property<float> field_empty_72_rectangle_73_width;
    slint::private_api::Property<float> field_empty_72_width;
    slint::cbindgen_private::Empty field_empty_72 = {};
    slint::cbindgen_private::BasicBorderRectangle field_rectangle_73 = {};
    slint::cbindgen_private::Clip field__clip_74 = {};
    slint::cbindgen_private::Rectangle field_rectangle_76 = {};
    slint::cbindgen_private::Rectangle field_rectangle_77 = {};
    slint::cbindgen_private::Empty field_empty_78 = {};
    slint::cbindgen_private::Empty field_empty_79 = {};
    slint::cbindgen_private::BasicBorderRectangle field_rectangle_80 = {};
    slint::cbindgen_private::SimpleText field_text_81 = {};
    slint::cbindgen_private::Empty field_empty_82 = {};
    slint::cbindgen_private::BasicBorderRectangle field_rectangle_83 = {};
    slint::cbindgen_private::SimpleText field_text_84 = {};
    slint::cbindgen_private::Empty field_empty_85 = {};
    slint::cbindgen_private::SimpleText field_text_86 = {};
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
    static auto create (class DetailsView_root_32 const * parent) -> slint::ComponentHandle<Component_empty_72>;
    ~Component_empty_72 ();
    auto init () -> void;
    auto layout_item_info (slint::cbindgen_private::Orientation o, [[maybe_unused]] std::optional<size_t> child_index) const -> slint::cbindgen_private::LayoutItemInfo;
    auto flexbox_layout_item_info (slint::cbindgen_private::Orientation o, [[maybe_unused]] std::optional<size_t> child_index) const -> slint::cbindgen_private::FlexboxLayoutItemInfo;
    friend class vtable::VRc<slint::private_api::ItemTreeVTable, Component_empty_72>;
};

class Component_deprow_92 {
    public:
    slint::cbindgen_private::ItemTreeWeak self_weak;
    const class SharedGlobals* globals;
    uint32_t tree_index_of_first_child;
    uint32_t tree_index;
    vtable::VWeakMapped<slint::private_api::ItemTreeVTable, class Component_rectangle_88 const> parent;
    slint::private_api::Property<UiPackageDependency> field_model_data;
    slint::private_api::Property<int> field_model_index;
    DepRow_root_14 field_deprow_92;
    auto init (const class SharedGlobals* globals,slint::cbindgen_private::ItemTreeWeak enclosing_component,uint32_t tree_index,uint32_t tree_index_of_first_child,class Component_rectangle_88 const *parent) -> void;
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
    static auto create (class Component_rectangle_88 const * parent) -> slint::ComponentHandle<Component_deprow_92>;
    ~Component_deprow_92 ();
    auto update_data ([[maybe_unused]] int i, [[maybe_unused]] const UiPackageDependency &data) const -> void;
    auto init () -> void;
    auto layout_item_info (slint::cbindgen_private::Orientation o, [[maybe_unused]] std::optional<size_t> child_index) const -> slint::cbindgen_private::LayoutItemInfo;
    auto flexbox_layout_item_info (slint::cbindgen_private::Orientation o, [[maybe_unused]] std::optional<size_t> child_index) const -> slint::cbindgen_private::FlexboxLayoutItemInfo;
    friend class vtable::VRc<slint::private_api::ItemTreeVTable, Component_deprow_92>;
};

class Component_rectangle_88 {
    public:
    slint::cbindgen_private::ItemTreeWeak self_weak;
    const class SharedGlobals* globals;
    uint32_t tree_index_of_first_child;
    uint32_t tree_index;
    vtable::VWeakMapped<slint::private_api::ItemTreeVTable, class DetailsView_root_32 const> parent;
    slint::private_api::Property<slint::SharedVector<float>> field_rectangle_88_empty_89_layout_cache;
    slint::private_api::Property<slint::cbindgen_private::LayoutInfo> field_rectangle_88_empty_89_layoutinfo_h;
    slint::private_api::Property<slint::cbindgen_private::LayoutInfo> field_rectangle_88_empty_89_layoutinfo_v;
    slint::cbindgen_private::BasicBorderRectangle field_rectangle_88 = {};
    slint::cbindgen_private::SimpleText field_text_90 = {};
    slint::cbindgen_private::Empty field_rectangle_91 = {};
    slint::private_api::Repeater<class Component_deprow_92, UiPackageDependency> repeater_0;
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
    static auto create (class DetailsView_root_32 const * parent) -> slint::ComponentHandle<Component_rectangle_88>;
    ~Component_rectangle_88 ();
    auto init () -> void;
    auto layout_item_info (slint::cbindgen_private::Orientation o, [[maybe_unused]] std::optional<size_t> child_index) const -> slint::cbindgen_private::LayoutItemInfo;
    auto flexbox_layout_item_info (slint::cbindgen_private::Orientation o, [[maybe_unused]] std::optional<size_t> child_index) const -> slint::cbindgen_private::FlexboxLayoutItemInfo;
    friend class vtable::VRc<slint::private_api::ItemTreeVTable, Component_rectangle_88>;
};

class Component_rectangle_95 {
    public:
    slint::cbindgen_private::ItemTreeWeak self_weak;
    const class SharedGlobals* globals;
    uint32_t tree_index_of_first_child;
    uint32_t tree_index;
    vtable::VWeakMapped<slint::private_api::ItemTreeVTable, class DetailsView_root_32 const> parent;
    slint::private_api::Property<slint::SharedVector<float>> field_rectangle_95_empty_96_layout_cache;
    slint::private_api::Property<slint::cbindgen_private::LayoutInfo> field_rectangle_95_empty_96_layoutinfo_h;
    slint::private_api::Property<slint::cbindgen_private::LayoutInfo> field_rectangle_95_empty_96_layoutinfo_v;
    slint::cbindgen_private::BasicBorderRectangle field_rectangle_95 = {};
    slint::cbindgen_private::SimpleText field_text_97 = {};
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
    static auto create (class DetailsView_root_32 const * parent) -> slint::ComponentHandle<Component_rectangle_95>;
    ~Component_rectangle_95 ();
    auto init () -> void;
    auto layout_item_info (slint::cbindgen_private::Orientation o, [[maybe_unused]] std::optional<size_t> child_index) const -> slint::cbindgen_private::LayoutItemInfo;
    auto flexbox_layout_item_info (slint::cbindgen_private::Orientation o, [[maybe_unused]] std::optional<size_t> child_index) const -> slint::cbindgen_private::FlexboxLayoutItemInfo;
    friend class vtable::VRc<slint::private_api::ItemTreeVTable, Component_rectangle_95>;
};

class Component_suggestioncard_104 {
    public:
    slint::cbindgen_private::ItemTreeWeak self_weak;
    const class SharedGlobals* globals;
    uint32_t tree_index_of_first_child;
    uint32_t tree_index;
    vtable::VWeakMapped<slint::private_api::ItemTreeVTable, class Component_empty_99 const> parent;
    slint::private_api::Property<UiPackage> field_model_data;
    slint::private_api::Property<int> field_model_index;
    SuggestionCard_root_20 field_suggestioncard_104;
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
    static auto create (class Component_empty_99 const * parent) -> slint::ComponentHandle<Component_suggestioncard_104>;
    ~Component_suggestioncard_104 ();
    auto update_data ([[maybe_unused]] int i, [[maybe_unused]] const UiPackage &data) const -> void;
    auto init () -> void;
    auto layout_item_info (slint::cbindgen_private::Orientation o, [[maybe_unused]] std::optional<size_t> child_index) const -> slint::cbindgen_private::LayoutItemInfo;
    auto flexbox_layout_item_info (slint::cbindgen_private::Orientation o, [[maybe_unused]] std::optional<size_t> child_index) const -> slint::cbindgen_private::FlexboxLayoutItemInfo;
    friend class vtable::VRc<slint::private_api::ItemTreeVTable, Component_suggestioncard_104>;
};

class Component_empty_99 {
    public:
    slint::cbindgen_private::ItemTreeWeak self_weak;
    const class SharedGlobals* globals;
    uint32_t tree_index_of_first_child;
    uint32_t tree_index;
    vtable::VWeakMapped<slint::private_api::ItemTreeVTable, class DetailsView_root_32 const> parent;
    slint::private_api::Property<slint::SharedVector<float>> field_empty_99_empty_103_layout_cache;
    slint::private_api::Property<slint::cbindgen_private::LayoutInfo> field_empty_99_empty_103_layoutinfo_h;
    slint::private_api::Property<slint::cbindgen_private::LayoutInfo> field_empty_99_empty_103_layoutinfo_v;
    slint::private_api::Property<float> field_empty_99_empty_103_max_width;
    slint::private_api::Property<float> field_empty_99_empty_103_preferred_width;
    slint::private_api::Property<slint::SharedVector<float>> field_empty_99_layout_cache;
    slint::private_api::Property<slint::cbindgen_private::LayoutInfo> field_empty_99_layoutinfo_h;
    slint::private_api::Property<slint::cbindgen_private::LayoutInfo> field_empty_99_layoutinfo_v;
    slint::private_api::Property<float> field_empty_99_scroll_track_106_content_width;
    slint::private_api::Property<float> field_empty_99_scroll_track_106_height;
    slint::private_api::Property<float> field_empty_99_scroll_track_106_max_scroll;
    slint::private_api::Property<float> field_empty_99_scroll_track_106_max_thumb_x;
    slint::private_api::Property<float> field_empty_99_scroll_track_106_thumb_width;
    slint::private_api::Property<float> field_empty_99_scroll_track_106_thumb_x;
    slint::private_api::Property<float> field_empty_99_spacing;
    slint::private_api::Property<float> field_empty_99_suggestions_flick_101_height;
    slint::private_api::Property<float> field_empty_99_suggestions_flick_101_width;
    slint::private_api::Property<float> field_empty_99_thumb_ta_108_press_thumb_x;
    slint::private_api::Property<float> field_empty_99_width;
    slint::cbindgen_private::Empty field_empty_99 = {};
    slint::cbindgen_private::SimpleText field_text_100 = {};
    slint::cbindgen_private::Flickable field_suggestions_flick_101 = {};
    slint::cbindgen_private::Empty field_suggestions_flick_viewport_102 = {};
    slint::cbindgen_private::BasicBorderRectangle field_scroll_track_106 = {};
    slint::cbindgen_private::BasicBorderRectangle field_thumb_107 = {};
    slint::cbindgen_private::TouchArea field_thumb_ta_108 = {};
    slint::private_api::Repeater<class Component_suggestioncard_104, UiPackage> repeater_0;
    auto fn_empty_103_layoutinfo_v_with_constraint ([[maybe_unused]] float arg_0) const -> slint::cbindgen_private::LayoutInfo;
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
    static auto create (class DetailsView_root_32 const * parent) -> slint::ComponentHandle<Component_empty_99>;
    ~Component_empty_99 ();
    auto init () -> void;
    auto layout_item_info (slint::cbindgen_private::Orientation o, [[maybe_unused]] std::optional<size_t> child_index) const -> slint::cbindgen_private::LayoutItemInfo;
    auto flexbox_layout_item_info (slint::cbindgen_private::Orientation o, [[maybe_unused]] std::optional<size_t> child_index) const -> slint::cbindgen_private::FlexboxLayoutItemInfo;
    friend class vtable::VRc<slint::private_api::ItemTreeVTable, Component_empty_99>;
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
    slint::private_api::Property<slint::SharedVector<float>> field_root_32_empty_33_layout_cache;
    slint::private_api::Property<slint::cbindgen_private::LayoutInfo> field_root_32_empty_33_layoutinfo_h;
    slint::private_api::Property<slint::cbindgen_private::LayoutInfo> field_root_32_empty_33_layoutinfo_v;
    slint::private_api::Property<float> field_root_32_empty_33_width;
    slint::private_api::Property<slint::SharedVector<float>> field_root_32_empty_35_layout_cache;
    slint::private_api::Property<slint::cbindgen_private::LayoutInfo> field_root_32_empty_35_layoutinfo_h;
    slint::private_api::Property<slint::cbindgen_private::LayoutInfo> field_root_32_empty_35_layoutinfo_v;
    slint::private_api::Property<slint::SharedVector<float>> field_root_32_empty_36_layout_cache;
    slint::private_api::Property<slint::cbindgen_private::LayoutInfo> field_root_32_empty_36_layoutinfo_h;
    slint::private_api::Property<slint::cbindgen_private::LayoutInfo> field_root_32_empty_36_layoutinfo_v;
    slint::private_api::Property<slint::SharedVector<float>> field_root_32_empty_38_layout_cache;
    slint::private_api::Property<slint::cbindgen_private::LayoutInfo> field_root_32_empty_38_layoutinfo_h;
    slint::private_api::Property<slint::cbindgen_private::LayoutInfo> field_root_32_empty_38_layoutinfo_v;
    slint::private_api::Property<slint::SharedVector<float>> field_root_32_empty_41_layout_cache;
    slint::private_api::Property<slint::cbindgen_private::LayoutInfo> field_root_32_empty_41_layoutinfo_h;
    slint::private_api::Property<slint::cbindgen_private::LayoutInfo> field_root_32_empty_41_layoutinfo_v;
    slint::private_api::Property<slint::cbindgen_private::LayoutAlignment> field_root_32_empty_47_alignment;
    slint::private_api::Property<slint::SharedVector<float>> field_root_32_empty_47_layout_cache;
    slint::private_api::Property<slint::cbindgen_private::LayoutInfo> field_root_32_empty_47_layoutinfo_h;
    slint::private_api::Property<slint::cbindgen_private::LayoutInfo> field_root_32_empty_47_layoutinfo_v;
    slint::private_api::Property<float> field_root_32_empty_47_max_height;
    slint::private_api::Property<float> field_root_32_empty_47_max_width;
    slint::private_api::Property<float> field_root_32_empty_47_padding_bottom;
    slint::private_api::Property<float> field_root_32_empty_47_padding_top;
    slint::private_api::Property<float> field_root_32_empty_47_preferred_height;
    slint::private_api::Property<float> field_root_32_empty_47_preferred_width;
    slint::private_api::Property<float> field_root_32_empty_47_spacing;
    slint::private_api::Property<slint::SharedVector<float>> field_root_32_empty_48_layout_cache;
    slint::private_api::Property<slint::cbindgen_private::LayoutInfo> field_root_32_empty_48_layoutinfo_h;
    slint::private_api::Property<slint::cbindgen_private::LayoutInfo> field_root_32_empty_48_layoutinfo_v;
    slint::private_api::Property<slint::cbindgen_private::LayoutAlignment> field_root_32_empty_53_alignment;
    slint::private_api::Property<slint::SharedVector<float>> field_root_32_empty_53_layout_cache;
    slint::private_api::Property<slint::cbindgen_private::LayoutInfo> field_root_32_empty_53_layoutinfo_h;
    slint::private_api::Property<slint::cbindgen_private::LayoutInfo> field_root_32_empty_53_layoutinfo_v;
    slint::private_api::Property<float> field_root_32_empty_53_spacing;
    slint::private_api::Property<float> field_root_32_empty_53_width;
    slint::private_api::Property<slint::SharedVector<float>> field_root_32_empty_54_layout_cache;
    slint::private_api::Property<slint::cbindgen_private::LayoutInfo> field_root_32_empty_54_layoutinfo_h;
    slint::private_api::Property<slint::cbindgen_private::LayoutInfo> field_root_32_empty_54_layoutinfo_v;
    slint::private_api::Property<slint::SharedVector<float>> field_root_32_empty_65_layout_cache;
    slint::private_api::Property<slint::cbindgen_private::LayoutInfo> field_root_32_empty_65_layoutinfo_h;
    slint::private_api::Property<slint::cbindgen_private::LayoutInfo> field_root_32_empty_65_layoutinfo_v;
    slint::private_api::Property<slint::SharedVector<float>> field_root_32_empty_66_layout_cache;
    slint::private_api::Property<slint::cbindgen_private::LayoutInfo> field_root_32_empty_66_layoutinfo_h;
    slint::private_api::Property<slint::cbindgen_private::LayoutInfo> field_root_32_empty_66_layoutinfo_v;
    slint::private_api::Property<float> field_root_32_flickable_45_max_height;
    slint::private_api::Property<float> field_root_32_flickable_45_preferred_height;
    slint::private_api::Property<float> field_root_32_height;
    slint::private_api::Property<float> field_root_32_instTxt_57_min_height;
    slint::private_api::Property<float> field_root_32_instTxt_57_min_width;
    slint::private_api::Property<float> field_root_32_instTxt_57_preferred_height;
    slint::private_api::Property<float> field_root_32_instTxt_57_preferred_width;
    slint::private_api::Property<float> field_root_32_instTxt_57_x;
    slint::private_api::Property<UiPackage> field_root_32_pkg;
    slint::private_api::Property<float> field_root_32_rectangle_34_height;
    slint::private_api::Property<slint::cbindgen_private::LayoutInfo> field_root_32_rectangle_34_layoutinfo_v;
    slint::private_api::Property<float> field_root_32_rectangle_34_width;
    slint::private_api::Property<slint::cbindgen_private::LayoutInfo> field_root_32_rectangle_42_layoutinfo_h;
    slint::private_api::Property<slint::cbindgen_private::LayoutInfo> field_root_32_rectangle_42_layoutinfo_v;
    slint::private_api::Property<slint::cbindgen_private::LayoutInfo> field_root_32_rectangle_56_layoutinfo_h;
    slint::private_api::Property<slint::cbindgen_private::LayoutInfo> field_root_32_rectangle_56_layoutinfo_v;
    slint::private_api::Property<float> field_root_32_rectangle_61_height;
    slint::private_api::Property<slint::cbindgen_private::LayoutInfo> field_root_32_rectangle_61_layoutinfo_h;
    slint::private_api::Property<slint::cbindgen_private::LayoutInfo> field_root_32_rectangle_61_layoutinfo_v;
    slint::private_api::Property<slint::cbindgen_private::LayoutInfo> field_root_32_rectangle_64_layoutinfo_v;
    slint::private_api::Property<std::shared_ptr<slint::Model<UiPackage>>> field_root_32_suggestions;
    slint::private_api::Property<float> field_root_32_text_44_min_height;
    slint::private_api::Property<float> field_root_32_text_44_min_width;
    slint::private_api::Property<float> field_root_32_text_44_preferred_height;
    slint::private_api::Property<float> field_root_32_text_44_preferred_width;
    slint::private_api::Property<float> field_root_32_text_63_min_height;
    slint::private_api::Property<float> field_root_32_text_63_min_width;
    slint::private_api::Property<float> field_root_32_text_63_preferred_height;
    slint::private_api::Property<float> field_root_32_text_63_preferred_width;
    slint::private_api::Property<float> field_root_32_width;
    slint::private_api::Callback<void()> field_root_32_back_clicked;
    slint::private_api::Callback<void()> field_root_32_install_clicked;
    slint::private_api::Callback<void()> field_root_32_remove_clicked;
    slint::private_api::Callback<void(UiPackage)> field_root_32_suggestion_clicked;
    slint::cbindgen_private::Rectangle field_root_32 = {};
    slint::cbindgen_private::BasicBorderRectangle field_rectangle_34 = {};
    slint::cbindgen_private::Empty field_empty_36 = {};
    slint::cbindgen_private::SimpleText field_text_37 = {};
    slint::cbindgen_private::Empty field_empty_38 = {};
    slint::cbindgen_private::SimpleText field_text_39 = {};
    slint::cbindgen_private::SimpleText field_text_40 = {};
    slint::cbindgen_private::Empty field_empty_41 = {};
    slint::cbindgen_private::BasicBorderRectangle field_rectangle_42 = {};
    slint::cbindgen_private::TouchArea field_back_ta_43 = {};
    slint::cbindgen_private::SimpleText field_text_44 = {};
    slint::cbindgen_private::Flickable field_flickable_45 = {};
    slint::cbindgen_private::Empty field__viewport_46 = {};
    slint::cbindgen_private::Empty field_empty_48 = {};
    slint::cbindgen_private::Empty field_empty_53 = {};
    slint::cbindgen_private::Empty field_empty_54 = {};
    slint::cbindgen_private::ComplexText field_text_55 = {};
    slint::cbindgen_private::BasicBorderRectangle field_rectangle_56 = {};
    slint::cbindgen_private::SimpleText field_instTxt_57 = {};
    slint::cbindgen_private::ComplexText field_text_58 = {};
    slint::cbindgen_private::SimpleText field_text_59 = {};
    slint::cbindgen_private::Empty field_rectangle_60 = {};
    slint::cbindgen_private::BasicBorderRectangle field_rectangle_61 = {};
    slint::cbindgen_private::TouchArea field_toucharea_62 = {};
    slint::cbindgen_private::SimpleText field_text_63 = {};
    slint::cbindgen_private::BasicBorderRectangle field_rectangle_64 = {};
    slint::cbindgen_private::Empty field_empty_66 = {};
    slint::cbindgen_private::SimpleText field_text_67 = {};
    slint::private_api::Conditional<class Component_image_49> repeater_0;
    slint::private_api::Conditional<class Component_rectangle_51> repeater_1;
    slint::private_api::Conditional<class Component_text_68> repeater_2;
    slint::private_api::Conditional<class Component_text_70> repeater_3;
    slint::private_api::Conditional<class Component_empty_72> repeater_4;
    slint::private_api::Conditional<class Component_rectangle_88> repeater_5;
    slint::private_api::Conditional<class Component_rectangle_95> repeater_6;
    slint::private_api::Conditional<class Component_empty_99> repeater_7;
    auto fn_empty_33_layoutinfo_v_with_constraint ([[maybe_unused]] float arg_0) const -> slint::cbindgen_private::LayoutInfo;
    auto fn_empty_47_layoutinfo_v_with_constraint ([[maybe_unused]] float arg_0) const -> slint::cbindgen_private::LayoutInfo;
    auto fn_empty_48_layoutinfo_v_with_constraint ([[maybe_unused]] float arg_0) const -> slint::cbindgen_private::LayoutInfo;
    auto fn_empty_53_layoutinfo_v_with_constraint ([[maybe_unused]] float arg_0) const -> slint::cbindgen_private::LayoutInfo;
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

class Theme_133 {
    public:
    slint::private_api::Property<std::shared_ptr<slint::Model<slint::Color>>> field_accents;
    Theme_133 (const class SharedGlobals *globals);
    private:
    auto init () -> void;
    const class SharedGlobals* globals;
    friend class SharedGlobals;
};

class FluentPalette_135 {
    public:
    slint::private_api::Property<slint::cbindgen_private::ColorScheme> field_color_scheme;
    slint::private_api::Property<bool> field_dark_color_scheme;
    slint::private_api::Property<slint::Brush> field_foreground;
    slint::private_api::Property<slint::Brush> field_selection_background;
    slint::private_api::Property<slint::Brush> field_selection_foreground;
    FluentPalette_135 (const class SharedGlobals *globals);
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
    std::shared_ptr<Theme_133> global_Theme_133 = std::make_shared<Theme_133>(this);
    std::shared_ptr<FluentPalette_135> global_FluentPalette_135 = std::make_shared<FluentPalette_135>(this);
    SharedGlobals (){
        global_Theme_133->init();
        global_FluentPalette_135->init();
    }
    private:
    SharedGlobals (const SharedGlobals& source, const slint::private_api::WindowAdapterRc& adapter) : root_weak(source.root_weak), global_Theme_133(source.global_Theme_133), global_FluentPalette_135(source.global_FluentPalette_135){
        m_window.emplace(adapter);
    }
    public:
    auto clone_with_window_adapter (const slint::private_api::WindowAdapterRc& adapter) const -> SharedGlobals*{
        return new SharedGlobals(*this, adapter);
    }
};

class Component_appcard_128 {
    public:
    slint::cbindgen_private::ItemTreeWeak self_weak;
    const class SharedGlobals* globals;
    uint32_t tree_index_of_first_child;
    uint32_t tree_index;
    vtable::VWeakMapped<slint::private_api::ItemTreeVTable, class Component_empty_111 const> parent;
    slint::private_api::Property<UiPackage> field_model_data;
    slint::private_api::Property<int> field_model_index;
    AppCard_root_1 field_appcard_128;
    auto init (const class SharedGlobals* globals,slint::cbindgen_private::ItemTreeWeak enclosing_component,uint32_t tree_index,uint32_t tree_index_of_first_child,class Component_empty_111 const *parent) -> void;
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
    static auto create (class Component_empty_111 const * parent) -> slint::ComponentHandle<Component_appcard_128>;
    ~Component_appcard_128 ();
    auto update_data ([[maybe_unused]] int i, [[maybe_unused]] const UiPackage &data) const -> void;
    auto init () -> void;
    auto layout_item_info (slint::cbindgen_private::Orientation o, [[maybe_unused]] std::optional<size_t> child_index) const -> slint::cbindgen_private::LayoutItemInfo;
    auto flexbox_layout_item_info (slint::cbindgen_private::Orientation o, [[maybe_unused]] std::optional<size_t> child_index) const -> slint::cbindgen_private::FlexboxLayoutItemInfo;
    friend class vtable::VRc<slint::private_api::ItemTreeVTable, Component_appcard_128>;
};

class Component_empty_111 {
    public:
    slint::cbindgen_private::ItemTreeWeak self_weak;
    const class SharedGlobals* globals;
    uint32_t tree_index_of_first_child;
    uint32_t tree_index;
    vtable::VWeakMapped<slint::private_api::ItemTreeVTable, class MainWindow const> parent;
    slint::private_api::Property<slint::SharedVector<float>> field_empty_111_empty_113_layout_cache;
    slint::private_api::Property<slint::cbindgen_private::LayoutInfo> field_empty_111_empty_113_layoutinfo_h;
    slint::private_api::Property<slint::cbindgen_private::LayoutInfo> field_empty_111_empty_113_layoutinfo_v;
    slint::private_api::Property<slint::SharedVector<float>> field_empty_111_empty_114_layout_cache;
    slint::private_api::Property<slint::cbindgen_private::LayoutInfo> field_empty_111_empty_114_layoutinfo_h;
    slint::private_api::Property<slint::cbindgen_private::LayoutInfo> field_empty_111_empty_114_layoutinfo_v;
    slint::private_api::Property<slint::SharedVector<float>> field_empty_111_empty_116_layout_cache;
    slint::private_api::Property<slint::cbindgen_private::LayoutInfo> field_empty_111_empty_116_layoutinfo_h;
    slint::private_api::Property<slint::cbindgen_private::LayoutInfo> field_empty_111_empty_116_layoutinfo_v;
    slint::private_api::Property<slint::SharedVector<float>> field_empty_111_empty_119_layout_cache;
    slint::private_api::Property<slint::cbindgen_private::LayoutInfo> field_empty_111_empty_119_layoutinfo_h;
    slint::private_api::Property<slint::cbindgen_private::LayoutInfo> field_empty_111_empty_119_layoutinfo_v;
    slint::private_api::Property<slint::SharedVector<float>> field_empty_111_empty_124_layout_cache;
    slint::private_api::Property<slint::cbindgen_private::LayoutInfo> field_empty_111_empty_124_layoutinfo_h;
    slint::private_api::Property<slint::cbindgen_private::LayoutInfo> field_empty_111_empty_124_layoutinfo_v;
    slint::private_api::Property<int> field_empty_111_grid_area_126_total_rows;
    slint::private_api::Property<slint::SharedVector<float>> field_empty_111_layout_cache;
    slint::private_api::Property<slint::cbindgen_private::LayoutInfo> field_empty_111_layoutinfo_h;
    slint::private_api::Property<slint::cbindgen_private::LayoutInfo> field_empty_111_layoutinfo_v;
    slint::private_api::Property<float> field_empty_111_rectangle_112_height;
    slint::private_api::Property<slint::cbindgen_private::LayoutInfo> field_empty_111_rectangle_112_layoutinfo_v;
    slint::private_api::Property<float> field_empty_111_rectangle_112_width;
    slint::private_api::Property<slint::cbindgen_private::LayoutInfo> field_empty_111_rectangle_120_layoutinfo_h;
    slint::private_api::Property<slint::cbindgen_private::LayoutInfo> field_empty_111_rectangle_120_layoutinfo_v;
    slint::private_api::Property<float> field_empty_111_text_122_min_height;
    slint::private_api::Property<float> field_empty_111_text_122_min_width;
    slint::private_api::Property<float> field_empty_111_text_122_preferred_height;
    slint::private_api::Property<float> field_empty_111_text_122_preferred_width;
    slint::private_api::Property<float> field_empty_111_width;
    slint::private_api::Callback<void(slint::SharedString)> field_empty_111_textinput_125_accessible_action_set_value;
    slint::cbindgen_private::Empty field_empty_111 = {};
    slint::cbindgen_private::BasicBorderRectangle field_rectangle_112 = {};
    slint::cbindgen_private::Empty field_empty_114 = {};
    slint::cbindgen_private::SimpleText field_text_115 = {};
    slint::cbindgen_private::Empty field_empty_116 = {};
    slint::cbindgen_private::SimpleText field_text_117 = {};
    slint::cbindgen_private::SimpleText field_text_118 = {};
    slint::cbindgen_private::Empty field_empty_119 = {};
    slint::cbindgen_private::BasicBorderRectangle field_rectangle_120 = {};
    slint::cbindgen_private::TouchArea field_home_ta_121 = {};
    slint::cbindgen_private::SimpleText field_text_122 = {};
    slint::cbindgen_private::BasicBorderRectangle field_rectangle_123 = {};
    slint::cbindgen_private::TextInput field_textinput_125 = {};
    slint::cbindgen_private::Flickable field_grid_area_126 = {};
    slint::cbindgen_private::Empty field_grid_area_viewport_127 = {};
    slint::private_api::Repeater<class Component_appcard_128, UiPackage> repeater_0;
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
    static auto create (class MainWindow const * parent) -> slint::ComponentHandle<Component_empty_111>;
    ~Component_empty_111 ();
    auto init () -> void;
    auto layout_item_info (slint::cbindgen_private::Orientation o, [[maybe_unused]] std::optional<size_t> child_index) const -> slint::cbindgen_private::LayoutItemInfo;
    auto flexbox_layout_item_info (slint::cbindgen_private::Orientation o, [[maybe_unused]] std::optional<size_t> child_index) const -> slint::cbindgen_private::FlexboxLayoutItemInfo;
    friend class vtable::VRc<slint::private_api::ItemTreeVTable, Component_empty_111>;
};

class Component_detailsview_131 {
    public:
    slint::cbindgen_private::ItemTreeWeak self_weak;
    const class SharedGlobals* globals;
    uint32_t tree_index_of_first_child;
    uint32_t tree_index;
    vtable::VWeakMapped<slint::private_api::ItemTreeVTable, class MainWindow const> parent;
    DetailsView_root_32 field_detailsview_131;
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
    static auto create (class MainWindow const * parent) -> slint::ComponentHandle<Component_detailsview_131>;
    ~Component_detailsview_131 ();
    auto init () -> void;
    auto layout_item_info (slint::cbindgen_private::Orientation o, [[maybe_unused]] std::optional<size_t> child_index) const -> slint::cbindgen_private::LayoutItemInfo;
    auto flexbox_layout_item_info (slint::cbindgen_private::Orientation o, [[maybe_unused]] std::optional<size_t> child_index) const -> slint::cbindgen_private::FlexboxLayoutItemInfo;
    friend class vtable::VRc<slint::private_api::ItemTreeVTable, Component_detailsview_131>;
};

class MainWindow {
    SharedGlobals m_globals;
    public:
    slint::cbindgen_private::ItemTreeWeak self_weak;
    private:
    const class SharedGlobals* globals;
    uint32_t tree_index_of_first_child;
    uint32_t tree_index;
    slint::private_api::Property<UiPackageDetails> field_root_110_current_details;
    slint::private_api::Property<UiPackage> field_root_110_current_package;
    slint::private_api::Property<std::shared_ptr<slint::Model<UiPackage>>> field_root_110_current_suggestions;
    slint::private_api::Property<bool> field_root_110_is_showing_details;
    slint::private_api::Property<std::shared_ptr<slint::Model<UiPackage>>> field_root_110_packages;
    slint::private_api::Property<slint::SharedString> field_root_110_search_query;
    slint::private_api::Callback<void(UiPackage)> field_root_110_app_clicked;
    slint::private_api::Property<uint8_t> callback_tracker_root_110_app_clicked;
    slint::private_api::Callback<void()> field_root_110_back_clicked;
    slint::private_api::Property<uint8_t> callback_tracker_root_110_back_clicked;
    slint::private_api::Callback<void(UiPackage)> field_root_110_install_clicked;
    slint::private_api::Property<uint8_t> callback_tracker_root_110_install_clicked;
    slint::private_api::Callback<void(UiPackage)> field_root_110_remove_clicked;
    slint::private_api::Property<uint8_t> callback_tracker_root_110_remove_clicked;
    slint::private_api::Callback<void(slint::SharedString)> field_root_110_search_changed;
    slint::private_api::Property<uint8_t> callback_tracker_root_110_search_changed;
    slint::cbindgen_private::WindowItem field_root_110 = {};
    slint::private_api::Conditional<class Component_empty_111> repeater_0;
    slint::private_api::Conditional<class Component_detailsview_131> repeater_1;
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
    friend class Theme_133;
    friend class FluentPalette_135;
    friend class vtable::VRc<slint::private_api::ItemTreeVTable, MainWindow>;
    friend class Component_appcard_128;
    friend class Component_empty_111;
    friend class Component_detailsview_131;
    friend class slint::private_api::WindowAdapterRc;
    friend class Component_empty_111;
    friend class Component_appcard_128;
    friend class Component_detailsview_131;
};

template<std::invocable<UiPackage> Functor> inline auto MainWindow::on_app_clicked (Functor && callback_handler) const{
    slint::private_api::assert_main_thread();
    [[maybe_unused]] auto self = this;
    self->field_root_110_app_clicked.set_handler(std::forward<Functor>(callback_handler));
    self->callback_tracker_root_110_app_clicked.mark_dirty();
}

template<std::invocable<> Functor> inline auto MainWindow::on_back_clicked (Functor && callback_handler) const{
    slint::private_api::assert_main_thread();
    [[maybe_unused]] auto self = this;
    self->field_root_110_back_clicked.set_handler(std::forward<Functor>(callback_handler));
    self->callback_tracker_root_110_back_clicked.mark_dirty();
}

template<std::invocable<UiPackage> Functor> inline auto MainWindow::on_install_clicked (Functor && callback_handler) const{
    slint::private_api::assert_main_thread();
    [[maybe_unused]] auto self = this;
    self->field_root_110_install_clicked.set_handler(std::forward<Functor>(callback_handler));
    self->callback_tracker_root_110_install_clicked.mark_dirty();
}

template<std::invocable<UiPackage> Functor> inline auto MainWindow::on_remove_clicked (Functor && callback_handler) const{
    slint::private_api::assert_main_thread();
    [[maybe_unused]] auto self = this;
    self->field_root_110_remove_clicked.set_handler(std::forward<Functor>(callback_handler));
    self->callback_tracker_root_110_remove_clicked.mark_dirty();
}

template<std::invocable<slint::SharedString> Functor> inline auto MainWindow::on_search_changed (Functor && callback_handler) const{
    slint::private_api::assert_main_thread();
    [[maybe_unused]] auto self = this;
    self->field_root_110_search_changed.set_handler(std::forward<Functor>(callback_handler));
    self->callback_tracker_root_110_search_changed.mark_dirty();
}
