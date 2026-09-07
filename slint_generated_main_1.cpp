// This file is auto-generated
#include "/mnt/data/github_repos/tux_store/main.h"

const slint::private_api::ItemTreeVTable Component_image_5::static_vtable = { visit_children, get_item_ref, get_subtree_range, get_subtree, get_item_tree, parent_node, embed_component, subtree_index, layout_info, ensure_instantiated, item_geometry, accessible_role, accessible_string_property, accessibility_action, supported_accessibility_actions, element_infos, window_adapter, slint::private_api::drop_in_place<Component_image_5>, slint::private_api::dealloc };

auto Component_image_5::init (const class SharedGlobals* globals,slint::cbindgen_private::ItemTreeWeak enclosing_component,uint32_t tree_index,uint32_t tree_index_of_first_child,class AppCard_root_1 const *parent) -> void{
    auto self = this;
    self->self_weak = enclosing_component;
    self->globals = globals;
    this->tree_index_of_first_child = tree_index_of_first_child;
    self->tree_index = tree_index;
    self->parent = vtable::VRcMapped<slint::private_api::ItemTreeVTable, const AppCard_root_1>(parent->self_weak.lock().value(), parent);
    self->field_image_5.height.set(64);
    self->field_image_5.source.set_binding([this]() {
                            [[maybe_unused]] auto self = this;
                            return slint::private_api::optional_or_default(slint::private_api::optional_transform(self->parent.lock(), [&](auto&&x) { return x->field_root_1_pkg.get(); })).icon;
                        });
    self->field_image_5.width.set(64);
    self->field_image_5.colorize.set_constant();
    self->field_image_5.height.set_constant();
    self->field_image_5.image_fit.set_constant();
    self->field_image_5.image_rendering.set_constant();
    self->field_image_5.width.set_constant();
}

auto Component_image_5::user_init () -> void{
    [[maybe_unused]] auto self = this;
}

auto Component_image_5::layout_info (slint::cbindgen_private::Orientation o) const -> slint::cbindgen_private::LayoutInfo{
    [[maybe_unused]] auto self = this;
    return o == slint::cbindgen_private::Orientation::Horizontal ? [&]{ [[maybe_unused]] auto layout_info = slint::private_api::item_layout_info(SLINT_GET_ITEM_VTABLE(ImageItemVTable), const_cast<slint::cbindgen_private::ImageItem*>(&self->field_image_5), slint::cbindgen_private::Orientation::Horizontal, -1, &self->globals->window().window_handle(), self->self_weak.lock()->into_dyn(), self->tree_index);;return [&](const auto &a_0, const auto &a_1, const auto &a_2, const auto &a_3, const auto &a_4, const auto &a_5){ slint::cbindgen_private::LayoutInfo o{}; o.max = a_0; o.max_percent = a_1; o.min = a_2; o.min_percent = a_3; o.preferred = a_4; o.stretch = a_5; return o; }(64, layout_info.max_percent, 64, layout_info.min_percent, layout_info.preferred, layout_info.stretch); }() : [&]{ [[maybe_unused]] auto layout_info = slint::private_api::item_layout_info(SLINT_GET_ITEM_VTABLE(ImageItemVTable), const_cast<slint::cbindgen_private::ImageItem*>(&self->field_image_5), slint::cbindgen_private::Orientation::Vertical, -1, &self->globals->window().window_handle(), self->self_weak.lock()->into_dyn(), self->tree_index);;return [&](const auto &a_0, const auto &a_1, const auto &a_2, const auto &a_3, const auto &a_4, const auto &a_5){ slint::cbindgen_private::LayoutInfo o{}; o.max = a_0; o.max_percent = a_1; o.min = a_2; o.min_percent = a_3; o.preferred = a_4; o.stretch = a_5; return o; }(64, layout_info.max_percent, 64, layout_info.min_percent, layout_info.preferred, layout_info.stretch); }();
}

auto Component_image_5::item_geometry (uint32_t index) const -> slint::cbindgen_private::Rect{
    [[maybe_unused]] auto self = this;
    switch (index) {
        case 0: return slint::private_api::convert_anonymous_rect(std::make_tuple(float(64), float(64), float(slint::private_api::optional_or_default(slint::private_api::optional_transform(self->parent.lock(), [&](auto&&x) { return slint::private_api::layout_cache_access(x->field_root_1_empty_4_layout_cache.get(), 0, 0, 2); }))), float(0)));
    }
    return {};
}

auto Component_image_5::accessible_role (uint32_t index) const -> slint::cbindgen_private::AccessibleRole{
    [[maybe_unused]] auto self = this;
    switch (index) {
        case 0: return slint::cbindgen_private::AccessibleRole::Image;
    }
    return {};
}

auto Component_image_5::accessible_string_property (uint32_t index, slint::cbindgen_private::AccessibleStringProperty what) const -> std::optional<slint::SharedString>{
    [[maybe_unused]] auto self = this;
    switch ((index << 8) | uintptr_t(what)) {
    }
    return {};
}

auto Component_image_5::accessibility_action (uint32_t index, const slint::cbindgen_private::AccessibilityAction &action) const -> void{
    [[maybe_unused]] auto self = this;
    switch ((index << 8) | uintptr_t(action.tag)) {
    }
    return ;
}

auto Component_image_5::supported_accessibility_actions (uint32_t index) const -> uint32_t{
    [[maybe_unused]] auto self = this;
    switch (index) {
    }
    return {};
}

auto Component_image_5::element_infos (uint32_t index) const -> std::optional<slint::SharedString>{
    [[maybe_unused]] auto self = this;
    switch (index) {
    }
    return {};
}

auto Component_image_5::ensure_instantiated () const -> bool{
    [[maybe_unused]] auto self = this;
    bool _changed = false;
    return _changed;
}

auto Component_image_5::visit_children (slint::private_api::ItemTreeRef component, intptr_t index, slint::private_api::TraversalOrder order, slint::private_api::ItemVisitorRefMut visitor) -> uint64_t{
    static const auto dyn_visit = [] (const void *base,  [[maybe_unused]] slint::private_api::TraversalOrder order, [[maybe_unused]] slint::private_api::ItemVisitorRefMut visitor, [[maybe_unused]] uint32_t dyn_index) -> uint64_t {
        [[maybe_unused]] auto self = reinterpret_cast<const Component_image_5*>(base);
        std::abort();
    };
    auto self_rc = reinterpret_cast<const Component_image_5*>(component.instance)->self_weak.lock()->into_dyn();
    return slint::cbindgen_private::slint_visit_item_tree(&self_rc, get_item_tree(component) , index, order, visitor, dyn_visit);
}

auto Component_image_5::get_item_ref (slint::private_api::ItemTreeRef component, uint32_t index) -> slint::private_api::ItemRef{
    return slint::private_api::get_item_ref(component, get_item_tree(component), item_array(), index);
}

auto Component_image_5::get_subtree_range ([[maybe_unused]] slint::private_api::ItemTreeRef component, [[maybe_unused]] uint32_t dyn_index) -> slint::private_api::IndexRange{
        std::abort();
}

auto Component_image_5::get_subtree ([[maybe_unused]] slint::private_api::ItemTreeRef component, [[maybe_unused]] uint32_t dyn_index, [[maybe_unused]] uintptr_t subtree_index, [[maybe_unused]] slint::private_api::ItemTreeWeak *result) -> void{
        std::abort();
}

auto Component_image_5::get_item_tree (slint::private_api::ItemTreeRef) -> slint::cbindgen_private::Slice<slint::private_api::ItemTreeNode>{
    return item_tree();
}

auto Component_image_5::parent_node ([[maybe_unused]] slint::private_api::ItemTreeRef component, [[maybe_unused]] slint::private_api::ItemWeak *result) -> void{
    auto self = reinterpret_cast<const Component_image_5*>(component.instance);
    auto parent = self->parent.lock().value();
    *result = { parent->self_weak, parent->tree_index_of_first_child + 3 };
}

auto Component_image_5::embed_component ([[maybe_unused]] slint::private_api::ItemTreeRef component, [[maybe_unused]] const slint::private_api::ItemTreeWeak *parent_component, [[maybe_unused]] const uint32_t parent_index) -> bool{
    return false; /* todo! */
}

auto Component_image_5::subtree_index ([[maybe_unused]] slint::private_api::ItemTreeRef component) -> uintptr_t{
    return std::numeric_limits<uintptr_t>::max();
}

auto Component_image_5::item_tree () -> slint::cbindgen_private::Slice<slint::private_api::ItemTreeNode>{
    static const slint::private_api::ItemTreeNode children[] {
        slint::private_api::make_item_node(0, 1, 0, 0, true) };
    return slint::private_api::make_slice(std::span(children));
}

auto Component_image_5::item_array () -> const slint::private_api::ItemArray{
    static const slint::private_api::ItemArrayEntry items[] {
        { SLINT_GET_ITEM_VTABLE(ImageItemVTable),  offsetof(Component_image_5, field_image_5) } };
    return slint::private_api::make_slice(std::span(items));
}

auto Component_image_5::layout_info ([[maybe_unused]] slint::private_api::ItemTreeRef component, slint::cbindgen_private::Orientation o) -> slint::cbindgen_private::LayoutInfo{
    return reinterpret_cast<const Component_image_5*>(component.instance)->layout_info(o);
}

auto Component_image_5::ensure_instantiated ([[maybe_unused]] slint::private_api::ItemTreeRef component) -> bool{
    return reinterpret_cast<const Component_image_5*>(component.instance)->ensure_instantiated();
}

auto Component_image_5::item_geometry ([[maybe_unused]] slint::private_api::ItemTreeRef component, uint32_t index) -> slint::cbindgen_private::LogicalRect{
    return reinterpret_cast<const Component_image_5*>(component.instance)->item_geometry(index);
}

auto Component_image_5::accessible_role ([[maybe_unused]] slint::private_api::ItemTreeRef component, uint32_t index) -> slint::cbindgen_private::AccessibleRole{
    return reinterpret_cast<const Component_image_5*>(component.instance)->accessible_role(index);
}

auto Component_image_5::accessible_string_property ([[maybe_unused]] slint::private_api::ItemTreeRef component, uint32_t index, slint::cbindgen_private::AccessibleStringProperty what, slint::SharedString *result) -> bool{
    if (auto r = reinterpret_cast<const Component_image_5*>(component.instance)->accessible_string_property(index, what)) { *result = *r; return true; } else { return false; }
}

auto Component_image_5::accessibility_action ([[maybe_unused]] slint::private_api::ItemTreeRef component, uint32_t index, const slint::cbindgen_private::AccessibilityAction *action) -> void{
    reinterpret_cast<const Component_image_5*>(component.instance)->accessibility_action(index, *action);
}

auto Component_image_5::supported_accessibility_actions ([[maybe_unused]] slint::private_api::ItemTreeRef component, uint32_t index) -> uint32_t{
    return reinterpret_cast<const Component_image_5*>(component.instance)->supported_accessibility_actions(index);
}

auto Component_image_5::element_infos ([[maybe_unused]] slint::private_api::ItemTreeRef component, [[maybe_unused]] uint32_t index, [[maybe_unused]] slint::SharedString *result) -> bool{
    return false;
}

auto Component_image_5::window_adapter ([[maybe_unused]] slint::private_api::ItemTreeRef component, [[maybe_unused]] bool do_create, [[maybe_unused]] slint::cbindgen_private::Option<slint::private_api::WindowAdapterRc>* result) -> void{
    *reinterpret_cast<slint::private_api::WindowAdapterRc*>(result) = reinterpret_cast<const Component_image_5*>(component.instance)->globals->window().window_handle();
}

auto Component_image_5::create (class AppCard_root_1 const * parent) -> slint::ComponentHandle<Component_image_5>{
    auto self_rc = vtable::VRc<slint::private_api::ItemTreeVTable, Component_image_5>::make();
    auto self = const_cast<Component_image_5 *>(&*self_rc);
    self->self_weak = vtable::VWeak(self_rc).into_dyn();
    slint::private_api::register_item_tree(&self_rc.into_dyn(), parent->globals->m_window);
    self->init(parent->globals, self->self_weak, 0, 1 , parent);
    return slint::ComponentHandle<Component_image_5>{ self_rc };
}

Component_image_5::~Component_image_5 (){
    if (auto &window = globals->m_window) window->window_handle().unregister_item_tree(this, item_array());
}

auto Component_image_5::init () -> void{
    user_init();
}

auto Component_image_5::layout_item_info (slint::cbindgen_private::Orientation o, [[maybe_unused]] std::optional<size_t> child_index) const -> slint::cbindgen_private::LayoutItemInfo{
    return { layout_info({&static_vtable, const_cast<void *>(static_cast<const void *>(this))}, o) };
}

auto Component_image_5::flexbox_layout_item_info (slint::cbindgen_private::Orientation o, [[maybe_unused]] std::optional<size_t> child_index) const -> slint::cbindgen_private::FlexboxLayoutItemInfo{
    auto base = layout_item_info(o, child_index); return { base.constraint, 0.0f, 0.0f, -1.0f, slint::cbindgen_private::FlexboxLayoutAlignSelf::Auto, 0 };
}

const slint::private_api::ItemTreeVTable Component_rectangle_7::static_vtable = { visit_children, get_item_ref, get_subtree_range, get_subtree, get_item_tree, parent_node, embed_component, subtree_index, layout_info, ensure_instantiated, item_geometry, accessible_role, accessible_string_property, accessibility_action, supported_accessibility_actions, element_infos, window_adapter, slint::private_api::drop_in_place<Component_rectangle_7>, slint::private_api::dealloc };

auto Component_rectangle_7::init (const class SharedGlobals* globals,slint::cbindgen_private::ItemTreeWeak enclosing_component,uint32_t tree_index,uint32_t tree_index_of_first_child,class AppCard_root_1 const *parent) -> void{
    auto self = this;
    self->self_weak = enclosing_component;
    self->globals = globals;
    this->tree_index_of_first_child = tree_index_of_first_child;
    self->tree_index = tree_index;
    self->parent = vtable::VRcMapped<slint::private_api::ItemTreeVTable, const AppCard_root_1>(parent->self_weak.lock().value(), parent);
    self->field_rectangle_7.background.set_binding([this]() {
                            [[maybe_unused]] auto self = this;
                            return [&]{ [[maybe_unused]] auto tmp_Theme_219_accents = self->globals->global_Theme_219->field_accents.get();;return slint::Brush(slint::private_api::access_array_index(tmp_Theme_219_accents, ([](float a, float b) { auto r = std::fmod(a, b); return r >= 0 ? r : r + std::abs(b); })(slint::private_api::optional_or_default(slint::private_api::optional_transform(self->parent.lock(), [&](auto&&x) { return x->field_root_1_accent_idx.get(); })),slint::private_api::model_length(tmp_Theme_219_accents)))); }();
                        });
    self->field_rectangle_7.border_radius.set(12);
    self->field_rectangle_7_layoutinfo_h.set_binding([this]() {
                            [[maybe_unused]] auto self = this;
                            return ([&](const auto &a_0, const auto &a_1, const auto &a_2, const auto &a_3, const auto &a_4, const auto &a_5){ slint::cbindgen_private::LayoutInfo o{}; o.max = a_0; o.max_percent = a_1; o.min = a_2; o.min_percent = a_3; o.preferred = a_4; o.stretch = a_5; return o; }(+3.4028234663852886e38, 100, 0, 0, 0, 1) + slint::private_api::item_layout_info(SLINT_GET_ITEM_VTABLE(SimpleTextVTable), const_cast<slint::cbindgen_private::SimpleText*>(&self->field_text_8), slint::cbindgen_private::Orientation::Horizontal, -1, &self->globals->window().window_handle(), self->self_weak.lock()->into_dyn(), self->tree_index_of_first_child + 1 - 1));
                        });
    self->field_rectangle_7_layoutinfo_v.set_binding([this]() {
                            [[maybe_unused]] auto self = this;
                            return ([&](const auto &a_0, const auto &a_1, const auto &a_2, const auto &a_3, const auto &a_4, const auto &a_5){ slint::cbindgen_private::LayoutInfo o{}; o.max = a_0; o.max_percent = a_1; o.min = a_2; o.min_percent = a_3; o.preferred = a_4; o.stretch = a_5; return o; }(+3.4028234663852886e38, 100, 0, 0, 0, 1) + slint::private_api::item_layout_info(SLINT_GET_ITEM_VTABLE(SimpleTextVTable), const_cast<slint::cbindgen_private::SimpleText*>(&self->field_text_8), slint::cbindgen_private::Orientation::Vertical, -1, &self->globals->window().window_handle(), self->self_weak.lock()->into_dyn(), self->tree_index_of_first_child + 1 - 1));
                        });
    self->field_rectangle_7_text_8_min_height.set_binding([this]() {
                            [[maybe_unused]] auto self = this;
                            return slint::private_api::item_layout_info(SLINT_GET_ITEM_VTABLE(SimpleTextVTable), const_cast<slint::cbindgen_private::SimpleText*>(&self->field_text_8), slint::cbindgen_private::Orientation::Vertical, -1, &self->globals->window().window_handle(), self->self_weak.lock()->into_dyn(), self->tree_index_of_first_child + 1 - 1).min;
                        });
    self->field_rectangle_7_text_8_min_width.set_binding([this]() {
                            [[maybe_unused]] auto self = this;
                            return slint::private_api::item_layout_info(SLINT_GET_ITEM_VTABLE(SimpleTextVTable), const_cast<slint::cbindgen_private::SimpleText*>(&self->field_text_8), slint::cbindgen_private::Orientation::Horizontal, -1, &self->globals->window().window_handle(), self->self_weak.lock()->into_dyn(), self->tree_index_of_first_child + 1 - 1).min;
                        });
    self->field_rectangle_7_text_8_preferred_height.set_binding([this]() {
                            [[maybe_unused]] auto self = this;
                            return slint::private_api::item_layout_info(SLINT_GET_ITEM_VTABLE(SimpleTextVTable), const_cast<slint::cbindgen_private::SimpleText*>(&self->field_text_8), slint::cbindgen_private::Orientation::Vertical, -1, &self->globals->window().window_handle(), self->self_weak.lock()->into_dyn(), self->tree_index_of_first_child + 1 - 1).preferred;
                        });
    self->field_rectangle_7_text_8_preferred_width.set_binding([this]() {
                            [[maybe_unused]] auto self = this;
                            return slint::private_api::item_layout_info(SLINT_GET_ITEM_VTABLE(SimpleTextVTable), const_cast<slint::cbindgen_private::SimpleText*>(&self->field_text_8), slint::cbindgen_private::Orientation::Horizontal, -1, &self->globals->window().window_handle(), self->self_weak.lock()->into_dyn(), self->tree_index_of_first_child + 1 - 1).preferred;
                        });
    self->field_text_8.color.set(slint::Brush(slint::Color::from_argb_encoded(+4.279308571e9)));
    self->field_text_8.font_size.set(24);
    self->field_text_8.height.set_binding([this]() {
                            [[maybe_unused]] auto self = this;
                            return std::max<float>(self->field_rectangle_7_text_8_preferred_height.get(), self->field_rectangle_7_text_8_min_height.get());
                        });
    self->field_text_8.horizontal_alignment.set(slint::cbindgen_private::TextHorizontalAlignment::Center);
    self->field_text_8.text.set(slint::SharedString(u8"\U000021bb"));
    self->field_text_8.vertical_alignment.set(slint::cbindgen_private::TextVerticalAlignment::Center);
    self->field_text_8.width.set_binding([this]() {
                            [[maybe_unused]] auto self = this;
                            return std::max<float>(self->field_rectangle_7_text_8_preferred_width.get(), self->field_rectangle_7_text_8_min_width.get());
                        });
    self->field_rectangle_7.border_color.set_constant();
    self->field_rectangle_7.border_radius.set_constant();
    self->field_rectangle_7.border_width.set_constant();
    self->field_text_8.color.set_constant();
    self->field_text_8.font_size.set_constant();
    self->field_text_8.font_weight.set_constant();
    self->field_text_8.horizontal_alignment.set_constant();
    self->field_text_8.text.set_constant();
    self->field_text_8.vertical_alignment.set_constant();
}

auto Component_rectangle_7::user_init () -> void{
    [[maybe_unused]] auto self = this;
}

auto Component_rectangle_7::layout_info (slint::cbindgen_private::Orientation o) const -> slint::cbindgen_private::LayoutInfo{
    [[maybe_unused]] auto self = this;
    return o == slint::cbindgen_private::Orientation::Horizontal ? [&]{ [[maybe_unused]] auto layout_info = self->field_rectangle_7_layoutinfo_h.get();;return [&](const auto &a_0, const auto &a_1, const auto &a_2, const auto &a_3, const auto &a_4, const auto &a_5){ slint::cbindgen_private::LayoutInfo o{}; o.max = a_0; o.max_percent = a_1; o.min = a_2; o.min_percent = a_3; o.preferred = a_4; o.stretch = a_5; return o; }(64, layout_info.max_percent, 64, layout_info.min_percent, layout_info.preferred, layout_info.stretch); }() : [&]{ [[maybe_unused]] auto layout_info = self->field_rectangle_7_layoutinfo_v.get();;return [&](const auto &a_0, const auto &a_1, const auto &a_2, const auto &a_3, const auto &a_4, const auto &a_5){ slint::cbindgen_private::LayoutInfo o{}; o.max = a_0; o.max_percent = a_1; o.min = a_2; o.min_percent = a_3; o.preferred = a_4; o.stretch = a_5; return o; }(64, layout_info.max_percent, 64, layout_info.min_percent, layout_info.preferred, layout_info.stretch); }();
}

auto Component_rectangle_7::item_geometry (uint32_t index) const -> slint::cbindgen_private::Rect{
    [[maybe_unused]] auto self = this;
    switch (index) {
        case 0: return slint::private_api::convert_anonymous_rect(std::make_tuple(float(64), float(64), float(slint::private_api::optional_or_default(slint::private_api::optional_transform(self->parent.lock(), [&](auto&&x) { return slint::private_api::layout_cache_access(x->field_root_1_empty_4_layout_cache.get(), 2, 0, 2); }))), float(0)));
        case 1: return slint::private_api::convert_anonymous_rect(std::make_tuple(float(self->field_text_8.height.get()), float(self->field_text_8.width.get()), float(((64 -(float) self->field_text_8.width.get()) /(float) 2)), float(((64 -(float) self->field_text_8.height.get()) /(float) 2))));
    }
    return {};
}

auto Component_rectangle_7::accessible_role (uint32_t index) const -> slint::cbindgen_private::AccessibleRole{
    [[maybe_unused]] auto self = this;
    switch (index) {
        case 1: return slint::cbindgen_private::AccessibleRole::Text;
    }
    return {};
}

auto Component_rectangle_7::accessible_string_property (uint32_t index, slint::cbindgen_private::AccessibleStringProperty what) const -> std::optional<slint::SharedString>{
    [[maybe_unused]] auto self = this;
    switch ((index << 8) | uintptr_t(what)) {
        case (1 << 8) | uintptr_t(slint::cbindgen_private::AccessibleStringProperty::Label): return slint::SharedString(u8"\U000021bb");
    }
    return {};
}

auto Component_rectangle_7::accessibility_action (uint32_t index, const slint::cbindgen_private::AccessibilityAction &action) const -> void{
    [[maybe_unused]] auto self = this;
    switch ((index << 8) | uintptr_t(action.tag)) {
    }
    return ;
}

auto Component_rectangle_7::supported_accessibility_actions (uint32_t index) const -> uint32_t{
    [[maybe_unused]] auto self = this;
    switch (index) {
    }
    return {};
}

auto Component_rectangle_7::element_infos (uint32_t index) const -> std::optional<slint::SharedString>{
    [[maybe_unused]] auto self = this;
    switch (index) {
    }
    return {};
}

auto Component_rectangle_7::ensure_instantiated () const -> bool{
    [[maybe_unused]] auto self = this;
    bool _changed = false;
    return _changed;
}

auto Component_rectangle_7::visit_children (slint::private_api::ItemTreeRef component, intptr_t index, slint::private_api::TraversalOrder order, slint::private_api::ItemVisitorRefMut visitor) -> uint64_t{
    static const auto dyn_visit = [] (const void *base,  [[maybe_unused]] slint::private_api::TraversalOrder order, [[maybe_unused]] slint::private_api::ItemVisitorRefMut visitor, [[maybe_unused]] uint32_t dyn_index) -> uint64_t {
        [[maybe_unused]] auto self = reinterpret_cast<const Component_rectangle_7*>(base);
        std::abort();
    };
    auto self_rc = reinterpret_cast<const Component_rectangle_7*>(component.instance)->self_weak.lock()->into_dyn();
    return slint::cbindgen_private::slint_visit_item_tree(&self_rc, get_item_tree(component) , index, order, visitor, dyn_visit);
}

auto Component_rectangle_7::get_item_ref (slint::private_api::ItemTreeRef component, uint32_t index) -> slint::private_api::ItemRef{
    return slint::private_api::get_item_ref(component, get_item_tree(component), item_array(), index);
}

auto Component_rectangle_7::get_subtree_range ([[maybe_unused]] slint::private_api::ItemTreeRef component, [[maybe_unused]] uint32_t dyn_index) -> slint::private_api::IndexRange{
        std::abort();
}

auto Component_rectangle_7::get_subtree ([[maybe_unused]] slint::private_api::ItemTreeRef component, [[maybe_unused]] uint32_t dyn_index, [[maybe_unused]] uintptr_t subtree_index, [[maybe_unused]] slint::private_api::ItemTreeWeak *result) -> void{
        std::abort();
}

auto Component_rectangle_7::get_item_tree (slint::private_api::ItemTreeRef) -> slint::cbindgen_private::Slice<slint::private_api::ItemTreeNode>{
    return item_tree();
}

auto Component_rectangle_7::parent_node ([[maybe_unused]] slint::private_api::ItemTreeRef component, [[maybe_unused]] slint::private_api::ItemWeak *result) -> void{
    auto self = reinterpret_cast<const Component_rectangle_7*>(component.instance);
    auto parent = self->parent.lock().value();
    *result = { parent->self_weak, parent->tree_index_of_first_child + 4 };
}

auto Component_rectangle_7::embed_component ([[maybe_unused]] slint::private_api::ItemTreeRef component, [[maybe_unused]] const slint::private_api::ItemTreeWeak *parent_component, [[maybe_unused]] const uint32_t parent_index) -> bool{
    return false; /* todo! */
}

auto Component_rectangle_7::subtree_index ([[maybe_unused]] slint::private_api::ItemTreeRef component) -> uintptr_t{
    return std::numeric_limits<uintptr_t>::max();
}

auto Component_rectangle_7::item_tree () -> slint::cbindgen_private::Slice<slint::private_api::ItemTreeNode>{
    static const slint::private_api::ItemTreeNode children[] {
        slint::private_api::make_item_node(1, 1, 0, 0, false), 
slint::private_api::make_item_node(0, 2, 0, 1, true) };
    return slint::private_api::make_slice(std::span(children));
}

auto Component_rectangle_7::item_array () -> const slint::private_api::ItemArray{
    static const slint::private_api::ItemArrayEntry items[] {
        { SLINT_GET_ITEM_VTABLE(BasicBorderRectangleVTable),  offsetof(Component_rectangle_7, field_rectangle_7) }, 
{ SLINT_GET_ITEM_VTABLE(SimpleTextVTable),  offsetof(Component_rectangle_7, field_text_8) } };
    return slint::private_api::make_slice(std::span(items));
}

auto Component_rectangle_7::layout_info ([[maybe_unused]] slint::private_api::ItemTreeRef component, slint::cbindgen_private::Orientation o) -> slint::cbindgen_private::LayoutInfo{
    return reinterpret_cast<const Component_rectangle_7*>(component.instance)->layout_info(o);
}

auto Component_rectangle_7::ensure_instantiated ([[maybe_unused]] slint::private_api::ItemTreeRef component) -> bool{
    return reinterpret_cast<const Component_rectangle_7*>(component.instance)->ensure_instantiated();
}

auto Component_rectangle_7::item_geometry ([[maybe_unused]] slint::private_api::ItemTreeRef component, uint32_t index) -> slint::cbindgen_private::LogicalRect{
    return reinterpret_cast<const Component_rectangle_7*>(component.instance)->item_geometry(index);
}

auto Component_rectangle_7::accessible_role ([[maybe_unused]] slint::private_api::ItemTreeRef component, uint32_t index) -> slint::cbindgen_private::AccessibleRole{
    return reinterpret_cast<const Component_rectangle_7*>(component.instance)->accessible_role(index);
}

auto Component_rectangle_7::accessible_string_property ([[maybe_unused]] slint::private_api::ItemTreeRef component, uint32_t index, slint::cbindgen_private::AccessibleStringProperty what, slint::SharedString *result) -> bool{
    if (auto r = reinterpret_cast<const Component_rectangle_7*>(component.instance)->accessible_string_property(index, what)) { *result = *r; return true; } else { return false; }
}

auto Component_rectangle_7::accessibility_action ([[maybe_unused]] slint::private_api::ItemTreeRef component, uint32_t index, const slint::cbindgen_private::AccessibilityAction *action) -> void{
    reinterpret_cast<const Component_rectangle_7*>(component.instance)->accessibility_action(index, *action);
}

auto Component_rectangle_7::supported_accessibility_actions ([[maybe_unused]] slint::private_api::ItemTreeRef component, uint32_t index) -> uint32_t{
    return reinterpret_cast<const Component_rectangle_7*>(component.instance)->supported_accessibility_actions(index);
}

auto Component_rectangle_7::element_infos ([[maybe_unused]] slint::private_api::ItemTreeRef component, [[maybe_unused]] uint32_t index, [[maybe_unused]] slint::SharedString *result) -> bool{
    return false;
}

auto Component_rectangle_7::window_adapter ([[maybe_unused]] slint::private_api::ItemTreeRef component, [[maybe_unused]] bool do_create, [[maybe_unused]] slint::cbindgen_private::Option<slint::private_api::WindowAdapterRc>* result) -> void{
    *reinterpret_cast<slint::private_api::WindowAdapterRc*>(result) = reinterpret_cast<const Component_rectangle_7*>(component.instance)->globals->window().window_handle();
}

auto Component_rectangle_7::create (class AppCard_root_1 const * parent) -> slint::ComponentHandle<Component_rectangle_7>{
    auto self_rc = vtable::VRc<slint::private_api::ItemTreeVTable, Component_rectangle_7>::make();
    auto self = const_cast<Component_rectangle_7 *>(&*self_rc);
    self->self_weak = vtable::VWeak(self_rc).into_dyn();
    slint::private_api::register_item_tree(&self_rc.into_dyn(), parent->globals->m_window);
    self->init(parent->globals, self->self_weak, 0, 1 , parent);
    return slint::ComponentHandle<Component_rectangle_7>{ self_rc };
}

Component_rectangle_7::~Component_rectangle_7 (){
    if (auto &window = globals->m_window) window->window_handle().unregister_item_tree(this, item_array());
}

auto Component_rectangle_7::init () -> void{
    user_init();
}

auto Component_rectangle_7::layout_item_info (slint::cbindgen_private::Orientation o, [[maybe_unused]] std::optional<size_t> child_index) const -> slint::cbindgen_private::LayoutItemInfo{
    return { layout_info({&static_vtable, const_cast<void *>(static_cast<const void *>(this))}, o) };
}

auto Component_rectangle_7::flexbox_layout_item_info (slint::cbindgen_private::Orientation o, [[maybe_unused]] std::optional<size_t> child_index) const -> slint::cbindgen_private::FlexboxLayoutItemInfo{
    auto base = layout_item_info(o, child_index); return { base.constraint, 0.0f, 0.0f, -1.0f, slint::cbindgen_private::FlexboxLayoutAlignSelf::Auto, 0 };
}

auto AppCard_root_1::fn_empty_3_layoutinfo_v_with_constraint ([[maybe_unused]] float arg_0) const -> slint::cbindgen_private::LayoutInfo{
    [[maybe_unused]] auto self = this;
    return slint::private_api::box_layout_info(slint::private_api::make_slice<slint::cbindgen_private::LayoutItemInfo>(std::array<slint::cbindgen_private::LayoutItemInfo, 2>{ slint::cbindgen_private::LayoutItemInfo ( [&](const auto &a_0){ slint::cbindgen_private::LayoutItemInfo o{}; o.constraint = a_0; return o; }(self->fn_empty_4_layoutinfo_v_with_constraint(arg_0)) ), slint::cbindgen_private::LayoutItemInfo ( [&](const auto &a_0){ slint::cbindgen_private::LayoutItemInfo o{}; o.constraint = a_0; return o; }(self->field_root_1_empty_10_layoutinfo_v.get()) ) }.data(), 2),self->field_root_1_empty_3_spacing.get(),[&](const auto &a_0, const auto &a_1){ slint::cbindgen_private::Padding o{}; o.begin = a_0; o.end = a_1; return o; }(self->field_root_1_empty_3_padding.get(), self->field_root_1_empty_3_padding.get()),self->field_root_1_empty_3_alignment.get());
}

auto AppCard_root_1::fn_empty_4_layoutinfo_v_with_constraint ([[maybe_unused]] float arg_0) const -> slint::cbindgen_private::LayoutInfo{
    [[maybe_unused]] auto self = this;
    return [&]{   std::vector<slint::cbindgen_private::LayoutItemInfo> cells_vector;self->repeater_0.track_instance_changes();{
                                    auto start_offset = cells_vector.size();
                                    self->repeater_0.for_each([&](const auto &sub_comp){ cells_vector.push_back(sub_comp->layout_item_info(slint::cbindgen_private::Orientation::Vertical, std::nullopt)); });
                                    cells_vector.resize(start_offset + self->repeater_0.len());
                                }self->repeater_1.track_instance_changes();{
                                    auto start_offset = cells_vector.size();
                                    self->repeater_1.for_each([&](const auto &sub_comp){ cells_vector.push_back(sub_comp->layout_item_info(slint::cbindgen_private::Orientation::Vertical, std::nullopt)); });
                                    cells_vector.resize(start_offset + self->repeater_1.len());
                                } slint::cbindgen_private::Slice<slint::cbindgen_private::LayoutItemInfo>cells = slint::private_api::make_slice(std::span(cells_vector)); return slint::private_api::box_layout_info_ortho(cells,[&](const auto &a_0, const auto &a_1){ slint::cbindgen_private::Padding o{}; o.begin = a_0; o.end = a_1; return o; }(0, 0)); }();
}

auto AppCard_root_1::fn_layoutinfo_v_with_constraint ([[maybe_unused]] float arg_0) const -> slint::cbindgen_private::LayoutInfo{
    [[maybe_unused]] auto self = this;
    return ([&](const auto &a_0, const auto &a_1, const auto &a_2, const auto &a_3, const auto &a_4, const auto &a_5){ slint::cbindgen_private::LayoutInfo o{}; o.max = a_0; o.max_percent = a_1; o.min = a_2; o.min_percent = a_3; o.preferred = a_4; o.stretch = a_5; return o; }(+3.4028234663852886e38, 100, 0, 0, 0, 1) + self->fn_empty_3_layoutinfo_v_with_constraint(arg_0));
}

auto AppCard_root_1::init (const class SharedGlobals* globals,slint::cbindgen_private::ItemTreeWeak enclosing_component,uint32_t tree_index,uint32_t tree_index_of_first_child) -> void{
    auto self = this;
    self->self_weak = enclosing_component;
    self->globals = globals;
    this->tree_index_of_first_child = tree_index_of_first_child;
    self->tree_index = tree_index;
    self->field_root_1.background.set_binding([this]() {
                            [[maybe_unused]] auto self = this;
                            return slint::Brush((self->field_ta_2.has_hover.get() ? slint::Color::from_argb_encoded(+4.28273033e9) : slint::Color::from_argb_encoded(+4.281414212e9)));
                        });
    self->field_root_1.border_color.set_binding([this]() {
                            [[maybe_unused]] auto self = this;
                            return slint::Brush((self->field_ta_2.has_hover.get() ? slint::Color::from_argb_encoded(+4.283980656e9) : slint::Color::from_argb_encoded(+4.28273033e9)));
                        });
    self->field_root_1.border_radius.set(12);
    self->field_root_1.border_width.set(1);
    self->field_root_1_empty_10_layout_cache.set_binding([this]() {
                            [[maybe_unused]] auto self = this;
                            return slint::private_api::solve_box_layout([&](const auto &a_0, const auto &a_1, const auto &a_2, const auto &a_3, const auto &a_4){ slint::cbindgen_private::BoxLayoutData o{}; o.alignment = a_0; o.cells = a_1; o.padding = a_2; o.size = a_3; o.spacing = a_4; return o; }(slint::cbindgen_private::LayoutAlignment::Stretch, slint::private_api::make_slice<slint::cbindgen_private::LayoutItemInfo>(std::array<slint::cbindgen_private::LayoutItemInfo, 3>{ slint::cbindgen_private::LayoutItemInfo ( [&](const auto &a_0){ slint::cbindgen_private::LayoutItemInfo o{}; o.constraint = a_0; return o; }(slint::private_api::item_layout_info(SLINT_GET_ITEM_VTABLE(ComplexTextVTable), const_cast<slint::cbindgen_private::ComplexText*>(&self->field_text_11), slint::cbindgen_private::Orientation::Vertical, -1, &self->globals->window().window_handle(), self->self_weak.lock()->into_dyn(), self->tree_index_of_first_child + 6 - 1)) ), slint::cbindgen_private::LayoutItemInfo ( [&](const auto &a_0){ slint::cbindgen_private::LayoutItemInfo o{}; o.constraint = a_0; return o; }(slint::private_api::item_layout_info(SLINT_GET_ITEM_VTABLE(ComplexTextVTable), const_cast<slint::cbindgen_private::ComplexText*>(&self->field_text_12), slint::cbindgen_private::Orientation::Vertical, -1, &self->globals->window().window_handle(), self->self_weak.lock()->into_dyn(), self->tree_index_of_first_child + 7 - 1)) ), slint::cbindgen_private::LayoutItemInfo ( [&](const auto &a_0){ slint::cbindgen_private::LayoutItemInfo o{}; o.constraint = a_0; return o; }(slint::private_api::item_layout_info(SLINT_GET_ITEM_VTABLE(SimpleTextVTable), const_cast<slint::cbindgen_private::SimpleText*>(&self->field_text_13), slint::cbindgen_private::Orientation::Vertical, -1, &self->globals->window().window_handle(), self->self_weak.lock()->into_dyn(), self->tree_index_of_first_child + 8 - 1)) ) }.data(), 3), [&](const auto &a_0, const auto &a_1){ slint::cbindgen_private::Padding o{}; o.begin = a_0; o.end = a_1; return o; }(0, 0), self->field_root_1_empty_3_layout_cache.get()[3], 3),slint::private_api::make_slice<int>(std::array<int, 0>{  }.data(), 0));
                        });
    self->field_root_1_empty_10_layoutinfo_h.set_binding([this]() {
                            [[maybe_unused]] auto self = this;
                            return slint::private_api::box_layout_info_ortho(slint::private_api::make_slice<slint::cbindgen_private::LayoutItemInfo>(std::array<slint::cbindgen_private::LayoutItemInfo, 3>{ slint::cbindgen_private::LayoutItemInfo ( [&](const auto &a_0){ slint::cbindgen_private::LayoutItemInfo o{}; o.constraint = a_0; return o; }(slint::private_api::item_layout_info(SLINT_GET_ITEM_VTABLE(ComplexTextVTable), const_cast<slint::cbindgen_private::ComplexText*>(&self->field_text_11), slint::cbindgen_private::Orientation::Horizontal, -1, &self->globals->window().window_handle(), self->self_weak.lock()->into_dyn(), self->tree_index_of_first_child + 6 - 1)) ), slint::cbindgen_private::LayoutItemInfo ( [&](const auto &a_0){ slint::cbindgen_private::LayoutItemInfo o{}; o.constraint = a_0; return o; }(slint::private_api::item_layout_info(SLINT_GET_ITEM_VTABLE(ComplexTextVTable), const_cast<slint::cbindgen_private::ComplexText*>(&self->field_text_12), slint::cbindgen_private::Orientation::Horizontal, -1, &self->globals->window().window_handle(), self->self_weak.lock()->into_dyn(), self->tree_index_of_first_child + 7 - 1)) ), slint::cbindgen_private::LayoutItemInfo ( [&](const auto &a_0){ slint::cbindgen_private::LayoutItemInfo o{}; o.constraint = a_0; return o; }(slint::private_api::item_layout_info(SLINT_GET_ITEM_VTABLE(SimpleTextVTable), const_cast<slint::cbindgen_private::SimpleText*>(&self->field_text_13), slint::cbindgen_private::Orientation::Horizontal, -1, &self->globals->window().window_handle(), self->self_weak.lock()->into_dyn(), self->tree_index_of_first_child + 8 - 1)) ) }.data(), 3),[&](const auto &a_0, const auto &a_1){ slint::cbindgen_private::Padding o{}; o.begin = a_0; o.end = a_1; return o; }(0, 0));
                        });
    self->field_root_1_empty_10_layoutinfo_v.set_binding([this]() {
                            [[maybe_unused]] auto self = this;
                            return slint::private_api::box_layout_info(slint::private_api::make_slice<slint::cbindgen_private::LayoutItemInfo>(std::array<slint::cbindgen_private::LayoutItemInfo, 3>{ slint::cbindgen_private::LayoutItemInfo ( [&](const auto &a_0){ slint::cbindgen_private::LayoutItemInfo o{}; o.constraint = a_0; return o; }(slint::private_api::item_layout_info(SLINT_GET_ITEM_VTABLE(ComplexTextVTable), const_cast<slint::cbindgen_private::ComplexText*>(&self->field_text_11), slint::cbindgen_private::Orientation::Vertical, -1, &self->globals->window().window_handle(), self->self_weak.lock()->into_dyn(), self->tree_index_of_first_child + 6 - 1)) ), slint::cbindgen_private::LayoutItemInfo ( [&](const auto &a_0){ slint::cbindgen_private::LayoutItemInfo o{}; o.constraint = a_0; return o; }(slint::private_api::item_layout_info(SLINT_GET_ITEM_VTABLE(ComplexTextVTable), const_cast<slint::cbindgen_private::ComplexText*>(&self->field_text_12), slint::cbindgen_private::Orientation::Vertical, -1, &self->globals->window().window_handle(), self->self_weak.lock()->into_dyn(), self->tree_index_of_first_child + 7 - 1)) ), slint::cbindgen_private::LayoutItemInfo ( [&](const auto &a_0){ slint::cbindgen_private::LayoutItemInfo o{}; o.constraint = a_0; return o; }(slint::private_api::item_layout_info(SLINT_GET_ITEM_VTABLE(SimpleTextVTable), const_cast<slint::cbindgen_private::SimpleText*>(&self->field_text_13), slint::cbindgen_private::Orientation::Vertical, -1, &self->globals->window().window_handle(), self->self_weak.lock()->into_dyn(), self->tree_index_of_first_child + 8 - 1)) ) }.data(), 3),3,[&](const auto &a_0, const auto &a_1){ slint::cbindgen_private::Padding o{}; o.begin = a_0; o.end = a_1; return o; }(0, 0),slint::cbindgen_private::LayoutAlignment::Stretch);
                        });
    self->field_root_1_empty_3_alignment.set(slint::cbindgen_private::LayoutAlignment::Center);
    self->field_root_1_empty_3_layout_cache.set_binding([this]() {
                            [[maybe_unused]] auto self = this;
                            return slint::private_api::solve_box_layout([&](const auto &a_0, const auto &a_1, const auto &a_2, const auto &a_3, const auto &a_4){ slint::cbindgen_private::BoxLayoutData o{}; o.alignment = a_0; o.cells = a_1; o.padding = a_2; o.size = a_3; o.spacing = a_4; return o; }(slint::cbindgen_private::LayoutAlignment::Center, slint::private_api::make_slice<slint::cbindgen_private::LayoutItemInfo>(std::array<slint::cbindgen_private::LayoutItemInfo, 2>{ slint::cbindgen_private::LayoutItemInfo ( [&](const auto &a_0){ slint::cbindgen_private::LayoutItemInfo o{}; o.constraint = a_0; return o; }(self->field_root_1_empty_4_layoutinfo_v.get()) ), slint::cbindgen_private::LayoutItemInfo ( [&](const auto &a_0){ slint::cbindgen_private::LayoutItemInfo o{}; o.constraint = a_0; return o; }(self->field_root_1_empty_10_layoutinfo_v.get()) ) }.data(), 2), [&](const auto &a_0, const auto &a_1){ slint::cbindgen_private::Padding o{}; o.begin = a_0; o.end = a_1; return o; }(20, 20), self->field_root_1_height.get(), 12),slint::private_api::make_slice<int>(std::array<int, 0>{  }.data(), 0));
                        });
    self->field_root_1_empty_3_layoutinfo_h.set_binding([this]() {
                            [[maybe_unused]] auto self = this;
                            return slint::private_api::box_layout_info_ortho(slint::private_api::make_slice<slint::cbindgen_private::LayoutItemInfo>(std::array<slint::cbindgen_private::LayoutItemInfo, 2>{ slint::cbindgen_private::LayoutItemInfo ( [&](const auto &a_0){ slint::cbindgen_private::LayoutItemInfo o{}; o.constraint = a_0; return o; }(self->field_root_1_empty_4_layoutinfo_h.get()) ), slint::cbindgen_private::LayoutItemInfo ( [&](const auto &a_0){ slint::cbindgen_private::LayoutItemInfo o{}; o.constraint = a_0; return o; }(self->field_root_1_empty_10_layoutinfo_h.get()) ) }.data(), 2),[&](const auto &a_0, const auto &a_1){ slint::cbindgen_private::Padding o{}; o.begin = a_0; o.end = a_1; return o; }(20, 20));
                        });
    self->field_root_1_empty_3_layoutinfo_v.set_binding([this]() {
                            [[maybe_unused]] auto self = this;
                            return slint::private_api::box_layout_info(slint::private_api::make_slice<slint::cbindgen_private::LayoutItemInfo>(std::array<slint::cbindgen_private::LayoutItemInfo, 2>{ slint::cbindgen_private::LayoutItemInfo ( [&](const auto &a_0){ slint::cbindgen_private::LayoutItemInfo o{}; o.constraint = a_0; return o; }(self->field_root_1_empty_4_layoutinfo_v.get()) ), slint::cbindgen_private::LayoutItemInfo ( [&](const auto &a_0){ slint::cbindgen_private::LayoutItemInfo o{}; o.constraint = a_0; return o; }(self->field_root_1_empty_10_layoutinfo_v.get()) ) }.data(), 2),12,[&](const auto &a_0, const auto &a_1){ slint::cbindgen_private::Padding o{}; o.begin = a_0; o.end = a_1; return o; }(20, 20),slint::cbindgen_private::LayoutAlignment::Center);
                        });
    self->field_root_1_empty_3_padding.set(20);
    self->field_root_1_empty_3_spacing.set(12);
    self->field_root_1_empty_4_layout_cache.set_binding([this]() {
                            [[maybe_unused]] auto self = this;
                            return [&]{ std::array<int, 4> repeated_indices_array;  std::vector<slint::cbindgen_private::LayoutItemInfo> cells_vector;self->repeater_0.track_instance_changes();repeated_indices_array[0] = cells_vector.size();repeated_indices_array[1] = self->repeater_0.len();{
                                    auto start_offset = cells_vector.size();
                                    self->repeater_0.for_each([&](const auto &sub_comp){ cells_vector.push_back(sub_comp->layout_item_info(slint::cbindgen_private::Orientation::Horizontal, std::nullopt)); });
                                    cells_vector.resize(start_offset + self->repeater_0.len());
                                }self->repeater_1.track_instance_changes();repeated_indices_array[2] = cells_vector.size();repeated_indices_array[3] = self->repeater_1.len();{
                                    auto start_offset = cells_vector.size();
                                    self->repeater_1.for_each([&](const auto &sub_comp){ cells_vector.push_back(sub_comp->layout_item_info(slint::cbindgen_private::Orientation::Horizontal, std::nullopt)); });
                                    cells_vector.resize(start_offset + self->repeater_1.len());
                                }slint::cbindgen_private::Slice<int> repeated_indices = slint::private_api::make_slice(std::span(repeated_indices_array)); slint::cbindgen_private::Slice<slint::cbindgen_private::LayoutItemInfo>cells = slint::private_api::make_slice(std::span(cells_vector)); return slint::private_api::solve_box_layout([&](const auto &a_0, const auto &a_1, const auto &a_2, const auto &a_3, const auto &a_4){ slint::cbindgen_private::BoxLayoutData o{}; o.alignment = a_0; o.cells = a_1; o.padding = a_2; o.size = a_3; o.spacing = a_4; return o; }(slint::cbindgen_private::LayoutAlignment::Center, cells, [&](const auto &a_0, const auto &a_1){ slint::cbindgen_private::Padding o{}; o.begin = a_0; o.end = a_1; return o; }(0, 0), ((self->field_root_1_width.get() -(float) 20) -(float) 20), 0),repeated_indices); }();
                        });
    self->field_root_1_empty_4_layoutinfo_h.set_binding([this]() {
                            [[maybe_unused]] auto self = this;
                            return [&]{   std::vector<slint::cbindgen_private::LayoutItemInfo> cells_vector;self->repeater_0.track_instance_changes();{
                                    auto start_offset = cells_vector.size();
                                    self->repeater_0.for_each([&](const auto &sub_comp){ cells_vector.push_back(sub_comp->layout_item_info(slint::cbindgen_private::Orientation::Horizontal, std::nullopt)); });
                                    cells_vector.resize(start_offset + self->repeater_0.len());
                                }self->repeater_1.track_instance_changes();{
                                    auto start_offset = cells_vector.size();
                                    self->repeater_1.for_each([&](const auto &sub_comp){ cells_vector.push_back(sub_comp->layout_item_info(slint::cbindgen_private::Orientation::Horizontal, std::nullopt)); });
                                    cells_vector.resize(start_offset + self->repeater_1.len());
                                } slint::cbindgen_private::Slice<slint::cbindgen_private::LayoutItemInfo>cells = slint::private_api::make_slice(std::span(cells_vector)); return slint::private_api::box_layout_info(cells,0,[&](const auto &a_0, const auto &a_1){ slint::cbindgen_private::Padding o{}; o.begin = a_0; o.end = a_1; return o; }(0, 0),slint::cbindgen_private::LayoutAlignment::Center); }();
                        });
    self->field_root_1_empty_4_layoutinfo_v.set_binding([this]() {
                            [[maybe_unused]] auto self = this;
                            return [&]{   std::vector<slint::cbindgen_private::LayoutItemInfo> cells_vector;self->repeater_0.track_instance_changes();{
                                    auto start_offset = cells_vector.size();
                                    self->repeater_0.for_each([&](const auto &sub_comp){ cells_vector.push_back(sub_comp->layout_item_info(slint::cbindgen_private::Orientation::Vertical, std::nullopt)); });
                                    cells_vector.resize(start_offset + self->repeater_0.len());
                                }self->repeater_1.track_instance_changes();{
                                    auto start_offset = cells_vector.size();
                                    self->repeater_1.for_each([&](const auto &sub_comp){ cells_vector.push_back(sub_comp->layout_item_info(slint::cbindgen_private::Orientation::Vertical, std::nullopt)); });
                                    cells_vector.resize(start_offset + self->repeater_1.len());
                                } slint::cbindgen_private::Slice<slint::cbindgen_private::LayoutItemInfo>cells = slint::private_api::make_slice(std::span(cells_vector)); return slint::private_api::box_layout_info_ortho(cells,[&](const auto &a_0, const auto &a_1){ slint::cbindgen_private::Padding o{}; o.begin = a_0; o.end = a_1; return o; }(0, 0)); }();
                        });
    self->field_ta_2.clicked.set_handler(
                [this]() {
                    [[maybe_unused]] auto self = this;
                    self->field_root_1_clicked.call();
                });
    self->field_ta_2.enabled.set(true);
    self->field_text_11.color.set(slint::Brush(slint::Color::from_argb_encoded(+4.291679988e9)));
    self->field_text_11.font_size.set(14);
    self->field_text_11.font_weight.set(static_cast<int>(700));
    self->field_text_11.height.set_binding([this]() {
                            [[maybe_unused]] auto self = this;
                            return self->field_root_1_empty_10_layout_cache.get()[1];
                        });
    self->field_text_11.horizontal_alignment.set(slint::cbindgen_private::TextHorizontalAlignment::Center);
    self->field_text_11.overflow.set(slint::cbindgen_private::TextOverflow::Elide);
    self->field_text_11.text.set_binding([this]() {
                            [[maybe_unused]] auto self = this;
                            return self->field_root_1_pkg.get().pretty_name;
                        });
    self->field_text_11.width.set_binding([this]() {
                            [[maybe_unused]] auto self = this;
                            return ((self->field_root_1_width.get() -(float) 20) -(float) 20);
                        });
    self->field_text_12.color.set(slint::Brush(slint::Color::from_argb_encoded(+4.2865471e9)));
    self->field_text_12.font_size.set(11);
    self->field_text_12.height.set_binding([this]() {
                            [[maybe_unused]] auto self = this;
                            return self->field_root_1_empty_10_layout_cache.get()[3];
                        });
    self->field_text_12.horizontal_alignment.set(slint::cbindgen_private::TextHorizontalAlignment::Center);
    self->field_text_12.overflow.set(slint::cbindgen_private::TextOverflow::Elide);
    self->field_text_12.text.set_binding([this]() {
                            [[maybe_unused]] auto self = this;
                            return [&]{ [[maybe_unused]] auto tmp_root_1_pkg = self->field_root_1_pkg.get();;return ((tmp_root_1_pkg.repo + slint::SharedString(u8" \U00002022 ")) + tmp_root_1_pkg.version); }();
                        });
    self->field_text_12.width.set_binding([this]() {
                            [[maybe_unused]] auto self = this;
                            return ((self->field_root_1_width.get() -(float) 20) -(float) 20);
                        });
    self->field_text_13.color.set_binding([this]() {
                            [[maybe_unused]] auto self = this;
                            return slint::Brush((self->field_root_1_pkg.get().installed ? slint::Color::from_argb_encoded(+4.289127329e9) : slint::Color::from_argb_encoded(+4.285296774e9)));
                        });
    self->field_text_13.font_size.set(11);
    self->field_text_13.font_weight.set(static_cast<int>(700));
    self->field_text_13.height.set_binding([this]() {
                            [[maybe_unused]] auto self = this;
                            return self->field_root_1_empty_10_layout_cache.get()[5];
                        });
    self->field_text_13.horizontal_alignment.set(slint::cbindgen_private::TextHorizontalAlignment::Center);
    self->field_text_13.text.set_binding([this]() {
                            [[maybe_unused]] auto self = this;
                            return (self->field_root_1_pkg.get().installed ? slint::SharedString(u8"Installed") : slint::SharedString(u8"Not Installed"));
                        });
    self->field_text_13.width.set_binding([this]() {
                            [[maybe_unused]] auto self = this;
                            return ((self->field_root_1_width.get() -(float) 20) -(float) 20);
                        });
    self->field_root_1.border_radius.set_constant();
    self->field_root_1.border_width.set_constant();
    self->field_root_1_empty_3_alignment.set_constant();
    self->field_root_1_empty_3_padding.set_constant();
    self->field_root_1_empty_3_spacing.set_constant();
    self->field_ta_2.enabled.set_constant();
    self->field_ta_2.mouse_cursor.set_constant();
    self->field_text_11.color.set_constant();
    self->field_text_11.font_family.set_constant();
    self->field_text_11.font_italic.set_constant();
    self->field_text_11.font_size.set_constant();
    self->field_text_11.font_weight.set_constant();
    self->field_text_11.horizontal_alignment.set_constant();
    self->field_text_11.letter_spacing.set_constant();
    self->field_text_11.overflow.set_constant();
    self->field_text_11.stroke.set_constant();
    self->field_text_11.stroke_style.set_constant();
    self->field_text_11.stroke_width.set_constant();
    self->field_text_11.vertical_alignment.set_constant();
    self->field_text_11.wrap.set_constant();
    self->field_text_12.color.set_constant();
    self->field_text_12.font_family.set_constant();
    self->field_text_12.font_italic.set_constant();
    self->field_text_12.font_size.set_constant();
    self->field_text_12.font_weight.set_constant();
    self->field_text_12.horizontal_alignment.set_constant();
    self->field_text_12.letter_spacing.set_constant();
    self->field_text_12.overflow.set_constant();
    self->field_text_12.stroke.set_constant();
    self->field_text_12.stroke_style.set_constant();
    self->field_text_12.stroke_width.set_constant();
    self->field_text_12.vertical_alignment.set_constant();
    self->field_text_12.wrap.set_constant();
    self->field_text_13.font_size.set_constant();
    self->field_text_13.font_weight.set_constant();
    self->field_text_13.horizontal_alignment.set_constant();
    self->field_text_13.vertical_alignment.set_constant();
    self->repeater_0.set_model_binding([self] { (void)self; return (self->field_root_1_pkg.get().icon.size().width > 0); });
    self->repeater_1.set_model_binding([self] { (void)self; return (std::abs(float(self->field_root_1_pkg.get().icon.size().width - 0)) < std::numeric_limits<float>::epsilon()); });
}

auto AppCard_root_1::user_init () -> void{
    [[maybe_unused]] auto self = this;
}

auto AppCard_root_1::layout_info (slint::cbindgen_private::Orientation o) const -> slint::cbindgen_private::LayoutInfo{
    [[maybe_unused]] auto self = this;
    return o == slint::cbindgen_private::Orientation::Horizontal ? ([&](const auto &a_0, const auto &a_1, const auto &a_2, const auto &a_3, const auto &a_4, const auto &a_5){ slint::cbindgen_private::LayoutInfo o{}; o.max = a_0; o.max_percent = a_1; o.min = a_2; o.min_percent = a_3; o.preferred = a_4; o.stretch = a_5; return o; }(+3.4028234663852886e38, 100, 0, 0, 0, 1) + self->field_root_1_empty_3_layoutinfo_h.get()) : ([&](const auto &a_0, const auto &a_1, const auto &a_2, const auto &a_3, const auto &a_4, const auto &a_5){ slint::cbindgen_private::LayoutInfo o{}; o.max = a_0; o.max_percent = a_1; o.min = a_2; o.min_percent = a_3; o.preferred = a_4; o.stretch = a_5; return o; }(+3.4028234663852886e38, 100, 0, 0, 0, 1) + self->field_root_1_empty_3_layoutinfo_v.get());
}

auto AppCard_root_1::item_geometry (uint32_t index) const -> slint::cbindgen_private::Rect{
    [[maybe_unused]] auto self = this;
    switch (index) {
        case 0: return slint::private_api::convert_anonymous_rect(std::make_tuple(float(self->field_root_1_height.get()), float(self->field_root_1_width.get()), float(self->field_root_1_x.get()), float(self->field_root_1_y.get())));
        case 1: return slint::private_api::convert_anonymous_rect(std::make_tuple(float(self->field_root_1_height.get()), float(self->field_root_1_width.get()), float(0), float(0)));
        case 2: return slint::private_api::convert_anonymous_rect(std::make_tuple(float(self->field_root_1_empty_3_layout_cache.get()[1]), float(((self->field_root_1_width.get() -(float) 20) -(float) 20)), float(20), float(self->field_root_1_empty_3_layout_cache.get()[0])));
        case 3: return slint::private_api::convert_anonymous_rect(std::make_tuple(float(self->field_root_1_empty_3_layout_cache.get()[3]), float(((self->field_root_1_width.get() -(float) 20) -(float) 20)), float(20), float(self->field_root_1_empty_3_layout_cache.get()[2])));
        case 6: return slint::private_api::convert_anonymous_rect(std::make_tuple(float(self->field_root_1_empty_10_layout_cache.get()[1]), float(((self->field_root_1_width.get() -(float) 20) -(float) 20)), float(0), float(self->field_root_1_empty_10_layout_cache.get()[0])));
        case 7: return slint::private_api::convert_anonymous_rect(std::make_tuple(float(self->field_root_1_empty_10_layout_cache.get()[3]), float(((self->field_root_1_width.get() -(float) 20) -(float) 20)), float(0), float(self->field_root_1_empty_10_layout_cache.get()[2])));
        case 8: return slint::private_api::convert_anonymous_rect(std::make_tuple(float(self->field_root_1_empty_10_layout_cache.get()[5]), float(((self->field_root_1_width.get() -(float) 20) -(float) 20)), float(0), float(self->field_root_1_empty_10_layout_cache.get()[4])));
    }
    return {};
}

auto AppCard_root_1::accessible_role (uint32_t index) const -> slint::cbindgen_private::AccessibleRole{
    [[maybe_unused]] auto self = this;
    switch (index) {
        case 6: return slint::cbindgen_private::AccessibleRole::Text;
        case 7: return slint::cbindgen_private::AccessibleRole::Text;
        case 8: return slint::cbindgen_private::AccessibleRole::Text;
    }
    return {};
}

auto AppCard_root_1::accessible_string_property (uint32_t index, slint::cbindgen_private::AccessibleStringProperty what) const -> std::optional<slint::SharedString>{
    [[maybe_unused]] auto self = this;
    switch ((index << 8) | uintptr_t(what)) {
        case (6 << 8) | uintptr_t(slint::cbindgen_private::AccessibleStringProperty::Label): return self->field_root_1_pkg.get().pretty_name;
        case (7 << 8) | uintptr_t(slint::cbindgen_private::AccessibleStringProperty::Label): return self->field_text_12.text.get();
        case (8 << 8) | uintptr_t(slint::cbindgen_private::AccessibleStringProperty::Label): return self->field_text_13.text.get();
    }
    return {};
}

auto AppCard_root_1::accessibility_action (uint32_t index, const slint::cbindgen_private::AccessibilityAction &action) const -> void{
    [[maybe_unused]] auto self = this;
    switch ((index << 8) | uintptr_t(action.tag)) {
    }
    return ;
}

auto AppCard_root_1::supported_accessibility_actions (uint32_t index) const -> uint32_t{
    [[maybe_unused]] auto self = this;
    switch (index) {
    }
    return {};
}

auto AppCard_root_1::element_infos (uint32_t index) const -> std::optional<slint::SharedString>{
    [[maybe_unused]] auto self = this;
    switch (index) {
    }
    return {};
}

auto AppCard_root_1::ensure_instantiated () const -> bool{
    [[maybe_unused]] auto self = this;
    bool _changed = false;
    _changed |= self->repeater_0.ensure_updated(self);
    _changed |= self->repeater_1.ensure_updated(self);
    return _changed;
}

auto AppCard_root_1::visit_dynamic_children (uint32_t dyn_index, [[maybe_unused]] slint::private_api::TraversalOrder order, [[maybe_unused]] slint::private_api::ItemVisitorRefMut visitor) const -> uint64_t{
        auto self = this;
        switch(dyn_index) { 
        case 0: {
                return self->repeater_0.visit(order, visitor);
            }
        case 1: {
                return self->repeater_1.visit(order, visitor);
            } };
        std::abort();
}

auto AppCard_root_1::subtree_range (uintptr_t dyn_index) const -> slint::private_api::IndexRange{
    [[maybe_unused]] auto self = this;
        switch(dyn_index) { 
        case 0: {
                self->repeater_0.track_instance_changes();
                return self->repeater_0.index_range();
            }
        case 1: {
                self->repeater_1.track_instance_changes();
                return self->repeater_1.index_range();
            } };
        std::abort();
}

auto AppCard_root_1::subtree_component (uintptr_t dyn_index, [[maybe_unused]] uintptr_t subtree_index, [[maybe_unused]] slint::private_api::ItemTreeWeak *result) const -> void{
    [[maybe_unused]] auto self = this;
        switch(dyn_index) { 
        case 0: {
                *result = self->repeater_0.instance_at(subtree_index);
                return;
            }
        case 1: {
                *result = self->repeater_1.instance_at(subtree_index);
                return;
            } };
        std::abort();
}

auto DepRow_root_14::init (const class SharedGlobals* globals,slint::cbindgen_private::ItemTreeWeak enclosing_component,uint32_t tree_index,uint32_t tree_index_of_first_child) -> void{
    auto self = this;
    self->self_weak = enclosing_component;
    self->globals = globals;
    this->tree_index_of_first_child = tree_index_of_first_child;
    self->tree_index = tree_index;
    self->field_root_14_empty_15_layout_cache.set_binding([this]() {
                            [[maybe_unused]] auto self = this;
                            return slint::private_api::solve_box_layout([&](const auto &a_0, const auto &a_1, const auto &a_2, const auto &a_3, const auto &a_4){ slint::cbindgen_private::BoxLayoutData o{}; o.alignment = a_0; o.cells = a_1; o.padding = a_2; o.size = a_3; o.spacing = a_4; return o; }(slint::cbindgen_private::LayoutAlignment::Start, slint::private_api::make_slice<slint::cbindgen_private::LayoutItemInfo>(std::array<slint::cbindgen_private::LayoutItemInfo, 3>{ slint::cbindgen_private::LayoutItemInfo ( [&](const auto &a_0){ slint::cbindgen_private::LayoutItemInfo o{}; o.constraint = a_0; return o; }([&]{ [[maybe_unused]] auto layout_info = self->field_root_14_rectangle_16_layoutinfo_h.get();;return [&](const auto &a_0, const auto &a_1, const auto &a_2, const auto &a_3, const auto &a_4, const auto &a_5){ slint::cbindgen_private::LayoutInfo o{}; o.max = a_0; o.max_percent = a_1; o.min = a_2; o.min_percent = a_3; o.preferred = a_4; o.stretch = a_5; return o; }(18, layout_info.max_percent, 18, layout_info.min_percent, layout_info.preferred, layout_info.stretch); }()) ), slint::cbindgen_private::LayoutItemInfo ( [&](const auto &a_0){ slint::cbindgen_private::LayoutItemInfo o{}; o.constraint = a_0; return o; }([&]{ [[maybe_unused]] auto layout_info = slint::private_api::item_layout_info(SLINT_GET_ITEM_VTABLE(SimpleTextVTable), const_cast<slint::cbindgen_private::SimpleText*>(&self->field_text_18), slint::cbindgen_private::Orientation::Horizontal, -1, &self->globals->window().window_handle(), self->self_weak.lock()->into_dyn(), self->tree_index_of_first_child + 2 - 1);;return [&](const auto &a_0, const auto &a_1, const auto &a_2, const auto &a_3, const auto &a_4, const auto &a_5){ slint::cbindgen_private::LayoutInfo o{}; o.max = a_0; o.max_percent = a_1; o.min = a_2; o.min_percent = a_3; o.preferred = a_4; o.stretch = a_5; return o; }(layout_info.max, layout_info.max_percent, layout_info.min, layout_info.min_percent, layout_info.preferred, 1); }()) ), slint::cbindgen_private::LayoutItemInfo ( [&](const auto &a_0){ slint::cbindgen_private::LayoutItemInfo o{}; o.constraint = a_0; return o; }(slint::private_api::item_layout_info(SLINT_GET_ITEM_VTABLE(SimpleTextVTable), const_cast<slint::cbindgen_private::SimpleText*>(&self->field_text_19), slint::cbindgen_private::Orientation::Horizontal, -1, &self->globals->window().window_handle(), self->self_weak.lock()->into_dyn(), self->tree_index_of_first_child + 3 - 1)) ) }.data(), 3), [&](const auto &a_0, const auto &a_1){ slint::cbindgen_private::Padding o{}; o.begin = a_0; o.end = a_1; return o; }(0, 0), self->field_root_14_width.get(), 10),slint::private_api::make_slice<int>(std::array<int, 0>{  }.data(), 0));
                        });
    self->field_root_14_empty_15_layoutinfo_h.set_binding([this]() {
                            [[maybe_unused]] auto self = this;
                            return slint::private_api::box_layout_info(slint::private_api::make_slice<slint::cbindgen_private::LayoutItemInfo>(std::array<slint::cbindgen_private::LayoutItemInfo, 3>{ slint::cbindgen_private::LayoutItemInfo ( [&](const auto &a_0){ slint::cbindgen_private::LayoutItemInfo o{}; o.constraint = a_0; return o; }([&]{ [[maybe_unused]] auto layout_info = self->field_root_14_rectangle_16_layoutinfo_h.get();;return [&](const auto &a_0, const auto &a_1, const auto &a_2, const auto &a_3, const auto &a_4, const auto &a_5){ slint::cbindgen_private::LayoutInfo o{}; o.max = a_0; o.max_percent = a_1; o.min = a_2; o.min_percent = a_3; o.preferred = a_4; o.stretch = a_5; return o; }(18, layout_info.max_percent, 18, layout_info.min_percent, layout_info.preferred, layout_info.stretch); }()) ), slint::cbindgen_private::LayoutItemInfo ( [&](const auto &a_0){ slint::cbindgen_private::LayoutItemInfo o{}; o.constraint = a_0; return o; }([&]{ [[maybe_unused]] auto layout_info = slint::private_api::item_layout_info(SLINT_GET_ITEM_VTABLE(SimpleTextVTable), const_cast<slint::cbindgen_private::SimpleText*>(&self->field_text_18), slint::cbindgen_private::Orientation::Horizontal, -1, &self->globals->window().window_handle(), self->self_weak.lock()->into_dyn(), self->tree_index_of_first_child + 2 - 1);;return [&](const auto &a_0, const auto &a_1, const auto &a_2, const auto &a_3, const auto &a_4, const auto &a_5){ slint::cbindgen_private::LayoutInfo o{}; o.max = a_0; o.max_percent = a_1; o.min = a_2; o.min_percent = a_3; o.preferred = a_4; o.stretch = a_5; return o; }(layout_info.max, layout_info.max_percent, layout_info.min, layout_info.min_percent, layout_info.preferred, 1); }()) ), slint::cbindgen_private::LayoutItemInfo ( [&](const auto &a_0){ slint::cbindgen_private::LayoutItemInfo o{}; o.constraint = a_0; return o; }(slint::private_api::item_layout_info(SLINT_GET_ITEM_VTABLE(SimpleTextVTable), const_cast<slint::cbindgen_private::SimpleText*>(&self->field_text_19), slint::cbindgen_private::Orientation::Horizontal, -1, &self->globals->window().window_handle(), self->self_weak.lock()->into_dyn(), self->tree_index_of_first_child + 3 - 1)) ) }.data(), 3),10,[&](const auto &a_0, const auto &a_1){ slint::cbindgen_private::Padding o{}; o.begin = a_0; o.end = a_1; return o; }(0, 0),slint::cbindgen_private::LayoutAlignment::Start);
                        });
    self->field_root_14_empty_15_layoutinfo_v.set_binding([this]() {
                            [[maybe_unused]] auto self = this;
                            return slint::private_api::box_layout_info_ortho(slint::private_api::make_slice<slint::cbindgen_private::LayoutItemInfo>(std::array<slint::cbindgen_private::LayoutItemInfo, 3>{ slint::cbindgen_private::LayoutItemInfo ( [&](const auto &a_0){ slint::cbindgen_private::LayoutItemInfo o{}; o.constraint = a_0; return o; }([&]{ [[maybe_unused]] auto layout_info = self->field_root_14_rectangle_16_layoutinfo_v.get();;return [&](const auto &a_0, const auto &a_1, const auto &a_2, const auto &a_3, const auto &a_4, const auto &a_5){ slint::cbindgen_private::LayoutInfo o{}; o.max = a_0; o.max_percent = a_1; o.min = a_2; o.min_percent = a_3; o.preferred = a_4; o.stretch = a_5; return o; }(18, layout_info.max_percent, 18, layout_info.min_percent, layout_info.preferred, layout_info.stretch); }()) ), slint::cbindgen_private::LayoutItemInfo ( [&](const auto &a_0){ slint::cbindgen_private::LayoutItemInfo o{}; o.constraint = a_0; return o; }(slint::private_api::item_layout_info(SLINT_GET_ITEM_VTABLE(SimpleTextVTable), const_cast<slint::cbindgen_private::SimpleText*>(&self->field_text_18), slint::cbindgen_private::Orientation::Vertical, -1, &self->globals->window().window_handle(), self->self_weak.lock()->into_dyn(), self->tree_index_of_first_child + 2 - 1)) ), slint::cbindgen_private::LayoutItemInfo ( [&](const auto &a_0){ slint::cbindgen_private::LayoutItemInfo o{}; o.constraint = a_0; return o; }(slint::private_api::item_layout_info(SLINT_GET_ITEM_VTABLE(SimpleTextVTable), const_cast<slint::cbindgen_private::SimpleText*>(&self->field_text_19), slint::cbindgen_private::Orientation::Vertical, -1, &self->globals->window().window_handle(), self->self_weak.lock()->into_dyn(), self->tree_index_of_first_child + 3 - 1)) ) }.data(), 3),[&](const auto &a_0, const auto &a_1){ slint::cbindgen_private::Padding o{}; o.begin = a_0; o.end = a_1; return o; }(0, 0));
                        });
    self->field_root_14_rectangle_16_layoutinfo_h.set_binding([this]() {
                            [[maybe_unused]] auto self = this;
                            return ([&](const auto &a_0, const auto &a_1, const auto &a_2, const auto &a_3, const auto &a_4, const auto &a_5){ slint::cbindgen_private::LayoutInfo o{}; o.max = a_0; o.max_percent = a_1; o.min = a_2; o.min_percent = a_3; o.preferred = a_4; o.stretch = a_5; return o; }(+3.4028234663852886e38, 100, 0, 0, 0, 1) + slint::private_api::item_layout_info(SLINT_GET_ITEM_VTABLE(SimpleTextVTable), const_cast<slint::cbindgen_private::SimpleText*>(&self->field_text_17), slint::cbindgen_private::Orientation::Horizontal, -1, &self->globals->window().window_handle(), self->self_weak.lock()->into_dyn(), self->tree_index_of_first_child + 4 - 1));
                        });
    self->field_root_14_rectangle_16_layoutinfo_v.set_binding([this]() {
                            [[maybe_unused]] auto self = this;
                            return ([&](const auto &a_0, const auto &a_1, const auto &a_2, const auto &a_3, const auto &a_4, const auto &a_5){ slint::cbindgen_private::LayoutInfo o{}; o.max = a_0; o.max_percent = a_1; o.min = a_2; o.min_percent = a_3; o.preferred = a_4; o.stretch = a_5; return o; }(+3.4028234663852886e38, 100, 0, 0, 0, 1) + slint::private_api::item_layout_info(SLINT_GET_ITEM_VTABLE(SimpleTextVTable), const_cast<slint::cbindgen_private::SimpleText*>(&self->field_text_17), slint::cbindgen_private::Orientation::Vertical, -1, &self->globals->window().window_handle(), self->self_weak.lock()->into_dyn(), self->tree_index_of_first_child + 4 - 1));
                        });
    self->field_root_14_text_17_min_height.set_binding([this]() {
                            [[maybe_unused]] auto self = this;
                            return slint::private_api::item_layout_info(SLINT_GET_ITEM_VTABLE(SimpleTextVTable), const_cast<slint::cbindgen_private::SimpleText*>(&self->field_text_17), slint::cbindgen_private::Orientation::Vertical, -1, &self->globals->window().window_handle(), self->self_weak.lock()->into_dyn(), self->tree_index_of_first_child + 4 - 1).min;
                        });
    self->field_root_14_text_17_min_width.set_binding([this]() {
                            [[maybe_unused]] auto self = this;
                            return slint::private_api::item_layout_info(SLINT_GET_ITEM_VTABLE(SimpleTextVTable), const_cast<slint::cbindgen_private::SimpleText*>(&self->field_text_17), slint::cbindgen_private::Orientation::Horizontal, -1, &self->globals->window().window_handle(), self->self_weak.lock()->into_dyn(), self->tree_index_of_first_child + 4 - 1).min;
                        });
    self->field_root_14_text_17_preferred_height.set_binding([this]() {
                            [[maybe_unused]] auto self = this;
                            return slint::private_api::item_layout_info(SLINT_GET_ITEM_VTABLE(SimpleTextVTable), const_cast<slint::cbindgen_private::SimpleText*>(&self->field_text_17), slint::cbindgen_private::Orientation::Vertical, -1, &self->globals->window().window_handle(), self->self_weak.lock()->into_dyn(), self->tree_index_of_first_child + 4 - 1).preferred;
                        });
    self->field_root_14_text_17_preferred_width.set_binding([this]() {
                            [[maybe_unused]] auto self = this;
                            return slint::private_api::item_layout_info(SLINT_GET_ITEM_VTABLE(SimpleTextVTable), const_cast<slint::cbindgen_private::SimpleText*>(&self->field_text_17), slint::cbindgen_private::Orientation::Horizontal, -1, &self->globals->window().window_handle(), self->self_weak.lock()->into_dyn(), self->tree_index_of_first_child + 4 - 1).preferred;
                        });
    self->field_rectangle_16.background.set_binding([this]() {
                            [[maybe_unused]] auto self = this;
                            return (self->field_root_14_dep.get().installed ? slint::Brush(slint::Color::from_argb_encoded(+4.28273033e9)) : slint::Brush(self->field_root_14_accent.get()).transparentize(0.82));
                        });
    self->field_rectangle_16.border_radius.set(5);
    self->field_text_17.color.set_binding([this]() {
                            [[maybe_unused]] auto self = this;
                            return slint::Brush((self->field_root_14_dep.get().installed ? slint::Color::from_argb_encoded(+4.2865471e9) : self->field_root_14_accent.get()));
                        });
    self->field_text_17.font_size.set(11);
    self->field_text_17.font_weight.set(static_cast<int>(700));
    self->field_text_17.height.set_binding([this]() {
                            [[maybe_unused]] auto self = this;
                            return std::max<float>(self->field_root_14_text_17_preferred_height.get(), self->field_root_14_text_17_min_height.get());
                        });
    self->field_text_17.horizontal_alignment.set(slint::cbindgen_private::TextHorizontalAlignment::Center);
    self->field_text_17.text.set_binding([this]() {
                            [[maybe_unused]] auto self = this;
                            return (self->field_root_14_dep.get().installed ? slint::SharedString(u8"\U00002713") : slint::SharedString(u8"\U00002193"));
                        });
    self->field_text_17.vertical_alignment.set(slint::cbindgen_private::TextVerticalAlignment::Center);
    self->field_text_17.width.set_binding([this]() {
                            [[maybe_unused]] auto self = this;
                            return std::max<float>(self->field_root_14_text_17_preferred_width.get(), self->field_root_14_text_17_min_width.get());
                        });
    self->field_text_18.color.set_binding([this]() {
                            [[maybe_unused]] auto self = this;
                            return slint::Brush((self->field_root_14_dep.get().installed ? slint::Color::from_argb_encoded(+4.289113544e9) : slint::Color::from_argb_encoded(+4.290429662e9)));
                        });
    self->field_text_18.font_size.set(13);
    self->field_text_18.height.set(34);
    self->field_text_18.text.set_binding([this]() {
                            [[maybe_unused]] auto self = this;
                            return self->field_root_14_dep.get().name;
                        });
    self->field_text_18.vertical_alignment.set(slint::cbindgen_private::TextVerticalAlignment::Center);
    self->field_text_18.width.set_binding([this]() {
                            [[maybe_unused]] auto self = this;
                            return self->field_root_14_empty_15_layout_cache.get()[3];
                        });
    self->field_text_19.color.set_binding([this]() {
                            [[maybe_unused]] auto self = this;
                            return slint::Brush((self->field_root_14_dep.get().installed ? slint::Color::from_argb_encoded(+4.2865471e9) : slint::Color::from_argb_encoded(+4.289113544e9)));
                        });
    self->field_text_19.font_size.set(12);
    self->field_text_19.font_weight.set_binding([this]() {
                            [[maybe_unused]] auto self = this;
                            return static_cast<int>((self->field_root_14_dep.get().installed ? 400 : 700));
                        });
    self->field_text_19.height.set(34);
    self->field_text_19.text.set_binding([this]() {
                            [[maybe_unused]] auto self = this;
                            return self->field_root_14_dep.get().size_str;
                        });
    self->field_text_19.vertical_alignment.set(slint::cbindgen_private::TextVerticalAlignment::Center);
    self->field_text_19.width.set_binding([this]() {
                            [[maybe_unused]] auto self = this;
                            return self->field_root_14_empty_15_layout_cache.get()[5];
                        });
    self->field_rectangle_16.border_color.set_constant();
    self->field_rectangle_16.border_radius.set_constant();
    self->field_rectangle_16.border_width.set_constant();
    self->field_text_17.font_size.set_constant();
    self->field_text_17.font_weight.set_constant();
    self->field_text_17.horizontal_alignment.set_constant();
    self->field_text_17.vertical_alignment.set_constant();
    self->field_text_18.font_size.set_constant();
    self->field_text_18.font_weight.set_constant();
    self->field_text_18.height.set_constant();
    self->field_text_18.horizontal_alignment.set_constant();
    self->field_text_18.vertical_alignment.set_constant();
    self->field_text_19.font_size.set_constant();
    self->field_text_19.height.set_constant();
    self->field_text_19.horizontal_alignment.set_constant();
    self->field_text_19.vertical_alignment.set_constant();
}

auto DepRow_root_14::user_init () -> void{
    [[maybe_unused]] auto self = this;
}

auto DepRow_root_14::layout_info (slint::cbindgen_private::Orientation o) const -> slint::cbindgen_private::LayoutInfo{
    [[maybe_unused]] auto self = this;
    return o == slint::cbindgen_private::Orientation::Horizontal ? ([&](const auto &a_0, const auto &a_1, const auto &a_2, const auto &a_3, const auto &a_4, const auto &a_5){ slint::cbindgen_private::LayoutInfo o{}; o.max = a_0; o.max_percent = a_1; o.min = a_2; o.min_percent = a_3; o.preferred = a_4; o.stretch = a_5; return o; }(+3.4028234663852886e38, 100, 0, 0, 0, 1) + self->field_root_14_empty_15_layoutinfo_h.get()) : [&]{ [[maybe_unused]] auto layout_info = ([&](const auto &a_0, const auto &a_1, const auto &a_2, const auto &a_3, const auto &a_4, const auto &a_5){ slint::cbindgen_private::LayoutInfo o{}; o.max = a_0; o.max_percent = a_1; o.min = a_2; o.min_percent = a_3; o.preferred = a_4; o.stretch = a_5; return o; }(+3.4028234663852886e38, 100, 0, 0, 0, 1) + self->field_root_14_empty_15_layoutinfo_v.get());;return [&](const auto &a_0, const auto &a_1, const auto &a_2, const auto &a_3, const auto &a_4, const auto &a_5){ slint::cbindgen_private::LayoutInfo o{}; o.max = a_0; o.max_percent = a_1; o.min = a_2; o.min_percent = a_3; o.preferred = a_4; o.stretch = a_5; return o; }(34, layout_info.max_percent, 34, layout_info.min_percent, layout_info.preferred, layout_info.stretch); }();
}

auto DepRow_root_14::item_geometry (uint32_t index) const -> slint::cbindgen_private::Rect{
    [[maybe_unused]] auto self = this;
    switch (index) {
        case 0: return slint::private_api::convert_anonymous_rect(std::make_tuple(float(34), float(self->field_root_14_width.get()), float(self->field_root_14_x.get()), float(self->field_root_14_y.get())));
        case 1: return slint::private_api::convert_anonymous_rect(std::make_tuple(float(18), float(18), float(self->field_root_14_empty_15_layout_cache.get()[0]), float(0)));
        case 2: return slint::private_api::convert_anonymous_rect(std::make_tuple(float(34), float(self->field_root_14_empty_15_layout_cache.get()[3]), float(self->field_root_14_empty_15_layout_cache.get()[2]), float(0)));
        case 3: return slint::private_api::convert_anonymous_rect(std::make_tuple(float(34), float(self->field_root_14_empty_15_layout_cache.get()[5]), float(self->field_root_14_empty_15_layout_cache.get()[4]), float(0)));
        case 4: return slint::private_api::convert_anonymous_rect(std::make_tuple(float(self->field_text_17.height.get()), float(self->field_text_17.width.get()), float(((18 -(float) self->field_text_17.width.get()) /(float) 2)), float(((18 -(float) self->field_text_17.height.get()) /(float) 2))));
    }
    return {};
}

auto DepRow_root_14::accessible_role (uint32_t index) const -> slint::cbindgen_private::AccessibleRole{
    [[maybe_unused]] auto self = this;
    switch (index) {
        case 2: return slint::cbindgen_private::AccessibleRole::Text;
        case 3: return slint::cbindgen_private::AccessibleRole::Text;
        case 4: return slint::cbindgen_private::AccessibleRole::Text;
    }
    return {};
}

auto DepRow_root_14::accessible_string_property (uint32_t index, slint::cbindgen_private::AccessibleStringProperty what) const -> std::optional<slint::SharedString>{
    [[maybe_unused]] auto self = this;
    switch ((index << 8) | uintptr_t(what)) {
        case (2 << 8) | uintptr_t(slint::cbindgen_private::AccessibleStringProperty::Label): return self->field_root_14_dep.get().name;
        case (3 << 8) | uintptr_t(slint::cbindgen_private::AccessibleStringProperty::Label): return self->field_root_14_dep.get().size_str;
        case (4 << 8) | uintptr_t(slint::cbindgen_private::AccessibleStringProperty::Label): return self->field_text_17.text.get();
    }
    return {};
}

auto DepRow_root_14::accessibility_action (uint32_t index, const slint::cbindgen_private::AccessibilityAction &action) const -> void{
    [[maybe_unused]] auto self = this;
    switch ((index << 8) | uintptr_t(action.tag)) {
    }
    return ;
}

auto DepRow_root_14::supported_accessibility_actions (uint32_t index) const -> uint32_t{
    [[maybe_unused]] auto self = this;
    switch (index) {
    }
    return {};
}

auto DepRow_root_14::element_infos (uint32_t index) const -> std::optional<slint::SharedString>{
    [[maybe_unused]] auto self = this;
    switch (index) {
    }
    return {};
}

auto DepRow_root_14::ensure_instantiated () const -> bool{
    [[maybe_unused]] auto self = this;
    bool _changed = false;
    return _changed;
}

const slint::private_api::ItemTreeVTable Component_image_23::static_vtable = { visit_children, get_item_ref, get_subtree_range, get_subtree, get_item_tree, parent_node, embed_component, subtree_index, layout_info, ensure_instantiated, item_geometry, accessible_role, accessible_string_property, accessibility_action, supported_accessibility_actions, element_infos, window_adapter, slint::private_api::drop_in_place<Component_image_23>, slint::private_api::dealloc };

auto Component_image_23::init (const class SharedGlobals* globals,slint::cbindgen_private::ItemTreeWeak enclosing_component,uint32_t tree_index,uint32_t tree_index_of_first_child,class SuggestionCard_root_20 const *parent) -> void{
    auto self = this;
    self->self_weak = enclosing_component;
    self->globals = globals;
    this->tree_index_of_first_child = tree_index_of_first_child;
    self->tree_index = tree_index;
    self->parent = vtable::VRcMapped<slint::private_api::ItemTreeVTable, const SuggestionCard_root_20>(parent->self_weak.lock().value(), parent);
    self->field_image_23.height.set(48);
    self->field_image_23.horizontal_alignment.set(slint::cbindgen_private::ImageHorizontalAlignment::Left);
    self->field_image_23.source.set_binding([this]() {
                            [[maybe_unused]] auto self = this;
                            return slint::private_api::optional_or_default(slint::private_api::optional_transform(self->parent.lock(), [&](auto&&x) { return x->field_root_20_pkg.get(); })).icon;
                        });
    self->field_image_23.source_clip_height.set_binding([this]() {
                            [[maybe_unused]] auto self = this;
                            return (slint::private_api::optional_or_default(slint::private_api::optional_transform(self->parent.lock(), [&](auto&&x) { return x->field_root_20_pkg.get(); })).icon.size().height -(float) static_cast<int>(0));
                        });
    self->field_image_23.source_clip_width.set_binding([this]() {
                            [[maybe_unused]] auto self = this;
                            return (slint::private_api::optional_or_default(slint::private_api::optional_transform(self->parent.lock(), [&](auto&&x) { return x->field_root_20_pkg.get(); })).icon.size().width -(float) static_cast<int>(0));
                        });
    self->field_image_23.width.set(48);
    self->field_image_23.colorize.set_constant();
    self->field_image_23.height.set_constant();
    self->field_image_23.horizontal_alignment.set_constant();
    self->field_image_23.horizontal_tiling.set_constant();
    self->field_image_23.image_fit.set_constant();
    self->field_image_23.image_rendering.set_constant();
    self->field_image_23.source_clip_x.set_constant();
    self->field_image_23.source_clip_y.set_constant();
    self->field_image_23.vertical_alignment.set_constant();
    self->field_image_23.vertical_tiling.set_constant();
    self->field_image_23.width.set_constant();
}

auto Component_image_23::user_init () -> void{
    [[maybe_unused]] auto self = this;
}

auto Component_image_23::layout_info (slint::cbindgen_private::Orientation o) const -> slint::cbindgen_private::LayoutInfo{
    [[maybe_unused]] auto self = this;
    return o == slint::cbindgen_private::Orientation::Horizontal ? [&]{ [[maybe_unused]] auto layout_info = slint::private_api::item_layout_info(SLINT_GET_ITEM_VTABLE(ClippedImageVTable), const_cast<slint::cbindgen_private::ClippedImage*>(&self->field_image_23), slint::cbindgen_private::Orientation::Horizontal, -1, &self->globals->window().window_handle(), self->self_weak.lock()->into_dyn(), self->tree_index);;return [&](const auto &a_0, const auto &a_1, const auto &a_2, const auto &a_3, const auto &a_4, const auto &a_5){ slint::cbindgen_private::LayoutInfo o{}; o.max = a_0; o.max_percent = a_1; o.min = a_2; o.min_percent = a_3; o.preferred = a_4; o.stretch = a_5; return o; }(48, layout_info.max_percent, 48, layout_info.min_percent, layout_info.preferred, layout_info.stretch); }() : [&]{ [[maybe_unused]] auto layout_info = slint::private_api::item_layout_info(SLINT_GET_ITEM_VTABLE(ClippedImageVTable), const_cast<slint::cbindgen_private::ClippedImage*>(&self->field_image_23), slint::cbindgen_private::Orientation::Vertical, -1, &self->globals->window().window_handle(), self->self_weak.lock()->into_dyn(), self->tree_index);;return [&](const auto &a_0, const auto &a_1, const auto &a_2, const auto &a_3, const auto &a_4, const auto &a_5){ slint::cbindgen_private::LayoutInfo o{}; o.max = a_0; o.max_percent = a_1; o.min = a_2; o.min_percent = a_3; o.preferred = a_4; o.stretch = a_5; return o; }(48, layout_info.max_percent, 48, layout_info.min_percent, layout_info.preferred, layout_info.stretch); }();
}

auto Component_image_23::item_geometry (uint32_t index) const -> slint::cbindgen_private::Rect{
    [[maybe_unused]] auto self = this;
    switch (index) {
        case 0: return slint::private_api::convert_anonymous_rect(std::make_tuple(float(48), float(48), float(18), float(slint::private_api::optional_or_default(slint::private_api::optional_transform(self->parent.lock(), [&](auto&&x) { return slint::private_api::layout_cache_access(x->field_root_20_empty_22_layout_cache.get(), 0, 0, 2); })))));
    }
    return {};
}

auto Component_image_23::accessible_role (uint32_t index) const -> slint::cbindgen_private::AccessibleRole{
    [[maybe_unused]] auto self = this;
    switch (index) {
        case 0: return slint::cbindgen_private::AccessibleRole::Image;
    }
    return {};
}

auto Component_image_23::accessible_string_property (uint32_t index, slint::cbindgen_private::AccessibleStringProperty what) const -> std::optional<slint::SharedString>{
    [[maybe_unused]] auto self = this;
    switch ((index << 8) | uintptr_t(what)) {
    }
    return {};
}

auto Component_image_23::accessibility_action (uint32_t index, const slint::cbindgen_private::AccessibilityAction &action) const -> void{
    [[maybe_unused]] auto self = this;
    switch ((index << 8) | uintptr_t(action.tag)) {
    }
    return ;
}

auto Component_image_23::supported_accessibility_actions (uint32_t index) const -> uint32_t{
    [[maybe_unused]] auto self = this;
    switch (index) {
    }
    return {};
}

auto Component_image_23::element_infos (uint32_t index) const -> std::optional<slint::SharedString>{
    [[maybe_unused]] auto self = this;
    switch (index) {
    }
    return {};
}

auto Component_image_23::ensure_instantiated () const -> bool{
    [[maybe_unused]] auto self = this;
    bool _changed = false;
    return _changed;
}

auto Component_image_23::visit_children (slint::private_api::ItemTreeRef component, intptr_t index, slint::private_api::TraversalOrder order, slint::private_api::ItemVisitorRefMut visitor) -> uint64_t{
    static const auto dyn_visit = [] (const void *base,  [[maybe_unused]] slint::private_api::TraversalOrder order, [[maybe_unused]] slint::private_api::ItemVisitorRefMut visitor, [[maybe_unused]] uint32_t dyn_index) -> uint64_t {
        [[maybe_unused]] auto self = reinterpret_cast<const Component_image_23*>(base);
        std::abort();
    };
    auto self_rc = reinterpret_cast<const Component_image_23*>(component.instance)->self_weak.lock()->into_dyn();
    return slint::cbindgen_private::slint_visit_item_tree(&self_rc, get_item_tree(component) , index, order, visitor, dyn_visit);
}

auto Component_image_23::get_item_ref (slint::private_api::ItemTreeRef component, uint32_t index) -> slint::private_api::ItemRef{
    return slint::private_api::get_item_ref(component, get_item_tree(component), item_array(), index);
}

auto Component_image_23::get_subtree_range ([[maybe_unused]] slint::private_api::ItemTreeRef component, [[maybe_unused]] uint32_t dyn_index) -> slint::private_api::IndexRange{
        std::abort();
}

auto Component_image_23::get_subtree ([[maybe_unused]] slint::private_api::ItemTreeRef component, [[maybe_unused]] uint32_t dyn_index, [[maybe_unused]] uintptr_t subtree_index, [[maybe_unused]] slint::private_api::ItemTreeWeak *result) -> void{
        std::abort();
}

auto Component_image_23::get_item_tree (slint::private_api::ItemTreeRef) -> slint::cbindgen_private::Slice<slint::private_api::ItemTreeNode>{
    return item_tree();
}

auto Component_image_23::parent_node ([[maybe_unused]] slint::private_api::ItemTreeRef component, [[maybe_unused]] slint::private_api::ItemWeak *result) -> void{
    auto self = reinterpret_cast<const Component_image_23*>(component.instance);
    auto parent = self->parent.lock().value();
    *result = { parent->self_weak, parent->tree_index_of_first_child + 1 };
}

auto Component_image_23::embed_component ([[maybe_unused]] slint::private_api::ItemTreeRef component, [[maybe_unused]] const slint::private_api::ItemTreeWeak *parent_component, [[maybe_unused]] const uint32_t parent_index) -> bool{
    return false; /* todo! */
}

auto Component_image_23::subtree_index ([[maybe_unused]] slint::private_api::ItemTreeRef component) -> uintptr_t{
    return std::numeric_limits<uintptr_t>::max();
}

auto Component_image_23::item_tree () -> slint::cbindgen_private::Slice<slint::private_api::ItemTreeNode>{
    static const slint::private_api::ItemTreeNode children[] {
        slint::private_api::make_item_node(0, 1, 0, 0, true) };
    return slint::private_api::make_slice(std::span(children));
}

auto Component_image_23::item_array () -> const slint::private_api::ItemArray{
    static const slint::private_api::ItemArrayEntry items[] {
        { SLINT_GET_ITEM_VTABLE(ClippedImageVTable),  offsetof(Component_image_23, field_image_23) } };
    return slint::private_api::make_slice(std::span(items));
}

auto Component_image_23::layout_info ([[maybe_unused]] slint::private_api::ItemTreeRef component, slint::cbindgen_private::Orientation o) -> slint::cbindgen_private::LayoutInfo{
    return reinterpret_cast<const Component_image_23*>(component.instance)->layout_info(o);
}

auto Component_image_23::ensure_instantiated ([[maybe_unused]] slint::private_api::ItemTreeRef component) -> bool{
    return reinterpret_cast<const Component_image_23*>(component.instance)->ensure_instantiated();
}

auto Component_image_23::item_geometry ([[maybe_unused]] slint::private_api::ItemTreeRef component, uint32_t index) -> slint::cbindgen_private::LogicalRect{
    return reinterpret_cast<const Component_image_23*>(component.instance)->item_geometry(index);
}

auto Component_image_23::accessible_role ([[maybe_unused]] slint::private_api::ItemTreeRef component, uint32_t index) -> slint::cbindgen_private::AccessibleRole{
    return reinterpret_cast<const Component_image_23*>(component.instance)->accessible_role(index);
}

auto Component_image_23::accessible_string_property ([[maybe_unused]] slint::private_api::ItemTreeRef component, uint32_t index, slint::cbindgen_private::AccessibleStringProperty what, slint::SharedString *result) -> bool{
    if (auto r = reinterpret_cast<const Component_image_23*>(component.instance)->accessible_string_property(index, what)) { *result = *r; return true; } else { return false; }
}

auto Component_image_23::accessibility_action ([[maybe_unused]] slint::private_api::ItemTreeRef component, uint32_t index, const slint::cbindgen_private::AccessibilityAction *action) -> void{
    reinterpret_cast<const Component_image_23*>(component.instance)->accessibility_action(index, *action);
}

auto Component_image_23::supported_accessibility_actions ([[maybe_unused]] slint::private_api::ItemTreeRef component, uint32_t index) -> uint32_t{
    return reinterpret_cast<const Component_image_23*>(component.instance)->supported_accessibility_actions(index);
}

auto Component_image_23::element_infos ([[maybe_unused]] slint::private_api::ItemTreeRef component, [[maybe_unused]] uint32_t index, [[maybe_unused]] slint::SharedString *result) -> bool{
    return false;
}

auto Component_image_23::window_adapter ([[maybe_unused]] slint::private_api::ItemTreeRef component, [[maybe_unused]] bool do_create, [[maybe_unused]] slint::cbindgen_private::Option<slint::private_api::WindowAdapterRc>* result) -> void{
    *reinterpret_cast<slint::private_api::WindowAdapterRc*>(result) = reinterpret_cast<const Component_image_23*>(component.instance)->globals->window().window_handle();
}

auto Component_image_23::create (class SuggestionCard_root_20 const * parent) -> slint::ComponentHandle<Component_image_23>{
    auto self_rc = vtable::VRc<slint::private_api::ItemTreeVTable, Component_image_23>::make();
    auto self = const_cast<Component_image_23 *>(&*self_rc);
    self->self_weak = vtable::VWeak(self_rc).into_dyn();
    slint::private_api::register_item_tree(&self_rc.into_dyn(), parent->globals->m_window);
    self->init(parent->globals, self->self_weak, 0, 1 , parent);
    return slint::ComponentHandle<Component_image_23>{ self_rc };
}

Component_image_23::~Component_image_23 (){
    if (auto &window = globals->m_window) window->window_handle().unregister_item_tree(this, item_array());
}

auto Component_image_23::init () -> void{
    user_init();
}

auto Component_image_23::layout_item_info (slint::cbindgen_private::Orientation o, [[maybe_unused]] std::optional<size_t> child_index) const -> slint::cbindgen_private::LayoutItemInfo{
    return { layout_info({&static_vtable, const_cast<void *>(static_cast<const void *>(this))}, o) };
}

auto Component_image_23::flexbox_layout_item_info (slint::cbindgen_private::Orientation o, [[maybe_unused]] std::optional<size_t> child_index) const -> slint::cbindgen_private::FlexboxLayoutItemInfo{
    auto base = layout_item_info(o, child_index); return { base.constraint, 0.0f, 0.0f, -1.0f, slint::cbindgen_private::FlexboxLayoutAlignSelf::Auto, 0 };
}

const slint::private_api::ItemTreeVTable Component_rectangle_25::static_vtable = { visit_children, get_item_ref, get_subtree_range, get_subtree, get_item_tree, parent_node, embed_component, subtree_index, layout_info, ensure_instantiated, item_geometry, accessible_role, accessible_string_property, accessibility_action, supported_accessibility_actions, element_infos, window_adapter, slint::private_api::drop_in_place<Component_rectangle_25>, slint::private_api::dealloc };

auto Component_rectangle_25::init (const class SharedGlobals* globals,slint::cbindgen_private::ItemTreeWeak enclosing_component,uint32_t tree_index,uint32_t tree_index_of_first_child,class SuggestionCard_root_20 const *parent) -> void{
    auto self = this;
    self->self_weak = enclosing_component;
    self->globals = globals;
    this->tree_index_of_first_child = tree_index_of_first_child;
    self->tree_index = tree_index;
    self->parent = vtable::VRcMapped<slint::private_api::ItemTreeVTable, const SuggestionCard_root_20>(parent->self_weak.lock().value(), parent);
    self->field_rectangle_25.background.set_binding([this]() {
                            [[maybe_unused]] auto self = this;
                            return [&]{ [[maybe_unused]] auto tmp_Theme_219_accents = self->globals->global_Theme_219->field_accents.get();;return slint::Brush(slint::private_api::access_array_index(tmp_Theme_219_accents, ([](float a, float b) { auto r = std::fmod(a, b); return r >= 0 ? r : r + std::abs(b); })(slint::private_api::optional_or_default(slint::private_api::optional_transform(self->parent.lock(), [&](auto&&x) { return x->field_root_20_accent_idx.get(); })),slint::private_api::model_length(tmp_Theme_219_accents)))); }();
                        });
    self->field_rectangle_25.border_radius.set(10);
    self->field_rectangle_25.border_color.set_constant();
    self->field_rectangle_25.border_radius.set_constant();
    self->field_rectangle_25.border_width.set_constant();
}

auto Component_rectangle_25::user_init () -> void{
    [[maybe_unused]] auto self = this;
}

auto Component_rectangle_25::layout_info (slint::cbindgen_private::Orientation o) const -> slint::cbindgen_private::LayoutInfo{
    [[maybe_unused]] auto self = this;
    return o == slint::cbindgen_private::Orientation::Horizontal ? [&]{ [[maybe_unused]] auto layout_info = slint::private_api::item_layout_info(SLINT_GET_ITEM_VTABLE(BasicBorderRectangleVTable), const_cast<slint::cbindgen_private::BasicBorderRectangle*>(&self->field_rectangle_25), slint::cbindgen_private::Orientation::Horizontal, -1, &self->globals->window().window_handle(), self->self_weak.lock()->into_dyn(), self->tree_index);;return [&](const auto &a_0, const auto &a_1, const auto &a_2, const auto &a_3, const auto &a_4, const auto &a_5){ slint::cbindgen_private::LayoutInfo o{}; o.max = a_0; o.max_percent = a_1; o.min = a_2; o.min_percent = a_3; o.preferred = a_4; o.stretch = a_5; return o; }(48, layout_info.max_percent, 48, layout_info.min_percent, layout_info.preferred, layout_info.stretch); }() : [&]{ [[maybe_unused]] auto layout_info = slint::private_api::item_layout_info(SLINT_GET_ITEM_VTABLE(BasicBorderRectangleVTable), const_cast<slint::cbindgen_private::BasicBorderRectangle*>(&self->field_rectangle_25), slint::cbindgen_private::Orientation::Vertical, -1, &self->globals->window().window_handle(), self->self_weak.lock()->into_dyn(), self->tree_index);;return [&](const auto &a_0, const auto &a_1, const auto &a_2, const auto &a_3, const auto &a_4, const auto &a_5){ slint::cbindgen_private::LayoutInfo o{}; o.max = a_0; o.max_percent = a_1; o.min = a_2; o.min_percent = a_3; o.preferred = a_4; o.stretch = a_5; return o; }(48, layout_info.max_percent, 48, layout_info.min_percent, layout_info.preferred, layout_info.stretch); }();
}

auto Component_rectangle_25::item_geometry (uint32_t index) const -> slint::cbindgen_private::Rect{
    [[maybe_unused]] auto self = this;
    switch (index) {
        case 0: return slint::private_api::convert_anonymous_rect(std::make_tuple(float(48), float(48), float(18), float(slint::private_api::optional_or_default(slint::private_api::optional_transform(self->parent.lock(), [&](auto&&x) { return slint::private_api::layout_cache_access(x->field_root_20_empty_22_layout_cache.get(), 2, 0, 2); })))));
    }
    return {};
}

auto Component_rectangle_25::accessible_role (uint32_t index) const -> slint::cbindgen_private::AccessibleRole{
    [[maybe_unused]] auto self = this;
    switch (index) {
    }
    return {};
}

auto Component_rectangle_25::accessible_string_property (uint32_t index, slint::cbindgen_private::AccessibleStringProperty what) const -> std::optional<slint::SharedString>{
    [[maybe_unused]] auto self = this;
    switch ((index << 8) | uintptr_t(what)) {
    }
    return {};
}

auto Component_rectangle_25::accessibility_action (uint32_t index, const slint::cbindgen_private::AccessibilityAction &action) const -> void{
    [[maybe_unused]] auto self = this;
    switch ((index << 8) | uintptr_t(action.tag)) {
    }
    return ;
}

auto Component_rectangle_25::supported_accessibility_actions (uint32_t index) const -> uint32_t{
    [[maybe_unused]] auto self = this;
    switch (index) {
    }
    return {};
}

auto Component_rectangle_25::element_infos (uint32_t index) const -> std::optional<slint::SharedString>{
    [[maybe_unused]] auto self = this;
    switch (index) {
    }
    return {};
}

auto Component_rectangle_25::ensure_instantiated () const -> bool{
    [[maybe_unused]] auto self = this;
    bool _changed = false;
    return _changed;
}

auto Component_rectangle_25::visit_children (slint::private_api::ItemTreeRef component, intptr_t index, slint::private_api::TraversalOrder order, slint::private_api::ItemVisitorRefMut visitor) -> uint64_t{
    static const auto dyn_visit = [] (const void *base,  [[maybe_unused]] slint::private_api::TraversalOrder order, [[maybe_unused]] slint::private_api::ItemVisitorRefMut visitor, [[maybe_unused]] uint32_t dyn_index) -> uint64_t {
        [[maybe_unused]] auto self = reinterpret_cast<const Component_rectangle_25*>(base);
        std::abort();
    };
    auto self_rc = reinterpret_cast<const Component_rectangle_25*>(component.instance)->self_weak.lock()->into_dyn();
    return slint::cbindgen_private::slint_visit_item_tree(&self_rc, get_item_tree(component) , index, order, visitor, dyn_visit);
}

auto Component_rectangle_25::get_item_ref (slint::private_api::ItemTreeRef component, uint32_t index) -> slint::private_api::ItemRef{
    return slint::private_api::get_item_ref(component, get_item_tree(component), item_array(), index);
}

auto Component_rectangle_25::get_subtree_range ([[maybe_unused]] slint::private_api::ItemTreeRef component, [[maybe_unused]] uint32_t dyn_index) -> slint::private_api::IndexRange{
        std::abort();
}

auto Component_rectangle_25::get_subtree ([[maybe_unused]] slint::private_api::ItemTreeRef component, [[maybe_unused]] uint32_t dyn_index, [[maybe_unused]] uintptr_t subtree_index, [[maybe_unused]] slint::private_api::ItemTreeWeak *result) -> void{
        std::abort();
}

auto Component_rectangle_25::get_item_tree (slint::private_api::ItemTreeRef) -> slint::cbindgen_private::Slice<slint::private_api::ItemTreeNode>{
    return item_tree();
}

auto Component_rectangle_25::parent_node ([[maybe_unused]] slint::private_api::ItemTreeRef component, [[maybe_unused]] slint::private_api::ItemWeak *result) -> void{
    auto self = reinterpret_cast<const Component_rectangle_25*>(component.instance);
    auto parent = self->parent.lock().value();
    *result = { parent->self_weak, parent->tree_index_of_first_child + 2 };
}

auto Component_rectangle_25::embed_component ([[maybe_unused]] slint::private_api::ItemTreeRef component, [[maybe_unused]] const slint::private_api::ItemTreeWeak *parent_component, [[maybe_unused]] const uint32_t parent_index) -> bool{
    return false; /* todo! */
}

auto Component_rectangle_25::subtree_index ([[maybe_unused]] slint::private_api::ItemTreeRef component) -> uintptr_t{
    return std::numeric_limits<uintptr_t>::max();
}

auto Component_rectangle_25::item_tree () -> slint::cbindgen_private::Slice<slint::private_api::ItemTreeNode>{
    static const slint::private_api::ItemTreeNode children[] {
        slint::private_api::make_item_node(0, 1, 0, 0, false) };
    return slint::private_api::make_slice(std::span(children));
}

auto Component_rectangle_25::item_array () -> const slint::private_api::ItemArray{
    static const slint::private_api::ItemArrayEntry items[] {
        { SLINT_GET_ITEM_VTABLE(BasicBorderRectangleVTable),  offsetof(Component_rectangle_25, field_rectangle_25) } };
    return slint::private_api::make_slice(std::span(items));
}

auto Component_rectangle_25::layout_info ([[maybe_unused]] slint::private_api::ItemTreeRef component, slint::cbindgen_private::Orientation o) -> slint::cbindgen_private::LayoutInfo{
    return reinterpret_cast<const Component_rectangle_25*>(component.instance)->layout_info(o);
}

auto Component_rectangle_25::ensure_instantiated ([[maybe_unused]] slint::private_api::ItemTreeRef component) -> bool{
    return reinterpret_cast<const Component_rectangle_25*>(component.instance)->ensure_instantiated();
}

auto Component_rectangle_25::item_geometry ([[maybe_unused]] slint::private_api::ItemTreeRef component, uint32_t index) -> slint::cbindgen_private::LogicalRect{
    return reinterpret_cast<const Component_rectangle_25*>(component.instance)->item_geometry(index);
}

auto Component_rectangle_25::accessible_role ([[maybe_unused]] slint::private_api::ItemTreeRef component, uint32_t index) -> slint::cbindgen_private::AccessibleRole{
    return reinterpret_cast<const Component_rectangle_25*>(component.instance)->accessible_role(index);
}

auto Component_rectangle_25::accessible_string_property ([[maybe_unused]] slint::private_api::ItemTreeRef component, uint32_t index, slint::cbindgen_private::AccessibleStringProperty what, slint::SharedString *result) -> bool{
    if (auto r = reinterpret_cast<const Component_rectangle_25*>(component.instance)->accessible_string_property(index, what)) { *result = *r; return true; } else { return false; }
}

auto Component_rectangle_25::accessibility_action ([[maybe_unused]] slint::private_api::ItemTreeRef component, uint32_t index, const slint::cbindgen_private::AccessibilityAction *action) -> void{
    reinterpret_cast<const Component_rectangle_25*>(component.instance)->accessibility_action(index, *action);
}

auto Component_rectangle_25::supported_accessibility_actions ([[maybe_unused]] slint::private_api::ItemTreeRef component, uint32_t index) -> uint32_t{
    return reinterpret_cast<const Component_rectangle_25*>(component.instance)->supported_accessibility_actions(index);
}

auto Component_rectangle_25::element_infos ([[maybe_unused]] slint::private_api::ItemTreeRef component, [[maybe_unused]] uint32_t index, [[maybe_unused]] slint::SharedString *result) -> bool{
    return false;
}

auto Component_rectangle_25::window_adapter ([[maybe_unused]] slint::private_api::ItemTreeRef component, [[maybe_unused]] bool do_create, [[maybe_unused]] slint::cbindgen_private::Option<slint::private_api::WindowAdapterRc>* result) -> void{
    *reinterpret_cast<slint::private_api::WindowAdapterRc*>(result) = reinterpret_cast<const Component_rectangle_25*>(component.instance)->globals->window().window_handle();
}

auto Component_rectangle_25::create (class SuggestionCard_root_20 const * parent) -> slint::ComponentHandle<Component_rectangle_25>{
    auto self_rc = vtable::VRc<slint::private_api::ItemTreeVTable, Component_rectangle_25>::make();
    auto self = const_cast<Component_rectangle_25 *>(&*self_rc);
    self->self_weak = vtable::VWeak(self_rc).into_dyn();
    slint::private_api::register_item_tree(&self_rc.into_dyn(), parent->globals->m_window);
    self->init(parent->globals, self->self_weak, 0, 1 , parent);
    return slint::ComponentHandle<Component_rectangle_25>{ self_rc };
}

Component_rectangle_25::~Component_rectangle_25 (){
    if (auto &window = globals->m_window) window->window_handle().unregister_item_tree(this, item_array());
}

auto Component_rectangle_25::init () -> void{
    user_init();
}

auto Component_rectangle_25::layout_item_info (slint::cbindgen_private::Orientation o, [[maybe_unused]] std::optional<size_t> child_index) const -> slint::cbindgen_private::LayoutItemInfo{
    return { layout_info({&static_vtable, const_cast<void *>(static_cast<const void *>(this))}, o) };
}

auto Component_rectangle_25::flexbox_layout_item_info (slint::cbindgen_private::Orientation o, [[maybe_unused]] std::optional<size_t> child_index) const -> slint::cbindgen_private::FlexboxLayoutItemInfo{
    auto base = layout_item_info(o, child_index); return { base.constraint, 0.0f, 0.0f, -1.0f, slint::cbindgen_private::FlexboxLayoutAlignSelf::Auto, 0 };
}

auto SuggestionCard_root_20::fn_empty_22_layoutinfo_v_with_constraint ([[maybe_unused]] float arg_0) const -> slint::cbindgen_private::LayoutInfo{
    [[maybe_unused]] auto self = this;
    return [&]{   std::vector<slint::cbindgen_private::LayoutItemInfo> cells_vector;self->repeater_0.track_instance_changes();{
                                    auto start_offset = cells_vector.size();
                                    self->repeater_0.for_each([&](const auto &sub_comp){ cells_vector.push_back(sub_comp->layout_item_info(slint::cbindgen_private::Orientation::Vertical, std::nullopt)); });
                                    cells_vector.resize(start_offset + self->repeater_0.len());
                                }self->repeater_1.track_instance_changes();{
                                    auto start_offset = cells_vector.size();
                                    self->repeater_1.for_each([&](const auto &sub_comp){ cells_vector.push_back(sub_comp->layout_item_info(slint::cbindgen_private::Orientation::Vertical, std::nullopt)); });
                                    cells_vector.resize(start_offset + self->repeater_1.len());
                                }cells_vector.push_back({ [&](const auto &a_0){ slint::cbindgen_private::LayoutItemInfo o{}; o.constraint = a_0; return o; }(self->field_root_20_empty_27_layoutinfo_v.get()) });cells_vector.push_back({ [&](const auto &a_0){ slint::cbindgen_private::LayoutItemInfo o{}; o.constraint = a_0; return o; }([&]{ [[maybe_unused]] auto layout_info = slint::private_api::item_layout_info(SLINT_GET_ITEM_VTABLE(EmptyVTable), const_cast<slint::cbindgen_private::Empty*>(&self->field_rectangle_30), slint::cbindgen_private::Orientation::Vertical, arg_0, &self->globals->window().window_handle(), self->self_weak.lock()->into_dyn(), self->tree_index_of_first_child + 5 - 1);;return [&](const auto &a_0, const auto &a_1, const auto &a_2, const auto &a_3, const auto &a_4, const auto &a_5){ slint::cbindgen_private::LayoutInfo o{}; o.max = a_0; o.max_percent = a_1; o.min = a_2; o.min_percent = a_3; o.preferred = a_4; o.stretch = a_5; return o; }(layout_info.max, layout_info.max_percent, layout_info.min, layout_info.min_percent, layout_info.preferred, self->field_root_20_rectangle_30_vertical_stretch.get()); }()) });cells_vector.push_back({ [&](const auto &a_0){ slint::cbindgen_private::LayoutItemInfo o{}; o.constraint = a_0; return o; }(slint::private_api::item_layout_info(SLINT_GET_ITEM_VTABLE(SimpleTextVTable), const_cast<slint::cbindgen_private::SimpleText*>(&self->field_text_31), slint::cbindgen_private::Orientation::Vertical, arg_0, &self->globals->window().window_handle(), self->self_weak.lock()->into_dyn(), self->tree_index_of_first_child + 6 - 1)) }); slint::cbindgen_private::Slice<slint::cbindgen_private::LayoutItemInfo>cells = slint::private_api::make_slice(std::span(cells_vector)); return slint::private_api::box_layout_info(cells,self->field_root_20_empty_22_spacing.get(),[&](const auto &a_0, const auto &a_1){ slint::cbindgen_private::Padding o{}; o.begin = a_0; o.end = a_1; return o; }(self->field_root_20_empty_22_padding.get(), self->field_root_20_empty_22_padding.get()),self->field_root_20_empty_22_alignment.get()); }();
}

auto SuggestionCard_root_20::fn_layoutinfo_v_with_constraint ([[maybe_unused]] float arg_0) const -> slint::cbindgen_private::LayoutInfo{
    [[maybe_unused]] auto self = this;
    return ([&](const auto &a_0, const auto &a_1, const auto &a_2, const auto &a_3, const auto &a_4, const auto &a_5){ slint::cbindgen_private::LayoutInfo o{}; o.max = a_0; o.max_percent = a_1; o.min = a_2; o.min_percent = a_3; o.preferred = a_4; o.stretch = a_5; return o; }(+3.4028234663852886e38, 100, 0, 0, 0, 1) + self->fn_empty_22_layoutinfo_v_with_constraint(arg_0));
}

auto SuggestionCard_root_20::init (const class SharedGlobals* globals,slint::cbindgen_private::ItemTreeWeak enclosing_component,uint32_t tree_index,uint32_t tree_index_of_first_child) -> void{
    auto self = this;
    self->self_weak = enclosing_component;
    self->globals = globals;
    this->tree_index_of_first_child = tree_index_of_first_child;
    self->tree_index = tree_index;
    self->field_root_20.background.set_binding([this]() {
                            [[maybe_unused]] auto self = this;
                            return slint::Brush((self->field_sta_21.has_hover.get() ? slint::Color::from_argb_encoded(+4.28273033e9) : slint::Color::from_argb_encoded(+4.281414212e9)));
                        });
    self->field_root_20.border_color.set_binding([this]() {
                            [[maybe_unused]] auto self = this;
                            return slint::Brush((self->field_sta_21.has_hover.get() ? [&]{ [[maybe_unused]] auto tmp_Theme_219_accents = self->globals->global_Theme_219->field_accents.get();;return slint::private_api::access_array_index(tmp_Theme_219_accents, ([](float a, float b) { auto r = std::fmod(a, b); return r >= 0 ? r : r + std::abs(b); })(self->field_root_20_accent_idx.get(),slint::private_api::model_length(tmp_Theme_219_accents))); }() : slint::Color::from_argb_encoded(+4.28273033e9)));
                        });
    self->field_root_20.border_radius.set(14);
    self->field_root_20.border_width.set(1);
    self->field_root_20_empty_22_alignment.set(slint::cbindgen_private::LayoutAlignment::Start);
    self->field_root_20_empty_22_layout_cache.set_binding([this]() {
                            [[maybe_unused]] auto self = this;
                            return [&]{ std::array<int, 4> repeated_indices_array;  std::vector<slint::cbindgen_private::LayoutItemInfo> cells_vector;self->repeater_0.track_instance_changes();repeated_indices_array[0] = cells_vector.size();repeated_indices_array[1] = self->repeater_0.len();{
                                    auto start_offset = cells_vector.size();
                                    self->repeater_0.for_each([&](const auto &sub_comp){ cells_vector.push_back(sub_comp->layout_item_info(slint::cbindgen_private::Orientation::Vertical, std::nullopt)); });
                                    cells_vector.resize(start_offset + self->repeater_0.len());
                                }self->repeater_1.track_instance_changes();repeated_indices_array[2] = cells_vector.size();repeated_indices_array[3] = self->repeater_1.len();{
                                    auto start_offset = cells_vector.size();
                                    self->repeater_1.for_each([&](const auto &sub_comp){ cells_vector.push_back(sub_comp->layout_item_info(slint::cbindgen_private::Orientation::Vertical, std::nullopt)); });
                                    cells_vector.resize(start_offset + self->repeater_1.len());
                                }cells_vector.push_back({ [&](const auto &a_0){ slint::cbindgen_private::LayoutItemInfo o{}; o.constraint = a_0; return o; }(self->field_root_20_empty_27_layoutinfo_v.get()) });cells_vector.push_back({ [&](const auto &a_0){ slint::cbindgen_private::LayoutItemInfo o{}; o.constraint = a_0; return o; }([&]{ [[maybe_unused]] auto layout_info = slint::private_api::item_layout_info(SLINT_GET_ITEM_VTABLE(EmptyVTable), const_cast<slint::cbindgen_private::Empty*>(&self->field_rectangle_30), slint::cbindgen_private::Orientation::Vertical, -1, &self->globals->window().window_handle(), self->self_weak.lock()->into_dyn(), self->tree_index_of_first_child + 5 - 1);;return [&](const auto &a_0, const auto &a_1, const auto &a_2, const auto &a_3, const auto &a_4, const auto &a_5){ slint::cbindgen_private::LayoutInfo o{}; o.max = a_0; o.max_percent = a_1; o.min = a_2; o.min_percent = a_3; o.preferred = a_4; o.stretch = a_5; return o; }(layout_info.max, layout_info.max_percent, layout_info.min, layout_info.min_percent, layout_info.preferred, 1); }()) });cells_vector.push_back({ [&](const auto &a_0){ slint::cbindgen_private::LayoutItemInfo o{}; o.constraint = a_0; return o; }(slint::private_api::item_layout_info(SLINT_GET_ITEM_VTABLE(SimpleTextVTable), const_cast<slint::cbindgen_private::SimpleText*>(&self->field_text_31), slint::cbindgen_private::Orientation::Vertical, -1, &self->globals->window().window_handle(), self->self_weak.lock()->into_dyn(), self->tree_index_of_first_child + 6 - 1)) });slint::cbindgen_private::Slice<int> repeated_indices = slint::private_api::make_slice(std::span(repeated_indices_array)); slint::cbindgen_private::Slice<slint::cbindgen_private::LayoutItemInfo>cells = slint::private_api::make_slice(std::span(cells_vector)); return slint::private_api::solve_box_layout([&](const auto &a_0, const auto &a_1, const auto &a_2, const auto &a_3, const auto &a_4){ slint::cbindgen_private::BoxLayoutData o{}; o.alignment = a_0; o.cells = a_1; o.padding = a_2; o.size = a_3; o.spacing = a_4; return o; }(slint::cbindgen_private::LayoutAlignment::Start, cells, [&](const auto &a_0, const auto &a_1){ slint::cbindgen_private::Padding o{}; o.begin = a_0; o.end = a_1; return o; }(18, 18), 190, 10),repeated_indices); }();
                        });
    self->field_root_20_empty_22_layoutinfo_h.set_binding([this]() {
                            [[maybe_unused]] auto self = this;
                            return [&]{   std::vector<slint::cbindgen_private::LayoutItemInfo> cells_vector;self->repeater_0.track_instance_changes();{
                                    auto start_offset = cells_vector.size();
                                    self->repeater_0.for_each([&](const auto &sub_comp){ cells_vector.push_back(sub_comp->layout_item_info(slint::cbindgen_private::Orientation::Horizontal, std::nullopt)); });
                                    cells_vector.resize(start_offset + self->repeater_0.len());
                                }self->repeater_1.track_instance_changes();{
                                    auto start_offset = cells_vector.size();
                                    self->repeater_1.for_each([&](const auto &sub_comp){ cells_vector.push_back(sub_comp->layout_item_info(slint::cbindgen_private::Orientation::Horizontal, std::nullopt)); });
                                    cells_vector.resize(start_offset + self->repeater_1.len());
                                }cells_vector.push_back({ [&](const auto &a_0){ slint::cbindgen_private::LayoutItemInfo o{}; o.constraint = a_0; return o; }(self->field_root_20_empty_27_layoutinfo_h.get()) });cells_vector.push_back({ [&](const auto &a_0){ slint::cbindgen_private::LayoutItemInfo o{}; o.constraint = a_0; return o; }(slint::private_api::item_layout_info(SLINT_GET_ITEM_VTABLE(EmptyVTable), const_cast<slint::cbindgen_private::Empty*>(&self->field_rectangle_30), slint::cbindgen_private::Orientation::Horizontal, -1, &self->globals->window().window_handle(), self->self_weak.lock()->into_dyn(), self->tree_index_of_first_child + 5 - 1)) });cells_vector.push_back({ [&](const auto &a_0){ slint::cbindgen_private::LayoutItemInfo o{}; o.constraint = a_0; return o; }(slint::private_api::item_layout_info(SLINT_GET_ITEM_VTABLE(SimpleTextVTable), const_cast<slint::cbindgen_private::SimpleText*>(&self->field_text_31), slint::cbindgen_private::Orientation::Horizontal, -1, &self->globals->window().window_handle(), self->self_weak.lock()->into_dyn(), self->tree_index_of_first_child + 6 - 1)) }); slint::cbindgen_private::Slice<slint::cbindgen_private::LayoutItemInfo>cells = slint::private_api::make_slice(std::span(cells_vector)); return slint::private_api::box_layout_info_ortho(cells,[&](const auto &a_0, const auto &a_1){ slint::cbindgen_private::Padding o{}; o.begin = a_0; o.end = a_1; return o; }(18, 18)); }();
                        });
    self->field_root_20_empty_22_layoutinfo_v.set_binding([this]() {
                            [[maybe_unused]] auto self = this;
                            return [&]{   std::vector<slint::cbindgen_private::LayoutItemInfo> cells_vector;self->repeater_0.track_instance_changes();{
                                    auto start_offset = cells_vector.size();
                                    self->repeater_0.for_each([&](const auto &sub_comp){ cells_vector.push_back(sub_comp->layout_item_info(slint::cbindgen_private::Orientation::Vertical, std::nullopt)); });
                                    cells_vector.resize(start_offset + self->repeater_0.len());
                                }self->repeater_1.track_instance_changes();{
                                    auto start_offset = cells_vector.size();
                                    self->repeater_1.for_each([&](const auto &sub_comp){ cells_vector.push_back(sub_comp->layout_item_info(slint::cbindgen_private::Orientation::Vertical, std::nullopt)); });
                                    cells_vector.resize(start_offset + self->repeater_1.len());
                                }cells_vector.push_back({ [&](const auto &a_0){ slint::cbindgen_private::LayoutItemInfo o{}; o.constraint = a_0; return o; }(self->field_root_20_empty_27_layoutinfo_v.get()) });cells_vector.push_back({ [&](const auto &a_0){ slint::cbindgen_private::LayoutItemInfo o{}; o.constraint = a_0; return o; }([&]{ [[maybe_unused]] auto layout_info = slint::private_api::item_layout_info(SLINT_GET_ITEM_VTABLE(EmptyVTable), const_cast<slint::cbindgen_private::Empty*>(&self->field_rectangle_30), slint::cbindgen_private::Orientation::Vertical, -1, &self->globals->window().window_handle(), self->self_weak.lock()->into_dyn(), self->tree_index_of_first_child + 5 - 1);;return [&](const auto &a_0, const auto &a_1, const auto &a_2, const auto &a_3, const auto &a_4, const auto &a_5){ slint::cbindgen_private::LayoutInfo o{}; o.max = a_0; o.max_percent = a_1; o.min = a_2; o.min_percent = a_3; o.preferred = a_4; o.stretch = a_5; return o; }(layout_info.max, layout_info.max_percent, layout_info.min, layout_info.min_percent, layout_info.preferred, 1); }()) });cells_vector.push_back({ [&](const auto &a_0){ slint::cbindgen_private::LayoutItemInfo o{}; o.constraint = a_0; return o; }(slint::private_api::item_layout_info(SLINT_GET_ITEM_VTABLE(SimpleTextVTable), const_cast<slint::cbindgen_private::SimpleText*>(&self->field_text_31), slint::cbindgen_private::Orientation::Vertical, -1, &self->globals->window().window_handle(), self->self_weak.lock()->into_dyn(), self->tree_index_of_first_child + 6 - 1)) }); slint::cbindgen_private::Slice<slint::cbindgen_private::LayoutItemInfo>cells = slint::private_api::make_slice(std::span(cells_vector)); return slint::private_api::box_layout_info(cells,10,[&](const auto &a_0, const auto &a_1){ slint::cbindgen_private::Padding o{}; o.begin = a_0; o.end = a_1; return o; }(18, 18),slint::cbindgen_private::LayoutAlignment::Start); }();
                        });
    self->field_root_20_empty_22_padding.set(18);
    self->field_root_20_empty_22_spacing.set(10);
    self->field_root_20_empty_27_layout_cache.set_binding([this]() {
                            [[maybe_unused]] auto self = this;
                            return slint::private_api::solve_box_layout([&](const auto &a_0, const auto &a_1, const auto &a_2, const auto &a_3, const auto &a_4){ slint::cbindgen_private::BoxLayoutData o{}; o.alignment = a_0; o.cells = a_1; o.padding = a_2; o.size = a_3; o.spacing = a_4; return o; }(slint::cbindgen_private::LayoutAlignment::Stretch, slint::private_api::make_slice<slint::cbindgen_private::LayoutItemInfo>(std::array<slint::cbindgen_private::LayoutItemInfo, 2>{ slint::cbindgen_private::LayoutItemInfo ( [&](const auto &a_0){ slint::cbindgen_private::LayoutItemInfo o{}; o.constraint = a_0; return o; }(slint::private_api::item_layout_info(SLINT_GET_ITEM_VTABLE(ComplexTextVTable), const_cast<slint::cbindgen_private::ComplexText*>(&self->field_text_28), slint::cbindgen_private::Orientation::Vertical, -1, &self->globals->window().window_handle(), self->self_weak.lock()->into_dyn(), self->tree_index_of_first_child + 7 - 1)) ), slint::cbindgen_private::LayoutItemInfo ( [&](const auto &a_0){ slint::cbindgen_private::LayoutItemInfo o{}; o.constraint = a_0; return o; }(slint::private_api::item_layout_info(SLINT_GET_ITEM_VTABLE(ComplexTextVTable), const_cast<slint::cbindgen_private::ComplexText*>(&self->field_text_29), slint::cbindgen_private::Orientation::Vertical, -1, &self->globals->window().window_handle(), self->self_weak.lock()->into_dyn(), self->tree_index_of_first_child + 8 - 1)) ) }.data(), 2), [&](const auto &a_0, const auto &a_1){ slint::cbindgen_private::Padding o{}; o.begin = a_0; o.end = a_1; return o; }(0, 0), self->field_root_20_empty_22_layout_cache.get()[5], 4),slint::private_api::make_slice<int>(std::array<int, 0>{  }.data(), 0));
                        });
    self->field_root_20_empty_27_layoutinfo_h.set_binding([this]() {
                            [[maybe_unused]] auto self = this;
                            return slint::private_api::box_layout_info_ortho(slint::private_api::make_slice<slint::cbindgen_private::LayoutItemInfo>(std::array<slint::cbindgen_private::LayoutItemInfo, 2>{ slint::cbindgen_private::LayoutItemInfo ( [&](const auto &a_0){ slint::cbindgen_private::LayoutItemInfo o{}; o.constraint = a_0; return o; }(slint::private_api::item_layout_info(SLINT_GET_ITEM_VTABLE(ComplexTextVTable), const_cast<slint::cbindgen_private::ComplexText*>(&self->field_text_28), slint::cbindgen_private::Orientation::Horizontal, -1, &self->globals->window().window_handle(), self->self_weak.lock()->into_dyn(), self->tree_index_of_first_child + 7 - 1)) ), slint::cbindgen_private::LayoutItemInfo ( [&](const auto &a_0){ slint::cbindgen_private::LayoutItemInfo o{}; o.constraint = a_0; return o; }(slint::private_api::item_layout_info(SLINT_GET_ITEM_VTABLE(ComplexTextVTable), const_cast<slint::cbindgen_private::ComplexText*>(&self->field_text_29), slint::cbindgen_private::Orientation::Horizontal, -1, &self->globals->window().window_handle(), self->self_weak.lock()->into_dyn(), self->tree_index_of_first_child + 8 - 1)) ) }.data(), 2),[&](const auto &a_0, const auto &a_1){ slint::cbindgen_private::Padding o{}; o.begin = a_0; o.end = a_1; return o; }(0, 0));
                        });
    self->field_root_20_empty_27_layoutinfo_v.set_binding([this]() {
                            [[maybe_unused]] auto self = this;
                            return slint::private_api::box_layout_info(slint::private_api::make_slice<slint::cbindgen_private::LayoutItemInfo>(std::array<slint::cbindgen_private::LayoutItemInfo, 2>{ slint::cbindgen_private::LayoutItemInfo ( [&](const auto &a_0){ slint::cbindgen_private::LayoutItemInfo o{}; o.constraint = a_0; return o; }(slint::private_api::item_layout_info(SLINT_GET_ITEM_VTABLE(ComplexTextVTable), const_cast<slint::cbindgen_private::ComplexText*>(&self->field_text_28), slint::cbindgen_private::Orientation::Vertical, -1, &self->globals->window().window_handle(), self->self_weak.lock()->into_dyn(), self->tree_index_of_first_child + 7 - 1)) ), slint::cbindgen_private::LayoutItemInfo ( [&](const auto &a_0){ slint::cbindgen_private::LayoutItemInfo o{}; o.constraint = a_0; return o; }(slint::private_api::item_layout_info(SLINT_GET_ITEM_VTABLE(ComplexTextVTable), const_cast<slint::cbindgen_private::ComplexText*>(&self->field_text_29), slint::cbindgen_private::Orientation::Vertical, -1, &self->globals->window().window_handle(), self->self_weak.lock()->into_dyn(), self->tree_index_of_first_child + 8 - 1)) ) }.data(), 2),4,[&](const auto &a_0, const auto &a_1){ slint::cbindgen_private::Padding o{}; o.begin = a_0; o.end = a_1; return o; }(0, 0),slint::cbindgen_private::LayoutAlignment::Stretch);
                        });
    self->field_root_20_rectangle_30_vertical_stretch.set(1);
    self->field_sta_21.clicked.set_handler(
                [this]() {
                    [[maybe_unused]] auto self = this;
                    self->field_root_20_clicked.call();
                });
    self->field_sta_21.enabled.set(true);
    self->field_text_28.color.set(slint::Brush(slint::Color::from_argb_encoded(+4.291679988e9)));
    self->field_text_28.font_size.set(13);
    self->field_text_28.font_weight.set(static_cast<int>(700));
    self->field_text_28.height.set_binding([this]() {
                            [[maybe_unused]] auto self = this;
                            return self->field_root_20_empty_27_layout_cache.get()[1];
                        });
    self->field_text_28.overflow.set(slint::cbindgen_private::TextOverflow::Elide);
    self->field_text_28.text.set_binding([this]() {
                            [[maybe_unused]] auto self = this;
                            return self->field_root_20_pkg.get().pretty_name;
                        });
    self->field_text_28.width.set(132);
    self->field_text_29.color.set(slint::Brush(slint::Color::from_argb_encoded(+4.2865471e9)));
    self->field_text_29.font_size.set(10);
    self->field_text_29.height.set_binding([this]() {
                            [[maybe_unused]] auto self = this;
                            return self->field_root_20_empty_27_layout_cache.get()[3];
                        });
    self->field_text_29.overflow.set(slint::cbindgen_private::TextOverflow::Elide);
    self->field_text_29.text.set_binding([this]() {
                            [[maybe_unused]] auto self = this;
                            return self->field_root_20_pkg.get().repo;
                        });
    self->field_text_29.width.set(132);
    self->field_text_31.color.set_binding([this]() {
                            [[maybe_unused]] auto self = this;
                            return slint::Brush((self->field_root_20_pkg.get().installed ? slint::Color::from_argb_encoded(+4.289127329e9) : [&]{ [[maybe_unused]] auto tmp_Theme_219_accents = self->globals->global_Theme_219->field_accents.get();;return slint::private_api::access_array_index(tmp_Theme_219_accents, ([](float a, float b) { auto r = std::fmod(a, b); return r >= 0 ? r : r + std::abs(b); })(self->field_root_20_accent_idx.get(),slint::private_api::model_length(tmp_Theme_219_accents))); }()));
                        });
    self->field_text_31.font_size.set(11);
    self->field_text_31.font_weight.set(static_cast<int>(700));
    self->field_text_31.height.set_binding([this]() {
                            [[maybe_unused]] auto self = this;
                            return self->field_root_20_empty_22_layout_cache.get()[9];
                        });
    self->field_text_31.text.set_binding([this]() {
                            [[maybe_unused]] auto self = this;
                            return (self->field_root_20_pkg.get().installed ? slint::SharedString(u8"Installed") : slint::SharedString(u8"View details"));
                        });
    self->field_text_31.width.set(132);
    self->field_root_20.border_radius.set_constant();
    self->field_root_20.border_width.set_constant();
    self->field_root_20_empty_22_alignment.set_constant();
    self->field_root_20_empty_22_padding.set_constant();
    self->field_root_20_empty_22_spacing.set_constant();
    self->field_root_20_rectangle_30_vertical_stretch.set_constant();
    self->field_sta_21.enabled.set_constant();
    self->field_sta_21.mouse_cursor.set_constant();
    self->field_text_28.color.set_constant();
    self->field_text_28.font_family.set_constant();
    self->field_text_28.font_italic.set_constant();
    self->field_text_28.font_size.set_constant();
    self->field_text_28.font_weight.set_constant();
    self->field_text_28.horizontal_alignment.set_constant();
    self->field_text_28.letter_spacing.set_constant();
    self->field_text_28.overflow.set_constant();
    self->field_text_28.stroke.set_constant();
    self->field_text_28.stroke_style.set_constant();
    self->field_text_28.stroke_width.set_constant();
    self->field_text_28.vertical_alignment.set_constant();
    self->field_text_28.width.set_constant();
    self->field_text_28.wrap.set_constant();
    self->field_text_29.color.set_constant();
    self->field_text_29.font_family.set_constant();
    self->field_text_29.font_italic.set_constant();
    self->field_text_29.font_size.set_constant();
    self->field_text_29.font_weight.set_constant();
    self->field_text_29.horizontal_alignment.set_constant();
    self->field_text_29.letter_spacing.set_constant();
    self->field_text_29.overflow.set_constant();
    self->field_text_29.stroke.set_constant();
    self->field_text_29.stroke_style.set_constant();
    self->field_text_29.stroke_width.set_constant();
    self->field_text_29.vertical_alignment.set_constant();
    self->field_text_29.width.set_constant();
    self->field_text_29.wrap.set_constant();
    self->field_text_31.font_size.set_constant();
    self->field_text_31.font_weight.set_constant();
    self->field_text_31.horizontal_alignment.set_constant();
    self->field_text_31.vertical_alignment.set_constant();
    self->field_text_31.width.set_constant();
    self->repeater_0.set_model_binding([self] { (void)self; return (self->field_root_20_pkg.get().icon.size().width > 0); });
    self->repeater_1.set_model_binding([self] { (void)self; return (std::abs(float(self->field_root_20_pkg.get().icon.size().width - 0)) < std::numeric_limits<float>::epsilon()); });
}

auto SuggestionCard_root_20::user_init () -> void{
    [[maybe_unused]] auto self = this;
}

auto SuggestionCard_root_20::layout_info (slint::cbindgen_private::Orientation o) const -> slint::cbindgen_private::LayoutInfo{
    [[maybe_unused]] auto self = this;
    return o == slint::cbindgen_private::Orientation::Horizontal ? [&]{ [[maybe_unused]] auto layout_info = ([&](const auto &a_0, const auto &a_1, const auto &a_2, const auto &a_3, const auto &a_4, const auto &a_5){ slint::cbindgen_private::LayoutInfo o{}; o.max = a_0; o.max_percent = a_1; o.min = a_2; o.min_percent = a_3; o.preferred = a_4; o.stretch = a_5; return o; }(+3.4028234663852886e38, 100, 0, 0, 0, 1) + self->field_root_20_empty_22_layoutinfo_h.get());;return [&](const auto &a_0, const auto &a_1, const auto &a_2, const auto &a_3, const auto &a_4, const auto &a_5){ slint::cbindgen_private::LayoutInfo o{}; o.max = a_0; o.max_percent = a_1; o.min = a_2; o.min_percent = a_3; o.preferred = a_4; o.stretch = a_5; return o; }(168, layout_info.max_percent, 168, layout_info.min_percent, layout_info.preferred, layout_info.stretch); }() : [&]{ [[maybe_unused]] auto layout_info = ([&](const auto &a_0, const auto &a_1, const auto &a_2, const auto &a_3, const auto &a_4, const auto &a_5){ slint::cbindgen_private::LayoutInfo o{}; o.max = a_0; o.max_percent = a_1; o.min = a_2; o.min_percent = a_3; o.preferred = a_4; o.stretch = a_5; return o; }(+3.4028234663852886e38, 100, 0, 0, 0, 1) + self->field_root_20_empty_22_layoutinfo_v.get());;return [&](const auto &a_0, const auto &a_1, const auto &a_2, const auto &a_3, const auto &a_4, const auto &a_5){ slint::cbindgen_private::LayoutInfo o{}; o.max = a_0; o.max_percent = a_1; o.min = a_2; o.min_percent = a_3; o.preferred = a_4; o.stretch = a_5; return o; }(190, layout_info.max_percent, 190, layout_info.min_percent, layout_info.preferred, layout_info.stretch); }();
}

auto SuggestionCard_root_20::item_geometry (uint32_t index) const -> slint::cbindgen_private::Rect{
    [[maybe_unused]] auto self = this;
    switch (index) {
        case 0: return slint::private_api::convert_anonymous_rect(std::make_tuple(float(190), float(168), float(self->field_root_20_x.get()), float(0)));
        case 1: return slint::private_api::convert_anonymous_rect(std::make_tuple(float(190), float(168), float(0), float(0)));
        case 4: return slint::private_api::convert_anonymous_rect(std::make_tuple(float(self->field_root_20_empty_22_layout_cache.get()[5]), float(132), float(18), float(self->field_root_20_empty_22_layout_cache.get()[4])));
        case 5: return slint::private_api::convert_anonymous_rect(std::make_tuple(float(self->field_root_20_empty_22_layout_cache.get()[7]), float(132), float(18), float(self->field_root_20_empty_22_layout_cache.get()[6])));
        case 6: return slint::private_api::convert_anonymous_rect(std::make_tuple(float(self->field_root_20_empty_22_layout_cache.get()[9]), float(132), float(18), float(self->field_root_20_empty_22_layout_cache.get()[8])));
        case 7: return slint::private_api::convert_anonymous_rect(std::make_tuple(float(self->field_root_20_empty_27_layout_cache.get()[1]), float(132), float(0), float(self->field_root_20_empty_27_layout_cache.get()[0])));
        case 8: return slint::private_api::convert_anonymous_rect(std::make_tuple(float(self->field_root_20_empty_27_layout_cache.get()[3]), float(132), float(0), float(self->field_root_20_empty_27_layout_cache.get()[2])));
    }
    return {};
}

auto SuggestionCard_root_20::accessible_role (uint32_t index) const -> slint::cbindgen_private::AccessibleRole{
    [[maybe_unused]] auto self = this;
    switch (index) {
        case 6: return slint::cbindgen_private::AccessibleRole::Text;
        case 7: return slint::cbindgen_private::AccessibleRole::Text;
        case 8: return slint::cbindgen_private::AccessibleRole::Text;
    }
    return {};
}

auto SuggestionCard_root_20::accessible_string_property (uint32_t index, slint::cbindgen_private::AccessibleStringProperty what) const -> std::optional<slint::SharedString>{
    [[maybe_unused]] auto self = this;
    switch ((index << 8) | uintptr_t(what)) {
        case (6 << 8) | uintptr_t(slint::cbindgen_private::AccessibleStringProperty::Label): return self->field_text_31.text.get();
        case (7 << 8) | uintptr_t(slint::cbindgen_private::AccessibleStringProperty::Label): return self->field_root_20_pkg.get().pretty_name;
        case (8 << 8) | uintptr_t(slint::cbindgen_private::AccessibleStringProperty::Label): return self->field_root_20_pkg.get().repo;
    }
    return {};
}

auto SuggestionCard_root_20::accessibility_action (uint32_t index, const slint::cbindgen_private::AccessibilityAction &action) const -> void{
    [[maybe_unused]] auto self = this;
    switch ((index << 8) | uintptr_t(action.tag)) {
    }
    return ;
}

auto SuggestionCard_root_20::supported_accessibility_actions (uint32_t index) const -> uint32_t{
    [[maybe_unused]] auto self = this;
    switch (index) {
    }
    return {};
}

auto SuggestionCard_root_20::element_infos (uint32_t index) const -> std::optional<slint::SharedString>{
    [[maybe_unused]] auto self = this;
    switch (index) {
    }
    return {};
}

auto SuggestionCard_root_20::ensure_instantiated () const -> bool{
    [[maybe_unused]] auto self = this;
    bool _changed = false;
    _changed |= self->repeater_0.ensure_updated(self);
    _changed |= self->repeater_1.ensure_updated(self);
    return _changed;
}

auto SuggestionCard_root_20::visit_dynamic_children (uint32_t dyn_index, [[maybe_unused]] slint::private_api::TraversalOrder order, [[maybe_unused]] slint::private_api::ItemVisitorRefMut visitor) const -> uint64_t{
        auto self = this;
        switch(dyn_index) { 
        case 0: {
                return self->repeater_0.visit(order, visitor);
            }
        case 1: {
                return self->repeater_1.visit(order, visitor);
            } };
        std::abort();
}

auto SuggestionCard_root_20::subtree_range (uintptr_t dyn_index) const -> slint::private_api::IndexRange{
    [[maybe_unused]] auto self = this;
        switch(dyn_index) { 
        case 0: {
                self->repeater_0.track_instance_changes();
                return self->repeater_0.index_range();
            }
        case 1: {
                self->repeater_1.track_instance_changes();
                return self->repeater_1.index_range();
            } };
        std::abort();
}

auto SuggestionCard_root_20::subtree_component (uintptr_t dyn_index, [[maybe_unused]] uintptr_t subtree_index, [[maybe_unused]] slint::private_api::ItemTreeWeak *result) const -> void{
    [[maybe_unused]] auto self = this;
        switch(dyn_index) { 
        case 0: {
                *result = self->repeater_0.instance_at(subtree_index);
                return;
            }
        case 1: {
                *result = self->repeater_1.instance_at(subtree_index);
                return;
            } };
        std::abort();
}

const slint::private_api::ItemTreeVTable Component_image_49::static_vtable = { visit_children, get_item_ref, get_subtree_range, get_subtree, get_item_tree, parent_node, embed_component, subtree_index, layout_info, ensure_instantiated, item_geometry, accessible_role, accessible_string_property, accessibility_action, supported_accessibility_actions, element_infos, window_adapter, slint::private_api::drop_in_place<Component_image_49>, slint::private_api::dealloc };

auto Component_image_49::init (const class SharedGlobals* globals,slint::cbindgen_private::ItemTreeWeak enclosing_component,uint32_t tree_index,uint32_t tree_index_of_first_child,class DetailsView_root_32 const *parent) -> void{
    auto self = this;
    self->self_weak = enclosing_component;
    self->globals = globals;
    this->tree_index_of_first_child = tree_index_of_first_child;
    self->tree_index = tree_index;
    self->parent = vtable::VRcMapped<slint::private_api::ItemTreeVTable, const DetailsView_root_32>(parent->self_weak.lock().value(), parent);
    self->field_image_49.height.set(96);
    self->field_image_49.source.set_binding([this]() {
                            [[maybe_unused]] auto self = this;
                            return slint::private_api::optional_or_default(slint::private_api::optional_transform(self->parent.lock(), [&](auto&&x) { return x->field_root_32_pkg.get(); })).icon;
                        });
    self->field_image_49.width.set(96);
    self->field_image_49.colorize.set_constant();
    self->field_image_49.height.set_constant();
    self->field_image_49.image_fit.set_constant();
    self->field_image_49.image_rendering.set_constant();
    self->field_image_49.width.set_constant();
}

auto Component_image_49::user_init () -> void{
    [[maybe_unused]] auto self = this;
}

auto Component_image_49::layout_info (slint::cbindgen_private::Orientation o) const -> slint::cbindgen_private::LayoutInfo{
    [[maybe_unused]] auto self = this;
    return o == slint::cbindgen_private::Orientation::Horizontal ? [&]{ [[maybe_unused]] auto layout_info = slint::private_api::item_layout_info(SLINT_GET_ITEM_VTABLE(ImageItemVTable), const_cast<slint::cbindgen_private::ImageItem*>(&self->field_image_49), slint::cbindgen_private::Orientation::Horizontal, -1, &self->globals->window().window_handle(), self->self_weak.lock()->into_dyn(), self->tree_index);;return [&](const auto &a_0, const auto &a_1, const auto &a_2, const auto &a_3, const auto &a_4, const auto &a_5){ slint::cbindgen_private::LayoutInfo o{}; o.max = a_0; o.max_percent = a_1; o.min = a_2; o.min_percent = a_3; o.preferred = a_4; o.stretch = a_5; return o; }(96, layout_info.max_percent, 96, layout_info.min_percent, layout_info.preferred, layout_info.stretch); }() : [&]{ [[maybe_unused]] auto layout_info = slint::private_api::item_layout_info(SLINT_GET_ITEM_VTABLE(ImageItemVTable), const_cast<slint::cbindgen_private::ImageItem*>(&self->field_image_49), slint::cbindgen_private::Orientation::Vertical, -1, &self->globals->window().window_handle(), self->self_weak.lock()->into_dyn(), self->tree_index);;return [&](const auto &a_0, const auto &a_1, const auto &a_2, const auto &a_3, const auto &a_4, const auto &a_5){ slint::cbindgen_private::LayoutInfo o{}; o.max = a_0; o.max_percent = a_1; o.min = a_2; o.min_percent = a_3; o.preferred = a_4; o.stretch = a_5; return o; }(96, layout_info.max_percent, 96, layout_info.min_percent, layout_info.preferred, layout_info.stretch); }();
}

auto Component_image_49::item_geometry (uint32_t index) const -> slint::cbindgen_private::Rect{
    [[maybe_unused]] auto self = this;
    switch (index) {
        case 0: return slint::private_api::convert_anonymous_rect(std::make_tuple(float(96), float(96), float(slint::private_api::optional_or_default(slint::private_api::optional_transform(self->parent.lock(), [&](auto&&x) { return slint::private_api::layout_cache_access(x->field_root_32_empty_48_layout_cache.get(), 0, 0, 2); }))), float(0)));
    }
    return {};
}

auto Component_image_49::accessible_role (uint32_t index) const -> slint::cbindgen_private::AccessibleRole{
    [[maybe_unused]] auto self = this;
    switch (index) {
        case 0: return slint::cbindgen_private::AccessibleRole::Image;
    }
    return {};
}

auto Component_image_49::accessible_string_property (uint32_t index, slint::cbindgen_private::AccessibleStringProperty what) const -> std::optional<slint::SharedString>{
    [[maybe_unused]] auto self = this;
    switch ((index << 8) | uintptr_t(what)) {
    }
    return {};
}

auto Component_image_49::accessibility_action (uint32_t index, const slint::cbindgen_private::AccessibilityAction &action) const -> void{
    [[maybe_unused]] auto self = this;
    switch ((index << 8) | uintptr_t(action.tag)) {
    }
    return ;
}

auto Component_image_49::supported_accessibility_actions (uint32_t index) const -> uint32_t{
    [[maybe_unused]] auto self = this;
    switch (index) {
    }
    return {};
}

auto Component_image_49::element_infos (uint32_t index) const -> std::optional<slint::SharedString>{
    [[maybe_unused]] auto self = this;
    switch (index) {
    }
    return {};
}

auto Component_image_49::ensure_instantiated () const -> bool{
    [[maybe_unused]] auto self = this;
    bool _changed = false;
    return _changed;
}

auto Component_image_49::visit_children (slint::private_api::ItemTreeRef component, intptr_t index, slint::private_api::TraversalOrder order, slint::private_api::ItemVisitorRefMut visitor) -> uint64_t{
    static const auto dyn_visit = [] (const void *base,  [[maybe_unused]] slint::private_api::TraversalOrder order, [[maybe_unused]] slint::private_api::ItemVisitorRefMut visitor, [[maybe_unused]] uint32_t dyn_index) -> uint64_t {
        [[maybe_unused]] auto self = reinterpret_cast<const Component_image_49*>(base);
        std::abort();
    };
    auto self_rc = reinterpret_cast<const Component_image_49*>(component.instance)->self_weak.lock()->into_dyn();
    return slint::cbindgen_private::slint_visit_item_tree(&self_rc, get_item_tree(component) , index, order, visitor, dyn_visit);
}

auto Component_image_49::get_item_ref (slint::private_api::ItemTreeRef component, uint32_t index) -> slint::private_api::ItemRef{
    return slint::private_api::get_item_ref(component, get_item_tree(component), item_array(), index);
}

auto Component_image_49::get_subtree_range ([[maybe_unused]] slint::private_api::ItemTreeRef component, [[maybe_unused]] uint32_t dyn_index) -> slint::private_api::IndexRange{
        std::abort();
}

auto Component_image_49::get_subtree ([[maybe_unused]] slint::private_api::ItemTreeRef component, [[maybe_unused]] uint32_t dyn_index, [[maybe_unused]] uintptr_t subtree_index, [[maybe_unused]] slint::private_api::ItemTreeWeak *result) -> void{
        std::abort();
}

auto Component_image_49::get_item_tree (slint::private_api::ItemTreeRef) -> slint::cbindgen_private::Slice<slint::private_api::ItemTreeNode>{
    return item_tree();
}

auto Component_image_49::parent_node ([[maybe_unused]] slint::private_api::ItemTreeRef component, [[maybe_unused]] slint::private_api::ItemWeak *result) -> void{
    auto self = reinterpret_cast<const Component_image_49*>(component.instance);
    auto parent = self->parent.lock().value();
    *result = { parent->self_weak, parent->tree_index_of_first_child + 20 };
}

auto Component_image_49::embed_component ([[maybe_unused]] slint::private_api::ItemTreeRef component, [[maybe_unused]] const slint::private_api::ItemTreeWeak *parent_component, [[maybe_unused]] const uint32_t parent_index) -> bool{
    return false; /* todo! */
}

auto Component_image_49::subtree_index ([[maybe_unused]] slint::private_api::ItemTreeRef component) -> uintptr_t{
    return std::numeric_limits<uintptr_t>::max();
}

auto Component_image_49::item_tree () -> slint::cbindgen_private::Slice<slint::private_api::ItemTreeNode>{
    static const slint::private_api::ItemTreeNode children[] {
        slint::private_api::make_item_node(0, 1, 0, 0, true) };
    return slint::private_api::make_slice(std::span(children));
}

auto Component_image_49::item_array () -> const slint::private_api::ItemArray{
    static const slint::private_api::ItemArrayEntry items[] {
        { SLINT_GET_ITEM_VTABLE(ImageItemVTable),  offsetof(Component_image_49, field_image_49) } };
    return slint::private_api::make_slice(std::span(items));
}

auto Component_image_49::layout_info ([[maybe_unused]] slint::private_api::ItemTreeRef component, slint::cbindgen_private::Orientation o) -> slint::cbindgen_private::LayoutInfo{
    return reinterpret_cast<const Component_image_49*>(component.instance)->layout_info(o);
}

auto Component_image_49::ensure_instantiated ([[maybe_unused]] slint::private_api::ItemTreeRef component) -> bool{
    return reinterpret_cast<const Component_image_49*>(component.instance)->ensure_instantiated();
}

auto Component_image_49::item_geometry ([[maybe_unused]] slint::private_api::ItemTreeRef component, uint32_t index) -> slint::cbindgen_private::LogicalRect{
    return reinterpret_cast<const Component_image_49*>(component.instance)->item_geometry(index);
}

auto Component_image_49::accessible_role ([[maybe_unused]] slint::private_api::ItemTreeRef component, uint32_t index) -> slint::cbindgen_private::AccessibleRole{
    return reinterpret_cast<const Component_image_49*>(component.instance)->accessible_role(index);
}

auto Component_image_49::accessible_string_property ([[maybe_unused]] slint::private_api::ItemTreeRef component, uint32_t index, slint::cbindgen_private::AccessibleStringProperty what, slint::SharedString *result) -> bool{
    if (auto r = reinterpret_cast<const Component_image_49*>(component.instance)->accessible_string_property(index, what)) { *result = *r; return true; } else { return false; }
}

auto Component_image_49::accessibility_action ([[maybe_unused]] slint::private_api::ItemTreeRef component, uint32_t index, const slint::cbindgen_private::AccessibilityAction *action) -> void{
    reinterpret_cast<const Component_image_49*>(component.instance)->accessibility_action(index, *action);
}

auto Component_image_49::supported_accessibility_actions ([[maybe_unused]] slint::private_api::ItemTreeRef component, uint32_t index) -> uint32_t{
    return reinterpret_cast<const Component_image_49*>(component.instance)->supported_accessibility_actions(index);
}

auto Component_image_49::element_infos ([[maybe_unused]] slint::private_api::ItemTreeRef component, [[maybe_unused]] uint32_t index, [[maybe_unused]] slint::SharedString *result) -> bool{
    return false;
}

auto Component_image_49::window_adapter ([[maybe_unused]] slint::private_api::ItemTreeRef component, [[maybe_unused]] bool do_create, [[maybe_unused]] slint::cbindgen_private::Option<slint::private_api::WindowAdapterRc>* result) -> void{
    *reinterpret_cast<slint::private_api::WindowAdapterRc*>(result) = reinterpret_cast<const Component_image_49*>(component.instance)->globals->window().window_handle();
}

auto Component_image_49::create (class DetailsView_root_32 const * parent) -> slint::ComponentHandle<Component_image_49>{
    auto self_rc = vtable::VRc<slint::private_api::ItemTreeVTable, Component_image_49>::make();
    auto self = const_cast<Component_image_49 *>(&*self_rc);
    self->self_weak = vtable::VWeak(self_rc).into_dyn();
    slint::private_api::register_item_tree(&self_rc.into_dyn(), parent->globals->m_window);
    self->init(parent->globals, self->self_weak, 0, 1 , parent);
    return slint::ComponentHandle<Component_image_49>{ self_rc };
}

Component_image_49::~Component_image_49 (){
    if (auto &window = globals->m_window) window->window_handle().unregister_item_tree(this, item_array());
}

auto Component_image_49::init () -> void{
    user_init();
}

auto Component_image_49::layout_item_info (slint::cbindgen_private::Orientation o, [[maybe_unused]] std::optional<size_t> child_index) const -> slint::cbindgen_private::LayoutItemInfo{
    return { layout_info({&static_vtable, const_cast<void *>(static_cast<const void *>(this))}, o) };
}

auto Component_image_49::flexbox_layout_item_info (slint::cbindgen_private::Orientation o, [[maybe_unused]] std::optional<size_t> child_index) const -> slint::cbindgen_private::FlexboxLayoutItemInfo{
    auto base = layout_item_info(o, child_index); return { base.constraint, 0.0f, 0.0f, -1.0f, slint::cbindgen_private::FlexboxLayoutAlignSelf::Auto, 0 };
}

const slint::private_api::ItemTreeVTable Component_rectangle_51::static_vtable = { visit_children, get_item_ref, get_subtree_range, get_subtree, get_item_tree, parent_node, embed_component, subtree_index, layout_info, ensure_instantiated, item_geometry, accessible_role, accessible_string_property, accessibility_action, supported_accessibility_actions, element_infos, window_adapter, slint::private_api::drop_in_place<Component_rectangle_51>, slint::private_api::dealloc };

auto Component_rectangle_51::init (const class SharedGlobals* globals,slint::cbindgen_private::ItemTreeWeak enclosing_component,uint32_t tree_index,uint32_t tree_index_of_first_child,class DetailsView_root_32 const *parent) -> void{
    auto self = this;
    self->self_weak = enclosing_component;
    self->globals = globals;
    this->tree_index_of_first_child = tree_index_of_first_child;
    self->tree_index = tree_index;
    self->parent = vtable::VRcMapped<slint::private_api::ItemTreeVTable, const DetailsView_root_32>(parent->self_weak.lock().value(), parent);
    self->field_rectangle_51.background.set_binding([this]() {
                            [[maybe_unused]] auto self = this;
                            return slint::Brush(slint::private_api::optional_or_default(slint::private_api::optional_transform(self->parent.lock(), [&](auto&&x) { return x->field_root_32_accent.get(); })));
                        });
    self->field_rectangle_51.border_radius.set(22);
    self->field_rectangle_51.border_color.set_constant();
    self->field_rectangle_51.border_radius.set_constant();
    self->field_rectangle_51.border_width.set_constant();
}

auto Component_rectangle_51::user_init () -> void{
    [[maybe_unused]] auto self = this;
}

auto Component_rectangle_51::layout_info (slint::cbindgen_private::Orientation o) const -> slint::cbindgen_private::LayoutInfo{
    [[maybe_unused]] auto self = this;
    return o == slint::cbindgen_private::Orientation::Horizontal ? [&]{ [[maybe_unused]] auto layout_info = slint::private_api::item_layout_info(SLINT_GET_ITEM_VTABLE(BasicBorderRectangleVTable), const_cast<slint::cbindgen_private::BasicBorderRectangle*>(&self->field_rectangle_51), slint::cbindgen_private::Orientation::Horizontal, -1, &self->globals->window().window_handle(), self->self_weak.lock()->into_dyn(), self->tree_index);;return [&](const auto &a_0, const auto &a_1, const auto &a_2, const auto &a_3, const auto &a_4, const auto &a_5){ slint::cbindgen_private::LayoutInfo o{}; o.max = a_0; o.max_percent = a_1; o.min = a_2; o.min_percent = a_3; o.preferred = a_4; o.stretch = a_5; return o; }(96, layout_info.max_percent, 96, layout_info.min_percent, layout_info.preferred, layout_info.stretch); }() : [&]{ [[maybe_unused]] auto layout_info = slint::private_api::item_layout_info(SLINT_GET_ITEM_VTABLE(BasicBorderRectangleVTable), const_cast<slint::cbindgen_private::BasicBorderRectangle*>(&self->field_rectangle_51), slint::cbindgen_private::Orientation::Vertical, -1, &self->globals->window().window_handle(), self->self_weak.lock()->into_dyn(), self->tree_index);;return [&](const auto &a_0, const auto &a_1, const auto &a_2, const auto &a_3, const auto &a_4, const auto &a_5){ slint::cbindgen_private::LayoutInfo o{}; o.max = a_0; o.max_percent = a_1; o.min = a_2; o.min_percent = a_3; o.preferred = a_4; o.stretch = a_5; return o; }(96, layout_info.max_percent, 96, layout_info.min_percent, layout_info.preferred, layout_info.stretch); }();
}

auto Component_rectangle_51::item_geometry (uint32_t index) const -> slint::cbindgen_private::Rect{
    [[maybe_unused]] auto self = this;
    switch (index) {
        case 0: return slint::private_api::convert_anonymous_rect(std::make_tuple(float(96), float(96), float(slint::private_api::optional_or_default(slint::private_api::optional_transform(self->parent.lock(), [&](auto&&x) { return slint::private_api::layout_cache_access(x->field_root_32_empty_48_layout_cache.get(), 2, 0, 2); }))), float(0)));
    }
    return {};
}

auto Component_rectangle_51::accessible_role (uint32_t index) const -> slint::cbindgen_private::AccessibleRole{
    [[maybe_unused]] auto self = this;
    switch (index) {
    }
    return {};
}

auto Component_rectangle_51::accessible_string_property (uint32_t index, slint::cbindgen_private::AccessibleStringProperty what) const -> std::optional<slint::SharedString>{
    [[maybe_unused]] auto self = this;
    switch ((index << 8) | uintptr_t(what)) {
    }
    return {};
}

auto Component_rectangle_51::accessibility_action (uint32_t index, const slint::cbindgen_private::AccessibilityAction &action) const -> void{
    [[maybe_unused]] auto self = this;
    switch ((index << 8) | uintptr_t(action.tag)) {
    }
    return ;
}

auto Component_rectangle_51::supported_accessibility_actions (uint32_t index) const -> uint32_t{
    [[maybe_unused]] auto self = this;
    switch (index) {
    }
    return {};
}

auto Component_rectangle_51::element_infos (uint32_t index) const -> std::optional<slint::SharedString>{
    [[maybe_unused]] auto self = this;
    switch (index) {
    }
    return {};
}

auto Component_rectangle_51::ensure_instantiated () const -> bool{
    [[maybe_unused]] auto self = this;
    bool _changed = false;
    return _changed;
}

auto Component_rectangle_51::visit_children (slint::private_api::ItemTreeRef component, intptr_t index, slint::private_api::TraversalOrder order, slint::private_api::ItemVisitorRefMut visitor) -> uint64_t{
    static const auto dyn_visit = [] (const void *base,  [[maybe_unused]] slint::private_api::TraversalOrder order, [[maybe_unused]] slint::private_api::ItemVisitorRefMut visitor, [[maybe_unused]] uint32_t dyn_index) -> uint64_t {
        [[maybe_unused]] auto self = reinterpret_cast<const Component_rectangle_51*>(base);
        std::abort();
    };
    auto self_rc = reinterpret_cast<const Component_rectangle_51*>(component.instance)->self_weak.lock()->into_dyn();
    return slint::cbindgen_private::slint_visit_item_tree(&self_rc, get_item_tree(component) , index, order, visitor, dyn_visit);
}

auto Component_rectangle_51::get_item_ref (slint::private_api::ItemTreeRef component, uint32_t index) -> slint::private_api::ItemRef{
    return slint::private_api::get_item_ref(component, get_item_tree(component), item_array(), index);
}

auto Component_rectangle_51::get_subtree_range ([[maybe_unused]] slint::private_api::ItemTreeRef component, [[maybe_unused]] uint32_t dyn_index) -> slint::private_api::IndexRange{
        std::abort();
}

auto Component_rectangle_51::get_subtree ([[maybe_unused]] slint::private_api::ItemTreeRef component, [[maybe_unused]] uint32_t dyn_index, [[maybe_unused]] uintptr_t subtree_index, [[maybe_unused]] slint::private_api::ItemTreeWeak *result) -> void{
        std::abort();
}

auto Component_rectangle_51::get_item_tree (slint::private_api::ItemTreeRef) -> slint::cbindgen_private::Slice<slint::private_api::ItemTreeNode>{
    return item_tree();
}

auto Component_rectangle_51::parent_node ([[maybe_unused]] slint::private_api::ItemTreeRef component, [[maybe_unused]] slint::private_api::ItemWeak *result) -> void{
    auto self = reinterpret_cast<const Component_rectangle_51*>(component.instance);
    auto parent = self->parent.lock().value();
    *result = { parent->self_weak, parent->tree_index_of_first_child + 21 };
}

auto Component_rectangle_51::embed_component ([[maybe_unused]] slint::private_api::ItemTreeRef component, [[maybe_unused]] const slint::private_api::ItemTreeWeak *parent_component, [[maybe_unused]] const uint32_t parent_index) -> bool{
    return false; /* todo! */
}

auto Component_rectangle_51::subtree_index ([[maybe_unused]] slint::private_api::ItemTreeRef component) -> uintptr_t{
    return std::numeric_limits<uintptr_t>::max();
}

auto Component_rectangle_51::item_tree () -> slint::cbindgen_private::Slice<slint::private_api::ItemTreeNode>{
    static const slint::private_api::ItemTreeNode children[] {
        slint::private_api::make_item_node(0, 1, 0, 0, false) };
    return slint::private_api::make_slice(std::span(children));
}

auto Component_rectangle_51::item_array () -> const slint::private_api::ItemArray{
    static const slint::private_api::ItemArrayEntry items[] {
        { SLINT_GET_ITEM_VTABLE(BasicBorderRectangleVTable),  offsetof(Component_rectangle_51, field_rectangle_51) } };
    return slint::private_api::make_slice(std::span(items));
}

auto Component_rectangle_51::layout_info ([[maybe_unused]] slint::private_api::ItemTreeRef component, slint::cbindgen_private::Orientation o) -> slint::cbindgen_private::LayoutInfo{
    return reinterpret_cast<const Component_rectangle_51*>(component.instance)->layout_info(o);
}

auto Component_rectangle_51::ensure_instantiated ([[maybe_unused]] slint::private_api::ItemTreeRef component) -> bool{
    return reinterpret_cast<const Component_rectangle_51*>(component.instance)->ensure_instantiated();
}

auto Component_rectangle_51::item_geometry ([[maybe_unused]] slint::private_api::ItemTreeRef component, uint32_t index) -> slint::cbindgen_private::LogicalRect{
    return reinterpret_cast<const Component_rectangle_51*>(component.instance)->item_geometry(index);
}

auto Component_rectangle_51::accessible_role ([[maybe_unused]] slint::private_api::ItemTreeRef component, uint32_t index) -> slint::cbindgen_private::AccessibleRole{
    return reinterpret_cast<const Component_rectangle_51*>(component.instance)->accessible_role(index);
}

auto Component_rectangle_51::accessible_string_property ([[maybe_unused]] slint::private_api::ItemTreeRef component, uint32_t index, slint::cbindgen_private::AccessibleStringProperty what, slint::SharedString *result) -> bool{
    if (auto r = reinterpret_cast<const Component_rectangle_51*>(component.instance)->accessible_string_property(index, what)) { *result = *r; return true; } else { return false; }
}

auto Component_rectangle_51::accessibility_action ([[maybe_unused]] slint::private_api::ItemTreeRef component, uint32_t index, const slint::cbindgen_private::AccessibilityAction *action) -> void{
    reinterpret_cast<const Component_rectangle_51*>(component.instance)->accessibility_action(index, *action);
}

auto Component_rectangle_51::supported_accessibility_actions ([[maybe_unused]] slint::private_api::ItemTreeRef component, uint32_t index) -> uint32_t{
    return reinterpret_cast<const Component_rectangle_51*>(component.instance)->supported_accessibility_actions(index);
}

auto Component_rectangle_51::element_infos ([[maybe_unused]] slint::private_api::ItemTreeRef component, [[maybe_unused]] uint32_t index, [[maybe_unused]] slint::SharedString *result) -> bool{
    return false;
}

auto Component_rectangle_51::window_adapter ([[maybe_unused]] slint::private_api::ItemTreeRef component, [[maybe_unused]] bool do_create, [[maybe_unused]] slint::cbindgen_private::Option<slint::private_api::WindowAdapterRc>* result) -> void{
    *reinterpret_cast<slint::private_api::WindowAdapterRc*>(result) = reinterpret_cast<const Component_rectangle_51*>(component.instance)->globals->window().window_handle();
}

auto Component_rectangle_51::create (class DetailsView_root_32 const * parent) -> slint::ComponentHandle<Component_rectangle_51>{
    auto self_rc = vtable::VRc<slint::private_api::ItemTreeVTable, Component_rectangle_51>::make();
    auto self = const_cast<Component_rectangle_51 *>(&*self_rc);
    self->self_weak = vtable::VWeak(self_rc).into_dyn();
    slint::private_api::register_item_tree(&self_rc.into_dyn(), parent->globals->m_window);
    self->init(parent->globals, self->self_weak, 0, 1 , parent);
    return slint::ComponentHandle<Component_rectangle_51>{ self_rc };
}

Component_rectangle_51::~Component_rectangle_51 (){
    if (auto &window = globals->m_window) window->window_handle().unregister_item_tree(this, item_array());
}

auto Component_rectangle_51::init () -> void{
    user_init();
}

auto Component_rectangle_51::layout_item_info (slint::cbindgen_private::Orientation o, [[maybe_unused]] std::optional<size_t> child_index) const -> slint::cbindgen_private::LayoutItemInfo{
    return { layout_info({&static_vtable, const_cast<void *>(static_cast<const void *>(this))}, o) };
}

auto Component_rectangle_51::flexbox_layout_item_info (slint::cbindgen_private::Orientation o, [[maybe_unused]] std::optional<size_t> child_index) const -> slint::cbindgen_private::FlexboxLayoutItemInfo{
    auto base = layout_item_info(o, child_index); return { base.constraint, 0.0f, 0.0f, -1.0f, slint::cbindgen_private::FlexboxLayoutAlignSelf::Auto, 0 };
}

const slint::private_api::ItemTreeVTable Component_rectangle_65::static_vtable = { visit_children, get_item_ref, get_subtree_range, get_subtree, get_item_tree, parent_node, embed_component, subtree_index, layout_info, ensure_instantiated, item_geometry, accessible_role, accessible_string_property, accessibility_action, supported_accessibility_actions, element_infos, window_adapter, slint::private_api::drop_in_place<Component_rectangle_65>, slint::private_api::dealloc };

auto Component_rectangle_65::init (const class SharedGlobals* globals,slint::cbindgen_private::ItemTreeWeak enclosing_component,uint32_t tree_index,uint32_t tree_index_of_first_child,class DetailsView_root_32 const *parent) -> void{
    auto self = this;
    self->self_weak = enclosing_component;
    self->globals = globals;
    this->tree_index_of_first_child = tree_index_of_first_child;
    self->tree_index = tree_index;
    self->parent = vtable::VRcMapped<slint::private_api::ItemTreeVTable, const DetailsView_root_32>(parent->self_weak.lock().value(), parent);
    self->field_rectangle_65.background.set(slint::Brush(slint::Color::from_argb_encoded(+4.279769125e9)));
    self->field_rectangle_65.border_color.set(slint::Brush(slint::Color::from_argb_encoded(+4.281414212e9)));
    self->field_rectangle_65.border_radius.set(16);
    self->field_rectangle_65.border_width.set(1);
    self->field_rectangle_65_empty_66_layout_cache.set_binding([this]() {
                            [[maybe_unused]] auto self = this;
                            return slint::private_api::solve_box_layout([&](const auto &a_0, const auto &a_1, const auto &a_2, const auto &a_3, const auto &a_4){ slint::cbindgen_private::BoxLayoutData o{}; o.alignment = a_0; o.cells = a_1; o.padding = a_2; o.size = a_3; o.spacing = a_4; return o; }(slint::cbindgen_private::LayoutAlignment::Stretch, slint::private_api::make_slice<slint::cbindgen_private::LayoutItemInfo>(std::array<slint::cbindgen_private::LayoutItemInfo, 2>{ slint::cbindgen_private::LayoutItemInfo ( [&](const auto &a_0){ slint::cbindgen_private::LayoutItemInfo o{}; o.constraint = a_0; return o; }(self->field_rectangle_65_empty_67_layoutinfo_v.get()) ), slint::cbindgen_private::LayoutItemInfo ( [&](const auto &a_0){ slint::cbindgen_private::LayoutItemInfo o{}; o.constraint = a_0; return o; }(self->field_rectangle_65_empty_70_layoutinfo_v.get()) ) }.data(), 2), [&](const auto &a_0, const auto &a_1){ slint::cbindgen_private::Padding o{}; o.begin = a_0; o.end = a_1; return o; }(22, 22), slint::private_api::optional_or_default(slint::private_api::optional_transform(self->parent.lock(), [&](auto&&x) { return slint::private_api::layout_cache_access(x->field_root_32_empty_47_layout_cache.get(), 3, 0, 2); })), 14),slint::private_api::make_slice<int>(std::array<int, 0>{  }.data(), 0));
                        });
    self->field_rectangle_65_empty_66_layoutinfo_h.set_binding([this]() {
                            [[maybe_unused]] auto self = this;
                            return slint::private_api::box_layout_info_ortho(slint::private_api::make_slice<slint::cbindgen_private::LayoutItemInfo>(std::array<slint::cbindgen_private::LayoutItemInfo, 2>{ slint::cbindgen_private::LayoutItemInfo ( [&](const auto &a_0){ slint::cbindgen_private::LayoutItemInfo o{}; o.constraint = a_0; return o; }(self->field_rectangle_65_empty_67_layoutinfo_h.get()) ), slint::cbindgen_private::LayoutItemInfo ( [&](const auto &a_0){ slint::cbindgen_private::LayoutItemInfo o{}; o.constraint = a_0; return o; }(self->field_rectangle_65_empty_70_layoutinfo_h.get()) ) }.data(), 2),[&](const auto &a_0, const auto &a_1){ slint::cbindgen_private::Padding o{}; o.begin = a_0; o.end = a_1; return o; }(22, 22));
                        });
    self->field_rectangle_65_empty_66_layoutinfo_v.set_binding([this]() {
                            [[maybe_unused]] auto self = this;
                            return slint::private_api::box_layout_info(slint::private_api::make_slice<slint::cbindgen_private::LayoutItemInfo>(std::array<slint::cbindgen_private::LayoutItemInfo, 2>{ slint::cbindgen_private::LayoutItemInfo ( [&](const auto &a_0){ slint::cbindgen_private::LayoutItemInfo o{}; o.constraint = a_0; return o; }(self->field_rectangle_65_empty_67_layoutinfo_v.get()) ), slint::cbindgen_private::LayoutItemInfo ( [&](const auto &a_0){ slint::cbindgen_private::LayoutItemInfo o{}; o.constraint = a_0; return o; }(self->field_rectangle_65_empty_70_layoutinfo_v.get()) ) }.data(), 2),14,[&](const auto &a_0, const auto &a_1){ slint::cbindgen_private::Padding o{}; o.begin = a_0; o.end = a_1; return o; }(22, 22),slint::cbindgen_private::LayoutAlignment::Stretch);
                        });
    self->field_rectangle_65_empty_67_layout_cache.set_binding([this]() {
                            [[maybe_unused]] auto self = this;
                            return slint::private_api::solve_box_layout([&](const auto &a_0, const auto &a_1, const auto &a_2, const auto &a_3, const auto &a_4){ slint::cbindgen_private::BoxLayoutData o{}; o.alignment = a_0; o.cells = a_1; o.padding = a_2; o.size = a_3; o.spacing = a_4; return o; }(slint::cbindgen_private::LayoutAlignment::SpaceBetween, slint::private_api::make_slice<slint::cbindgen_private::LayoutItemInfo>(std::array<slint::cbindgen_private::LayoutItemInfo, 2>{ slint::cbindgen_private::LayoutItemInfo ( [&](const auto &a_0){ slint::cbindgen_private::LayoutItemInfo o{}; o.constraint = a_0; return o; }(slint::private_api::item_layout_info(SLINT_GET_ITEM_VTABLE(SimpleTextVTable), const_cast<slint::cbindgen_private::SimpleText*>(&self->field_text_68), slint::cbindgen_private::Orientation::Horizontal, -1, &self->globals->window().window_handle(), self->self_weak.lock()->into_dyn(), self->tree_index_of_first_child + 3 - 1)) ), slint::cbindgen_private::LayoutItemInfo ( [&](const auto &a_0){ slint::cbindgen_private::LayoutItemInfo o{}; o.constraint = a_0; return o; }(slint::private_api::item_layout_info(SLINT_GET_ITEM_VTABLE(SimpleTextVTable), const_cast<slint::cbindgen_private::SimpleText*>(&self->field_text_69), slint::cbindgen_private::Orientation::Horizontal, -1, &self->globals->window().window_handle(), self->self_weak.lock()->into_dyn(), self->tree_index_of_first_child + 4 - 1)) ) }.data(), 2), [&](const auto &a_0, const auto &a_1){ slint::cbindgen_private::Padding o{}; o.begin = a_0; o.end = a_1; return o; }(0, 0), ((((slint::private_api::optional_or_default(slint::private_api::optional_transform(self->parent.lock(), [&](auto&&x) { return x->field_flickable_45.viewport_width.get(); })) -(float) 64) -(float) 64) -(float) 22) -(float) 22), 0),slint::private_api::make_slice<int>(std::array<int, 0>{  }.data(), 0));
                        });
    self->field_rectangle_65_empty_67_layoutinfo_h.set_binding([this]() {
                            [[maybe_unused]] auto self = this;
                            return slint::private_api::box_layout_info(slint::private_api::make_slice<slint::cbindgen_private::LayoutItemInfo>(std::array<slint::cbindgen_private::LayoutItemInfo, 2>{ slint::cbindgen_private::LayoutItemInfo ( [&](const auto &a_0){ slint::cbindgen_private::LayoutItemInfo o{}; o.constraint = a_0; return o; }(slint::private_api::item_layout_info(SLINT_GET_ITEM_VTABLE(SimpleTextVTable), const_cast<slint::cbindgen_private::SimpleText*>(&self->field_text_68), slint::cbindgen_private::Orientation::Horizontal, -1, &self->globals->window().window_handle(), self->self_weak.lock()->into_dyn(), self->tree_index_of_first_child + 3 - 1)) ), slint::cbindgen_private::LayoutItemInfo ( [&](const auto &a_0){ slint::cbindgen_private::LayoutItemInfo o{}; o.constraint = a_0; return o; }(slint::private_api::item_layout_info(SLINT_GET_ITEM_VTABLE(SimpleTextVTable), const_cast<slint::cbindgen_private::SimpleText*>(&self->field_text_69), slint::cbindgen_private::Orientation::Horizontal, -1, &self->globals->window().window_handle(), self->self_weak.lock()->into_dyn(), self->tree_index_of_first_child + 4 - 1)) ) }.data(), 2),0,[&](const auto &a_0, const auto &a_1){ slint::cbindgen_private::Padding o{}; o.begin = a_0; o.end = a_1; return o; }(0, 0),slint::cbindgen_private::LayoutAlignment::SpaceBetween);
                        });
    self->field_rectangle_65_empty_67_layoutinfo_v.set_binding([this]() {
                            [[maybe_unused]] auto self = this;
                            return slint::private_api::box_layout_info_ortho(slint::private_api::make_slice<slint::cbindgen_private::LayoutItemInfo>(std::array<slint::cbindgen_private::LayoutItemInfo, 2>{ slint::cbindgen_private::LayoutItemInfo ( [&](const auto &a_0){ slint::cbindgen_private::LayoutItemInfo o{}; o.constraint = a_0; return o; }(slint::private_api::item_layout_info(SLINT_GET_ITEM_VTABLE(SimpleTextVTable), const_cast<slint::cbindgen_private::SimpleText*>(&self->field_text_68), slint::cbindgen_private::Orientation::Vertical, -1, &self->globals->window().window_handle(), self->self_weak.lock()->into_dyn(), self->tree_index_of_first_child + 3 - 1)) ), slint::cbindgen_private::LayoutItemInfo ( [&](const auto &a_0){ slint::cbindgen_private::LayoutItemInfo o{}; o.constraint = a_0; return o; }(slint::private_api::item_layout_info(SLINT_GET_ITEM_VTABLE(SimpleTextVTable), const_cast<slint::cbindgen_private::SimpleText*>(&self->field_text_69), slint::cbindgen_private::Orientation::Vertical, -1, &self->globals->window().window_handle(), self->self_weak.lock()->into_dyn(), self->tree_index_of_first_child + 4 - 1)) ) }.data(), 2),[&](const auto &a_0, const auto &a_1){ slint::cbindgen_private::Padding o{}; o.begin = a_0; o.end = a_1; return o; }(0, 0));
                        });
    self->field_rectangle_65_empty_70_layout_cache.set_binding([this]() {
                            [[maybe_unused]] auto self = this;
                            return slint::private_api::solve_box_layout([&](const auto &a_0, const auto &a_1, const auto &a_2, const auto &a_3, const auto &a_4){ slint::cbindgen_private::BoxLayoutData o{}; o.alignment = a_0; o.cells = a_1; o.padding = a_2; o.size = a_3; o.spacing = a_4; return o; }(slint::cbindgen_private::LayoutAlignment::Stretch, slint::private_api::make_slice<slint::cbindgen_private::LayoutItemInfo>(std::array<slint::cbindgen_private::LayoutItemInfo, 2>{ slint::cbindgen_private::LayoutItemInfo ( [&](const auto &a_0){ slint::cbindgen_private::LayoutItemInfo o{}; o.constraint = a_0; return o; }([&]{ [[maybe_unused]] auto layout_info = ([&](const auto &a_0, const auto &a_1, const auto &a_2, const auto &a_3, const auto &a_4, const auto &a_5){ slint::cbindgen_private::LayoutInfo o{}; o.max = a_0; o.max_percent = a_1; o.min = a_2; o.min_percent = a_3; o.preferred = a_4; o.stretch = a_5; return o; }(+3.4028234663852886e38, 100, 0, 0, 0, 1) + self->field_rectangle_65_empty_73_layoutinfo_h.get());;return [&](const auto &a_0, const auto &a_1, const auto &a_2, const auto &a_3, const auto &a_4, const auto &a_5){ slint::cbindgen_private::LayoutInfo o{}; o.max = a_0; o.max_percent = a_1; o.min = a_2; o.min_percent = a_3; o.preferred = a_4; o.stretch = a_5; return o; }(layout_info.max, layout_info.max_percent, layout_info.min, layout_info.min_percent, layout_info.preferred, 1); }()) ), slint::cbindgen_private::LayoutItemInfo ( [&](const auto &a_0){ slint::cbindgen_private::LayoutItemInfo o{}; o.constraint = a_0; return o; }([&]{ [[maybe_unused]] auto layout_info = self->field_rectangle_65_rectangle_77_layoutinfo_h.get();;return [&](const auto &a_0, const auto &a_1, const auto &a_2, const auto &a_3, const auto &a_4, const auto &a_5){ slint::cbindgen_private::LayoutInfo o{}; o.max = a_0; o.max_percent = a_1; o.min = a_2; o.min_percent = a_3; o.preferred = a_4; o.stretch = a_5; return o; }(100, layout_info.max_percent, 100, layout_info.min_percent, layout_info.preferred, layout_info.stretch); }()) ) }.data(), 2), [&](const auto &a_0, const auto &a_1){ slint::cbindgen_private::Padding o{}; o.begin = a_0; o.end = a_1; return o; }(0, 0), ((((slint::private_api::optional_or_default(slint::private_api::optional_transform(self->parent.lock(), [&](auto&&x) { return x->field_flickable_45.viewport_width.get(); })) -(float) 64) -(float) 64) -(float) 22) -(float) 22), 12),slint::private_api::make_slice<int>(std::array<int, 0>{  }.data(), 0));
                        });
    self->field_rectangle_65_empty_70_layoutinfo_h.set_binding([this]() {
                            [[maybe_unused]] auto self = this;
                            return slint::private_api::box_layout_info(slint::private_api::make_slice<slint::cbindgen_private::LayoutItemInfo>(std::array<slint::cbindgen_private::LayoutItemInfo, 2>{ slint::cbindgen_private::LayoutItemInfo ( [&](const auto &a_0){ slint::cbindgen_private::LayoutItemInfo o{}; o.constraint = a_0; return o; }([&]{ [[maybe_unused]] auto layout_info = ([&](const auto &a_0, const auto &a_1, const auto &a_2, const auto &a_3, const auto &a_4, const auto &a_5){ slint::cbindgen_private::LayoutInfo o{}; o.max = a_0; o.max_percent = a_1; o.min = a_2; o.min_percent = a_3; o.preferred = a_4; o.stretch = a_5; return o; }(+3.4028234663852886e38, 100, 0, 0, 0, 1) + self->field_rectangle_65_empty_73_layoutinfo_h.get());;return [&](const auto &a_0, const auto &a_1, const auto &a_2, const auto &a_3, const auto &a_4, const auto &a_5){ slint::cbindgen_private::LayoutInfo o{}; o.max = a_0; o.max_percent = a_1; o.min = a_2; o.min_percent = a_3; o.preferred = a_4; o.stretch = a_5; return o; }(layout_info.max, layout_info.max_percent, layout_info.min, layout_info.min_percent, layout_info.preferred, 1); }()) ), slint::cbindgen_private::LayoutItemInfo ( [&](const auto &a_0){ slint::cbindgen_private::LayoutItemInfo o{}; o.constraint = a_0; return o; }([&]{ [[maybe_unused]] auto layout_info = self->field_rectangle_65_rectangle_77_layoutinfo_h.get();;return [&](const auto &a_0, const auto &a_1, const auto &a_2, const auto &a_3, const auto &a_4, const auto &a_5){ slint::cbindgen_private::LayoutInfo o{}; o.max = a_0; o.max_percent = a_1; o.min = a_2; o.min_percent = a_3; o.preferred = a_4; o.stretch = a_5; return o; }(100, layout_info.max_percent, 100, layout_info.min_percent, layout_info.preferred, layout_info.stretch); }()) ) }.data(), 2),12,[&](const auto &a_0, const auto &a_1){ slint::cbindgen_private::Padding o{}; o.begin = a_0; o.end = a_1; return o; }(0, 0),slint::cbindgen_private::LayoutAlignment::Stretch);
                        });
    self->field_rectangle_65_empty_70_layoutinfo_v.set_binding([this]() {
                            [[maybe_unused]] auto self = this;
                            return slint::private_api::box_layout_info_ortho(slint::private_api::make_slice<slint::cbindgen_private::LayoutItemInfo>(std::array<slint::cbindgen_private::LayoutItemInfo, 2>{ slint::cbindgen_private::LayoutItemInfo ( [&](const auto &a_0){ slint::cbindgen_private::LayoutItemInfo o{}; o.constraint = a_0; return o; }([&]{ [[maybe_unused]] auto layout_info = ([&](const auto &a_0, const auto &a_1, const auto &a_2, const auto &a_3, const auto &a_4, const auto &a_5){ slint::cbindgen_private::LayoutInfo o{}; o.max = a_0; o.max_percent = a_1; o.min = a_2; o.min_percent = a_3; o.preferred = a_4; o.stretch = a_5; return o; }(+3.4028234663852886e38, 100, 0, 0, 0, 1) + self->field_rectangle_65_empty_73_layoutinfo_v.get());;return [&](const auto &a_0, const auto &a_1, const auto &a_2, const auto &a_3, const auto &a_4, const auto &a_5){ slint::cbindgen_private::LayoutInfo o{}; o.max = a_0; o.max_percent = a_1; o.min = a_2; o.min_percent = a_3; o.preferred = a_4; o.stretch = a_5; return o; }(10, layout_info.max_percent, 10, layout_info.min_percent, layout_info.preferred, layout_info.stretch); }()) ), slint::cbindgen_private::LayoutItemInfo ( [&](const auto &a_0){ slint::cbindgen_private::LayoutItemInfo o{}; o.constraint = a_0; return o; }([&]{ [[maybe_unused]] auto layout_info = self->field_rectangle_65_rectangle_77_layoutinfo_v.get();;return [&](const auto &a_0, const auto &a_1, const auto &a_2, const auto &a_3, const auto &a_4, const auto &a_5){ slint::cbindgen_private::LayoutInfo o{}; o.max = a_0; o.max_percent = a_1; o.min = a_2; o.min_percent = a_3; o.preferred = a_4; o.stretch = a_5; return o; }(34, layout_info.max_percent, 34, layout_info.min_percent, layout_info.preferred, layout_info.stretch); }()) ) }.data(), 2),[&](const auto &a_0, const auto &a_1){ slint::cbindgen_private::Padding o{}; o.begin = a_0; o.end = a_1; return o; }(0, 0));
                        });
    self->field_rectangle_65_empty_73_layout_cache.set_binding([this]() {
                            [[maybe_unused]] auto self = this;
                            return slint::private_api::solve_box_layout([&](const auto &a_0, const auto &a_1, const auto &a_2, const auto &a_3, const auto &a_4){ slint::cbindgen_private::BoxLayoutData o{}; o.alignment = a_0; o.cells = a_1; o.padding = a_2; o.size = a_3; o.spacing = a_4; return o; }(slint::cbindgen_private::LayoutAlignment::Stretch, slint::private_api::make_slice<slint::cbindgen_private::LayoutItemInfo>(std::array<slint::cbindgen_private::LayoutItemInfo, 3>{ slint::cbindgen_private::LayoutItemInfo ( [&](const auto &a_0){ slint::cbindgen_private::LayoutItemInfo o{}; o.constraint = a_0; return o; }([&]{ [[maybe_unused]] auto layout_info = slint::private_api::item_layout_info(SLINT_GET_ITEM_VTABLE(RectangleVTable), const_cast<slint::cbindgen_private::Rectangle*>(&self->field_rectangle_74), slint::cbindgen_private::Orientation::Horizontal, -1, &self->globals->window().window_handle(), self->self_weak.lock()->into_dyn(), self->tree_index_of_first_child + 8 - 1);;return [&](const auto &a_0, const auto &a_1, const auto &a_2, const auto &a_3, const auto &a_4, const auto &a_5){ slint::cbindgen_private::LayoutInfo o{}; o.max = a_0; o.max_percent = a_1; o.min = a_2; o.min_percent = a_3; o.preferred = a_4; o.stretch = a_5; return o; }(layout_info.max, layout_info.max_percent, layout_info.min, layout_info.min_percent, layout_info.preferred, [&]{ [[maybe_unused]] auto tmp_root_32_install_state = slint::private_api::optional_or_default(slint::private_api::optional_transform(self->parent.lock(), [&](auto&&x) { return x->field_root_32_install_state.get(); }));;return std::max<float>(0.0001, std::min<float>(tmp_root_32_install_state.progress, tmp_root_32_install_state.deps_ratio)); }()); }()) ), slint::cbindgen_private::LayoutItemInfo ( [&](const auto &a_0){ slint::cbindgen_private::LayoutItemInfo o{}; o.constraint = a_0; return o; }([&]{ [[maybe_unused]] auto layout_info = slint::private_api::item_layout_info(SLINT_GET_ITEM_VTABLE(RectangleVTable), const_cast<slint::cbindgen_private::Rectangle*>(&self->field_rectangle_75), slint::cbindgen_private::Orientation::Horizontal, -1, &self->globals->window().window_handle(), self->self_weak.lock()->into_dyn(), self->tree_index_of_first_child + 9 - 1);;return [&](const auto &a_0, const auto &a_1, const auto &a_2, const auto &a_3, const auto &a_4, const auto &a_5){ slint::cbindgen_private::LayoutInfo o{}; o.max = a_0; o.max_percent = a_1; o.min = a_2; o.min_percent = a_3; o.preferred = a_4; o.stretch = a_5; return o; }(layout_info.max, layout_info.max_percent, layout_info.min, layout_info.min_percent, layout_info.preferred, [&]{ [[maybe_unused]] auto tmp_root_32_install_state = slint::private_api::optional_or_default(slint::private_api::optional_transform(self->parent.lock(), [&](auto&&x) { return x->field_root_32_install_state.get(); }));;return std::max<float>(0.0001, std::max<float>(0, (tmp_root_32_install_state.progress -(float) tmp_root_32_install_state.deps_ratio))); }()); }()) ), slint::cbindgen_private::LayoutItemInfo ( [&](const auto &a_0){ slint::cbindgen_private::LayoutItemInfo o{}; o.constraint = a_0; return o; }([&]{ [[maybe_unused]] auto layout_info = slint::private_api::item_layout_info(SLINT_GET_ITEM_VTABLE(RectangleVTable), const_cast<slint::cbindgen_private::Rectangle*>(&self->field_rectangle_76), slint::cbindgen_private::Orientation::Horizontal, -1, &self->globals->window().window_handle(), self->self_weak.lock()->into_dyn(), self->tree_index_of_first_child + 10 - 1);;return [&](const auto &a_0, const auto &a_1, const auto &a_2, const auto &a_3, const auto &a_4, const auto &a_5){ slint::cbindgen_private::LayoutInfo o{}; o.max = a_0; o.max_percent = a_1; o.min = a_2; o.min_percent = a_3; o.preferred = a_4; o.stretch = a_5; return o; }(layout_info.max, layout_info.max_percent, layout_info.min, layout_info.min_percent, layout_info.preferred, [&]{ [[maybe_unused]] auto tmp_root_32_install_state = slint::private_api::optional_or_default(slint::private_api::optional_transform(self->parent.lock(), [&](auto&&x) { return x->field_root_32_install_state.get(); }));;return std::max<float>(0.0001, ((1 -(float) std::min<float>(tmp_root_32_install_state.progress, tmp_root_32_install_state.deps_ratio)) -(float) std::max<float>(0, (tmp_root_32_install_state.progress -(float) tmp_root_32_install_state.deps_ratio)))); }()); }()) ) }.data(), 3), [&](const auto &a_0, const auto &a_1){ slint::cbindgen_private::Padding o{}; o.begin = a_0; o.end = a_1; return o; }(0, 0), self->field_rectangle_65_rectangle_71_width.get(), 0),slint::private_api::make_slice<int>(std::array<int, 0>{  }.data(), 0));
                        });
    self->field_rectangle_65_empty_73_layoutinfo_h.set_binding([this]() {
                            [[maybe_unused]] auto self = this;
                            return slint::private_api::box_layout_info(slint::private_api::make_slice<slint::cbindgen_private::LayoutItemInfo>(std::array<slint::cbindgen_private::LayoutItemInfo, 3>{ slint::cbindgen_private::LayoutItemInfo ( [&](const auto &a_0){ slint::cbindgen_private::LayoutItemInfo o{}; o.constraint = a_0; return o; }([&]{ [[maybe_unused]] auto layout_info = slint::private_api::item_layout_info(SLINT_GET_ITEM_VTABLE(RectangleVTable), const_cast<slint::cbindgen_private::Rectangle*>(&self->field_rectangle_74), slint::cbindgen_private::Orientation::Horizontal, -1, &self->globals->window().window_handle(), self->self_weak.lock()->into_dyn(), self->tree_index_of_first_child + 8 - 1);;return [&](const auto &a_0, const auto &a_1, const auto &a_2, const auto &a_3, const auto &a_4, const auto &a_5){ slint::cbindgen_private::LayoutInfo o{}; o.max = a_0; o.max_percent = a_1; o.min = a_2; o.min_percent = a_3; o.preferred = a_4; o.stretch = a_5; return o; }(layout_info.max, layout_info.max_percent, layout_info.min, layout_info.min_percent, layout_info.preferred, [&]{ [[maybe_unused]] auto tmp_root_32_install_state = slint::private_api::optional_or_default(slint::private_api::optional_transform(self->parent.lock(), [&](auto&&x) { return x->field_root_32_install_state.get(); }));;return std::max<float>(0.0001, std::min<float>(tmp_root_32_install_state.progress, tmp_root_32_install_state.deps_ratio)); }()); }()) ), slint::cbindgen_private::LayoutItemInfo ( [&](const auto &a_0){ slint::cbindgen_private::LayoutItemInfo o{}; o.constraint = a_0; return o; }([&]{ [[maybe_unused]] auto layout_info = slint::private_api::item_layout_info(SLINT_GET_ITEM_VTABLE(RectangleVTable), const_cast<slint::cbindgen_private::Rectangle*>(&self->field_rectangle_75), slint::cbindgen_private::Orientation::Horizontal, -1, &self->globals->window().window_handle(), self->self_weak.lock()->into_dyn(), self->tree_index_of_first_child + 9 - 1);;return [&](const auto &a_0, const auto &a_1, const auto &a_2, const auto &a_3, const auto &a_4, const auto &a_5){ slint::cbindgen_private::LayoutInfo o{}; o.max = a_0; o.max_percent = a_1; o.min = a_2; o.min_percent = a_3; o.preferred = a_4; o.stretch = a_5; return o; }(layout_info.max, layout_info.max_percent, layout_info.min, layout_info.min_percent, layout_info.preferred, [&]{ [[maybe_unused]] auto tmp_root_32_install_state = slint::private_api::optional_or_default(slint::private_api::optional_transform(self->parent.lock(), [&](auto&&x) { return x->field_root_32_install_state.get(); }));;return std::max<float>(0.0001, std::max<float>(0, (tmp_root_32_install_state.progress -(float) tmp_root_32_install_state.deps_ratio))); }()); }()) ), slint::cbindgen_private::LayoutItemInfo ( [&](const auto &a_0){ slint::cbindgen_private::LayoutItemInfo o{}; o.constraint = a_0; return o; }([&]{ [[maybe_unused]] auto layout_info = slint::private_api::item_layout_info(SLINT_GET_ITEM_VTABLE(RectangleVTable), const_cast<slint::cbindgen_private::Rectangle*>(&self->field_rectangle_76), slint::cbindgen_private::Orientation::Horizontal, -1, &self->globals->window().window_handle(), self->self_weak.lock()->into_dyn(), self->tree_index_of_first_child + 10 - 1);;return [&](const auto &a_0, const auto &a_1, const auto &a_2, const auto &a_3, const auto &a_4, const auto &a_5){ slint::cbindgen_private::LayoutInfo o{}; o.max = a_0; o.max_percent = a_1; o.min = a_2; o.min_percent = a_3; o.preferred = a_4; o.stretch = a_5; return o; }(layout_info.max, layout_info.max_percent, layout_info.min, layout_info.min_percent, layout_info.preferred, [&]{ [[maybe_unused]] auto tmp_root_32_install_state = slint::private_api::optional_or_default(slint::private_api::optional_transform(self->parent.lock(), [&](auto&&x) { return x->field_root_32_install_state.get(); }));;return std::max<float>(0.0001, ((1 -(float) std::min<float>(tmp_root_32_install_state.progress, tmp_root_32_install_state.deps_ratio)) -(float) std::max<float>(0, (tmp_root_32_install_state.progress -(float) tmp_root_32_install_state.deps_ratio)))); }()); }()) ) }.data(), 3),0,[&](const auto &a_0, const auto &a_1){ slint::cbindgen_private::Padding o{}; o.begin = a_0; o.end = a_1; return o; }(0, 0),slint::cbindgen_private::LayoutAlignment::Stretch);
                        });
    self->field_rectangle_65_empty_73_layoutinfo_v.set_binding([this]() {
                            [[maybe_unused]] auto self = this;
                            return slint::private_api::box_layout_info_ortho(slint::private_api::make_slice<slint::cbindgen_private::LayoutItemInfo>(std::array<slint::cbindgen_private::LayoutItemInfo, 3>{ slint::cbindgen_private::LayoutItemInfo ( [&](const auto &a_0){ slint::cbindgen_private::LayoutItemInfo o{}; o.constraint = a_0; return o; }(slint::private_api::item_layout_info(SLINT_GET_ITEM_VTABLE(RectangleVTable), const_cast<slint::cbindgen_private::Rectangle*>(&self->field_rectangle_74), slint::cbindgen_private::Orientation::Vertical, -1, &self->globals->window().window_handle(), self->self_weak.lock()->into_dyn(), self->tree_index_of_first_child + 8 - 1)) ), slint::cbindgen_private::LayoutItemInfo ( [&](const auto &a_0){ slint::cbindgen_private::LayoutItemInfo o{}; o.constraint = a_0; return o; }(slint::private_api::item_layout_info(SLINT_GET_ITEM_VTABLE(RectangleVTable), const_cast<slint::cbindgen_private::Rectangle*>(&self->field_rectangle_75), slint::cbindgen_private::Orientation::Vertical, -1, &self->globals->window().window_handle(), self->self_weak.lock()->into_dyn(), self->tree_index_of_first_child + 9 - 1)) ), slint::cbindgen_private::LayoutItemInfo ( [&](const auto &a_0){ slint::cbindgen_private::LayoutItemInfo o{}; o.constraint = a_0; return o; }(slint::private_api::item_layout_info(SLINT_GET_ITEM_VTABLE(RectangleVTable), const_cast<slint::cbindgen_private::Rectangle*>(&self->field_rectangle_76), slint::cbindgen_private::Orientation::Vertical, -1, &self->globals->window().window_handle(), self->self_weak.lock()->into_dyn(), self->tree_index_of_first_child + 10 - 1)) ) }.data(), 3),[&](const auto &a_0, const auto &a_1){ slint::cbindgen_private::Padding o{}; o.begin = a_0; o.end = a_1; return o; }(0, 0));
                        });
    self->field_rectangle_65_rectangle_71_width.set_binding([this]() {
                            [[maybe_unused]] auto self = this;
                            return self->field_rectangle_65_empty_70_layout_cache.get()[1];
                        });
    self->field_rectangle_65_rectangle_77_layoutinfo_h.set_binding([this]() {
                            [[maybe_unused]] auto self = this;
                            return ([&](const auto &a_0, const auto &a_1, const auto &a_2, const auto &a_3, const auto &a_4, const auto &a_5){ slint::cbindgen_private::LayoutInfo o{}; o.max = a_0; o.max_percent = a_1; o.min = a_2; o.min_percent = a_3; o.preferred = a_4; o.stretch = a_5; return o; }(+3.4028234663852886e38, 100, 0, 0, 0, 1) + slint::private_api::item_layout_info(SLINT_GET_ITEM_VTABLE(SimpleTextVTable), const_cast<slint::cbindgen_private::SimpleText*>(&self->field_text_79), slint::cbindgen_private::Orientation::Horizontal, -1, &self->globals->window().window_handle(), self->self_weak.lock()->into_dyn(), self->tree_index_of_first_child + 12 - 1));
                        });
    self->field_rectangle_65_rectangle_77_layoutinfo_v.set_binding([this]() {
                            [[maybe_unused]] auto self = this;
                            return ([&](const auto &a_0, const auto &a_1, const auto &a_2, const auto &a_3, const auto &a_4, const auto &a_5){ slint::cbindgen_private::LayoutInfo o{}; o.max = a_0; o.max_percent = a_1; o.min = a_2; o.min_percent = a_3; o.preferred = a_4; o.stretch = a_5; return o; }(+3.4028234663852886e38, 100, 0, 0, 0, 1) + slint::private_api::item_layout_info(SLINT_GET_ITEM_VTABLE(SimpleTextVTable), const_cast<slint::cbindgen_private::SimpleText*>(&self->field_text_79), slint::cbindgen_private::Orientation::Vertical, -1, &self->globals->window().window_handle(), self->self_weak.lock()->into_dyn(), self->tree_index_of_first_child + 12 - 1));
                        });
    self->field_rectangle_65_text_79_min_height.set_binding([this]() {
                            [[maybe_unused]] auto self = this;
                            return slint::private_api::item_layout_info(SLINT_GET_ITEM_VTABLE(SimpleTextVTable), const_cast<slint::cbindgen_private::SimpleText*>(&self->field_text_79), slint::cbindgen_private::Orientation::Vertical, -1, &self->globals->window().window_handle(), self->self_weak.lock()->into_dyn(), self->tree_index_of_first_child + 12 - 1).min;
                        });
    self->field_rectangle_65_text_79_min_width.set_binding([this]() {
                            [[maybe_unused]] auto self = this;
                            return slint::private_api::item_layout_info(SLINT_GET_ITEM_VTABLE(SimpleTextVTable), const_cast<slint::cbindgen_private::SimpleText*>(&self->field_text_79), slint::cbindgen_private::Orientation::Horizontal, -1, &self->globals->window().window_handle(), self->self_weak.lock()->into_dyn(), self->tree_index_of_first_child + 12 - 1).min;
                        });
    self->field_rectangle_65_text_79_preferred_height.set_binding([this]() {
                            [[maybe_unused]] auto self = this;
                            return slint::private_api::item_layout_info(SLINT_GET_ITEM_VTABLE(SimpleTextVTable), const_cast<slint::cbindgen_private::SimpleText*>(&self->field_text_79), slint::cbindgen_private::Orientation::Vertical, -1, &self->globals->window().window_handle(), self->self_weak.lock()->into_dyn(), self->tree_index_of_first_child + 12 - 1).preferred;
                        });
    self->field_rectangle_65_text_79_preferred_width.set_binding([this]() {
                            [[maybe_unused]] auto self = this;
                            return slint::private_api::item_layout_info(SLINT_GET_ITEM_VTABLE(SimpleTextVTable), const_cast<slint::cbindgen_private::SimpleText*>(&self->field_text_79), slint::cbindgen_private::Orientation::Horizontal, -1, &self->globals->window().window_handle(), self->self_weak.lock()->into_dyn(), self->tree_index_of_first_child + 12 - 1).preferred;
                        });
    self->field_text_68.color.set_binding([this]() {
                            [[maybe_unused]] auto self = this;
                            return [&]{ [[maybe_unused]] auto tmp_root_32_install_state = slint::private_api::optional_or_default(slint::private_api::optional_transform(self->parent.lock(), [&](auto&&x) { return x->field_root_32_install_state.get(); }));;return slint::Brush((tmp_root_32_install_state.finished && (! tmp_root_32_install_state.success) ? slint::Color::from_argb_encoded(+4.29415108e9) : slint::Color::from_argb_encoded(+4.291679988e9))); }();
                        });
    self->field_text_68.font_size.set(15);
    self->field_text_68.font_weight.set(static_cast<int>(700));
    self->field_text_68.height.set_binding([this]() {
                            [[maybe_unused]] auto self = this;
                            return self->field_rectangle_65_empty_66_layout_cache.get()[1];
                        });
    self->field_text_68.text.set_binding([this]() {
                            [[maybe_unused]] auto self = this;
                            return [&]{ [[maybe_unused]] auto tmp_root_32_install_state = slint::private_api::optional_or_default(slint::private_api::optional_transform(self->parent.lock(), [&](auto&&x) { return x->field_root_32_install_state.get(); }));;return (! tmp_root_32_install_state.finished ? (tmp_root_32_install_state.is_uninstalling ? slint::SharedString(u8"Uninstalling\U00002026") : (tmp_root_32_install_state.progress >= 0.98 ? slint::SharedString(u8"Finishing up\U00002026") : slint::SharedString(u8"Installing\U00002026"))) : (tmp_root_32_install_state.success ? (tmp_root_32_install_state.is_uninstalling ? slint::SharedString(u8"Uninstalled successfully") : slint::SharedString(u8"Installed successfully")) : (tmp_root_32_install_state.is_uninstalling ? slint::SharedString(u8"Uninstallation failed") : slint::SharedString(u8"Installation failed")))); }();
                        });
    self->field_text_68.vertical_alignment.set(slint::cbindgen_private::TextVerticalAlignment::Center);
    self->field_text_68.width.set_binding([this]() {
                            [[maybe_unused]] auto self = this;
                            return self->field_rectangle_65_empty_67_layout_cache.get()[1];
                        });
    self->field_text_69.color.set(slint::Brush(slint::Color::from_argb_encoded(+4.2865471e9)));
    self->field_text_69.font_size.set(13);
    self->field_text_69.height.set_binding([this]() {
                            [[maybe_unused]] auto self = this;
                            return self->field_rectangle_65_empty_66_layout_cache.get()[1];
                        });
    self->field_text_69.text.set_binding([this]() {
                            [[maybe_unused]] auto self = this;
                            return (slint::SharedString::from_number(std::round((slint::private_api::optional_or_default(slint::private_api::optional_transform(self->parent.lock(), [&](auto&&x) { return x->field_root_32_install_state.get(); })).progress * 100))) + slint::SharedString(u8"%"));
                        });
    self->field_text_69.vertical_alignment.set(slint::cbindgen_private::TextVerticalAlignment::Center);
    self->field_text_69.width.set_binding([this]() {
                            [[maybe_unused]] auto self = this;
                            return self->field_rectangle_65_empty_67_layout_cache.get()[3];
                        });
    self->field_rectangle_71.background.set(slint::Brush(slint::Color::from_argb_encoded(+4.28273033e9)));
    self->field_rectangle_71.border_radius.set(5);
    self->field__clip_72.border_bottom_left_radius.set(5);
    self->field__clip_72.border_bottom_right_radius.set(5);
    self->field__clip_72.border_top_left_radius.set(5);
    self->field__clip_72.border_top_right_radius.set(5);
    self->field__clip_72.clip.set(true);
    self->field_rectangle_74.background.set(slint::Brush(slint::Color::from_argb_encoded(+4.287214842e9)));
    self->field_rectangle_75.background.set(slint::Brush(slint::Color::from_argb_encoded(+4.291536631e9)));
    self->field_rectangle_76.background.set(slint::Brush(slint::Color::from_argb_encoded(+4.285296774e9)));
    self->field_rectangle_77.background.set_binding([this]() {
                            [[maybe_unused]] auto self = this;
                            return slint::Brush((self->field_console_ta_78.has_hover.get() ? slint::Color::from_argb_encoded(+4.28273033e9) : slint::Color::from_argb_encoded(+4.281414212e9)));
                        });
    self->field_rectangle_77.border_color.set(slint::Brush(slint::Color::from_argb_encoded(+4.283980656e9)));
    self->field_rectangle_77.border_radius.set(8);
    self->field_rectangle_77.border_width.set(1);
    self->field_console_ta_78.clicked.set_handler(
                [this]() {
                    [[maybe_unused]] auto self = this;
                    slint::private_api::optional_then(self->parent.lock(), [&](auto&&x) { x->field_root_32_show_console.set((! slint::private_api::optional_or_default(slint::private_api::optional_transform(self->parent.lock(), [&](auto&&x) { return x->field_root_32_show_console.get(); })))); });
                });
    self->field_console_ta_78.enabled.set(true);
    self->field_text_79.color.set(slint::Brush(slint::Color::from_argb_encoded(+4.291679988e9)));
    self->field_text_79.font_size.set(12);
    self->field_text_79.font_weight.set(static_cast<int>(700));
    self->field_text_79.height.set_binding([this]() {
                            [[maybe_unused]] auto self = this;
                            return std::max<float>(self->field_rectangle_65_text_79_preferred_height.get(), self->field_rectangle_65_text_79_min_height.get());
                        });
    self->field_text_79.horizontal_alignment.set(slint::cbindgen_private::TextHorizontalAlignment::Center);
    self->field_text_79.text.set(slint::SharedString(u8"Console"));
    self->field_text_79.vertical_alignment.set(slint::cbindgen_private::TextVerticalAlignment::Center);
    self->field_text_79.width.set_binding([this]() {
                            [[maybe_unused]] auto self = this;
                            return std::max<float>(self->field_rectangle_65_text_79_preferred_width.get(), self->field_rectangle_65_text_79_min_width.get());
                        });
    self->field_rectangle_65.background.set_constant();
    self->field_rectangle_65.border_color.set_constant();
    self->field_rectangle_65.border_radius.set_constant();
    self->field_rectangle_65.border_width.set_constant();
    self->field_text_68.font_size.set_constant();
    self->field_text_68.font_weight.set_constant();
    self->field_text_68.horizontal_alignment.set_constant();
    self->field_text_68.vertical_alignment.set_constant();
    self->field_text_69.color.set_constant();
    self->field_text_69.font_size.set_constant();
    self->field_text_69.font_weight.set_constant();
    self->field_text_69.horizontal_alignment.set_constant();
    self->field_text_69.vertical_alignment.set_constant();
    self->field_rectangle_71.background.set_constant();
    self->field_rectangle_71.border_color.set_constant();
    self->field_rectangle_71.border_radius.set_constant();
    self->field_rectangle_71.border_width.set_constant();
    self->field__clip_72.border_bottom_left_radius.set_constant();
    self->field__clip_72.border_bottom_right_radius.set_constant();
    self->field__clip_72.border_top_left_radius.set_constant();
    self->field__clip_72.border_top_right_radius.set_constant();
    self->field__clip_72.border_width.set_constant();
    self->field_rectangle_74.background.set_constant();
    self->field_rectangle_75.background.set_constant();
    self->field_rectangle_76.background.set_constant();
    self->field_rectangle_77.border_color.set_constant();
    self->field_rectangle_77.border_radius.set_constant();
    self->field_rectangle_77.border_width.set_constant();
    self->field_console_ta_78.enabled.set_constant();
    self->field_console_ta_78.mouse_cursor.set_constant();
    self->field_text_79.color.set_constant();
    self->field_text_79.font_size.set_constant();
    self->field_text_79.font_weight.set_constant();
    self->field_text_79.horizontal_alignment.set_constant();
    self->field_text_79.text.set_constant();
    self->field_text_79.vertical_alignment.set_constant();
}

auto Component_rectangle_65::user_init () -> void{
    [[maybe_unused]] auto self = this;
}

auto Component_rectangle_65::layout_info (slint::cbindgen_private::Orientation o) const -> slint::cbindgen_private::LayoutInfo{
    [[maybe_unused]] auto self = this;
    return o == slint::cbindgen_private::Orientation::Horizontal ? ([&](const auto &a_0, const auto &a_1, const auto &a_2, const auto &a_3, const auto &a_4, const auto &a_5){ slint::cbindgen_private::LayoutInfo o{}; o.max = a_0; o.max_percent = a_1; o.min = a_2; o.min_percent = a_3; o.preferred = a_4; o.stretch = a_5; return o; }(+3.4028234663852886e38, 100, 0, 0, 0, 1) + self->field_rectangle_65_empty_66_layoutinfo_h.get()) : ([&](const auto &a_0, const auto &a_1, const auto &a_2, const auto &a_3, const auto &a_4, const auto &a_5){ slint::cbindgen_private::LayoutInfo o{}; o.max = a_0; o.max_percent = a_1; o.min = a_2; o.min_percent = a_3; o.preferred = a_4; o.stretch = a_5; return o; }(+3.4028234663852886e38, 100, 0, 0, 0, 1) + self->field_rectangle_65_empty_66_layoutinfo_v.get());
}

auto Component_rectangle_65::item_geometry (uint32_t index) const -> slint::cbindgen_private::Rect{
    [[maybe_unused]] auto self = this;
    switch (index) {
        case 0: return slint::private_api::convert_anonymous_rect(std::make_tuple(float(slint::private_api::optional_or_default(slint::private_api::optional_transform(self->parent.lock(), [&](auto&&x) { return slint::private_api::layout_cache_access(x->field_root_32_empty_47_layout_cache.get(), 3, 0, 2); }))), float(((slint::private_api::optional_or_default(slint::private_api::optional_transform(self->parent.lock(), [&](auto&&x) { return x->field_flickable_45.viewport_width.get(); })) -(float) 64) -(float) 64)), float(64), float(slint::private_api::optional_or_default(slint::private_api::optional_transform(self->parent.lock(), [&](auto&&x) { return slint::private_api::layout_cache_access(x->field_root_32_empty_47_layout_cache.get(), 2, 0, 2); })))));
        case 1: return slint::private_api::convert_anonymous_rect(std::make_tuple(float(self->field_rectangle_65_empty_66_layout_cache.get()[1]), float(((((slint::private_api::optional_or_default(slint::private_api::optional_transform(self->parent.lock(), [&](auto&&x) { return x->field_flickable_45.viewport_width.get(); })) -(float) 64) -(float) 64) -(float) 22) -(float) 22)), float(22), float(self->field_rectangle_65_empty_66_layout_cache.get()[0])));
        case 2: return slint::private_api::convert_anonymous_rect(std::make_tuple(float(self->field_rectangle_65_empty_66_layout_cache.get()[3]), float(((((slint::private_api::optional_or_default(slint::private_api::optional_transform(self->parent.lock(), [&](auto&&x) { return x->field_flickable_45.viewport_width.get(); })) -(float) 64) -(float) 64) -(float) 22) -(float) 22)), float(22), float(self->field_rectangle_65_empty_66_layout_cache.get()[2])));
        case 3: return slint::private_api::convert_anonymous_rect(std::make_tuple(float(self->field_rectangle_65_empty_66_layout_cache.get()[1]), float(self->field_rectangle_65_empty_67_layout_cache.get()[1]), float(self->field_rectangle_65_empty_67_layout_cache.get()[0]), float(0)));
        case 4: return slint::private_api::convert_anonymous_rect(std::make_tuple(float(self->field_rectangle_65_empty_66_layout_cache.get()[1]), float(self->field_rectangle_65_empty_67_layout_cache.get()[3]), float(self->field_rectangle_65_empty_67_layout_cache.get()[2]), float(0)));
        case 5: return slint::private_api::convert_anonymous_rect(std::make_tuple(float(10), float(self->field_rectangle_65_empty_70_layout_cache.get()[1]), float(self->field_rectangle_65_empty_70_layout_cache.get()[0]), float(0)));
        case 6: return slint::private_api::convert_anonymous_rect(std::make_tuple(float(34), float(100), float(self->field_rectangle_65_empty_70_layout_cache.get()[2]), float(0)));
        case 7: return slint::private_api::convert_anonymous_rect(std::make_tuple(float(10), float(self->field_rectangle_65_empty_70_layout_cache.get()[1]), float(0), float(0)));
        case 8: return slint::private_api::convert_anonymous_rect(std::make_tuple(float(10), float(self->field_rectangle_65_empty_73_layout_cache.get()[1]), float(self->field_rectangle_65_empty_73_layout_cache.get()[0]), float(0)));
        case 9: return slint::private_api::convert_anonymous_rect(std::make_tuple(float(10), float(self->field_rectangle_65_empty_73_layout_cache.get()[3]), float(self->field_rectangle_65_empty_73_layout_cache.get()[2]), float(0)));
        case 10: return slint::private_api::convert_anonymous_rect(std::make_tuple(float(10), float(self->field_rectangle_65_empty_73_layout_cache.get()[5]), float(self->field_rectangle_65_empty_73_layout_cache.get()[4]), float(0)));
        case 11: return slint::private_api::convert_anonymous_rect(std::make_tuple(float(34), float(100), float(0), float(0)));
        case 12: return slint::private_api::convert_anonymous_rect(std::make_tuple(float(self->field_text_79.height.get()), float(self->field_text_79.width.get()), float(((100 -(float) self->field_text_79.width.get()) /(float) 2)), float(((34 -(float) self->field_text_79.height.get()) /(float) 2))));
    }
    return {};
}

auto Component_rectangle_65::accessible_role (uint32_t index) const -> slint::cbindgen_private::AccessibleRole{
    [[maybe_unused]] auto self = this;
    switch (index) {
        case 3: return slint::cbindgen_private::AccessibleRole::Text;
        case 4: return slint::cbindgen_private::AccessibleRole::Text;
        case 12: return slint::cbindgen_private::AccessibleRole::Text;
    }
    return {};
}

auto Component_rectangle_65::accessible_string_property (uint32_t index, slint::cbindgen_private::AccessibleStringProperty what) const -> std::optional<slint::SharedString>{
    [[maybe_unused]] auto self = this;
    switch ((index << 8) | uintptr_t(what)) {
        case (3 << 8) | uintptr_t(slint::cbindgen_private::AccessibleStringProperty::Label): return self->field_text_68.text.get();
        case (4 << 8) | uintptr_t(slint::cbindgen_private::AccessibleStringProperty::Label): return self->field_text_69.text.get();
        case (12 << 8) | uintptr_t(slint::cbindgen_private::AccessibleStringProperty::Label): return slint::SharedString(u8"Console");
    }
    return {};
}

auto Component_rectangle_65::accessibility_action (uint32_t index, const slint::cbindgen_private::AccessibilityAction &action) const -> void{
    [[maybe_unused]] auto self = this;
    switch ((index << 8) | uintptr_t(action.tag)) {
    }
    return ;
}

auto Component_rectangle_65::supported_accessibility_actions (uint32_t index) const -> uint32_t{
    [[maybe_unused]] auto self = this;
    switch (index) {
    }
    return {};
}

auto Component_rectangle_65::element_infos (uint32_t index) const -> std::optional<slint::SharedString>{
    [[maybe_unused]] auto self = this;
    switch (index) {
    }
    return {};
}

auto Component_rectangle_65::ensure_instantiated () const -> bool{
    [[maybe_unused]] auto self = this;
    bool _changed = false;
    return _changed;
}

auto Component_rectangle_65::visit_children (slint::private_api::ItemTreeRef component, intptr_t index, slint::private_api::TraversalOrder order, slint::private_api::ItemVisitorRefMut visitor) -> uint64_t{
    static const auto dyn_visit = [] (const void *base,  [[maybe_unused]] slint::private_api::TraversalOrder order, [[maybe_unused]] slint::private_api::ItemVisitorRefMut visitor, [[maybe_unused]] uint32_t dyn_index) -> uint64_t {
        [[maybe_unused]] auto self = reinterpret_cast<const Component_rectangle_65*>(base);
        std::abort();
    };
    auto self_rc = reinterpret_cast<const Component_rectangle_65*>(component.instance)->self_weak.lock()->into_dyn();
    return slint::cbindgen_private::slint_visit_item_tree(&self_rc, get_item_tree(component) , index, order, visitor, dyn_visit);
}

auto Component_rectangle_65::get_item_ref (slint::private_api::ItemTreeRef component, uint32_t index) -> slint::private_api::ItemRef{
    return slint::private_api::get_item_ref(component, get_item_tree(component), item_array(), index);
}

auto Component_rectangle_65::get_subtree_range ([[maybe_unused]] slint::private_api::ItemTreeRef component, [[maybe_unused]] uint32_t dyn_index) -> slint::private_api::IndexRange{
        std::abort();
}

auto Component_rectangle_65::get_subtree ([[maybe_unused]] slint::private_api::ItemTreeRef component, [[maybe_unused]] uint32_t dyn_index, [[maybe_unused]] uintptr_t subtree_index, [[maybe_unused]] slint::private_api::ItemTreeWeak *result) -> void{
        std::abort();
}

auto Component_rectangle_65::get_item_tree (slint::private_api::ItemTreeRef) -> slint::cbindgen_private::Slice<slint::private_api::ItemTreeNode>{
    return item_tree();
}

auto Component_rectangle_65::parent_node ([[maybe_unused]] slint::private_api::ItemTreeRef component, [[maybe_unused]] slint::private_api::ItemWeak *result) -> void{
    auto self = reinterpret_cast<const Component_rectangle_65*>(component.instance);
    auto parent = self->parent.lock().value();
    *result = { parent->self_weak, parent->tree_index_of_first_child + 15 };
}

auto Component_rectangle_65::embed_component ([[maybe_unused]] slint::private_api::ItemTreeRef component, [[maybe_unused]] const slint::private_api::ItemTreeWeak *parent_component, [[maybe_unused]] const uint32_t parent_index) -> bool{
    return false; /* todo! */
}

auto Component_rectangle_65::subtree_index ([[maybe_unused]] slint::private_api::ItemTreeRef component) -> uintptr_t{
    return std::numeric_limits<uintptr_t>::max();
}

auto Component_rectangle_65::item_tree () -> slint::cbindgen_private::Slice<slint::private_api::ItemTreeNode>{
    static const slint::private_api::ItemTreeNode children[] {
        slint::private_api::make_item_node(2, 1, 0, 0, false), 
slint::private_api::make_item_node(2, 3, 0, 1, false), 
slint::private_api::make_item_node(2, 5, 0, 2, false), 
slint::private_api::make_item_node(0, 5, 1, 3, true), 
slint::private_api::make_item_node(0, 5, 1, 4, true), 
slint::private_api::make_item_node(1, 7, 2, 5, false), 
slint::private_api::make_item_node(2, 11, 2, 6, false), 
slint::private_api::make_item_node(3, 8, 5, 7, false), 
slint::private_api::make_item_node(0, 11, 7, 8, false), 
slint::private_api::make_item_node(0, 11, 7, 9, false), 
slint::private_api::make_item_node(0, 11, 7, 10, false), 
slint::private_api::make_item_node(0, 13, 6, 11, false), 
slint::private_api::make_item_node(0, 13, 6, 12, true) };
    return slint::private_api::make_slice(std::span(children));
}

auto Component_rectangle_65::item_array () -> const slint::private_api::ItemArray{
    static const slint::private_api::ItemArrayEntry items[] {
        { SLINT_GET_ITEM_VTABLE(BasicBorderRectangleVTable),  offsetof(Component_rectangle_65, field_rectangle_65) }, 
{ SLINT_GET_ITEM_VTABLE(EmptyVTable),  offsetof(Component_rectangle_65, field_empty_67) }, 
{ SLINT_GET_ITEM_VTABLE(EmptyVTable),  offsetof(Component_rectangle_65, field_empty_70) }, 
{ SLINT_GET_ITEM_VTABLE(SimpleTextVTable),  offsetof(Component_rectangle_65, field_text_68) }, 
{ SLINT_GET_ITEM_VTABLE(SimpleTextVTable),  offsetof(Component_rectangle_65, field_text_69) }, 
{ SLINT_GET_ITEM_VTABLE(BasicBorderRectangleVTable),  offsetof(Component_rectangle_65, field_rectangle_71) }, 
{ SLINT_GET_ITEM_VTABLE(BasicBorderRectangleVTable),  offsetof(Component_rectangle_65, field_rectangle_77) }, 
{ SLINT_GET_ITEM_VTABLE(ClipVTable),  offsetof(Component_rectangle_65, field__clip_72) }, 
{ SLINT_GET_ITEM_VTABLE(RectangleVTable),  offsetof(Component_rectangle_65, field_rectangle_74) }, 
{ SLINT_GET_ITEM_VTABLE(RectangleVTable),  offsetof(Component_rectangle_65, field_rectangle_75) }, 
{ SLINT_GET_ITEM_VTABLE(RectangleVTable),  offsetof(Component_rectangle_65, field_rectangle_76) }, 
{ SLINT_GET_ITEM_VTABLE(TouchAreaVTable),  offsetof(Component_rectangle_65, field_console_ta_78) }, 
{ SLINT_GET_ITEM_VTABLE(SimpleTextVTable),  offsetof(Component_rectangle_65, field_text_79) } };
    return slint::private_api::make_slice(std::span(items));
}

auto Component_rectangle_65::layout_info ([[maybe_unused]] slint::private_api::ItemTreeRef component, slint::cbindgen_private::Orientation o) -> slint::cbindgen_private::LayoutInfo{
    return reinterpret_cast<const Component_rectangle_65*>(component.instance)->layout_info(o);
}

auto Component_rectangle_65::ensure_instantiated ([[maybe_unused]] slint::private_api::ItemTreeRef component) -> bool{
    return reinterpret_cast<const Component_rectangle_65*>(component.instance)->ensure_instantiated();
}

auto Component_rectangle_65::item_geometry ([[maybe_unused]] slint::private_api::ItemTreeRef component, uint32_t index) -> slint::cbindgen_private::LogicalRect{
    return reinterpret_cast<const Component_rectangle_65*>(component.instance)->item_geometry(index);
}

auto Component_rectangle_65::accessible_role ([[maybe_unused]] slint::private_api::ItemTreeRef component, uint32_t index) -> slint::cbindgen_private::AccessibleRole{
    return reinterpret_cast<const Component_rectangle_65*>(component.instance)->accessible_role(index);
}

auto Component_rectangle_65::accessible_string_property ([[maybe_unused]] slint::private_api::ItemTreeRef component, uint32_t index, slint::cbindgen_private::AccessibleStringProperty what, slint::SharedString *result) -> bool{
    if (auto r = reinterpret_cast<const Component_rectangle_65*>(component.instance)->accessible_string_property(index, what)) { *result = *r; return true; } else { return false; }
}

auto Component_rectangle_65::accessibility_action ([[maybe_unused]] slint::private_api::ItemTreeRef component, uint32_t index, const slint::cbindgen_private::AccessibilityAction *action) -> void{
    reinterpret_cast<const Component_rectangle_65*>(component.instance)->accessibility_action(index, *action);
}

auto Component_rectangle_65::supported_accessibility_actions ([[maybe_unused]] slint::private_api::ItemTreeRef component, uint32_t index) -> uint32_t{
    return reinterpret_cast<const Component_rectangle_65*>(component.instance)->supported_accessibility_actions(index);
}

auto Component_rectangle_65::element_infos ([[maybe_unused]] slint::private_api::ItemTreeRef component, [[maybe_unused]] uint32_t index, [[maybe_unused]] slint::SharedString *result) -> bool{
    return false;
}

auto Component_rectangle_65::window_adapter ([[maybe_unused]] slint::private_api::ItemTreeRef component, [[maybe_unused]] bool do_create, [[maybe_unused]] slint::cbindgen_private::Option<slint::private_api::WindowAdapterRc>* result) -> void{
    *reinterpret_cast<slint::private_api::WindowAdapterRc*>(result) = reinterpret_cast<const Component_rectangle_65*>(component.instance)->globals->window().window_handle();
}

auto Component_rectangle_65::create (class DetailsView_root_32 const * parent) -> slint::ComponentHandle<Component_rectangle_65>{
    auto self_rc = vtable::VRc<slint::private_api::ItemTreeVTable, Component_rectangle_65>::make();
    auto self = const_cast<Component_rectangle_65 *>(&*self_rc);
    self->self_weak = vtable::VWeak(self_rc).into_dyn();
    slint::private_api::register_item_tree(&self_rc.into_dyn(), parent->globals->m_window);
    self->init(parent->globals, self->self_weak, 0, 1 , parent);
    return slint::ComponentHandle<Component_rectangle_65>{ self_rc };
}

Component_rectangle_65::~Component_rectangle_65 (){
    if (auto &window = globals->m_window) window->window_handle().unregister_item_tree(this, item_array());
}

auto Component_rectangle_65::init () -> void{
    user_init();
}

auto Component_rectangle_65::layout_item_info (slint::cbindgen_private::Orientation o, [[maybe_unused]] std::optional<size_t> child_index) const -> slint::cbindgen_private::LayoutItemInfo{
    return { layout_info({&static_vtable, const_cast<void *>(static_cast<const void *>(this))}, o) };
}

auto Component_rectangle_65::flexbox_layout_item_info (slint::cbindgen_private::Orientation o, [[maybe_unused]] std::optional<size_t> child_index) const -> slint::cbindgen_private::FlexboxLayoutItemInfo{
    auto base = layout_item_info(o, child_index); return { base.constraint, 0.0f, 0.0f, -1.0f, slint::cbindgen_private::FlexboxLayoutAlignSelf::Auto, 0 };
}

const slint::private_api::ItemTreeVTable Component_text_85::static_vtable = { visit_children, get_item_ref, get_subtree_range, get_subtree, get_item_tree, parent_node, embed_component, subtree_index, layout_info, ensure_instantiated, item_geometry, accessible_role, accessible_string_property, accessibility_action, supported_accessibility_actions, element_infos, window_adapter, slint::private_api::drop_in_place<Component_text_85>, slint::private_api::dealloc };

auto Component_text_85::init (const class SharedGlobals* globals,slint::cbindgen_private::ItemTreeWeak enclosing_component,uint32_t tree_index,uint32_t tree_index_of_first_child,class DetailsView_root_32 const *parent) -> void{
    auto self = this;
    self->self_weak = enclosing_component;
    self->globals = globals;
    this->tree_index_of_first_child = tree_index_of_first_child;
    self->tree_index = tree_index;
    self->parent = vtable::VRcMapped<slint::private_api::ItemTreeVTable, const DetailsView_root_32>(parent->self_weak.lock().value(), parent);
    self->field_text_85.color.set_binding([this]() {
                            [[maybe_unused]] auto self = this;
                            return slint::Brush(slint::private_api::optional_or_default(slint::private_api::optional_transform(self->parent.lock(), [&](auto&&x) { return x->field_root_32_accent.get(); })));
                        });
    self->field_text_85.font_size.set(26);
    self->field_text_85.font_weight.set(static_cast<int>(700));
    self->field_text_85.height.set_binding([this]() {
                            [[maybe_unused]] auto self = this;
                            return slint::private_api::optional_or_default(slint::private_api::optional_transform(self->parent.lock(), [&](auto&&x) { return x->field_root_32_empty_82_layout_cache.get()[1]; }));
                        });
    self->field_text_85.text.set_binding([this]() {
                            [[maybe_unused]] auto self = this;
                            return slint::private_api::optional_or_default(slint::private_api::optional_transform(self->parent.lock(), [&](auto&&x) { return x->field_root_32_details.get(); })).download_size_str;
                        });
    self->field_text_85.vertical_alignment.set(slint::cbindgen_private::TextVerticalAlignment::Center);
    self->field_text_85.width.set_binding([this]() {
                            [[maybe_unused]] auto self = this;
                            return slint::private_api::optional_or_default(slint::private_api::optional_transform(self->parent.lock(), [&](auto&&x) { return slint::private_api::layout_cache_access(x->field_root_32_empty_83_layout_cache.get(), 3, 0, 2); }));
                        });
    self->field_text_85.font_size.set_constant();
    self->field_text_85.font_weight.set_constant();
    self->field_text_85.horizontal_alignment.set_constant();
    self->field_text_85.vertical_alignment.set_constant();
}

auto Component_text_85::user_init () -> void{
    [[maybe_unused]] auto self = this;
}

auto Component_text_85::layout_info (slint::cbindgen_private::Orientation o) const -> slint::cbindgen_private::LayoutInfo{
    [[maybe_unused]] auto self = this;
    return o == slint::cbindgen_private::Orientation::Horizontal ? slint::private_api::item_layout_info(SLINT_GET_ITEM_VTABLE(SimpleTextVTable), const_cast<slint::cbindgen_private::SimpleText*>(&self->field_text_85), slint::cbindgen_private::Orientation::Horizontal, -1, &self->globals->window().window_handle(), self->self_weak.lock()->into_dyn(), self->tree_index) : slint::private_api::item_layout_info(SLINT_GET_ITEM_VTABLE(SimpleTextVTable), const_cast<slint::cbindgen_private::SimpleText*>(&self->field_text_85), slint::cbindgen_private::Orientation::Vertical, -1, &self->globals->window().window_handle(), self->self_weak.lock()->into_dyn(), self->tree_index);
}

auto Component_text_85::item_geometry (uint32_t index) const -> slint::cbindgen_private::Rect{
    [[maybe_unused]] auto self = this;
    switch (index) {
        case 0: return slint::private_api::convert_anonymous_rect(std::make_tuple(float(slint::private_api::optional_or_default(slint::private_api::optional_transform(self->parent.lock(), [&](auto&&x) { return x->field_root_32_empty_82_layout_cache.get()[1]; }))), float(slint::private_api::optional_or_default(slint::private_api::optional_transform(self->parent.lock(), [&](auto&&x) { return slint::private_api::layout_cache_access(x->field_root_32_empty_83_layout_cache.get(), 3, 0, 2); }))), float(slint::private_api::optional_or_default(slint::private_api::optional_transform(self->parent.lock(), [&](auto&&x) { return slint::private_api::layout_cache_access(x->field_root_32_empty_83_layout_cache.get(), 2, 0, 2); }))), float(0)));
    }
    return {};
}

auto Component_text_85::accessible_role (uint32_t index) const -> slint::cbindgen_private::AccessibleRole{
    [[maybe_unused]] auto self = this;
    switch (index) {
        case 0: return slint::cbindgen_private::AccessibleRole::Text;
    }
    return {};
}

auto Component_text_85::accessible_string_property (uint32_t index, slint::cbindgen_private::AccessibleStringProperty what) const -> std::optional<slint::SharedString>{
    [[maybe_unused]] auto self = this;
    switch ((index << 8) | uintptr_t(what)) {
        case (0 << 8) | uintptr_t(slint::cbindgen_private::AccessibleStringProperty::Label): return slint::private_api::optional_or_default(slint::private_api::optional_transform(self->parent.lock(), [&](auto&&x) { return x->field_root_32_details.get(); })).download_size_str;
    }
    return {};
}

auto Component_text_85::accessibility_action (uint32_t index, const slint::cbindgen_private::AccessibilityAction &action) const -> void{
    [[maybe_unused]] auto self = this;
    switch ((index << 8) | uintptr_t(action.tag)) {
    }
    return ;
}

auto Component_text_85::supported_accessibility_actions (uint32_t index) const -> uint32_t{
    [[maybe_unused]] auto self = this;
    switch (index) {
    }
    return {};
}

auto Component_text_85::element_infos (uint32_t index) const -> std::optional<slint::SharedString>{
    [[maybe_unused]] auto self = this;
    switch (index) {
    }
    return {};
}

auto Component_text_85::ensure_instantiated () const -> bool{
    [[maybe_unused]] auto self = this;
    bool _changed = false;
    return _changed;
}

auto Component_text_85::visit_children (slint::private_api::ItemTreeRef component, intptr_t index, slint::private_api::TraversalOrder order, slint::private_api::ItemVisitorRefMut visitor) -> uint64_t{
    static const auto dyn_visit = [] (const void *base,  [[maybe_unused]] slint::private_api::TraversalOrder order, [[maybe_unused]] slint::private_api::ItemVisitorRefMut visitor, [[maybe_unused]] uint32_t dyn_index) -> uint64_t {
        [[maybe_unused]] auto self = reinterpret_cast<const Component_text_85*>(base);
        std::abort();
    };
    auto self_rc = reinterpret_cast<const Component_text_85*>(component.instance)->self_weak.lock()->into_dyn();
    return slint::cbindgen_private::slint_visit_item_tree(&self_rc, get_item_tree(component) , index, order, visitor, dyn_visit);
}

auto Component_text_85::get_item_ref (slint::private_api::ItemTreeRef component, uint32_t index) -> slint::private_api::ItemRef{
    return slint::private_api::get_item_ref(component, get_item_tree(component), item_array(), index);
}

auto Component_text_85::get_subtree_range ([[maybe_unused]] slint::private_api::ItemTreeRef component, [[maybe_unused]] uint32_t dyn_index) -> slint::private_api::IndexRange{
        std::abort();
}

auto Component_text_85::get_subtree ([[maybe_unused]] slint::private_api::ItemTreeRef component, [[maybe_unused]] uint32_t dyn_index, [[maybe_unused]] uintptr_t subtree_index, [[maybe_unused]] slint::private_api::ItemTreeWeak *result) -> void{
        std::abort();
}

auto Component_text_85::get_item_tree (slint::private_api::ItemTreeRef) -> slint::cbindgen_private::Slice<slint::private_api::ItemTreeNode>{
    return item_tree();
}

auto Component_text_85::parent_node ([[maybe_unused]] slint::private_api::ItemTreeRef component, [[maybe_unused]] slint::private_api::ItemWeak *result) -> void{
    auto self = reinterpret_cast<const Component_text_85*>(component.instance);
    auto parent = self->parent.lock().value();
    *result = { parent->self_weak, parent->tree_index_of_first_child + 38 };
}

auto Component_text_85::embed_component ([[maybe_unused]] slint::private_api::ItemTreeRef component, [[maybe_unused]] const slint::private_api::ItemTreeWeak *parent_component, [[maybe_unused]] const uint32_t parent_index) -> bool{
    return false; /* todo! */
}

auto Component_text_85::subtree_index ([[maybe_unused]] slint::private_api::ItemTreeRef component) -> uintptr_t{
    return std::numeric_limits<uintptr_t>::max();
}

auto Component_text_85::item_tree () -> slint::cbindgen_private::Slice<slint::private_api::ItemTreeNode>{
    static const slint::private_api::ItemTreeNode children[] {
        slint::private_api::make_item_node(0, 1, 0, 0, true) };
    return slint::private_api::make_slice(std::span(children));
}

auto Component_text_85::item_array () -> const slint::private_api::ItemArray{
    static const slint::private_api::ItemArrayEntry items[] {
        { SLINT_GET_ITEM_VTABLE(SimpleTextVTable),  offsetof(Component_text_85, field_text_85) } };
    return slint::private_api::make_slice(std::span(items));
}

auto Component_text_85::layout_info ([[maybe_unused]] slint::private_api::ItemTreeRef component, slint::cbindgen_private::Orientation o) -> slint::cbindgen_private::LayoutInfo{
    return reinterpret_cast<const Component_text_85*>(component.instance)->layout_info(o);
}

auto Component_text_85::ensure_instantiated ([[maybe_unused]] slint::private_api::ItemTreeRef component) -> bool{
    return reinterpret_cast<const Component_text_85*>(component.instance)->ensure_instantiated();
}

auto Component_text_85::item_geometry ([[maybe_unused]] slint::private_api::ItemTreeRef component, uint32_t index) -> slint::cbindgen_private::LogicalRect{
    return reinterpret_cast<const Component_text_85*>(component.instance)->item_geometry(index);
}

auto Component_text_85::accessible_role ([[maybe_unused]] slint::private_api::ItemTreeRef component, uint32_t index) -> slint::cbindgen_private::AccessibleRole{
    return reinterpret_cast<const Component_text_85*>(component.instance)->accessible_role(index);
}

auto Component_text_85::accessible_string_property ([[maybe_unused]] slint::private_api::ItemTreeRef component, uint32_t index, slint::cbindgen_private::AccessibleStringProperty what, slint::SharedString *result) -> bool{
    if (auto r = reinterpret_cast<const Component_text_85*>(component.instance)->accessible_string_property(index, what)) { *result = *r; return true; } else { return false; }
}

auto Component_text_85::accessibility_action ([[maybe_unused]] slint::private_api::ItemTreeRef component, uint32_t index, const slint::cbindgen_private::AccessibilityAction *action) -> void{
    reinterpret_cast<const Component_text_85*>(component.instance)->accessibility_action(index, *action);
}

auto Component_text_85::supported_accessibility_actions ([[maybe_unused]] slint::private_api::ItemTreeRef component, uint32_t index) -> uint32_t{
    return reinterpret_cast<const Component_text_85*>(component.instance)->supported_accessibility_actions(index);
}

auto Component_text_85::element_infos ([[maybe_unused]] slint::private_api::ItemTreeRef component, [[maybe_unused]] uint32_t index, [[maybe_unused]] slint::SharedString *result) -> bool{
    return false;
}

auto Component_text_85::window_adapter ([[maybe_unused]] slint::private_api::ItemTreeRef component, [[maybe_unused]] bool do_create, [[maybe_unused]] slint::cbindgen_private::Option<slint::private_api::WindowAdapterRc>* result) -> void{
    *reinterpret_cast<slint::private_api::WindowAdapterRc*>(result) = reinterpret_cast<const Component_text_85*>(component.instance)->globals->window().window_handle();
}

auto Component_text_85::create (class DetailsView_root_32 const * parent) -> slint::ComponentHandle<Component_text_85>{
    auto self_rc = vtable::VRc<slint::private_api::ItemTreeVTable, Component_text_85>::make();
    auto self = const_cast<Component_text_85 *>(&*self_rc);
    self->self_weak = vtable::VWeak(self_rc).into_dyn();
    slint::private_api::register_item_tree(&self_rc.into_dyn(), parent->globals->m_window);
    self->init(parent->globals, self->self_weak, 0, 1 , parent);
    return slint::ComponentHandle<Component_text_85>{ self_rc };
}

Component_text_85::~Component_text_85 (){
    if (auto &window = globals->m_window) window->window_handle().unregister_item_tree(this, item_array());
}

auto Component_text_85::init () -> void{
    user_init();
}

auto Component_text_85::layout_item_info (slint::cbindgen_private::Orientation o, [[maybe_unused]] std::optional<size_t> child_index) const -> slint::cbindgen_private::LayoutItemInfo{
    return { layout_info({&static_vtable, const_cast<void *>(static_cast<const void *>(this))}, o) };
}

auto Component_text_85::flexbox_layout_item_info (slint::cbindgen_private::Orientation o, [[maybe_unused]] std::optional<size_t> child_index) const -> slint::cbindgen_private::FlexboxLayoutItemInfo{
    auto base = layout_item_info(o, child_index); return { base.constraint, 0.0f, 0.0f, -1.0f, slint::cbindgen_private::FlexboxLayoutAlignSelf::Auto, 0 };
}

const slint::private_api::ItemTreeVTable Component_text_87::static_vtable = { visit_children, get_item_ref, get_subtree_range, get_subtree, get_item_tree, parent_node, embed_component, subtree_index, layout_info, ensure_instantiated, item_geometry, accessible_role, accessible_string_property, accessibility_action, supported_accessibility_actions, element_infos, window_adapter, slint::private_api::drop_in_place<Component_text_87>, slint::private_api::dealloc };

auto Component_text_87::init (const class SharedGlobals* globals,slint::cbindgen_private::ItemTreeWeak enclosing_component,uint32_t tree_index,uint32_t tree_index_of_first_child,class DetailsView_root_32 const *parent) -> void{
    auto self = this;
    self->self_weak = enclosing_component;
    self->globals = globals;
    this->tree_index_of_first_child = tree_index_of_first_child;
    self->tree_index = tree_index;
    self->parent = vtable::VRcMapped<slint::private_api::ItemTreeVTable, const DetailsView_root_32>(parent->self_weak.lock().value(), parent);
    self->field_text_87.color.set(slint::Brush(slint::Color::from_argb_encoded(+4.2865471e9)));
    self->field_text_87.font_size.set(13);
    self->field_text_87.height.set_binding([this]() {
                            [[maybe_unused]] auto self = this;
                            return slint::private_api::optional_or_default(slint::private_api::optional_transform(self->parent.lock(), [&](auto&&x) { return slint::private_api::layout_cache_access(x->field_root_32_empty_82_layout_cache.get(), 3, 0, 2); }));
                        });
    self->field_text_87.text.set(slint::SharedString(u8"Calculating download size\U00002026"));
    self->field_text_87.width.set_binding([this]() {
                            [[maybe_unused]] auto self = this;
                            return ((((slint::private_api::optional_or_default(slint::private_api::optional_transform(self->parent.lock(), [&](auto&&x) { return x->field_flickable_45.viewport_width.get(); })) -(float) 64) -(float) 64) -(float) 26) -(float) 26);
                        });
    self->field_text_87.color.set_constant();
    self->field_text_87.font_size.set_constant();
    self->field_text_87.font_weight.set_constant();
    self->field_text_87.horizontal_alignment.set_constant();
    self->field_text_87.text.set_constant();
    self->field_text_87.vertical_alignment.set_constant();
}

auto Component_text_87::user_init () -> void{
    [[maybe_unused]] auto self = this;
}

auto Component_text_87::layout_info (slint::cbindgen_private::Orientation o) const -> slint::cbindgen_private::LayoutInfo{
    [[maybe_unused]] auto self = this;
    return o == slint::cbindgen_private::Orientation::Horizontal ? slint::private_api::item_layout_info(SLINT_GET_ITEM_VTABLE(SimpleTextVTable), const_cast<slint::cbindgen_private::SimpleText*>(&self->field_text_87), slint::cbindgen_private::Orientation::Horizontal, -1, &self->globals->window().window_handle(), self->self_weak.lock()->into_dyn(), self->tree_index) : slint::private_api::item_layout_info(SLINT_GET_ITEM_VTABLE(SimpleTextVTable), const_cast<slint::cbindgen_private::SimpleText*>(&self->field_text_87), slint::cbindgen_private::Orientation::Vertical, -1, &self->globals->window().window_handle(), self->self_weak.lock()->into_dyn(), self->tree_index);
}

auto Component_text_87::item_geometry (uint32_t index) const -> slint::cbindgen_private::Rect{
    [[maybe_unused]] auto self = this;
    switch (index) {
        case 0: return slint::private_api::convert_anonymous_rect(std::make_tuple(float(slint::private_api::optional_or_default(slint::private_api::optional_transform(self->parent.lock(), [&](auto&&x) { return slint::private_api::layout_cache_access(x->field_root_32_empty_82_layout_cache.get(), 3, 0, 2); }))), float(((((slint::private_api::optional_or_default(slint::private_api::optional_transform(self->parent.lock(), [&](auto&&x) { return x->field_flickable_45.viewport_width.get(); })) -(float) 64) -(float) 64) -(float) 26) -(float) 26)), float(26), float(slint::private_api::optional_or_default(slint::private_api::optional_transform(self->parent.lock(), [&](auto&&x) { return slint::private_api::layout_cache_access(x->field_root_32_empty_82_layout_cache.get(), 2, 0, 2); })))));
    }
    return {};
}

auto Component_text_87::accessible_role (uint32_t index) const -> slint::cbindgen_private::AccessibleRole{
    [[maybe_unused]] auto self = this;
    switch (index) {
        case 0: return slint::cbindgen_private::AccessibleRole::Text;
    }
    return {};
}

auto Component_text_87::accessible_string_property (uint32_t index, slint::cbindgen_private::AccessibleStringProperty what) const -> std::optional<slint::SharedString>{
    [[maybe_unused]] auto self = this;
    switch ((index << 8) | uintptr_t(what)) {
        case (0 << 8) | uintptr_t(slint::cbindgen_private::AccessibleStringProperty::Label): return slint::SharedString(u8"Calculating download size\U00002026");
    }
    return {};
}

auto Component_text_87::accessibility_action (uint32_t index, const slint::cbindgen_private::AccessibilityAction &action) const -> void{
    [[maybe_unused]] auto self = this;
    switch ((index << 8) | uintptr_t(action.tag)) {
    }
    return ;
}

auto Component_text_87::supported_accessibility_actions (uint32_t index) const -> uint32_t{
    [[maybe_unused]] auto self = this;
    switch (index) {
    }
    return {};
}

auto Component_text_87::element_infos (uint32_t index) const -> std::optional<slint::SharedString>{
    [[maybe_unused]] auto self = this;
    switch (index) {
    }
    return {};
}

auto Component_text_87::ensure_instantiated () const -> bool{
    [[maybe_unused]] auto self = this;
    bool _changed = false;
    return _changed;
}

auto Component_text_87::visit_children (slint::private_api::ItemTreeRef component, intptr_t index, slint::private_api::TraversalOrder order, slint::private_api::ItemVisitorRefMut visitor) -> uint64_t{
    static const auto dyn_visit = [] (const void *base,  [[maybe_unused]] slint::private_api::TraversalOrder order, [[maybe_unused]] slint::private_api::ItemVisitorRefMut visitor, [[maybe_unused]] uint32_t dyn_index) -> uint64_t {
        [[maybe_unused]] auto self = reinterpret_cast<const Component_text_87*>(base);
        std::abort();
    };
    auto self_rc = reinterpret_cast<const Component_text_87*>(component.instance)->self_weak.lock()->into_dyn();
    return slint::cbindgen_private::slint_visit_item_tree(&self_rc, get_item_tree(component) , index, order, visitor, dyn_visit);
}

auto Component_text_87::get_item_ref (slint::private_api::ItemTreeRef component, uint32_t index) -> slint::private_api::ItemRef{
    return slint::private_api::get_item_ref(component, get_item_tree(component), item_array(), index);
}

auto Component_text_87::get_subtree_range ([[maybe_unused]] slint::private_api::ItemTreeRef component, [[maybe_unused]] uint32_t dyn_index) -> slint::private_api::IndexRange{
        std::abort();
}

auto Component_text_87::get_subtree ([[maybe_unused]] slint::private_api::ItemTreeRef component, [[maybe_unused]] uint32_t dyn_index, [[maybe_unused]] uintptr_t subtree_index, [[maybe_unused]] slint::private_api::ItemTreeWeak *result) -> void{
        std::abort();
}

auto Component_text_87::get_item_tree (slint::private_api::ItemTreeRef) -> slint::cbindgen_private::Slice<slint::private_api::ItemTreeNode>{
    return item_tree();
}

auto Component_text_87::parent_node ([[maybe_unused]] slint::private_api::ItemTreeRef component, [[maybe_unused]] slint::private_api::ItemWeak *result) -> void{
    auto self = reinterpret_cast<const Component_text_87*>(component.instance);
    auto parent = self->parent.lock().value();
    *result = { parent->self_weak, parent->tree_index_of_first_child + 35 };
}

auto Component_text_87::embed_component ([[maybe_unused]] slint::private_api::ItemTreeRef component, [[maybe_unused]] const slint::private_api::ItemTreeWeak *parent_component, [[maybe_unused]] const uint32_t parent_index) -> bool{
    return false; /* todo! */
}

auto Component_text_87::subtree_index ([[maybe_unused]] slint::private_api::ItemTreeRef component) -> uintptr_t{
    return std::numeric_limits<uintptr_t>::max();
}

auto Component_text_87::item_tree () -> slint::cbindgen_private::Slice<slint::private_api::ItemTreeNode>{
    static const slint::private_api::ItemTreeNode children[] {
        slint::private_api::make_item_node(0, 1, 0, 0, true) };
    return slint::private_api::make_slice(std::span(children));
}

auto Component_text_87::item_array () -> const slint::private_api::ItemArray{
    static const slint::private_api::ItemArrayEntry items[] {
        { SLINT_GET_ITEM_VTABLE(SimpleTextVTable),  offsetof(Component_text_87, field_text_87) } };
    return slint::private_api::make_slice(std::span(items));
}

auto Component_text_87::layout_info ([[maybe_unused]] slint::private_api::ItemTreeRef component, slint::cbindgen_private::Orientation o) -> slint::cbindgen_private::LayoutInfo{
    return reinterpret_cast<const Component_text_87*>(component.instance)->layout_info(o);
}

auto Component_text_87::ensure_instantiated ([[maybe_unused]] slint::private_api::ItemTreeRef component) -> bool{
    return reinterpret_cast<const Component_text_87*>(component.instance)->ensure_instantiated();
}

auto Component_text_87::item_geometry ([[maybe_unused]] slint::private_api::ItemTreeRef component, uint32_t index) -> slint::cbindgen_private::LogicalRect{
    return reinterpret_cast<const Component_text_87*>(component.instance)->item_geometry(index);
}

auto Component_text_87::accessible_role ([[maybe_unused]] slint::private_api::ItemTreeRef component, uint32_t index) -> slint::cbindgen_private::AccessibleRole{
    return reinterpret_cast<const Component_text_87*>(component.instance)->accessible_role(index);
}

auto Component_text_87::accessible_string_property ([[maybe_unused]] slint::private_api::ItemTreeRef component, uint32_t index, slint::cbindgen_private::AccessibleStringProperty what, slint::SharedString *result) -> bool{
    if (auto r = reinterpret_cast<const Component_text_87*>(component.instance)->accessible_string_property(index, what)) { *result = *r; return true; } else { return false; }
}

auto Component_text_87::accessibility_action ([[maybe_unused]] slint::private_api::ItemTreeRef component, uint32_t index, const slint::cbindgen_private::AccessibilityAction *action) -> void{
    reinterpret_cast<const Component_text_87*>(component.instance)->accessibility_action(index, *action);
}

auto Component_text_87::supported_accessibility_actions ([[maybe_unused]] slint::private_api::ItemTreeRef component, uint32_t index) -> uint32_t{
    return reinterpret_cast<const Component_text_87*>(component.instance)->supported_accessibility_actions(index);
}

auto Component_text_87::element_infos ([[maybe_unused]] slint::private_api::ItemTreeRef component, [[maybe_unused]] uint32_t index, [[maybe_unused]] slint::SharedString *result) -> bool{
    return false;
}

auto Component_text_87::window_adapter ([[maybe_unused]] slint::private_api::ItemTreeRef component, [[maybe_unused]] bool do_create, [[maybe_unused]] slint::cbindgen_private::Option<slint::private_api::WindowAdapterRc>* result) -> void{
    *reinterpret_cast<slint::private_api::WindowAdapterRc*>(result) = reinterpret_cast<const Component_text_87*>(component.instance)->globals->window().window_handle();
}

auto Component_text_87::create (class DetailsView_root_32 const * parent) -> slint::ComponentHandle<Component_text_87>{
    auto self_rc = vtable::VRc<slint::private_api::ItemTreeVTable, Component_text_87>::make();
    auto self = const_cast<Component_text_87 *>(&*self_rc);
    self->self_weak = vtable::VWeak(self_rc).into_dyn();
    slint::private_api::register_item_tree(&self_rc.into_dyn(), parent->globals->m_window);
    self->init(parent->globals, self->self_weak, 0, 1 , parent);
    return slint::ComponentHandle<Component_text_87>{ self_rc };
}

Component_text_87::~Component_text_87 (){
    if (auto &window = globals->m_window) window->window_handle().unregister_item_tree(this, item_array());
}

auto Component_text_87::init () -> void{
    user_init();
}

auto Component_text_87::layout_item_info (slint::cbindgen_private::Orientation o, [[maybe_unused]] std::optional<size_t> child_index) const -> slint::cbindgen_private::LayoutItemInfo{
    return { layout_info({&static_vtable, const_cast<void *>(static_cast<const void *>(this))}, o) };
}

auto Component_text_87::flexbox_layout_item_info (slint::cbindgen_private::Orientation o, [[maybe_unused]] std::optional<size_t> child_index) const -> slint::cbindgen_private::FlexboxLayoutItemInfo{
    auto base = layout_item_info(o, child_index); return { base.constraint, 0.0f, 0.0f, -1.0f, slint::cbindgen_private::FlexboxLayoutAlignSelf::Auto, 0 };
}

const slint::private_api::ItemTreeVTable Component_empty_89::static_vtable = { visit_children, get_item_ref, get_subtree_range, get_subtree, get_item_tree, parent_node, embed_component, subtree_index, layout_info, ensure_instantiated, item_geometry, accessible_role, accessible_string_property, accessibility_action, supported_accessibility_actions, element_infos, window_adapter, slint::private_api::drop_in_place<Component_empty_89>, slint::private_api::dealloc };

auto Component_empty_89::init (const class SharedGlobals* globals,slint::cbindgen_private::ItemTreeWeak enclosing_component,uint32_t tree_index,uint32_t tree_index_of_first_child,class DetailsView_root_32 const *parent) -> void{
    auto self = this;
    self->self_weak = enclosing_component;
    self->globals = globals;
    this->tree_index_of_first_child = tree_index_of_first_child;
    self->tree_index = tree_index;
    self->parent = vtable::VRcMapped<slint::private_api::ItemTreeVTable, const DetailsView_root_32>(parent->self_weak.lock().value(), parent);
    self->field_empty_89_empty_100_layout_cache.set_binding([this]() {
                            [[maybe_unused]] auto self = this;
                            return slint::private_api::solve_box_layout([&](const auto &a_0, const auto &a_1, const auto &a_2, const auto &a_3, const auto &a_4){ slint::cbindgen_private::BoxLayoutData o{}; o.alignment = a_0; o.cells = a_1; o.padding = a_2; o.size = a_3; o.spacing = a_4; return o; }(slint::cbindgen_private::LayoutAlignment::Start, slint::private_api::make_slice<slint::cbindgen_private::LayoutItemInfo>(std::array<slint::cbindgen_private::LayoutItemInfo, 2>{ slint::cbindgen_private::LayoutItemInfo ( [&](const auto &a_0){ slint::cbindgen_private::LayoutItemInfo o{}; o.constraint = a_0; return o; }([&]{ [[maybe_unused]] auto layout_info = slint::private_api::item_layout_info(SLINT_GET_ITEM_VTABLE(BasicBorderRectangleVTable), const_cast<slint::cbindgen_private::BasicBorderRectangle*>(&self->field_rectangle_101), slint::cbindgen_private::Orientation::Horizontal, -1, &self->globals->window().window_handle(), self->self_weak.lock()->into_dyn(), self->tree_index_of_first_child + 14 - 1);;return [&](const auto &a_0, const auto &a_1, const auto &a_2, const auto &a_3, const auto &a_4, const auto &a_5){ slint::cbindgen_private::LayoutInfo o{}; o.max = a_0; o.max_percent = a_1; o.min = a_2; o.min_percent = a_3; o.preferred = a_4; o.stretch = a_5; return o; }(9, layout_info.max_percent, 9, layout_info.min_percent, layout_info.preferred, layout_info.stretch); }()) ), slint::cbindgen_private::LayoutItemInfo ( [&](const auto &a_0){ slint::cbindgen_private::LayoutItemInfo o{}; o.constraint = a_0; return o; }(slint::private_api::item_layout_info(SLINT_GET_ITEM_VTABLE(SimpleTextVTable), const_cast<slint::cbindgen_private::SimpleText*>(&self->field_text_102), slint::cbindgen_private::Orientation::Horizontal, -1, &self->globals->window().window_handle(), self->self_weak.lock()->into_dyn(), self->tree_index_of_first_child + 15 - 1)) ) }.data(), 2), [&](const auto &a_0, const auto &a_1){ slint::cbindgen_private::Padding o{}; o.begin = a_0; o.end = a_1; return o; }(0, 0), self->field_empty_89_empty_96_layout_cache.get()[3], 6),slint::private_api::make_slice<int>(std::array<int, 0>{  }.data(), 0));
                        });
    self->field_empty_89_empty_100_layoutinfo_h.set_binding([this]() {
                            [[maybe_unused]] auto self = this;
                            return slint::private_api::box_layout_info(slint::private_api::make_slice<slint::cbindgen_private::LayoutItemInfo>(std::array<slint::cbindgen_private::LayoutItemInfo, 2>{ slint::cbindgen_private::LayoutItemInfo ( [&](const auto &a_0){ slint::cbindgen_private::LayoutItemInfo o{}; o.constraint = a_0; return o; }([&]{ [[maybe_unused]] auto layout_info = slint::private_api::item_layout_info(SLINT_GET_ITEM_VTABLE(BasicBorderRectangleVTable), const_cast<slint::cbindgen_private::BasicBorderRectangle*>(&self->field_rectangle_101), slint::cbindgen_private::Orientation::Horizontal, -1, &self->globals->window().window_handle(), self->self_weak.lock()->into_dyn(), self->tree_index_of_first_child + 14 - 1);;return [&](const auto &a_0, const auto &a_1, const auto &a_2, const auto &a_3, const auto &a_4, const auto &a_5){ slint::cbindgen_private::LayoutInfo o{}; o.max = a_0; o.max_percent = a_1; o.min = a_2; o.min_percent = a_3; o.preferred = a_4; o.stretch = a_5; return o; }(9, layout_info.max_percent, 9, layout_info.min_percent, layout_info.preferred, layout_info.stretch); }()) ), slint::cbindgen_private::LayoutItemInfo ( [&](const auto &a_0){ slint::cbindgen_private::LayoutItemInfo o{}; o.constraint = a_0; return o; }(slint::private_api::item_layout_info(SLINT_GET_ITEM_VTABLE(SimpleTextVTable), const_cast<slint::cbindgen_private::SimpleText*>(&self->field_text_102), slint::cbindgen_private::Orientation::Horizontal, -1, &self->globals->window().window_handle(), self->self_weak.lock()->into_dyn(), self->tree_index_of_first_child + 15 - 1)) ) }.data(), 2),6,[&](const auto &a_0, const auto &a_1){ slint::cbindgen_private::Padding o{}; o.begin = a_0; o.end = a_1; return o; }(0, 0),slint::cbindgen_private::LayoutAlignment::Start);
                        });
    self->field_empty_89_empty_100_layoutinfo_v.set_binding([this]() {
                            [[maybe_unused]] auto self = this;
                            return slint::private_api::box_layout_info_ortho(slint::private_api::make_slice<slint::cbindgen_private::LayoutItemInfo>(std::array<slint::cbindgen_private::LayoutItemInfo, 2>{ slint::cbindgen_private::LayoutItemInfo ( [&](const auto &a_0){ slint::cbindgen_private::LayoutItemInfo o{}; o.constraint = a_0; return o; }([&]{ [[maybe_unused]] auto layout_info = slint::private_api::item_layout_info(SLINT_GET_ITEM_VTABLE(BasicBorderRectangleVTable), const_cast<slint::cbindgen_private::BasicBorderRectangle*>(&self->field_rectangle_101), slint::cbindgen_private::Orientation::Vertical, -1, &self->globals->window().window_handle(), self->self_weak.lock()->into_dyn(), self->tree_index_of_first_child + 14 - 1);;return [&](const auto &a_0, const auto &a_1, const auto &a_2, const auto &a_3, const auto &a_4, const auto &a_5){ slint::cbindgen_private::LayoutInfo o{}; o.max = a_0; o.max_percent = a_1; o.min = a_2; o.min_percent = a_3; o.preferred = a_4; o.stretch = a_5; return o; }(9, layout_info.max_percent, 9, layout_info.min_percent, layout_info.preferred, layout_info.stretch); }()) ), slint::cbindgen_private::LayoutItemInfo ( [&](const auto &a_0){ slint::cbindgen_private::LayoutItemInfo o{}; o.constraint = a_0; return o; }(slint::private_api::item_layout_info(SLINT_GET_ITEM_VTABLE(SimpleTextVTable), const_cast<slint::cbindgen_private::SimpleText*>(&self->field_text_102), slint::cbindgen_private::Orientation::Vertical, -1, &self->globals->window().window_handle(), self->self_weak.lock()->into_dyn(), self->tree_index_of_first_child + 15 - 1)) ) }.data(), 2),[&](const auto &a_0, const auto &a_1){ slint::cbindgen_private::Padding o{}; o.begin = a_0; o.end = a_1; return o; }(0, 0));
                        });
    self->field_empty_89_empty_103_layout_cache.set_binding([this]() {
                            [[maybe_unused]] auto self = this;
                            return slint::private_api::solve_box_layout([&](const auto &a_0, const auto &a_1, const auto &a_2, const auto &a_3, const auto &a_4){ slint::cbindgen_private::BoxLayoutData o{}; o.alignment = a_0; o.cells = a_1; o.padding = a_2; o.size = a_3; o.spacing = a_4; return o; }(slint::cbindgen_private::LayoutAlignment::Start, slint::private_api::make_slice<slint::cbindgen_private::LayoutItemInfo>(std::array<slint::cbindgen_private::LayoutItemInfo, 2>{ slint::cbindgen_private::LayoutItemInfo ( [&](const auto &a_0){ slint::cbindgen_private::LayoutItemInfo o{}; o.constraint = a_0; return o; }([&]{ [[maybe_unused]] auto layout_info = slint::private_api::item_layout_info(SLINT_GET_ITEM_VTABLE(BasicBorderRectangleVTable), const_cast<slint::cbindgen_private::BasicBorderRectangle*>(&self->field_rectangle_104), slint::cbindgen_private::Orientation::Horizontal, -1, &self->globals->window().window_handle(), self->self_weak.lock()->into_dyn(), self->tree_index_of_first_child + 16 - 1);;return [&](const auto &a_0, const auto &a_1, const auto &a_2, const auto &a_3, const auto &a_4, const auto &a_5){ slint::cbindgen_private::LayoutInfo o{}; o.max = a_0; o.max_percent = a_1; o.min = a_2; o.min_percent = a_3; o.preferred = a_4; o.stretch = a_5; return o; }(9, layout_info.max_percent, 9, layout_info.min_percent, layout_info.preferred, layout_info.stretch); }()) ), slint::cbindgen_private::LayoutItemInfo ( [&](const auto &a_0){ slint::cbindgen_private::LayoutItemInfo o{}; o.constraint = a_0; return o; }(slint::private_api::item_layout_info(SLINT_GET_ITEM_VTABLE(SimpleTextVTable), const_cast<slint::cbindgen_private::SimpleText*>(&self->field_text_105), slint::cbindgen_private::Orientation::Horizontal, -1, &self->globals->window().window_handle(), self->self_weak.lock()->into_dyn(), self->tree_index_of_first_child + 17 - 1)) ) }.data(), 2), [&](const auto &a_0, const auto &a_1){ slint::cbindgen_private::Padding o{}; o.begin = a_0; o.end = a_1; return o; }(0, 0), self->field_empty_89_empty_96_layout_cache.get()[5], 6),slint::private_api::make_slice<int>(std::array<int, 0>{  }.data(), 0));
                        });
    self->field_empty_89_empty_103_layoutinfo_h.set_binding([this]() {
                            [[maybe_unused]] auto self = this;
                            return slint::private_api::box_layout_info(slint::private_api::make_slice<slint::cbindgen_private::LayoutItemInfo>(std::array<slint::cbindgen_private::LayoutItemInfo, 2>{ slint::cbindgen_private::LayoutItemInfo ( [&](const auto &a_0){ slint::cbindgen_private::LayoutItemInfo o{}; o.constraint = a_0; return o; }([&]{ [[maybe_unused]] auto layout_info = slint::private_api::item_layout_info(SLINT_GET_ITEM_VTABLE(BasicBorderRectangleVTable), const_cast<slint::cbindgen_private::BasicBorderRectangle*>(&self->field_rectangle_104), slint::cbindgen_private::Orientation::Horizontal, -1, &self->globals->window().window_handle(), self->self_weak.lock()->into_dyn(), self->tree_index_of_first_child + 16 - 1);;return [&](const auto &a_0, const auto &a_1, const auto &a_2, const auto &a_3, const auto &a_4, const auto &a_5){ slint::cbindgen_private::LayoutInfo o{}; o.max = a_0; o.max_percent = a_1; o.min = a_2; o.min_percent = a_3; o.preferred = a_4; o.stretch = a_5; return o; }(9, layout_info.max_percent, 9, layout_info.min_percent, layout_info.preferred, layout_info.stretch); }()) ), slint::cbindgen_private::LayoutItemInfo ( [&](const auto &a_0){ slint::cbindgen_private::LayoutItemInfo o{}; o.constraint = a_0; return o; }(slint::private_api::item_layout_info(SLINT_GET_ITEM_VTABLE(SimpleTextVTable), const_cast<slint::cbindgen_private::SimpleText*>(&self->field_text_105), slint::cbindgen_private::Orientation::Horizontal, -1, &self->globals->window().window_handle(), self->self_weak.lock()->into_dyn(), self->tree_index_of_first_child + 17 - 1)) ) }.data(), 2),6,[&](const auto &a_0, const auto &a_1){ slint::cbindgen_private::Padding o{}; o.begin = a_0; o.end = a_1; return o; }(0, 0),slint::cbindgen_private::LayoutAlignment::Start);
                        });
    self->field_empty_89_empty_103_layoutinfo_v.set_binding([this]() {
                            [[maybe_unused]] auto self = this;
                            return slint::private_api::box_layout_info_ortho(slint::private_api::make_slice<slint::cbindgen_private::LayoutItemInfo>(std::array<slint::cbindgen_private::LayoutItemInfo, 2>{ slint::cbindgen_private::LayoutItemInfo ( [&](const auto &a_0){ slint::cbindgen_private::LayoutItemInfo o{}; o.constraint = a_0; return o; }([&]{ [[maybe_unused]] auto layout_info = slint::private_api::item_layout_info(SLINT_GET_ITEM_VTABLE(BasicBorderRectangleVTable), const_cast<slint::cbindgen_private::BasicBorderRectangle*>(&self->field_rectangle_104), slint::cbindgen_private::Orientation::Vertical, -1, &self->globals->window().window_handle(), self->self_weak.lock()->into_dyn(), self->tree_index_of_first_child + 16 - 1);;return [&](const auto &a_0, const auto &a_1, const auto &a_2, const auto &a_3, const auto &a_4, const auto &a_5){ slint::cbindgen_private::LayoutInfo o{}; o.max = a_0; o.max_percent = a_1; o.min = a_2; o.min_percent = a_3; o.preferred = a_4; o.stretch = a_5; return o; }(9, layout_info.max_percent, 9, layout_info.min_percent, layout_info.preferred, layout_info.stretch); }()) ), slint::cbindgen_private::LayoutItemInfo ( [&](const auto &a_0){ slint::cbindgen_private::LayoutItemInfo o{}; o.constraint = a_0; return o; }(slint::private_api::item_layout_info(SLINT_GET_ITEM_VTABLE(SimpleTextVTable), const_cast<slint::cbindgen_private::SimpleText*>(&self->field_text_105), slint::cbindgen_private::Orientation::Vertical, -1, &self->globals->window().window_handle(), self->self_weak.lock()->into_dyn(), self->tree_index_of_first_child + 17 - 1)) ) }.data(), 2),[&](const auto &a_0, const auto &a_1){ slint::cbindgen_private::Padding o{}; o.begin = a_0; o.end = a_1; return o; }(0, 0));
                        });
    self->field_empty_89_empty_107_layout_cache.set_binding([this]() {
                            [[maybe_unused]] auto self = this;
                            return slint::private_api::solve_box_layout([&](const auto &a_0, const auto &a_1, const auto &a_2, const auto &a_3, const auto &a_4){ slint::cbindgen_private::BoxLayoutData o{}; o.alignment = a_0; o.cells = a_1; o.padding = a_2; o.size = a_3; o.spacing = a_4; return o; }(slint::cbindgen_private::LayoutAlignment::Stretch, slint::private_api::make_slice<slint::cbindgen_private::LayoutItemInfo>(std::array<slint::cbindgen_private::LayoutItemInfo, 5>{ slint::cbindgen_private::LayoutItemInfo ( [&](const auto &a_0){ slint::cbindgen_private::LayoutItemInfo o{}; o.constraint = a_0; return o; }(self->field_empty_89_empty_108_layoutinfo_h.get()) ), slint::cbindgen_private::LayoutItemInfo ( [&](const auto &a_0){ slint::cbindgen_private::LayoutItemInfo o{}; o.constraint = a_0; return o; }([&]{ [[maybe_unused]] auto layout_info = slint::private_api::item_layout_info(SLINT_GET_ITEM_VTABLE(EmptyVTable), const_cast<slint::cbindgen_private::Empty*>(&self->field_rectangle_111), slint::cbindgen_private::Orientation::Horizontal, -1, &self->globals->window().window_handle(), self->self_weak.lock()->into_dyn(), self->tree_index_of_first_child + 19 - 1);;return [&](const auto &a_0, const auto &a_1, const auto &a_2, const auto &a_3, const auto &a_4, const auto &a_5){ slint::cbindgen_private::LayoutInfo o{}; o.max = a_0; o.max_percent = a_1; o.min = a_2; o.min_percent = a_3; o.preferred = a_4; o.stretch = a_5; return o; }(layout_info.max, layout_info.max_percent, layout_info.min, layout_info.min_percent, layout_info.preferred, 1); }()) ), slint::cbindgen_private::LayoutItemInfo ( [&](const auto &a_0){ slint::cbindgen_private::LayoutItemInfo o{}; o.constraint = a_0; return o; }(self->field_empty_89_empty_112_layoutinfo_h.get()) ), slint::cbindgen_private::LayoutItemInfo ( [&](const auto &a_0){ slint::cbindgen_private::LayoutItemInfo o{}; o.constraint = a_0; return o; }([&]{ [[maybe_unused]] auto layout_info = slint::private_api::item_layout_info(SLINT_GET_ITEM_VTABLE(EmptyVTable), const_cast<slint::cbindgen_private::Empty*>(&self->field_rectangle_115), slint::cbindgen_private::Orientation::Horizontal, -1, &self->globals->window().window_handle(), self->self_weak.lock()->into_dyn(), self->tree_index_of_first_child + 21 - 1);;return [&](const auto &a_0, const auto &a_1, const auto &a_2, const auto &a_3, const auto &a_4, const auto &a_5){ slint::cbindgen_private::LayoutInfo o{}; o.max = a_0; o.max_percent = a_1; o.min = a_2; o.min_percent = a_3; o.preferred = a_4; o.stretch = a_5; return o; }(layout_info.max, layout_info.max_percent, layout_info.min, layout_info.min_percent, layout_info.preferred, 1); }()) ), slint::cbindgen_private::LayoutItemInfo ( [&](const auto &a_0){ slint::cbindgen_private::LayoutItemInfo o{}; o.constraint = a_0; return o; }(self->field_empty_89_empty_116_layoutinfo_h.get()) ) }.data(), 5), [&](const auto &a_0, const auto &a_1){ slint::cbindgen_private::Padding o{}; o.begin = a_0; o.end = a_1; return o; }(0, 0), self->field_empty_89_width.get(), 0),slint::private_api::make_slice<int>(std::array<int, 0>{  }.data(), 0));
                        });
    self->field_empty_89_empty_107_layoutinfo_h.set_binding([this]() {
                            [[maybe_unused]] auto self = this;
                            return slint::private_api::box_layout_info(slint::private_api::make_slice<slint::cbindgen_private::LayoutItemInfo>(std::array<slint::cbindgen_private::LayoutItemInfo, 5>{ slint::cbindgen_private::LayoutItemInfo ( [&](const auto &a_0){ slint::cbindgen_private::LayoutItemInfo o{}; o.constraint = a_0; return o; }(self->field_empty_89_empty_108_layoutinfo_h.get()) ), slint::cbindgen_private::LayoutItemInfo ( [&](const auto &a_0){ slint::cbindgen_private::LayoutItemInfo o{}; o.constraint = a_0; return o; }([&]{ [[maybe_unused]] auto layout_info = slint::private_api::item_layout_info(SLINT_GET_ITEM_VTABLE(EmptyVTable), const_cast<slint::cbindgen_private::Empty*>(&self->field_rectangle_111), slint::cbindgen_private::Orientation::Horizontal, -1, &self->globals->window().window_handle(), self->self_weak.lock()->into_dyn(), self->tree_index_of_first_child + 19 - 1);;return [&](const auto &a_0, const auto &a_1, const auto &a_2, const auto &a_3, const auto &a_4, const auto &a_5){ slint::cbindgen_private::LayoutInfo o{}; o.max = a_0; o.max_percent = a_1; o.min = a_2; o.min_percent = a_3; o.preferred = a_4; o.stretch = a_5; return o; }(layout_info.max, layout_info.max_percent, layout_info.min, layout_info.min_percent, layout_info.preferred, 1); }()) ), slint::cbindgen_private::LayoutItemInfo ( [&](const auto &a_0){ slint::cbindgen_private::LayoutItemInfo o{}; o.constraint = a_0; return o; }(self->field_empty_89_empty_112_layoutinfo_h.get()) ), slint::cbindgen_private::LayoutItemInfo ( [&](const auto &a_0){ slint::cbindgen_private::LayoutItemInfo o{}; o.constraint = a_0; return o; }([&]{ [[maybe_unused]] auto layout_info = slint::private_api::item_layout_info(SLINT_GET_ITEM_VTABLE(EmptyVTable), const_cast<slint::cbindgen_private::Empty*>(&self->field_rectangle_115), slint::cbindgen_private::Orientation::Horizontal, -1, &self->globals->window().window_handle(), self->self_weak.lock()->into_dyn(), self->tree_index_of_first_child + 21 - 1);;return [&](const auto &a_0, const auto &a_1, const auto &a_2, const auto &a_3, const auto &a_4, const auto &a_5){ slint::cbindgen_private::LayoutInfo o{}; o.max = a_0; o.max_percent = a_1; o.min = a_2; o.min_percent = a_3; o.preferred = a_4; o.stretch = a_5; return o; }(layout_info.max, layout_info.max_percent, layout_info.min, layout_info.min_percent, layout_info.preferred, 1); }()) ), slint::cbindgen_private::LayoutItemInfo ( [&](const auto &a_0){ slint::cbindgen_private::LayoutItemInfo o{}; o.constraint = a_0; return o; }(self->field_empty_89_empty_116_layoutinfo_h.get()) ) }.data(), 5),0,[&](const auto &a_0, const auto &a_1){ slint::cbindgen_private::Padding o{}; o.begin = a_0; o.end = a_1; return o; }(0, 0),slint::cbindgen_private::LayoutAlignment::Stretch);
                        });
    self->field_empty_89_empty_107_layoutinfo_v.set_binding([this]() {
                            [[maybe_unused]] auto self = this;
                            return slint::private_api::box_layout_info_ortho(slint::private_api::make_slice<slint::cbindgen_private::LayoutItemInfo>(std::array<slint::cbindgen_private::LayoutItemInfo, 5>{ slint::cbindgen_private::LayoutItemInfo ( [&](const auto &a_0){ slint::cbindgen_private::LayoutItemInfo o{}; o.constraint = a_0; return o; }(self->field_empty_89_empty_108_layoutinfo_v.get()) ), slint::cbindgen_private::LayoutItemInfo ( [&](const auto &a_0){ slint::cbindgen_private::LayoutItemInfo o{}; o.constraint = a_0; return o; }(slint::private_api::item_layout_info(SLINT_GET_ITEM_VTABLE(EmptyVTable), const_cast<slint::cbindgen_private::Empty*>(&self->field_rectangle_111), slint::cbindgen_private::Orientation::Vertical, -1, &self->globals->window().window_handle(), self->self_weak.lock()->into_dyn(), self->tree_index_of_first_child + 19 - 1)) ), slint::cbindgen_private::LayoutItemInfo ( [&](const auto &a_0){ slint::cbindgen_private::LayoutItemInfo o{}; o.constraint = a_0; return o; }(self->field_empty_89_empty_112_layoutinfo_v.get()) ), slint::cbindgen_private::LayoutItemInfo ( [&](const auto &a_0){ slint::cbindgen_private::LayoutItemInfo o{}; o.constraint = a_0; return o; }(slint::private_api::item_layout_info(SLINT_GET_ITEM_VTABLE(EmptyVTable), const_cast<slint::cbindgen_private::Empty*>(&self->field_rectangle_115), slint::cbindgen_private::Orientation::Vertical, -1, &self->globals->window().window_handle(), self->self_weak.lock()->into_dyn(), self->tree_index_of_first_child + 21 - 1)) ), slint::cbindgen_private::LayoutItemInfo ( [&](const auto &a_0){ slint::cbindgen_private::LayoutItemInfo o{}; o.constraint = a_0; return o; }(self->field_empty_89_empty_116_layoutinfo_v.get()) ) }.data(), 5),[&](const auto &a_0, const auto &a_1){ slint::cbindgen_private::Padding o{}; o.begin = a_0; o.end = a_1; return o; }(0, 0));
                        });
    self->field_empty_89_empty_108_layout_cache.set_binding([this]() {
                            [[maybe_unused]] auto self = this;
                            return slint::private_api::solve_box_layout([&](const auto &a_0, const auto &a_1, const auto &a_2, const auto &a_3, const auto &a_4){ slint::cbindgen_private::BoxLayoutData o{}; o.alignment = a_0; o.cells = a_1; o.padding = a_2; o.size = a_3; o.spacing = a_4; return o; }(slint::cbindgen_private::LayoutAlignment::Start, slint::private_api::make_slice<slint::cbindgen_private::LayoutItemInfo>(std::array<slint::cbindgen_private::LayoutItemInfo, 2>{ slint::cbindgen_private::LayoutItemInfo ( [&](const auto &a_0){ slint::cbindgen_private::LayoutItemInfo o{}; o.constraint = a_0; return o; }(slint::private_api::item_layout_info(SLINT_GET_ITEM_VTABLE(SimpleTextVTable), const_cast<slint::cbindgen_private::SimpleText*>(&self->field_text_109), slint::cbindgen_private::Orientation::Vertical, -1, &self->globals->window().window_handle(), self->self_weak.lock()->into_dyn(), self->tree_index_of_first_child + 23 - 1)) ), slint::cbindgen_private::LayoutItemInfo ( [&](const auto &a_0){ slint::cbindgen_private::LayoutItemInfo o{}; o.constraint = a_0; return o; }(slint::private_api::item_layout_info(SLINT_GET_ITEM_VTABLE(SimpleTextVTable), const_cast<slint::cbindgen_private::SimpleText*>(&self->field_text_110), slint::cbindgen_private::Orientation::Vertical, -1, &self->globals->window().window_handle(), self->self_weak.lock()->into_dyn(), self->tree_index_of_first_child + 24 - 1)) ) }.data(), 2), [&](const auto &a_0, const auto &a_1){ slint::cbindgen_private::Padding o{}; o.begin = a_0; o.end = a_1; return o; }(0, 0), self->field_empty_89_layout_cache.get()[7], 4),slint::private_api::make_slice<int>(std::array<int, 0>{  }.data(), 0));
                        });
    self->field_empty_89_empty_108_layoutinfo_h.set_binding([this]() {
                            [[maybe_unused]] auto self = this;
                            return slint::private_api::box_layout_info_ortho(slint::private_api::make_slice<slint::cbindgen_private::LayoutItemInfo>(std::array<slint::cbindgen_private::LayoutItemInfo, 2>{ slint::cbindgen_private::LayoutItemInfo ( [&](const auto &a_0){ slint::cbindgen_private::LayoutItemInfo o{}; o.constraint = a_0; return o; }(slint::private_api::item_layout_info(SLINT_GET_ITEM_VTABLE(SimpleTextVTable), const_cast<slint::cbindgen_private::SimpleText*>(&self->field_text_109), slint::cbindgen_private::Orientation::Horizontal, -1, &self->globals->window().window_handle(), self->self_weak.lock()->into_dyn(), self->tree_index_of_first_child + 23 - 1)) ), slint::cbindgen_private::LayoutItemInfo ( [&](const auto &a_0){ slint::cbindgen_private::LayoutItemInfo o{}; o.constraint = a_0; return o; }(slint::private_api::item_layout_info(SLINT_GET_ITEM_VTABLE(SimpleTextVTable), const_cast<slint::cbindgen_private::SimpleText*>(&self->field_text_110), slint::cbindgen_private::Orientation::Horizontal, -1, &self->globals->window().window_handle(), self->self_weak.lock()->into_dyn(), self->tree_index_of_first_child + 24 - 1)) ) }.data(), 2),[&](const auto &a_0, const auto &a_1){ slint::cbindgen_private::Padding o{}; o.begin = a_0; o.end = a_1; return o; }(0, 0));
                        });
    self->field_empty_89_empty_108_layoutinfo_v.set_binding([this]() {
                            [[maybe_unused]] auto self = this;
                            return slint::private_api::box_layout_info(slint::private_api::make_slice<slint::cbindgen_private::LayoutItemInfo>(std::array<slint::cbindgen_private::LayoutItemInfo, 2>{ slint::cbindgen_private::LayoutItemInfo ( [&](const auto &a_0){ slint::cbindgen_private::LayoutItemInfo o{}; o.constraint = a_0; return o; }(slint::private_api::item_layout_info(SLINT_GET_ITEM_VTABLE(SimpleTextVTable), const_cast<slint::cbindgen_private::SimpleText*>(&self->field_text_109), slint::cbindgen_private::Orientation::Vertical, -1, &self->globals->window().window_handle(), self->self_weak.lock()->into_dyn(), self->tree_index_of_first_child + 23 - 1)) ), slint::cbindgen_private::LayoutItemInfo ( [&](const auto &a_0){ slint::cbindgen_private::LayoutItemInfo o{}; o.constraint = a_0; return o; }(slint::private_api::item_layout_info(SLINT_GET_ITEM_VTABLE(SimpleTextVTable), const_cast<slint::cbindgen_private::SimpleText*>(&self->field_text_110), slint::cbindgen_private::Orientation::Vertical, -1, &self->globals->window().window_handle(), self->self_weak.lock()->into_dyn(), self->tree_index_of_first_child + 24 - 1)) ) }.data(), 2),4,[&](const auto &a_0, const auto &a_1){ slint::cbindgen_private::Padding o{}; o.begin = a_0; o.end = a_1; return o; }(0, 0),slint::cbindgen_private::LayoutAlignment::Start);
                        });
    self->field_empty_89_empty_112_layout_cache.set_binding([this]() {
                            [[maybe_unused]] auto self = this;
                            return slint::private_api::solve_box_layout([&](const auto &a_0, const auto &a_1, const auto &a_2, const auto &a_3, const auto &a_4){ slint::cbindgen_private::BoxLayoutData o{}; o.alignment = a_0; o.cells = a_1; o.padding = a_2; o.size = a_3; o.spacing = a_4; return o; }(slint::cbindgen_private::LayoutAlignment::Start, slint::private_api::make_slice<slint::cbindgen_private::LayoutItemInfo>(std::array<slint::cbindgen_private::LayoutItemInfo, 2>{ slint::cbindgen_private::LayoutItemInfo ( [&](const auto &a_0){ slint::cbindgen_private::LayoutItemInfo o{}; o.constraint = a_0; return o; }(slint::private_api::item_layout_info(SLINT_GET_ITEM_VTABLE(SimpleTextVTable), const_cast<slint::cbindgen_private::SimpleText*>(&self->field_text_113), slint::cbindgen_private::Orientation::Vertical, -1, &self->globals->window().window_handle(), self->self_weak.lock()->into_dyn(), self->tree_index_of_first_child + 25 - 1)) ), slint::cbindgen_private::LayoutItemInfo ( [&](const auto &a_0){ slint::cbindgen_private::LayoutItemInfo o{}; o.constraint = a_0; return o; }(slint::private_api::item_layout_info(SLINT_GET_ITEM_VTABLE(SimpleTextVTable), const_cast<slint::cbindgen_private::SimpleText*>(&self->field_text_114), slint::cbindgen_private::Orientation::Vertical, -1, &self->globals->window().window_handle(), self->self_weak.lock()->into_dyn(), self->tree_index_of_first_child + 26 - 1)) ) }.data(), 2), [&](const auto &a_0, const auto &a_1){ slint::cbindgen_private::Padding o{}; o.begin = a_0; o.end = a_1; return o; }(0, 0), self->field_empty_89_layout_cache.get()[7], 4),slint::private_api::make_slice<int>(std::array<int, 0>{  }.data(), 0));
                        });
    self->field_empty_89_empty_112_layoutinfo_h.set_binding([this]() {
                            [[maybe_unused]] auto self = this;
                            return slint::private_api::box_layout_info_ortho(slint::private_api::make_slice<slint::cbindgen_private::LayoutItemInfo>(std::array<slint::cbindgen_private::LayoutItemInfo, 2>{ slint::cbindgen_private::LayoutItemInfo ( [&](const auto &a_0){ slint::cbindgen_private::LayoutItemInfo o{}; o.constraint = a_0; return o; }(slint::private_api::item_layout_info(SLINT_GET_ITEM_VTABLE(SimpleTextVTable), const_cast<slint::cbindgen_private::SimpleText*>(&self->field_text_113), slint::cbindgen_private::Orientation::Horizontal, -1, &self->globals->window().window_handle(), self->self_weak.lock()->into_dyn(), self->tree_index_of_first_child + 25 - 1)) ), slint::cbindgen_private::LayoutItemInfo ( [&](const auto &a_0){ slint::cbindgen_private::LayoutItemInfo o{}; o.constraint = a_0; return o; }(slint::private_api::item_layout_info(SLINT_GET_ITEM_VTABLE(SimpleTextVTable), const_cast<slint::cbindgen_private::SimpleText*>(&self->field_text_114), slint::cbindgen_private::Orientation::Horizontal, -1, &self->globals->window().window_handle(), self->self_weak.lock()->into_dyn(), self->tree_index_of_first_child + 26 - 1)) ) }.data(), 2),[&](const auto &a_0, const auto &a_1){ slint::cbindgen_private::Padding o{}; o.begin = a_0; o.end = a_1; return o; }(0, 0));
                        });
    self->field_empty_89_empty_112_layoutinfo_v.set_binding([this]() {
                            [[maybe_unused]] auto self = this;
                            return slint::private_api::box_layout_info(slint::private_api::make_slice<slint::cbindgen_private::LayoutItemInfo>(std::array<slint::cbindgen_private::LayoutItemInfo, 2>{ slint::cbindgen_private::LayoutItemInfo ( [&](const auto &a_0){ slint::cbindgen_private::LayoutItemInfo o{}; o.constraint = a_0; return o; }(slint::private_api::item_layout_info(SLINT_GET_ITEM_VTABLE(SimpleTextVTable), const_cast<slint::cbindgen_private::SimpleText*>(&self->field_text_113), slint::cbindgen_private::Orientation::Vertical, -1, &self->globals->window().window_handle(), self->self_weak.lock()->into_dyn(), self->tree_index_of_first_child + 25 - 1)) ), slint::cbindgen_private::LayoutItemInfo ( [&](const auto &a_0){ slint::cbindgen_private::LayoutItemInfo o{}; o.constraint = a_0; return o; }(slint::private_api::item_layout_info(SLINT_GET_ITEM_VTABLE(SimpleTextVTable), const_cast<slint::cbindgen_private::SimpleText*>(&self->field_text_114), slint::cbindgen_private::Orientation::Vertical, -1, &self->globals->window().window_handle(), self->self_weak.lock()->into_dyn(), self->tree_index_of_first_child + 26 - 1)) ) }.data(), 2),4,[&](const auto &a_0, const auto &a_1){ slint::cbindgen_private::Padding o{}; o.begin = a_0; o.end = a_1; return o; }(0, 0),slint::cbindgen_private::LayoutAlignment::Start);
                        });
    self->field_empty_89_empty_116_layout_cache.set_binding([this]() {
                            [[maybe_unused]] auto self = this;
                            return slint::private_api::solve_box_layout([&](const auto &a_0, const auto &a_1, const auto &a_2, const auto &a_3, const auto &a_4){ slint::cbindgen_private::BoxLayoutData o{}; o.alignment = a_0; o.cells = a_1; o.padding = a_2; o.size = a_3; o.spacing = a_4; return o; }(slint::cbindgen_private::LayoutAlignment::End, slint::private_api::make_slice<slint::cbindgen_private::LayoutItemInfo>(std::array<slint::cbindgen_private::LayoutItemInfo, 2>{ slint::cbindgen_private::LayoutItemInfo ( [&](const auto &a_0){ slint::cbindgen_private::LayoutItemInfo o{}; o.constraint = a_0; return o; }(slint::private_api::item_layout_info(SLINT_GET_ITEM_VTABLE(SimpleTextVTable), const_cast<slint::cbindgen_private::SimpleText*>(&self->field_text_117), slint::cbindgen_private::Orientation::Vertical, -1, &self->globals->window().window_handle(), self->self_weak.lock()->into_dyn(), self->tree_index_of_first_child + 27 - 1)) ), slint::cbindgen_private::LayoutItemInfo ( [&](const auto &a_0){ slint::cbindgen_private::LayoutItemInfo o{}; o.constraint = a_0; return o; }(slint::private_api::item_layout_info(SLINT_GET_ITEM_VTABLE(SimpleTextVTable), const_cast<slint::cbindgen_private::SimpleText*>(&self->field_text_118), slint::cbindgen_private::Orientation::Vertical, -1, &self->globals->window().window_handle(), self->self_weak.lock()->into_dyn(), self->tree_index_of_first_child + 28 - 1)) ) }.data(), 2), [&](const auto &a_0, const auto &a_1){ slint::cbindgen_private::Padding o{}; o.begin = a_0; o.end = a_1; return o; }(0, 0), self->field_empty_89_layout_cache.get()[7], 4),slint::private_api::make_slice<int>(std::array<int, 0>{  }.data(), 0));
                        });
    self->field_empty_89_empty_116_layoutinfo_h.set_binding([this]() {
                            [[maybe_unused]] auto self = this;
                            return slint::private_api::box_layout_info_ortho(slint::private_api::make_slice<slint::cbindgen_private::LayoutItemInfo>(std::array<slint::cbindgen_private::LayoutItemInfo, 2>{ slint::cbindgen_private::LayoutItemInfo ( [&](const auto &a_0){ slint::cbindgen_private::LayoutItemInfo o{}; o.constraint = a_0; return o; }(slint::private_api::item_layout_info(SLINT_GET_ITEM_VTABLE(SimpleTextVTable), const_cast<slint::cbindgen_private::SimpleText*>(&self->field_text_117), slint::cbindgen_private::Orientation::Horizontal, -1, &self->globals->window().window_handle(), self->self_weak.lock()->into_dyn(), self->tree_index_of_first_child + 27 - 1)) ), slint::cbindgen_private::LayoutItemInfo ( [&](const auto &a_0){ slint::cbindgen_private::LayoutItemInfo o{}; o.constraint = a_0; return o; }(slint::private_api::item_layout_info(SLINT_GET_ITEM_VTABLE(SimpleTextVTable), const_cast<slint::cbindgen_private::SimpleText*>(&self->field_text_118), slint::cbindgen_private::Orientation::Horizontal, -1, &self->globals->window().window_handle(), self->self_weak.lock()->into_dyn(), self->tree_index_of_first_child + 28 - 1)) ) }.data(), 2),[&](const auto &a_0, const auto &a_1){ slint::cbindgen_private::Padding o{}; o.begin = a_0; o.end = a_1; return o; }(0, 0));
                        });
    self->field_empty_89_empty_116_layoutinfo_v.set_binding([this]() {
                            [[maybe_unused]] auto self = this;
                            return slint::private_api::box_layout_info(slint::private_api::make_slice<slint::cbindgen_private::LayoutItemInfo>(std::array<slint::cbindgen_private::LayoutItemInfo, 2>{ slint::cbindgen_private::LayoutItemInfo ( [&](const auto &a_0){ slint::cbindgen_private::LayoutItemInfo o{}; o.constraint = a_0; return o; }(slint::private_api::item_layout_info(SLINT_GET_ITEM_VTABLE(SimpleTextVTable), const_cast<slint::cbindgen_private::SimpleText*>(&self->field_text_117), slint::cbindgen_private::Orientation::Vertical, -1, &self->globals->window().window_handle(), self->self_weak.lock()->into_dyn(), self->tree_index_of_first_child + 27 - 1)) ), slint::cbindgen_private::LayoutItemInfo ( [&](const auto &a_0){ slint::cbindgen_private::LayoutItemInfo o{}; o.constraint = a_0; return o; }(slint::private_api::item_layout_info(SLINT_GET_ITEM_VTABLE(SimpleTextVTable), const_cast<slint::cbindgen_private::SimpleText*>(&self->field_text_118), slint::cbindgen_private::Orientation::Vertical, -1, &self->globals->window().window_handle(), self->self_weak.lock()->into_dyn(), self->tree_index_of_first_child + 28 - 1)) ) }.data(), 2),4,[&](const auto &a_0, const auto &a_1){ slint::cbindgen_private::Padding o{}; o.begin = a_0; o.end = a_1; return o; }(0, 0),slint::cbindgen_private::LayoutAlignment::End);
                        });
    self->field_empty_89_empty_92_layout_cache.set_binding([this]() {
                            [[maybe_unused]] auto self = this;
                            return slint::private_api::solve_box_layout([&](const auto &a_0, const auto &a_1, const auto &a_2, const auto &a_3, const auto &a_4){ slint::cbindgen_private::BoxLayoutData o{}; o.alignment = a_0; o.cells = a_1; o.padding = a_2; o.size = a_3; o.spacing = a_4; return o; }(slint::cbindgen_private::LayoutAlignment::Stretch, slint::private_api::make_slice<slint::cbindgen_private::LayoutItemInfo>(std::array<slint::cbindgen_private::LayoutItemInfo, 3>{ slint::cbindgen_private::LayoutItemInfo ( [&](const auto &a_0){ slint::cbindgen_private::LayoutItemInfo o{}; o.constraint = a_0; return o; }([&]{ [[maybe_unused]] auto layout_info = slint::private_api::item_layout_info(SLINT_GET_ITEM_VTABLE(RectangleVTable), const_cast<slint::cbindgen_private::Rectangle*>(&self->field_rectangle_93), slint::cbindgen_private::Orientation::Horizontal, -1, &self->globals->window().window_handle(), self->self_weak.lock()->into_dyn(), self->tree_index_of_first_child + 6 - 1);;return [&](const auto &a_0, const auto &a_1, const auto &a_2, const auto &a_3, const auto &a_4, const auto &a_5){ slint::cbindgen_private::LayoutInfo o{}; o.max = a_0; o.max_percent = a_1; o.min = a_2; o.min_percent = a_3; o.preferred = a_4; o.stretch = a_5; return o; }(layout_info.max, layout_info.max_percent, layout_info.min, layout_info.min_percent, layout_info.preferred, std::max<float>(0.0001, slint::private_api::optional_or_default(slint::private_api::optional_transform(self->parent.lock(), [&](auto&&x) { return x->field_root_32_details.get(); })).installed_ratio)); }()) ), slint::cbindgen_private::LayoutItemInfo ( [&](const auto &a_0){ slint::cbindgen_private::LayoutItemInfo o{}; o.constraint = a_0; return o; }([&]{ [[maybe_unused]] auto layout_info = slint::private_api::item_layout_info(SLINT_GET_ITEM_VTABLE(RectangleVTable), const_cast<slint::cbindgen_private::Rectangle*>(&self->field_rectangle_94), slint::cbindgen_private::Orientation::Horizontal, -1, &self->globals->window().window_handle(), self->self_weak.lock()->into_dyn(), self->tree_index_of_first_child + 7 - 1);;return [&](const auto &a_0, const auto &a_1, const auto &a_2, const auto &a_3, const auto &a_4, const auto &a_5){ slint::cbindgen_private::LayoutInfo o{}; o.max = a_0; o.max_percent = a_1; o.min = a_2; o.min_percent = a_3; o.preferred = a_4; o.stretch = a_5; return o; }(layout_info.max, layout_info.max_percent, layout_info.min, layout_info.min_percent, layout_info.preferred, std::max<float>(0.0001, slint::private_api::optional_or_default(slint::private_api::optional_transform(self->parent.lock(), [&](auto&&x) { return x->field_root_32_details.get(); })).new_ratio)); }()) ), slint::cbindgen_private::LayoutItemInfo ( [&](const auto &a_0){ slint::cbindgen_private::LayoutItemInfo o{}; o.constraint = a_0; return o; }([&]{ [[maybe_unused]] auto layout_info = slint::private_api::item_layout_info(SLINT_GET_ITEM_VTABLE(RectangleVTable), const_cast<slint::cbindgen_private::Rectangle*>(&self->field_rectangle_95), slint::cbindgen_private::Orientation::Horizontal, -1, &self->globals->window().window_handle(), self->self_weak.lock()->into_dyn(), self->tree_index_of_first_child + 8 - 1);;return [&](const auto &a_0, const auto &a_1, const auto &a_2, const auto &a_3, const auto &a_4, const auto &a_5){ slint::cbindgen_private::LayoutInfo o{}; o.max = a_0; o.max_percent = a_1; o.min = a_2; o.min_percent = a_3; o.preferred = a_4; o.stretch = a_5; return o; }(layout_info.max, layout_info.max_percent, layout_info.min, layout_info.min_percent, layout_info.preferred, std::max<float>(0.0001, slint::private_api::optional_or_default(slint::private_api::optional_transform(self->parent.lock(), [&](auto&&x) { return x->field_root_32_details.get(); })).app_ratio)); }()) ) }.data(), 3), [&](const auto &a_0, const auto &a_1){ slint::cbindgen_private::Padding o{}; o.begin = a_0; o.end = a_1; return o; }(0, 0), self->field_empty_89_rectangle_90_width.get(), 0),slint::private_api::make_slice<int>(std::array<int, 0>{  }.data(), 0));
                        });
    self->field_empty_89_empty_92_layoutinfo_h.set_binding([this]() {
                            [[maybe_unused]] auto self = this;
                            return slint::private_api::box_layout_info(slint::private_api::make_slice<slint::cbindgen_private::LayoutItemInfo>(std::array<slint::cbindgen_private::LayoutItemInfo, 3>{ slint::cbindgen_private::LayoutItemInfo ( [&](const auto &a_0){ slint::cbindgen_private::LayoutItemInfo o{}; o.constraint = a_0; return o; }([&]{ [[maybe_unused]] auto layout_info = slint::private_api::item_layout_info(SLINT_GET_ITEM_VTABLE(RectangleVTable), const_cast<slint::cbindgen_private::Rectangle*>(&self->field_rectangle_93), slint::cbindgen_private::Orientation::Horizontal, -1, &self->globals->window().window_handle(), self->self_weak.lock()->into_dyn(), self->tree_index_of_first_child + 6 - 1);;return [&](const auto &a_0, const auto &a_1, const auto &a_2, const auto &a_3, const auto &a_4, const auto &a_5){ slint::cbindgen_private::LayoutInfo o{}; o.max = a_0; o.max_percent = a_1; o.min = a_2; o.min_percent = a_3; o.preferred = a_4; o.stretch = a_5; return o; }(layout_info.max, layout_info.max_percent, layout_info.min, layout_info.min_percent, layout_info.preferred, std::max<float>(0.0001, slint::private_api::optional_or_default(slint::private_api::optional_transform(self->parent.lock(), [&](auto&&x) { return x->field_root_32_details.get(); })).installed_ratio)); }()) ), slint::cbindgen_private::LayoutItemInfo ( [&](const auto &a_0){ slint::cbindgen_private::LayoutItemInfo o{}; o.constraint = a_0; return o; }([&]{ [[maybe_unused]] auto layout_info = slint::private_api::item_layout_info(SLINT_GET_ITEM_VTABLE(RectangleVTable), const_cast<slint::cbindgen_private::Rectangle*>(&self->field_rectangle_94), slint::cbindgen_private::Orientation::Horizontal, -1, &self->globals->window().window_handle(), self->self_weak.lock()->into_dyn(), self->tree_index_of_first_child + 7 - 1);;return [&](const auto &a_0, const auto &a_1, const auto &a_2, const auto &a_3, const auto &a_4, const auto &a_5){ slint::cbindgen_private::LayoutInfo o{}; o.max = a_0; o.max_percent = a_1; o.min = a_2; o.min_percent = a_3; o.preferred = a_4; o.stretch = a_5; return o; }(layout_info.max, layout_info.max_percent, layout_info.min, layout_info.min_percent, layout_info.preferred, std::max<float>(0.0001, slint::private_api::optional_or_default(slint::private_api::optional_transform(self->parent.lock(), [&](auto&&x) { return x->field_root_32_details.get(); })).new_ratio)); }()) ), slint::cbindgen_private::LayoutItemInfo ( [&](const auto &a_0){ slint::cbindgen_private::LayoutItemInfo o{}; o.constraint = a_0; return o; }([&]{ [[maybe_unused]] auto layout_info = slint::private_api::item_layout_info(SLINT_GET_ITEM_VTABLE(RectangleVTable), const_cast<slint::cbindgen_private::Rectangle*>(&self->field_rectangle_95), slint::cbindgen_private::Orientation::Horizontal, -1, &self->globals->window().window_handle(), self->self_weak.lock()->into_dyn(), self->tree_index_of_first_child + 8 - 1);;return [&](const auto &a_0, const auto &a_1, const auto &a_2, const auto &a_3, const auto &a_4, const auto &a_5){ slint::cbindgen_private::LayoutInfo o{}; o.max = a_0; o.max_percent = a_1; o.min = a_2; o.min_percent = a_3; o.preferred = a_4; o.stretch = a_5; return o; }(layout_info.max, layout_info.max_percent, layout_info.min, layout_info.min_percent, layout_info.preferred, std::max<float>(0.0001, slint::private_api::optional_or_default(slint::private_api::optional_transform(self->parent.lock(), [&](auto&&x) { return x->field_root_32_details.get(); })).app_ratio)); }()) ) }.data(), 3),0,[&](const auto &a_0, const auto &a_1){ slint::cbindgen_private::Padding o{}; o.begin = a_0; o.end = a_1; return o; }(0, 0),slint::cbindgen_private::LayoutAlignment::Stretch);
                        });
    self->field_empty_89_empty_92_layoutinfo_v.set_binding([this]() {
                            [[maybe_unused]] auto self = this;
                            return slint::private_api::box_layout_info_ortho(slint::private_api::make_slice<slint::cbindgen_private::LayoutItemInfo>(std::array<slint::cbindgen_private::LayoutItemInfo, 3>{ slint::cbindgen_private::LayoutItemInfo ( [&](const auto &a_0){ slint::cbindgen_private::LayoutItemInfo o{}; o.constraint = a_0; return o; }(slint::private_api::item_layout_info(SLINT_GET_ITEM_VTABLE(RectangleVTable), const_cast<slint::cbindgen_private::Rectangle*>(&self->field_rectangle_93), slint::cbindgen_private::Orientation::Vertical, -1, &self->globals->window().window_handle(), self->self_weak.lock()->into_dyn(), self->tree_index_of_first_child + 6 - 1)) ), slint::cbindgen_private::LayoutItemInfo ( [&](const auto &a_0){ slint::cbindgen_private::LayoutItemInfo o{}; o.constraint = a_0; return o; }(slint::private_api::item_layout_info(SLINT_GET_ITEM_VTABLE(RectangleVTable), const_cast<slint::cbindgen_private::Rectangle*>(&self->field_rectangle_94), slint::cbindgen_private::Orientation::Vertical, -1, &self->globals->window().window_handle(), self->self_weak.lock()->into_dyn(), self->tree_index_of_first_child + 7 - 1)) ), slint::cbindgen_private::LayoutItemInfo ( [&](const auto &a_0){ slint::cbindgen_private::LayoutItemInfo o{}; o.constraint = a_0; return o; }(slint::private_api::item_layout_info(SLINT_GET_ITEM_VTABLE(RectangleVTable), const_cast<slint::cbindgen_private::Rectangle*>(&self->field_rectangle_95), slint::cbindgen_private::Orientation::Vertical, -1, &self->globals->window().window_handle(), self->self_weak.lock()->into_dyn(), self->tree_index_of_first_child + 8 - 1)) ) }.data(), 3),[&](const auto &a_0, const auto &a_1){ slint::cbindgen_private::Padding o{}; o.begin = a_0; o.end = a_1; return o; }(0, 0));
                        });
    self->field_empty_89_empty_96_layout_cache.set_binding([this]() {
                            [[maybe_unused]] auto self = this;
                            return slint::private_api::solve_box_layout([&](const auto &a_0, const auto &a_1, const auto &a_2, const auto &a_3, const auto &a_4){ slint::cbindgen_private::BoxLayoutData o{}; o.alignment = a_0; o.cells = a_1; o.padding = a_2; o.size = a_3; o.spacing = a_4; return o; }(slint::cbindgen_private::LayoutAlignment::Stretch, slint::private_api::make_slice<slint::cbindgen_private::LayoutItemInfo>(std::array<slint::cbindgen_private::LayoutItemInfo, 3>{ slint::cbindgen_private::LayoutItemInfo ( [&](const auto &a_0){ slint::cbindgen_private::LayoutItemInfo o{}; o.constraint = a_0; return o; }(self->field_empty_89_empty_97_layoutinfo_h.get()) ), slint::cbindgen_private::LayoutItemInfo ( [&](const auto &a_0){ slint::cbindgen_private::LayoutItemInfo o{}; o.constraint = a_0; return o; }(self->field_empty_89_empty_100_layoutinfo_h.get()) ), slint::cbindgen_private::LayoutItemInfo ( [&](const auto &a_0){ slint::cbindgen_private::LayoutItemInfo o{}; o.constraint = a_0; return o; }(self->field_empty_89_empty_103_layoutinfo_h.get()) ) }.data(), 3), [&](const auto &a_0, const auto &a_1){ slint::cbindgen_private::Padding o{}; o.begin = a_0; o.end = a_1; return o; }(0, 0), self->field_empty_89_width.get(), 24),slint::private_api::make_slice<int>(std::array<int, 0>{  }.data(), 0));
                        });
    self->field_empty_89_empty_96_layoutinfo_h.set_binding([this]() {
                            [[maybe_unused]] auto self = this;
                            return slint::private_api::box_layout_info(slint::private_api::make_slice<slint::cbindgen_private::LayoutItemInfo>(std::array<slint::cbindgen_private::LayoutItemInfo, 3>{ slint::cbindgen_private::LayoutItemInfo ( [&](const auto &a_0){ slint::cbindgen_private::LayoutItemInfo o{}; o.constraint = a_0; return o; }(self->field_empty_89_empty_97_layoutinfo_h.get()) ), slint::cbindgen_private::LayoutItemInfo ( [&](const auto &a_0){ slint::cbindgen_private::LayoutItemInfo o{}; o.constraint = a_0; return o; }(self->field_empty_89_empty_100_layoutinfo_h.get()) ), slint::cbindgen_private::LayoutItemInfo ( [&](const auto &a_0){ slint::cbindgen_private::LayoutItemInfo o{}; o.constraint = a_0; return o; }(self->field_empty_89_empty_103_layoutinfo_h.get()) ) }.data(), 3),24,[&](const auto &a_0, const auto &a_1){ slint::cbindgen_private::Padding o{}; o.begin = a_0; o.end = a_1; return o; }(0, 0),slint::cbindgen_private::LayoutAlignment::Stretch);
                        });
    self->field_empty_89_empty_96_layoutinfo_v.set_binding([this]() {
                            [[maybe_unused]] auto self = this;
                            return slint::private_api::box_layout_info_ortho(slint::private_api::make_slice<slint::cbindgen_private::LayoutItemInfo>(std::array<slint::cbindgen_private::LayoutItemInfo, 3>{ slint::cbindgen_private::LayoutItemInfo ( [&](const auto &a_0){ slint::cbindgen_private::LayoutItemInfo o{}; o.constraint = a_0; return o; }(self->field_empty_89_empty_97_layoutinfo_v.get()) ), slint::cbindgen_private::LayoutItemInfo ( [&](const auto &a_0){ slint::cbindgen_private::LayoutItemInfo o{}; o.constraint = a_0; return o; }(self->field_empty_89_empty_100_layoutinfo_v.get()) ), slint::cbindgen_private::LayoutItemInfo ( [&](const auto &a_0){ slint::cbindgen_private::LayoutItemInfo o{}; o.constraint = a_0; return o; }(self->field_empty_89_empty_103_layoutinfo_v.get()) ) }.data(), 3),[&](const auto &a_0, const auto &a_1){ slint::cbindgen_private::Padding o{}; o.begin = a_0; o.end = a_1; return o; }(0, 0));
                        });
    self->field_empty_89_empty_97_layout_cache.set_binding([this]() {
                            [[maybe_unused]] auto self = this;
                            return slint::private_api::solve_box_layout([&](const auto &a_0, const auto &a_1, const auto &a_2, const auto &a_3, const auto &a_4){ slint::cbindgen_private::BoxLayoutData o{}; o.alignment = a_0; o.cells = a_1; o.padding = a_2; o.size = a_3; o.spacing = a_4; return o; }(slint::cbindgen_private::LayoutAlignment::Start, slint::private_api::make_slice<slint::cbindgen_private::LayoutItemInfo>(std::array<slint::cbindgen_private::LayoutItemInfo, 2>{ slint::cbindgen_private::LayoutItemInfo ( [&](const auto &a_0){ slint::cbindgen_private::LayoutItemInfo o{}; o.constraint = a_0; return o; }([&]{ [[maybe_unused]] auto layout_info = slint::private_api::item_layout_info(SLINT_GET_ITEM_VTABLE(BasicBorderRectangleVTable), const_cast<slint::cbindgen_private::BasicBorderRectangle*>(&self->field_rectangle_98), slint::cbindgen_private::Orientation::Horizontal, -1, &self->globals->window().window_handle(), self->self_weak.lock()->into_dyn(), self->tree_index_of_first_child + 12 - 1);;return [&](const auto &a_0, const auto &a_1, const auto &a_2, const auto &a_3, const auto &a_4, const auto &a_5){ slint::cbindgen_private::LayoutInfo o{}; o.max = a_0; o.max_percent = a_1; o.min = a_2; o.min_percent = a_3; o.preferred = a_4; o.stretch = a_5; return o; }(9, layout_info.max_percent, 9, layout_info.min_percent, layout_info.preferred, layout_info.stretch); }()) ), slint::cbindgen_private::LayoutItemInfo ( [&](const auto &a_0){ slint::cbindgen_private::LayoutItemInfo o{}; o.constraint = a_0; return o; }(slint::private_api::item_layout_info(SLINT_GET_ITEM_VTABLE(SimpleTextVTable), const_cast<slint::cbindgen_private::SimpleText*>(&self->field_text_99), slint::cbindgen_private::Orientation::Horizontal, -1, &self->globals->window().window_handle(), self->self_weak.lock()->into_dyn(), self->tree_index_of_first_child + 13 - 1)) ) }.data(), 2), [&](const auto &a_0, const auto &a_1){ slint::cbindgen_private::Padding o{}; o.begin = a_0; o.end = a_1; return o; }(0, 0), self->field_empty_89_empty_96_layout_cache.get()[1], 6),slint::private_api::make_slice<int>(std::array<int, 0>{  }.data(), 0));
                        });
    self->field_empty_89_empty_97_layoutinfo_h.set_binding([this]() {
                            [[maybe_unused]] auto self = this;
                            return slint::private_api::box_layout_info(slint::private_api::make_slice<slint::cbindgen_private::LayoutItemInfo>(std::array<slint::cbindgen_private::LayoutItemInfo, 2>{ slint::cbindgen_private::LayoutItemInfo ( [&](const auto &a_0){ slint::cbindgen_private::LayoutItemInfo o{}; o.constraint = a_0; return o; }([&]{ [[maybe_unused]] auto layout_info = slint::private_api::item_layout_info(SLINT_GET_ITEM_VTABLE(BasicBorderRectangleVTable), const_cast<slint::cbindgen_private::BasicBorderRectangle*>(&self->field_rectangle_98), slint::cbindgen_private::Orientation::Horizontal, -1, &self->globals->window().window_handle(), self->self_weak.lock()->into_dyn(), self->tree_index_of_first_child + 12 - 1);;return [&](const auto &a_0, const auto &a_1, const auto &a_2, const auto &a_3, const auto &a_4, const auto &a_5){ slint::cbindgen_private::LayoutInfo o{}; o.max = a_0; o.max_percent = a_1; o.min = a_2; o.min_percent = a_3; o.preferred = a_4; o.stretch = a_5; return o; }(9, layout_info.max_percent, 9, layout_info.min_percent, layout_info.preferred, layout_info.stretch); }()) ), slint::cbindgen_private::LayoutItemInfo ( [&](const auto &a_0){ slint::cbindgen_private::LayoutItemInfo o{}; o.constraint = a_0; return o; }(slint::private_api::item_layout_info(SLINT_GET_ITEM_VTABLE(SimpleTextVTable), const_cast<slint::cbindgen_private::SimpleText*>(&self->field_text_99), slint::cbindgen_private::Orientation::Horizontal, -1, &self->globals->window().window_handle(), self->self_weak.lock()->into_dyn(), self->tree_index_of_first_child + 13 - 1)) ) }.data(), 2),6,[&](const auto &a_0, const auto &a_1){ slint::cbindgen_private::Padding o{}; o.begin = a_0; o.end = a_1; return o; }(0, 0),slint::cbindgen_private::LayoutAlignment::Start);
                        });
    self->field_empty_89_empty_97_layoutinfo_v.set_binding([this]() {
                            [[maybe_unused]] auto self = this;
                            return slint::private_api::box_layout_info_ortho(slint::private_api::make_slice<slint::cbindgen_private::LayoutItemInfo>(std::array<slint::cbindgen_private::LayoutItemInfo, 2>{ slint::cbindgen_private::LayoutItemInfo ( [&](const auto &a_0){ slint::cbindgen_private::LayoutItemInfo o{}; o.constraint = a_0; return o; }([&]{ [[maybe_unused]] auto layout_info = slint::private_api::item_layout_info(SLINT_GET_ITEM_VTABLE(BasicBorderRectangleVTable), const_cast<slint::cbindgen_private::BasicBorderRectangle*>(&self->field_rectangle_98), slint::cbindgen_private::Orientation::Vertical, -1, &self->globals->window().window_handle(), self->self_weak.lock()->into_dyn(), self->tree_index_of_first_child + 12 - 1);;return [&](const auto &a_0, const auto &a_1, const auto &a_2, const auto &a_3, const auto &a_4, const auto &a_5){ slint::cbindgen_private::LayoutInfo o{}; o.max = a_0; o.max_percent = a_1; o.min = a_2; o.min_percent = a_3; o.preferred = a_4; o.stretch = a_5; return o; }(9, layout_info.max_percent, 9, layout_info.min_percent, layout_info.preferred, layout_info.stretch); }()) ), slint::cbindgen_private::LayoutItemInfo ( [&](const auto &a_0){ slint::cbindgen_private::LayoutItemInfo o{}; o.constraint = a_0; return o; }(slint::private_api::item_layout_info(SLINT_GET_ITEM_VTABLE(SimpleTextVTable), const_cast<slint::cbindgen_private::SimpleText*>(&self->field_text_99), slint::cbindgen_private::Orientation::Vertical, -1, &self->globals->window().window_handle(), self->self_weak.lock()->into_dyn(), self->tree_index_of_first_child + 13 - 1)) ) }.data(), 2),[&](const auto &a_0, const auto &a_1){ slint::cbindgen_private::Padding o{}; o.begin = a_0; o.end = a_1; return o; }(0, 0));
                        });
    self->field_empty_89_layout_cache.set_binding([this]() {
                            [[maybe_unused]] auto self = this;
                            return slint::private_api::solve_box_layout([&](const auto &a_0, const auto &a_1, const auto &a_2, const auto &a_3, const auto &a_4){ slint::cbindgen_private::BoxLayoutData o{}; o.alignment = a_0; o.cells = a_1; o.padding = a_2; o.size = a_3; o.spacing = a_4; return o; }(slint::cbindgen_private::LayoutAlignment::Stretch, slint::private_api::make_slice<slint::cbindgen_private::LayoutItemInfo>(std::array<slint::cbindgen_private::LayoutItemInfo, 4>{ slint::cbindgen_private::LayoutItemInfo ( [&](const auto &a_0){ slint::cbindgen_private::LayoutItemInfo o{}; o.constraint = a_0; return o; }([&]{ [[maybe_unused]] auto layout_info = ([&](const auto &a_0, const auto &a_1, const auto &a_2, const auto &a_3, const auto &a_4, const auto &a_5){ slint::cbindgen_private::LayoutInfo o{}; o.max = a_0; o.max_percent = a_1; o.min = a_2; o.min_percent = a_3; o.preferred = a_4; o.stretch = a_5; return o; }(+3.4028234663852886e38, 100, 0, 0, 0, 1) + self->field_empty_89_empty_92_layoutinfo_v.get());;return [&](const auto &a_0, const auto &a_1, const auto &a_2, const auto &a_3, const auto &a_4, const auto &a_5){ slint::cbindgen_private::LayoutInfo o{}; o.max = a_0; o.max_percent = a_1; o.min = a_2; o.min_percent = a_3; o.preferred = a_4; o.stretch = a_5; return o; }(8, layout_info.max_percent, 8, layout_info.min_percent, layout_info.preferred, layout_info.stretch); }()) ), slint::cbindgen_private::LayoutItemInfo ( [&](const auto &a_0){ slint::cbindgen_private::LayoutItemInfo o{}; o.constraint = a_0; return o; }(self->field_empty_89_empty_96_layoutinfo_v.get()) ), slint::cbindgen_private::LayoutItemInfo ( [&](const auto &a_0){ slint::cbindgen_private::LayoutItemInfo o{}; o.constraint = a_0; return o; }([&]{ [[maybe_unused]] auto layout_info = slint::private_api::item_layout_info(SLINT_GET_ITEM_VTABLE(RectangleVTable), const_cast<slint::cbindgen_private::Rectangle*>(&self->field_rectangle_106), slint::cbindgen_private::Orientation::Vertical, -1, &self->globals->window().window_handle(), self->self_weak.lock()->into_dyn(), self->tree_index_of_first_child + 3 - 1);;return [&](const auto &a_0, const auto &a_1, const auto &a_2, const auto &a_3, const auto &a_4, const auto &a_5){ slint::cbindgen_private::LayoutInfo o{}; o.max = a_0; o.max_percent = a_1; o.min = a_2; o.min_percent = a_3; o.preferred = a_4; o.stretch = a_5; return o; }(1, layout_info.max_percent, 1, layout_info.min_percent, layout_info.preferred, layout_info.stretch); }()) ), slint::cbindgen_private::LayoutItemInfo ( [&](const auto &a_0){ slint::cbindgen_private::LayoutItemInfo o{}; o.constraint = a_0; return o; }(self->field_empty_89_empty_107_layoutinfo_v.get()) ) }.data(), 4), [&](const auto &a_0, const auto &a_1){ slint::cbindgen_private::Padding o{}; o.begin = a_0; o.end = a_1; return o; }(0, 0), slint::private_api::optional_or_default(slint::private_api::optional_transform(self->parent.lock(), [&](auto&&x) { return slint::private_api::layout_cache_access(x->field_root_32_empty_82_layout_cache.get(), 5, 0, 2); })), 14),slint::private_api::make_slice<int>(std::array<int, 0>{  }.data(), 0));
                        });
    self->field_empty_89_layoutinfo_h.set_binding([this]() {
                            [[maybe_unused]] auto self = this;
                            return slint::private_api::box_layout_info_ortho(slint::private_api::make_slice<slint::cbindgen_private::LayoutItemInfo>(std::array<slint::cbindgen_private::LayoutItemInfo, 4>{ slint::cbindgen_private::LayoutItemInfo ( [&](const auto &a_0){ slint::cbindgen_private::LayoutItemInfo o{}; o.constraint = a_0; return o; }(([&](const auto &a_0, const auto &a_1, const auto &a_2, const auto &a_3, const auto &a_4, const auto &a_5){ slint::cbindgen_private::LayoutInfo o{}; o.max = a_0; o.max_percent = a_1; o.min = a_2; o.min_percent = a_3; o.preferred = a_4; o.stretch = a_5; return o; }(+3.4028234663852886e38, 100, 0, 0, 0, 1) + self->field_empty_89_empty_92_layoutinfo_h.get())) ), slint::cbindgen_private::LayoutItemInfo ( [&](const auto &a_0){ slint::cbindgen_private::LayoutItemInfo o{}; o.constraint = a_0; return o; }(self->field_empty_89_empty_96_layoutinfo_h.get()) ), slint::cbindgen_private::LayoutItemInfo ( [&](const auto &a_0){ slint::cbindgen_private::LayoutItemInfo o{}; o.constraint = a_0; return o; }(slint::private_api::item_layout_info(SLINT_GET_ITEM_VTABLE(RectangleVTable), const_cast<slint::cbindgen_private::Rectangle*>(&self->field_rectangle_106), slint::cbindgen_private::Orientation::Horizontal, -1, &self->globals->window().window_handle(), self->self_weak.lock()->into_dyn(), self->tree_index_of_first_child + 3 - 1)) ), slint::cbindgen_private::LayoutItemInfo ( [&](const auto &a_0){ slint::cbindgen_private::LayoutItemInfo o{}; o.constraint = a_0; return o; }(self->field_empty_89_empty_107_layoutinfo_h.get()) ) }.data(), 4),[&](const auto &a_0, const auto &a_1){ slint::cbindgen_private::Padding o{}; o.begin = a_0; o.end = a_1; return o; }(0, 0));
                        });
    self->field_empty_89_layoutinfo_v.set_binding([this]() {
                            [[maybe_unused]] auto self = this;
                            return slint::private_api::box_layout_info(slint::private_api::make_slice<slint::cbindgen_private::LayoutItemInfo>(std::array<slint::cbindgen_private::LayoutItemInfo, 4>{ slint::cbindgen_private::LayoutItemInfo ( [&](const auto &a_0){ slint::cbindgen_private::LayoutItemInfo o{}; o.constraint = a_0; return o; }([&]{ [[maybe_unused]] auto layout_info = ([&](const auto &a_0, const auto &a_1, const auto &a_2, const auto &a_3, const auto &a_4, const auto &a_5){ slint::cbindgen_private::LayoutInfo o{}; o.max = a_0; o.max_percent = a_1; o.min = a_2; o.min_percent = a_3; o.preferred = a_4; o.stretch = a_5; return o; }(+3.4028234663852886e38, 100, 0, 0, 0, 1) + self->field_empty_89_empty_92_layoutinfo_v.get());;return [&](const auto &a_0, const auto &a_1, const auto &a_2, const auto &a_3, const auto &a_4, const auto &a_5){ slint::cbindgen_private::LayoutInfo o{}; o.max = a_0; o.max_percent = a_1; o.min = a_2; o.min_percent = a_3; o.preferred = a_4; o.stretch = a_5; return o; }(8, layout_info.max_percent, 8, layout_info.min_percent, layout_info.preferred, layout_info.stretch); }()) ), slint::cbindgen_private::LayoutItemInfo ( [&](const auto &a_0){ slint::cbindgen_private::LayoutItemInfo o{}; o.constraint = a_0; return o; }(self->field_empty_89_empty_96_layoutinfo_v.get()) ), slint::cbindgen_private::LayoutItemInfo ( [&](const auto &a_0){ slint::cbindgen_private::LayoutItemInfo o{}; o.constraint = a_0; return o; }([&]{ [[maybe_unused]] auto layout_info = slint::private_api::item_layout_info(SLINT_GET_ITEM_VTABLE(RectangleVTable), const_cast<slint::cbindgen_private::Rectangle*>(&self->field_rectangle_106), slint::cbindgen_private::Orientation::Vertical, -1, &self->globals->window().window_handle(), self->self_weak.lock()->into_dyn(), self->tree_index_of_first_child + 3 - 1);;return [&](const auto &a_0, const auto &a_1, const auto &a_2, const auto &a_3, const auto &a_4, const auto &a_5){ slint::cbindgen_private::LayoutInfo o{}; o.max = a_0; o.max_percent = a_1; o.min = a_2; o.min_percent = a_3; o.preferred = a_4; o.stretch = a_5; return o; }(1, layout_info.max_percent, 1, layout_info.min_percent, layout_info.preferred, layout_info.stretch); }()) ), slint::cbindgen_private::LayoutItemInfo ( [&](const auto &a_0){ slint::cbindgen_private::LayoutItemInfo o{}; o.constraint = a_0; return o; }(self->field_empty_89_empty_107_layoutinfo_v.get()) ) }.data(), 4),14,[&](const auto &a_0, const auto &a_1){ slint::cbindgen_private::Padding o{}; o.begin = a_0; o.end = a_1; return o; }(0, 0),slint::cbindgen_private::LayoutAlignment::Stretch);
                        });
    self->field_empty_89_rectangle_90_width.set_binding([this]() {
                            [[maybe_unused]] auto self = this;
                            return ((((slint::private_api::optional_or_default(slint::private_api::optional_transform(self->parent.lock(), [&](auto&&x) { return x->field_flickable_45.viewport_width.get(); })) -(float) 64) -(float) 64) -(float) 26) -(float) 26);
                        });
    self->field_empty_89_width.set_binding([this]() {
                            [[maybe_unused]] auto self = this;
                            return ((((slint::private_api::optional_or_default(slint::private_api::optional_transform(self->parent.lock(), [&](auto&&x) { return x->field_flickable_45.viewport_width.get(); })) -(float) 64) -(float) 64) -(float) 26) -(float) 26);
                        });
    self->field_rectangle_90.background.set(slint::Brush(slint::Color::from_argb_encoded(+4.28273033e9)));
    self->field_rectangle_90.border_radius.set(4);
    self->field__clip_91.border_bottom_left_radius.set(4);
    self->field__clip_91.border_bottom_right_radius.set(4);
    self->field__clip_91.border_top_left_radius.set(4);
    self->field__clip_91.border_top_right_radius.set(4);
    self->field__clip_91.clip.set(true);
    self->field_rectangle_93.background.set(slint::Brush(slint::Color::from_argb_encoded(+4.285296774e9)));
    self->field_rectangle_94.background.set(slint::Brush(slint::Color::from_argb_encoded(+4.287214842e9)));
    self->field_rectangle_95.background.set(slint::Brush(slint::Color::from_argb_encoded(+4.291536631e9)));
    self->field_rectangle_98.background.set(slint::Brush(slint::Color::from_argb_encoded(+4.285296774e9)));
    self->field_rectangle_98.border_radius.set(4.5);
    self->field_text_99.color.set(slint::Brush(slint::Color::from_argb_encoded(+4.289113544e9)));
    self->field_text_99.font_size.set(12);
    self->field_text_99.height.set_binding([this]() {
                            [[maybe_unused]] auto self = this;
                            return self->field_empty_89_layout_cache.get()[3];
                        });
    self->field_text_99.text.set_binding([this]() {
                            [[maybe_unused]] auto self = this;
                            return (slint::SharedString(u8"Already on disk: ") + slint::private_api::optional_or_default(slint::private_api::optional_transform(self->parent.lock(), [&](auto&&x) { return x->field_root_32_details.get(); })).installed_deps_size_str);
                        });
    self->field_text_99.width.set_binding([this]() {
                            [[maybe_unused]] auto self = this;
                            return self->field_empty_89_empty_97_layout_cache.get()[3];
                        });
    self->field_rectangle_101.background.set(slint::Brush(slint::Color::from_argb_encoded(+4.287214842e9)));
    self->field_rectangle_101.border_radius.set(4.5);
    self->field_text_102.color.set(slint::Brush(slint::Color::from_argb_encoded(+4.289113544e9)));
    self->field_text_102.font_size.set(12);
    self->field_text_102.height.set_binding([this]() {
                            [[maybe_unused]] auto self = this;
                            return self->field_empty_89_layout_cache.get()[3];
                        });
    self->field_text_102.text.set_binding([this]() {
                            [[maybe_unused]] auto self = this;
                            return (slint::SharedString(u8"New dependencies: ") + slint::private_api::optional_or_default(slint::private_api::optional_transform(self->parent.lock(), [&](auto&&x) { return x->field_root_32_details.get(); })).new_deps_size_str);
                        });
    self->field_text_102.width.set_binding([this]() {
                            [[maybe_unused]] auto self = this;
                            return self->field_empty_89_empty_100_layout_cache.get()[3];
                        });
    self->field_rectangle_104.background.set(slint::Brush(slint::Color::from_argb_encoded(+4.291536631e9)));
    self->field_rectangle_104.border_radius.set(4.5);
    self->field_text_105.color.set(slint::Brush(slint::Color::from_argb_encoded(+4.289113544e9)));
    self->field_text_105.font_size.set(12);
    self->field_text_105.height.set_binding([this]() {
                            [[maybe_unused]] auto self = this;
                            return self->field_empty_89_layout_cache.get()[3];
                        });
    self->field_text_105.text.set_binding([this]() {
                            [[maybe_unused]] auto self = this;
                            return (slint::SharedString(u8"App itself: ") + slint::private_api::optional_or_default(slint::private_api::optional_transform(self->parent.lock(), [&](auto&&x) { return x->field_root_32_details.get(); })).app_size_str);
                        });
    self->field_text_105.width.set_binding([this]() {
                            [[maybe_unused]] auto self = this;
                            return self->field_empty_89_empty_103_layout_cache.get()[3];
                        });
    self->field_rectangle_106.background.set(slint::Brush(slint::Color::from_argb_encoded(+4.281414212e9)));
    self->field_text_109.color.set(slint::Brush(slint::Color::from_argb_encoded(+4.2865471e9)));
    self->field_text_109.font_size.set(11);
    self->field_text_109.height.set_binding([this]() {
                            [[maybe_unused]] auto self = this;
                            return self->field_empty_89_empty_108_layout_cache.get()[1];
                        });
    self->field_text_109.text.set(slint::SharedString(u8"Total Download"));
    self->field_text_109.width.set_binding([this]() {
                            [[maybe_unused]] auto self = this;
                            return self->field_empty_89_empty_107_layout_cache.get()[1];
                        });
    self->field_text_110.color.set(slint::Brush(slint::Color::from_argb_encoded(+4.291679988e9)));
    self->field_text_110.font_size.set(17);
    self->field_text_110.font_weight.set(static_cast<int>(700));
    self->field_text_110.height.set_binding([this]() {
                            [[maybe_unused]] auto self = this;
                            return self->field_empty_89_empty_108_layout_cache.get()[3];
                        });
    self->field_text_110.text.set_binding([this]() {
                            [[maybe_unused]] auto self = this;
                            return slint::private_api::optional_or_default(slint::private_api::optional_transform(self->parent.lock(), [&](auto&&x) { return x->field_root_32_details.get(); })).total_download_str;
                        });
    self->field_text_110.width.set_binding([this]() {
                            [[maybe_unused]] auto self = this;
                            return self->field_empty_89_empty_107_layout_cache.get()[1];
                        });
    self->field_text_113.color.set(slint::Brush(slint::Color::from_argb_encoded(+4.2865471e9)));
    self->field_text_113.font_size.set(11);
    self->field_text_113.height.set_binding([this]() {
                            [[maybe_unused]] auto self = this;
                            return self->field_empty_89_empty_112_layout_cache.get()[1];
                        });
    self->field_text_113.horizontal_alignment.set(slint::cbindgen_private::TextHorizontalAlignment::Center);
    self->field_text_113.text.set(slint::SharedString(u8"Total Installed"));
    self->field_text_113.width.set_binding([this]() {
                            [[maybe_unused]] auto self = this;
                            return self->field_empty_89_empty_107_layout_cache.get()[5];
                        });
    self->field_text_114.color.set(slint::Brush(slint::Color::from_argb_encoded(+4.291679988e9)));
    self->field_text_114.font_size.set(17);
    self->field_text_114.font_weight.set(static_cast<int>(700));
    self->field_text_114.height.set_binding([this]() {
                            [[maybe_unused]] auto self = this;
                            return self->field_empty_89_empty_112_layout_cache.get()[3];
                        });
    self->field_text_114.horizontal_alignment.set(slint::cbindgen_private::TextHorizontalAlignment::Center);
    self->field_text_114.text.set_binding([this]() {
                            [[maybe_unused]] auto self = this;
                            return slint::private_api::optional_or_default(slint::private_api::optional_transform(self->parent.lock(), [&](auto&&x) { return x->field_root_32_details.get(); })).total_installed_str;
                        });
    self->field_text_114.width.set_binding([this]() {
                            [[maybe_unused]] auto self = this;
                            return self->field_empty_89_empty_107_layout_cache.get()[5];
                        });
    self->field_text_117.color.set(slint::Brush(slint::Color::from_argb_encoded(+4.2865471e9)));
    self->field_text_117.font_size.set(11);
    self->field_text_117.height.set_binding([this]() {
                            [[maybe_unused]] auto self = this;
                            return self->field_empty_89_empty_116_layout_cache.get()[1];
                        });
    self->field_text_117.horizontal_alignment.set(slint::cbindgen_private::TextHorizontalAlignment::Right);
    self->field_text_117.text.set(slint::SharedString(u8"Net Upgrade"));
    self->field_text_117.width.set_binding([this]() {
                            [[maybe_unused]] auto self = this;
                            return self->field_empty_89_empty_107_layout_cache.get()[9];
                        });
    self->field_text_118.color.set_binding([this]() {
                            [[maybe_unused]] auto self = this;
                            return slint::Brush(slint::private_api::optional_or_default(slint::private_api::optional_transform(self->parent.lock(), [&](auto&&x) { return x->field_root_32_accent.get(); })));
                        });
    self->field_text_118.font_size.set(17);
    self->field_text_118.font_weight.set(static_cast<int>(700));
    self->field_text_118.height.set_binding([this]() {
                            [[maybe_unused]] auto self = this;
                            return self->field_empty_89_empty_116_layout_cache.get()[3];
                        });
    self->field_text_118.horizontal_alignment.set(slint::cbindgen_private::TextHorizontalAlignment::Right);
    self->field_text_118.text.set_binding([this]() {
                            [[maybe_unused]] auto self = this;
                            return slint::private_api::optional_or_default(slint::private_api::optional_transform(self->parent.lock(), [&](auto&&x) { return x->field_root_32_details.get(); })).net_upgrade_str;
                        });
    self->field_text_118.width.set_binding([this]() {
                            [[maybe_unused]] auto self = this;
                            return self->field_empty_89_empty_107_layout_cache.get()[9];
                        });
    self->field_rectangle_90.background.set_constant();
    self->field_rectangle_90.border_color.set_constant();
    self->field_rectangle_90.border_radius.set_constant();
    self->field_rectangle_90.border_width.set_constant();
    self->field__clip_91.border_bottom_left_radius.set_constant();
    self->field__clip_91.border_bottom_right_radius.set_constant();
    self->field__clip_91.border_top_left_radius.set_constant();
    self->field__clip_91.border_top_right_radius.set_constant();
    self->field__clip_91.border_width.set_constant();
    self->field_rectangle_93.background.set_constant();
    self->field_rectangle_94.background.set_constant();
    self->field_rectangle_95.background.set_constant();
    self->field_rectangle_98.background.set_constant();
    self->field_rectangle_98.border_color.set_constant();
    self->field_rectangle_98.border_radius.set_constant();
    self->field_rectangle_98.border_width.set_constant();
    self->field_text_99.color.set_constant();
    self->field_text_99.font_size.set_constant();
    self->field_text_99.font_weight.set_constant();
    self->field_text_99.horizontal_alignment.set_constant();
    self->field_text_99.vertical_alignment.set_constant();
    self->field_rectangle_101.background.set_constant();
    self->field_rectangle_101.border_color.set_constant();
    self->field_rectangle_101.border_radius.set_constant();
    self->field_rectangle_101.border_width.set_constant();
    self->field_text_102.color.set_constant();
    self->field_text_102.font_size.set_constant();
    self->field_text_102.font_weight.set_constant();
    self->field_text_102.horizontal_alignment.set_constant();
    self->field_text_102.vertical_alignment.set_constant();
    self->field_rectangle_104.background.set_constant();
    self->field_rectangle_104.border_color.set_constant();
    self->field_rectangle_104.border_radius.set_constant();
    self->field_rectangle_104.border_width.set_constant();
    self->field_text_105.color.set_constant();
    self->field_text_105.font_size.set_constant();
    self->field_text_105.font_weight.set_constant();
    self->field_text_105.horizontal_alignment.set_constant();
    self->field_text_105.vertical_alignment.set_constant();
    self->field_rectangle_106.background.set_constant();
    self->field_text_109.color.set_constant();
    self->field_text_109.font_size.set_constant();
    self->field_text_109.font_weight.set_constant();
    self->field_text_109.horizontal_alignment.set_constant();
    self->field_text_109.text.set_constant();
    self->field_text_109.vertical_alignment.set_constant();
    self->field_text_110.color.set_constant();
    self->field_text_110.font_size.set_constant();
    self->field_text_110.font_weight.set_constant();
    self->field_text_110.horizontal_alignment.set_constant();
    self->field_text_110.vertical_alignment.set_constant();
    self->field_text_113.color.set_constant();
    self->field_text_113.font_size.set_constant();
    self->field_text_113.font_weight.set_constant();
    self->field_text_113.horizontal_alignment.set_constant();
    self->field_text_113.text.set_constant();
    self->field_text_113.vertical_alignment.set_constant();
    self->field_text_114.color.set_constant();
    self->field_text_114.font_size.set_constant();
    self->field_text_114.font_weight.set_constant();
    self->field_text_114.horizontal_alignment.set_constant();
    self->field_text_114.vertical_alignment.set_constant();
    self->field_text_117.color.set_constant();
    self->field_text_117.font_size.set_constant();
    self->field_text_117.font_weight.set_constant();
    self->field_text_117.horizontal_alignment.set_constant();
    self->field_text_117.text.set_constant();
    self->field_text_117.vertical_alignment.set_constant();
    self->field_text_118.font_size.set_constant();
    self->field_text_118.font_weight.set_constant();
    self->field_text_118.horizontal_alignment.set_constant();
    self->field_text_118.vertical_alignment.set_constant();
}

auto Component_empty_89::user_init () -> void{
    [[maybe_unused]] auto self = this;
}

auto Component_empty_89::layout_info (slint::cbindgen_private::Orientation o) const -> slint::cbindgen_private::LayoutInfo{
    [[maybe_unused]] auto self = this;
    return o == slint::cbindgen_private::Orientation::Horizontal ? self->field_empty_89_layoutinfo_h.get() : self->field_empty_89_layoutinfo_v.get();
}

auto Component_empty_89::item_geometry (uint32_t index) const -> slint::cbindgen_private::Rect{
    [[maybe_unused]] auto self = this;
    switch (index) {
        case 0: return slint::private_api::convert_anonymous_rect(std::make_tuple(float(slint::private_api::optional_or_default(slint::private_api::optional_transform(self->parent.lock(), [&](auto&&x) { return slint::private_api::layout_cache_access(x->field_root_32_empty_82_layout_cache.get(), 5, 0, 2); }))), float(((((slint::private_api::optional_or_default(slint::private_api::optional_transform(self->parent.lock(), [&](auto&&x) { return x->field_flickable_45.viewport_width.get(); })) -(float) 64) -(float) 64) -(float) 26) -(float) 26)), float(26), float(slint::private_api::optional_or_default(slint::private_api::optional_transform(self->parent.lock(), [&](auto&&x) { return slint::private_api::layout_cache_access(x->field_root_32_empty_82_layout_cache.get(), 4, 0, 2); })))));
        case 1: return slint::private_api::convert_anonymous_rect(std::make_tuple(float(8), float(((((slint::private_api::optional_or_default(slint::private_api::optional_transform(self->parent.lock(), [&](auto&&x) { return x->field_flickable_45.viewport_width.get(); })) -(float) 64) -(float) 64) -(float) 26) -(float) 26)), float(0), float(self->field_empty_89_layout_cache.get()[0])));
        case 2: return slint::private_api::convert_anonymous_rect(std::make_tuple(float(self->field_empty_89_layout_cache.get()[3]), float(((((slint::private_api::optional_or_default(slint::private_api::optional_transform(self->parent.lock(), [&](auto&&x) { return x->field_flickable_45.viewport_width.get(); })) -(float) 64) -(float) 64) -(float) 26) -(float) 26)), float(0), float(self->field_empty_89_layout_cache.get()[2])));
        case 3: return slint::private_api::convert_anonymous_rect(std::make_tuple(float(1), float(((((slint::private_api::optional_or_default(slint::private_api::optional_transform(self->parent.lock(), [&](auto&&x) { return x->field_flickable_45.viewport_width.get(); })) -(float) 64) -(float) 64) -(float) 26) -(float) 26)), float(0), float(self->field_empty_89_layout_cache.get()[4])));
        case 4: return slint::private_api::convert_anonymous_rect(std::make_tuple(float(self->field_empty_89_layout_cache.get()[7]), float(((((slint::private_api::optional_or_default(slint::private_api::optional_transform(self->parent.lock(), [&](auto&&x) { return x->field_flickable_45.viewport_width.get(); })) -(float) 64) -(float) 64) -(float) 26) -(float) 26)), float(0), float(self->field_empty_89_layout_cache.get()[6])));
        case 5: return slint::private_api::convert_anonymous_rect(std::make_tuple(float(8), float(self->field_empty_89_width.get()), float(0), float(0)));
        case 6: return slint::private_api::convert_anonymous_rect(std::make_tuple(float(8), float(self->field_empty_89_empty_92_layout_cache.get()[1]), float(self->field_empty_89_empty_92_layout_cache.get()[0]), float(0)));
        case 7: return slint::private_api::convert_anonymous_rect(std::make_tuple(float(8), float(self->field_empty_89_empty_92_layout_cache.get()[3]), float(self->field_empty_89_empty_92_layout_cache.get()[2]), float(0)));
        case 8: return slint::private_api::convert_anonymous_rect(std::make_tuple(float(8), float(self->field_empty_89_empty_92_layout_cache.get()[5]), float(self->field_empty_89_empty_92_layout_cache.get()[4]), float(0)));
        case 9: return slint::private_api::convert_anonymous_rect(std::make_tuple(float(self->field_empty_89_layout_cache.get()[3]), float(self->field_empty_89_empty_96_layout_cache.get()[1]), float(self->field_empty_89_empty_96_layout_cache.get()[0]), float(0)));
        case 10: return slint::private_api::convert_anonymous_rect(std::make_tuple(float(self->field_empty_89_layout_cache.get()[3]), float(self->field_empty_89_empty_96_layout_cache.get()[3]), float(self->field_empty_89_empty_96_layout_cache.get()[2]), float(0)));
        case 11: return slint::private_api::convert_anonymous_rect(std::make_tuple(float(self->field_empty_89_layout_cache.get()[3]), float(self->field_empty_89_empty_96_layout_cache.get()[5]), float(self->field_empty_89_empty_96_layout_cache.get()[4]), float(0)));
        case 12: return slint::private_api::convert_anonymous_rect(std::make_tuple(float(9), float(9), float(self->field_empty_89_empty_97_layout_cache.get()[0]), float(2)));
        case 13: return slint::private_api::convert_anonymous_rect(std::make_tuple(float(self->field_empty_89_layout_cache.get()[3]), float(self->field_empty_89_empty_97_layout_cache.get()[3]), float(self->field_empty_89_empty_97_layout_cache.get()[2]), float(0)));
        case 14: return slint::private_api::convert_anonymous_rect(std::make_tuple(float(9), float(9), float(self->field_empty_89_empty_100_layout_cache.get()[0]), float(2)));
        case 15: return slint::private_api::convert_anonymous_rect(std::make_tuple(float(self->field_empty_89_layout_cache.get()[3]), float(self->field_empty_89_empty_100_layout_cache.get()[3]), float(self->field_empty_89_empty_100_layout_cache.get()[2]), float(0)));
        case 16: return slint::private_api::convert_anonymous_rect(std::make_tuple(float(9), float(9), float(self->field_empty_89_empty_103_layout_cache.get()[0]), float(2)));
        case 17: return slint::private_api::convert_anonymous_rect(std::make_tuple(float(self->field_empty_89_layout_cache.get()[3]), float(self->field_empty_89_empty_103_layout_cache.get()[3]), float(self->field_empty_89_empty_103_layout_cache.get()[2]), float(0)));
        case 18: return slint::private_api::convert_anonymous_rect(std::make_tuple(float(self->field_empty_89_layout_cache.get()[7]), float(self->field_empty_89_empty_107_layout_cache.get()[1]), float(self->field_empty_89_empty_107_layout_cache.get()[0]), float(0)));
        case 19: return slint::private_api::convert_anonymous_rect(std::make_tuple(float(self->field_empty_89_layout_cache.get()[7]), float(self->field_empty_89_empty_107_layout_cache.get()[3]), float(self->field_empty_89_empty_107_layout_cache.get()[2]), float(0)));
        case 20: return slint::private_api::convert_anonymous_rect(std::make_tuple(float(self->field_empty_89_layout_cache.get()[7]), float(self->field_empty_89_empty_107_layout_cache.get()[5]), float(self->field_empty_89_empty_107_layout_cache.get()[4]), float(0)));
        case 21: return slint::private_api::convert_anonymous_rect(std::make_tuple(float(self->field_empty_89_layout_cache.get()[7]), float(self->field_empty_89_empty_107_layout_cache.get()[7]), float(self->field_empty_89_empty_107_layout_cache.get()[6]), float(0)));
        case 22: return slint::private_api::convert_anonymous_rect(std::make_tuple(float(self->field_empty_89_layout_cache.get()[7]), float(self->field_empty_89_empty_107_layout_cache.get()[9]), float(self->field_empty_89_empty_107_layout_cache.get()[8]), float(0)));
        case 23: return slint::private_api::convert_anonymous_rect(std::make_tuple(float(self->field_empty_89_empty_108_layout_cache.get()[1]), float(self->field_empty_89_empty_107_layout_cache.get()[1]), float(0), float(self->field_empty_89_empty_108_layout_cache.get()[0])));
        case 24: return slint::private_api::convert_anonymous_rect(std::make_tuple(float(self->field_empty_89_empty_108_layout_cache.get()[3]), float(self->field_empty_89_empty_107_layout_cache.get()[1]), float(0), float(self->field_empty_89_empty_108_layout_cache.get()[2])));
        case 25: return slint::private_api::convert_anonymous_rect(std::make_tuple(float(self->field_empty_89_empty_112_layout_cache.get()[1]), float(self->field_empty_89_empty_107_layout_cache.get()[5]), float(0), float(self->field_empty_89_empty_112_layout_cache.get()[0])));
        case 26: return slint::private_api::convert_anonymous_rect(std::make_tuple(float(self->field_empty_89_empty_112_layout_cache.get()[3]), float(self->field_empty_89_empty_107_layout_cache.get()[5]), float(0), float(self->field_empty_89_empty_112_layout_cache.get()[2])));
        case 27: return slint::private_api::convert_anonymous_rect(std::make_tuple(float(self->field_empty_89_empty_116_layout_cache.get()[1]), float(self->field_empty_89_empty_107_layout_cache.get()[9]), float(0), float(self->field_empty_89_empty_116_layout_cache.get()[0])));
        case 28: return slint::private_api::convert_anonymous_rect(std::make_tuple(float(self->field_empty_89_empty_116_layout_cache.get()[3]), float(self->field_empty_89_empty_107_layout_cache.get()[9]), float(0), float(self->field_empty_89_empty_116_layout_cache.get()[2])));
    }
    return {};
}

auto Component_empty_89::accessible_role (uint32_t index) const -> slint::cbindgen_private::AccessibleRole{
    [[maybe_unused]] auto self = this;
    switch (index) {
        case 13: return slint::cbindgen_private::AccessibleRole::Text;
        case 15: return slint::cbindgen_private::AccessibleRole::Text;
        case 17: return slint::cbindgen_private::AccessibleRole::Text;
        case 23: return slint::cbindgen_private::AccessibleRole::Text;
        case 24: return slint::cbindgen_private::AccessibleRole::Text;
        case 25: return slint::cbindgen_private::AccessibleRole::Text;
        case 26: return slint::cbindgen_private::AccessibleRole::Text;
        case 27: return slint::cbindgen_private::AccessibleRole::Text;
        case 28: return slint::cbindgen_private::AccessibleRole::Text;
    }
    return {};
}

auto Component_empty_89::accessible_string_property (uint32_t index, slint::cbindgen_private::AccessibleStringProperty what) const -> std::optional<slint::SharedString>{
    [[maybe_unused]] auto self = this;
    switch ((index << 8) | uintptr_t(what)) {
        case (13 << 8) | uintptr_t(slint::cbindgen_private::AccessibleStringProperty::Label): return self->field_text_99.text.get();
        case (15 << 8) | uintptr_t(slint::cbindgen_private::AccessibleStringProperty::Label): return self->field_text_102.text.get();
        case (17 << 8) | uintptr_t(slint::cbindgen_private::AccessibleStringProperty::Label): return self->field_text_105.text.get();
        case (23 << 8) | uintptr_t(slint::cbindgen_private::AccessibleStringProperty::Label): return slint::SharedString(u8"Total Download");
        case (24 << 8) | uintptr_t(slint::cbindgen_private::AccessibleStringProperty::Label): return slint::private_api::optional_or_default(slint::private_api::optional_transform(self->parent.lock(), [&](auto&&x) { return x->field_root_32_details.get(); })).total_download_str;
        case (25 << 8) | uintptr_t(slint::cbindgen_private::AccessibleStringProperty::Label): return slint::SharedString(u8"Total Installed");
        case (26 << 8) | uintptr_t(slint::cbindgen_private::AccessibleStringProperty::Label): return slint::private_api::optional_or_default(slint::private_api::optional_transform(self->parent.lock(), [&](auto&&x) { return x->field_root_32_details.get(); })).total_installed_str;
        case (27 << 8) | uintptr_t(slint::cbindgen_private::AccessibleStringProperty::Label): return slint::SharedString(u8"Net Upgrade");
        case (28 << 8) | uintptr_t(slint::cbindgen_private::AccessibleStringProperty::Label): return slint::private_api::optional_or_default(slint::private_api::optional_transform(self->parent.lock(), [&](auto&&x) { return x->field_root_32_details.get(); })).net_upgrade_str;
    }
    return {};
}

auto Component_empty_89::accessibility_action (uint32_t index, const slint::cbindgen_private::AccessibilityAction &action) const -> void{
    [[maybe_unused]] auto self = this;
    switch ((index << 8) | uintptr_t(action.tag)) {
    }
    return ;
}

auto Component_empty_89::supported_accessibility_actions (uint32_t index) const -> uint32_t{
    [[maybe_unused]] auto self = this;
    switch (index) {
    }
    return {};
}

auto Component_empty_89::element_infos (uint32_t index) const -> std::optional<slint::SharedString>{
    [[maybe_unused]] auto self = this;
    switch (index) {
    }
    return {};
}

auto Component_empty_89::ensure_instantiated () const -> bool{
    [[maybe_unused]] auto self = this;
    bool _changed = false;
    return _changed;
}

auto Component_empty_89::visit_children (slint::private_api::ItemTreeRef component, intptr_t index, slint::private_api::TraversalOrder order, slint::private_api::ItemVisitorRefMut visitor) -> uint64_t{
    static const auto dyn_visit = [] (const void *base,  [[maybe_unused]] slint::private_api::TraversalOrder order, [[maybe_unused]] slint::private_api::ItemVisitorRefMut visitor, [[maybe_unused]] uint32_t dyn_index) -> uint64_t {
        [[maybe_unused]] auto self = reinterpret_cast<const Component_empty_89*>(base);
        std::abort();
    };
    auto self_rc = reinterpret_cast<const Component_empty_89*>(component.instance)->self_weak.lock()->into_dyn();
    return slint::cbindgen_private::slint_visit_item_tree(&self_rc, get_item_tree(component) , index, order, visitor, dyn_visit);
}

auto Component_empty_89::get_item_ref (slint::private_api::ItemTreeRef component, uint32_t index) -> slint::private_api::ItemRef{
    return slint::private_api::get_item_ref(component, get_item_tree(component), item_array(), index);
}

auto Component_empty_89::get_subtree_range ([[maybe_unused]] slint::private_api::ItemTreeRef component, [[maybe_unused]] uint32_t dyn_index) -> slint::private_api::IndexRange{
        std::abort();
}

auto Component_empty_89::get_subtree ([[maybe_unused]] slint::private_api::ItemTreeRef component, [[maybe_unused]] uint32_t dyn_index, [[maybe_unused]] uintptr_t subtree_index, [[maybe_unused]] slint::private_api::ItemTreeWeak *result) -> void{
        std::abort();
}

auto Component_empty_89::get_item_tree (slint::private_api::ItemTreeRef) -> slint::cbindgen_private::Slice<slint::private_api::ItemTreeNode>{
    return item_tree();
}

auto Component_empty_89::parent_node ([[maybe_unused]] slint::private_api::ItemTreeRef component, [[maybe_unused]] slint::private_api::ItemWeak *result) -> void{
    auto self = reinterpret_cast<const Component_empty_89*>(component.instance);
    auto parent = self->parent.lock().value();
    *result = { parent->self_weak, parent->tree_index_of_first_child + 36 };
}

auto Component_empty_89::embed_component ([[maybe_unused]] slint::private_api::ItemTreeRef component, [[maybe_unused]] const slint::private_api::ItemTreeWeak *parent_component, [[maybe_unused]] const uint32_t parent_index) -> bool{
    return false; /* todo! */
}

auto Component_empty_89::subtree_index ([[maybe_unused]] slint::private_api::ItemTreeRef component) -> uintptr_t{
    return std::numeric_limits<uintptr_t>::max();
}

auto Component_empty_89::item_tree () -> slint::cbindgen_private::Slice<slint::private_api::ItemTreeNode>{
    static const slint::private_api::ItemTreeNode children[] {
        slint::private_api::make_item_node(4, 1, 0, 0, false), 
slint::private_api::make_item_node(1, 5, 0, 1, false), 
slint::private_api::make_item_node(3, 9, 0, 2, false), 
slint::private_api::make_item_node(0, 18, 0, 3, false), 
slint::private_api::make_item_node(5, 18, 0, 4, false), 
slint::private_api::make_item_node(3, 6, 1, 5, false), 
slint::private_api::make_item_node(0, 9, 5, 6, false), 
slint::private_api::make_item_node(0, 9, 5, 7, false), 
slint::private_api::make_item_node(0, 9, 5, 8, false), 
slint::private_api::make_item_node(2, 12, 2, 9, false), 
slint::private_api::make_item_node(2, 14, 2, 10, false), 
slint::private_api::make_item_node(2, 16, 2, 11, false), 
slint::private_api::make_item_node(0, 14, 9, 12, false), 
slint::private_api::make_item_node(0, 14, 9, 13, true), 
slint::private_api::make_item_node(0, 16, 10, 14, false), 
slint::private_api::make_item_node(0, 16, 10, 15, true), 
slint::private_api::make_item_node(0, 18, 11, 16, false), 
slint::private_api::make_item_node(0, 18, 11, 17, true), 
slint::private_api::make_item_node(2, 23, 4, 18, false), 
slint::private_api::make_item_node(0, 25, 4, 19, false), 
slint::private_api::make_item_node(2, 25, 4, 20, false), 
slint::private_api::make_item_node(0, 27, 4, 21, false), 
slint::private_api::make_item_node(2, 27, 4, 22, false), 
slint::private_api::make_item_node(0, 25, 18, 23, true), 
slint::private_api::make_item_node(0, 25, 18, 24, true), 
slint::private_api::make_item_node(0, 27, 20, 25, true), 
slint::private_api::make_item_node(0, 27, 20, 26, true), 
slint::private_api::make_item_node(0, 29, 22, 27, true), 
slint::private_api::make_item_node(0, 29, 22, 28, true) };
    return slint::private_api::make_slice(std::span(children));
}

auto Component_empty_89::item_array () -> const slint::private_api::ItemArray{
    static const slint::private_api::ItemArrayEntry items[] {
        { SLINT_GET_ITEM_VTABLE(EmptyVTable),  offsetof(Component_empty_89, field_empty_89) }, 
{ SLINT_GET_ITEM_VTABLE(BasicBorderRectangleVTable),  offsetof(Component_empty_89, field_rectangle_90) }, 
{ SLINT_GET_ITEM_VTABLE(EmptyVTable),  offsetof(Component_empty_89, field_empty_96) }, 
{ SLINT_GET_ITEM_VTABLE(RectangleVTable),  offsetof(Component_empty_89, field_rectangle_106) }, 
{ SLINT_GET_ITEM_VTABLE(EmptyVTable),  offsetof(Component_empty_89, field_empty_107) }, 
{ SLINT_GET_ITEM_VTABLE(ClipVTable),  offsetof(Component_empty_89, field__clip_91) }, 
{ SLINT_GET_ITEM_VTABLE(RectangleVTable),  offsetof(Component_empty_89, field_rectangle_93) }, 
{ SLINT_GET_ITEM_VTABLE(RectangleVTable),  offsetof(Component_empty_89, field_rectangle_94) }, 
{ SLINT_GET_ITEM_VTABLE(RectangleVTable),  offsetof(Component_empty_89, field_rectangle_95) }, 
{ SLINT_GET_ITEM_VTABLE(EmptyVTable),  offsetof(Component_empty_89, field_empty_97) }, 
{ SLINT_GET_ITEM_VTABLE(EmptyVTable),  offsetof(Component_empty_89, field_empty_100) }, 
{ SLINT_GET_ITEM_VTABLE(EmptyVTable),  offsetof(Component_empty_89, field_empty_103) }, 
{ SLINT_GET_ITEM_VTABLE(BasicBorderRectangleVTable),  offsetof(Component_empty_89, field_rectangle_98) }, 
{ SLINT_GET_ITEM_VTABLE(SimpleTextVTable),  offsetof(Component_empty_89, field_text_99) }, 
{ SLINT_GET_ITEM_VTABLE(BasicBorderRectangleVTable),  offsetof(Component_empty_89, field_rectangle_101) }, 
{ SLINT_GET_ITEM_VTABLE(SimpleTextVTable),  offsetof(Component_empty_89, field_text_102) }, 
{ SLINT_GET_ITEM_VTABLE(BasicBorderRectangleVTable),  offsetof(Component_empty_89, field_rectangle_104) }, 
{ SLINT_GET_ITEM_VTABLE(SimpleTextVTable),  offsetof(Component_empty_89, field_text_105) }, 
{ SLINT_GET_ITEM_VTABLE(EmptyVTable),  offsetof(Component_empty_89, field_empty_108) }, 
{ SLINT_GET_ITEM_VTABLE(EmptyVTable),  offsetof(Component_empty_89, field_rectangle_111) }, 
{ SLINT_GET_ITEM_VTABLE(EmptyVTable),  offsetof(Component_empty_89, field_empty_112) }, 
{ SLINT_GET_ITEM_VTABLE(EmptyVTable),  offsetof(Component_empty_89, field_rectangle_115) }, 
{ SLINT_GET_ITEM_VTABLE(EmptyVTable),  offsetof(Component_empty_89, field_empty_116) }, 
{ SLINT_GET_ITEM_VTABLE(SimpleTextVTable),  offsetof(Component_empty_89, field_text_109) }, 
{ SLINT_GET_ITEM_VTABLE(SimpleTextVTable),  offsetof(Component_empty_89, field_text_110) }, 
{ SLINT_GET_ITEM_VTABLE(SimpleTextVTable),  offsetof(Component_empty_89, field_text_113) }, 
{ SLINT_GET_ITEM_VTABLE(SimpleTextVTable),  offsetof(Component_empty_89, field_text_114) }, 
{ SLINT_GET_ITEM_VTABLE(SimpleTextVTable),  offsetof(Component_empty_89, field_text_117) }, 
{ SLINT_GET_ITEM_VTABLE(SimpleTextVTable),  offsetof(Component_empty_89, field_text_118) } };
    return slint::private_api::make_slice(std::span(items));
}

auto Component_empty_89::layout_info ([[maybe_unused]] slint::private_api::ItemTreeRef component, slint::cbindgen_private::Orientation o) -> slint::cbindgen_private::LayoutInfo{
    return reinterpret_cast<const Component_empty_89*>(component.instance)->layout_info(o);
}

auto Component_empty_89::ensure_instantiated ([[maybe_unused]] slint::private_api::ItemTreeRef component) -> bool{
    return reinterpret_cast<const Component_empty_89*>(component.instance)->ensure_instantiated();
}

auto Component_empty_89::item_geometry ([[maybe_unused]] slint::private_api::ItemTreeRef component, uint32_t index) -> slint::cbindgen_private::LogicalRect{
    return reinterpret_cast<const Component_empty_89*>(component.instance)->item_geometry(index);
}

auto Component_empty_89::accessible_role ([[maybe_unused]] slint::private_api::ItemTreeRef component, uint32_t index) -> slint::cbindgen_private::AccessibleRole{
    return reinterpret_cast<const Component_empty_89*>(component.instance)->accessible_role(index);
}

auto Component_empty_89::accessible_string_property ([[maybe_unused]] slint::private_api::ItemTreeRef component, uint32_t index, slint::cbindgen_private::AccessibleStringProperty what, slint::SharedString *result) -> bool{
    if (auto r = reinterpret_cast<const Component_empty_89*>(component.instance)->accessible_string_property(index, what)) { *result = *r; return true; } else { return false; }
}

auto Component_empty_89::accessibility_action ([[maybe_unused]] slint::private_api::ItemTreeRef component, uint32_t index, const slint::cbindgen_private::AccessibilityAction *action) -> void{
    reinterpret_cast<const Component_empty_89*>(component.instance)->accessibility_action(index, *action);
}

auto Component_empty_89::supported_accessibility_actions ([[maybe_unused]] slint::private_api::ItemTreeRef component, uint32_t index) -> uint32_t{
    return reinterpret_cast<const Component_empty_89*>(component.instance)->supported_accessibility_actions(index);
}

auto Component_empty_89::element_infos ([[maybe_unused]] slint::private_api::ItemTreeRef component, [[maybe_unused]] uint32_t index, [[maybe_unused]] slint::SharedString *result) -> bool{
    return false;
}

auto Component_empty_89::window_adapter ([[maybe_unused]] slint::private_api::ItemTreeRef component, [[maybe_unused]] bool do_create, [[maybe_unused]] slint::cbindgen_private::Option<slint::private_api::WindowAdapterRc>* result) -> void{
    *reinterpret_cast<slint::private_api::WindowAdapterRc*>(result) = reinterpret_cast<const Component_empty_89*>(component.instance)->globals->window().window_handle();
}

auto Component_empty_89::create (class DetailsView_root_32 const * parent) -> slint::ComponentHandle<Component_empty_89>{
    auto self_rc = vtable::VRc<slint::private_api::ItemTreeVTable, Component_empty_89>::make();
    auto self = const_cast<Component_empty_89 *>(&*self_rc);
    self->self_weak = vtable::VWeak(self_rc).into_dyn();
    slint::private_api::register_item_tree(&self_rc.into_dyn(), parent->globals->m_window);
    self->init(parent->globals, self->self_weak, 0, 1 , parent);
    return slint::ComponentHandle<Component_empty_89>{ self_rc };
}

Component_empty_89::~Component_empty_89 (){
    if (auto &window = globals->m_window) window->window_handle().unregister_item_tree(this, item_array());
}

auto Component_empty_89::init () -> void{
    user_init();
}

auto Component_empty_89::layout_item_info (slint::cbindgen_private::Orientation o, [[maybe_unused]] std::optional<size_t> child_index) const -> slint::cbindgen_private::LayoutItemInfo{
    return { layout_info({&static_vtable, const_cast<void *>(static_cast<const void *>(this))}, o) };
}

auto Component_empty_89::flexbox_layout_item_info (slint::cbindgen_private::Orientation o, [[maybe_unused]] std::optional<size_t> child_index) const -> slint::cbindgen_private::FlexboxLayoutItemInfo{
    auto base = layout_item_info(o, child_index); return { base.constraint, 0.0f, 0.0f, -1.0f, slint::cbindgen_private::FlexboxLayoutAlignSelf::Auto, 0 };
}

const slint::private_api::ItemTreeVTable Component_deprow_124::static_vtable = { visit_children, get_item_ref, get_subtree_range, get_subtree, get_item_tree, parent_node, embed_component, subtree_index, layout_info, ensure_instantiated, item_geometry, accessible_role, accessible_string_property, accessibility_action, supported_accessibility_actions, element_infos, window_adapter, slint::private_api::drop_in_place<Component_deprow_124>, slint::private_api::dealloc };

auto Component_deprow_124::init (const class SharedGlobals* globals,slint::cbindgen_private::ItemTreeWeak enclosing_component,uint32_t tree_index,uint32_t tree_index_of_first_child,class Component_rectangle_120 const *parent) -> void{
    auto self = this;
    self->self_weak = enclosing_component;
    self->globals = globals;
    this->tree_index_of_first_child = tree_index_of_first_child;
    self->tree_index = tree_index;
    self->parent = vtable::VRcMapped<slint::private_api::ItemTreeVTable, const Component_rectangle_120>(parent->self_weak.lock().value(), parent);
    this->field_deprow_124.init(globals, self_weak.into_dyn(), tree_index, tree_index_of_first_child + 1 - 1);
    self->field_deprow_124.field_root_14_accent.set_binding([this]() {
                            [[maybe_unused]] auto self = this;
                            return slint::private_api::optional_or_default(slint::private_api::optional_transform(slint::private_api::optional_and_then(self->parent.lock(), [&](auto&&x) { return x->parent.lock(); }), [&](auto&&x) { return x->field_root_32_accent.get(); }));
                        });
    self->field_deprow_124.field_root_14_dep.set_binding([this]() {
                            [[maybe_unused]] auto self = this;
                            return self->field_model_data.get();
                        });
    self->field_deprow_124.field_root_14_width.set_binding([this]() {
                            [[maybe_unused]] auto self = this;
                            return ((((slint::private_api::optional_or_default(slint::private_api::optional_transform(slint::private_api::optional_and_then(self->parent.lock(), [&](auto&&x) { return x->parent.lock(); }), [&](auto&&x) { return x->field_flickable_45.viewport_width.get(); })) -(float) 64) -(float) 64) -(float) 26) -(float) 26);
                        });
    self->field_deprow_124.field_root_14_x.set(26);
    self->field_deprow_124.field_root_14_y.set_binding([this]() {
                            [[maybe_unused]] auto self = this;
                            return slint::private_api::optional_or_default(slint::private_api::optional_transform(self->parent.lock(), [&](auto&&x) { return slint::private_api::layout_cache_access(x->field_rectangle_120_empty_121_layout_cache.get(), 4, self->field_model_index.get(), 2); }));
                        });
    self->field_deprow_124.field_root_14_x.set_constant();
}

auto Component_deprow_124::user_init () -> void{
    [[maybe_unused]] auto self = this;
    this->field_deprow_124.user_init();
}

auto Component_deprow_124::layout_info (slint::cbindgen_private::Orientation o) const -> slint::cbindgen_private::LayoutInfo{
    [[maybe_unused]] auto self = this;
    return o == slint::cbindgen_private::Orientation::Horizontal ? ([&](const auto &a_0, const auto &a_1, const auto &a_2, const auto &a_3, const auto &a_4, const auto &a_5){ slint::cbindgen_private::LayoutInfo o{}; o.max = a_0; o.max_percent = a_1; o.min = a_2; o.min_percent = a_3; o.preferred = a_4; o.stretch = a_5; return o; }(+3.4028234663852886e38, 100, 0, 0, 0, 1) + self->field_deprow_124.field_root_14_empty_15_layoutinfo_h.get()) : [&]{ [[maybe_unused]] auto layout_info = ([&](const auto &a_0, const auto &a_1, const auto &a_2, const auto &a_3, const auto &a_4, const auto &a_5){ slint::cbindgen_private::LayoutInfo o{}; o.max = a_0; o.max_percent = a_1; o.min = a_2; o.min_percent = a_3; o.preferred = a_4; o.stretch = a_5; return o; }(+3.4028234663852886e38, 100, 0, 0, 0, 1) + self->field_deprow_124.field_root_14_empty_15_layoutinfo_v.get());;return [&](const auto &a_0, const auto &a_1, const auto &a_2, const auto &a_3, const auto &a_4, const auto &a_5){ slint::cbindgen_private::LayoutInfo o{}; o.max = a_0; o.max_percent = a_1; o.min = a_2; o.min_percent = a_3; o.preferred = a_4; o.stretch = a_5; return o; }(34, layout_info.max_percent, 34, layout_info.min_percent, layout_info.preferred, layout_info.stretch); }();
}

auto Component_deprow_124::item_geometry (uint32_t index) const -> slint::cbindgen_private::Rect{
    [[maybe_unused]] auto self = this;
    switch (index) {
        case 0: return slint::private_api::convert_anonymous_rect(std::make_tuple(float(34), float(((((slint::private_api::optional_or_default(slint::private_api::optional_transform(slint::private_api::optional_and_then(self->parent.lock(), [&](auto&&x) { return x->parent.lock(); }), [&](auto&&x) { return x->field_flickable_45.viewport_width.get(); })) -(float) 64) -(float) 64) -(float) 26) -(float) 26)), float(26), float(self->field_deprow_124.field_root_14_y.get())));
    }
    if (index == 0) {
        return self->field_deprow_124.item_geometry(0);
    } else if (index >= 1 && index < 5) {
        return self->field_deprow_124.item_geometry(index - 0);
    } else return {};
}

auto Component_deprow_124::accessible_role (uint32_t index) const -> slint::cbindgen_private::AccessibleRole{
    [[maybe_unused]] auto self = this;
    switch (index) {
    }
    if (index == 0) {
        return self->field_deprow_124.accessible_role(0);
    } else if (index >= 1 && index < 5) {
        return self->field_deprow_124.accessible_role(index - 0);
    } else return {};
}

auto Component_deprow_124::accessible_string_property (uint32_t index, slint::cbindgen_private::AccessibleStringProperty what) const -> std::optional<slint::SharedString>{
    [[maybe_unused]] auto self = this;
    switch ((index << 8) | uintptr_t(what)) {
    }
    if (index == 0) {
        return self->field_deprow_124.accessible_string_property(0, what);
    } else if (index >= 1 && index < 5) {
        return self->field_deprow_124.accessible_string_property(index - 0, what);
    } else return {};
}

auto Component_deprow_124::accessibility_action (uint32_t index, const slint::cbindgen_private::AccessibilityAction &action) const -> void{
    [[maybe_unused]] auto self = this;
    switch ((index << 8) | uintptr_t(action.tag)) {
    }
    if (index == 0) {
        return self->field_deprow_124.accessibility_action(0, action);
    } else if (index >= 1 && index < 5) {
        return self->field_deprow_124.accessibility_action(index - 0, action);
    } else return ;
}

auto Component_deprow_124::supported_accessibility_actions (uint32_t index) const -> uint32_t{
    [[maybe_unused]] auto self = this;
    switch (index) {
    }
    if (index == 0) {
        return self->field_deprow_124.supported_accessibility_actions(0);
    } else if (index >= 1 && index < 5) {
        return self->field_deprow_124.supported_accessibility_actions(index - 0);
    } else return {};
}

auto Component_deprow_124::element_infos (uint32_t index) const -> std::optional<slint::SharedString>{
    [[maybe_unused]] auto self = this;
    switch (index) {
    }
    if (index == 0) {
        return self->field_deprow_124.element_infos(0);
    } else if (index >= 1 && index < 5) {
        return self->field_deprow_124.element_infos(index - 0);
    } else return {};
}

auto Component_deprow_124::ensure_instantiated () const -> bool{
    [[maybe_unused]] auto self = this;
    bool _changed = false;
    return _changed;
}

auto Component_deprow_124::visit_children (slint::private_api::ItemTreeRef component, intptr_t index, slint::private_api::TraversalOrder order, slint::private_api::ItemVisitorRefMut visitor) -> uint64_t{
    static const auto dyn_visit = [] (const void *base,  [[maybe_unused]] slint::private_api::TraversalOrder order, [[maybe_unused]] slint::private_api::ItemVisitorRefMut visitor, [[maybe_unused]] uint32_t dyn_index) -> uint64_t {
        [[maybe_unused]] auto self = reinterpret_cast<const Component_deprow_124*>(base);
        std::abort();
    };
    auto self_rc = reinterpret_cast<const Component_deprow_124*>(component.instance)->self_weak.lock()->into_dyn();
    return slint::cbindgen_private::slint_visit_item_tree(&self_rc, get_item_tree(component) , index, order, visitor, dyn_visit);
}

auto Component_deprow_124::get_item_ref (slint::private_api::ItemTreeRef component, uint32_t index) -> slint::private_api::ItemRef{
    return slint::private_api::get_item_ref(component, get_item_tree(component), item_array(), index);
}

auto Component_deprow_124::get_subtree_range ([[maybe_unused]] slint::private_api::ItemTreeRef component, [[maybe_unused]] uint32_t dyn_index) -> slint::private_api::IndexRange{
        std::abort();
}

auto Component_deprow_124::get_subtree ([[maybe_unused]] slint::private_api::ItemTreeRef component, [[maybe_unused]] uint32_t dyn_index, [[maybe_unused]] uintptr_t subtree_index, [[maybe_unused]] slint::private_api::ItemTreeWeak *result) -> void{
        std::abort();
}

auto Component_deprow_124::get_item_tree (slint::private_api::ItemTreeRef) -> slint::cbindgen_private::Slice<slint::private_api::ItemTreeNode>{
    return item_tree();
}

auto Component_deprow_124::parent_node ([[maybe_unused]] slint::private_api::ItemTreeRef component, [[maybe_unused]] slint::private_api::ItemWeak *result) -> void{
    auto self = reinterpret_cast<const Component_deprow_124*>(component.instance);
    auto parent = self->parent.lock().value();
    *result = { parent->self_weak, parent->tree_index_of_first_child + 2 };
}

auto Component_deprow_124::embed_component ([[maybe_unused]] slint::private_api::ItemTreeRef component, [[maybe_unused]] const slint::private_api::ItemTreeWeak *parent_component, [[maybe_unused]] const uint32_t parent_index) -> bool{
    return false; /* todo! */
}

auto Component_deprow_124::subtree_index ([[maybe_unused]] slint::private_api::ItemTreeRef component) -> uintptr_t{
    auto self = reinterpret_cast<const Component_deprow_124*>(component.instance);
    return self->field_model_index.get();
}

auto Component_deprow_124::item_tree () -> slint::cbindgen_private::Slice<slint::private_api::ItemTreeNode>{
    static const slint::private_api::ItemTreeNode children[] {
        slint::private_api::make_item_node(3, 1, 0, 0, false), 
slint::private_api::make_item_node(1, 4, 0, 1, false), 
slint::private_api::make_item_node(0, 5, 0, 2, true), 
slint::private_api::make_item_node(0, 5, 0, 3, true), 
slint::private_api::make_item_node(0, 5, 1, 4, true) };
    return slint::private_api::make_slice(std::span(children));
}

auto Component_deprow_124::item_array () -> const slint::private_api::ItemArray{
    static const slint::private_api::ItemArrayEntry items[] {
        { SLINT_GET_ITEM_VTABLE(EmptyVTable), offsetof(Component_deprow_124, field_deprow_124) +  offsetof(DepRow_root_14, field_root_14) }, 
{ SLINT_GET_ITEM_VTABLE(BasicBorderRectangleVTable), offsetof(Component_deprow_124, field_deprow_124) +  offsetof(DepRow_root_14, field_rectangle_16) }, 
{ SLINT_GET_ITEM_VTABLE(SimpleTextVTable), offsetof(Component_deprow_124, field_deprow_124) +  offsetof(DepRow_root_14, field_text_18) }, 
{ SLINT_GET_ITEM_VTABLE(SimpleTextVTable), offsetof(Component_deprow_124, field_deprow_124) +  offsetof(DepRow_root_14, field_text_19) }, 
{ SLINT_GET_ITEM_VTABLE(SimpleTextVTable), offsetof(Component_deprow_124, field_deprow_124) +  offsetof(DepRow_root_14, field_text_17) } };
    return slint::private_api::make_slice(std::span(items));
}

auto Component_deprow_124::layout_info ([[maybe_unused]] slint::private_api::ItemTreeRef component, slint::cbindgen_private::Orientation o) -> slint::cbindgen_private::LayoutInfo{
    return reinterpret_cast<const Component_deprow_124*>(component.instance)->layout_info(o);
}

auto Component_deprow_124::ensure_instantiated ([[maybe_unused]] slint::private_api::ItemTreeRef component) -> bool{
    return reinterpret_cast<const Component_deprow_124*>(component.instance)->ensure_instantiated();
}

auto Component_deprow_124::item_geometry ([[maybe_unused]] slint::private_api::ItemTreeRef component, uint32_t index) -> slint::cbindgen_private::LogicalRect{
    return reinterpret_cast<const Component_deprow_124*>(component.instance)->item_geometry(index);
}

auto Component_deprow_124::accessible_role ([[maybe_unused]] slint::private_api::ItemTreeRef component, uint32_t index) -> slint::cbindgen_private::AccessibleRole{
    return reinterpret_cast<const Component_deprow_124*>(component.instance)->accessible_role(index);
}

auto Component_deprow_124::accessible_string_property ([[maybe_unused]] slint::private_api::ItemTreeRef component, uint32_t index, slint::cbindgen_private::AccessibleStringProperty what, slint::SharedString *result) -> bool{
    if (auto r = reinterpret_cast<const Component_deprow_124*>(component.instance)->accessible_string_property(index, what)) { *result = *r; return true; } else { return false; }
}

auto Component_deprow_124::accessibility_action ([[maybe_unused]] slint::private_api::ItemTreeRef component, uint32_t index, const slint::cbindgen_private::AccessibilityAction *action) -> void{
    reinterpret_cast<const Component_deprow_124*>(component.instance)->accessibility_action(index, *action);
}

auto Component_deprow_124::supported_accessibility_actions ([[maybe_unused]] slint::private_api::ItemTreeRef component, uint32_t index) -> uint32_t{
    return reinterpret_cast<const Component_deprow_124*>(component.instance)->supported_accessibility_actions(index);
}

auto Component_deprow_124::element_infos ([[maybe_unused]] slint::private_api::ItemTreeRef component, [[maybe_unused]] uint32_t index, [[maybe_unused]] slint::SharedString *result) -> bool{
    return false;
}

auto Component_deprow_124::window_adapter ([[maybe_unused]] slint::private_api::ItemTreeRef component, [[maybe_unused]] bool do_create, [[maybe_unused]] slint::cbindgen_private::Option<slint::private_api::WindowAdapterRc>* result) -> void{
    *reinterpret_cast<slint::private_api::WindowAdapterRc*>(result) = reinterpret_cast<const Component_deprow_124*>(component.instance)->globals->window().window_handle();
}

auto Component_deprow_124::create (class Component_rectangle_120 const * parent) -> slint::ComponentHandle<Component_deprow_124>{
    auto self_rc = vtable::VRc<slint::private_api::ItemTreeVTable, Component_deprow_124>::make();
    auto self = const_cast<Component_deprow_124 *>(&*self_rc);
    self->self_weak = vtable::VWeak(self_rc).into_dyn();
    slint::private_api::register_item_tree(&self_rc.into_dyn(), parent->globals->m_window);
    self->init(parent->globals, self->self_weak, 0, 1 , parent);
    return slint::ComponentHandle<Component_deprow_124>{ self_rc };
}

Component_deprow_124::~Component_deprow_124 (){
    if (auto &window = globals->m_window) window->window_handle().unregister_item_tree(this, item_array());
}

auto Component_deprow_124::update_data ([[maybe_unused]] int i, [[maybe_unused]] const UiPackageDependency &data) const -> void{
    [[maybe_unused]] auto self = this;
    self->field_model_index.set(i);
    self->field_model_data.set(data);
}

auto Component_deprow_124::init () -> void{
    user_init();
}

auto Component_deprow_124::layout_item_info (slint::cbindgen_private::Orientation o, [[maybe_unused]] std::optional<size_t> child_index) const -> slint::cbindgen_private::LayoutItemInfo{
    return { layout_info({&static_vtable, const_cast<void *>(static_cast<const void *>(this))}, o) };
}

auto Component_deprow_124::flexbox_layout_item_info (slint::cbindgen_private::Orientation o, [[maybe_unused]] std::optional<size_t> child_index) const -> slint::cbindgen_private::FlexboxLayoutItemInfo{
    auto base = layout_item_info(o, child_index); return { base.constraint, 0.0f, 0.0f, -1.0f, slint::cbindgen_private::FlexboxLayoutAlignSelf::Auto, 0 };
}

const slint::private_api::ItemTreeVTable Component_rectangle_120::static_vtable = { visit_children, get_item_ref, get_subtree_range, get_subtree, get_item_tree, parent_node, embed_component, subtree_index, layout_info, ensure_instantiated, item_geometry, accessible_role, accessible_string_property, accessibility_action, supported_accessibility_actions, element_infos, window_adapter, slint::private_api::drop_in_place<Component_rectangle_120>, slint::private_api::dealloc };

auto Component_rectangle_120::init (const class SharedGlobals* globals,slint::cbindgen_private::ItemTreeWeak enclosing_component,uint32_t tree_index,uint32_t tree_index_of_first_child,class DetailsView_root_32 const *parent) -> void{
    auto self = this;
    self->self_weak = enclosing_component;
    self->globals = globals;
    this->tree_index_of_first_child = tree_index_of_first_child;
    self->tree_index = tree_index;
    self->parent = vtable::VRcMapped<slint::private_api::ItemTreeVTable, const DetailsView_root_32>(parent->self_weak.lock().value(), parent);
    self->field_rectangle_120.background.set(slint::Brush(slint::Color::from_argb_encoded(+4.279769125e9)));
    self->field_rectangle_120.border_color.set(slint::Brush(slint::Color::from_argb_encoded(+4.281414212e9)));
    self->field_rectangle_120.border_radius.set(16);
    self->field_rectangle_120.border_width.set(1);
    self->field_rectangle_120_empty_121_layout_cache.set_binding([this]() {
                            [[maybe_unused]] auto self = this;
                            return [&]{ std::array<int, 2> repeated_indices_array;  std::vector<slint::cbindgen_private::LayoutItemInfo> cells_vector;cells_vector.push_back({ [&](const auto &a_0){ slint::cbindgen_private::LayoutItemInfo o{}; o.constraint = a_0; return o; }(slint::private_api::item_layout_info(SLINT_GET_ITEM_VTABLE(SimpleTextVTable), const_cast<slint::cbindgen_private::SimpleText*>(&self->field_text_122), slint::cbindgen_private::Orientation::Vertical, -1, &self->globals->window().window_handle(), self->self_weak.lock()->into_dyn(), self->tree_index_of_first_child + 1 - 1)) });cells_vector.push_back({ [&](const auto &a_0){ slint::cbindgen_private::LayoutItemInfo o{}; o.constraint = a_0; return o; }([&]{ [[maybe_unused]] auto layout_info = slint::private_api::item_layout_info(SLINT_GET_ITEM_VTABLE(EmptyVTable), const_cast<slint::cbindgen_private::Empty*>(&self->field_rectangle_123), slint::cbindgen_private::Orientation::Vertical, -1, &self->globals->window().window_handle(), self->self_weak.lock()->into_dyn(), self->tree_index_of_first_child + 2 - 1);;return [&](const auto &a_0, const auto &a_1, const auto &a_2, const auto &a_3, const auto &a_4, const auto &a_5){ slint::cbindgen_private::LayoutInfo o{}; o.max = a_0; o.max_percent = a_1; o.min = a_2; o.min_percent = a_3; o.preferred = a_4; o.stretch = a_5; return o; }(10, layout_info.max_percent, 10, layout_info.min_percent, layout_info.preferred, layout_info.stretch); }()) });self->repeater_0.track_instance_changes();repeated_indices_array[0] = cells_vector.size();repeated_indices_array[1] = self->repeater_0.len();{
                                    auto start_offset = cells_vector.size();
                                    self->repeater_0.for_each([&](const auto &sub_comp){ cells_vector.push_back(sub_comp->layout_item_info(slint::cbindgen_private::Orientation::Vertical, std::nullopt)); });
                                    cells_vector.resize(start_offset + self->repeater_0.len());
                                }slint::cbindgen_private::Slice<int> repeated_indices = slint::private_api::make_slice(std::span(repeated_indices_array)); slint::cbindgen_private::Slice<slint::cbindgen_private::LayoutItemInfo>cells = slint::private_api::make_slice(std::span(cells_vector)); return slint::private_api::solve_box_layout([&](const auto &a_0, const auto &a_1, const auto &a_2, const auto &a_3, const auto &a_4){ slint::cbindgen_private::BoxLayoutData o{}; o.alignment = a_0; o.cells = a_1; o.padding = a_2; o.size = a_3; o.spacing = a_4; return o; }(slint::cbindgen_private::LayoutAlignment::Stretch, cells, [&](const auto &a_0, const auto &a_1){ slint::cbindgen_private::Padding o{}; o.begin = a_0; o.end = a_1; return o; }(26, 26), slint::private_api::optional_or_default(slint::private_api::optional_transform(self->parent.lock(), [&](auto&&x) { return slint::private_api::layout_cache_access(x->field_root_32_empty_47_layout_cache.get(), 7, 0, 2); })), 4),repeated_indices); }();
                        });
    self->field_rectangle_120_empty_121_layoutinfo_h.set_binding([this]() {
                            [[maybe_unused]] auto self = this;
                            return [&]{   std::vector<slint::cbindgen_private::LayoutItemInfo> cells_vector;cells_vector.push_back({ [&](const auto &a_0){ slint::cbindgen_private::LayoutItemInfo o{}; o.constraint = a_0; return o; }(slint::private_api::item_layout_info(SLINT_GET_ITEM_VTABLE(SimpleTextVTable), const_cast<slint::cbindgen_private::SimpleText*>(&self->field_text_122), slint::cbindgen_private::Orientation::Horizontal, -1, &self->globals->window().window_handle(), self->self_weak.lock()->into_dyn(), self->tree_index_of_first_child + 1 - 1)) });cells_vector.push_back({ [&](const auto &a_0){ slint::cbindgen_private::LayoutItemInfo o{}; o.constraint = a_0; return o; }(slint::private_api::item_layout_info(SLINT_GET_ITEM_VTABLE(EmptyVTable), const_cast<slint::cbindgen_private::Empty*>(&self->field_rectangle_123), slint::cbindgen_private::Orientation::Horizontal, -1, &self->globals->window().window_handle(), self->self_weak.lock()->into_dyn(), self->tree_index_of_first_child + 2 - 1)) });self->repeater_0.track_instance_changes();{
                                    auto start_offset = cells_vector.size();
                                    self->repeater_0.for_each([&](const auto &sub_comp){ cells_vector.push_back(sub_comp->layout_item_info(slint::cbindgen_private::Orientation::Horizontal, std::nullopt)); });
                                    cells_vector.resize(start_offset + self->repeater_0.len());
                                } slint::cbindgen_private::Slice<slint::cbindgen_private::LayoutItemInfo>cells = slint::private_api::make_slice(std::span(cells_vector)); return slint::private_api::box_layout_info_ortho(cells,[&](const auto &a_0, const auto &a_1){ slint::cbindgen_private::Padding o{}; o.begin = a_0; o.end = a_1; return o; }(26, 26)); }();
                        });
    self->field_rectangle_120_empty_121_layoutinfo_v.set_binding([this]() {
                            [[maybe_unused]] auto self = this;
                            return [&]{   std::vector<slint::cbindgen_private::LayoutItemInfo> cells_vector;cells_vector.push_back({ [&](const auto &a_0){ slint::cbindgen_private::LayoutItemInfo o{}; o.constraint = a_0; return o; }(slint::private_api::item_layout_info(SLINT_GET_ITEM_VTABLE(SimpleTextVTable), const_cast<slint::cbindgen_private::SimpleText*>(&self->field_text_122), slint::cbindgen_private::Orientation::Vertical, -1, &self->globals->window().window_handle(), self->self_weak.lock()->into_dyn(), self->tree_index_of_first_child + 1 - 1)) });cells_vector.push_back({ [&](const auto &a_0){ slint::cbindgen_private::LayoutItemInfo o{}; o.constraint = a_0; return o; }([&]{ [[maybe_unused]] auto layout_info = slint::private_api::item_layout_info(SLINT_GET_ITEM_VTABLE(EmptyVTable), const_cast<slint::cbindgen_private::Empty*>(&self->field_rectangle_123), slint::cbindgen_private::Orientation::Vertical, -1, &self->globals->window().window_handle(), self->self_weak.lock()->into_dyn(), self->tree_index_of_first_child + 2 - 1);;return [&](const auto &a_0, const auto &a_1, const auto &a_2, const auto &a_3, const auto &a_4, const auto &a_5){ slint::cbindgen_private::LayoutInfo o{}; o.max = a_0; o.max_percent = a_1; o.min = a_2; o.min_percent = a_3; o.preferred = a_4; o.stretch = a_5; return o; }(10, layout_info.max_percent, 10, layout_info.min_percent, layout_info.preferred, layout_info.stretch); }()) });self->repeater_0.track_instance_changes();{
                                    auto start_offset = cells_vector.size();
                                    self->repeater_0.for_each([&](const auto &sub_comp){ cells_vector.push_back(sub_comp->layout_item_info(slint::cbindgen_private::Orientation::Vertical, std::nullopt)); });
                                    cells_vector.resize(start_offset + self->repeater_0.len());
                                } slint::cbindgen_private::Slice<slint::cbindgen_private::LayoutItemInfo>cells = slint::private_api::make_slice(std::span(cells_vector)); return slint::private_api::box_layout_info(cells,4,[&](const auto &a_0, const auto &a_1){ slint::cbindgen_private::Padding o{}; o.begin = a_0; o.end = a_1; return o; }(26, 26),slint::cbindgen_private::LayoutAlignment::Stretch); }();
                        });
    self->field_text_122.color.set(slint::Brush(slint::Color::from_argb_encoded(+4.291679988e9)));
    self->field_text_122.font_size.set(16);
    self->field_text_122.font_weight.set(static_cast<int>(700));
    self->field_text_122.height.set_binding([this]() {
                            [[maybe_unused]] auto self = this;
                            return self->field_rectangle_120_empty_121_layout_cache.get()[1];
                        });
    self->field_text_122.text.set_binding([this]() {
                            [[maybe_unused]] auto self = this;
                            return ((slint::SharedString(u8"Dependencies (") + slint::SharedString::from_number(slint::private_api::model_length(slint::private_api::optional_or_default(slint::private_api::optional_transform(self->parent.lock(), [&](auto&&x) { return x->field_root_32_details.get(); })).dependencies))) + slint::SharedString(u8")"));
                        });
    self->field_text_122.width.set_binding([this]() {
                            [[maybe_unused]] auto self = this;
                            return ((((slint::private_api::optional_or_default(slint::private_api::optional_transform(self->parent.lock(), [&](auto&&x) { return x->field_flickable_45.viewport_width.get(); })) -(float) 64) -(float) 64) -(float) 26) -(float) 26);
                        });
    self->field_rectangle_120.background.set_constant();
    self->field_rectangle_120.border_color.set_constant();
    self->field_rectangle_120.border_radius.set_constant();
    self->field_rectangle_120.border_width.set_constant();
    self->field_text_122.color.set_constant();
    self->field_text_122.font_size.set_constant();
    self->field_text_122.font_weight.set_constant();
    self->field_text_122.horizontal_alignment.set_constant();
    self->field_text_122.vertical_alignment.set_constant();
    self->repeater_0.set_model_binding([self] { (void)self; return slint::private_api::optional_or_default(slint::private_api::optional_transform(self->parent.lock(), [&](auto&&x) { return x->field_root_32_details.get(); })).dependencies; });
}

auto Component_rectangle_120::user_init () -> void{
    [[maybe_unused]] auto self = this;
}

auto Component_rectangle_120::layout_info (slint::cbindgen_private::Orientation o) const -> slint::cbindgen_private::LayoutInfo{
    [[maybe_unused]] auto self = this;
    return o == slint::cbindgen_private::Orientation::Horizontal ? ([&](const auto &a_0, const auto &a_1, const auto &a_2, const auto &a_3, const auto &a_4, const auto &a_5){ slint::cbindgen_private::LayoutInfo o{}; o.max = a_0; o.max_percent = a_1; o.min = a_2; o.min_percent = a_3; o.preferred = a_4; o.stretch = a_5; return o; }(+3.4028234663852886e38, 100, 0, 0, 0, 1) + self->field_rectangle_120_empty_121_layoutinfo_h.get()) : ([&](const auto &a_0, const auto &a_1, const auto &a_2, const auto &a_3, const auto &a_4, const auto &a_5){ slint::cbindgen_private::LayoutInfo o{}; o.max = a_0; o.max_percent = a_1; o.min = a_2; o.min_percent = a_3; o.preferred = a_4; o.stretch = a_5; return o; }(+3.4028234663852886e38, 100, 0, 0, 0, 1) + self->field_rectangle_120_empty_121_layoutinfo_v.get());
}

auto Component_rectangle_120::item_geometry (uint32_t index) const -> slint::cbindgen_private::Rect{
    [[maybe_unused]] auto self = this;
    switch (index) {
        case 0: return slint::private_api::convert_anonymous_rect(std::make_tuple(float(slint::private_api::optional_or_default(slint::private_api::optional_transform(self->parent.lock(), [&](auto&&x) { return slint::private_api::layout_cache_access(x->field_root_32_empty_47_layout_cache.get(), 7, 0, 2); }))), float(((slint::private_api::optional_or_default(slint::private_api::optional_transform(self->parent.lock(), [&](auto&&x) { return x->field_flickable_45.viewport_width.get(); })) -(float) 64) -(float) 64)), float(64), float(slint::private_api::optional_or_default(slint::private_api::optional_transform(self->parent.lock(), [&](auto&&x) { return slint::private_api::layout_cache_access(x->field_root_32_empty_47_layout_cache.get(), 6, 0, 2); })))));
        case 1: return slint::private_api::convert_anonymous_rect(std::make_tuple(float(self->field_rectangle_120_empty_121_layout_cache.get()[1]), float(((((slint::private_api::optional_or_default(slint::private_api::optional_transform(self->parent.lock(), [&](auto&&x) { return x->field_flickable_45.viewport_width.get(); })) -(float) 64) -(float) 64) -(float) 26) -(float) 26)), float(26), float(self->field_rectangle_120_empty_121_layout_cache.get()[0])));
        case 2: return slint::private_api::convert_anonymous_rect(std::make_tuple(float(10), float(((((slint::private_api::optional_or_default(slint::private_api::optional_transform(self->parent.lock(), [&](auto&&x) { return x->field_flickable_45.viewport_width.get(); })) -(float) 64) -(float) 64) -(float) 26) -(float) 26)), float(26), float(self->field_rectangle_120_empty_121_layout_cache.get()[2])));
    }
    return {};
}

auto Component_rectangle_120::accessible_role (uint32_t index) const -> slint::cbindgen_private::AccessibleRole{
    [[maybe_unused]] auto self = this;
    switch (index) {
        case 1: return slint::cbindgen_private::AccessibleRole::Text;
    }
    return {};
}

auto Component_rectangle_120::accessible_string_property (uint32_t index, slint::cbindgen_private::AccessibleStringProperty what) const -> std::optional<slint::SharedString>{
    [[maybe_unused]] auto self = this;
    switch ((index << 8) | uintptr_t(what)) {
        case (1 << 8) | uintptr_t(slint::cbindgen_private::AccessibleStringProperty::Label): return self->field_text_122.text.get();
    }
    return {};
}

auto Component_rectangle_120::accessibility_action (uint32_t index, const slint::cbindgen_private::AccessibilityAction &action) const -> void{
    [[maybe_unused]] auto self = this;
    switch ((index << 8) | uintptr_t(action.tag)) {
    }
    return ;
}

auto Component_rectangle_120::supported_accessibility_actions (uint32_t index) const -> uint32_t{
    [[maybe_unused]] auto self = this;
    switch (index) {
    }
    return {};
}

auto Component_rectangle_120::element_infos (uint32_t index) const -> std::optional<slint::SharedString>{
    [[maybe_unused]] auto self = this;
    switch (index) {
    }
    return {};
}

auto Component_rectangle_120::ensure_instantiated () const -> bool{
    [[maybe_unused]] auto self = this;
    bool _changed = false;
    _changed |= self->repeater_0.ensure_updated(self);
    return _changed;
}

auto Component_rectangle_120::visit_dynamic_children (uint32_t dyn_index, [[maybe_unused]] slint::private_api::TraversalOrder order, [[maybe_unused]] slint::private_api::ItemVisitorRefMut visitor) const -> uint64_t{
        auto self = this;
        switch(dyn_index) { 
        case 0: {
                return self->repeater_0.visit(order, visitor);
            } };
        std::abort();
}

auto Component_rectangle_120::subtree_range (uintptr_t dyn_index) const -> slint::private_api::IndexRange{
    [[maybe_unused]] auto self = this;
        switch(dyn_index) { 
        case 0: {
                self->repeater_0.track_instance_changes();
                return self->repeater_0.index_range();
            } };
        std::abort();
}

auto Component_rectangle_120::subtree_component (uintptr_t dyn_index, [[maybe_unused]] uintptr_t subtree_index, [[maybe_unused]] slint::private_api::ItemTreeWeak *result) const -> void{
    [[maybe_unused]] auto self = this;
        switch(dyn_index) { 
        case 0: {
                *result = self->repeater_0.instance_at(subtree_index);
                return;
            } };
        std::abort();
}

auto Component_rectangle_120::visit_children (slint::private_api::ItemTreeRef component, intptr_t index, slint::private_api::TraversalOrder order, slint::private_api::ItemVisitorRefMut visitor) -> uint64_t{
    static const auto dyn_visit = [] (const void *base,  [[maybe_unused]] slint::private_api::TraversalOrder order, [[maybe_unused]] slint::private_api::ItemVisitorRefMut visitor, [[maybe_unused]] uint32_t dyn_index) -> uint64_t {
        [[maybe_unused]] auto self = reinterpret_cast<const Component_rectangle_120*>(base);
        return self->visit_dynamic_children(dyn_index, order, visitor);
    };
    auto self_rc = reinterpret_cast<const Component_rectangle_120*>(component.instance)->self_weak.lock()->into_dyn();
    return slint::cbindgen_private::slint_visit_item_tree(&self_rc, get_item_tree(component) , index, order, visitor, dyn_visit);
}

auto Component_rectangle_120::get_item_ref (slint::private_api::ItemTreeRef component, uint32_t index) -> slint::private_api::ItemRef{
    return slint::private_api::get_item_ref(component, get_item_tree(component), item_array(), index);
}

auto Component_rectangle_120::get_subtree_range ([[maybe_unused]] slint::private_api::ItemTreeRef component, [[maybe_unused]] uint32_t dyn_index) -> slint::private_api::IndexRange{
    auto self = reinterpret_cast<const Component_rectangle_120*>(component.instance);
    return self->subtree_range(dyn_index);
}

auto Component_rectangle_120::get_subtree ([[maybe_unused]] slint::private_api::ItemTreeRef component, [[maybe_unused]] uint32_t dyn_index, [[maybe_unused]] uintptr_t subtree_index, [[maybe_unused]] slint::private_api::ItemTreeWeak *result) -> void{
    auto self = reinterpret_cast<const Component_rectangle_120*>(component.instance);
    self->subtree_component(dyn_index, subtree_index, result);
}

auto Component_rectangle_120::get_item_tree (slint::private_api::ItemTreeRef) -> slint::cbindgen_private::Slice<slint::private_api::ItemTreeNode>{
    return item_tree();
}

auto Component_rectangle_120::parent_node ([[maybe_unused]] slint::private_api::ItemTreeRef component, [[maybe_unused]] slint::private_api::ItemWeak *result) -> void{
    auto self = reinterpret_cast<const Component_rectangle_120*>(component.instance);
    auto parent = self->parent.lock().value();
    *result = { parent->self_weak, parent->tree_index_of_first_child + 17 };
}

auto Component_rectangle_120::embed_component ([[maybe_unused]] slint::private_api::ItemTreeRef component, [[maybe_unused]] const slint::private_api::ItemTreeWeak *parent_component, [[maybe_unused]] const uint32_t parent_index) -> bool{
    return false; /* todo! */
}

auto Component_rectangle_120::subtree_index ([[maybe_unused]] slint::private_api::ItemTreeRef component) -> uintptr_t{
    return std::numeric_limits<uintptr_t>::max();
}

auto Component_rectangle_120::item_tree () -> slint::cbindgen_private::Slice<slint::private_api::ItemTreeNode>{
    static const slint::private_api::ItemTreeNode children[] {
        slint::private_api::make_item_node(3, 1, 0, 0, false), 
slint::private_api::make_item_node(0, 4, 0, 1, true), 
slint::private_api::make_item_node(0, 4, 0, 2, false), 
slint::private_api::make_dyn_node(0, 0) };
    return slint::private_api::make_slice(std::span(children));
}

auto Component_rectangle_120::item_array () -> const slint::private_api::ItemArray{
    static const slint::private_api::ItemArrayEntry items[] {
        { SLINT_GET_ITEM_VTABLE(BasicBorderRectangleVTable),  offsetof(Component_rectangle_120, field_rectangle_120) }, 
{ SLINT_GET_ITEM_VTABLE(SimpleTextVTable),  offsetof(Component_rectangle_120, field_text_122) }, 
{ SLINT_GET_ITEM_VTABLE(EmptyVTable),  offsetof(Component_rectangle_120, field_rectangle_123) } };
    return slint::private_api::make_slice(std::span(items));
}

auto Component_rectangle_120::layout_info ([[maybe_unused]] slint::private_api::ItemTreeRef component, slint::cbindgen_private::Orientation o) -> slint::cbindgen_private::LayoutInfo{
    return reinterpret_cast<const Component_rectangle_120*>(component.instance)->layout_info(o);
}

auto Component_rectangle_120::ensure_instantiated ([[maybe_unused]] slint::private_api::ItemTreeRef component) -> bool{
    return reinterpret_cast<const Component_rectangle_120*>(component.instance)->ensure_instantiated();
}

auto Component_rectangle_120::item_geometry ([[maybe_unused]] slint::private_api::ItemTreeRef component, uint32_t index) -> slint::cbindgen_private::LogicalRect{
    return reinterpret_cast<const Component_rectangle_120*>(component.instance)->item_geometry(index);
}

auto Component_rectangle_120::accessible_role ([[maybe_unused]] slint::private_api::ItemTreeRef component, uint32_t index) -> slint::cbindgen_private::AccessibleRole{
    return reinterpret_cast<const Component_rectangle_120*>(component.instance)->accessible_role(index);
}

auto Component_rectangle_120::accessible_string_property ([[maybe_unused]] slint::private_api::ItemTreeRef component, uint32_t index, slint::cbindgen_private::AccessibleStringProperty what, slint::SharedString *result) -> bool{
    if (auto r = reinterpret_cast<const Component_rectangle_120*>(component.instance)->accessible_string_property(index, what)) { *result = *r; return true; } else { return false; }
}

auto Component_rectangle_120::accessibility_action ([[maybe_unused]] slint::private_api::ItemTreeRef component, uint32_t index, const slint::cbindgen_private::AccessibilityAction *action) -> void{
    reinterpret_cast<const Component_rectangle_120*>(component.instance)->accessibility_action(index, *action);
}

auto Component_rectangle_120::supported_accessibility_actions ([[maybe_unused]] slint::private_api::ItemTreeRef component, uint32_t index) -> uint32_t{
    return reinterpret_cast<const Component_rectangle_120*>(component.instance)->supported_accessibility_actions(index);
}

auto Component_rectangle_120::element_infos ([[maybe_unused]] slint::private_api::ItemTreeRef component, [[maybe_unused]] uint32_t index, [[maybe_unused]] slint::SharedString *result) -> bool{
    return false;
}

auto Component_rectangle_120::window_adapter ([[maybe_unused]] slint::private_api::ItemTreeRef component, [[maybe_unused]] bool do_create, [[maybe_unused]] slint::cbindgen_private::Option<slint::private_api::WindowAdapterRc>* result) -> void{
    *reinterpret_cast<slint::private_api::WindowAdapterRc*>(result) = reinterpret_cast<const Component_rectangle_120*>(component.instance)->globals->window().window_handle();
}

auto Component_rectangle_120::create (class DetailsView_root_32 const * parent) -> slint::ComponentHandle<Component_rectangle_120>{
    auto self_rc = vtable::VRc<slint::private_api::ItemTreeVTable, Component_rectangle_120>::make();
    auto self = const_cast<Component_rectangle_120 *>(&*self_rc);
    self->self_weak = vtable::VWeak(self_rc).into_dyn();
    slint::private_api::register_item_tree(&self_rc.into_dyn(), parent->globals->m_window);
    self->init(parent->globals, self->self_weak, 0, 1 , parent);
    return slint::ComponentHandle<Component_rectangle_120>{ self_rc };
}

Component_rectangle_120::~Component_rectangle_120 (){
    if (auto &window = globals->m_window) window->window_handle().unregister_item_tree(this, item_array());
}

auto Component_rectangle_120::init () -> void{
    user_init();
}

auto Component_rectangle_120::layout_item_info (slint::cbindgen_private::Orientation o, [[maybe_unused]] std::optional<size_t> child_index) const -> slint::cbindgen_private::LayoutItemInfo{
    return { layout_info({&static_vtable, const_cast<void *>(static_cast<const void *>(this))}, o) };
}

auto Component_rectangle_120::flexbox_layout_item_info (slint::cbindgen_private::Orientation o, [[maybe_unused]] std::optional<size_t> child_index) const -> slint::cbindgen_private::FlexboxLayoutItemInfo{
    auto base = layout_item_info(o, child_index); return { base.constraint, 0.0f, 0.0f, -1.0f, slint::cbindgen_private::FlexboxLayoutAlignSelf::Auto, 0 };
}

const slint::private_api::ItemTreeVTable Component_rectangle_127::static_vtable = { visit_children, get_item_ref, get_subtree_range, get_subtree, get_item_tree, parent_node, embed_component, subtree_index, layout_info, ensure_instantiated, item_geometry, accessible_role, accessible_string_property, accessibility_action, supported_accessibility_actions, element_infos, window_adapter, slint::private_api::drop_in_place<Component_rectangle_127>, slint::private_api::dealloc };

auto Component_rectangle_127::init (const class SharedGlobals* globals,slint::cbindgen_private::ItemTreeWeak enclosing_component,uint32_t tree_index,uint32_t tree_index_of_first_child,class DetailsView_root_32 const *parent) -> void{
    auto self = this;
    self->self_weak = enclosing_component;
    self->globals = globals;
    this->tree_index_of_first_child = tree_index_of_first_child;
    self->tree_index = tree_index;
    self->parent = vtable::VRcMapped<slint::private_api::ItemTreeVTable, const DetailsView_root_32>(parent->self_weak.lock().value(), parent);
    self->field_rectangle_127.background.set(slint::Brush(slint::Color::from_argb_encoded(+4.279769125e9)));
    self->field_rectangle_127.border_color.set(slint::Brush(slint::Color::from_argb_encoded(+4.281414212e9)));
    self->field_rectangle_127.border_radius.set(16);
    self->field_rectangle_127.border_width.set(1);
    self->field_rectangle_127_empty_128_layout_cache.set_binding([this]() {
                            [[maybe_unused]] auto self = this;
                            return slint::private_api::solve_box_layout([&](const auto &a_0, const auto &a_1, const auto &a_2, const auto &a_3, const auto &a_4){ slint::cbindgen_private::BoxLayoutData o{}; o.alignment = a_0; o.cells = a_1; o.padding = a_2; o.size = a_3; o.spacing = a_4; return o; }(slint::cbindgen_private::LayoutAlignment::Stretch, slint::private_api::make_slice<slint::cbindgen_private::LayoutItemInfo>(std::array<slint::cbindgen_private::LayoutItemInfo, 1>{ slint::cbindgen_private::LayoutItemInfo ( [&](const auto &a_0){ slint::cbindgen_private::LayoutItemInfo o{}; o.constraint = a_0; return o; }(slint::private_api::item_layout_info(SLINT_GET_ITEM_VTABLE(SimpleTextVTable), const_cast<slint::cbindgen_private::SimpleText*>(&self->field_text_129), slint::cbindgen_private::Orientation::Vertical, -1, &self->globals->window().window_handle(), self->self_weak.lock()->into_dyn(), self->tree_index_of_first_child + 1 - 1)) ) }.data(), 1), [&](const auto &a_0, const auto &a_1){ slint::cbindgen_private::Padding o{}; o.begin = a_0; o.end = a_1; return o; }(26, 26), slint::private_api::optional_or_default(slint::private_api::optional_transform(self->parent.lock(), [&](auto&&x) { return slint::private_api::layout_cache_access(x->field_root_32_empty_47_layout_cache.get(), 9, 0, 2); })), 0),slint::private_api::make_slice<int>(std::array<int, 0>{  }.data(), 0));
                        });
    self->field_rectangle_127_empty_128_layoutinfo_h.set_binding([this]() {
                            [[maybe_unused]] auto self = this;
                            return slint::private_api::box_layout_info_ortho(slint::private_api::make_slice<slint::cbindgen_private::LayoutItemInfo>(std::array<slint::cbindgen_private::LayoutItemInfo, 1>{ slint::cbindgen_private::LayoutItemInfo ( [&](const auto &a_0){ slint::cbindgen_private::LayoutItemInfo o{}; o.constraint = a_0; return o; }(slint::private_api::item_layout_info(SLINT_GET_ITEM_VTABLE(SimpleTextVTable), const_cast<slint::cbindgen_private::SimpleText*>(&self->field_text_129), slint::cbindgen_private::Orientation::Horizontal, -1, &self->globals->window().window_handle(), self->self_weak.lock()->into_dyn(), self->tree_index_of_first_child + 1 - 1)) ) }.data(), 1),[&](const auto &a_0, const auto &a_1){ slint::cbindgen_private::Padding o{}; o.begin = a_0; o.end = a_1; return o; }(26, 26));
                        });
    self->field_rectangle_127_empty_128_layoutinfo_v.set_binding([this]() {
                            [[maybe_unused]] auto self = this;
                            return slint::private_api::box_layout_info(slint::private_api::make_slice<slint::cbindgen_private::LayoutItemInfo>(std::array<slint::cbindgen_private::LayoutItemInfo, 1>{ slint::cbindgen_private::LayoutItemInfo ( [&](const auto &a_0){ slint::cbindgen_private::LayoutItemInfo o{}; o.constraint = a_0; return o; }(slint::private_api::item_layout_info(SLINT_GET_ITEM_VTABLE(SimpleTextVTable), const_cast<slint::cbindgen_private::SimpleText*>(&self->field_text_129), slint::cbindgen_private::Orientation::Vertical, -1, &self->globals->window().window_handle(), self->self_weak.lock()->into_dyn(), self->tree_index_of_first_child + 1 - 1)) ) }.data(), 1),0,[&](const auto &a_0, const auto &a_1){ slint::cbindgen_private::Padding o{}; o.begin = a_0; o.end = a_1; return o; }(26, 26),slint::cbindgen_private::LayoutAlignment::Stretch);
                        });
    self->field_text_129.color.set(slint::Brush(slint::Color::from_argb_encoded(+4.290429662e9)));
    self->field_text_129.font_size.set(13);
    self->field_text_129.height.set_binding([this]() {
                            [[maybe_unused]] auto self = this;
                            return self->field_rectangle_127_empty_128_layout_cache.get()[1];
                        });
    self->field_text_129.text.set(slint::SharedString(u8"No additional dependencies required."));
    self->field_text_129.width.set_binding([this]() {
                            [[maybe_unused]] auto self = this;
                            return ((((slint::private_api::optional_or_default(slint::private_api::optional_transform(self->parent.lock(), [&](auto&&x) { return x->field_flickable_45.viewport_width.get(); })) -(float) 64) -(float) 64) -(float) 26) -(float) 26);
                        });
    self->field_rectangle_127.background.set_constant();
    self->field_rectangle_127.border_color.set_constant();
    self->field_rectangle_127.border_radius.set_constant();
    self->field_rectangle_127.border_width.set_constant();
    self->field_text_129.color.set_constant();
    self->field_text_129.font_size.set_constant();
    self->field_text_129.font_weight.set_constant();
    self->field_text_129.horizontal_alignment.set_constant();
    self->field_text_129.text.set_constant();
    self->field_text_129.vertical_alignment.set_constant();
}

auto Component_rectangle_127::user_init () -> void{
    [[maybe_unused]] auto self = this;
}

auto Component_rectangle_127::layout_info (slint::cbindgen_private::Orientation o) const -> slint::cbindgen_private::LayoutInfo{
    [[maybe_unused]] auto self = this;
    return o == slint::cbindgen_private::Orientation::Horizontal ? ([&](const auto &a_0, const auto &a_1, const auto &a_2, const auto &a_3, const auto &a_4, const auto &a_5){ slint::cbindgen_private::LayoutInfo o{}; o.max = a_0; o.max_percent = a_1; o.min = a_2; o.min_percent = a_3; o.preferred = a_4; o.stretch = a_5; return o; }(+3.4028234663852886e38, 100, 0, 0, 0, 1) + self->field_rectangle_127_empty_128_layoutinfo_h.get()) : ([&](const auto &a_0, const auto &a_1, const auto &a_2, const auto &a_3, const auto &a_4, const auto &a_5){ slint::cbindgen_private::LayoutInfo o{}; o.max = a_0; o.max_percent = a_1; o.min = a_2; o.min_percent = a_3; o.preferred = a_4; o.stretch = a_5; return o; }(+3.4028234663852886e38, 100, 0, 0, 0, 1) + self->field_rectangle_127_empty_128_layoutinfo_v.get());
}

auto Component_rectangle_127::item_geometry (uint32_t index) const -> slint::cbindgen_private::Rect{
    [[maybe_unused]] auto self = this;
    switch (index) {
        case 0: return slint::private_api::convert_anonymous_rect(std::make_tuple(float(slint::private_api::optional_or_default(slint::private_api::optional_transform(self->parent.lock(), [&](auto&&x) { return slint::private_api::layout_cache_access(x->field_root_32_empty_47_layout_cache.get(), 9, 0, 2); }))), float(((slint::private_api::optional_or_default(slint::private_api::optional_transform(self->parent.lock(), [&](auto&&x) { return x->field_flickable_45.viewport_width.get(); })) -(float) 64) -(float) 64)), float(64), float(slint::private_api::optional_or_default(slint::private_api::optional_transform(self->parent.lock(), [&](auto&&x) { return slint::private_api::layout_cache_access(x->field_root_32_empty_47_layout_cache.get(), 8, 0, 2); })))));
        case 1: return slint::private_api::convert_anonymous_rect(std::make_tuple(float(self->field_rectangle_127_empty_128_layout_cache.get()[1]), float(((((slint::private_api::optional_or_default(slint::private_api::optional_transform(self->parent.lock(), [&](auto&&x) { return x->field_flickable_45.viewport_width.get(); })) -(float) 64) -(float) 64) -(float) 26) -(float) 26)), float(26), float(self->field_rectangle_127_empty_128_layout_cache.get()[0])));
    }
    return {};
}

auto Component_rectangle_127::accessible_role (uint32_t index) const -> slint::cbindgen_private::AccessibleRole{
    [[maybe_unused]] auto self = this;
    switch (index) {
        case 1: return slint::cbindgen_private::AccessibleRole::Text;
    }
    return {};
}

auto Component_rectangle_127::accessible_string_property (uint32_t index, slint::cbindgen_private::AccessibleStringProperty what) const -> std::optional<slint::SharedString>{
    [[maybe_unused]] auto self = this;
    switch ((index << 8) | uintptr_t(what)) {
        case (1 << 8) | uintptr_t(slint::cbindgen_private::AccessibleStringProperty::Label): return slint::SharedString(u8"No additional dependencies required.");
    }
    return {};
}

auto Component_rectangle_127::accessibility_action (uint32_t index, const slint::cbindgen_private::AccessibilityAction &action) const -> void{
    [[maybe_unused]] auto self = this;
    switch ((index << 8) | uintptr_t(action.tag)) {
    }
    return ;
}

auto Component_rectangle_127::supported_accessibility_actions (uint32_t index) const -> uint32_t{
    [[maybe_unused]] auto self = this;
    switch (index) {
    }
    return {};
}

auto Component_rectangle_127::element_infos (uint32_t index) const -> std::optional<slint::SharedString>{
    [[maybe_unused]] auto self = this;
    switch (index) {
    }
    return {};
}

auto Component_rectangle_127::ensure_instantiated () const -> bool{
    [[maybe_unused]] auto self = this;
    bool _changed = false;
    return _changed;
}

auto Component_rectangle_127::visit_children (slint::private_api::ItemTreeRef component, intptr_t index, slint::private_api::TraversalOrder order, slint::private_api::ItemVisitorRefMut visitor) -> uint64_t{
    static const auto dyn_visit = [] (const void *base,  [[maybe_unused]] slint::private_api::TraversalOrder order, [[maybe_unused]] slint::private_api::ItemVisitorRefMut visitor, [[maybe_unused]] uint32_t dyn_index) -> uint64_t {
        [[maybe_unused]] auto self = reinterpret_cast<const Component_rectangle_127*>(base);
        std::abort();
    };
    auto self_rc = reinterpret_cast<const Component_rectangle_127*>(component.instance)->self_weak.lock()->into_dyn();
    return slint::cbindgen_private::slint_visit_item_tree(&self_rc, get_item_tree(component) , index, order, visitor, dyn_visit);
}

auto Component_rectangle_127::get_item_ref (slint::private_api::ItemTreeRef component, uint32_t index) -> slint::private_api::ItemRef{
    return slint::private_api::get_item_ref(component, get_item_tree(component), item_array(), index);
}

auto Component_rectangle_127::get_subtree_range ([[maybe_unused]] slint::private_api::ItemTreeRef component, [[maybe_unused]] uint32_t dyn_index) -> slint::private_api::IndexRange{
        std::abort();
}

auto Component_rectangle_127::get_subtree ([[maybe_unused]] slint::private_api::ItemTreeRef component, [[maybe_unused]] uint32_t dyn_index, [[maybe_unused]] uintptr_t subtree_index, [[maybe_unused]] slint::private_api::ItemTreeWeak *result) -> void{
        std::abort();
}

auto Component_rectangle_127::get_item_tree (slint::private_api::ItemTreeRef) -> slint::cbindgen_private::Slice<slint::private_api::ItemTreeNode>{
    return item_tree();
}

auto Component_rectangle_127::parent_node ([[maybe_unused]] slint::private_api::ItemTreeRef component, [[maybe_unused]] slint::private_api::ItemWeak *result) -> void{
    auto self = reinterpret_cast<const Component_rectangle_127*>(component.instance);
    auto parent = self->parent.lock().value();
    *result = { parent->self_weak, parent->tree_index_of_first_child + 18 };
}

auto Component_rectangle_127::embed_component ([[maybe_unused]] slint::private_api::ItemTreeRef component, [[maybe_unused]] const slint::private_api::ItemTreeWeak *parent_component, [[maybe_unused]] const uint32_t parent_index) -> bool{
    return false; /* todo! */
}

auto Component_rectangle_127::subtree_index ([[maybe_unused]] slint::private_api::ItemTreeRef component) -> uintptr_t{
    return std::numeric_limits<uintptr_t>::max();
}

auto Component_rectangle_127::item_tree () -> slint::cbindgen_private::Slice<slint::private_api::ItemTreeNode>{
    static const slint::private_api::ItemTreeNode children[] {
        slint::private_api::make_item_node(1, 1, 0, 0, false), 
slint::private_api::make_item_node(0, 2, 0, 1, true) };
    return slint::private_api::make_slice(std::span(children));
}

auto Component_rectangle_127::item_array () -> const slint::private_api::ItemArray{
    static const slint::private_api::ItemArrayEntry items[] {
        { SLINT_GET_ITEM_VTABLE(BasicBorderRectangleVTable),  offsetof(Component_rectangle_127, field_rectangle_127) }, 
{ SLINT_GET_ITEM_VTABLE(SimpleTextVTable),  offsetof(Component_rectangle_127, field_text_129) } };
    return slint::private_api::make_slice(std::span(items));
}

auto Component_rectangle_127::layout_info ([[maybe_unused]] slint::private_api::ItemTreeRef component, slint::cbindgen_private::Orientation o) -> slint::cbindgen_private::LayoutInfo{
    return reinterpret_cast<const Component_rectangle_127*>(component.instance)->layout_info(o);
}

auto Component_rectangle_127::ensure_instantiated ([[maybe_unused]] slint::private_api::ItemTreeRef component) -> bool{
    return reinterpret_cast<const Component_rectangle_127*>(component.instance)->ensure_instantiated();
}

auto Component_rectangle_127::item_geometry ([[maybe_unused]] slint::private_api::ItemTreeRef component, uint32_t index) -> slint::cbindgen_private::LogicalRect{
    return reinterpret_cast<const Component_rectangle_127*>(component.instance)->item_geometry(index);
}

auto Component_rectangle_127::accessible_role ([[maybe_unused]] slint::private_api::ItemTreeRef component, uint32_t index) -> slint::cbindgen_private::AccessibleRole{
    return reinterpret_cast<const Component_rectangle_127*>(component.instance)->accessible_role(index);
}

auto Component_rectangle_127::accessible_string_property ([[maybe_unused]] slint::private_api::ItemTreeRef component, uint32_t index, slint::cbindgen_private::AccessibleStringProperty what, slint::SharedString *result) -> bool{
    if (auto r = reinterpret_cast<const Component_rectangle_127*>(component.instance)->accessible_string_property(index, what)) { *result = *r; return true; } else { return false; }
}

auto Component_rectangle_127::accessibility_action ([[maybe_unused]] slint::private_api::ItemTreeRef component, uint32_t index, const slint::cbindgen_private::AccessibilityAction *action) -> void{
    reinterpret_cast<const Component_rectangle_127*>(component.instance)->accessibility_action(index, *action);
}

auto Component_rectangle_127::supported_accessibility_actions ([[maybe_unused]] slint::private_api::ItemTreeRef component, uint32_t index) -> uint32_t{
    return reinterpret_cast<const Component_rectangle_127*>(component.instance)->supported_accessibility_actions(index);
}

auto Component_rectangle_127::element_infos ([[maybe_unused]] slint::private_api::ItemTreeRef component, [[maybe_unused]] uint32_t index, [[maybe_unused]] slint::SharedString *result) -> bool{
    return false;
}

auto Component_rectangle_127::window_adapter ([[maybe_unused]] slint::private_api::ItemTreeRef component, [[maybe_unused]] bool do_create, [[maybe_unused]] slint::cbindgen_private::Option<slint::private_api::WindowAdapterRc>* result) -> void{
    *reinterpret_cast<slint::private_api::WindowAdapterRc*>(result) = reinterpret_cast<const Component_rectangle_127*>(component.instance)->globals->window().window_handle();
}

auto Component_rectangle_127::create (class DetailsView_root_32 const * parent) -> slint::ComponentHandle<Component_rectangle_127>{
    auto self_rc = vtable::VRc<slint::private_api::ItemTreeVTable, Component_rectangle_127>::make();
    auto self = const_cast<Component_rectangle_127 *>(&*self_rc);
    self->self_weak = vtable::VWeak(self_rc).into_dyn();
    slint::private_api::register_item_tree(&self_rc.into_dyn(), parent->globals->m_window);
    self->init(parent->globals, self->self_weak, 0, 1 , parent);
    return slint::ComponentHandle<Component_rectangle_127>{ self_rc };
}

Component_rectangle_127::~Component_rectangle_127 (){
    if (auto &window = globals->m_window) window->window_handle().unregister_item_tree(this, item_array());
}

auto Component_rectangle_127::init () -> void{
    user_init();
}

auto Component_rectangle_127::layout_item_info (slint::cbindgen_private::Orientation o, [[maybe_unused]] std::optional<size_t> child_index) const -> slint::cbindgen_private::LayoutItemInfo{
    return { layout_info({&static_vtable, const_cast<void *>(static_cast<const void *>(this))}, o) };
}

auto Component_rectangle_127::flexbox_layout_item_info (slint::cbindgen_private::Orientation o, [[maybe_unused]] std::optional<size_t> child_index) const -> slint::cbindgen_private::FlexboxLayoutItemInfo{
    auto base = layout_item_info(o, child_index); return { base.constraint, 0.0f, 0.0f, -1.0f, slint::cbindgen_private::FlexboxLayoutAlignSelf::Auto, 0 };
}

const slint::private_api::ItemTreeVTable Component_suggestioncard_136::static_vtable = { visit_children, get_item_ref, get_subtree_range, get_subtree, get_item_tree, parent_node, embed_component, subtree_index, layout_info, ensure_instantiated, item_geometry, accessible_role, accessible_string_property, accessibility_action, supported_accessibility_actions, element_infos, window_adapter, slint::private_api::drop_in_place<Component_suggestioncard_136>, slint::private_api::dealloc };

auto Component_suggestioncard_136::init (const class SharedGlobals* globals,slint::cbindgen_private::ItemTreeWeak enclosing_component,uint32_t tree_index,uint32_t tree_index_of_first_child,class Component_empty_131 const *parent) -> void{
    auto self = this;
    self->self_weak = enclosing_component;
    self->globals = globals;
    this->tree_index_of_first_child = tree_index_of_first_child;
    self->tree_index = tree_index;
    self->parent = vtable::VRcMapped<slint::private_api::ItemTreeVTable, const Component_empty_131>(parent->self_weak.lock().value(), parent);
    this->field_suggestioncard_136.init(globals, self_weak.into_dyn(), tree_index, tree_index_of_first_child + 1 - 1);
    self->field_suggestioncard_136.field_root_20_accent_idx.set_binding([this]() {
                            [[maybe_unused]] auto self = this;
                            return static_cast<int>((self->field_model_index.get() + 1));
                        });
    self->field_suggestioncard_136.field_root_20_clicked.set_handler(
                [this]() {
                    [[maybe_unused]] auto self = this;
                    slint::private_api::optional_then(slint::private_api::optional_and_then(self->parent.lock(), [&](auto&&x) { return x->parent.lock(); }), [&](auto&&x) { x->field_root_32_suggestion_clicked.call(self->field_model_data.get()); });
                });
    self->field_suggestioncard_136.field_root_20_pkg.set_binding([this]() {
                            [[maybe_unused]] auto self = this;
                            return self->field_model_data.get();
                        });
    self->field_suggestioncard_136.field_root_20_x.set_binding([this]() {
                            [[maybe_unused]] auto self = this;
                            return slint::private_api::optional_or_default(slint::private_api::optional_transform(self->parent.lock(), [&](auto&&x) { return slint::private_api::layout_cache_access(x->field_empty_131_empty_135_layout_cache.get(), 0, self->field_model_index.get(), 2); }));
                        });
    self->field_suggestioncard_136.field_root_20.border_radius.set_constant();
    self->field_suggestioncard_136.field_root_20.border_width.set_constant();
    self->field_suggestioncard_136.field_root_20_empty_22_alignment.set_constant();
    self->field_suggestioncard_136.field_root_20_empty_22_padding.set_constant();
    self->field_suggestioncard_136.field_root_20_empty_22_spacing.set_constant();
    self->field_suggestioncard_136.field_root_20_rectangle_30_vertical_stretch.set_constant();
}

auto Component_suggestioncard_136::user_init () -> void{
    [[maybe_unused]] auto self = this;
    this->field_suggestioncard_136.user_init();
}

auto Component_suggestioncard_136::layout_info (slint::cbindgen_private::Orientation o) const -> slint::cbindgen_private::LayoutInfo{
    [[maybe_unused]] auto self = this;
    return o == slint::cbindgen_private::Orientation::Horizontal ? [&]{ [[maybe_unused]] auto layout_info = ([&](const auto &a_0, const auto &a_1, const auto &a_2, const auto &a_3, const auto &a_4, const auto &a_5){ slint::cbindgen_private::LayoutInfo o{}; o.max = a_0; o.max_percent = a_1; o.min = a_2; o.min_percent = a_3; o.preferred = a_4; o.stretch = a_5; return o; }(+3.4028234663852886e38, 100, 0, 0, 0, 1) + self->field_suggestioncard_136.field_root_20_empty_22_layoutinfo_h.get());;return [&](const auto &a_0, const auto &a_1, const auto &a_2, const auto &a_3, const auto &a_4, const auto &a_5){ slint::cbindgen_private::LayoutInfo o{}; o.max = a_0; o.max_percent = a_1; o.min = a_2; o.min_percent = a_3; o.preferred = a_4; o.stretch = a_5; return o; }(168, layout_info.max_percent, 168, layout_info.min_percent, layout_info.preferred, layout_info.stretch); }() : [&]{ [[maybe_unused]] auto layout_info = ([&](const auto &a_0, const auto &a_1, const auto &a_2, const auto &a_3, const auto &a_4, const auto &a_5){ slint::cbindgen_private::LayoutInfo o{}; o.max = a_0; o.max_percent = a_1; o.min = a_2; o.min_percent = a_3; o.preferred = a_4; o.stretch = a_5; return o; }(+3.4028234663852886e38, 100, 0, 0, 0, 1) + self->field_suggestioncard_136.field_root_20_empty_22_layoutinfo_v.get());;return [&](const auto &a_0, const auto &a_1, const auto &a_2, const auto &a_3, const auto &a_4, const auto &a_5){ slint::cbindgen_private::LayoutInfo o{}; o.max = a_0; o.max_percent = a_1; o.min = a_2; o.min_percent = a_3; o.preferred = a_4; o.stretch = a_5; return o; }(190, layout_info.max_percent, 190, layout_info.min_percent, layout_info.preferred, layout_info.stretch); }();
}

auto Component_suggestioncard_136::item_geometry (uint32_t index) const -> slint::cbindgen_private::Rect{
    [[maybe_unused]] auto self = this;
    switch (index) {
        case 0: return slint::private_api::convert_anonymous_rect(std::make_tuple(float(190), float(168), float(self->field_suggestioncard_136.field_root_20_x.get()), float(0)));
    }
    if (index == 0) {
        return self->field_suggestioncard_136.item_geometry(0);
    } else if (index >= 1 && index < 9) {
        return self->field_suggestioncard_136.item_geometry(index - 0);
    } else return {};
}

auto Component_suggestioncard_136::accessible_role (uint32_t index) const -> slint::cbindgen_private::AccessibleRole{
    [[maybe_unused]] auto self = this;
    switch (index) {
    }
    if (index == 0) {
        return self->field_suggestioncard_136.accessible_role(0);
    } else if (index >= 1 && index < 9) {
        return self->field_suggestioncard_136.accessible_role(index - 0);
    } else return {};
}

auto Component_suggestioncard_136::accessible_string_property (uint32_t index, slint::cbindgen_private::AccessibleStringProperty what) const -> std::optional<slint::SharedString>{
    [[maybe_unused]] auto self = this;
    switch ((index << 8) | uintptr_t(what)) {
    }
    if (index == 0) {
        return self->field_suggestioncard_136.accessible_string_property(0, what);
    } else if (index >= 1 && index < 9) {
        return self->field_suggestioncard_136.accessible_string_property(index - 0, what);
    } else return {};
}

auto Component_suggestioncard_136::accessibility_action (uint32_t index, const slint::cbindgen_private::AccessibilityAction &action) const -> void{
    [[maybe_unused]] auto self = this;
    switch ((index << 8) | uintptr_t(action.tag)) {
    }
    if (index == 0) {
        return self->field_suggestioncard_136.accessibility_action(0, action);
    } else if (index >= 1 && index < 9) {
        return self->field_suggestioncard_136.accessibility_action(index - 0, action);
    } else return ;
}

auto Component_suggestioncard_136::supported_accessibility_actions (uint32_t index) const -> uint32_t{
    [[maybe_unused]] auto self = this;
    switch (index) {
    }
    if (index == 0) {
        return self->field_suggestioncard_136.supported_accessibility_actions(0);
    } else if (index >= 1 && index < 9) {
        return self->field_suggestioncard_136.supported_accessibility_actions(index - 0);
    } else return {};
}

auto Component_suggestioncard_136::element_infos (uint32_t index) const -> std::optional<slint::SharedString>{
    [[maybe_unused]] auto self = this;
    switch (index) {
    }
    if (index == 0) {
        return self->field_suggestioncard_136.element_infos(0);
    } else if (index >= 1 && index < 9) {
        return self->field_suggestioncard_136.element_infos(index - 0);
    } else return {};
}

auto Component_suggestioncard_136::ensure_instantiated () const -> bool{
    [[maybe_unused]] auto self = this;
    bool _changed = false;
    _changed |= self->field_suggestioncard_136.ensure_instantiated();
    return _changed;
}

auto Component_suggestioncard_136::visit_dynamic_children (uint32_t dyn_index, [[maybe_unused]] slint::private_api::TraversalOrder order, [[maybe_unused]] slint::private_api::ItemVisitorRefMut visitor) const -> uint64_t{
        auto self = this;
        switch(dyn_index) { 
        case 0: case 1:  {
                        return self->field_suggestioncard_136.visit_dynamic_children(dyn_index - 0, order, visitor);
                    } };
        std::abort();
}

auto Component_suggestioncard_136::subtree_range (uintptr_t dyn_index) const -> slint::private_api::IndexRange{
    [[maybe_unused]] auto self = this;
        switch(dyn_index) { 
        case 0: case 1:  {
                        return self->field_suggestioncard_136.subtree_range(dyn_index - 0);
                    } };
        std::abort();
}

auto Component_suggestioncard_136::subtree_component (uintptr_t dyn_index, [[maybe_unused]] uintptr_t subtree_index, [[maybe_unused]] slint::private_api::ItemTreeWeak *result) const -> void{
    [[maybe_unused]] auto self = this;
        switch(dyn_index) { 
        case 0: case 1:  {
                        self->field_suggestioncard_136.subtree_component(dyn_index - 0, subtree_index, result);
                        return;
                    } };
        std::abort();
}

auto Component_suggestioncard_136::visit_children (slint::private_api::ItemTreeRef component, intptr_t index, slint::private_api::TraversalOrder order, slint::private_api::ItemVisitorRefMut visitor) -> uint64_t{
    static const auto dyn_visit = [] (const void *base,  [[maybe_unused]] slint::private_api::TraversalOrder order, [[maybe_unused]] slint::private_api::ItemVisitorRefMut visitor, [[maybe_unused]] uint32_t dyn_index) -> uint64_t {
        [[maybe_unused]] auto self = reinterpret_cast<const Component_suggestioncard_136*>(base);
        return self->visit_dynamic_children(dyn_index, order, visitor);
    };
    auto self_rc = reinterpret_cast<const Component_suggestioncard_136*>(component.instance)->self_weak.lock()->into_dyn();
    return slint::cbindgen_private::slint_visit_item_tree(&self_rc, get_item_tree(component) , index, order, visitor, dyn_visit);
}

auto Component_suggestioncard_136::get_item_ref (slint::private_api::ItemTreeRef component, uint32_t index) -> slint::private_api::ItemRef{
    return slint::private_api::get_item_ref(component, get_item_tree(component), item_array(), index);
}

auto Component_suggestioncard_136::get_subtree_range ([[maybe_unused]] slint::private_api::ItemTreeRef component, [[maybe_unused]] uint32_t dyn_index) -> slint::private_api::IndexRange{
    auto self = reinterpret_cast<const Component_suggestioncard_136*>(component.instance);
    return self->subtree_range(dyn_index);
}

auto Component_suggestioncard_136::get_subtree ([[maybe_unused]] slint::private_api::ItemTreeRef component, [[maybe_unused]] uint32_t dyn_index, [[maybe_unused]] uintptr_t subtree_index, [[maybe_unused]] slint::private_api::ItemTreeWeak *result) -> void{
    auto self = reinterpret_cast<const Component_suggestioncard_136*>(component.instance);
    self->subtree_component(dyn_index, subtree_index, result);
}

auto Component_suggestioncard_136::get_item_tree (slint::private_api::ItemTreeRef) -> slint::cbindgen_private::Slice<slint::private_api::ItemTreeNode>{
    return item_tree();
}

auto Component_suggestioncard_136::parent_node ([[maybe_unused]] slint::private_api::ItemTreeRef component, [[maybe_unused]] slint::private_api::ItemWeak *result) -> void{
    auto self = reinterpret_cast<const Component_suggestioncard_136*>(component.instance);
    auto parent = self->parent.lock().value();
    *result = { parent->self_weak, parent->tree_index_of_first_child + 4 };
}

auto Component_suggestioncard_136::embed_component ([[maybe_unused]] slint::private_api::ItemTreeRef component, [[maybe_unused]] const slint::private_api::ItemTreeWeak *parent_component, [[maybe_unused]] const uint32_t parent_index) -> bool{
    return false; /* todo! */
}

auto Component_suggestioncard_136::subtree_index ([[maybe_unused]] slint::private_api::ItemTreeRef component) -> uintptr_t{
    auto self = reinterpret_cast<const Component_suggestioncard_136*>(component.instance);
    return self->field_model_index.get();
}

auto Component_suggestioncard_136::item_tree () -> slint::cbindgen_private::Slice<slint::private_api::ItemTreeNode>{
    static const slint::private_api::ItemTreeNode children[] {
        slint::private_api::make_item_node(6, 1, 0, 0, false), 
slint::private_api::make_item_node(0, 7, 0, 1, false), 
slint::private_api::make_dyn_node(0, 0), 
slint::private_api::make_dyn_node(1, 0), 
slint::private_api::make_item_node(2, 7, 0, 2, false), 
slint::private_api::make_item_node(0, 9, 0, 3, false), 
slint::private_api::make_item_node(0, 9, 0, 4, true), 
slint::private_api::make_item_node(0, 9, 4, 5, true), 
slint::private_api::make_item_node(0, 9, 4, 6, true) };
    return slint::private_api::make_slice(std::span(children));
}

auto Component_suggestioncard_136::item_array () -> const slint::private_api::ItemArray{
    static const slint::private_api::ItemArrayEntry items[] {
        { SLINT_GET_ITEM_VTABLE(BasicBorderRectangleVTable), offsetof(Component_suggestioncard_136, field_suggestioncard_136) +  offsetof(SuggestionCard_root_20, field_root_20) }, 
{ SLINT_GET_ITEM_VTABLE(TouchAreaVTable), offsetof(Component_suggestioncard_136, field_suggestioncard_136) +  offsetof(SuggestionCard_root_20, field_sta_21) }, 
{ SLINT_GET_ITEM_VTABLE(EmptyVTable), offsetof(Component_suggestioncard_136, field_suggestioncard_136) +  offsetof(SuggestionCard_root_20, field_empty_27) }, 
{ SLINT_GET_ITEM_VTABLE(EmptyVTable), offsetof(Component_suggestioncard_136, field_suggestioncard_136) +  offsetof(SuggestionCard_root_20, field_rectangle_30) }, 
{ SLINT_GET_ITEM_VTABLE(SimpleTextVTable), offsetof(Component_suggestioncard_136, field_suggestioncard_136) +  offsetof(SuggestionCard_root_20, field_text_31) }, 
{ SLINT_GET_ITEM_VTABLE(ComplexTextVTable), offsetof(Component_suggestioncard_136, field_suggestioncard_136) +  offsetof(SuggestionCard_root_20, field_text_28) }, 
{ SLINT_GET_ITEM_VTABLE(ComplexTextVTable), offsetof(Component_suggestioncard_136, field_suggestioncard_136) +  offsetof(SuggestionCard_root_20, field_text_29) } };
    return slint::private_api::make_slice(std::span(items));
}

auto Component_suggestioncard_136::layout_info ([[maybe_unused]] slint::private_api::ItemTreeRef component, slint::cbindgen_private::Orientation o) -> slint::cbindgen_private::LayoutInfo{
    return reinterpret_cast<const Component_suggestioncard_136*>(component.instance)->layout_info(o);
}

auto Component_suggestioncard_136::ensure_instantiated ([[maybe_unused]] slint::private_api::ItemTreeRef component) -> bool{
    return reinterpret_cast<const Component_suggestioncard_136*>(component.instance)->ensure_instantiated();
}

auto Component_suggestioncard_136::item_geometry ([[maybe_unused]] slint::private_api::ItemTreeRef component, uint32_t index) -> slint::cbindgen_private::LogicalRect{
    return reinterpret_cast<const Component_suggestioncard_136*>(component.instance)->item_geometry(index);
}

auto Component_suggestioncard_136::accessible_role ([[maybe_unused]] slint::private_api::ItemTreeRef component, uint32_t index) -> slint::cbindgen_private::AccessibleRole{
    return reinterpret_cast<const Component_suggestioncard_136*>(component.instance)->accessible_role(index);
}

auto Component_suggestioncard_136::accessible_string_property ([[maybe_unused]] slint::private_api::ItemTreeRef component, uint32_t index, slint::cbindgen_private::AccessibleStringProperty what, slint::SharedString *result) -> bool{
    if (auto r = reinterpret_cast<const Component_suggestioncard_136*>(component.instance)->accessible_string_property(index, what)) { *result = *r; return true; } else { return false; }
}

auto Component_suggestioncard_136::accessibility_action ([[maybe_unused]] slint::private_api::ItemTreeRef component, uint32_t index, const slint::cbindgen_private::AccessibilityAction *action) -> void{
    reinterpret_cast<const Component_suggestioncard_136*>(component.instance)->accessibility_action(index, *action);
}

auto Component_suggestioncard_136::supported_accessibility_actions ([[maybe_unused]] slint::private_api::ItemTreeRef component, uint32_t index) -> uint32_t{
    return reinterpret_cast<const Component_suggestioncard_136*>(component.instance)->supported_accessibility_actions(index);
}

auto Component_suggestioncard_136::element_infos ([[maybe_unused]] slint::private_api::ItemTreeRef component, [[maybe_unused]] uint32_t index, [[maybe_unused]] slint::SharedString *result) -> bool{
    return false;
}

auto Component_suggestioncard_136::window_adapter ([[maybe_unused]] slint::private_api::ItemTreeRef component, [[maybe_unused]] bool do_create, [[maybe_unused]] slint::cbindgen_private::Option<slint::private_api::WindowAdapterRc>* result) -> void{
    *reinterpret_cast<slint::private_api::WindowAdapterRc*>(result) = reinterpret_cast<const Component_suggestioncard_136*>(component.instance)->globals->window().window_handle();
}

auto Component_suggestioncard_136::create (class Component_empty_131 const * parent) -> slint::ComponentHandle<Component_suggestioncard_136>{
    auto self_rc = vtable::VRc<slint::private_api::ItemTreeVTable, Component_suggestioncard_136>::make();
    auto self = const_cast<Component_suggestioncard_136 *>(&*self_rc);
    self->self_weak = vtable::VWeak(self_rc).into_dyn();
    slint::private_api::register_item_tree(&self_rc.into_dyn(), parent->globals->m_window);
    self->init(parent->globals, self->self_weak, 0, 1 , parent);
    return slint::ComponentHandle<Component_suggestioncard_136>{ self_rc };
}

Component_suggestioncard_136::~Component_suggestioncard_136 (){
    if (auto &window = globals->m_window) window->window_handle().unregister_item_tree(this, item_array());
}

auto Component_suggestioncard_136::update_data ([[maybe_unused]] int i, [[maybe_unused]] const UiPackage &data) const -> void{
    [[maybe_unused]] auto self = this;
    self->field_model_index.set(i);
    self->field_model_data.set(data);
}

auto Component_suggestioncard_136::init () -> void{
    user_init();
}

auto Component_suggestioncard_136::layout_item_info (slint::cbindgen_private::Orientation o, [[maybe_unused]] std::optional<size_t> child_index) const -> slint::cbindgen_private::LayoutItemInfo{
    return { layout_info({&static_vtable, const_cast<void *>(static_cast<const void *>(this))}, o) };
}

auto Component_suggestioncard_136::flexbox_layout_item_info (slint::cbindgen_private::Orientation o, [[maybe_unused]] std::optional<size_t> child_index) const -> slint::cbindgen_private::FlexboxLayoutItemInfo{
    auto base = layout_item_info(o, child_index); return { base.constraint, 0.0f, 0.0f, -1.0f, slint::cbindgen_private::FlexboxLayoutAlignSelf::Auto, 0 };
}

const slint::private_api::ItemTreeVTable Component_empty_131::static_vtable = { visit_children, get_item_ref, get_subtree_range, get_subtree, get_item_tree, parent_node, embed_component, subtree_index, layout_info, ensure_instantiated, item_geometry, accessible_role, accessible_string_property, accessibility_action, supported_accessibility_actions, element_infos, window_adapter, slint::private_api::drop_in_place<Component_empty_131>, slint::private_api::dealloc };

auto Component_empty_131::fn_empty_135_layoutinfo_v_with_constraint ([[maybe_unused]] float arg_0) const -> slint::cbindgen_private::LayoutInfo{
    [[maybe_unused]] auto self = this;
    return [&]{   std::vector<slint::cbindgen_private::LayoutItemInfo> cells_vector;self->repeater_0.track_instance_changes();{
                                    auto start_offset = cells_vector.size();
                                    self->repeater_0.for_each([&](const auto &sub_comp){ cells_vector.push_back(sub_comp->layout_item_info(slint::cbindgen_private::Orientation::Vertical, std::nullopt)); });
                                    cells_vector.resize(start_offset + self->repeater_0.len());
                                } slint::cbindgen_private::Slice<slint::cbindgen_private::LayoutItemInfo>cells = slint::private_api::make_slice(std::span(cells_vector)); return slint::private_api::box_layout_info_ortho(cells,[&](const auto &a_0, const auto &a_1){ slint::cbindgen_private::Padding o{}; o.begin = a_0; o.end = a_1; return o; }(0, 0)); }();
}

auto Component_empty_131::fn_layoutinfo_v_with_constraint ([[maybe_unused]] float arg_0) const -> slint::cbindgen_private::LayoutInfo{
    [[maybe_unused]] auto self = this;
    return slint::private_api::box_layout_info(slint::private_api::make_slice<slint::cbindgen_private::LayoutItemInfo>(std::array<slint::cbindgen_private::LayoutItemInfo, 3>{ slint::cbindgen_private::LayoutItemInfo ( [&](const auto &a_0){ slint::cbindgen_private::LayoutItemInfo o{}; o.constraint = a_0; return o; }(slint::private_api::item_layout_info(SLINT_GET_ITEM_VTABLE(SimpleTextVTable), const_cast<slint::cbindgen_private::SimpleText*>(&self->field_text_132), slint::cbindgen_private::Orientation::Vertical, arg_0, &self->globals->window().window_handle(), self->self_weak.lock()->into_dyn(), self->tree_index_of_first_child + 1 - 1)) ), slint::cbindgen_private::LayoutItemInfo ( [&](const auto &a_0){ slint::cbindgen_private::LayoutItemInfo o{}; o.constraint = a_0; return o; }([&]{ [[maybe_unused]] auto layout_info = slint::private_api::item_layout_info(SLINT_GET_ITEM_VTABLE(FlickableVTable), const_cast<slint::cbindgen_private::Flickable*>(&self->field_suggestions_flick_133), slint::cbindgen_private::Orientation::Vertical, arg_0, &self->globals->window().window_handle(), self->self_weak.lock()->into_dyn(), self->tree_index_of_first_child + 2 - 1);;return [&](const auto &a_0, const auto &a_1, const auto &a_2, const auto &a_3, const auto &a_4, const auto &a_5){ slint::cbindgen_private::LayoutInfo o{}; o.max = a_0; o.max_percent = a_1; o.min = a_2; o.min_percent = a_3; o.preferred = a_4; o.stretch = a_5; return o; }(self->field_empty_131_suggestions_flick_133_height.get(), layout_info.max_percent, self->field_empty_131_suggestions_flick_133_height.get(), layout_info.min_percent, layout_info.preferred, layout_info.stretch); }()) ), slint::cbindgen_private::LayoutItemInfo ( [&](const auto &a_0){ slint::cbindgen_private::LayoutItemInfo o{}; o.constraint = a_0; return o; }([&]{ [[maybe_unused]] auto layout_info = slint::private_api::item_layout_info(SLINT_GET_ITEM_VTABLE(BasicBorderRectangleVTable), const_cast<slint::cbindgen_private::BasicBorderRectangle*>(&self->field_scroll_track_138), slint::cbindgen_private::Orientation::Vertical, arg_0, &self->globals->window().window_handle(), self->self_weak.lock()->into_dyn(), self->tree_index_of_first_child + 3 - 1);;return [&](const auto &a_0, const auto &a_1, const auto &a_2, const auto &a_3, const auto &a_4, const auto &a_5){ slint::cbindgen_private::LayoutInfo o{}; o.max = a_0; o.max_percent = a_1; o.min = a_2; o.min_percent = a_3; o.preferred = a_4; o.stretch = a_5; return o; }(self->field_empty_131_scroll_track_138_height.get(), layout_info.max_percent, self->field_empty_131_scroll_track_138_height.get(), layout_info.min_percent, layout_info.preferred, layout_info.stretch); }()) ) }.data(), 3),self->field_empty_131_spacing.get(),[&](const auto &a_0, const auto &a_1){ slint::cbindgen_private::Padding o{}; o.begin = a_0; o.end = a_1; return o; }(0, 0),slint::cbindgen_private::LayoutAlignment::Stretch);
}

auto Component_empty_131::init (const class SharedGlobals* globals,slint::cbindgen_private::ItemTreeWeak enclosing_component,uint32_t tree_index,uint32_t tree_index_of_first_child,class DetailsView_root_32 const *parent) -> void{
    auto self = this;
    self->self_weak = enclosing_component;
    self->globals = globals;
    this->tree_index_of_first_child = tree_index_of_first_child;
    self->tree_index = tree_index;
    self->parent = vtable::VRcMapped<slint::private_api::ItemTreeVTable, const DetailsView_root_32>(parent->self_weak.lock().value(), parent);
    self->field_empty_131_empty_135_layout_cache.set_binding([this]() {
                            [[maybe_unused]] auto self = this;
                            return [&]{ std::array<int, 2> repeated_indices_array;  std::vector<slint::cbindgen_private::LayoutItemInfo> cells_vector;self->repeater_0.track_instance_changes();repeated_indices_array[0] = cells_vector.size();repeated_indices_array[1] = self->repeater_0.len();{
                                    auto start_offset = cells_vector.size();
                                    self->repeater_0.for_each([&](const auto &sub_comp){ cells_vector.push_back(sub_comp->layout_item_info(slint::cbindgen_private::Orientation::Horizontal, std::nullopt)); });
                                    cells_vector.resize(start_offset + self->repeater_0.len());
                                }slint::cbindgen_private::Slice<int> repeated_indices = slint::private_api::make_slice(std::span(repeated_indices_array)); slint::cbindgen_private::Slice<slint::cbindgen_private::LayoutItemInfo>cells = slint::private_api::make_slice(std::span(cells_vector)); return slint::private_api::solve_box_layout([&](const auto &a_0, const auto &a_1, const auto &a_2, const auto &a_3, const auto &a_4){ slint::cbindgen_private::BoxLayoutData o{}; o.alignment = a_0; o.cells = a_1; o.padding = a_2; o.size = a_3; o.spacing = a_4; return o; }(slint::cbindgen_private::LayoutAlignment::Stretch, cells, [&](const auto &a_0, const auto &a_1){ slint::cbindgen_private::Padding o{}; o.begin = a_0; o.end = a_1; return o; }(0, 0), self->field_suggestions_flick_133.viewport_width.get(), 16),repeated_indices); }();
                        });
    self->field_empty_131_empty_135_layoutinfo_h.set_binding([this]() {
                            [[maybe_unused]] auto self = this;
                            return [&]{   std::vector<slint::cbindgen_private::LayoutItemInfo> cells_vector;self->repeater_0.track_instance_changes();{
                                    auto start_offset = cells_vector.size();
                                    self->repeater_0.for_each([&](const auto &sub_comp){ cells_vector.push_back(sub_comp->layout_item_info(slint::cbindgen_private::Orientation::Horizontal, std::nullopt)); });
                                    cells_vector.resize(start_offset + self->repeater_0.len());
                                } slint::cbindgen_private::Slice<slint::cbindgen_private::LayoutItemInfo>cells = slint::private_api::make_slice(std::span(cells_vector)); return slint::private_api::box_layout_info(cells,16,[&](const auto &a_0, const auto &a_1){ slint::cbindgen_private::Padding o{}; o.begin = a_0; o.end = a_1; return o; }(0, 0),slint::cbindgen_private::LayoutAlignment::Stretch); }();
                        });
    self->field_empty_131_empty_135_layoutinfo_v.set_binding([this]() {
                            [[maybe_unused]] auto self = this;
                            return [&]{   std::vector<slint::cbindgen_private::LayoutItemInfo> cells_vector;self->repeater_0.track_instance_changes();{
                                    auto start_offset = cells_vector.size();
                                    self->repeater_0.for_each([&](const auto &sub_comp){ cells_vector.push_back(sub_comp->layout_item_info(slint::cbindgen_private::Orientation::Vertical, std::nullopt)); });
                                    cells_vector.resize(start_offset + self->repeater_0.len());
                                } slint::cbindgen_private::Slice<slint::cbindgen_private::LayoutItemInfo>cells = slint::private_api::make_slice(std::span(cells_vector)); return slint::private_api::box_layout_info_ortho(cells,[&](const auto &a_0, const auto &a_1){ slint::cbindgen_private::Padding o{}; o.begin = a_0; o.end = a_1; return o; }(0, 0)); }();
                        });
    self->field_empty_131_empty_135_max_width.set_binding([this]() {
                            [[maybe_unused]] auto self = this;
                            return self->field_empty_131_empty_135_layoutinfo_h.get().max;
                        });
    self->field_empty_131_empty_135_preferred_width.set_binding([this]() {
                            [[maybe_unused]] auto self = this;
                            return self->field_empty_131_empty_135_layoutinfo_h.get().preferred;
                        });
    self->field_empty_131_layout_cache.set_binding([this]() {
                            [[maybe_unused]] auto self = this;
                            return slint::private_api::solve_box_layout([&](const auto &a_0, const auto &a_1, const auto &a_2, const auto &a_3, const auto &a_4){ slint::cbindgen_private::BoxLayoutData o{}; o.alignment = a_0; o.cells = a_1; o.padding = a_2; o.size = a_3; o.spacing = a_4; return o; }(slint::cbindgen_private::LayoutAlignment::Stretch, slint::private_api::make_slice<slint::cbindgen_private::LayoutItemInfo>(std::array<slint::cbindgen_private::LayoutItemInfo, 3>{ slint::cbindgen_private::LayoutItemInfo ( [&](const auto &a_0){ slint::cbindgen_private::LayoutItemInfo o{}; o.constraint = a_0; return o; }(slint::private_api::item_layout_info(SLINT_GET_ITEM_VTABLE(SimpleTextVTable), const_cast<slint::cbindgen_private::SimpleText*>(&self->field_text_132), slint::cbindgen_private::Orientation::Vertical, -1, &self->globals->window().window_handle(), self->self_weak.lock()->into_dyn(), self->tree_index_of_first_child + 1 - 1)) ), slint::cbindgen_private::LayoutItemInfo ( [&](const auto &a_0){ slint::cbindgen_private::LayoutItemInfo o{}; o.constraint = a_0; return o; }([&]{ [[maybe_unused]] auto layout_info = slint::private_api::item_layout_info(SLINT_GET_ITEM_VTABLE(FlickableVTable), const_cast<slint::cbindgen_private::Flickable*>(&self->field_suggestions_flick_133), slint::cbindgen_private::Orientation::Vertical, -1, &self->globals->window().window_handle(), self->self_weak.lock()->into_dyn(), self->tree_index_of_first_child + 2 - 1);;return [&](const auto &a_0, const auto &a_1, const auto &a_2, const auto &a_3, const auto &a_4, const auto &a_5){ slint::cbindgen_private::LayoutInfo o{}; o.max = a_0; o.max_percent = a_1; o.min = a_2; o.min_percent = a_3; o.preferred = a_4; o.stretch = a_5; return o; }(190, layout_info.max_percent, 190, layout_info.min_percent, layout_info.preferred, layout_info.stretch); }()) ), slint::cbindgen_private::LayoutItemInfo ( [&](const auto &a_0){ slint::cbindgen_private::LayoutItemInfo o{}; o.constraint = a_0; return o; }([&]{ [[maybe_unused]] auto layout_info = slint::private_api::item_layout_info(SLINT_GET_ITEM_VTABLE(BasicBorderRectangleVTable), const_cast<slint::cbindgen_private::BasicBorderRectangle*>(&self->field_scroll_track_138), slint::cbindgen_private::Orientation::Vertical, -1, &self->globals->window().window_handle(), self->self_weak.lock()->into_dyn(), self->tree_index_of_first_child + 3 - 1);;return [&](const auto &a_0, const auto &a_1, const auto &a_2, const auto &a_3, const auto &a_4, const auto &a_5){ slint::cbindgen_private::LayoutInfo o{}; o.max = a_0; o.max_percent = a_1; o.min = a_2; o.min_percent = a_3; o.preferred = a_4; o.stretch = a_5; return o; }(8, layout_info.max_percent, 8, layout_info.min_percent, layout_info.preferred, layout_info.stretch); }()) ) }.data(), 3), [&](const auto &a_0, const auto &a_1){ slint::cbindgen_private::Padding o{}; o.begin = a_0; o.end = a_1; return o; }(0, 0), slint::private_api::optional_or_default(slint::private_api::optional_transform(self->parent.lock(), [&](auto&&x) { return slint::private_api::layout_cache_access(x->field_root_32_empty_47_layout_cache.get(), 11, 0, 2); })), 14),slint::private_api::make_slice<int>(std::array<int, 0>{  }.data(), 0));
                        });
    self->field_empty_131_layoutinfo_h.set_binding([this]() {
                            [[maybe_unused]] auto self = this;
                            return slint::private_api::box_layout_info_ortho(slint::private_api::make_slice<slint::cbindgen_private::LayoutItemInfo>(std::array<slint::cbindgen_private::LayoutItemInfo, 3>{ slint::cbindgen_private::LayoutItemInfo ( [&](const auto &a_0){ slint::cbindgen_private::LayoutItemInfo o{}; o.constraint = a_0; return o; }(slint::private_api::item_layout_info(SLINT_GET_ITEM_VTABLE(SimpleTextVTable), const_cast<slint::cbindgen_private::SimpleText*>(&self->field_text_132), slint::cbindgen_private::Orientation::Horizontal, -1, &self->globals->window().window_handle(), self->self_weak.lock()->into_dyn(), self->tree_index_of_first_child + 1 - 1)) ), slint::cbindgen_private::LayoutItemInfo ( [&](const auto &a_0){ slint::cbindgen_private::LayoutItemInfo o{}; o.constraint = a_0; return o; }([&]{ [[maybe_unused]] auto layout_info = slint::private_api::item_layout_info(SLINT_GET_ITEM_VTABLE(FlickableVTable), const_cast<slint::cbindgen_private::Flickable*>(&self->field_suggestions_flick_133), slint::cbindgen_private::Orientation::Horizontal, -1, &self->globals->window().window_handle(), self->self_weak.lock()->into_dyn(), self->tree_index_of_first_child + 2 - 1);;return [&](const auto &a_0, const auto &a_1, const auto &a_2, const auto &a_3, const auto &a_4, const auto &a_5){ slint::cbindgen_private::LayoutInfo o{}; o.max = a_0; o.max_percent = a_1; o.min = a_2; o.min_percent = a_3; o.preferred = a_4; o.stretch = a_5; return o; }(self->field_empty_131_empty_135_max_width.get(), layout_info.max_percent, layout_info.min, layout_info.min_percent, self->field_empty_131_empty_135_preferred_width.get(), layout_info.stretch); }()) ), slint::cbindgen_private::LayoutItemInfo ( [&](const auto &a_0){ slint::cbindgen_private::LayoutItemInfo o{}; o.constraint = a_0; return o; }(slint::private_api::item_layout_info(SLINT_GET_ITEM_VTABLE(BasicBorderRectangleVTable), const_cast<slint::cbindgen_private::BasicBorderRectangle*>(&self->field_scroll_track_138), slint::cbindgen_private::Orientation::Horizontal, -1, &self->globals->window().window_handle(), self->self_weak.lock()->into_dyn(), self->tree_index_of_first_child + 3 - 1)) ) }.data(), 3),[&](const auto &a_0, const auto &a_1){ slint::cbindgen_private::Padding o{}; o.begin = a_0; o.end = a_1; return o; }(0, 0));
                        });
    self->field_empty_131_layoutinfo_v.set_binding([this]() {
                            [[maybe_unused]] auto self = this;
                            return slint::private_api::box_layout_info(slint::private_api::make_slice<slint::cbindgen_private::LayoutItemInfo>(std::array<slint::cbindgen_private::LayoutItemInfo, 3>{ slint::cbindgen_private::LayoutItemInfo ( [&](const auto &a_0){ slint::cbindgen_private::LayoutItemInfo o{}; o.constraint = a_0; return o; }(slint::private_api::item_layout_info(SLINT_GET_ITEM_VTABLE(SimpleTextVTable), const_cast<slint::cbindgen_private::SimpleText*>(&self->field_text_132), slint::cbindgen_private::Orientation::Vertical, -1, &self->globals->window().window_handle(), self->self_weak.lock()->into_dyn(), self->tree_index_of_first_child + 1 - 1)) ), slint::cbindgen_private::LayoutItemInfo ( [&](const auto &a_0){ slint::cbindgen_private::LayoutItemInfo o{}; o.constraint = a_0; return o; }([&]{ [[maybe_unused]] auto layout_info = slint::private_api::item_layout_info(SLINT_GET_ITEM_VTABLE(FlickableVTable), const_cast<slint::cbindgen_private::Flickable*>(&self->field_suggestions_flick_133), slint::cbindgen_private::Orientation::Vertical, -1, &self->globals->window().window_handle(), self->self_weak.lock()->into_dyn(), self->tree_index_of_first_child + 2 - 1);;return [&](const auto &a_0, const auto &a_1, const auto &a_2, const auto &a_3, const auto &a_4, const auto &a_5){ slint::cbindgen_private::LayoutInfo o{}; o.max = a_0; o.max_percent = a_1; o.min = a_2; o.min_percent = a_3; o.preferred = a_4; o.stretch = a_5; return o; }(190, layout_info.max_percent, 190, layout_info.min_percent, layout_info.preferred, layout_info.stretch); }()) ), slint::cbindgen_private::LayoutItemInfo ( [&](const auto &a_0){ slint::cbindgen_private::LayoutItemInfo o{}; o.constraint = a_0; return o; }([&]{ [[maybe_unused]] auto layout_info = slint::private_api::item_layout_info(SLINT_GET_ITEM_VTABLE(BasicBorderRectangleVTable), const_cast<slint::cbindgen_private::BasicBorderRectangle*>(&self->field_scroll_track_138), slint::cbindgen_private::Orientation::Vertical, -1, &self->globals->window().window_handle(), self->self_weak.lock()->into_dyn(), self->tree_index_of_first_child + 3 - 1);;return [&](const auto &a_0, const auto &a_1, const auto &a_2, const auto &a_3, const auto &a_4, const auto &a_5){ slint::cbindgen_private::LayoutInfo o{}; o.max = a_0; o.max_percent = a_1; o.min = a_2; o.min_percent = a_3; o.preferred = a_4; o.stretch = a_5; return o; }(8, layout_info.max_percent, 8, layout_info.min_percent, layout_info.preferred, layout_info.stretch); }()) ) }.data(), 3),14,[&](const auto &a_0, const auto &a_1){ slint::cbindgen_private::Padding o{}; o.begin = a_0; o.end = a_1; return o; }(0, 0),slint::cbindgen_private::LayoutAlignment::Stretch);
                        });
    self->field_empty_131_scroll_track_138_content_width.set_binding([this]() {
                            [[maybe_unused]] auto self = this;
                            return std::max<float>(self->field_suggestions_flick_133.viewport_width.get(), self->field_empty_131_width.get());
                        });
    self->field_empty_131_scroll_track_138_height.set(8);
    self->field_empty_131_scroll_track_138_max_scroll.set_binding([this]() {
                            [[maybe_unused]] auto self = this;
                            return (self->field_empty_131_scroll_track_138_content_width.get() -(float) self->field_empty_131_suggestions_flick_133_width.get());
                        });
    self->field_empty_131_scroll_track_138_max_thumb_x.set_binding([this]() {
                            [[maybe_unused]] auto self = this;
                            return (self->field_empty_131_width.get() -(float) self->field_empty_131_scroll_track_138_thumb_width.get());
                        });
    self->field_empty_131_scroll_track_138_thumb_width.set_binding([this]() {
                            [[maybe_unused]] auto self = this;
                            return std::max<float>(36, (self->field_empty_131_width.get() * (self->field_empty_131_suggestions_flick_133_width.get() /(float) self->field_empty_131_scroll_track_138_content_width.get())));
                        });
    self->field_empty_131_scroll_track_138_thumb_x.set_binding([this]() {
                            [[maybe_unused]] auto self = this;
                            return [&]{ [[maybe_unused]] auto tmp_empty_131_scroll_track_138_max_thumb_x = self->field_empty_131_scroll_track_138_max_thumb_x.get();;return (tmp_empty_131_scroll_track_138_max_thumb_x > 0 ? (((- self->field_suggestions_flick_133.viewport_x.get()) /(float) std::max<float>(1, self->field_empty_131_scroll_track_138_max_scroll.get())) * tmp_empty_131_scroll_track_138_max_thumb_x) : 0); }();
                        });
    self->field_empty_131_spacing.set(14);
    self->field_empty_131_suggestions_flick_133_height.set(190);
    self->field_empty_131_suggestions_flick_133_width.set_binding([this]() {
                            [[maybe_unused]] auto self = this;
                            return ((slint::private_api::optional_or_default(slint::private_api::optional_transform(self->parent.lock(), [&](auto&&x) { return x->field_flickable_45.viewport_width.get(); })) -(float) 64) -(float) 64);
                        });
    self->field_empty_131_thumb_ta_140_press_thumb_x.set(0);
    self->field_empty_131_width.set_binding([this]() {
                            [[maybe_unused]] auto self = this;
                            return ((slint::private_api::optional_or_default(slint::private_api::optional_transform(self->parent.lock(), [&](auto&&x) { return x->field_flickable_45.viewport_width.get(); })) -(float) 64) -(float) 64);
                        });
    self->field_text_132.color.set(slint::Brush(slint::Color::from_argb_encoded(+4.291679988e9)));
    self->field_text_132.font_size.set(18);
    self->field_text_132.font_weight.set(static_cast<int>(700));
    self->field_text_132.height.set_binding([this]() {
                            [[maybe_unused]] auto self = this;
                            return self->field_empty_131_layout_cache.get()[1];
                        });
    self->field_text_132.text.set(slint::SharedString(u8"You might also like"));
    self->field_text_132.width.set_binding([this]() {
                            [[maybe_unused]] auto self = this;
                            return ((slint::private_api::optional_or_default(slint::private_api::optional_transform(self->parent.lock(), [&](auto&&x) { return x->field_flickable_45.viewport_width.get(); })) -(float) 64) -(float) 64);
                        });
    self->field_suggestions_flick_133.interactive.set(true);
    self->field_suggestions_flick_133.viewport_height.set_binding([this]() {
                            [[maybe_unused]] auto self = this;
                            return std::max<float>(190, self->field_empty_131_empty_135_layoutinfo_v.get().min);
                        });
    self->field_suggestions_flick_133.viewport_width.set_binding([this]() {
                            [[maybe_unused]] auto self = this;
                            return (slint::private_api::model_length(slint::private_api::optional_or_default(slint::private_api::optional_transform(self->parent.lock(), [&](auto&&x) { return x->field_root_32_suggestions.get(); }))) * 184);
                        });
    self->field_scroll_track_138.background.set(slint::Brush(slint::Color::from_argb_encoded(+4.281414212e9)));
    self->field_scroll_track_138.border_radius.set(4);
    self->field_thumb_139.background.set_binding([this]() {
                            [[maybe_unused]] auto self = this;
                            return slint::Brush((self->field_thumb_ta_140.has_hover.get() || self->field_thumb_ta_140.pressed.get() ? slint::private_api::optional_or_default(slint::private_api::optional_transform(self->parent.lock(), [&](auto&&x) { return x->field_root_32_accent.get(); })) : slint::Color::from_argb_encoded(+4.283980656e9)));
                        });
    self->field_thumb_139.border_radius.set(4);
    self->field_thumb_ta_140.enabled.set(true);
    self->field_thumb_ta_140.moved.set_handler(
                [this]() {
                    [[maybe_unused]] auto self = this;
                    if (self->field_thumb_ta_140.pressed.get() && (self->field_empty_131_scroll_track_138_max_thumb_x.get() > 0)) { self->field_suggestions_flick_133.viewport_x.set(((- (std::max<float>(0, std::min<float>(self->field_empty_131_scroll_track_138_max_thumb_x.get(), (self->field_empty_131_thumb_ta_140_press_thumb_x.get() + (self->field_thumb_ta_140.mouse_x.get() -(float) self->field_thumb_ta_140.pressed_x.get())))) /(float) self->field_empty_131_scroll_track_138_max_thumb_x.get())) * self->field_empty_131_scroll_track_138_max_scroll.get())); } else { ; };
                });
    self->field_thumb_ta_140.pointer_event.set_handler(
                [this]([[maybe_unused]] slint::language::PointerEvent arg_0) {
                    [[maybe_unused]] auto self = this;
                    if (arg_0.kind == slint::cbindgen_private::PointerEventKind::Down) { self->field_empty_131_thumb_ta_140_press_thumb_x.set(self->field_empty_131_scroll_track_138_thumb_x.get()); } else { ; };
                });
    self->field_empty_131_scroll_track_138_height.set_constant();
    self->field_empty_131_spacing.set_constant();
    self->field_empty_131_suggestions_flick_133_height.set_constant();
    self->field_text_132.color.set_constant();
    self->field_text_132.font_size.set_constant();
    self->field_text_132.font_weight.set_constant();
    self->field_text_132.horizontal_alignment.set_constant();
    self->field_text_132.text.set_constant();
    self->field_text_132.vertical_alignment.set_constant();
    self->field_suggestions_flick_133.interactive.set_constant();
    self->field_scroll_track_138.background.set_constant();
    self->field_scroll_track_138.border_color.set_constant();
    self->field_scroll_track_138.border_radius.set_constant();
    self->field_scroll_track_138.border_width.set_constant();
    self->field_thumb_139.border_color.set_constant();
    self->field_thumb_139.border_radius.set_constant();
    self->field_thumb_139.border_width.set_constant();
    self->field_thumb_ta_140.enabled.set_constant();
    self->field_thumb_ta_140.mouse_cursor.set_constant();
    self->repeater_0.set_model_binding([self] { (void)self; return slint::private_api::optional_or_default(slint::private_api::optional_transform(self->parent.lock(), [&](auto&&x) { return x->field_root_32_suggestions.get(); })); });
}

auto Component_empty_131::user_init () -> void{
    [[maybe_unused]] auto self = this;
}

auto Component_empty_131::layout_info (slint::cbindgen_private::Orientation o) const -> slint::cbindgen_private::LayoutInfo{
    [[maybe_unused]] auto self = this;
    return o == slint::cbindgen_private::Orientation::Horizontal ? self->field_empty_131_layoutinfo_h.get() : self->field_empty_131_layoutinfo_v.get();
}

auto Component_empty_131::item_geometry (uint32_t index) const -> slint::cbindgen_private::Rect{
    [[maybe_unused]] auto self = this;
    switch (index) {
        case 0: return slint::private_api::convert_anonymous_rect(std::make_tuple(float(slint::private_api::optional_or_default(slint::private_api::optional_transform(self->parent.lock(), [&](auto&&x) { return slint::private_api::layout_cache_access(x->field_root_32_empty_47_layout_cache.get(), 11, 0, 2); }))), float(((slint::private_api::optional_or_default(slint::private_api::optional_transform(self->parent.lock(), [&](auto&&x) { return x->field_flickable_45.viewport_width.get(); })) -(float) 64) -(float) 64)), float(64), float(slint::private_api::optional_or_default(slint::private_api::optional_transform(self->parent.lock(), [&](auto&&x) { return slint::private_api::layout_cache_access(x->field_root_32_empty_47_layout_cache.get(), 10, 0, 2); })))));
        case 1: return slint::private_api::convert_anonymous_rect(std::make_tuple(float(self->field_empty_131_layout_cache.get()[1]), float(((slint::private_api::optional_or_default(slint::private_api::optional_transform(self->parent.lock(), [&](auto&&x) { return x->field_flickable_45.viewport_width.get(); })) -(float) 64) -(float) 64)), float(0), float(self->field_empty_131_layout_cache.get()[0])));
        case 2: return slint::private_api::convert_anonymous_rect(std::make_tuple(float(190), float(((slint::private_api::optional_or_default(slint::private_api::optional_transform(self->parent.lock(), [&](auto&&x) { return x->field_flickable_45.viewport_width.get(); })) -(float) 64) -(float) 64)), float(0), float(self->field_empty_131_layout_cache.get()[2])));
        case 3: return slint::private_api::convert_anonymous_rect(std::make_tuple(float(8), float(((slint::private_api::optional_or_default(slint::private_api::optional_transform(self->parent.lock(), [&](auto&&x) { return x->field_flickable_45.viewport_width.get(); })) -(float) 64) -(float) 64)), float(0), float(self->field_empty_131_layout_cache.get()[4])));
        case 4: return slint::private_api::convert_anonymous_rect(std::make_tuple(float(self->field_suggestions_flick_133.viewport_height.get()), float(self->field_suggestions_flick_133.viewport_width.get()), float(self->field_suggestions_flick_133.viewport_x.get()), float(self->field_suggestions_flick_133.viewport_y.get())));
        case 6: return slint::private_api::convert_anonymous_rect(std::make_tuple(float(8), float(self->field_empty_131_scroll_track_138_thumb_width.get()), float(self->field_empty_131_scroll_track_138_thumb_x.get()), float(0)));
        case 7: return slint::private_api::convert_anonymous_rect(std::make_tuple(float(8), float(((slint::private_api::optional_or_default(slint::private_api::optional_transform(self->parent.lock(), [&](auto&&x) { return x->field_flickable_45.viewport_width.get(); })) -(float) 64) -(float) 64)), float(0), float(0)));
    }
    return {};
}

auto Component_empty_131::accessible_role (uint32_t index) const -> slint::cbindgen_private::AccessibleRole{
    [[maybe_unused]] auto self = this;
    switch (index) {
        case 1: return slint::cbindgen_private::AccessibleRole::Text;
    }
    return {};
}

auto Component_empty_131::accessible_string_property (uint32_t index, slint::cbindgen_private::AccessibleStringProperty what) const -> std::optional<slint::SharedString>{
    [[maybe_unused]] auto self = this;
    switch ((index << 8) | uintptr_t(what)) {
        case (1 << 8) | uintptr_t(slint::cbindgen_private::AccessibleStringProperty::Label): return slint::SharedString(u8"You might also like");
    }
    return {};
}

auto Component_empty_131::accessibility_action (uint32_t index, const slint::cbindgen_private::AccessibilityAction &action) const -> void{
    [[maybe_unused]] auto self = this;
    switch ((index << 8) | uintptr_t(action.tag)) {
    }
    return ;
}

auto Component_empty_131::supported_accessibility_actions (uint32_t index) const -> uint32_t{
    [[maybe_unused]] auto self = this;
    switch (index) {
    }
    return {};
}

auto Component_empty_131::element_infos (uint32_t index) const -> std::optional<slint::SharedString>{
    [[maybe_unused]] auto self = this;
    switch (index) {
    }
    return {};
}

auto Component_empty_131::ensure_instantiated () const -> bool{
    [[maybe_unused]] auto self = this;
    bool _changed = false;
    _changed |= self->repeater_0.ensure_updated(self);
    return _changed;
}

auto Component_empty_131::visit_dynamic_children (uint32_t dyn_index, [[maybe_unused]] slint::private_api::TraversalOrder order, [[maybe_unused]] slint::private_api::ItemVisitorRefMut visitor) const -> uint64_t{
        auto self = this;
        switch(dyn_index) { 
        case 0: {
                return self->repeater_0.visit(order, visitor);
            } };
        std::abort();
}

auto Component_empty_131::subtree_range (uintptr_t dyn_index) const -> slint::private_api::IndexRange{
    [[maybe_unused]] auto self = this;
        switch(dyn_index) { 
        case 0: {
                self->repeater_0.track_instance_changes();
                return self->repeater_0.index_range();
            } };
        std::abort();
}

auto Component_empty_131::subtree_component (uintptr_t dyn_index, [[maybe_unused]] uintptr_t subtree_index, [[maybe_unused]] slint::private_api::ItemTreeWeak *result) const -> void{
    [[maybe_unused]] auto self = this;
        switch(dyn_index) { 
        case 0: {
                *result = self->repeater_0.instance_at(subtree_index);
                return;
            } };
        std::abort();
}

auto Component_empty_131::visit_children (slint::private_api::ItemTreeRef component, intptr_t index, slint::private_api::TraversalOrder order, slint::private_api::ItemVisitorRefMut visitor) -> uint64_t{
    static const auto dyn_visit = [] (const void *base,  [[maybe_unused]] slint::private_api::TraversalOrder order, [[maybe_unused]] slint::private_api::ItemVisitorRefMut visitor, [[maybe_unused]] uint32_t dyn_index) -> uint64_t {
        [[maybe_unused]] auto self = reinterpret_cast<const Component_empty_131*>(base);
        return self->visit_dynamic_children(dyn_index, order, visitor);
    };
    auto self_rc = reinterpret_cast<const Component_empty_131*>(component.instance)->self_weak.lock()->into_dyn();
    return slint::cbindgen_private::slint_visit_item_tree(&self_rc, get_item_tree(component) , index, order, visitor, dyn_visit);
}

auto Component_empty_131::get_item_ref (slint::private_api::ItemTreeRef component, uint32_t index) -> slint::private_api::ItemRef{
    return slint::private_api::get_item_ref(component, get_item_tree(component), item_array(), index);
}

auto Component_empty_131::get_subtree_range ([[maybe_unused]] slint::private_api::ItemTreeRef component, [[maybe_unused]] uint32_t dyn_index) -> slint::private_api::IndexRange{
    auto self = reinterpret_cast<const Component_empty_131*>(component.instance);
    return self->subtree_range(dyn_index);
}

auto Component_empty_131::get_subtree ([[maybe_unused]] slint::private_api::ItemTreeRef component, [[maybe_unused]] uint32_t dyn_index, [[maybe_unused]] uintptr_t subtree_index, [[maybe_unused]] slint::private_api::ItemTreeWeak *result) -> void{
    auto self = reinterpret_cast<const Component_empty_131*>(component.instance);
    self->subtree_component(dyn_index, subtree_index, result);
}

auto Component_empty_131::get_item_tree (slint::private_api::ItemTreeRef) -> slint::cbindgen_private::Slice<slint::private_api::ItemTreeNode>{
    return item_tree();
}

auto Component_empty_131::parent_node ([[maybe_unused]] slint::private_api::ItemTreeRef component, [[maybe_unused]] slint::private_api::ItemWeak *result) -> void{
    auto self = reinterpret_cast<const Component_empty_131*>(component.instance);
    auto parent = self->parent.lock().value();
    *result = { parent->self_weak, parent->tree_index_of_first_child + 19 };
}

auto Component_empty_131::embed_component ([[maybe_unused]] slint::private_api::ItemTreeRef component, [[maybe_unused]] const slint::private_api::ItemTreeWeak *parent_component, [[maybe_unused]] const uint32_t parent_index) -> bool{
    return false; /* todo! */
}

auto Component_empty_131::subtree_index ([[maybe_unused]] slint::private_api::ItemTreeRef component) -> uintptr_t{
    return std::numeric_limits<uintptr_t>::max();
}

auto Component_empty_131::item_tree () -> slint::cbindgen_private::Slice<slint::private_api::ItemTreeNode>{
    static const slint::private_api::ItemTreeNode children[] {
        slint::private_api::make_item_node(3, 1, 0, 0, false), 
slint::private_api::make_item_node(0, 4, 0, 1, true), 
slint::private_api::make_item_node(1, 4, 0, 2, false), 
slint::private_api::make_item_node(2, 6, 0, 3, false), 
slint::private_api::make_item_node(1, 5, 2, 4, false), 
slint::private_api::make_dyn_node(0, 4), 
slint::private_api::make_item_node(0, 8, 3, 5, false), 
slint::private_api::make_item_node(0, 8, 3, 6, false) };
    return slint::private_api::make_slice(std::span(children));
}

auto Component_empty_131::item_array () -> const slint::private_api::ItemArray{
    static const slint::private_api::ItemArrayEntry items[] {
        { SLINT_GET_ITEM_VTABLE(EmptyVTable),  offsetof(Component_empty_131, field_empty_131) }, 
{ SLINT_GET_ITEM_VTABLE(SimpleTextVTable),  offsetof(Component_empty_131, field_text_132) }, 
{ SLINT_GET_ITEM_VTABLE(FlickableVTable),  offsetof(Component_empty_131, field_suggestions_flick_133) }, 
{ SLINT_GET_ITEM_VTABLE(BasicBorderRectangleVTable),  offsetof(Component_empty_131, field_scroll_track_138) }, 
{ SLINT_GET_ITEM_VTABLE(EmptyVTable),  offsetof(Component_empty_131, field_suggestions_flick_viewport_134) }, 
{ SLINT_GET_ITEM_VTABLE(BasicBorderRectangleVTable),  offsetof(Component_empty_131, field_thumb_139) }, 
{ SLINT_GET_ITEM_VTABLE(TouchAreaVTable),  offsetof(Component_empty_131, field_thumb_ta_140) } };
    return slint::private_api::make_slice(std::span(items));
}

auto Component_empty_131::layout_info ([[maybe_unused]] slint::private_api::ItemTreeRef component, slint::cbindgen_private::Orientation o) -> slint::cbindgen_private::LayoutInfo{
    return reinterpret_cast<const Component_empty_131*>(component.instance)->layout_info(o);
}

auto Component_empty_131::ensure_instantiated ([[maybe_unused]] slint::private_api::ItemTreeRef component) -> bool{
    return reinterpret_cast<const Component_empty_131*>(component.instance)->ensure_instantiated();
}

auto Component_empty_131::item_geometry ([[maybe_unused]] slint::private_api::ItemTreeRef component, uint32_t index) -> slint::cbindgen_private::LogicalRect{
    return reinterpret_cast<const Component_empty_131*>(component.instance)->item_geometry(index);
}

auto Component_empty_131::accessible_role ([[maybe_unused]] slint::private_api::ItemTreeRef component, uint32_t index) -> slint::cbindgen_private::AccessibleRole{
    return reinterpret_cast<const Component_empty_131*>(component.instance)->accessible_role(index);
}

auto Component_empty_131::accessible_string_property ([[maybe_unused]] slint::private_api::ItemTreeRef component, uint32_t index, slint::cbindgen_private::AccessibleStringProperty what, slint::SharedString *result) -> bool{
    if (auto r = reinterpret_cast<const Component_empty_131*>(component.instance)->accessible_string_property(index, what)) { *result = *r; return true; } else { return false; }
}

auto Component_empty_131::accessibility_action ([[maybe_unused]] slint::private_api::ItemTreeRef component, uint32_t index, const slint::cbindgen_private::AccessibilityAction *action) -> void{
    reinterpret_cast<const Component_empty_131*>(component.instance)->accessibility_action(index, *action);
}

auto Component_empty_131::supported_accessibility_actions ([[maybe_unused]] slint::private_api::ItemTreeRef component, uint32_t index) -> uint32_t{
    return reinterpret_cast<const Component_empty_131*>(component.instance)->supported_accessibility_actions(index);
}

auto Component_empty_131::element_infos ([[maybe_unused]] slint::private_api::ItemTreeRef component, [[maybe_unused]] uint32_t index, [[maybe_unused]] slint::SharedString *result) -> bool{
    return false;
}

auto Component_empty_131::window_adapter ([[maybe_unused]] slint::private_api::ItemTreeRef component, [[maybe_unused]] bool do_create, [[maybe_unused]] slint::cbindgen_private::Option<slint::private_api::WindowAdapterRc>* result) -> void{
    *reinterpret_cast<slint::private_api::WindowAdapterRc*>(result) = reinterpret_cast<const Component_empty_131*>(component.instance)->globals->window().window_handle();
}

auto Component_empty_131::create (class DetailsView_root_32 const * parent) -> slint::ComponentHandle<Component_empty_131>{
    auto self_rc = vtable::VRc<slint::private_api::ItemTreeVTable, Component_empty_131>::make();
    auto self = const_cast<Component_empty_131 *>(&*self_rc);
    self->self_weak = vtable::VWeak(self_rc).into_dyn();
    slint::private_api::register_item_tree(&self_rc.into_dyn(), parent->globals->m_window);
    self->init(parent->globals, self->self_weak, 0, 1 , parent);
    return slint::ComponentHandle<Component_empty_131>{ self_rc };
}

Component_empty_131::~Component_empty_131 (){
    if (auto &window = globals->m_window) window->window_handle().unregister_item_tree(this, item_array());
}

auto Component_empty_131::init () -> void{
    user_init();
}

auto Component_empty_131::layout_item_info (slint::cbindgen_private::Orientation o, [[maybe_unused]] std::optional<size_t> child_index) const -> slint::cbindgen_private::LayoutItemInfo{
    return { layout_info({&static_vtable, const_cast<void *>(static_cast<const void *>(this))}, o) };
}

auto Component_empty_131::flexbox_layout_item_info (slint::cbindgen_private::Orientation o, [[maybe_unused]] std::optional<size_t> child_index) const -> slint::cbindgen_private::FlexboxLayoutItemInfo{
    auto base = layout_item_info(o, child_index); return { base.constraint, 0.0f, 0.0f, -1.0f, slint::cbindgen_private::FlexboxLayoutAlignSelf::Auto, 0 };
}

const slint::private_api::ItemTreeVTable Component_rectangle_142::static_vtable = { visit_children, get_item_ref, get_subtree_range, get_subtree, get_item_tree, parent_node, embed_component, subtree_index, layout_info, ensure_instantiated, item_geometry, accessible_role, accessible_string_property, accessibility_action, supported_accessibility_actions, element_infos, window_adapter, slint::private_api::drop_in_place<Component_rectangle_142>, slint::private_api::dealloc };

auto Component_rectangle_142::fn_empty_145_layoutinfo_v_with_constraint ([[maybe_unused]] float arg_0) const -> slint::cbindgen_private::LayoutInfo{
    [[maybe_unused]] auto self = this;
    return slint::private_api::box_layout_info(slint::private_api::make_slice<slint::cbindgen_private::LayoutItemInfo>(std::array<slint::cbindgen_private::LayoutItemInfo, 2>{ slint::cbindgen_private::LayoutItemInfo ( [&](const auto &a_0){ slint::cbindgen_private::LayoutItemInfo o{}; o.constraint = a_0; return o; }(self->field_rectangle_142_empty_146_layoutinfo_v.get()) ), slint::cbindgen_private::LayoutItemInfo ( [&](const auto &a_0){ slint::cbindgen_private::LayoutItemInfo o{}; o.constraint = a_0; return o; }([&]{ [[maybe_unused]] auto layout_info = slint::private_api::item_layout_info(SLINT_GET_ITEM_VTABLE(BasicBorderRectangleVTable), const_cast<slint::cbindgen_private::BasicBorderRectangle*>(&self->field_rectangle_151), slint::cbindgen_private::Orientation::Vertical, arg_0, &self->globals->window().window_handle(), self->self_weak.lock()->into_dyn(), self->tree_index_of_first_child + 4 - 1);;return [&](const auto &a_0, const auto &a_1, const auto &a_2, const auto &a_3, const auto &a_4, const auto &a_5){ slint::cbindgen_private::LayoutInfo o{}; o.max = a_0; o.max_percent = a_1; o.min = a_2; o.min_percent = a_3; o.preferred = a_4; o.stretch = a_5; return o; }(layout_info.max, layout_info.max_percent, layout_info.min, layout_info.min_percent, layout_info.preferred, self->field_rectangle_142_rectangle_151_vertical_stretch.get()); }()) ) }.data(), 2),self->field_rectangle_142_empty_145_spacing.get(),[&](const auto &a_0, const auto &a_1){ slint::cbindgen_private::Padding o{}; o.begin = a_0; o.end = a_1; return o; }(self->field_rectangle_142_empty_145_padding.get(), self->field_rectangle_142_empty_145_padding.get()),slint::cbindgen_private::LayoutAlignment::Stretch);
}

auto Component_rectangle_142::fn_rectangle_144_layoutinfo_v_with_constraint ([[maybe_unused]] float arg_0) const -> slint::cbindgen_private::LayoutInfo{
    [[maybe_unused]] auto self = this;
    return ([&](const auto &a_0, const auto &a_1, const auto &a_2, const auto &a_3, const auto &a_4, const auto &a_5){ slint::cbindgen_private::LayoutInfo o{}; o.max = a_0; o.max_percent = a_1; o.min = a_2; o.min_percent = a_3; o.preferred = a_4; o.stretch = a_5; return o; }(+3.4028234663852886e38, 100, 0, 0, 0, 1) + self->fn_empty_145_layoutinfo_v_with_constraint(arg_0));
}

auto Component_rectangle_142::init (const class SharedGlobals* globals,slint::cbindgen_private::ItemTreeWeak enclosing_component,uint32_t tree_index,uint32_t tree_index_of_first_child,class DetailsView_root_32 const *parent) -> void{
    auto self = this;
    self->self_weak = enclosing_component;
    self->globals = globals;
    this->tree_index_of_first_child = tree_index_of_first_child;
    self->tree_index = tree_index;
    self->parent = vtable::VRcMapped<slint::private_api::ItemTreeVTable, const DetailsView_root_32>(parent->self_weak.lock().value(), parent);
    self->field_rectangle_142.background.set(slint::Brush(slint::Color::from_argb_encoded(+4.279308571e9)).transparentize(0.15));
    self->field_rectangle_142_empty_145_layout_cache.set_binding([this]() {
                            [[maybe_unused]] auto self = this;
                            return slint::private_api::solve_box_layout([&](const auto &a_0, const auto &a_1, const auto &a_2, const auto &a_3, const auto &a_4){ slint::cbindgen_private::BoxLayoutData o{}; o.alignment = a_0; o.cells = a_1; o.padding = a_2; o.size = a_3; o.spacing = a_4; return o; }(slint::cbindgen_private::LayoutAlignment::Stretch, slint::private_api::make_slice<slint::cbindgen_private::LayoutItemInfo>(std::array<slint::cbindgen_private::LayoutItemInfo, 2>{ slint::cbindgen_private::LayoutItemInfo ( [&](const auto &a_0){ slint::cbindgen_private::LayoutItemInfo o{}; o.constraint = a_0; return o; }(self->field_rectangle_142_empty_146_layoutinfo_v.get()) ), slint::cbindgen_private::LayoutItemInfo ( [&](const auto &a_0){ slint::cbindgen_private::LayoutItemInfo o{}; o.constraint = a_0; return o; }([&]{ [[maybe_unused]] auto layout_info = slint::private_api::item_layout_info(SLINT_GET_ITEM_VTABLE(BasicBorderRectangleVTable), const_cast<slint::cbindgen_private::BasicBorderRectangle*>(&self->field_rectangle_151), slint::cbindgen_private::Orientation::Vertical, -1, &self->globals->window().window_handle(), self->self_weak.lock()->into_dyn(), self->tree_index_of_first_child + 4 - 1);;return [&](const auto &a_0, const auto &a_1, const auto &a_2, const auto &a_3, const auto &a_4, const auto &a_5){ slint::cbindgen_private::LayoutInfo o{}; o.max = a_0; o.max_percent = a_1; o.min = a_2; o.min_percent = a_3; o.preferred = a_4; o.stretch = a_5; return o; }(layout_info.max, layout_info.max_percent, layout_info.min, layout_info.min_percent, layout_info.preferred, 1); }()) ) }.data(), 2), [&](const auto &a_0, const auto &a_1){ slint::cbindgen_private::Padding o{}; o.begin = a_0; o.end = a_1; return o; }(20, 20), (slint::private_api::optional_or_default(slint::private_api::optional_transform(self->parent.lock(), [&](auto&&x) { return x->field_root_32_height.get(); })) -(float) 120), 12),slint::private_api::make_slice<int>(std::array<int, 0>{  }.data(), 0));
                        });
    self->field_rectangle_142_empty_145_layoutinfo_h.set_binding([this]() {
                            [[maybe_unused]] auto self = this;
                            return slint::private_api::box_layout_info_ortho(slint::private_api::make_slice<slint::cbindgen_private::LayoutItemInfo>(std::array<slint::cbindgen_private::LayoutItemInfo, 2>{ slint::cbindgen_private::LayoutItemInfo ( [&](const auto &a_0){ slint::cbindgen_private::LayoutItemInfo o{}; o.constraint = a_0; return o; }(self->field_rectangle_142_empty_146_layoutinfo_h.get()) ), slint::cbindgen_private::LayoutItemInfo ( [&](const auto &a_0){ slint::cbindgen_private::LayoutItemInfo o{}; o.constraint = a_0; return o; }(slint::private_api::item_layout_info(SLINT_GET_ITEM_VTABLE(BasicBorderRectangleVTable), const_cast<slint::cbindgen_private::BasicBorderRectangle*>(&self->field_rectangle_151), slint::cbindgen_private::Orientation::Horizontal, -1, &self->globals->window().window_handle(), self->self_weak.lock()->into_dyn(), self->tree_index_of_first_child + 4 - 1)) ) }.data(), 2),[&](const auto &a_0, const auto &a_1){ slint::cbindgen_private::Padding o{}; o.begin = a_0; o.end = a_1; return o; }(20, 20));
                        });
    self->field_rectangle_142_empty_145_layoutinfo_v.set_binding([this]() {
                            [[maybe_unused]] auto self = this;
                            return slint::private_api::box_layout_info(slint::private_api::make_slice<slint::cbindgen_private::LayoutItemInfo>(std::array<slint::cbindgen_private::LayoutItemInfo, 2>{ slint::cbindgen_private::LayoutItemInfo ( [&](const auto &a_0){ slint::cbindgen_private::LayoutItemInfo o{}; o.constraint = a_0; return o; }(self->field_rectangle_142_empty_146_layoutinfo_v.get()) ), slint::cbindgen_private::LayoutItemInfo ( [&](const auto &a_0){ slint::cbindgen_private::LayoutItemInfo o{}; o.constraint = a_0; return o; }([&]{ [[maybe_unused]] auto layout_info = slint::private_api::item_layout_info(SLINT_GET_ITEM_VTABLE(BasicBorderRectangleVTable), const_cast<slint::cbindgen_private::BasicBorderRectangle*>(&self->field_rectangle_151), slint::cbindgen_private::Orientation::Vertical, -1, &self->globals->window().window_handle(), self->self_weak.lock()->into_dyn(), self->tree_index_of_first_child + 4 - 1);;return [&](const auto &a_0, const auto &a_1, const auto &a_2, const auto &a_3, const auto &a_4, const auto &a_5){ slint::cbindgen_private::LayoutInfo o{}; o.max = a_0; o.max_percent = a_1; o.min = a_2; o.min_percent = a_3; o.preferred = a_4; o.stretch = a_5; return o; }(layout_info.max, layout_info.max_percent, layout_info.min, layout_info.min_percent, layout_info.preferred, 1); }()) ) }.data(), 2),12,[&](const auto &a_0, const auto &a_1){ slint::cbindgen_private::Padding o{}; o.begin = a_0; o.end = a_1; return o; }(20, 20),slint::cbindgen_private::LayoutAlignment::Stretch);
                        });
    self->field_rectangle_142_empty_145_padding.set(20);
    self->field_rectangle_142_empty_145_spacing.set(12);
    self->field_rectangle_142_empty_146_layout_cache.set_binding([this]() {
                            [[maybe_unused]] auto self = this;
                            return slint::private_api::solve_box_layout([&](const auto &a_0, const auto &a_1, const auto &a_2, const auto &a_3, const auto &a_4){ slint::cbindgen_private::BoxLayoutData o{}; o.alignment = a_0; o.cells = a_1; o.padding = a_2; o.size = a_3; o.spacing = a_4; return o; }(slint::cbindgen_private::LayoutAlignment::SpaceBetween, slint::private_api::make_slice<slint::cbindgen_private::LayoutItemInfo>(std::array<slint::cbindgen_private::LayoutItemInfo, 2>{ slint::cbindgen_private::LayoutItemInfo ( [&](const auto &a_0){ slint::cbindgen_private::LayoutItemInfo o{}; o.constraint = a_0; return o; }(slint::private_api::item_layout_info(SLINT_GET_ITEM_VTABLE(SimpleTextVTable), const_cast<slint::cbindgen_private::SimpleText*>(&self->field_text_147), slint::cbindgen_private::Orientation::Horizontal, -1, &self->globals->window().window_handle(), self->self_weak.lock()->into_dyn(), self->tree_index_of_first_child + 5 - 1)) ), slint::cbindgen_private::LayoutItemInfo ( [&](const auto &a_0){ slint::cbindgen_private::LayoutItemInfo o{}; o.constraint = a_0; return o; }([&]{ [[maybe_unused]] auto layout_info = self->field_rectangle_142_rectangle_148_layoutinfo_h.get();;return [&](const auto &a_0, const auto &a_1, const auto &a_2, const auto &a_3, const auto &a_4, const auto &a_5){ slint::cbindgen_private::LayoutInfo o{}; o.max = a_0; o.max_percent = a_1; o.min = a_2; o.min_percent = a_3; o.preferred = a_4; o.stretch = a_5; return o; }(80, layout_info.max_percent, 80, layout_info.min_percent, layout_info.preferred, layout_info.stretch); }()) ) }.data(), 2), [&](const auto &a_0, const auto &a_1){ slint::cbindgen_private::Padding o{}; o.begin = a_0; o.end = a_1; return o; }(0, 0), (((slint::private_api::optional_or_default(slint::private_api::optional_transform(self->parent.lock(), [&](auto&&x) { return x->field_root_32_width.get(); })) -(float) 120) -(float) 20) -(float) 20), 0),slint::private_api::make_slice<int>(std::array<int, 0>{  }.data(), 0));
                        });
    self->field_rectangle_142_empty_146_layoutinfo_h.set_binding([this]() {
                            [[maybe_unused]] auto self = this;
                            return slint::private_api::box_layout_info(slint::private_api::make_slice<slint::cbindgen_private::LayoutItemInfo>(std::array<slint::cbindgen_private::LayoutItemInfo, 2>{ slint::cbindgen_private::LayoutItemInfo ( [&](const auto &a_0){ slint::cbindgen_private::LayoutItemInfo o{}; o.constraint = a_0; return o; }(slint::private_api::item_layout_info(SLINT_GET_ITEM_VTABLE(SimpleTextVTable), const_cast<slint::cbindgen_private::SimpleText*>(&self->field_text_147), slint::cbindgen_private::Orientation::Horizontal, -1, &self->globals->window().window_handle(), self->self_weak.lock()->into_dyn(), self->tree_index_of_first_child + 5 - 1)) ), slint::cbindgen_private::LayoutItemInfo ( [&](const auto &a_0){ slint::cbindgen_private::LayoutItemInfo o{}; o.constraint = a_0; return o; }([&]{ [[maybe_unused]] auto layout_info = self->field_rectangle_142_rectangle_148_layoutinfo_h.get();;return [&](const auto &a_0, const auto &a_1, const auto &a_2, const auto &a_3, const auto &a_4, const auto &a_5){ slint::cbindgen_private::LayoutInfo o{}; o.max = a_0; o.max_percent = a_1; o.min = a_2; o.min_percent = a_3; o.preferred = a_4; o.stretch = a_5; return o; }(80, layout_info.max_percent, 80, layout_info.min_percent, layout_info.preferred, layout_info.stretch); }()) ) }.data(), 2),0,[&](const auto &a_0, const auto &a_1){ slint::cbindgen_private::Padding o{}; o.begin = a_0; o.end = a_1; return o; }(0, 0),slint::cbindgen_private::LayoutAlignment::SpaceBetween);
                        });
    self->field_rectangle_142_empty_146_layoutinfo_v.set_binding([this]() {
                            [[maybe_unused]] auto self = this;
                            return slint::private_api::box_layout_info_ortho(slint::private_api::make_slice<slint::cbindgen_private::LayoutItemInfo>(std::array<slint::cbindgen_private::LayoutItemInfo, 2>{ slint::cbindgen_private::LayoutItemInfo ( [&](const auto &a_0){ slint::cbindgen_private::LayoutItemInfo o{}; o.constraint = a_0; return o; }(slint::private_api::item_layout_info(SLINT_GET_ITEM_VTABLE(SimpleTextVTable), const_cast<slint::cbindgen_private::SimpleText*>(&self->field_text_147), slint::cbindgen_private::Orientation::Vertical, -1, &self->globals->window().window_handle(), self->self_weak.lock()->into_dyn(), self->tree_index_of_first_child + 5 - 1)) ), slint::cbindgen_private::LayoutItemInfo ( [&](const auto &a_0){ slint::cbindgen_private::LayoutItemInfo o{}; o.constraint = a_0; return o; }([&]{ [[maybe_unused]] auto layout_info = self->field_rectangle_142_rectangle_148_layoutinfo_v.get();;return [&](const auto &a_0, const auto &a_1, const auto &a_2, const auto &a_3, const auto &a_4, const auto &a_5){ slint::cbindgen_private::LayoutInfo o{}; o.max = a_0; o.max_percent = a_1; o.min = a_2; o.min_percent = a_3; o.preferred = a_4; o.stretch = a_5; return o; }(30, layout_info.max_percent, 30, layout_info.min_percent, layout_info.preferred, layout_info.stretch); }()) ) }.data(), 2),[&](const auto &a_0, const auto &a_1){ slint::cbindgen_private::Padding o{}; o.begin = a_0; o.end = a_1; return o; }(0, 0));
                        });
    self->field_rectangle_142_log_text_155_min_height.set_binding([this]() {
                            [[maybe_unused]] auto self = this;
                            return slint::private_api::item_layout_info(SLINT_GET_ITEM_VTABLE(ComplexTextVTable), const_cast<slint::cbindgen_private::ComplexText*>(&self->field_log_text_155), slint::cbindgen_private::Orientation::Vertical, -1, &self->globals->window().window_handle(), self->self_weak.lock()->into_dyn(), self->tree_index_of_first_child + 12 - 1).min;
                        });
    self->field_rectangle_142_log_text_155_preferred_height.set_binding([this]() {
                            [[maybe_unused]] auto self = this;
                            return slint::private_api::item_layout_info(SLINT_GET_ITEM_VTABLE(ComplexTextVTable), const_cast<slint::cbindgen_private::ComplexText*>(&self->field_log_text_155), slint::cbindgen_private::Orientation::Vertical, -1, &self->globals->window().window_handle(), self->self_weak.lock()->into_dyn(), self->tree_index_of_first_child + 12 - 1).preferred;
                        });
    self->field_rectangle_142_rectangle_144_width.set_binding([this]() {
                            [[maybe_unused]] auto self = this;
                            return (slint::private_api::optional_or_default(slint::private_api::optional_transform(self->parent.lock(), [&](auto&&x) { return x->field_root_32_width.get(); })) -(float) 120);
                        });
    self->field_rectangle_142_rectangle_148_layoutinfo_h.set_binding([this]() {
                            [[maybe_unused]] auto self = this;
                            return ([&](const auto &a_0, const auto &a_1, const auto &a_2, const auto &a_3, const auto &a_4, const auto &a_5){ slint::cbindgen_private::LayoutInfo o{}; o.max = a_0; o.max_percent = a_1; o.min = a_2; o.min_percent = a_3; o.preferred = a_4; o.stretch = a_5; return o; }(+3.4028234663852886e38, 100, 0, 0, 0, 1) + slint::private_api::item_layout_info(SLINT_GET_ITEM_VTABLE(SimpleTextVTable), const_cast<slint::cbindgen_private::SimpleText*>(&self->field_text_150), slint::cbindgen_private::Orientation::Horizontal, -1, &self->globals->window().window_handle(), self->self_weak.lock()->into_dyn(), self->tree_index_of_first_child + 8 - 1));
                        });
    self->field_rectangle_142_rectangle_148_layoutinfo_v.set_binding([this]() {
                            [[maybe_unused]] auto self = this;
                            return ([&](const auto &a_0, const auto &a_1, const auto &a_2, const auto &a_3, const auto &a_4, const auto &a_5){ slint::cbindgen_private::LayoutInfo o{}; o.max = a_0; o.max_percent = a_1; o.min = a_2; o.min_percent = a_3; o.preferred = a_4; o.stretch = a_5; return o; }(+3.4028234663852886e38, 100, 0, 0, 0, 1) + slint::private_api::item_layout_info(SLINT_GET_ITEM_VTABLE(SimpleTextVTable), const_cast<slint::cbindgen_private::SimpleText*>(&self->field_text_150), slint::cbindgen_private::Orientation::Vertical, -1, &self->globals->window().window_handle(), self->self_weak.lock()->into_dyn(), self->tree_index_of_first_child + 8 - 1));
                        });
    self->field_rectangle_142_rectangle_151_vertical_stretch.set(1);
    self->field_rectangle_142_text_150_min_height.set_binding([this]() {
                            [[maybe_unused]] auto self = this;
                            return slint::private_api::item_layout_info(SLINT_GET_ITEM_VTABLE(SimpleTextVTable), const_cast<slint::cbindgen_private::SimpleText*>(&self->field_text_150), slint::cbindgen_private::Orientation::Vertical, -1, &self->globals->window().window_handle(), self->self_weak.lock()->into_dyn(), self->tree_index_of_first_child + 8 - 1).min;
                        });
    self->field_rectangle_142_text_150_min_width.set_binding([this]() {
                            [[maybe_unused]] auto self = this;
                            return slint::private_api::item_layout_info(SLINT_GET_ITEM_VTABLE(SimpleTextVTable), const_cast<slint::cbindgen_private::SimpleText*>(&self->field_text_150), slint::cbindgen_private::Orientation::Horizontal, -1, &self->globals->window().window_handle(), self->self_weak.lock()->into_dyn(), self->tree_index_of_first_child + 8 - 1).min;
                        });
    self->field_rectangle_142_text_150_preferred_height.set_binding([this]() {
                            [[maybe_unused]] auto self = this;
                            return slint::private_api::item_layout_info(SLINT_GET_ITEM_VTABLE(SimpleTextVTable), const_cast<slint::cbindgen_private::SimpleText*>(&self->field_text_150), slint::cbindgen_private::Orientation::Vertical, -1, &self->globals->window().window_handle(), self->self_weak.lock()->into_dyn(), self->tree_index_of_first_child + 8 - 1).preferred;
                        });
    self->field_rectangle_142_text_150_preferred_width.set_binding([this]() {
                            [[maybe_unused]] auto self = this;
                            return slint::private_api::item_layout_info(SLINT_GET_ITEM_VTABLE(SimpleTextVTable), const_cast<slint::cbindgen_private::SimpleText*>(&self->field_text_150), slint::cbindgen_private::Orientation::Horizontal, -1, &self->globals->window().window_handle(), self->self_weak.lock()->into_dyn(), self->tree_index_of_first_child + 8 - 1).preferred;
                        });
    self->field_toucharea_143.enabled.set(true);
    self->field_rectangle_144.background.set(slint::Brush(slint::Color::from_argb_encoded(+4.279769125e9)));
    self->field_rectangle_144.border_color.set(slint::Brush(slint::Color::from_argb_encoded(+4.28273033e9)));
    self->field_rectangle_144.border_radius.set(14);
    self->field_rectangle_144.border_width.set(1);
    self->field_text_147.color.set(slint::Brush(slint::Color::from_argb_encoded(+4.291679988e9)));
    self->field_text_147.font_size.set(15);
    self->field_text_147.font_weight.set(static_cast<int>(700));
    self->field_text_147.height.set_binding([this]() {
                            [[maybe_unused]] auto self = this;
                            return self->field_rectangle_142_empty_145_layout_cache.get()[1];
                        });
    self->field_text_147.text.set(slint::SharedString(u8"pacman output"));
    self->field_text_147.vertical_alignment.set(slint::cbindgen_private::TextVerticalAlignment::Center);
    self->field_text_147.width.set_binding([this]() {
                            [[maybe_unused]] auto self = this;
                            return self->field_rectangle_142_empty_146_layout_cache.get()[1];
                        });
    self->field_rectangle_148.background.set_binding([this]() {
                            [[maybe_unused]] auto self = this;
                            return slint::Brush((self->field_close_ta_149.has_hover.get() ? slint::Color::from_argb_encoded(+4.283980656e9) : slint::Color::from_argb_encoded(+4.28273033e9)));
                        });
    self->field_rectangle_148.border_radius.set(8);
    self->field_close_ta_149.clicked.set_handler(
                [this]() {
                    [[maybe_unused]] auto self = this;
                    slint::private_api::optional_then(self->parent.lock(), [&](auto&&x) { x->field_root_32_show_console.set(false); });
                });
    self->field_close_ta_149.enabled.set(true);
    self->field_text_150.color.set(slint::Brush(slint::Color::from_argb_encoded(+4.291679988e9)));
    self->field_text_150.font_size.set(12);
    self->field_text_150.font_weight.set(static_cast<int>(700));
    self->field_text_150.height.set_binding([this]() {
                            [[maybe_unused]] auto self = this;
                            return std::max<float>(self->field_rectangle_142_text_150_preferred_height.get(), self->field_rectangle_142_text_150_min_height.get());
                        });
    self->field_text_150.horizontal_alignment.set(slint::cbindgen_private::TextHorizontalAlignment::Center);
    self->field_text_150.text.set(slint::SharedString(u8"Close"));
    self->field_text_150.vertical_alignment.set(slint::cbindgen_private::TextVerticalAlignment::Center);
    self->field_text_150.width.set_binding([this]() {
                            [[maybe_unused]] auto self = this;
                            return std::max<float>(self->field_rectangle_142_text_150_preferred_width.get(), self->field_rectangle_142_text_150_min_width.get());
                        });
    self->field_rectangle_151.background.set(slint::Brush(slint::Color::from_argb_encoded(+4.279308571e9)));
    self->field_rectangle_151.border_radius.set(8);
    self->field__clip_152.border_bottom_left_radius.set(8);
    self->field__clip_152.border_bottom_right_radius.set(8);
    self->field__clip_152.border_top_left_radius.set(8);
    self->field__clip_152.border_top_right_radius.set(8);
    self->field__clip_152.clip.set(true);
    self->field_flickable_153.interactive.set(true);
    self->field_flickable_153.viewport_height.set_binding([this]() {
                            [[maybe_unused]] auto self = this;
                            return std::max<float>(self->field_rectangle_142_empty_145_layout_cache.get()[3], (self->field_log_text_155.height.get() + 20));
                        });
    self->field_flickable_153.viewport_width.set_binding([this]() {
                            [[maybe_unused]] auto self = this;
                            return (((slint::private_api::optional_or_default(slint::private_api::optional_transform(self->parent.lock(), [&](auto&&x) { return x->field_root_32_width.get(); })) -(float) 120) -(float) 20) -(float) 20);
                        });
    self->field_log_text_155.color.set(slint::Brush(slint::Color::from_argb_encoded(+4.289127329e9)));
    self->field_log_text_155.font_family.set(slint::SharedString(u8"monospace"));
    self->field_log_text_155.font_size.set(11);
    self->field_log_text_155.height.set_binding([this]() {
                            [[maybe_unused]] auto self = this;
                            return std::max<float>(self->field_rectangle_142_log_text_155_preferred_height.get(), self->field_rectangle_142_log_text_155_min_height.get());
                        });
    self->field_log_text_155.text.set_binding([this]() {
                            [[maybe_unused]] auto self = this;
                            return slint::private_api::optional_or_default(slint::private_api::optional_transform(self->parent.lock(), [&](auto&&x) { return x->field_root_32_install_state.get(); })).console_log;
                        });
    self->field_log_text_155.width.set_binding([this]() {
                            [[maybe_unused]] auto self = this;
                            return ((((slint::private_api::optional_or_default(slint::private_api::optional_transform(self->parent.lock(), [&](auto&&x) { return x->field_root_32_width.get(); })) -(float) 120) -(float) 20) -(float) 20) -(float) 20);
                        });
    self->field_log_text_155.wrap.set(slint::cbindgen_private::TextWrap::WordWrap);
    self->field_rectangle_142.background.set_constant();
    self->field_rectangle_142_empty_145_padding.set_constant();
    self->field_rectangle_142_empty_145_spacing.set_constant();
    self->field_rectangle_142_rectangle_151_vertical_stretch.set_constant();
    self->field_toucharea_143.enabled.set_constant();
    self->field_toucharea_143.mouse_cursor.set_constant();
    self->field_rectangle_144.background.set_constant();
    self->field_rectangle_144.border_color.set_constant();
    self->field_rectangle_144.border_radius.set_constant();
    self->field_rectangle_144.border_width.set_constant();
    self->field_text_147.color.set_constant();
    self->field_text_147.font_size.set_constant();
    self->field_text_147.font_weight.set_constant();
    self->field_text_147.horizontal_alignment.set_constant();
    self->field_text_147.text.set_constant();
    self->field_text_147.vertical_alignment.set_constant();
    self->field_rectangle_148.border_color.set_constant();
    self->field_rectangle_148.border_radius.set_constant();
    self->field_rectangle_148.border_width.set_constant();
    self->field_close_ta_149.enabled.set_constant();
    self->field_close_ta_149.mouse_cursor.set_constant();
    self->field_text_150.color.set_constant();
    self->field_text_150.font_size.set_constant();
    self->field_text_150.font_weight.set_constant();
    self->field_text_150.horizontal_alignment.set_constant();
    self->field_text_150.text.set_constant();
    self->field_text_150.vertical_alignment.set_constant();
    self->field_rectangle_151.background.set_constant();
    self->field_rectangle_151.border_color.set_constant();
    self->field_rectangle_151.border_radius.set_constant();
    self->field_rectangle_151.border_width.set_constant();
    self->field__clip_152.border_bottom_left_radius.set_constant();
    self->field__clip_152.border_bottom_right_radius.set_constant();
    self->field__clip_152.border_top_left_radius.set_constant();
    self->field__clip_152.border_top_right_radius.set_constant();
    self->field__clip_152.border_width.set_constant();
    self->field_flickable_153.interactive.set_constant();
    self->field_log_text_155.color.set_constant();
    self->field_log_text_155.font_family.set_constant();
    self->field_log_text_155.font_italic.set_constant();
    self->field_log_text_155.font_size.set_constant();
    self->field_log_text_155.font_weight.set_constant();
    self->field_log_text_155.horizontal_alignment.set_constant();
    self->field_log_text_155.letter_spacing.set_constant();
    self->field_log_text_155.overflow.set_constant();
    self->field_log_text_155.stroke.set_constant();
    self->field_log_text_155.stroke_style.set_constant();
    self->field_log_text_155.stroke_width.set_constant();
    self->field_log_text_155.vertical_alignment.set_constant();
    self->field_log_text_155.wrap.set_constant();
}

auto Component_rectangle_142::user_init () -> void{
    [[maybe_unused]] auto self = this;
}

auto Component_rectangle_142::layout_info (slint::cbindgen_private::Orientation o) const -> slint::cbindgen_private::LayoutInfo{
    [[maybe_unused]] auto self = this;
    return o == slint::cbindgen_private::Orientation::Horizontal ? slint::private_api::item_layout_info(SLINT_GET_ITEM_VTABLE(RectangleVTable), const_cast<slint::cbindgen_private::Rectangle*>(&self->field_rectangle_142), slint::cbindgen_private::Orientation::Horizontal, -1, &self->globals->window().window_handle(), self->self_weak.lock()->into_dyn(), self->tree_index) : slint::private_api::item_layout_info(SLINT_GET_ITEM_VTABLE(RectangleVTable), const_cast<slint::cbindgen_private::Rectangle*>(&self->field_rectangle_142), slint::cbindgen_private::Orientation::Vertical, -1, &self->globals->window().window_handle(), self->self_weak.lock()->into_dyn(), self->tree_index);
}

auto Component_rectangle_142::item_geometry (uint32_t index) const -> slint::cbindgen_private::Rect{
    [[maybe_unused]] auto self = this;
    switch (index) {
        case 0: return slint::private_api::convert_anonymous_rect(std::make_tuple(float(slint::private_api::optional_or_default(slint::private_api::optional_transform(self->parent.lock(), [&](auto&&x) { return x->field_root_32_height.get(); }))), float(slint::private_api::optional_or_default(slint::private_api::optional_transform(self->parent.lock(), [&](auto&&x) { return x->field_root_32_width.get(); }))), float(0), float(0)));
        case 1: return slint::private_api::convert_anonymous_rect(std::make_tuple(float(slint::private_api::optional_or_default(slint::private_api::optional_transform(self->parent.lock(), [&](auto&&x) { return x->field_root_32_height.get(); }))), float(slint::private_api::optional_or_default(slint::private_api::optional_transform(self->parent.lock(), [&](auto&&x) { return x->field_root_32_width.get(); }))), float(0), float(0)));
        case 2: return slint::private_api::convert_anonymous_rect(std::make_tuple(float((slint::private_api::optional_or_default(slint::private_api::optional_transform(self->parent.lock(), [&](auto&&x) { return x->field_root_32_height.get(); })) -(float) 120)), float((slint::private_api::optional_or_default(slint::private_api::optional_transform(self->parent.lock(), [&](auto&&x) { return x->field_root_32_width.get(); })) -(float) 120)), float(60), float(60)));
        case 3: return slint::private_api::convert_anonymous_rect(std::make_tuple(float(self->field_rectangle_142_empty_145_layout_cache.get()[1]), float((((slint::private_api::optional_or_default(slint::private_api::optional_transform(self->parent.lock(), [&](auto&&x) { return x->field_root_32_width.get(); })) -(float) 120) -(float) 20) -(float) 20)), float(20), float(self->field_rectangle_142_empty_145_layout_cache.get()[0])));
        case 4: return slint::private_api::convert_anonymous_rect(std::make_tuple(float(self->field_rectangle_142_empty_145_layout_cache.get()[3]), float((((slint::private_api::optional_or_default(slint::private_api::optional_transform(self->parent.lock(), [&](auto&&x) { return x->field_root_32_width.get(); })) -(float) 120) -(float) 20) -(float) 20)), float(20), float(self->field_rectangle_142_empty_145_layout_cache.get()[2])));
        case 5: return slint::private_api::convert_anonymous_rect(std::make_tuple(float(self->field_rectangle_142_empty_145_layout_cache.get()[1]), float(self->field_rectangle_142_empty_146_layout_cache.get()[1]), float(self->field_rectangle_142_empty_146_layout_cache.get()[0]), float(0)));
        case 6: return slint::private_api::convert_anonymous_rect(std::make_tuple(float(30), float(80), float(self->field_rectangle_142_empty_146_layout_cache.get()[2]), float(0)));
        case 7: return slint::private_api::convert_anonymous_rect(std::make_tuple(float(30), float(80), float(0), float(0)));
        case 8: return slint::private_api::convert_anonymous_rect(std::make_tuple(float(self->field_text_150.height.get()), float(self->field_text_150.width.get()), float(((80 -(float) self->field_text_150.width.get()) /(float) 2)), float(((30 -(float) self->field_text_150.height.get()) /(float) 2))));
        case 9: return slint::private_api::convert_anonymous_rect(std::make_tuple(float(self->field_rectangle_142_empty_145_layout_cache.get()[3]), float((((slint::private_api::optional_or_default(slint::private_api::optional_transform(self->parent.lock(), [&](auto&&x) { return x->field_root_32_width.get(); })) -(float) 120) -(float) 20) -(float) 20)), float(0), float(0)));
        case 10: return slint::private_api::convert_anonymous_rect(std::make_tuple(float(self->field_rectangle_142_empty_145_layout_cache.get()[3]), float((((slint::private_api::optional_or_default(slint::private_api::optional_transform(self->parent.lock(), [&](auto&&x) { return x->field_root_32_width.get(); })) -(float) 120) -(float) 20) -(float) 20)), float(0), float(0)));
        case 11: return slint::private_api::convert_anonymous_rect(std::make_tuple(float(self->field_flickable_153.viewport_height.get()), float(self->field_flickable_153.viewport_width.get()), float(self->field_flickable_153.viewport_x.get()), float(self->field_flickable_153.viewport_y.get())));
        case 12: return slint::private_api::convert_anonymous_rect(std::make_tuple(float(self->field_log_text_155.height.get()), float(((((slint::private_api::optional_or_default(slint::private_api::optional_transform(self->parent.lock(), [&](auto&&x) { return x->field_root_32_width.get(); })) -(float) 120) -(float) 20) -(float) 20) -(float) 20)), float(10), float(10)));
    }
    return {};
}

auto Component_rectangle_142::accessible_role (uint32_t index) const -> slint::cbindgen_private::AccessibleRole{
    [[maybe_unused]] auto self = this;
    switch (index) {
        case 5: return slint::cbindgen_private::AccessibleRole::Text;
        case 8: return slint::cbindgen_private::AccessibleRole::Text;
        case 12: return slint::cbindgen_private::AccessibleRole::Text;
    }
    return {};
}

auto Component_rectangle_142::accessible_string_property (uint32_t index, slint::cbindgen_private::AccessibleStringProperty what) const -> std::optional<slint::SharedString>{
    [[maybe_unused]] auto self = this;
    switch ((index << 8) | uintptr_t(what)) {
        case (5 << 8) | uintptr_t(slint::cbindgen_private::AccessibleStringProperty::Label): return slint::SharedString(u8"pacman output");
        case (8 << 8) | uintptr_t(slint::cbindgen_private::AccessibleStringProperty::Label): return slint::SharedString(u8"Close");
        case (12 << 8) | uintptr_t(slint::cbindgen_private::AccessibleStringProperty::Label): return slint::private_api::optional_or_default(slint::private_api::optional_transform(self->parent.lock(), [&](auto&&x) { return x->field_root_32_install_state.get(); })).console_log;
    }
    return {};
}

auto Component_rectangle_142::accessibility_action (uint32_t index, const slint::cbindgen_private::AccessibilityAction &action) const -> void{
    [[maybe_unused]] auto self = this;
    switch ((index << 8) | uintptr_t(action.tag)) {
    }
    return ;
}

auto Component_rectangle_142::supported_accessibility_actions (uint32_t index) const -> uint32_t{
    [[maybe_unused]] auto self = this;
    switch (index) {
    }
    return {};
}

auto Component_rectangle_142::element_infos (uint32_t index) const -> std::optional<slint::SharedString>{
    [[maybe_unused]] auto self = this;
    switch (index) {
    }
    return {};
}

auto Component_rectangle_142::ensure_instantiated () const -> bool{
    [[maybe_unused]] auto self = this;
    bool _changed = false;
    return _changed;
}

auto Component_rectangle_142::visit_children (slint::private_api::ItemTreeRef component, intptr_t index, slint::private_api::TraversalOrder order, slint::private_api::ItemVisitorRefMut visitor) -> uint64_t{
    static const auto dyn_visit = [] (const void *base,  [[maybe_unused]] slint::private_api::TraversalOrder order, [[maybe_unused]] slint::private_api::ItemVisitorRefMut visitor, [[maybe_unused]] uint32_t dyn_index) -> uint64_t {
        [[maybe_unused]] auto self = reinterpret_cast<const Component_rectangle_142*>(base);
        std::abort();
    };
    auto self_rc = reinterpret_cast<const Component_rectangle_142*>(component.instance)->self_weak.lock()->into_dyn();
    return slint::cbindgen_private::slint_visit_item_tree(&self_rc, get_item_tree(component) , index, order, visitor, dyn_visit);
}

auto Component_rectangle_142::get_item_ref (slint::private_api::ItemTreeRef component, uint32_t index) -> slint::private_api::ItemRef{
    return slint::private_api::get_item_ref(component, get_item_tree(component), item_array(), index);
}

auto Component_rectangle_142::get_subtree_range ([[maybe_unused]] slint::private_api::ItemTreeRef component, [[maybe_unused]] uint32_t dyn_index) -> slint::private_api::IndexRange{
        std::abort();
}

auto Component_rectangle_142::get_subtree ([[maybe_unused]] slint::private_api::ItemTreeRef component, [[maybe_unused]] uint32_t dyn_index, [[maybe_unused]] uintptr_t subtree_index, [[maybe_unused]] slint::private_api::ItemTreeWeak *result) -> void{
        std::abort();
}

auto Component_rectangle_142::get_item_tree (slint::private_api::ItemTreeRef) -> slint::cbindgen_private::Slice<slint::private_api::ItemTreeNode>{
    return item_tree();
}

auto Component_rectangle_142::parent_node ([[maybe_unused]] slint::private_api::ItemTreeRef component, [[maybe_unused]] slint::private_api::ItemWeak *result) -> void{
    auto self = reinterpret_cast<const Component_rectangle_142*>(component.instance);
    auto parent = self->parent.lock().value();
    *result = { parent->self_weak, parent->tree_index_of_first_child + 2 };
}

auto Component_rectangle_142::embed_component ([[maybe_unused]] slint::private_api::ItemTreeRef component, [[maybe_unused]] const slint::private_api::ItemTreeWeak *parent_component, [[maybe_unused]] const uint32_t parent_index) -> bool{
    return false; /* todo! */
}

auto Component_rectangle_142::subtree_index ([[maybe_unused]] slint::private_api::ItemTreeRef component) -> uintptr_t{
    return std::numeric_limits<uintptr_t>::max();
}

auto Component_rectangle_142::item_tree () -> slint::cbindgen_private::Slice<slint::private_api::ItemTreeNode>{
    static const slint::private_api::ItemTreeNode children[] {
        slint::private_api::make_item_node(2, 1, 0, 0, false), 
slint::private_api::make_item_node(0, 3, 0, 1, false), 
slint::private_api::make_item_node(2, 3, 0, 2, false), 
slint::private_api::make_item_node(2, 5, 2, 3, false), 
slint::private_api::make_item_node(1, 9, 2, 4, false), 
slint::private_api::make_item_node(0, 7, 3, 5, true), 
slint::private_api::make_item_node(2, 7, 3, 6, false), 
slint::private_api::make_item_node(0, 9, 6, 7, false), 
slint::private_api::make_item_node(0, 9, 6, 8, true), 
slint::private_api::make_item_node(1, 10, 4, 9, false), 
slint::private_api::make_item_node(1, 11, 9, 10, false), 
slint::private_api::make_item_node(1, 12, 10, 11, false), 
slint::private_api::make_item_node(0, 13, 11, 12, true) };
    return slint::private_api::make_slice(std::span(children));
}

auto Component_rectangle_142::item_array () -> const slint::private_api::ItemArray{
    static const slint::private_api::ItemArrayEntry items[] {
        { SLINT_GET_ITEM_VTABLE(RectangleVTable),  offsetof(Component_rectangle_142, field_rectangle_142) }, 
{ SLINT_GET_ITEM_VTABLE(TouchAreaVTable),  offsetof(Component_rectangle_142, field_toucharea_143) }, 
{ SLINT_GET_ITEM_VTABLE(BasicBorderRectangleVTable),  offsetof(Component_rectangle_142, field_rectangle_144) }, 
{ SLINT_GET_ITEM_VTABLE(EmptyVTable),  offsetof(Component_rectangle_142, field_empty_146) }, 
{ SLINT_GET_ITEM_VTABLE(BasicBorderRectangleVTable),  offsetof(Component_rectangle_142, field_rectangle_151) }, 
{ SLINT_GET_ITEM_VTABLE(SimpleTextVTable),  offsetof(Component_rectangle_142, field_text_147) }, 
{ SLINT_GET_ITEM_VTABLE(BasicBorderRectangleVTable),  offsetof(Component_rectangle_142, field_rectangle_148) }, 
{ SLINT_GET_ITEM_VTABLE(TouchAreaVTable),  offsetof(Component_rectangle_142, field_close_ta_149) }, 
{ SLINT_GET_ITEM_VTABLE(SimpleTextVTable),  offsetof(Component_rectangle_142, field_text_150) }, 
{ SLINT_GET_ITEM_VTABLE(ClipVTable),  offsetof(Component_rectangle_142, field__clip_152) }, 
{ SLINT_GET_ITEM_VTABLE(FlickableVTable),  offsetof(Component_rectangle_142, field_flickable_153) }, 
{ SLINT_GET_ITEM_VTABLE(EmptyVTable),  offsetof(Component_rectangle_142, field__viewport_154) }, 
{ SLINT_GET_ITEM_VTABLE(ComplexTextVTable),  offsetof(Component_rectangle_142, field_log_text_155) } };
    return slint::private_api::make_slice(std::span(items));
}

auto Component_rectangle_142::layout_info ([[maybe_unused]] slint::private_api::ItemTreeRef component, slint::cbindgen_private::Orientation o) -> slint::cbindgen_private::LayoutInfo{
    return reinterpret_cast<const Component_rectangle_142*>(component.instance)->layout_info(o);
}

auto Component_rectangle_142::ensure_instantiated ([[maybe_unused]] slint::private_api::ItemTreeRef component) -> bool{
    return reinterpret_cast<const Component_rectangle_142*>(component.instance)->ensure_instantiated();
}

auto Component_rectangle_142::item_geometry ([[maybe_unused]] slint::private_api::ItemTreeRef component, uint32_t index) -> slint::cbindgen_private::LogicalRect{
    return reinterpret_cast<const Component_rectangle_142*>(component.instance)->item_geometry(index);
}

auto Component_rectangle_142::accessible_role ([[maybe_unused]] slint::private_api::ItemTreeRef component, uint32_t index) -> slint::cbindgen_private::AccessibleRole{
    return reinterpret_cast<const Component_rectangle_142*>(component.instance)->accessible_role(index);
}

auto Component_rectangle_142::accessible_string_property ([[maybe_unused]] slint::private_api::ItemTreeRef component, uint32_t index, slint::cbindgen_private::AccessibleStringProperty what, slint::SharedString *result) -> bool{
    if (auto r = reinterpret_cast<const Component_rectangle_142*>(component.instance)->accessible_string_property(index, what)) { *result = *r; return true; } else { return false; }
}

auto Component_rectangle_142::accessibility_action ([[maybe_unused]] slint::private_api::ItemTreeRef component, uint32_t index, const slint::cbindgen_private::AccessibilityAction *action) -> void{
    reinterpret_cast<const Component_rectangle_142*>(component.instance)->accessibility_action(index, *action);
}

auto Component_rectangle_142::supported_accessibility_actions ([[maybe_unused]] slint::private_api::ItemTreeRef component, uint32_t index) -> uint32_t{
    return reinterpret_cast<const Component_rectangle_142*>(component.instance)->supported_accessibility_actions(index);
}

auto Component_rectangle_142::element_infos ([[maybe_unused]] slint::private_api::ItemTreeRef component, [[maybe_unused]] uint32_t index, [[maybe_unused]] slint::SharedString *result) -> bool{
    return false;
}

auto Component_rectangle_142::window_adapter ([[maybe_unused]] slint::private_api::ItemTreeRef component, [[maybe_unused]] bool do_create, [[maybe_unused]] slint::cbindgen_private::Option<slint::private_api::WindowAdapterRc>* result) -> void{
    *reinterpret_cast<slint::private_api::WindowAdapterRc*>(result) = reinterpret_cast<const Component_rectangle_142*>(component.instance)->globals->window().window_handle();
}

auto Component_rectangle_142::create (class DetailsView_root_32 const * parent) -> slint::ComponentHandle<Component_rectangle_142>{
    auto self_rc = vtable::VRc<slint::private_api::ItemTreeVTable, Component_rectangle_142>::make();
    auto self = const_cast<Component_rectangle_142 *>(&*self_rc);
    self->self_weak = vtable::VWeak(self_rc).into_dyn();
    slint::private_api::register_item_tree(&self_rc.into_dyn(), parent->globals->m_window);
    self->init(parent->globals, self->self_weak, 0, 1 , parent);
    return slint::ComponentHandle<Component_rectangle_142>{ self_rc };
}

Component_rectangle_142::~Component_rectangle_142 (){
    if (auto &window = globals->m_window) window->window_handle().unregister_item_tree(this, item_array());
}

auto Component_rectangle_142::init () -> void{
    user_init();
}

auto Component_rectangle_142::layout_item_info (slint::cbindgen_private::Orientation o, [[maybe_unused]] std::optional<size_t> child_index) const -> slint::cbindgen_private::LayoutItemInfo{
    return { layout_info({&static_vtable, const_cast<void *>(static_cast<const void *>(this))}, o) };
}

auto Component_rectangle_142::flexbox_layout_item_info (slint::cbindgen_private::Orientation o, [[maybe_unused]] std::optional<size_t> child_index) const -> slint::cbindgen_private::FlexboxLayoutItemInfo{
    auto base = layout_item_info(o, child_index); return { base.constraint, 0.0f, 0.0f, -1.0f, slint::cbindgen_private::FlexboxLayoutAlignSelf::Auto, 0 };
}

const slint::private_api::ItemTreeVTable Component_rectangle_157::static_vtable = { visit_children, get_item_ref, get_subtree_range, get_subtree, get_item_tree, parent_node, embed_component, subtree_index, layout_info, ensure_instantiated, item_geometry, accessible_role, accessible_string_property, accessibility_action, supported_accessibility_actions, element_infos, window_adapter, slint::private_api::drop_in_place<Component_rectangle_157>, slint::private_api::dealloc };

auto Component_rectangle_157::fn_empty_159_layoutinfo_v_with_constraint ([[maybe_unused]] float arg_0) const -> slint::cbindgen_private::LayoutInfo{
    [[maybe_unused]] auto self = this;
    return slint::private_api::box_layout_info(slint::private_api::make_slice<slint::cbindgen_private::LayoutItemInfo>(std::array<slint::cbindgen_private::LayoutItemInfo, 1>{ slint::cbindgen_private::LayoutItemInfo ( [&](const auto &a_0){ slint::cbindgen_private::LayoutItemInfo o{}; o.constraint = a_0; return o; }(self->fn_empty_160_layoutinfo_v_with_constraint(arg_0)) ) }.data(), 1),0,[&](const auto &a_0, const auto &a_1){ slint::cbindgen_private::Padding o{}; o.begin = a_0; o.end = a_1; return o; }(0, 0),self->field_rectangle_157_empty_159_alignment.get());
}

auto Component_rectangle_157::fn_empty_160_layoutinfo_v_with_constraint ([[maybe_unused]] float arg_0) const -> slint::cbindgen_private::LayoutInfo{
    [[maybe_unused]] auto self = this;
    return slint::private_api::box_layout_info_ortho(slint::private_api::make_slice<slint::cbindgen_private::LayoutItemInfo>(std::array<slint::cbindgen_private::LayoutItemInfo, 1>{ slint::cbindgen_private::LayoutItemInfo ( [&](const auto &a_0){ slint::cbindgen_private::LayoutItemInfo o{}; o.constraint = a_0; return o; }(self->fn_rectangle_161_layoutinfo_v_with_constraint(arg_0)) ) }.data(), 1),[&](const auto &a_0, const auto &a_1){ slint::cbindgen_private::Padding o{}; o.begin = a_0; o.end = a_1; return o; }(0, 0));
}

auto Component_rectangle_157::fn_empty_162_layoutinfo_v_with_constraint ([[maybe_unused]] float arg_0) const -> slint::cbindgen_private::LayoutInfo{
    [[maybe_unused]] auto self = this;
    return slint::private_api::box_layout_info(slint::private_api::make_slice<slint::cbindgen_private::LayoutItemInfo>(std::array<slint::cbindgen_private::LayoutItemInfo, 3>{ slint::cbindgen_private::LayoutItemInfo ( [&](const auto &a_0){ slint::cbindgen_private::LayoutItemInfo o{}; o.constraint = a_0; return o; }(self->field_rectangle_157_empty_163_layoutinfo_v.get()) ), slint::cbindgen_private::LayoutItemInfo ( [&](const auto &a_0){ slint::cbindgen_private::LayoutItemInfo o{}; o.constraint = a_0; return o; }(slint::private_api::item_layout_info(SLINT_GET_ITEM_VTABLE(SimpleTextVTable), const_cast<slint::cbindgen_private::SimpleText*>(&self->field_text_168), slint::cbindgen_private::Orientation::Vertical, arg_0, &self->globals->window().window_handle(), self->self_weak.lock()->into_dyn(), self->tree_index_of_first_child + 5 - 1)) ), slint::cbindgen_private::LayoutItemInfo ( [&](const auto &a_0){ slint::cbindgen_private::LayoutItemInfo o{}; o.constraint = a_0; return o; }(self->fn_empty_169_layoutinfo_v_with_constraint(arg_0)) ) }.data(), 3),self->field_rectangle_157_empty_162_spacing.get(),[&](const auto &a_0, const auto &a_1){ slint::cbindgen_private::Padding o{}; o.begin = a_0; o.end = a_1; return o; }(self->field_rectangle_157_empty_162_padding.get(), self->field_rectangle_157_empty_162_padding.get()),slint::cbindgen_private::LayoutAlignment::Stretch);
}

auto Component_rectangle_157::fn_empty_169_layoutinfo_v_with_constraint ([[maybe_unused]] float arg_0) const -> slint::cbindgen_private::LayoutInfo{
    [[maybe_unused]] auto self = this;
    return slint::private_api::box_layout_info(slint::private_api::make_slice<slint::cbindgen_private::LayoutItemInfo>(std::array<slint::cbindgen_private::LayoutItemInfo, 5>{ slint::cbindgen_private::LayoutItemInfo ( [&](const auto &a_0){ slint::cbindgen_private::LayoutItemInfo o{}; o.constraint = a_0; return o; }(self->fn_rectangle_170_layoutinfo_v_with_constraint(arg_0)) ), slint::cbindgen_private::LayoutItemInfo ( [&](const auto &a_0){ slint::cbindgen_private::LayoutItemInfo o{}; o.constraint = a_0; return o; }(self->fn_rectangle_175_layoutinfo_v_with_constraint(arg_0)) ), slint::cbindgen_private::LayoutItemInfo ( [&](const auto &a_0){ slint::cbindgen_private::LayoutItemInfo o{}; o.constraint = a_0; return o; }(self->fn_rectangle_180_layoutinfo_v_with_constraint(arg_0)) ), slint::cbindgen_private::LayoutItemInfo ( [&](const auto &a_0){ slint::cbindgen_private::LayoutItemInfo o{}; o.constraint = a_0; return o; }(self->fn_rectangle_185_layoutinfo_v_with_constraint(arg_0)) ), slint::cbindgen_private::LayoutItemInfo ( [&](const auto &a_0){ slint::cbindgen_private::LayoutItemInfo o{}; o.constraint = a_0; return o; }(self->fn_rectangle_190_layoutinfo_v_with_constraint(arg_0)) ) }.data(), 5),self->field_rectangle_157_empty_169_spacing.get(),[&](const auto &a_0, const auto &a_1){ slint::cbindgen_private::Padding o{}; o.begin = a_0; o.end = a_1; return o; }(0, 0),self->field_rectangle_157_empty_169_alignment.get());
}

auto Component_rectangle_157::fn_empty_172_layoutinfo_v_with_constraint ([[maybe_unused]] float arg_0) const -> slint::cbindgen_private::LayoutInfo{
    [[maybe_unused]] auto self = this;
    return slint::private_api::box_layout_info(slint::private_api::make_slice<slint::cbindgen_private::LayoutItemInfo>(std::array<slint::cbindgen_private::LayoutItemInfo, 2>{ slint::cbindgen_private::LayoutItemInfo ( [&](const auto &a_0){ slint::cbindgen_private::LayoutItemInfo o{}; o.constraint = a_0; return o; }(slint::private_api::item_layout_info(SLINT_GET_ITEM_VTABLE(ComplexTextVTable), const_cast<slint::cbindgen_private::ComplexText*>(&self->field_text_173), slint::cbindgen_private::Orientation::Vertical, arg_0, &self->globals->window().window_handle(), self->self_weak.lock()->into_dyn(), self->tree_index_of_first_child + 17 - 1)) ), slint::cbindgen_private::LayoutItemInfo ( [&](const auto &a_0){ slint::cbindgen_private::LayoutItemInfo o{}; o.constraint = a_0; return o; }(slint::private_api::item_layout_info(SLINT_GET_ITEM_VTABLE(ComplexTextVTable), const_cast<slint::cbindgen_private::ComplexText*>(&self->field_text_174), slint::cbindgen_private::Orientation::Vertical, arg_0, &self->globals->window().window_handle(), self->self_weak.lock()->into_dyn(), self->tree_index_of_first_child + 18 - 1)) ) }.data(), 2),self->field_rectangle_157_empty_172_spacing.get(),[&](const auto &a_0, const auto &a_1){ slint::cbindgen_private::Padding o{}; o.begin = a_0; o.end = a_1; return o; }(self->field_rectangle_157_empty_172_padding.get(), self->field_rectangle_157_empty_172_padding.get()),self->field_rectangle_157_empty_172_alignment.get());
}

auto Component_rectangle_157::fn_empty_177_layoutinfo_v_with_constraint ([[maybe_unused]] float arg_0) const -> slint::cbindgen_private::LayoutInfo{
    [[maybe_unused]] auto self = this;
    return slint::private_api::box_layout_info(slint::private_api::make_slice<slint::cbindgen_private::LayoutItemInfo>(std::array<slint::cbindgen_private::LayoutItemInfo, 2>{ slint::cbindgen_private::LayoutItemInfo ( [&](const auto &a_0){ slint::cbindgen_private::LayoutItemInfo o{}; o.constraint = a_0; return o; }(slint::private_api::item_layout_info(SLINT_GET_ITEM_VTABLE(ComplexTextVTable), const_cast<slint::cbindgen_private::ComplexText*>(&self->field_text_178), slint::cbindgen_private::Orientation::Vertical, arg_0, &self->globals->window().window_handle(), self->self_weak.lock()->into_dyn(), self->tree_index_of_first_child + 20 - 1)) ), slint::cbindgen_private::LayoutItemInfo ( [&](const auto &a_0){ slint::cbindgen_private::LayoutItemInfo o{}; o.constraint = a_0; return o; }(slint::private_api::item_layout_info(SLINT_GET_ITEM_VTABLE(ComplexTextVTable), const_cast<slint::cbindgen_private::ComplexText*>(&self->field_text_179), slint::cbindgen_private::Orientation::Vertical, arg_0, &self->globals->window().window_handle(), self->self_weak.lock()->into_dyn(), self->tree_index_of_first_child + 21 - 1)) ) }.data(), 2),self->field_rectangle_157_empty_177_spacing.get(),[&](const auto &a_0, const auto &a_1){ slint::cbindgen_private::Padding o{}; o.begin = a_0; o.end = a_1; return o; }(self->field_rectangle_157_empty_177_padding.get(), self->field_rectangle_157_empty_177_padding.get()),self->field_rectangle_157_empty_177_alignment.get());
}

auto Component_rectangle_157::fn_empty_182_layoutinfo_v_with_constraint ([[maybe_unused]] float arg_0) const -> slint::cbindgen_private::LayoutInfo{
    [[maybe_unused]] auto self = this;
    return slint::private_api::box_layout_info(slint::private_api::make_slice<slint::cbindgen_private::LayoutItemInfo>(std::array<slint::cbindgen_private::LayoutItemInfo, 2>{ slint::cbindgen_private::LayoutItemInfo ( [&](const auto &a_0){ slint::cbindgen_private::LayoutItemInfo o{}; o.constraint = a_0; return o; }(slint::private_api::item_layout_info(SLINT_GET_ITEM_VTABLE(ComplexTextVTable), const_cast<slint::cbindgen_private::ComplexText*>(&self->field_text_183), slint::cbindgen_private::Orientation::Vertical, arg_0, &self->globals->window().window_handle(), self->self_weak.lock()->into_dyn(), self->tree_index_of_first_child + 23 - 1)) ), slint::cbindgen_private::LayoutItemInfo ( [&](const auto &a_0){ slint::cbindgen_private::LayoutItemInfo o{}; o.constraint = a_0; return o; }(slint::private_api::item_layout_info(SLINT_GET_ITEM_VTABLE(ComplexTextVTable), const_cast<slint::cbindgen_private::ComplexText*>(&self->field_text_184), slint::cbindgen_private::Orientation::Vertical, arg_0, &self->globals->window().window_handle(), self->self_weak.lock()->into_dyn(), self->tree_index_of_first_child + 24 - 1)) ) }.data(), 2),self->field_rectangle_157_empty_182_spacing.get(),[&](const auto &a_0, const auto &a_1){ slint::cbindgen_private::Padding o{}; o.begin = a_0; o.end = a_1; return o; }(self->field_rectangle_157_empty_182_padding.get(), self->field_rectangle_157_empty_182_padding.get()),self->field_rectangle_157_empty_182_alignment.get());
}

auto Component_rectangle_157::fn_empty_187_layoutinfo_v_with_constraint ([[maybe_unused]] float arg_0) const -> slint::cbindgen_private::LayoutInfo{
    [[maybe_unused]] auto self = this;
    return slint::private_api::box_layout_info(slint::private_api::make_slice<slint::cbindgen_private::LayoutItemInfo>(std::array<slint::cbindgen_private::LayoutItemInfo, 2>{ slint::cbindgen_private::LayoutItemInfo ( [&](const auto &a_0){ slint::cbindgen_private::LayoutItemInfo o{}; o.constraint = a_0; return o; }(slint::private_api::item_layout_info(SLINT_GET_ITEM_VTABLE(ComplexTextVTable), const_cast<slint::cbindgen_private::ComplexText*>(&self->field_text_188), slint::cbindgen_private::Orientation::Vertical, arg_0, &self->globals->window().window_handle(), self->self_weak.lock()->into_dyn(), self->tree_index_of_first_child + 26 - 1)) ), slint::cbindgen_private::LayoutItemInfo ( [&](const auto &a_0){ slint::cbindgen_private::LayoutItemInfo o{}; o.constraint = a_0; return o; }(slint::private_api::item_layout_info(SLINT_GET_ITEM_VTABLE(ComplexTextVTable), const_cast<slint::cbindgen_private::ComplexText*>(&self->field_text_189), slint::cbindgen_private::Orientation::Vertical, arg_0, &self->globals->window().window_handle(), self->self_weak.lock()->into_dyn(), self->tree_index_of_first_child + 27 - 1)) ) }.data(), 2),self->field_rectangle_157_empty_187_spacing.get(),[&](const auto &a_0, const auto &a_1){ slint::cbindgen_private::Padding o{}; o.begin = a_0; o.end = a_1; return o; }(self->field_rectangle_157_empty_187_padding.get(), self->field_rectangle_157_empty_187_padding.get()),self->field_rectangle_157_empty_187_alignment.get());
}

auto Component_rectangle_157::fn_empty_192_layoutinfo_v_with_constraint ([[maybe_unused]] float arg_0) const -> slint::cbindgen_private::LayoutInfo{
    [[maybe_unused]] auto self = this;
    return slint::private_api::box_layout_info(slint::private_api::make_slice<slint::cbindgen_private::LayoutItemInfo>(std::array<slint::cbindgen_private::LayoutItemInfo, 2>{ slint::cbindgen_private::LayoutItemInfo ( [&](const auto &a_0){ slint::cbindgen_private::LayoutItemInfo o{}; o.constraint = a_0; return o; }(slint::private_api::item_layout_info(SLINT_GET_ITEM_VTABLE(ComplexTextVTable), const_cast<slint::cbindgen_private::ComplexText*>(&self->field_text_193), slint::cbindgen_private::Orientation::Vertical, arg_0, &self->globals->window().window_handle(), self->self_weak.lock()->into_dyn(), self->tree_index_of_first_child + 29 - 1)) ), slint::cbindgen_private::LayoutItemInfo ( [&](const auto &a_0){ slint::cbindgen_private::LayoutItemInfo o{}; o.constraint = a_0; return o; }(slint::private_api::item_layout_info(SLINT_GET_ITEM_VTABLE(ComplexTextVTable), const_cast<slint::cbindgen_private::ComplexText*>(&self->field_text_194), slint::cbindgen_private::Orientation::Vertical, arg_0, &self->globals->window().window_handle(), self->self_weak.lock()->into_dyn(), self->tree_index_of_first_child + 30 - 1)) ) }.data(), 2),self->field_rectangle_157_empty_192_spacing.get(),[&](const auto &a_0, const auto &a_1){ slint::cbindgen_private::Padding o{}; o.begin = a_0; o.end = a_1; return o; }(self->field_rectangle_157_empty_192_padding.get(), self->field_rectangle_157_empty_192_padding.get()),self->field_rectangle_157_empty_192_alignment.get());
}

auto Component_rectangle_157::fn_layoutinfo_v_with_constraint ([[maybe_unused]] float arg_0) const -> slint::cbindgen_private::LayoutInfo{
    [[maybe_unused]] auto self = this;
    return ([&](const auto &a_0, const auto &a_1, const auto &a_2, const auto &a_3, const auto &a_4, const auto &a_5){ slint::cbindgen_private::LayoutInfo o{}; o.max = a_0; o.max_percent = a_1; o.min = a_2; o.min_percent = a_3; o.preferred = a_4; o.stretch = a_5; return o; }(+3.4028234663852886e38, 100, 0, 0, 0, 1) + self->fn_empty_159_layoutinfo_v_with_constraint(arg_0));
}

auto Component_rectangle_157::fn_rectangle_161_layoutinfo_v_with_constraint ([[maybe_unused]] float arg_0) const -> slint::cbindgen_private::LayoutInfo{
    [[maybe_unused]] auto self = this;
    return ([&](const auto &a_0, const auto &a_1, const auto &a_2, const auto &a_3, const auto &a_4, const auto &a_5){ slint::cbindgen_private::LayoutInfo o{}; o.max = a_0; o.max_percent = a_1; o.min = a_2; o.min_percent = a_3; o.preferred = a_4; o.stretch = a_5; return o; }(+3.4028234663852886e38, 100, 0, 0, 0, 1) + self->fn_empty_162_layoutinfo_v_with_constraint(arg_0));
}

auto Component_rectangle_157::fn_rectangle_170_layoutinfo_v_with_constraint ([[maybe_unused]] float arg_0) const -> slint::cbindgen_private::LayoutInfo{
    [[maybe_unused]] auto self = this;
    return ([&](const auto &a_0, const auto &a_1, const auto &a_2, const auto &a_3, const auto &a_4, const auto &a_5){ slint::cbindgen_private::LayoutInfo o{}; o.max = a_0; o.max_percent = a_1; o.min = a_2; o.min_percent = a_3; o.preferred = a_4; o.stretch = a_5; return o; }(+3.4028234663852886e38, 100, 0, 0, 0, 1) + self->fn_empty_172_layoutinfo_v_with_constraint(arg_0));
}

auto Component_rectangle_157::fn_rectangle_175_layoutinfo_v_with_constraint ([[maybe_unused]] float arg_0) const -> slint::cbindgen_private::LayoutInfo{
    [[maybe_unused]] auto self = this;
    return ([&](const auto &a_0, const auto &a_1, const auto &a_2, const auto &a_3, const auto &a_4, const auto &a_5){ slint::cbindgen_private::LayoutInfo o{}; o.max = a_0; o.max_percent = a_1; o.min = a_2; o.min_percent = a_3; o.preferred = a_4; o.stretch = a_5; return o; }(+3.4028234663852886e38, 100, 0, 0, 0, 1) + self->fn_empty_177_layoutinfo_v_with_constraint(arg_0));
}

auto Component_rectangle_157::fn_rectangle_180_layoutinfo_v_with_constraint ([[maybe_unused]] float arg_0) const -> slint::cbindgen_private::LayoutInfo{
    [[maybe_unused]] auto self = this;
    return ([&](const auto &a_0, const auto &a_1, const auto &a_2, const auto &a_3, const auto &a_4, const auto &a_5){ slint::cbindgen_private::LayoutInfo o{}; o.max = a_0; o.max_percent = a_1; o.min = a_2; o.min_percent = a_3; o.preferred = a_4; o.stretch = a_5; return o; }(+3.4028234663852886e38, 100, 0, 0, 0, 1) + self->fn_empty_182_layoutinfo_v_with_constraint(arg_0));
}

auto Component_rectangle_157::fn_rectangle_185_layoutinfo_v_with_constraint ([[maybe_unused]] float arg_0) const -> slint::cbindgen_private::LayoutInfo{
    [[maybe_unused]] auto self = this;
    return ([&](const auto &a_0, const auto &a_1, const auto &a_2, const auto &a_3, const auto &a_4, const auto &a_5){ slint::cbindgen_private::LayoutInfo o{}; o.max = a_0; o.max_percent = a_1; o.min = a_2; o.min_percent = a_3; o.preferred = a_4; o.stretch = a_5; return o; }(+3.4028234663852886e38, 100, 0, 0, 0, 1) + self->fn_empty_187_layoutinfo_v_with_constraint(arg_0));
}

auto Component_rectangle_157::fn_rectangle_190_layoutinfo_v_with_constraint ([[maybe_unused]] float arg_0) const -> slint::cbindgen_private::LayoutInfo{
    [[maybe_unused]] auto self = this;
    return ([&](const auto &a_0, const auto &a_1, const auto &a_2, const auto &a_3, const auto &a_4, const auto &a_5){ slint::cbindgen_private::LayoutInfo o{}; o.max = a_0; o.max_percent = a_1; o.min = a_2; o.min_percent = a_3; o.preferred = a_4; o.stretch = a_5; return o; }(+3.4028234663852886e38, 100, 0, 0, 0, 1) + self->fn_empty_192_layoutinfo_v_with_constraint(arg_0));
}

auto Component_rectangle_157::init (const class SharedGlobals* globals,slint::cbindgen_private::ItemTreeWeak enclosing_component,uint32_t tree_index,uint32_t tree_index_of_first_child,class DetailsView_root_32 const *parent) -> void{
    auto self = this;
    self->self_weak = enclosing_component;
    self->globals = globals;
    this->tree_index_of_first_child = tree_index_of_first_child;
    self->tree_index = tree_index;
    self->parent = vtable::VRcMapped<slint::private_api::ItemTreeVTable, const DetailsView_root_32>(parent->self_weak.lock().value(), parent);
    self->field_rectangle_157.background.set(slint::Brush(slint::Color::from_argb_encoded(+4.279308571e9)).transparentize(0.15));
    self->field_rectangle_157_empty_159_alignment.set(slint::cbindgen_private::LayoutAlignment::Center);
    self->field_rectangle_157_empty_159_layout_cache.set_binding([this]() {
                            [[maybe_unused]] auto self = this;
                            return slint::private_api::solve_box_layout([&](const auto &a_0, const auto &a_1, const auto &a_2, const auto &a_3, const auto &a_4){ slint::cbindgen_private::BoxLayoutData o{}; o.alignment = a_0; o.cells = a_1; o.padding = a_2; o.size = a_3; o.spacing = a_4; return o; }(slint::cbindgen_private::LayoutAlignment::Center, slint::private_api::make_slice<slint::cbindgen_private::LayoutItemInfo>(std::array<slint::cbindgen_private::LayoutItemInfo, 1>{ slint::cbindgen_private::LayoutItemInfo ( [&](const auto &a_0){ slint::cbindgen_private::LayoutItemInfo o{}; o.constraint = a_0; return o; }(self->field_rectangle_157_empty_160_layoutinfo_v.get()) ) }.data(), 1), [&](const auto &a_0, const auto &a_1){ slint::cbindgen_private::Padding o{}; o.begin = a_0; o.end = a_1; return o; }(0, 0), slint::private_api::optional_or_default(slint::private_api::optional_transform(self->parent.lock(), [&](auto&&x) { return x->field_root_32_height.get(); })), 0),slint::private_api::make_slice<int>(std::array<int, 0>{  }.data(), 0));
                        });
    self->field_rectangle_157_empty_159_layoutinfo_h.set_binding([this]() {
                            [[maybe_unused]] auto self = this;
                            return slint::private_api::box_layout_info_ortho(slint::private_api::make_slice<slint::cbindgen_private::LayoutItemInfo>(std::array<slint::cbindgen_private::LayoutItemInfo, 1>{ slint::cbindgen_private::LayoutItemInfo ( [&](const auto &a_0){ slint::cbindgen_private::LayoutItemInfo o{}; o.constraint = a_0; return o; }(self->field_rectangle_157_empty_160_layoutinfo_h.get()) ) }.data(), 1),[&](const auto &a_0, const auto &a_1){ slint::cbindgen_private::Padding o{}; o.begin = a_0; o.end = a_1; return o; }(0, 0));
                        });
    self->field_rectangle_157_empty_159_layoutinfo_v.set_binding([this]() {
                            [[maybe_unused]] auto self = this;
                            return slint::private_api::box_layout_info(slint::private_api::make_slice<slint::cbindgen_private::LayoutItemInfo>(std::array<slint::cbindgen_private::LayoutItemInfo, 1>{ slint::cbindgen_private::LayoutItemInfo ( [&](const auto &a_0){ slint::cbindgen_private::LayoutItemInfo o{}; o.constraint = a_0; return o; }(self->field_rectangle_157_empty_160_layoutinfo_v.get()) ) }.data(), 1),0,[&](const auto &a_0, const auto &a_1){ slint::cbindgen_private::Padding o{}; o.begin = a_0; o.end = a_1; return o; }(0, 0),slint::cbindgen_private::LayoutAlignment::Center);
                        });
    self->field_rectangle_157_empty_159_width.set_binding([this]() {
                            [[maybe_unused]] auto self = this;
                            return slint::private_api::optional_or_default(slint::private_api::optional_transform(self->parent.lock(), [&](auto&&x) { return x->field_root_32_width.get(); }));
                        });
    self->field_rectangle_157_empty_160_height.set_binding([this]() {
                            [[maybe_unused]] auto self = this;
                            return self->field_rectangle_157_empty_159_layout_cache.get()[1];
                        });
    self->field_rectangle_157_empty_160_layout_cache.set_binding([this]() {
                            [[maybe_unused]] auto self = this;
                            return slint::private_api::solve_box_layout([&](const auto &a_0, const auto &a_1, const auto &a_2, const auto &a_3, const auto &a_4){ slint::cbindgen_private::BoxLayoutData o{}; o.alignment = a_0; o.cells = a_1; o.padding = a_2; o.size = a_3; o.spacing = a_4; return o; }(slint::cbindgen_private::LayoutAlignment::Center, slint::private_api::make_slice<slint::cbindgen_private::LayoutItemInfo>(std::array<slint::cbindgen_private::LayoutItemInfo, 1>{ slint::cbindgen_private::LayoutItemInfo ( [&](const auto &a_0){ slint::cbindgen_private::LayoutItemInfo o{}; o.constraint = a_0; return o; }([&]{ [[maybe_unused]] auto layout_info = ([&](const auto &a_0, const auto &a_1, const auto &a_2, const auto &a_3, const auto &a_4, const auto &a_5){ slint::cbindgen_private::LayoutInfo o{}; o.max = a_0; o.max_percent = a_1; o.min = a_2; o.min_percent = a_3; o.preferred = a_4; o.stretch = a_5; return o; }(+3.4028234663852886e38, 100, 0, 0, 0, 1) + self->field_rectangle_157_empty_162_layoutinfo_h.get());;return [&](const auto &a_0, const auto &a_1, const auto &a_2, const auto &a_3, const auto &a_4, const auto &a_5){ slint::cbindgen_private::LayoutInfo o{}; o.max = a_0; o.max_percent = a_1; o.min = a_2; o.min_percent = a_3; o.preferred = a_4; o.stretch = a_5; return o; }(std::min<float>(700, (slint::private_api::optional_or_default(slint::private_api::optional_transform(self->parent.lock(), [&](auto&&x) { return x->field_root_32_width.get(); })) -(float) 40)), layout_info.max_percent, std::min<float>(700, (slint::private_api::optional_or_default(slint::private_api::optional_transform(self->parent.lock(), [&](auto&&x) { return x->field_root_32_width.get(); })) -(float) 40)), layout_info.min_percent, layout_info.preferred, layout_info.stretch); }()) ) }.data(), 1), [&](const auto &a_0, const auto &a_1){ slint::cbindgen_private::Padding o{}; o.begin = a_0; o.end = a_1; return o; }(0, 0), self->field_rectangle_157_empty_159_width.get(), 0),slint::private_api::make_slice<int>(std::array<int, 0>{  }.data(), 0));
                        });
    self->field_rectangle_157_empty_160_layoutinfo_h.set_binding([this]() {
                            [[maybe_unused]] auto self = this;
                            return slint::private_api::box_layout_info(slint::private_api::make_slice<slint::cbindgen_private::LayoutItemInfo>(std::array<slint::cbindgen_private::LayoutItemInfo, 1>{ slint::cbindgen_private::LayoutItemInfo ( [&](const auto &a_0){ slint::cbindgen_private::LayoutItemInfo o{}; o.constraint = a_0; return o; }([&]{ [[maybe_unused]] auto layout_info = ([&](const auto &a_0, const auto &a_1, const auto &a_2, const auto &a_3, const auto &a_4, const auto &a_5){ slint::cbindgen_private::LayoutInfo o{}; o.max = a_0; o.max_percent = a_1; o.min = a_2; o.min_percent = a_3; o.preferred = a_4; o.stretch = a_5; return o; }(+3.4028234663852886e38, 100, 0, 0, 0, 1) + self->field_rectangle_157_empty_162_layoutinfo_h.get());;return [&](const auto &a_0, const auto &a_1, const auto &a_2, const auto &a_3, const auto &a_4, const auto &a_5){ slint::cbindgen_private::LayoutInfo o{}; o.max = a_0; o.max_percent = a_1; o.min = a_2; o.min_percent = a_3; o.preferred = a_4; o.stretch = a_5; return o; }(std::min<float>(700, (slint::private_api::optional_or_default(slint::private_api::optional_transform(self->parent.lock(), [&](auto&&x) { return x->field_root_32_width.get(); })) -(float) 40)), layout_info.max_percent, std::min<float>(700, (slint::private_api::optional_or_default(slint::private_api::optional_transform(self->parent.lock(), [&](auto&&x) { return x->field_root_32_width.get(); })) -(float) 40)), layout_info.min_percent, layout_info.preferred, layout_info.stretch); }()) ) }.data(), 1),0,[&](const auto &a_0, const auto &a_1){ slint::cbindgen_private::Padding o{}; o.begin = a_0; o.end = a_1; return o; }(0, 0),slint::cbindgen_private::LayoutAlignment::Center);
                        });
    self->field_rectangle_157_empty_160_layoutinfo_v.set_binding([this]() {
                            [[maybe_unused]] auto self = this;
                            return slint::private_api::box_layout_info_ortho(slint::private_api::make_slice<slint::cbindgen_private::LayoutItemInfo>(std::array<slint::cbindgen_private::LayoutItemInfo, 1>{ slint::cbindgen_private::LayoutItemInfo ( [&](const auto &a_0){ slint::cbindgen_private::LayoutItemInfo o{}; o.constraint = a_0; return o; }(([&](const auto &a_0, const auto &a_1, const auto &a_2, const auto &a_3, const auto &a_4, const auto &a_5){ slint::cbindgen_private::LayoutInfo o{}; o.max = a_0; o.max_percent = a_1; o.min = a_2; o.min_percent = a_3; o.preferred = a_4; o.stretch = a_5; return o; }(+3.4028234663852886e38, 100, 0, 0, 0, 1) + self->field_rectangle_157_empty_162_layoutinfo_v.get())) ) }.data(), 1),[&](const auto &a_0, const auto &a_1){ slint::cbindgen_private::Padding o{}; o.begin = a_0; o.end = a_1; return o; }(0, 0));
                        });
    self->field_rectangle_157_empty_162_layout_cache.set_binding([this]() {
                            [[maybe_unused]] auto self = this;
                            return slint::private_api::solve_box_layout([&](const auto &a_0, const auto &a_1, const auto &a_2, const auto &a_3, const auto &a_4){ slint::cbindgen_private::BoxLayoutData o{}; o.alignment = a_0; o.cells = a_1; o.padding = a_2; o.size = a_3; o.spacing = a_4; return o; }(slint::cbindgen_private::LayoutAlignment::Stretch, slint::private_api::make_slice<slint::cbindgen_private::LayoutItemInfo>(std::array<slint::cbindgen_private::LayoutItemInfo, 3>{ slint::cbindgen_private::LayoutItemInfo ( [&](const auto &a_0){ slint::cbindgen_private::LayoutItemInfo o{}; o.constraint = a_0; return o; }(self->field_rectangle_157_empty_163_layoutinfo_v.get()) ), slint::cbindgen_private::LayoutItemInfo ( [&](const auto &a_0){ slint::cbindgen_private::LayoutItemInfo o{}; o.constraint = a_0; return o; }(slint::private_api::item_layout_info(SLINT_GET_ITEM_VTABLE(SimpleTextVTable), const_cast<slint::cbindgen_private::SimpleText*>(&self->field_text_168), slint::cbindgen_private::Orientation::Vertical, -1, &self->globals->window().window_handle(), self->self_weak.lock()->into_dyn(), self->tree_index_of_first_child + 5 - 1)) ), slint::cbindgen_private::LayoutItemInfo ( [&](const auto &a_0){ slint::cbindgen_private::LayoutItemInfo o{}; o.constraint = a_0; return o; }(self->field_rectangle_157_empty_169_layoutinfo_v.get()) ) }.data(), 3), [&](const auto &a_0, const auto &a_1){ slint::cbindgen_private::Padding o{}; o.begin = a_0; o.end = a_1; return o; }(30, 30), self->field_rectangle_157_empty_160_height.get(), 20),slint::private_api::make_slice<int>(std::array<int, 0>{  }.data(), 0));
                        });
    self->field_rectangle_157_empty_162_layoutinfo_h.set_binding([this]() {
                            [[maybe_unused]] auto self = this;
                            return slint::private_api::box_layout_info_ortho(slint::private_api::make_slice<slint::cbindgen_private::LayoutItemInfo>(std::array<slint::cbindgen_private::LayoutItemInfo, 3>{ slint::cbindgen_private::LayoutItemInfo ( [&](const auto &a_0){ slint::cbindgen_private::LayoutItemInfo o{}; o.constraint = a_0; return o; }(self->field_rectangle_157_empty_163_layoutinfo_h.get()) ), slint::cbindgen_private::LayoutItemInfo ( [&](const auto &a_0){ slint::cbindgen_private::LayoutItemInfo o{}; o.constraint = a_0; return o; }(slint::private_api::item_layout_info(SLINT_GET_ITEM_VTABLE(SimpleTextVTable), const_cast<slint::cbindgen_private::SimpleText*>(&self->field_text_168), slint::cbindgen_private::Orientation::Horizontal, -1, &self->globals->window().window_handle(), self->self_weak.lock()->into_dyn(), self->tree_index_of_first_child + 5 - 1)) ), slint::cbindgen_private::LayoutItemInfo ( [&](const auto &a_0){ slint::cbindgen_private::LayoutItemInfo o{}; o.constraint = a_0; return o; }(self->field_rectangle_157_empty_169_layoutinfo_h.get()) ) }.data(), 3),[&](const auto &a_0, const auto &a_1){ slint::cbindgen_private::Padding o{}; o.begin = a_0; o.end = a_1; return o; }(30, 30));
                        });
    self->field_rectangle_157_empty_162_layoutinfo_v.set_binding([this]() {
                            [[maybe_unused]] auto self = this;
                            return slint::private_api::box_layout_info(slint::private_api::make_slice<slint::cbindgen_private::LayoutItemInfo>(std::array<slint::cbindgen_private::LayoutItemInfo, 3>{ slint::cbindgen_private::LayoutItemInfo ( [&](const auto &a_0){ slint::cbindgen_private::LayoutItemInfo o{}; o.constraint = a_0; return o; }(self->field_rectangle_157_empty_163_layoutinfo_v.get()) ), slint::cbindgen_private::LayoutItemInfo ( [&](const auto &a_0){ slint::cbindgen_private::LayoutItemInfo o{}; o.constraint = a_0; return o; }(slint::private_api::item_layout_info(SLINT_GET_ITEM_VTABLE(SimpleTextVTable), const_cast<slint::cbindgen_private::SimpleText*>(&self->field_text_168), slint::cbindgen_private::Orientation::Vertical, -1, &self->globals->window().window_handle(), self->self_weak.lock()->into_dyn(), self->tree_index_of_first_child + 5 - 1)) ), slint::cbindgen_private::LayoutItemInfo ( [&](const auto &a_0){ slint::cbindgen_private::LayoutItemInfo o{}; o.constraint = a_0; return o; }(self->field_rectangle_157_empty_169_layoutinfo_v.get()) ) }.data(), 3),20,[&](const auto &a_0, const auto &a_1){ slint::cbindgen_private::Padding o{}; o.begin = a_0; o.end = a_1; return o; }(30, 30),slint::cbindgen_private::LayoutAlignment::Stretch);
                        });
    self->field_rectangle_157_empty_162_padding.set(30);
    self->field_rectangle_157_empty_162_spacing.set(20);
    self->field_rectangle_157_empty_163_layout_cache.set_binding([this]() {
                            [[maybe_unused]] auto self = this;
                            return slint::private_api::solve_box_layout([&](const auto &a_0, const auto &a_1, const auto &a_2, const auto &a_3, const auto &a_4){ slint::cbindgen_private::BoxLayoutData o{}; o.alignment = a_0; o.cells = a_1; o.padding = a_2; o.size = a_3; o.spacing = a_4; return o; }(slint::cbindgen_private::LayoutAlignment::SpaceBetween, slint::private_api::make_slice<slint::cbindgen_private::LayoutItemInfo>(std::array<slint::cbindgen_private::LayoutItemInfo, 2>{ slint::cbindgen_private::LayoutItemInfo ( [&](const auto &a_0){ slint::cbindgen_private::LayoutItemInfo o{}; o.constraint = a_0; return o; }(slint::private_api::item_layout_info(SLINT_GET_ITEM_VTABLE(SimpleTextVTable), const_cast<slint::cbindgen_private::SimpleText*>(&self->field_text_164), slint::cbindgen_private::Orientation::Horizontal, -1, &self->globals->window().window_handle(), self->self_weak.lock()->into_dyn(), self->tree_index_of_first_child + 7 - 1)) ), slint::cbindgen_private::LayoutItemInfo ( [&](const auto &a_0){ slint::cbindgen_private::LayoutItemInfo o{}; o.constraint = a_0; return o; }([&]{ [[maybe_unused]] auto layout_info = self->field_rectangle_157_rectangle_165_layoutinfo_h.get();;return [&](const auto &a_0, const auto &a_1, const auto &a_2, const auto &a_3, const auto &a_4, const auto &a_5){ slint::cbindgen_private::LayoutInfo o{}; o.max = a_0; o.max_percent = a_1; o.min = a_2; o.min_percent = a_3; o.preferred = a_4; o.stretch = a_5; return o; }(80, layout_info.max_percent, 80, layout_info.min_percent, layout_info.preferred, layout_info.stretch); }()) ) }.data(), 2), [&](const auto &a_0, const auto &a_1){ slint::cbindgen_private::Padding o{}; o.begin = a_0; o.end = a_1; return o; }(0, 0), ((std::min<float>(700, (slint::private_api::optional_or_default(slint::private_api::optional_transform(self->parent.lock(), [&](auto&&x) { return x->field_root_32_width.get(); })) -(float) 40)) -(float) 30) -(float) 30), 0),slint::private_api::make_slice<int>(std::array<int, 0>{  }.data(), 0));
                        });
    self->field_rectangle_157_empty_163_layoutinfo_h.set_binding([this]() {
                            [[maybe_unused]] auto self = this;
                            return slint::private_api::box_layout_info(slint::private_api::make_slice<slint::cbindgen_private::LayoutItemInfo>(std::array<slint::cbindgen_private::LayoutItemInfo, 2>{ slint::cbindgen_private::LayoutItemInfo ( [&](const auto &a_0){ slint::cbindgen_private::LayoutItemInfo o{}; o.constraint = a_0; return o; }(slint::private_api::item_layout_info(SLINT_GET_ITEM_VTABLE(SimpleTextVTable), const_cast<slint::cbindgen_private::SimpleText*>(&self->field_text_164), slint::cbindgen_private::Orientation::Horizontal, -1, &self->globals->window().window_handle(), self->self_weak.lock()->into_dyn(), self->tree_index_of_first_child + 7 - 1)) ), slint::cbindgen_private::LayoutItemInfo ( [&](const auto &a_0){ slint::cbindgen_private::LayoutItemInfo o{}; o.constraint = a_0; return o; }([&]{ [[maybe_unused]] auto layout_info = self->field_rectangle_157_rectangle_165_layoutinfo_h.get();;return [&](const auto &a_0, const auto &a_1, const auto &a_2, const auto &a_3, const auto &a_4, const auto &a_5){ slint::cbindgen_private::LayoutInfo o{}; o.max = a_0; o.max_percent = a_1; o.min = a_2; o.min_percent = a_3; o.preferred = a_4; o.stretch = a_5; return o; }(80, layout_info.max_percent, 80, layout_info.min_percent, layout_info.preferred, layout_info.stretch); }()) ) }.data(), 2),0,[&](const auto &a_0, const auto &a_1){ slint::cbindgen_private::Padding o{}; o.begin = a_0; o.end = a_1; return o; }(0, 0),slint::cbindgen_private::LayoutAlignment::SpaceBetween);
                        });
    self->field_rectangle_157_empty_163_layoutinfo_v.set_binding([this]() {
                            [[maybe_unused]] auto self = this;
                            return slint::private_api::box_layout_info_ortho(slint::private_api::make_slice<slint::cbindgen_private::LayoutItemInfo>(std::array<slint::cbindgen_private::LayoutItemInfo, 2>{ slint::cbindgen_private::LayoutItemInfo ( [&](const auto &a_0){ slint::cbindgen_private::LayoutItemInfo o{}; o.constraint = a_0; return o; }(slint::private_api::item_layout_info(SLINT_GET_ITEM_VTABLE(SimpleTextVTable), const_cast<slint::cbindgen_private::SimpleText*>(&self->field_text_164), slint::cbindgen_private::Orientation::Vertical, -1, &self->globals->window().window_handle(), self->self_weak.lock()->into_dyn(), self->tree_index_of_first_child + 7 - 1)) ), slint::cbindgen_private::LayoutItemInfo ( [&](const auto &a_0){ slint::cbindgen_private::LayoutItemInfo o{}; o.constraint = a_0; return o; }([&]{ [[maybe_unused]] auto layout_info = self->field_rectangle_157_rectangle_165_layoutinfo_v.get();;return [&](const auto &a_0, const auto &a_1, const auto &a_2, const auto &a_3, const auto &a_4, const auto &a_5){ slint::cbindgen_private::LayoutInfo o{}; o.max = a_0; o.max_percent = a_1; o.min = a_2; o.min_percent = a_3; o.preferred = a_4; o.stretch = a_5; return o; }(30, layout_info.max_percent, 30, layout_info.min_percent, layout_info.preferred, layout_info.stretch); }()) ) }.data(), 2),[&](const auto &a_0, const auto &a_1){ slint::cbindgen_private::Padding o{}; o.begin = a_0; o.end = a_1; return o; }(0, 0));
                        });
    self->field_rectangle_157_empty_169_alignment.set(slint::cbindgen_private::LayoutAlignment::Start);
    self->field_rectangle_157_empty_169_layout_cache.set_binding([this]() {
                            [[maybe_unused]] auto self = this;
                            return slint::private_api::solve_box_layout([&](const auto &a_0, const auto &a_1, const auto &a_2, const auto &a_3, const auto &a_4){ slint::cbindgen_private::BoxLayoutData o{}; o.alignment = a_0; o.cells = a_1; o.padding = a_2; o.size = a_3; o.spacing = a_4; return o; }(slint::cbindgen_private::LayoutAlignment::Start, slint::private_api::make_slice<slint::cbindgen_private::LayoutItemInfo>(std::array<slint::cbindgen_private::LayoutItemInfo, 5>{ slint::cbindgen_private::LayoutItemInfo ( [&](const auto &a_0){ slint::cbindgen_private::LayoutItemInfo o{}; o.constraint = a_0; return o; }(([&](const auto &a_0, const auto &a_1, const auto &a_2, const auto &a_3, const auto &a_4, const auto &a_5){ slint::cbindgen_private::LayoutInfo o{}; o.max = a_0; o.max_percent = a_1; o.min = a_2; o.min_percent = a_3; o.preferred = a_4; o.stretch = a_5; return o; }(+3.4028234663852886e38, 100, 0, 0, 0, 1) + self->field_rectangle_157_empty_172_layoutinfo_v.get())) ), slint::cbindgen_private::LayoutItemInfo ( [&](const auto &a_0){ slint::cbindgen_private::LayoutItemInfo o{}; o.constraint = a_0; return o; }(([&](const auto &a_0, const auto &a_1, const auto &a_2, const auto &a_3, const auto &a_4, const auto &a_5){ slint::cbindgen_private::LayoutInfo o{}; o.max = a_0; o.max_percent = a_1; o.min = a_2; o.min_percent = a_3; o.preferred = a_4; o.stretch = a_5; return o; }(+3.4028234663852886e38, 100, 0, 0, 0, 1) + self->field_rectangle_157_empty_177_layoutinfo_v.get())) ), slint::cbindgen_private::LayoutItemInfo ( [&](const auto &a_0){ slint::cbindgen_private::LayoutItemInfo o{}; o.constraint = a_0; return o; }(([&](const auto &a_0, const auto &a_1, const auto &a_2, const auto &a_3, const auto &a_4, const auto &a_5){ slint::cbindgen_private::LayoutInfo o{}; o.max = a_0; o.max_percent = a_1; o.min = a_2; o.min_percent = a_3; o.preferred = a_4; o.stretch = a_5; return o; }(+3.4028234663852886e38, 100, 0, 0, 0, 1) + self->field_rectangle_157_empty_182_layoutinfo_v.get())) ), slint::cbindgen_private::LayoutItemInfo ( [&](const auto &a_0){ slint::cbindgen_private::LayoutItemInfo o{}; o.constraint = a_0; return o; }(([&](const auto &a_0, const auto &a_1, const auto &a_2, const auto &a_3, const auto &a_4, const auto &a_5){ slint::cbindgen_private::LayoutInfo o{}; o.max = a_0; o.max_percent = a_1; o.min = a_2; o.min_percent = a_3; o.preferred = a_4; o.stretch = a_5; return o; }(+3.4028234663852886e38, 100, 0, 0, 0, 1) + self->field_rectangle_157_empty_187_layoutinfo_v.get())) ), slint::cbindgen_private::LayoutItemInfo ( [&](const auto &a_0){ slint::cbindgen_private::LayoutItemInfo o{}; o.constraint = a_0; return o; }(([&](const auto &a_0, const auto &a_1, const auto &a_2, const auto &a_3, const auto &a_4, const auto &a_5){ slint::cbindgen_private::LayoutInfo o{}; o.max = a_0; o.max_percent = a_1; o.min = a_2; o.min_percent = a_3; o.preferred = a_4; o.stretch = a_5; return o; }(+3.4028234663852886e38, 100, 0, 0, 0, 1) + self->field_rectangle_157_empty_192_layoutinfo_v.get())) ) }.data(), 5), [&](const auto &a_0, const auto &a_1){ slint::cbindgen_private::Padding o{}; o.begin = a_0; o.end = a_1; return o; }(0, 0), self->field_rectangle_157_empty_162_layout_cache.get()[5], 12),slint::private_api::make_slice<int>(std::array<int, 0>{  }.data(), 0));
                        });
    self->field_rectangle_157_empty_169_layoutinfo_h.set_binding([this]() {
                            [[maybe_unused]] auto self = this;
                            return slint::private_api::box_layout_info_ortho(slint::private_api::make_slice<slint::cbindgen_private::LayoutItemInfo>(std::array<slint::cbindgen_private::LayoutItemInfo, 5>{ slint::cbindgen_private::LayoutItemInfo ( [&](const auto &a_0){ slint::cbindgen_private::LayoutItemInfo o{}; o.constraint = a_0; return o; }(([&](const auto &a_0, const auto &a_1, const auto &a_2, const auto &a_3, const auto &a_4, const auto &a_5){ slint::cbindgen_private::LayoutInfo o{}; o.max = a_0; o.max_percent = a_1; o.min = a_2; o.min_percent = a_3; o.preferred = a_4; o.stretch = a_5; return o; }(+3.4028234663852886e38, 100, 0, 0, 0, 1) + self->field_rectangle_157_empty_172_layoutinfo_h.get())) ), slint::cbindgen_private::LayoutItemInfo ( [&](const auto &a_0){ slint::cbindgen_private::LayoutItemInfo o{}; o.constraint = a_0; return o; }(([&](const auto &a_0, const auto &a_1, const auto &a_2, const auto &a_3, const auto &a_4, const auto &a_5){ slint::cbindgen_private::LayoutInfo o{}; o.max = a_0; o.max_percent = a_1; o.min = a_2; o.min_percent = a_3; o.preferred = a_4; o.stretch = a_5; return o; }(+3.4028234663852886e38, 100, 0, 0, 0, 1) + self->field_rectangle_157_empty_177_layoutinfo_h.get())) ), slint::cbindgen_private::LayoutItemInfo ( [&](const auto &a_0){ slint::cbindgen_private::LayoutItemInfo o{}; o.constraint = a_0; return o; }(([&](const auto &a_0, const auto &a_1, const auto &a_2, const auto &a_3, const auto &a_4, const auto &a_5){ slint::cbindgen_private::LayoutInfo o{}; o.max = a_0; o.max_percent = a_1; o.min = a_2; o.min_percent = a_3; o.preferred = a_4; o.stretch = a_5; return o; }(+3.4028234663852886e38, 100, 0, 0, 0, 1) + self->field_rectangle_157_empty_182_layoutinfo_h.get())) ), slint::cbindgen_private::LayoutItemInfo ( [&](const auto &a_0){ slint::cbindgen_private::LayoutItemInfo o{}; o.constraint = a_0; return o; }(([&](const auto &a_0, const auto &a_1, const auto &a_2, const auto &a_3, const auto &a_4, const auto &a_5){ slint::cbindgen_private::LayoutInfo o{}; o.max = a_0; o.max_percent = a_1; o.min = a_2; o.min_percent = a_3; o.preferred = a_4; o.stretch = a_5; return o; }(+3.4028234663852886e38, 100, 0, 0, 0, 1) + self->field_rectangle_157_empty_187_layoutinfo_h.get())) ), slint::cbindgen_private::LayoutItemInfo ( [&](const auto &a_0){ slint::cbindgen_private::LayoutItemInfo o{}; o.constraint = a_0; return o; }(([&](const auto &a_0, const auto &a_1, const auto &a_2, const auto &a_3, const auto &a_4, const auto &a_5){ slint::cbindgen_private::LayoutInfo o{}; o.max = a_0; o.max_percent = a_1; o.min = a_2; o.min_percent = a_3; o.preferred = a_4; o.stretch = a_5; return o; }(+3.4028234663852886e38, 100, 0, 0, 0, 1) + self->field_rectangle_157_empty_192_layoutinfo_h.get())) ) }.data(), 5),[&](const auto &a_0, const auto &a_1){ slint::cbindgen_private::Padding o{}; o.begin = a_0; o.end = a_1; return o; }(0, 0));
                        });
    self->field_rectangle_157_empty_169_layoutinfo_v.set_binding([this]() {
                            [[maybe_unused]] auto self = this;
                            return slint::private_api::box_layout_info(slint::private_api::make_slice<slint::cbindgen_private::LayoutItemInfo>(std::array<slint::cbindgen_private::LayoutItemInfo, 5>{ slint::cbindgen_private::LayoutItemInfo ( [&](const auto &a_0){ slint::cbindgen_private::LayoutItemInfo o{}; o.constraint = a_0; return o; }(([&](const auto &a_0, const auto &a_1, const auto &a_2, const auto &a_3, const auto &a_4, const auto &a_5){ slint::cbindgen_private::LayoutInfo o{}; o.max = a_0; o.max_percent = a_1; o.min = a_2; o.min_percent = a_3; o.preferred = a_4; o.stretch = a_5; return o; }(+3.4028234663852886e38, 100, 0, 0, 0, 1) + self->field_rectangle_157_empty_172_layoutinfo_v.get())) ), slint::cbindgen_private::LayoutItemInfo ( [&](const auto &a_0){ slint::cbindgen_private::LayoutItemInfo o{}; o.constraint = a_0; return o; }(([&](const auto &a_0, const auto &a_1, const auto &a_2, const auto &a_3, const auto &a_4, const auto &a_5){ slint::cbindgen_private::LayoutInfo o{}; o.max = a_0; o.max_percent = a_1; o.min = a_2; o.min_percent = a_3; o.preferred = a_4; o.stretch = a_5; return o; }(+3.4028234663852886e38, 100, 0, 0, 0, 1) + self->field_rectangle_157_empty_177_layoutinfo_v.get())) ), slint::cbindgen_private::LayoutItemInfo ( [&](const auto &a_0){ slint::cbindgen_private::LayoutItemInfo o{}; o.constraint = a_0; return o; }(([&](const auto &a_0, const auto &a_1, const auto &a_2, const auto &a_3, const auto &a_4, const auto &a_5){ slint::cbindgen_private::LayoutInfo o{}; o.max = a_0; o.max_percent = a_1; o.min = a_2; o.min_percent = a_3; o.preferred = a_4; o.stretch = a_5; return o; }(+3.4028234663852886e38, 100, 0, 0, 0, 1) + self->field_rectangle_157_empty_182_layoutinfo_v.get())) ), slint::cbindgen_private::LayoutItemInfo ( [&](const auto &a_0){ slint::cbindgen_private::LayoutItemInfo o{}; o.constraint = a_0; return o; }(([&](const auto &a_0, const auto &a_1, const auto &a_2, const auto &a_3, const auto &a_4, const auto &a_5){ slint::cbindgen_private::LayoutInfo o{}; o.max = a_0; o.max_percent = a_1; o.min = a_2; o.min_percent = a_3; o.preferred = a_4; o.stretch = a_5; return o; }(+3.4028234663852886e38, 100, 0, 0, 0, 1) + self->field_rectangle_157_empty_187_layoutinfo_v.get())) ), slint::cbindgen_private::LayoutItemInfo ( [&](const auto &a_0){ slint::cbindgen_private::LayoutItemInfo o{}; o.constraint = a_0; return o; }(([&](const auto &a_0, const auto &a_1, const auto &a_2, const auto &a_3, const auto &a_4, const auto &a_5){ slint::cbindgen_private::LayoutInfo o{}; o.max = a_0; o.max_percent = a_1; o.min = a_2; o.min_percent = a_3; o.preferred = a_4; o.stretch = a_5; return o; }(+3.4028234663852886e38, 100, 0, 0, 0, 1) + self->field_rectangle_157_empty_192_layoutinfo_v.get())) ) }.data(), 5),12,[&](const auto &a_0, const auto &a_1){ slint::cbindgen_private::Padding o{}; o.begin = a_0; o.end = a_1; return o; }(0, 0),slint::cbindgen_private::LayoutAlignment::Start);
                        });
    self->field_rectangle_157_empty_169_spacing.set(12);
    self->field_rectangle_157_empty_169_width.set_binding([this]() {
                            [[maybe_unused]] auto self = this;
                            return ((std::min<float>(700, (slint::private_api::optional_or_default(slint::private_api::optional_transform(self->parent.lock(), [&](auto&&x) { return x->field_root_32_width.get(); })) -(float) 40)) -(float) 30) -(float) 30);
                        });
    self->field_rectangle_157_empty_172_alignment.set(slint::cbindgen_private::LayoutAlignment::Center);
    self->field_rectangle_157_empty_172_layout_cache.set_binding([this]() {
                            [[maybe_unused]] auto self = this;
                            return slint::private_api::solve_box_layout([&](const auto &a_0, const auto &a_1, const auto &a_2, const auto &a_3, const auto &a_4){ slint::cbindgen_private::BoxLayoutData o{}; o.alignment = a_0; o.cells = a_1; o.padding = a_2; o.size = a_3; o.spacing = a_4; return o; }(slint::cbindgen_private::LayoutAlignment::Center, slint::private_api::make_slice<slint::cbindgen_private::LayoutItemInfo>(std::array<slint::cbindgen_private::LayoutItemInfo, 2>{ slint::cbindgen_private::LayoutItemInfo ( [&](const auto &a_0){ slint::cbindgen_private::LayoutItemInfo o{}; o.constraint = a_0; return o; }(slint::private_api::item_layout_info(SLINT_GET_ITEM_VTABLE(ComplexTextVTable), const_cast<slint::cbindgen_private::ComplexText*>(&self->field_text_173), slint::cbindgen_private::Orientation::Vertical, -1, &self->globals->window().window_handle(), self->self_weak.lock()->into_dyn(), self->tree_index_of_first_child + 17 - 1)) ), slint::cbindgen_private::LayoutItemInfo ( [&](const auto &a_0){ slint::cbindgen_private::LayoutItemInfo o{}; o.constraint = a_0; return o; }(slint::private_api::item_layout_info(SLINT_GET_ITEM_VTABLE(ComplexTextVTable), const_cast<slint::cbindgen_private::ComplexText*>(&self->field_text_174), slint::cbindgen_private::Orientation::Vertical, -1, &self->globals->window().window_handle(), self->self_weak.lock()->into_dyn(), self->tree_index_of_first_child + 18 - 1)) ) }.data(), 2), [&](const auto &a_0, const auto &a_1){ slint::cbindgen_private::Padding o{}; o.begin = a_0; o.end = a_1; return o; }(16, 16), self->field_rectangle_157_empty_169_layout_cache.get()[1], 4),slint::private_api::make_slice<int>(std::array<int, 0>{  }.data(), 0));
                        });
    self->field_rectangle_157_empty_172_layoutinfo_h.set_binding([this]() {
                            [[maybe_unused]] auto self = this;
                            return slint::private_api::box_layout_info_ortho(slint::private_api::make_slice<slint::cbindgen_private::LayoutItemInfo>(std::array<slint::cbindgen_private::LayoutItemInfo, 2>{ slint::cbindgen_private::LayoutItemInfo ( [&](const auto &a_0){ slint::cbindgen_private::LayoutItemInfo o{}; o.constraint = a_0; return o; }(slint::private_api::item_layout_info(SLINT_GET_ITEM_VTABLE(ComplexTextVTable), const_cast<slint::cbindgen_private::ComplexText*>(&self->field_text_173), slint::cbindgen_private::Orientation::Horizontal, -1, &self->globals->window().window_handle(), self->self_weak.lock()->into_dyn(), self->tree_index_of_first_child + 17 - 1)) ), slint::cbindgen_private::LayoutItemInfo ( [&](const auto &a_0){ slint::cbindgen_private::LayoutItemInfo o{}; o.constraint = a_0; return o; }(slint::private_api::item_layout_info(SLINT_GET_ITEM_VTABLE(ComplexTextVTable), const_cast<slint::cbindgen_private::ComplexText*>(&self->field_text_174), slint::cbindgen_private::Orientation::Horizontal, -1, &self->globals->window().window_handle(), self->self_weak.lock()->into_dyn(), self->tree_index_of_first_child + 18 - 1)) ) }.data(), 2),[&](const auto &a_0, const auto &a_1){ slint::cbindgen_private::Padding o{}; o.begin = a_0; o.end = a_1; return o; }(16, 16));
                        });
    self->field_rectangle_157_empty_172_layoutinfo_v.set_binding([this]() {
                            [[maybe_unused]] auto self = this;
                            return slint::private_api::box_layout_info(slint::private_api::make_slice<slint::cbindgen_private::LayoutItemInfo>(std::array<slint::cbindgen_private::LayoutItemInfo, 2>{ slint::cbindgen_private::LayoutItemInfo ( [&](const auto &a_0){ slint::cbindgen_private::LayoutItemInfo o{}; o.constraint = a_0; return o; }(slint::private_api::item_layout_info(SLINT_GET_ITEM_VTABLE(ComplexTextVTable), const_cast<slint::cbindgen_private::ComplexText*>(&self->field_text_173), slint::cbindgen_private::Orientation::Vertical, -1, &self->globals->window().window_handle(), self->self_weak.lock()->into_dyn(), self->tree_index_of_first_child + 17 - 1)) ), slint::cbindgen_private::LayoutItemInfo ( [&](const auto &a_0){ slint::cbindgen_private::LayoutItemInfo o{}; o.constraint = a_0; return o; }(slint::private_api::item_layout_info(SLINT_GET_ITEM_VTABLE(ComplexTextVTable), const_cast<slint::cbindgen_private::ComplexText*>(&self->field_text_174), slint::cbindgen_private::Orientation::Vertical, -1, &self->globals->window().window_handle(), self->self_weak.lock()->into_dyn(), self->tree_index_of_first_child + 18 - 1)) ) }.data(), 2),4,[&](const auto &a_0, const auto &a_1){ slint::cbindgen_private::Padding o{}; o.begin = a_0; o.end = a_1; return o; }(16, 16),slint::cbindgen_private::LayoutAlignment::Center);
                        });
    self->field_rectangle_157_empty_172_padding.set(16);
    self->field_rectangle_157_empty_172_spacing.set(4);
    self->field_rectangle_157_empty_177_alignment.set(slint::cbindgen_private::LayoutAlignment::Center);
    self->field_rectangle_157_empty_177_layout_cache.set_binding([this]() {
                            [[maybe_unused]] auto self = this;
                            return slint::private_api::solve_box_layout([&](const auto &a_0, const auto &a_1, const auto &a_2, const auto &a_3, const auto &a_4){ slint::cbindgen_private::BoxLayoutData o{}; o.alignment = a_0; o.cells = a_1; o.padding = a_2; o.size = a_3; o.spacing = a_4; return o; }(slint::cbindgen_private::LayoutAlignment::Center, slint::private_api::make_slice<slint::cbindgen_private::LayoutItemInfo>(std::array<slint::cbindgen_private::LayoutItemInfo, 2>{ slint::cbindgen_private::LayoutItemInfo ( [&](const auto &a_0){ slint::cbindgen_private::LayoutItemInfo o{}; o.constraint = a_0; return o; }(slint::private_api::item_layout_info(SLINT_GET_ITEM_VTABLE(ComplexTextVTable), const_cast<slint::cbindgen_private::ComplexText*>(&self->field_text_178), slint::cbindgen_private::Orientation::Vertical, -1, &self->globals->window().window_handle(), self->self_weak.lock()->into_dyn(), self->tree_index_of_first_child + 20 - 1)) ), slint::cbindgen_private::LayoutItemInfo ( [&](const auto &a_0){ slint::cbindgen_private::LayoutItemInfo o{}; o.constraint = a_0; return o; }(slint::private_api::item_layout_info(SLINT_GET_ITEM_VTABLE(ComplexTextVTable), const_cast<slint::cbindgen_private::ComplexText*>(&self->field_text_179), slint::cbindgen_private::Orientation::Vertical, -1, &self->globals->window().window_handle(), self->self_weak.lock()->into_dyn(), self->tree_index_of_first_child + 21 - 1)) ) }.data(), 2), [&](const auto &a_0, const auto &a_1){ slint::cbindgen_private::Padding o{}; o.begin = a_0; o.end = a_1; return o; }(16, 16), self->field_rectangle_157_empty_169_layout_cache.get()[3], 4),slint::private_api::make_slice<int>(std::array<int, 0>{  }.data(), 0));
                        });
    self->field_rectangle_157_empty_177_layoutinfo_h.set_binding([this]() {
                            [[maybe_unused]] auto self = this;
                            return slint::private_api::box_layout_info_ortho(slint::private_api::make_slice<slint::cbindgen_private::LayoutItemInfo>(std::array<slint::cbindgen_private::LayoutItemInfo, 2>{ slint::cbindgen_private::LayoutItemInfo ( [&](const auto &a_0){ slint::cbindgen_private::LayoutItemInfo o{}; o.constraint = a_0; return o; }(slint::private_api::item_layout_info(SLINT_GET_ITEM_VTABLE(ComplexTextVTable), const_cast<slint::cbindgen_private::ComplexText*>(&self->field_text_178), slint::cbindgen_private::Orientation::Horizontal, -1, &self->globals->window().window_handle(), self->self_weak.lock()->into_dyn(), self->tree_index_of_first_child + 20 - 1)) ), slint::cbindgen_private::LayoutItemInfo ( [&](const auto &a_0){ slint::cbindgen_private::LayoutItemInfo o{}; o.constraint = a_0; return o; }(slint::private_api::item_layout_info(SLINT_GET_ITEM_VTABLE(ComplexTextVTable), const_cast<slint::cbindgen_private::ComplexText*>(&self->field_text_179), slint::cbindgen_private::Orientation::Horizontal, -1, &self->globals->window().window_handle(), self->self_weak.lock()->into_dyn(), self->tree_index_of_first_child + 21 - 1)) ) }.data(), 2),[&](const auto &a_0, const auto &a_1){ slint::cbindgen_private::Padding o{}; o.begin = a_0; o.end = a_1; return o; }(16, 16));
                        });
    self->field_rectangle_157_empty_177_layoutinfo_v.set_binding([this]() {
                            [[maybe_unused]] auto self = this;
                            return slint::private_api::box_layout_info(slint::private_api::make_slice<slint::cbindgen_private::LayoutItemInfo>(std::array<slint::cbindgen_private::LayoutItemInfo, 2>{ slint::cbindgen_private::LayoutItemInfo ( [&](const auto &a_0){ slint::cbindgen_private::LayoutItemInfo o{}; o.constraint = a_0; return o; }(slint::private_api::item_layout_info(SLINT_GET_ITEM_VTABLE(ComplexTextVTable), const_cast<slint::cbindgen_private::ComplexText*>(&self->field_text_178), slint::cbindgen_private::Orientation::Vertical, -1, &self->globals->window().window_handle(), self->self_weak.lock()->into_dyn(), self->tree_index_of_first_child + 20 - 1)) ), slint::cbindgen_private::LayoutItemInfo ( [&](const auto &a_0){ slint::cbindgen_private::LayoutItemInfo o{}; o.constraint = a_0; return o; }(slint::private_api::item_layout_info(SLINT_GET_ITEM_VTABLE(ComplexTextVTable), const_cast<slint::cbindgen_private::ComplexText*>(&self->field_text_179), slint::cbindgen_private::Orientation::Vertical, -1, &self->globals->window().window_handle(), self->self_weak.lock()->into_dyn(), self->tree_index_of_first_child + 21 - 1)) ) }.data(), 2),4,[&](const auto &a_0, const auto &a_1){ slint::cbindgen_private::Padding o{}; o.begin = a_0; o.end = a_1; return o; }(16, 16),slint::cbindgen_private::LayoutAlignment::Center);
                        });
    self->field_rectangle_157_empty_177_padding.set(16);
    self->field_rectangle_157_empty_177_spacing.set(4);
    self->field_rectangle_157_empty_182_alignment.set(slint::cbindgen_private::LayoutAlignment::Center);
    self->field_rectangle_157_empty_182_layout_cache.set_binding([this]() {
                            [[maybe_unused]] auto self = this;
                            return slint::private_api::solve_box_layout([&](const auto &a_0, const auto &a_1, const auto &a_2, const auto &a_3, const auto &a_4){ slint::cbindgen_private::BoxLayoutData o{}; o.alignment = a_0; o.cells = a_1; o.padding = a_2; o.size = a_3; o.spacing = a_4; return o; }(slint::cbindgen_private::LayoutAlignment::Center, slint::private_api::make_slice<slint::cbindgen_private::LayoutItemInfo>(std::array<slint::cbindgen_private::LayoutItemInfo, 2>{ slint::cbindgen_private::LayoutItemInfo ( [&](const auto &a_0){ slint::cbindgen_private::LayoutItemInfo o{}; o.constraint = a_0; return o; }(slint::private_api::item_layout_info(SLINT_GET_ITEM_VTABLE(ComplexTextVTable), const_cast<slint::cbindgen_private::ComplexText*>(&self->field_text_183), slint::cbindgen_private::Orientation::Vertical, -1, &self->globals->window().window_handle(), self->self_weak.lock()->into_dyn(), self->tree_index_of_first_child + 23 - 1)) ), slint::cbindgen_private::LayoutItemInfo ( [&](const auto &a_0){ slint::cbindgen_private::LayoutItemInfo o{}; o.constraint = a_0; return o; }(slint::private_api::item_layout_info(SLINT_GET_ITEM_VTABLE(ComplexTextVTable), const_cast<slint::cbindgen_private::ComplexText*>(&self->field_text_184), slint::cbindgen_private::Orientation::Vertical, -1, &self->globals->window().window_handle(), self->self_weak.lock()->into_dyn(), self->tree_index_of_first_child + 24 - 1)) ) }.data(), 2), [&](const auto &a_0, const auto &a_1){ slint::cbindgen_private::Padding o{}; o.begin = a_0; o.end = a_1; return o; }(16, 16), self->field_rectangle_157_empty_169_layout_cache.get()[5], 4),slint::private_api::make_slice<int>(std::array<int, 0>{  }.data(), 0));
                        });
    self->field_rectangle_157_empty_182_layoutinfo_h.set_binding([this]() {
                            [[maybe_unused]] auto self = this;
                            return slint::private_api::box_layout_info_ortho(slint::private_api::make_slice<slint::cbindgen_private::LayoutItemInfo>(std::array<slint::cbindgen_private::LayoutItemInfo, 2>{ slint::cbindgen_private::LayoutItemInfo ( [&](const auto &a_0){ slint::cbindgen_private::LayoutItemInfo o{}; o.constraint = a_0; return o; }(slint::private_api::item_layout_info(SLINT_GET_ITEM_VTABLE(ComplexTextVTable), const_cast<slint::cbindgen_private::ComplexText*>(&self->field_text_183), slint::cbindgen_private::Orientation::Horizontal, -1, &self->globals->window().window_handle(), self->self_weak.lock()->into_dyn(), self->tree_index_of_first_child + 23 - 1)) ), slint::cbindgen_private::LayoutItemInfo ( [&](const auto &a_0){ slint::cbindgen_private::LayoutItemInfo o{}; o.constraint = a_0; return o; }(slint::private_api::item_layout_info(SLINT_GET_ITEM_VTABLE(ComplexTextVTable), const_cast<slint::cbindgen_private::ComplexText*>(&self->field_text_184), slint::cbindgen_private::Orientation::Horizontal, -1, &self->globals->window().window_handle(), self->self_weak.lock()->into_dyn(), self->tree_index_of_first_child + 24 - 1)) ) }.data(), 2),[&](const auto &a_0, const auto &a_1){ slint::cbindgen_private::Padding o{}; o.begin = a_0; o.end = a_1; return o; }(16, 16));
                        });
    self->field_rectangle_157_empty_182_layoutinfo_v.set_binding([this]() {
                            [[maybe_unused]] auto self = this;
                            return slint::private_api::box_layout_info(slint::private_api::make_slice<slint::cbindgen_private::LayoutItemInfo>(std::array<slint::cbindgen_private::LayoutItemInfo, 2>{ slint::cbindgen_private::LayoutItemInfo ( [&](const auto &a_0){ slint::cbindgen_private::LayoutItemInfo o{}; o.constraint = a_0; return o; }(slint::private_api::item_layout_info(SLINT_GET_ITEM_VTABLE(ComplexTextVTable), const_cast<slint::cbindgen_private::ComplexText*>(&self->field_text_183), slint::cbindgen_private::Orientation::Vertical, -1, &self->globals->window().window_handle(), self->self_weak.lock()->into_dyn(), self->tree_index_of_first_child + 23 - 1)) ), slint::cbindgen_private::LayoutItemInfo ( [&](const auto &a_0){ slint::cbindgen_private::LayoutItemInfo o{}; o.constraint = a_0; return o; }(slint::private_api::item_layout_info(SLINT_GET_ITEM_VTABLE(ComplexTextVTable), const_cast<slint::cbindgen_private::ComplexText*>(&self->field_text_184), slint::cbindgen_private::Orientation::Vertical, -1, &self->globals->window().window_handle(), self->self_weak.lock()->into_dyn(), self->tree_index_of_first_child + 24 - 1)) ) }.data(), 2),4,[&](const auto &a_0, const auto &a_1){ slint::cbindgen_private::Padding o{}; o.begin = a_0; o.end = a_1; return o; }(16, 16),slint::cbindgen_private::LayoutAlignment::Center);
                        });
    self->field_rectangle_157_empty_182_padding.set(16);
    self->field_rectangle_157_empty_182_spacing.set(4);
    self->field_rectangle_157_empty_187_alignment.set(slint::cbindgen_private::LayoutAlignment::Center);
    self->field_rectangle_157_empty_187_layout_cache.set_binding([this]() {
                            [[maybe_unused]] auto self = this;
                            return slint::private_api::solve_box_layout([&](const auto &a_0, const auto &a_1, const auto &a_2, const auto &a_3, const auto &a_4){ slint::cbindgen_private::BoxLayoutData o{}; o.alignment = a_0; o.cells = a_1; o.padding = a_2; o.size = a_3; o.spacing = a_4; return o; }(slint::cbindgen_private::LayoutAlignment::Center, slint::private_api::make_slice<slint::cbindgen_private::LayoutItemInfo>(std::array<slint::cbindgen_private::LayoutItemInfo, 2>{ slint::cbindgen_private::LayoutItemInfo ( [&](const auto &a_0){ slint::cbindgen_private::LayoutItemInfo o{}; o.constraint = a_0; return o; }(slint::private_api::item_layout_info(SLINT_GET_ITEM_VTABLE(ComplexTextVTable), const_cast<slint::cbindgen_private::ComplexText*>(&self->field_text_188), slint::cbindgen_private::Orientation::Vertical, -1, &self->globals->window().window_handle(), self->self_weak.lock()->into_dyn(), self->tree_index_of_first_child + 26 - 1)) ), slint::cbindgen_private::LayoutItemInfo ( [&](const auto &a_0){ slint::cbindgen_private::LayoutItemInfo o{}; o.constraint = a_0; return o; }(slint::private_api::item_layout_info(SLINT_GET_ITEM_VTABLE(ComplexTextVTable), const_cast<slint::cbindgen_private::ComplexText*>(&self->field_text_189), slint::cbindgen_private::Orientation::Vertical, -1, &self->globals->window().window_handle(), self->self_weak.lock()->into_dyn(), self->tree_index_of_first_child + 27 - 1)) ) }.data(), 2), [&](const auto &a_0, const auto &a_1){ slint::cbindgen_private::Padding o{}; o.begin = a_0; o.end = a_1; return o; }(16, 16), self->field_rectangle_157_empty_169_layout_cache.get()[7], 4),slint::private_api::make_slice<int>(std::array<int, 0>{  }.data(), 0));
                        });
    self->field_rectangle_157_empty_187_layoutinfo_h.set_binding([this]() {
                            [[maybe_unused]] auto self = this;
                            return slint::private_api::box_layout_info_ortho(slint::private_api::make_slice<slint::cbindgen_private::LayoutItemInfo>(std::array<slint::cbindgen_private::LayoutItemInfo, 2>{ slint::cbindgen_private::LayoutItemInfo ( [&](const auto &a_0){ slint::cbindgen_private::LayoutItemInfo o{}; o.constraint = a_0; return o; }(slint::private_api::item_layout_info(SLINT_GET_ITEM_VTABLE(ComplexTextVTable), const_cast<slint::cbindgen_private::ComplexText*>(&self->field_text_188), slint::cbindgen_private::Orientation::Horizontal, -1, &self->globals->window().window_handle(), self->self_weak.lock()->into_dyn(), self->tree_index_of_first_child + 26 - 1)) ), slint::cbindgen_private::LayoutItemInfo ( [&](const auto &a_0){ slint::cbindgen_private::LayoutItemInfo o{}; o.constraint = a_0; return o; }(slint::private_api::item_layout_info(SLINT_GET_ITEM_VTABLE(ComplexTextVTable), const_cast<slint::cbindgen_private::ComplexText*>(&self->field_text_189), slint::cbindgen_private::Orientation::Horizontal, -1, &self->globals->window().window_handle(), self->self_weak.lock()->into_dyn(), self->tree_index_of_first_child + 27 - 1)) ) }.data(), 2),[&](const auto &a_0, const auto &a_1){ slint::cbindgen_private::Padding o{}; o.begin = a_0; o.end = a_1; return o; }(16, 16));
                        });
    self->field_rectangle_157_empty_187_layoutinfo_v.set_binding([this]() {
                            [[maybe_unused]] auto self = this;
                            return slint::private_api::box_layout_info(slint::private_api::make_slice<slint::cbindgen_private::LayoutItemInfo>(std::array<slint::cbindgen_private::LayoutItemInfo, 2>{ slint::cbindgen_private::LayoutItemInfo ( [&](const auto &a_0){ slint::cbindgen_private::LayoutItemInfo o{}; o.constraint = a_0; return o; }(slint::private_api::item_layout_info(SLINT_GET_ITEM_VTABLE(ComplexTextVTable), const_cast<slint::cbindgen_private::ComplexText*>(&self->field_text_188), slint::cbindgen_private::Orientation::Vertical, -1, &self->globals->window().window_handle(), self->self_weak.lock()->into_dyn(), self->tree_index_of_first_child + 26 - 1)) ), slint::cbindgen_private::LayoutItemInfo ( [&](const auto &a_0){ slint::cbindgen_private::LayoutItemInfo o{}; o.constraint = a_0; return o; }(slint::private_api::item_layout_info(SLINT_GET_ITEM_VTABLE(ComplexTextVTable), const_cast<slint::cbindgen_private::ComplexText*>(&self->field_text_189), slint::cbindgen_private::Orientation::Vertical, -1, &self->globals->window().window_handle(), self->self_weak.lock()->into_dyn(), self->tree_index_of_first_child + 27 - 1)) ) }.data(), 2),4,[&](const auto &a_0, const auto &a_1){ slint::cbindgen_private::Padding o{}; o.begin = a_0; o.end = a_1; return o; }(16, 16),slint::cbindgen_private::LayoutAlignment::Center);
                        });
    self->field_rectangle_157_empty_187_padding.set(16);
    self->field_rectangle_157_empty_187_spacing.set(4);
    self->field_rectangle_157_empty_192_alignment.set(slint::cbindgen_private::LayoutAlignment::Center);
    self->field_rectangle_157_empty_192_layout_cache.set_binding([this]() {
                            [[maybe_unused]] auto self = this;
                            return slint::private_api::solve_box_layout([&](const auto &a_0, const auto &a_1, const auto &a_2, const auto &a_3, const auto &a_4){ slint::cbindgen_private::BoxLayoutData o{}; o.alignment = a_0; o.cells = a_1; o.padding = a_2; o.size = a_3; o.spacing = a_4; return o; }(slint::cbindgen_private::LayoutAlignment::Center, slint::private_api::make_slice<slint::cbindgen_private::LayoutItemInfo>(std::array<slint::cbindgen_private::LayoutItemInfo, 2>{ slint::cbindgen_private::LayoutItemInfo ( [&](const auto &a_0){ slint::cbindgen_private::LayoutItemInfo o{}; o.constraint = a_0; return o; }(slint::private_api::item_layout_info(SLINT_GET_ITEM_VTABLE(ComplexTextVTable), const_cast<slint::cbindgen_private::ComplexText*>(&self->field_text_193), slint::cbindgen_private::Orientation::Vertical, -1, &self->globals->window().window_handle(), self->self_weak.lock()->into_dyn(), self->tree_index_of_first_child + 29 - 1)) ), slint::cbindgen_private::LayoutItemInfo ( [&](const auto &a_0){ slint::cbindgen_private::LayoutItemInfo o{}; o.constraint = a_0; return o; }(slint::private_api::item_layout_info(SLINT_GET_ITEM_VTABLE(ComplexTextVTable), const_cast<slint::cbindgen_private::ComplexText*>(&self->field_text_194), slint::cbindgen_private::Orientation::Vertical, -1, &self->globals->window().window_handle(), self->self_weak.lock()->into_dyn(), self->tree_index_of_first_child + 30 - 1)) ) }.data(), 2), [&](const auto &a_0, const auto &a_1){ slint::cbindgen_private::Padding o{}; o.begin = a_0; o.end = a_1; return o; }(16, 16), self->field_rectangle_157_empty_169_layout_cache.get()[9], 4),slint::private_api::make_slice<int>(std::array<int, 0>{  }.data(), 0));
                        });
    self->field_rectangle_157_empty_192_layoutinfo_h.set_binding([this]() {
                            [[maybe_unused]] auto self = this;
                            return slint::private_api::box_layout_info_ortho(slint::private_api::make_slice<slint::cbindgen_private::LayoutItemInfo>(std::array<slint::cbindgen_private::LayoutItemInfo, 2>{ slint::cbindgen_private::LayoutItemInfo ( [&](const auto &a_0){ slint::cbindgen_private::LayoutItemInfo o{}; o.constraint = a_0; return o; }(slint::private_api::item_layout_info(SLINT_GET_ITEM_VTABLE(ComplexTextVTable), const_cast<slint::cbindgen_private::ComplexText*>(&self->field_text_193), slint::cbindgen_private::Orientation::Horizontal, -1, &self->globals->window().window_handle(), self->self_weak.lock()->into_dyn(), self->tree_index_of_first_child + 29 - 1)) ), slint::cbindgen_private::LayoutItemInfo ( [&](const auto &a_0){ slint::cbindgen_private::LayoutItemInfo o{}; o.constraint = a_0; return o; }(slint::private_api::item_layout_info(SLINT_GET_ITEM_VTABLE(ComplexTextVTable), const_cast<slint::cbindgen_private::ComplexText*>(&self->field_text_194), slint::cbindgen_private::Orientation::Horizontal, -1, &self->globals->window().window_handle(), self->self_weak.lock()->into_dyn(), self->tree_index_of_first_child + 30 - 1)) ) }.data(), 2),[&](const auto &a_0, const auto &a_1){ slint::cbindgen_private::Padding o{}; o.begin = a_0; o.end = a_1; return o; }(16, 16));
                        });
    self->field_rectangle_157_empty_192_layoutinfo_v.set_binding([this]() {
                            [[maybe_unused]] auto self = this;
                            return slint::private_api::box_layout_info(slint::private_api::make_slice<slint::cbindgen_private::LayoutItemInfo>(std::array<slint::cbindgen_private::LayoutItemInfo, 2>{ slint::cbindgen_private::LayoutItemInfo ( [&](const auto &a_0){ slint::cbindgen_private::LayoutItemInfo o{}; o.constraint = a_0; return o; }(slint::private_api::item_layout_info(SLINT_GET_ITEM_VTABLE(ComplexTextVTable), const_cast<slint::cbindgen_private::ComplexText*>(&self->field_text_193), slint::cbindgen_private::Orientation::Vertical, -1, &self->globals->window().window_handle(), self->self_weak.lock()->into_dyn(), self->tree_index_of_first_child + 29 - 1)) ), slint::cbindgen_private::LayoutItemInfo ( [&](const auto &a_0){ slint::cbindgen_private::LayoutItemInfo o{}; o.constraint = a_0; return o; }(slint::private_api::item_layout_info(SLINT_GET_ITEM_VTABLE(ComplexTextVTable), const_cast<slint::cbindgen_private::ComplexText*>(&self->field_text_194), slint::cbindgen_private::Orientation::Vertical, -1, &self->globals->window().window_handle(), self->self_weak.lock()->into_dyn(), self->tree_index_of_first_child + 30 - 1)) ) }.data(), 2),4,[&](const auto &a_0, const auto &a_1){ slint::cbindgen_private::Padding o{}; o.begin = a_0; o.end = a_1; return o; }(16, 16),slint::cbindgen_private::LayoutAlignment::Center);
                        });
    self->field_rectangle_157_empty_192_padding.set(16);
    self->field_rectangle_157_empty_192_spacing.set(4);
    self->field_rectangle_157_rectangle_165_layoutinfo_h.set_binding([this]() {
                            [[maybe_unused]] auto self = this;
                            return ([&](const auto &a_0, const auto &a_1, const auto &a_2, const auto &a_3, const auto &a_4, const auto &a_5){ slint::cbindgen_private::LayoutInfo o{}; o.max = a_0; o.max_percent = a_1; o.min = a_2; o.min_percent = a_3; o.preferred = a_4; o.stretch = a_5; return o; }(+3.4028234663852886e38, 100, 0, 0, 0, 1) + slint::private_api::item_layout_info(SLINT_GET_ITEM_VTABLE(SimpleTextVTable), const_cast<slint::cbindgen_private::SimpleText*>(&self->field_text_167), slint::cbindgen_private::Orientation::Horizontal, -1, &self->globals->window().window_handle(), self->self_weak.lock()->into_dyn(), self->tree_index_of_first_child + 10 - 1));
                        });
    self->field_rectangle_157_rectangle_165_layoutinfo_v.set_binding([this]() {
                            [[maybe_unused]] auto self = this;
                            return ([&](const auto &a_0, const auto &a_1, const auto &a_2, const auto &a_3, const auto &a_4, const auto &a_5){ slint::cbindgen_private::LayoutInfo o{}; o.max = a_0; o.max_percent = a_1; o.min = a_2; o.min_percent = a_3; o.preferred = a_4; o.stretch = a_5; return o; }(+3.4028234663852886e38, 100, 0, 0, 0, 1) + slint::private_api::item_layout_info(SLINT_GET_ITEM_VTABLE(SimpleTextVTable), const_cast<slint::cbindgen_private::SimpleText*>(&self->field_text_167), slint::cbindgen_private::Orientation::Vertical, -1, &self->globals->window().window_handle(), self->self_weak.lock()->into_dyn(), self->tree_index_of_first_child + 10 - 1));
                        });
    self->field_rectangle_157_text_167_min_height.set_binding([this]() {
                            [[maybe_unused]] auto self = this;
                            return slint::private_api::item_layout_info(SLINT_GET_ITEM_VTABLE(SimpleTextVTable), const_cast<slint::cbindgen_private::SimpleText*>(&self->field_text_167), slint::cbindgen_private::Orientation::Vertical, -1, &self->globals->window().window_handle(), self->self_weak.lock()->into_dyn(), self->tree_index_of_first_child + 10 - 1).min;
                        });
    self->field_rectangle_157_text_167_min_width.set_binding([this]() {
                            [[maybe_unused]] auto self = this;
                            return slint::private_api::item_layout_info(SLINT_GET_ITEM_VTABLE(SimpleTextVTable), const_cast<slint::cbindgen_private::SimpleText*>(&self->field_text_167), slint::cbindgen_private::Orientation::Horizontal, -1, &self->globals->window().window_handle(), self->self_weak.lock()->into_dyn(), self->tree_index_of_first_child + 10 - 1).min;
                        });
    self->field_rectangle_157_text_167_preferred_height.set_binding([this]() {
                            [[maybe_unused]] auto self = this;
                            return slint::private_api::item_layout_info(SLINT_GET_ITEM_VTABLE(SimpleTextVTable), const_cast<slint::cbindgen_private::SimpleText*>(&self->field_text_167), slint::cbindgen_private::Orientation::Vertical, -1, &self->globals->window().window_handle(), self->self_weak.lock()->into_dyn(), self->tree_index_of_first_child + 10 - 1).preferred;
                        });
    self->field_rectangle_157_text_167_preferred_width.set_binding([this]() {
                            [[maybe_unused]] auto self = this;
                            return slint::private_api::item_layout_info(SLINT_GET_ITEM_VTABLE(SimpleTextVTable), const_cast<slint::cbindgen_private::SimpleText*>(&self->field_text_167), slint::cbindgen_private::Orientation::Horizontal, -1, &self->globals->window().window_handle(), self->self_weak.lock()->into_dyn(), self->tree_index_of_first_child + 10 - 1).preferred;
                        });
    self->field_toucharea_158.enabled.set(true);
    self->field_rectangle_161.background.set(slint::Brush(slint::Color::from_argb_encoded(+4.279769125e9)));
    self->field_rectangle_161.border_color.set(slint::Brush(slint::Color::from_argb_encoded(+4.28273033e9)));
    self->field_rectangle_161.border_radius.set(14);
    self->field_rectangle_161.border_width.set(1);
    self->field_text_164.color.set(slint::Brush(slint::Color::from_argb_encoded(+4.291679988e9)));
    self->field_text_164.font_size.set(20);
    self->field_text_164.font_weight.set(static_cast<int>(700));
    self->field_text_164.height.set_binding([this]() {
                            [[maybe_unused]] auto self = this;
                            return self->field_rectangle_157_empty_162_layout_cache.get()[1];
                        });
    self->field_text_164.text.set_binding([this]() {
                            [[maybe_unused]] auto self = this;
                            return (slint::SharedString(u8"Uninstall ") + slint::private_api::optional_or_default(slint::private_api::optional_transform(self->parent.lock(), [&](auto&&x) { return x->field_root_32_pkg.get(); })).pretty_name);
                        });
    self->field_text_164.vertical_alignment.set(slint::cbindgen_private::TextVerticalAlignment::Center);
    self->field_text_164.width.set_binding([this]() {
                            [[maybe_unused]] auto self = this;
                            return self->field_rectangle_157_empty_163_layout_cache.get()[1];
                        });
    self->field_rectangle_165.background.set_binding([this]() {
                            [[maybe_unused]] auto self = this;
                            return slint::Brush((self->field_close_uninstall_ta_166.has_hover.get() ? slint::Color::from_argb_encoded(+4.283980656e9) : slint::Color::from_argb_encoded(+4.28273033e9)));
                        });
    self->field_rectangle_165.border_radius.set(8);
    self->field_close_uninstall_ta_166.clicked.set_handler(
                [this]() {
                    [[maybe_unused]] auto self = this;
                    slint::private_api::optional_then(self->parent.lock(), [&](auto&&x) { x->field_root_32_show_uninstall_modal.set(false); });
                });
    self->field_close_uninstall_ta_166.enabled.set(true);
    self->field_text_167.color.set(slint::Brush(slint::Color::from_argb_encoded(+4.291679988e9)));
    self->field_text_167.font_size.set(13);
    self->field_text_167.font_weight.set(static_cast<int>(700));
    self->field_text_167.height.set_binding([this]() {
                            [[maybe_unused]] auto self = this;
                            return std::max<float>(self->field_rectangle_157_text_167_preferred_height.get(), self->field_rectangle_157_text_167_min_height.get());
                        });
    self->field_text_167.horizontal_alignment.set(slint::cbindgen_private::TextHorizontalAlignment::Center);
    self->field_text_167.text.set(slint::SharedString(u8"Cancel"));
    self->field_text_167.vertical_alignment.set(slint::cbindgen_private::TextVerticalAlignment::Center);
    self->field_text_167.width.set_binding([this]() {
                            [[maybe_unused]] auto self = this;
                            return std::max<float>(self->field_rectangle_157_text_167_preferred_width.get(), self->field_rectangle_157_text_167_min_width.get());
                        });
    self->field_text_168.color.set(slint::Brush(slint::Color::from_argb_encoded(+4.289113544e9)));
    self->field_text_168.font_size.set(14);
    self->field_text_168.height.set_binding([this]() {
                            [[maybe_unused]] auto self = this;
                            return self->field_rectangle_157_empty_162_layout_cache.get()[3];
                        });
    self->field_text_168.text.set(slint::SharedString(u8"Please select how you want to uninstall this package:"));
    self->field_text_168.width.set_binding([this]() {
                            [[maybe_unused]] auto self = this;
                            return ((std::min<float>(700, (slint::private_api::optional_or_default(slint::private_api::optional_transform(self->parent.lock(), [&](auto&&x) { return x->field_root_32_width.get(); })) -(float) 40)) -(float) 30) -(float) 30);
                        });
    self->field_rectangle_170.background.set_binding([this]() {
                            [[maybe_unused]] auto self = this;
                            return slint::Brush((self->field_r_ta_171.has_hover.get() ? slint::Color::from_argb_encoded(+4.28273033e9) : slint::Color::from_argb_encoded(+4.281414212e9)));
                        });
    self->field_rectangle_170.border_radius.set(10);
    self->field_r_ta_171.clicked.set_handler(
                [this]() {
                    [[maybe_unused]] auto self = this;
                    [&]{ slint::private_api::optional_then(self->parent.lock(), [&](auto&&x) { x->field_root_32_show_uninstall_modal.set(false); });slint::private_api::optional_then(self->parent.lock(), [&](auto&&x) { x->field_root_32_remove_clicked.call(slint::SharedString(u8"-R")); }); }();
                });
    self->field_r_ta_171.enabled.set(true);
    self->field_text_173.color.set(slint::Brush(slint::Color::from_argb_encoded(+4.291679988e9)));
    self->field_text_173.font_size.set(14);
    self->field_text_173.font_weight.set(static_cast<int>(700));
    self->field_text_173.height.set_binding([this]() {
                            [[maybe_unused]] auto self = this;
                            return self->field_rectangle_157_empty_172_layout_cache.get()[1];
                        });
    self->field_text_173.text.set(slint::SharedString(u8"Basic Uninstall"));
    self->field_text_173.width.set_binding([this]() {
                            [[maybe_unused]] auto self = this;
                            return ((self->field_rectangle_157_empty_169_width.get() -(float) 16) -(float) 16);
                        });
    self->field_text_173.wrap.set(slint::cbindgen_private::TextWrap::WordWrap);
    self->field_text_174.color.set(slint::Brush(slint::Color::from_argb_encoded(+4.2865471e9)));
    self->field_text_174.font_size.set(12);
    self->field_text_174.height.set_binding([this]() {
                            [[maybe_unused]] auto self = this;
                            return self->field_rectangle_157_empty_172_layout_cache.get()[3];
                        });
    self->field_text_174.text.set(slint::SharedString(u8"Removes the app but keeps its settings and shared files."));
    self->field_text_174.width.set_binding([this]() {
                            [[maybe_unused]] auto self = this;
                            return ((self->field_rectangle_157_empty_169_width.get() -(float) 16) -(float) 16);
                        });
    self->field_text_174.wrap.set(slint::cbindgen_private::TextWrap::WordWrap);
    self->field_rectangle_175.background.set_binding([this]() {
                            [[maybe_unused]] auto self = this;
                            return slint::Brush((self->field_rn_ta_176.has_hover.get() ? slint::Color::from_argb_encoded(+4.28273033e9) : slint::Color::from_argb_encoded(+4.281414212e9)));
                        });
    self->field_rectangle_175.border_radius.set(10);
    self->field_rn_ta_176.clicked.set_handler(
                [this]() {
                    [[maybe_unused]] auto self = this;
                    [&]{ slint::private_api::optional_then(self->parent.lock(), [&](auto&&x) { x->field_root_32_show_uninstall_modal.set(false); });slint::private_api::optional_then(self->parent.lock(), [&](auto&&x) { x->field_root_32_remove_clicked.call(slint::SharedString(u8"-Rn")); }); }();
                });
    self->field_rn_ta_176.enabled.set(true);
    self->field_text_178.color.set(slint::Brush(slint::Color::from_argb_encoded(+4.291679988e9)));
    self->field_text_178.font_size.set(14);
    self->field_text_178.font_weight.set(static_cast<int>(700));
    self->field_text_178.height.set_binding([this]() {
                            [[maybe_unused]] auto self = this;
                            return self->field_rectangle_157_empty_177_layout_cache.get()[1];
                        });
    self->field_text_178.text.set(slint::SharedString(u8"Uninstall and Reset"));
    self->field_text_178.width.set_binding([this]() {
                            [[maybe_unused]] auto self = this;
                            return ((self->field_rectangle_157_empty_169_width.get() -(float) 16) -(float) 16);
                        });
    self->field_text_178.wrap.set(slint::cbindgen_private::TextWrap::WordWrap);
    self->field_text_179.color.set(slint::Brush(slint::Color::from_argb_encoded(+4.2865471e9)));
    self->field_text_179.font_size.set(12);
    self->field_text_179.height.set_binding([this]() {
                            [[maybe_unused]] auto self = this;
                            return self->field_rectangle_157_empty_177_layout_cache.get()[3];
                        });
    self->field_text_179.text.set(slint::SharedString(u8"Removes the app and deletes all its settings."));
    self->field_text_179.width.set_binding([this]() {
                            [[maybe_unused]] auto self = this;
                            return ((self->field_rectangle_157_empty_169_width.get() -(float) 16) -(float) 16);
                        });
    self->field_text_179.wrap.set(slint::cbindgen_private::TextWrap::WordWrap);
    self->field_rectangle_180.background.set_binding([this]() {
                            [[maybe_unused]] auto self = this;
                            return slint::Brush((self->field_rs_ta_181.has_hover.get() ? slint::Color::from_argb_encoded(+4.28273033e9) : slint::Color::from_argb_encoded(+4.281414212e9)));
                        });
    self->field_rectangle_180.border_radius.set(10);
    self->field_rs_ta_181.clicked.set_handler(
                [this]() {
                    [[maybe_unused]] auto self = this;
                    [&]{ slint::private_api::optional_then(self->parent.lock(), [&](auto&&x) { x->field_root_32_show_uninstall_modal.set(false); });slint::private_api::optional_then(self->parent.lock(), [&](auto&&x) { x->field_root_32_remove_clicked.call(slint::SharedString(u8"-Rs")); }); }();
                });
    self->field_rs_ta_181.enabled.set(true);
    self->field_text_183.color.set(slint::Brush(slint::Color::from_argb_encoded(+4.291679988e9)));
    self->field_text_183.font_size.set(14);
    self->field_text_183.font_weight.set(static_cast<int>(700));
    self->field_text_183.height.set_binding([this]() {
                            [[maybe_unused]] auto self = this;
                            return self->field_rectangle_157_empty_182_layout_cache.get()[1];
                        });
    self->field_text_183.text.set(slint::SharedString(u8"Uninstall and Clean Shared Files"));
    self->field_text_183.width.set_binding([this]() {
                            [[maybe_unused]] auto self = this;
                            return ((self->field_rectangle_157_empty_169_width.get() -(float) 16) -(float) 16);
                        });
    self->field_text_183.wrap.set(slint::cbindgen_private::TextWrap::WordWrap);
    self->field_text_184.color.set(slint::Brush(slint::Color::from_argb_encoded(+4.2865471e9)));
    self->field_text_184.font_size.set(12);
    self->field_text_184.height.set_binding([this]() {
                            [[maybe_unused]] auto self = this;
                            return self->field_rectangle_157_empty_182_layout_cache.get()[3];
                        });
    self->field_text_184.text.set(slint::SharedString(u8"Removes the app and shared files that are no longer needed. Keeps your settings."));
    self->field_text_184.width.set_binding([this]() {
                            [[maybe_unused]] auto self = this;
                            return ((self->field_rectangle_157_empty_169_width.get() -(float) 16) -(float) 16);
                        });
    self->field_text_184.wrap.set(slint::cbindgen_private::TextWrap::WordWrap);
    self->field_rectangle_185.background.set_binding([this]() {
                            [[maybe_unused]] auto self = this;
                            return slint::Brush((self->field_rdd_ta_186.has_hover.get() ? slint::Color::from_argb_encoded(+4.28273033e9) : slint::Color::from_argb_encoded(+4.281414212e9)));
                        });
    self->field_rectangle_185.border_color.set(slint::Brush(slint::Color::from_argb_encoded(+4.29415108e9)));
    self->field_rectangle_185.border_radius.set(10);
    self->field_rectangle_185.border_width.set(1);
    self->field_rdd_ta_186.clicked.set_handler(
                [this]() {
                    [[maybe_unused]] auto self = this;
                    [&]{ slint::private_api::optional_then(self->parent.lock(), [&](auto&&x) { x->field_root_32_show_uninstall_modal.set(false); });slint::private_api::optional_then(self->parent.lock(), [&](auto&&x) { x->field_root_32_remove_clicked.call(slint::SharedString(u8"-Rdd")); }); }();
                });
    self->field_rdd_ta_186.enabled.set(true);
    self->field_text_188.color.set(slint::Brush(slint::Color::from_argb_encoded(+4.29415108e9)));
    self->field_text_188.font_size.set(14);
    self->field_text_188.font_weight.set(static_cast<int>(700));
    self->field_text_188.height.set_binding([this]() {
                            [[maybe_unused]] auto self = this;
                            return self->field_rectangle_157_empty_187_layout_cache.get()[1];
                        });
    self->field_text_188.text.set(slint::SharedString(u8"Force Uninstall (Advanced)"));
    self->field_text_188.width.set_binding([this]() {
                            [[maybe_unused]] auto self = this;
                            return ((self->field_rectangle_157_empty_169_width.get() -(float) 16) -(float) 16);
                        });
    self->field_text_188.wrap.set(slint::cbindgen_private::TextWrap::WordWrap);
    self->field_text_189.color.set(slint::Brush(slint::Color::from_argb_encoded(+4.2865471e9)));
    self->field_text_189.font_size.set(12);
    self->field_text_189.height.set_binding([this]() {
                            [[maybe_unused]] auto self = this;
                            return self->field_rectangle_157_empty_187_layout_cache.get()[3];
                        });
    self->field_text_189.text.set(slint::SharedString(u8"Removes the app even if other apps rely on it. May break things!"));
    self->field_text_189.width.set_binding([this]() {
                            [[maybe_unused]] auto self = this;
                            return ((self->field_rectangle_157_empty_169_width.get() -(float) 16) -(float) 16);
                        });
    self->field_text_189.wrap.set(slint::cbindgen_private::TextWrap::WordWrap);
    self->field_rectangle_190.background.set_binding([this]() {
                            [[maybe_unused]] auto self = this;
                            return slint::Brush((self->field_rns_ta_191.has_hover.get() ? slint::Color::from_argb_encoded(+4.283980656e9) : slint::Color::from_argb_encoded(+4.28273033e9)));
                        });
    self->field_rectangle_190.border_color.set(slint::Brush(slint::Color::from_argb_encoded(+4.289127329e9)));
    self->field_rectangle_190.border_radius.set(10);
    self->field_rectangle_190.border_width.set(1);
    self->field_rns_ta_191.clicked.set_handler(
                [this]() {
                    [[maybe_unused]] auto self = this;
                    [&]{ slint::private_api::optional_then(self->parent.lock(), [&](auto&&x) { x->field_root_32_show_uninstall_modal.set(false); });slint::private_api::optional_then(self->parent.lock(), [&](auto&&x) { x->field_root_32_remove_clicked.call(slint::SharedString(u8"-Rns")); }); }();
                });
    self->field_rns_ta_191.enabled.set(true);
    self->field_text_193.color.set(slint::Brush(slint::Color::from_argb_encoded(+4.289127329e9)));
    self->field_text_193.font_size.set(14);
    self->field_text_193.font_weight.set(static_cast<int>(700));
    self->field_text_193.height.set_binding([this]() {
                            [[maybe_unused]] auto self = this;
                            return self->field_rectangle_157_empty_192_layout_cache.get()[1];
                        });
    self->field_text_193.text.set(slint::SharedString(u8"Complete Uninstall (Recommended)"));
    self->field_text_193.width.set_binding([this]() {
                            [[maybe_unused]] auto self = this;
                            return ((self->field_rectangle_157_empty_169_width.get() -(float) 16) -(float) 16);
                        });
    self->field_text_193.wrap.set(slint::cbindgen_private::TextWrap::WordWrap);
    self->field_text_194.color.set(slint::Brush(slint::Color::from_argb_encoded(+4.2865471e9)));
    self->field_text_194.font_size.set(12);
    self->field_text_194.height.set_binding([this]() {
                            [[maybe_unused]] auto self = this;
                            return self->field_rectangle_157_empty_192_layout_cache.get()[3];
                        });
    self->field_text_194.text.set(slint::SharedString(u8"Safely removes the app, deletes its settings, and cleans up all unneeded files."));
    self->field_text_194.width.set_binding([this]() {
                            [[maybe_unused]] auto self = this;
                            return ((self->field_rectangle_157_empty_169_width.get() -(float) 16) -(float) 16);
                        });
    self->field_text_194.wrap.set(slint::cbindgen_private::TextWrap::WordWrap);
    self->field_rectangle_157.background.set_constant();
    self->field_rectangle_157_empty_159_alignment.set_constant();
    self->field_rectangle_157_empty_162_padding.set_constant();
    self->field_rectangle_157_empty_162_spacing.set_constant();
    self->field_rectangle_157_empty_169_alignment.set_constant();
    self->field_rectangle_157_empty_169_spacing.set_constant();
    self->field_rectangle_157_empty_172_alignment.set_constant();
    self->field_rectangle_157_empty_172_padding.set_constant();
    self->field_rectangle_157_empty_172_spacing.set_constant();
    self->field_rectangle_157_empty_177_alignment.set_constant();
    self->field_rectangle_157_empty_177_padding.set_constant();
    self->field_rectangle_157_empty_177_spacing.set_constant();
    self->field_rectangle_157_empty_182_alignment.set_constant();
    self->field_rectangle_157_empty_182_padding.set_constant();
    self->field_rectangle_157_empty_182_spacing.set_constant();
    self->field_rectangle_157_empty_187_alignment.set_constant();
    self->field_rectangle_157_empty_187_padding.set_constant();
    self->field_rectangle_157_empty_187_spacing.set_constant();
    self->field_rectangle_157_empty_192_alignment.set_constant();
    self->field_rectangle_157_empty_192_padding.set_constant();
    self->field_rectangle_157_empty_192_spacing.set_constant();
    self->field_toucharea_158.enabled.set_constant();
    self->field_toucharea_158.mouse_cursor.set_constant();
    self->field_rectangle_161.background.set_constant();
    self->field_rectangle_161.border_color.set_constant();
    self->field_rectangle_161.border_radius.set_constant();
    self->field_rectangle_161.border_width.set_constant();
    self->field_text_164.color.set_constant();
    self->field_text_164.font_size.set_constant();
    self->field_text_164.font_weight.set_constant();
    self->field_text_164.horizontal_alignment.set_constant();
    self->field_text_164.vertical_alignment.set_constant();
    self->field_rectangle_165.border_color.set_constant();
    self->field_rectangle_165.border_radius.set_constant();
    self->field_rectangle_165.border_width.set_constant();
    self->field_close_uninstall_ta_166.enabled.set_constant();
    self->field_close_uninstall_ta_166.mouse_cursor.set_constant();
    self->field_text_167.color.set_constant();
    self->field_text_167.font_size.set_constant();
    self->field_text_167.font_weight.set_constant();
    self->field_text_167.horizontal_alignment.set_constant();
    self->field_text_167.text.set_constant();
    self->field_text_167.vertical_alignment.set_constant();
    self->field_text_168.color.set_constant();
    self->field_text_168.font_size.set_constant();
    self->field_text_168.font_weight.set_constant();
    self->field_text_168.horizontal_alignment.set_constant();
    self->field_text_168.text.set_constant();
    self->field_text_168.vertical_alignment.set_constant();
    self->field_rectangle_170.border_color.set_constant();
    self->field_rectangle_170.border_radius.set_constant();
    self->field_rectangle_170.border_width.set_constant();
    self->field_r_ta_171.enabled.set_constant();
    self->field_r_ta_171.mouse_cursor.set_constant();
    self->field_text_173.color.set_constant();
    self->field_text_173.font_family.set_constant();
    self->field_text_173.font_italic.set_constant();
    self->field_text_173.font_size.set_constant();
    self->field_text_173.font_weight.set_constant();
    self->field_text_173.horizontal_alignment.set_constant();
    self->field_text_173.letter_spacing.set_constant();
    self->field_text_173.overflow.set_constant();
    self->field_text_173.stroke.set_constant();
    self->field_text_173.stroke_style.set_constant();
    self->field_text_173.stroke_width.set_constant();
    self->field_text_173.text.set_constant();
    self->field_text_173.vertical_alignment.set_constant();
    self->field_text_173.wrap.set_constant();
    self->field_text_174.color.set_constant();
    self->field_text_174.font_family.set_constant();
    self->field_text_174.font_italic.set_constant();
    self->field_text_174.font_size.set_constant();
    self->field_text_174.font_weight.set_constant();
    self->field_text_174.horizontal_alignment.set_constant();
    self->field_text_174.letter_spacing.set_constant();
    self->field_text_174.overflow.set_constant();
    self->field_text_174.stroke.set_constant();
    self->field_text_174.stroke_style.set_constant();
    self->field_text_174.stroke_width.set_constant();
    self->field_text_174.text.set_constant();
    self->field_text_174.vertical_alignment.set_constant();
    self->field_text_174.wrap.set_constant();
    self->field_rectangle_175.border_color.set_constant();
    self->field_rectangle_175.border_radius.set_constant();
    self->field_rectangle_175.border_width.set_constant();
    self->field_rn_ta_176.enabled.set_constant();
    self->field_rn_ta_176.mouse_cursor.set_constant();
    self->field_text_178.color.set_constant();
    self->field_text_178.font_family.set_constant();
    self->field_text_178.font_italic.set_constant();
    self->field_text_178.font_size.set_constant();
    self->field_text_178.font_weight.set_constant();
    self->field_text_178.horizontal_alignment.set_constant();
    self->field_text_178.letter_spacing.set_constant();
    self->field_text_178.overflow.set_constant();
    self->field_text_178.stroke.set_constant();
    self->field_text_178.stroke_style.set_constant();
    self->field_text_178.stroke_width.set_constant();
    self->field_text_178.text.set_constant();
    self->field_text_178.vertical_alignment.set_constant();
    self->field_text_178.wrap.set_constant();
    self->field_text_179.color.set_constant();
    self->field_text_179.font_family.set_constant();
    self->field_text_179.font_italic.set_constant();
    self->field_text_179.font_size.set_constant();
    self->field_text_179.font_weight.set_constant();
    self->field_text_179.horizontal_alignment.set_constant();
    self->field_text_179.letter_spacing.set_constant();
    self->field_text_179.overflow.set_constant();
    self->field_text_179.stroke.set_constant();
    self->field_text_179.stroke_style.set_constant();
    self->field_text_179.stroke_width.set_constant();
    self->field_text_179.text.set_constant();
    self->field_text_179.vertical_alignment.set_constant();
    self->field_text_179.wrap.set_constant();
    self->field_rectangle_180.border_color.set_constant();
    self->field_rectangle_180.border_radius.set_constant();
    self->field_rectangle_180.border_width.set_constant();
    self->field_rs_ta_181.enabled.set_constant();
    self->field_rs_ta_181.mouse_cursor.set_constant();
    self->field_text_183.color.set_constant();
    self->field_text_183.font_family.set_constant();
    self->field_text_183.font_italic.set_constant();
    self->field_text_183.font_size.set_constant();
    self->field_text_183.font_weight.set_constant();
    self->field_text_183.horizontal_alignment.set_constant();
    self->field_text_183.letter_spacing.set_constant();
    self->field_text_183.overflow.set_constant();
    self->field_text_183.stroke.set_constant();
    self->field_text_183.stroke_style.set_constant();
    self->field_text_183.stroke_width.set_constant();
    self->field_text_183.text.set_constant();
    self->field_text_183.vertical_alignment.set_constant();
    self->field_text_183.wrap.set_constant();
    self->field_text_184.color.set_constant();
    self->field_text_184.font_family.set_constant();
    self->field_text_184.font_italic.set_constant();
    self->field_text_184.font_size.set_constant();
    self->field_text_184.font_weight.set_constant();
    self->field_text_184.horizontal_alignment.set_constant();
    self->field_text_184.letter_spacing.set_constant();
    self->field_text_184.overflow.set_constant();
    self->field_text_184.stroke.set_constant();
    self->field_text_184.stroke_style.set_constant();
    self->field_text_184.stroke_width.set_constant();
    self->field_text_184.text.set_constant();
    self->field_text_184.vertical_alignment.set_constant();
    self->field_text_184.wrap.set_constant();
    self->field_rectangle_185.border_color.set_constant();
    self->field_rectangle_185.border_radius.set_constant();
    self->field_rectangle_185.border_width.set_constant();
    self->field_rdd_ta_186.enabled.set_constant();
    self->field_rdd_ta_186.mouse_cursor.set_constant();
    self->field_text_188.color.set_constant();
    self->field_text_188.font_family.set_constant();
    self->field_text_188.font_italic.set_constant();
    self->field_text_188.font_size.set_constant();
    self->field_text_188.font_weight.set_constant();
    self->field_text_188.horizontal_alignment.set_constant();
    self->field_text_188.letter_spacing.set_constant();
    self->field_text_188.overflow.set_constant();
    self->field_text_188.stroke.set_constant();
    self->field_text_188.stroke_style.set_constant();
    self->field_text_188.stroke_width.set_constant();
    self->field_text_188.text.set_constant();
    self->field_text_188.vertical_alignment.set_constant();
    self->field_text_188.wrap.set_constant();
    self->field_text_189.color.set_constant();
    self->field_text_189.font_family.set_constant();
    self->field_text_189.font_italic.set_constant();
    self->field_text_189.font_size.set_constant();
    self->field_text_189.font_weight.set_constant();
    self->field_text_189.horizontal_alignment.set_constant();
    self->field_text_189.letter_spacing.set_constant();
    self->field_text_189.overflow.set_constant();
    self->field_text_189.stroke.set_constant();
    self->field_text_189.stroke_style.set_constant();
    self->field_text_189.stroke_width.set_constant();
    self->field_text_189.text.set_constant();
    self->field_text_189.vertical_alignment.set_constant();
    self->field_text_189.wrap.set_constant();
    self->field_rectangle_190.border_color.set_constant();
    self->field_rectangle_190.border_radius.set_constant();
    self->field_rectangle_190.border_width.set_constant();
    self->field_rns_ta_191.enabled.set_constant();
    self->field_rns_ta_191.mouse_cursor.set_constant();
    self->field_text_193.color.set_constant();
    self->field_text_193.font_family.set_constant();
    self->field_text_193.font_italic.set_constant();
    self->field_text_193.font_size.set_constant();
    self->field_text_193.font_weight.set_constant();
    self->field_text_193.horizontal_alignment.set_constant();
    self->field_text_193.letter_spacing.set_constant();
    self->field_text_193.overflow.set_constant();
    self->field_text_193.stroke.set_constant();
    self->field_text_193.stroke_style.set_constant();
    self->field_text_193.stroke_width.set_constant();
    self->field_text_193.text.set_constant();
    self->field_text_193.vertical_alignment.set_constant();
    self->field_text_193.wrap.set_constant();
    self->field_text_194.color.set_constant();
    self->field_text_194.font_family.set_constant();
    self->field_text_194.font_italic.set_constant();
    self->field_text_194.font_size.set_constant();
    self->field_text_194.font_weight.set_constant();
    self->field_text_194.horizontal_alignment.set_constant();
    self->field_text_194.letter_spacing.set_constant();
    self->field_text_194.overflow.set_constant();
    self->field_text_194.stroke.set_constant();
    self->field_text_194.stroke_style.set_constant();
    self->field_text_194.stroke_width.set_constant();
    self->field_text_194.text.set_constant();
    self->field_text_194.vertical_alignment.set_constant();
    self->field_text_194.wrap.set_constant();
}

auto Component_rectangle_157::user_init () -> void{
    [[maybe_unused]] auto self = this;
}

auto Component_rectangle_157::layout_info (slint::cbindgen_private::Orientation o) const -> slint::cbindgen_private::LayoutInfo{
    [[maybe_unused]] auto self = this;
    return o == slint::cbindgen_private::Orientation::Horizontal ? ([&](const auto &a_0, const auto &a_1, const auto &a_2, const auto &a_3, const auto &a_4, const auto &a_5){ slint::cbindgen_private::LayoutInfo o{}; o.max = a_0; o.max_percent = a_1; o.min = a_2; o.min_percent = a_3; o.preferred = a_4; o.stretch = a_5; return o; }(+3.4028234663852886e38, 100, 0, 0, 0, 1) + self->field_rectangle_157_empty_159_layoutinfo_h.get()) : ([&](const auto &a_0, const auto &a_1, const auto &a_2, const auto &a_3, const auto &a_4, const auto &a_5){ slint::cbindgen_private::LayoutInfo o{}; o.max = a_0; o.max_percent = a_1; o.min = a_2; o.min_percent = a_3; o.preferred = a_4; o.stretch = a_5; return o; }(+3.4028234663852886e38, 100, 0, 0, 0, 1) + self->field_rectangle_157_empty_159_layoutinfo_v.get());
}

auto Component_rectangle_157::item_geometry (uint32_t index) const -> slint::cbindgen_private::Rect{
    [[maybe_unused]] auto self = this;
    switch (index) {
        case 0: return slint::private_api::convert_anonymous_rect(std::make_tuple(float(slint::private_api::optional_or_default(slint::private_api::optional_transform(self->parent.lock(), [&](auto&&x) { return x->field_root_32_height.get(); }))), float(slint::private_api::optional_or_default(slint::private_api::optional_transform(self->parent.lock(), [&](auto&&x) { return x->field_root_32_width.get(); }))), float(0), float(0)));
        case 1: return slint::private_api::convert_anonymous_rect(std::make_tuple(float(slint::private_api::optional_or_default(slint::private_api::optional_transform(self->parent.lock(), [&](auto&&x) { return x->field_root_32_height.get(); }))), float(slint::private_api::optional_or_default(slint::private_api::optional_transform(self->parent.lock(), [&](auto&&x) { return x->field_root_32_width.get(); }))), float(0), float(0)));
        case 2: return slint::private_api::convert_anonymous_rect(std::make_tuple(float(self->field_rectangle_157_empty_159_layout_cache.get()[1]), float(slint::private_api::optional_or_default(slint::private_api::optional_transform(self->parent.lock(), [&](auto&&x) { return x->field_root_32_width.get(); }))), float(0), float(self->field_rectangle_157_empty_159_layout_cache.get()[0])));
        case 3: return slint::private_api::convert_anonymous_rect(std::make_tuple(float(self->field_rectangle_157_empty_159_layout_cache.get()[1]), float(std::min<float>(700, (slint::private_api::optional_or_default(slint::private_api::optional_transform(self->parent.lock(), [&](auto&&x) { return x->field_root_32_width.get(); })) -(float) 40))), float(self->field_rectangle_157_empty_160_layout_cache.get()[0]), float(0)));
        case 4: return slint::private_api::convert_anonymous_rect(std::make_tuple(float(self->field_rectangle_157_empty_162_layout_cache.get()[1]), float(((std::min<float>(700, (slint::private_api::optional_or_default(slint::private_api::optional_transform(self->parent.lock(), [&](auto&&x) { return x->field_root_32_width.get(); })) -(float) 40)) -(float) 30) -(float) 30)), float(30), float(self->field_rectangle_157_empty_162_layout_cache.get()[0])));
        case 5: return slint::private_api::convert_anonymous_rect(std::make_tuple(float(self->field_rectangle_157_empty_162_layout_cache.get()[3]), float(((std::min<float>(700, (slint::private_api::optional_or_default(slint::private_api::optional_transform(self->parent.lock(), [&](auto&&x) { return x->field_root_32_width.get(); })) -(float) 40)) -(float) 30) -(float) 30)), float(30), float(self->field_rectangle_157_empty_162_layout_cache.get()[2])));
        case 6: return slint::private_api::convert_anonymous_rect(std::make_tuple(float(self->field_rectangle_157_empty_162_layout_cache.get()[5]), float(((std::min<float>(700, (slint::private_api::optional_or_default(slint::private_api::optional_transform(self->parent.lock(), [&](auto&&x) { return x->field_root_32_width.get(); })) -(float) 40)) -(float) 30) -(float) 30)), float(30), float(self->field_rectangle_157_empty_162_layout_cache.get()[4])));
        case 7: return slint::private_api::convert_anonymous_rect(std::make_tuple(float(self->field_rectangle_157_empty_162_layout_cache.get()[1]), float(self->field_rectangle_157_empty_163_layout_cache.get()[1]), float(self->field_rectangle_157_empty_163_layout_cache.get()[0]), float(0)));
        case 8: return slint::private_api::convert_anonymous_rect(std::make_tuple(float(30), float(80), float(self->field_rectangle_157_empty_163_layout_cache.get()[2]), float(0)));
        case 9: return slint::private_api::convert_anonymous_rect(std::make_tuple(float(30), float(80), float(0), float(0)));
        case 10: return slint::private_api::convert_anonymous_rect(std::make_tuple(float(self->field_text_167.height.get()), float(self->field_text_167.width.get()), float(((80 -(float) self->field_text_167.width.get()) /(float) 2)), float(((30 -(float) self->field_text_167.height.get()) /(float) 2))));
        case 11: return slint::private_api::convert_anonymous_rect(std::make_tuple(float(self->field_rectangle_157_empty_169_layout_cache.get()[1]), float(((std::min<float>(700, (slint::private_api::optional_or_default(slint::private_api::optional_transform(self->parent.lock(), [&](auto&&x) { return x->field_root_32_width.get(); })) -(float) 40)) -(float) 30) -(float) 30)), float(0), float(self->field_rectangle_157_empty_169_layout_cache.get()[0])));
        case 12: return slint::private_api::convert_anonymous_rect(std::make_tuple(float(self->field_rectangle_157_empty_169_layout_cache.get()[3]), float(((std::min<float>(700, (slint::private_api::optional_or_default(slint::private_api::optional_transform(self->parent.lock(), [&](auto&&x) { return x->field_root_32_width.get(); })) -(float) 40)) -(float) 30) -(float) 30)), float(0), float(self->field_rectangle_157_empty_169_layout_cache.get()[2])));
        case 13: return slint::private_api::convert_anonymous_rect(std::make_tuple(float(self->field_rectangle_157_empty_169_layout_cache.get()[5]), float(((std::min<float>(700, (slint::private_api::optional_or_default(slint::private_api::optional_transform(self->parent.lock(), [&](auto&&x) { return x->field_root_32_width.get(); })) -(float) 40)) -(float) 30) -(float) 30)), float(0), float(self->field_rectangle_157_empty_169_layout_cache.get()[4])));
        case 14: return slint::private_api::convert_anonymous_rect(std::make_tuple(float(self->field_rectangle_157_empty_169_layout_cache.get()[7]), float(((std::min<float>(700, (slint::private_api::optional_or_default(slint::private_api::optional_transform(self->parent.lock(), [&](auto&&x) { return x->field_root_32_width.get(); })) -(float) 40)) -(float) 30) -(float) 30)), float(0), float(self->field_rectangle_157_empty_169_layout_cache.get()[6])));
        case 15: return slint::private_api::convert_anonymous_rect(std::make_tuple(float(self->field_rectangle_157_empty_169_layout_cache.get()[9]), float(((std::min<float>(700, (slint::private_api::optional_or_default(slint::private_api::optional_transform(self->parent.lock(), [&](auto&&x) { return x->field_root_32_width.get(); })) -(float) 40)) -(float) 30) -(float) 30)), float(0), float(self->field_rectangle_157_empty_169_layout_cache.get()[8])));
        case 16: return slint::private_api::convert_anonymous_rect(std::make_tuple(float(self->field_rectangle_157_empty_169_layout_cache.get()[1]), float(self->field_rectangle_157_empty_169_width.get()), float(0), float(0)));
        case 17: return slint::private_api::convert_anonymous_rect(std::make_tuple(float(self->field_rectangle_157_empty_172_layout_cache.get()[1]), float(((((std::min<float>(700, (slint::private_api::optional_or_default(slint::private_api::optional_transform(self->parent.lock(), [&](auto&&x) { return x->field_root_32_width.get(); })) -(float) 40)) -(float) 30) -(float) 30) -(float) 16) -(float) 16)), float(16), float(self->field_rectangle_157_empty_172_layout_cache.get()[0])));
        case 18: return slint::private_api::convert_anonymous_rect(std::make_tuple(float(self->field_rectangle_157_empty_172_layout_cache.get()[3]), float(((((std::min<float>(700, (slint::private_api::optional_or_default(slint::private_api::optional_transform(self->parent.lock(), [&](auto&&x) { return x->field_root_32_width.get(); })) -(float) 40)) -(float) 30) -(float) 30) -(float) 16) -(float) 16)), float(16), float(self->field_rectangle_157_empty_172_layout_cache.get()[2])));
        case 19: return slint::private_api::convert_anonymous_rect(std::make_tuple(float(self->field_rectangle_157_empty_169_layout_cache.get()[3]), float(((std::min<float>(700, (slint::private_api::optional_or_default(slint::private_api::optional_transform(self->parent.lock(), [&](auto&&x) { return x->field_root_32_width.get(); })) -(float) 40)) -(float) 30) -(float) 30)), float(0), float(0)));
        case 20: return slint::private_api::convert_anonymous_rect(std::make_tuple(float(self->field_rectangle_157_empty_177_layout_cache.get()[1]), float(((((std::min<float>(700, (slint::private_api::optional_or_default(slint::private_api::optional_transform(self->parent.lock(), [&](auto&&x) { return x->field_root_32_width.get(); })) -(float) 40)) -(float) 30) -(float) 30) -(float) 16) -(float) 16)), float(16), float(self->field_rectangle_157_empty_177_layout_cache.get()[0])));
        case 21: return slint::private_api::convert_anonymous_rect(std::make_tuple(float(self->field_rectangle_157_empty_177_layout_cache.get()[3]), float(((((std::min<float>(700, (slint::private_api::optional_or_default(slint::private_api::optional_transform(self->parent.lock(), [&](auto&&x) { return x->field_root_32_width.get(); })) -(float) 40)) -(float) 30) -(float) 30) -(float) 16) -(float) 16)), float(16), float(self->field_rectangle_157_empty_177_layout_cache.get()[2])));
        case 22: return slint::private_api::convert_anonymous_rect(std::make_tuple(float(self->field_rectangle_157_empty_169_layout_cache.get()[5]), float(((std::min<float>(700, (slint::private_api::optional_or_default(slint::private_api::optional_transform(self->parent.lock(), [&](auto&&x) { return x->field_root_32_width.get(); })) -(float) 40)) -(float) 30) -(float) 30)), float(0), float(0)));
        case 23: return slint::private_api::convert_anonymous_rect(std::make_tuple(float(self->field_rectangle_157_empty_182_layout_cache.get()[1]), float(((((std::min<float>(700, (slint::private_api::optional_or_default(slint::private_api::optional_transform(self->parent.lock(), [&](auto&&x) { return x->field_root_32_width.get(); })) -(float) 40)) -(float) 30) -(float) 30) -(float) 16) -(float) 16)), float(16), float(self->field_rectangle_157_empty_182_layout_cache.get()[0])));
        case 24: return slint::private_api::convert_anonymous_rect(std::make_tuple(float(self->field_rectangle_157_empty_182_layout_cache.get()[3]), float(((((std::min<float>(700, (slint::private_api::optional_or_default(slint::private_api::optional_transform(self->parent.lock(), [&](auto&&x) { return x->field_root_32_width.get(); })) -(float) 40)) -(float) 30) -(float) 30) -(float) 16) -(float) 16)), float(16), float(self->field_rectangle_157_empty_182_layout_cache.get()[2])));
        case 25: return slint::private_api::convert_anonymous_rect(std::make_tuple(float(self->field_rectangle_157_empty_169_layout_cache.get()[7]), float(self->field_rectangle_157_empty_169_width.get()), float(0), float(0)));
        case 26: return slint::private_api::convert_anonymous_rect(std::make_tuple(float(self->field_rectangle_157_empty_187_layout_cache.get()[1]), float(((((std::min<float>(700, (slint::private_api::optional_or_default(slint::private_api::optional_transform(self->parent.lock(), [&](auto&&x) { return x->field_root_32_width.get(); })) -(float) 40)) -(float) 30) -(float) 30) -(float) 16) -(float) 16)), float(16), float(self->field_rectangle_157_empty_187_layout_cache.get()[0])));
        case 27: return slint::private_api::convert_anonymous_rect(std::make_tuple(float(self->field_rectangle_157_empty_187_layout_cache.get()[3]), float(((((std::min<float>(700, (slint::private_api::optional_or_default(slint::private_api::optional_transform(self->parent.lock(), [&](auto&&x) { return x->field_root_32_width.get(); })) -(float) 40)) -(float) 30) -(float) 30) -(float) 16) -(float) 16)), float(16), float(self->field_rectangle_157_empty_187_layout_cache.get()[2])));
        case 28: return slint::private_api::convert_anonymous_rect(std::make_tuple(float(self->field_rectangle_157_empty_169_layout_cache.get()[9]), float(((std::min<float>(700, (slint::private_api::optional_or_default(slint::private_api::optional_transform(self->parent.lock(), [&](auto&&x) { return x->field_root_32_width.get(); })) -(float) 40)) -(float) 30) -(float) 30)), float(0), float(0)));
        case 29: return slint::private_api::convert_anonymous_rect(std::make_tuple(float(self->field_rectangle_157_empty_192_layout_cache.get()[1]), float(((((std::min<float>(700, (slint::private_api::optional_or_default(slint::private_api::optional_transform(self->parent.lock(), [&](auto&&x) { return x->field_root_32_width.get(); })) -(float) 40)) -(float) 30) -(float) 30) -(float) 16) -(float) 16)), float(16), float(self->field_rectangle_157_empty_192_layout_cache.get()[0])));
        case 30: return slint::private_api::convert_anonymous_rect(std::make_tuple(float(self->field_rectangle_157_empty_192_layout_cache.get()[3]), float(((((std::min<float>(700, (slint::private_api::optional_or_default(slint::private_api::optional_transform(self->parent.lock(), [&](auto&&x) { return x->field_root_32_width.get(); })) -(float) 40)) -(float) 30) -(float) 30) -(float) 16) -(float) 16)), float(16), float(self->field_rectangle_157_empty_192_layout_cache.get()[2])));
    }
    return {};
}

auto Component_rectangle_157::accessible_role (uint32_t index) const -> slint::cbindgen_private::AccessibleRole{
    [[maybe_unused]] auto self = this;
    switch (index) {
        case 5: return slint::cbindgen_private::AccessibleRole::Text;
        case 7: return slint::cbindgen_private::AccessibleRole::Text;
        case 10: return slint::cbindgen_private::AccessibleRole::Text;
        case 17: return slint::cbindgen_private::AccessibleRole::Text;
        case 18: return slint::cbindgen_private::AccessibleRole::Text;
        case 20: return slint::cbindgen_private::AccessibleRole::Text;
        case 21: return slint::cbindgen_private::AccessibleRole::Text;
        case 23: return slint::cbindgen_private::AccessibleRole::Text;
        case 24: return slint::cbindgen_private::AccessibleRole::Text;
        case 26: return slint::cbindgen_private::AccessibleRole::Text;
        case 27: return slint::cbindgen_private::AccessibleRole::Text;
        case 29: return slint::cbindgen_private::AccessibleRole::Text;
        case 30: return slint::cbindgen_private::AccessibleRole::Text;
    }
    return {};
}

auto Component_rectangle_157::accessible_string_property (uint32_t index, slint::cbindgen_private::AccessibleStringProperty what) const -> std::optional<slint::SharedString>{
    [[maybe_unused]] auto self = this;
    switch ((index << 8) | uintptr_t(what)) {
        case (5 << 8) | uintptr_t(slint::cbindgen_private::AccessibleStringProperty::Label): return slint::SharedString(u8"Please select how you want to uninstall this package:");
        case (7 << 8) | uintptr_t(slint::cbindgen_private::AccessibleStringProperty::Label): return self->field_text_164.text.get();
        case (10 << 8) | uintptr_t(slint::cbindgen_private::AccessibleStringProperty::Label): return slint::SharedString(u8"Cancel");
        case (17 << 8) | uintptr_t(slint::cbindgen_private::AccessibleStringProperty::Label): return slint::SharedString(u8"Basic Uninstall");
        case (18 << 8) | uintptr_t(slint::cbindgen_private::AccessibleStringProperty::Label): return slint::SharedString(u8"Removes the app but keeps its settings and shared files.");
        case (20 << 8) | uintptr_t(slint::cbindgen_private::AccessibleStringProperty::Label): return slint::SharedString(u8"Uninstall and Reset");
        case (21 << 8) | uintptr_t(slint::cbindgen_private::AccessibleStringProperty::Label): return slint::SharedString(u8"Removes the app and deletes all its settings.");
        case (23 << 8) | uintptr_t(slint::cbindgen_private::AccessibleStringProperty::Label): return slint::SharedString(u8"Uninstall and Clean Shared Files");
        case (24 << 8) | uintptr_t(slint::cbindgen_private::AccessibleStringProperty::Label): return slint::SharedString(u8"Removes the app and shared files that are no longer needed. Keeps your settings.");
        case (26 << 8) | uintptr_t(slint::cbindgen_private::AccessibleStringProperty::Label): return slint::SharedString(u8"Force Uninstall (Advanced)");
        case (27 << 8) | uintptr_t(slint::cbindgen_private::AccessibleStringProperty::Label): return slint::SharedString(u8"Removes the app even if other apps rely on it. May break things!");
        case (29 << 8) | uintptr_t(slint::cbindgen_private::AccessibleStringProperty::Label): return slint::SharedString(u8"Complete Uninstall (Recommended)");
        case (30 << 8) | uintptr_t(slint::cbindgen_private::AccessibleStringProperty::Label): return slint::SharedString(u8"Safely removes the app, deletes its settings, and cleans up all unneeded files.");
    }
    return {};
}

auto Component_rectangle_157::accessibility_action (uint32_t index, const slint::cbindgen_private::AccessibilityAction &action) const -> void{
    [[maybe_unused]] auto self = this;
    switch ((index << 8) | uintptr_t(action.tag)) {
    }
    return ;
}

auto Component_rectangle_157::supported_accessibility_actions (uint32_t index) const -> uint32_t{
    [[maybe_unused]] auto self = this;
    switch (index) {
    }
    return {};
}

auto Component_rectangle_157::element_infos (uint32_t index) const -> std::optional<slint::SharedString>{
    [[maybe_unused]] auto self = this;
    switch (index) {
    }
    return {};
}

auto Component_rectangle_157::ensure_instantiated () const -> bool{
    [[maybe_unused]] auto self = this;
    bool _changed = false;
    return _changed;
}

auto Component_rectangle_157::visit_children (slint::private_api::ItemTreeRef component, intptr_t index, slint::private_api::TraversalOrder order, slint::private_api::ItemVisitorRefMut visitor) -> uint64_t{
    static const auto dyn_visit = [] (const void *base,  [[maybe_unused]] slint::private_api::TraversalOrder order, [[maybe_unused]] slint::private_api::ItemVisitorRefMut visitor, [[maybe_unused]] uint32_t dyn_index) -> uint64_t {
        [[maybe_unused]] auto self = reinterpret_cast<const Component_rectangle_157*>(base);
        std::abort();
    };
    auto self_rc = reinterpret_cast<const Component_rectangle_157*>(component.instance)->self_weak.lock()->into_dyn();
    return slint::cbindgen_private::slint_visit_item_tree(&self_rc, get_item_tree(component) , index, order, visitor, dyn_visit);
}

auto Component_rectangle_157::get_item_ref (slint::private_api::ItemTreeRef component, uint32_t index) -> slint::private_api::ItemRef{
    return slint::private_api::get_item_ref(component, get_item_tree(component), item_array(), index);
}

auto Component_rectangle_157::get_subtree_range ([[maybe_unused]] slint::private_api::ItemTreeRef component, [[maybe_unused]] uint32_t dyn_index) -> slint::private_api::IndexRange{
        std::abort();
}

auto Component_rectangle_157::get_subtree ([[maybe_unused]] slint::private_api::ItemTreeRef component, [[maybe_unused]] uint32_t dyn_index, [[maybe_unused]] uintptr_t subtree_index, [[maybe_unused]] slint::private_api::ItemTreeWeak *result) -> void{
        std::abort();
}

auto Component_rectangle_157::get_item_tree (slint::private_api::ItemTreeRef) -> slint::cbindgen_private::Slice<slint::private_api::ItemTreeNode>{
    return item_tree();
}

auto Component_rectangle_157::parent_node ([[maybe_unused]] slint::private_api::ItemTreeRef component, [[maybe_unused]] slint::private_api::ItemWeak *result) -> void{
    auto self = reinterpret_cast<const Component_rectangle_157*>(component.instance);
    auto parent = self->parent.lock().value();
    *result = { parent->self_weak, parent->tree_index_of_first_child + 3 };
}

auto Component_rectangle_157::embed_component ([[maybe_unused]] slint::private_api::ItemTreeRef component, [[maybe_unused]] const slint::private_api::ItemTreeWeak *parent_component, [[maybe_unused]] const uint32_t parent_index) -> bool{
    return false; /* todo! */
}

auto Component_rectangle_157::subtree_index ([[maybe_unused]] slint::private_api::ItemTreeRef component) -> uintptr_t{
    return std::numeric_limits<uintptr_t>::max();
}

auto Component_rectangle_157::item_tree () -> slint::cbindgen_private::Slice<slint::private_api::ItemTreeNode>{
    static const slint::private_api::ItemTreeNode children[] {
        slint::private_api::make_item_node(2, 1, 0, 0, false), 
slint::private_api::make_item_node(0, 3, 0, 1, false), 
slint::private_api::make_item_node(1, 3, 0, 2, false), 
slint::private_api::make_item_node(3, 4, 2, 3, false), 
slint::private_api::make_item_node(2, 7, 3, 4, false), 
slint::private_api::make_item_node(0, 11, 3, 5, true), 
slint::private_api::make_item_node(5, 11, 3, 6, false), 
slint::private_api::make_item_node(0, 9, 4, 7, true), 
slint::private_api::make_item_node(2, 9, 4, 8, false), 
slint::private_api::make_item_node(0, 11, 8, 9, false), 
slint::private_api::make_item_node(0, 11, 8, 10, true), 
slint::private_api::make_item_node(3, 16, 6, 11, false), 
slint::private_api::make_item_node(3, 19, 6, 12, false), 
slint::private_api::make_item_node(3, 22, 6, 13, false), 
slint::private_api::make_item_node(3, 25, 6, 14, false), 
slint::private_api::make_item_node(3, 28, 6, 15, false), 
slint::private_api::make_item_node(0, 19, 11, 16, false), 
slint::private_api::make_item_node(0, 19, 11, 17, true), 
slint::private_api::make_item_node(0, 19, 11, 18, true), 
slint::private_api::make_item_node(0, 22, 12, 19, false), 
slint::private_api::make_item_node(0, 22, 12, 20, true), 
slint::private_api::make_item_node(0, 22, 12, 21, true), 
slint::private_api::make_item_node(0, 25, 13, 22, false), 
slint::private_api::make_item_node(0, 25, 13, 23, true), 
slint::private_api::make_item_node(0, 25, 13, 24, true), 
slint::private_api::make_item_node(0, 28, 14, 25, false), 
slint::private_api::make_item_node(0, 28, 14, 26, true), 
slint::private_api::make_item_node(0, 28, 14, 27, true), 
slint::private_api::make_item_node(0, 31, 15, 28, false), 
slint::private_api::make_item_node(0, 31, 15, 29, true), 
slint::private_api::make_item_node(0, 31, 15, 30, true) };
    return slint::private_api::make_slice(std::span(children));
}

auto Component_rectangle_157::item_array () -> const slint::private_api::ItemArray{
    static const slint::private_api::ItemArrayEntry items[] {
        { SLINT_GET_ITEM_VTABLE(RectangleVTable),  offsetof(Component_rectangle_157, field_rectangle_157) }, 
{ SLINT_GET_ITEM_VTABLE(TouchAreaVTable),  offsetof(Component_rectangle_157, field_toucharea_158) }, 
{ SLINT_GET_ITEM_VTABLE(EmptyVTable),  offsetof(Component_rectangle_157, field_empty_160) }, 
{ SLINT_GET_ITEM_VTABLE(BasicBorderRectangleVTable),  offsetof(Component_rectangle_157, field_rectangle_161) }, 
{ SLINT_GET_ITEM_VTABLE(EmptyVTable),  offsetof(Component_rectangle_157, field_empty_163) }, 
{ SLINT_GET_ITEM_VTABLE(SimpleTextVTable),  offsetof(Component_rectangle_157, field_text_168) }, 
{ SLINT_GET_ITEM_VTABLE(EmptyVTable),  offsetof(Component_rectangle_157, field_empty_169) }, 
{ SLINT_GET_ITEM_VTABLE(SimpleTextVTable),  offsetof(Component_rectangle_157, field_text_164) }, 
{ SLINT_GET_ITEM_VTABLE(BasicBorderRectangleVTable),  offsetof(Component_rectangle_157, field_rectangle_165) }, 
{ SLINT_GET_ITEM_VTABLE(TouchAreaVTable),  offsetof(Component_rectangle_157, field_close_uninstall_ta_166) }, 
{ SLINT_GET_ITEM_VTABLE(SimpleTextVTable),  offsetof(Component_rectangle_157, field_text_167) }, 
{ SLINT_GET_ITEM_VTABLE(BasicBorderRectangleVTable),  offsetof(Component_rectangle_157, field_rectangle_170) }, 
{ SLINT_GET_ITEM_VTABLE(BasicBorderRectangleVTable),  offsetof(Component_rectangle_157, field_rectangle_175) }, 
{ SLINT_GET_ITEM_VTABLE(BasicBorderRectangleVTable),  offsetof(Component_rectangle_157, field_rectangle_180) }, 
{ SLINT_GET_ITEM_VTABLE(BasicBorderRectangleVTable),  offsetof(Component_rectangle_157, field_rectangle_185) }, 
{ SLINT_GET_ITEM_VTABLE(BasicBorderRectangleVTable),  offsetof(Component_rectangle_157, field_rectangle_190) }, 
{ SLINT_GET_ITEM_VTABLE(TouchAreaVTable),  offsetof(Component_rectangle_157, field_r_ta_171) }, 
{ SLINT_GET_ITEM_VTABLE(ComplexTextVTable),  offsetof(Component_rectangle_157, field_text_173) }, 
{ SLINT_GET_ITEM_VTABLE(ComplexTextVTable),  offsetof(Component_rectangle_157, field_text_174) }, 
{ SLINT_GET_ITEM_VTABLE(TouchAreaVTable),  offsetof(Component_rectangle_157, field_rn_ta_176) }, 
{ SLINT_GET_ITEM_VTABLE(ComplexTextVTable),  offsetof(Component_rectangle_157, field_text_178) }, 
{ SLINT_GET_ITEM_VTABLE(ComplexTextVTable),  offsetof(Component_rectangle_157, field_text_179) }, 
{ SLINT_GET_ITEM_VTABLE(TouchAreaVTable),  offsetof(Component_rectangle_157, field_rs_ta_181) }, 
{ SLINT_GET_ITEM_VTABLE(ComplexTextVTable),  offsetof(Component_rectangle_157, field_text_183) }, 
{ SLINT_GET_ITEM_VTABLE(ComplexTextVTable),  offsetof(Component_rectangle_157, field_text_184) }, 
{ SLINT_GET_ITEM_VTABLE(TouchAreaVTable),  offsetof(Component_rectangle_157, field_rdd_ta_186) }, 
{ SLINT_GET_ITEM_VTABLE(ComplexTextVTable),  offsetof(Component_rectangle_157, field_text_188) }, 
{ SLINT_GET_ITEM_VTABLE(ComplexTextVTable),  offsetof(Component_rectangle_157, field_text_189) }, 
{ SLINT_GET_ITEM_VTABLE(TouchAreaVTable),  offsetof(Component_rectangle_157, field_rns_ta_191) }, 
{ SLINT_GET_ITEM_VTABLE(ComplexTextVTable),  offsetof(Component_rectangle_157, field_text_193) }, 
{ SLINT_GET_ITEM_VTABLE(ComplexTextVTable),  offsetof(Component_rectangle_157, field_text_194) } };
    return slint::private_api::make_slice(std::span(items));
}

auto Component_rectangle_157::layout_info ([[maybe_unused]] slint::private_api::ItemTreeRef component, slint::cbindgen_private::Orientation o) -> slint::cbindgen_private::LayoutInfo{
    return reinterpret_cast<const Component_rectangle_157*>(component.instance)->layout_info(o);
}

auto Component_rectangle_157::ensure_instantiated ([[maybe_unused]] slint::private_api::ItemTreeRef component) -> bool{
    return reinterpret_cast<const Component_rectangle_157*>(component.instance)->ensure_instantiated();
}

auto Component_rectangle_157::item_geometry ([[maybe_unused]] slint::private_api::ItemTreeRef component, uint32_t index) -> slint::cbindgen_private::LogicalRect{
    return reinterpret_cast<const Component_rectangle_157*>(component.instance)->item_geometry(index);
}

auto Component_rectangle_157::accessible_role ([[maybe_unused]] slint::private_api::ItemTreeRef component, uint32_t index) -> slint::cbindgen_private::AccessibleRole{
    return reinterpret_cast<const Component_rectangle_157*>(component.instance)->accessible_role(index);
}

auto Component_rectangle_157::accessible_string_property ([[maybe_unused]] slint::private_api::ItemTreeRef component, uint32_t index, slint::cbindgen_private::AccessibleStringProperty what, slint::SharedString *result) -> bool{
    if (auto r = reinterpret_cast<const Component_rectangle_157*>(component.instance)->accessible_string_property(index, what)) { *result = *r; return true; } else { return false; }
}

auto Component_rectangle_157::accessibility_action ([[maybe_unused]] slint::private_api::ItemTreeRef component, uint32_t index, const slint::cbindgen_private::AccessibilityAction *action) -> void{
    reinterpret_cast<const Component_rectangle_157*>(component.instance)->accessibility_action(index, *action);
}

auto Component_rectangle_157::supported_accessibility_actions ([[maybe_unused]] slint::private_api::ItemTreeRef component, uint32_t index) -> uint32_t{
    return reinterpret_cast<const Component_rectangle_157*>(component.instance)->supported_accessibility_actions(index);
}

auto Component_rectangle_157::element_infos ([[maybe_unused]] slint::private_api::ItemTreeRef component, [[maybe_unused]] uint32_t index, [[maybe_unused]] slint::SharedString *result) -> bool{
    return false;
}

auto Component_rectangle_157::window_adapter ([[maybe_unused]] slint::private_api::ItemTreeRef component, [[maybe_unused]] bool do_create, [[maybe_unused]] slint::cbindgen_private::Option<slint::private_api::WindowAdapterRc>* result) -> void{
    *reinterpret_cast<slint::private_api::WindowAdapterRc*>(result) = reinterpret_cast<const Component_rectangle_157*>(component.instance)->globals->window().window_handle();
}

auto Component_rectangle_157::create (class DetailsView_root_32 const * parent) -> slint::ComponentHandle<Component_rectangle_157>{
    auto self_rc = vtable::VRc<slint::private_api::ItemTreeVTable, Component_rectangle_157>::make();
    auto self = const_cast<Component_rectangle_157 *>(&*self_rc);
    self->self_weak = vtable::VWeak(self_rc).into_dyn();
    slint::private_api::register_item_tree(&self_rc.into_dyn(), parent->globals->m_window);
    self->init(parent->globals, self->self_weak, 0, 1 , parent);
    return slint::ComponentHandle<Component_rectangle_157>{ self_rc };
}

Component_rectangle_157::~Component_rectangle_157 (){
    if (auto &window = globals->m_window) window->window_handle().unregister_item_tree(this, item_array());
}

auto Component_rectangle_157::init () -> void{
    user_init();
}

auto Component_rectangle_157::layout_item_info (slint::cbindgen_private::Orientation o, [[maybe_unused]] std::optional<size_t> child_index) const -> slint::cbindgen_private::LayoutItemInfo{
    return { layout_info({&static_vtable, const_cast<void *>(static_cast<const void *>(this))}, o) };
}

auto Component_rectangle_157::flexbox_layout_item_info (slint::cbindgen_private::Orientation o, [[maybe_unused]] std::optional<size_t> child_index) const -> slint::cbindgen_private::FlexboxLayoutItemInfo{
    auto base = layout_item_info(o, child_index); return { base.constraint, 0.0f, 0.0f, -1.0f, slint::cbindgen_private::FlexboxLayoutAlignSelf::Auto, 0 };
}

auto DetailsView_root_32::fn_empty_33_layoutinfo_v_with_constraint ([[maybe_unused]] float arg_0) const -> slint::cbindgen_private::LayoutInfo{
    [[maybe_unused]] auto self = this;
    return slint::private_api::box_layout_info(slint::private_api::make_slice<slint::cbindgen_private::LayoutItemInfo>(std::array<slint::cbindgen_private::LayoutItemInfo, 2>{ slint::cbindgen_private::LayoutItemInfo ( [&](const auto &a_0){ slint::cbindgen_private::LayoutItemInfo o{}; o.constraint = a_0; return o; }([&]{ [[maybe_unused]] auto layout_info = self->field_root_32_rectangle_34_layoutinfo_v.get();;return [&](const auto &a_0, const auto &a_1, const auto &a_2, const auto &a_3, const auto &a_4, const auto &a_5){ slint::cbindgen_private::LayoutInfo o{}; o.max = a_0; o.max_percent = a_1; o.min = a_2; o.min_percent = a_3; o.preferred = a_4; o.stretch = a_5; return o; }(self->field_root_32_rectangle_34_height.get(), layout_info.max_percent, self->field_root_32_rectangle_34_height.get(), layout_info.min_percent, layout_info.preferred, layout_info.stretch); }()) ), slint::cbindgen_private::LayoutItemInfo ( [&](const auto &a_0){ slint::cbindgen_private::LayoutItemInfo o{}; o.constraint = a_0; return o; }([&]{ [[maybe_unused]] auto layout_info = slint::private_api::item_layout_info(SLINT_GET_ITEM_VTABLE(FlickableVTable), const_cast<slint::cbindgen_private::Flickable*>(&self->field_flickable_45), slint::cbindgen_private::Orientation::Vertical, arg_0, &self->globals->window().window_handle(), self->self_weak.lock()->into_dyn(), self->tree_index_of_first_child + 2 - 1);;return [&](const auto &a_0, const auto &a_1, const auto &a_2, const auto &a_3, const auto &a_4, const auto &a_5){ slint::cbindgen_private::LayoutInfo o{}; o.max = a_0; o.max_percent = a_1; o.min = a_2; o.min_percent = a_3; o.preferred = a_4; o.stretch = a_5; return o; }(self->field_root_32_flickable_45_max_height.get(), layout_info.max_percent, layout_info.min, layout_info.min_percent, self->field_root_32_flickable_45_preferred_height.get(), layout_info.stretch); }()) ) }.data(), 2),0,[&](const auto &a_0, const auto &a_1){ slint::cbindgen_private::Padding o{}; o.begin = a_0; o.end = a_1; return o; }(0, 0),slint::cbindgen_private::LayoutAlignment::Stretch);
}

auto DetailsView_root_32::fn_empty_47_layoutinfo_v_with_constraint ([[maybe_unused]] float arg_0) const -> slint::cbindgen_private::LayoutInfo{
    [[maybe_unused]] auto self = this;
    return [&]{   std::vector<slint::cbindgen_private::LayoutItemInfo> cells_vector;cells_vector.push_back({ [&](const auto &a_0){ slint::cbindgen_private::LayoutItemInfo o{}; o.constraint = a_0; return o; }(self->fn_empty_48_layoutinfo_v_with_constraint(arg_0)) });self->repeater_2.track_instance_changes();{
                                    auto start_offset = cells_vector.size();
                                    self->repeater_2.for_each([&](const auto &sub_comp){ cells_vector.push_back(sub_comp->layout_item_info(slint::cbindgen_private::Orientation::Vertical, std::nullopt)); });
                                    cells_vector.resize(start_offset + self->repeater_2.len());
                                }cells_vector.push_back({ [&](const auto &a_0){ slint::cbindgen_private::LayoutItemInfo o{}; o.constraint = a_0; return o; }(self->field_root_32_rectangle_81_layoutinfo_v.get()) });self->repeater_6.track_instance_changes();{
                                    auto start_offset = cells_vector.size();
                                    self->repeater_6.for_each([&](const auto &sub_comp){ cells_vector.push_back(sub_comp->layout_item_info(slint::cbindgen_private::Orientation::Vertical, std::nullopt)); });
                                    cells_vector.resize(start_offset + self->repeater_6.len());
                                }self->repeater_7.track_instance_changes();{
                                    auto start_offset = cells_vector.size();
                                    self->repeater_7.for_each([&](const auto &sub_comp){ cells_vector.push_back(sub_comp->layout_item_info(slint::cbindgen_private::Orientation::Vertical, std::nullopt)); });
                                    cells_vector.resize(start_offset + self->repeater_7.len());
                                }self->repeater_8.track_instance_changes();{
                                    auto start_offset = cells_vector.size();
                                    self->repeater_8.for_each([&](const auto &sub_comp){ cells_vector.push_back(sub_comp->layout_item_info(slint::cbindgen_private::Orientation::Vertical, std::nullopt)); });
                                    cells_vector.resize(start_offset + self->repeater_8.len());
                                } slint::cbindgen_private::Slice<slint::cbindgen_private::LayoutItemInfo>cells = slint::private_api::make_slice(std::span(cells_vector)); return slint::private_api::box_layout_info(cells,self->field_root_32_empty_47_spacing.get(),[&](const auto &a_0, const auto &a_1){ slint::cbindgen_private::Padding o{}; o.begin = a_0; o.end = a_1; return o; }(self->field_root_32_empty_47_padding_top.get(), self->field_root_32_empty_47_padding_bottom.get()),self->field_root_32_empty_47_alignment.get()); }();
}

auto DetailsView_root_32::fn_empty_48_layoutinfo_v_with_constraint ([[maybe_unused]] float arg_0) const -> slint::cbindgen_private::LayoutInfo{
    [[maybe_unused]] auto self = this;
    return [&]{   std::vector<slint::cbindgen_private::LayoutItemInfo> cells_vector;self->repeater_0.track_instance_changes();{
                                    auto start_offset = cells_vector.size();
                                    self->repeater_0.for_each([&](const auto &sub_comp){ cells_vector.push_back(sub_comp->layout_item_info(slint::cbindgen_private::Orientation::Vertical, std::nullopt)); });
                                    cells_vector.resize(start_offset + self->repeater_0.len());
                                }self->repeater_1.track_instance_changes();{
                                    auto start_offset = cells_vector.size();
                                    self->repeater_1.for_each([&](const auto &sub_comp){ cells_vector.push_back(sub_comp->layout_item_info(slint::cbindgen_private::Orientation::Vertical, std::nullopt)); });
                                    cells_vector.resize(start_offset + self->repeater_1.len());
                                }cells_vector.push_back({ [&](const auto &a_0){ slint::cbindgen_private::LayoutItemInfo o{}; o.constraint = a_0; return o; }(self->fn_empty_53_layoutinfo_v_with_constraint(arg_0)) });cells_vector.push_back({ [&](const auto &a_0){ slint::cbindgen_private::LayoutItemInfo o{}; o.constraint = a_0; return o; }(slint::private_api::item_layout_info(SLINT_GET_ITEM_VTABLE(EmptyVTable), const_cast<slint::cbindgen_private::Empty*>(&self->field_rectangle_60), slint::cbindgen_private::Orientation::Vertical, arg_0, &self->globals->window().window_handle(), self->self_weak.lock()->into_dyn(), self->tree_index_of_first_child + 24 - 1)) });cells_vector.push_back({ [&](const auto &a_0){ slint::cbindgen_private::LayoutItemInfo o{}; o.constraint = a_0; return o; }(self->field_root_32_empty_61_layoutinfo_v.get()) }); slint::cbindgen_private::Slice<slint::cbindgen_private::LayoutItemInfo>cells = slint::private_api::make_slice(std::span(cells_vector)); return slint::private_api::box_layout_info_ortho(cells,[&](const auto &a_0, const auto &a_1){ slint::cbindgen_private::Padding o{}; o.begin = a_0; o.end = a_1; return o; }(0, 0)); }();
}

auto DetailsView_root_32::fn_empty_53_layoutinfo_v_with_constraint ([[maybe_unused]] float arg_0) const -> slint::cbindgen_private::LayoutInfo{
    [[maybe_unused]] auto self = this;
    return slint::private_api::box_layout_info(slint::private_api::make_slice<slint::cbindgen_private::LayoutItemInfo>(std::array<slint::cbindgen_private::LayoutItemInfo, 3>{ slint::cbindgen_private::LayoutItemInfo ( [&](const auto &a_0){ slint::cbindgen_private::LayoutItemInfo o{}; o.constraint = a_0; return o; }(self->field_root_32_empty_54_layoutinfo_v.get()) ), slint::cbindgen_private::LayoutItemInfo ( [&](const auto &a_0){ slint::cbindgen_private::LayoutItemInfo o{}; o.constraint = a_0; return o; }(slint::private_api::item_layout_info(SLINT_GET_ITEM_VTABLE(ComplexTextVTable), const_cast<slint::cbindgen_private::ComplexText*>(&self->field_text_58), slint::cbindgen_private::Orientation::Vertical, arg_0, &self->globals->window().window_handle(), self->self_weak.lock()->into_dyn(), self->tree_index_of_first_child + 27 - 1)) ), slint::cbindgen_private::LayoutItemInfo ( [&](const auto &a_0){ slint::cbindgen_private::LayoutItemInfo o{}; o.constraint = a_0; return o; }(slint::private_api::item_layout_info(SLINT_GET_ITEM_VTABLE(SimpleTextVTable), const_cast<slint::cbindgen_private::SimpleText*>(&self->field_text_59), slint::cbindgen_private::Orientation::Vertical, arg_0, &self->globals->window().window_handle(), self->self_weak.lock()->into_dyn(), self->tree_index_of_first_child + 28 - 1)) ) }.data(), 3),self->field_root_32_empty_53_spacing.get(),[&](const auto &a_0, const auto &a_1){ slint::cbindgen_private::Padding o{}; o.begin = a_0; o.end = a_1; return o; }(0, 0),self->field_root_32_empty_53_alignment.get());
}

auto DetailsView_root_32::fn_layoutinfo_v_with_constraint ([[maybe_unused]] float arg_0) const -> slint::cbindgen_private::LayoutInfo{
    [[maybe_unused]] auto self = this;
    return ([&](const auto &a_0, const auto &a_1, const auto &a_2, const auto &a_3, const auto &a_4, const auto &a_5){ slint::cbindgen_private::LayoutInfo o{}; o.max = a_0; o.max_percent = a_1; o.min = a_2; o.min_percent = a_3; o.preferred = a_4; o.stretch = a_5; return o; }(+3.4028234663852886e38, 100, 0, 0, 0, 1) + self->fn_empty_33_layoutinfo_v_with_constraint(arg_0));
}

auto DetailsView_root_32::init (const class SharedGlobals* globals,slint::cbindgen_private::ItemTreeWeak enclosing_component,uint32_t tree_index,uint32_t tree_index_of_first_child) -> void{
    auto self = this;
    self->self_weak = enclosing_component;
    self->globals = globals;
    this->tree_index_of_first_child = tree_index_of_first_child;
    self->tree_index = tree_index;
    self->field_root_32_accent.set_binding([this]() {
                            [[maybe_unused]] auto self = this;
                            return [&]{ [[maybe_unused]] auto tmp_Theme_219_accents = self->globals->global_Theme_219->field_accents.get();;return slint::private_api::access_array_index(tmp_Theme_219_accents, ([](float a, float b) { auto r = std::fmod(a, b); return r >= 0 ? r : r + std::abs(b); })(self->field_root_32_accent_idx.get(),slint::private_api::model_length(tmp_Theme_219_accents))); }();
                        });
    self->field_root_32.background.set(slint::Brush(slint::Color::from_argb_encoded(+4.280163886e9)));
    self->field_root_32_empty_33_layout_cache.set_binding([this]() {
                            [[maybe_unused]] auto self = this;
                            return slint::private_api::solve_box_layout([&](const auto &a_0, const auto &a_1, const auto &a_2, const auto &a_3, const auto &a_4){ slint::cbindgen_private::BoxLayoutData o{}; o.alignment = a_0; o.cells = a_1; o.padding = a_2; o.size = a_3; o.spacing = a_4; return o; }(slint::cbindgen_private::LayoutAlignment::Stretch, slint::private_api::make_slice<slint::cbindgen_private::LayoutItemInfo>(std::array<slint::cbindgen_private::LayoutItemInfo, 2>{ slint::cbindgen_private::LayoutItemInfo ( [&](const auto &a_0){ slint::cbindgen_private::LayoutItemInfo o{}; o.constraint = a_0; return o; }([&]{ [[maybe_unused]] auto layout_info = ([&](const auto &a_0, const auto &a_1, const auto &a_2, const auto &a_3, const auto &a_4, const auto &a_5){ slint::cbindgen_private::LayoutInfo o{}; o.max = a_0; o.max_percent = a_1; o.min = a_2; o.min_percent = a_3; o.preferred = a_4; o.stretch = a_5; return o; }(+3.4028234663852886e38, 100, 0, 0, 0, 1) + self->field_root_32_empty_35_layoutinfo_v.get());;return [&](const auto &a_0, const auto &a_1, const auto &a_2, const auto &a_3, const auto &a_4, const auto &a_5){ slint::cbindgen_private::LayoutInfo o{}; o.max = a_0; o.max_percent = a_1; o.min = a_2; o.min_percent = a_3; o.preferred = a_4; o.stretch = a_5; return o; }(64, layout_info.max_percent, 64, layout_info.min_percent, layout_info.preferred, layout_info.stretch); }()) ), slint::cbindgen_private::LayoutItemInfo ( [&](const auto &a_0){ slint::cbindgen_private::LayoutItemInfo o{}; o.constraint = a_0; return o; }([&]{ [[maybe_unused]] auto layout_info = slint::private_api::item_layout_info(SLINT_GET_ITEM_VTABLE(FlickableVTable), const_cast<slint::cbindgen_private::Flickable*>(&self->field_flickable_45), slint::cbindgen_private::Orientation::Vertical, -1, &self->globals->window().window_handle(), self->self_weak.lock()->into_dyn(), self->tree_index_of_first_child + 2 - 1);;return [&](const auto &a_0, const auto &a_1, const auto &a_2, const auto &a_3, const auto &a_4, const auto &a_5){ slint::cbindgen_private::LayoutInfo o{}; o.max = a_0; o.max_percent = a_1; o.min = a_2; o.min_percent = a_3; o.preferred = a_4; o.stretch = a_5; return o; }(self->field_root_32_empty_47_max_height.get(), layout_info.max_percent, layout_info.min, layout_info.min_percent, self->field_root_32_empty_47_preferred_height.get(), layout_info.stretch); }()) ) }.data(), 2), [&](const auto &a_0, const auto &a_1){ slint::cbindgen_private::Padding o{}; o.begin = a_0; o.end = a_1; return o; }(0, 0), self->field_root_32_height.get(), 0),slint::private_api::make_slice<int>(std::array<int, 0>{  }.data(), 0));
                        });
    self->field_root_32_empty_33_layoutinfo_h.set_binding([this]() {
                            [[maybe_unused]] auto self = this;
                            return slint::private_api::box_layout_info_ortho(slint::private_api::make_slice<slint::cbindgen_private::LayoutItemInfo>(std::array<slint::cbindgen_private::LayoutItemInfo, 2>{ slint::cbindgen_private::LayoutItemInfo ( [&](const auto &a_0){ slint::cbindgen_private::LayoutItemInfo o{}; o.constraint = a_0; return o; }(([&](const auto &a_0, const auto &a_1, const auto &a_2, const auto &a_3, const auto &a_4, const auto &a_5){ slint::cbindgen_private::LayoutInfo o{}; o.max = a_0; o.max_percent = a_1; o.min = a_2; o.min_percent = a_3; o.preferred = a_4; o.stretch = a_5; return o; }(+3.4028234663852886e38, 100, 0, 0, 0, 1) + self->field_root_32_empty_35_layoutinfo_h.get())) ), slint::cbindgen_private::LayoutItemInfo ( [&](const auto &a_0){ slint::cbindgen_private::LayoutItemInfo o{}; o.constraint = a_0; return o; }([&]{ [[maybe_unused]] auto layout_info = slint::private_api::item_layout_info(SLINT_GET_ITEM_VTABLE(FlickableVTable), const_cast<slint::cbindgen_private::Flickable*>(&self->field_flickable_45), slint::cbindgen_private::Orientation::Horizontal, -1, &self->globals->window().window_handle(), self->self_weak.lock()->into_dyn(), self->tree_index_of_first_child + 2 - 1);;return [&](const auto &a_0, const auto &a_1, const auto &a_2, const auto &a_3, const auto &a_4, const auto &a_5){ slint::cbindgen_private::LayoutInfo o{}; o.max = a_0; o.max_percent = a_1; o.min = a_2; o.min_percent = a_3; o.preferred = a_4; o.stretch = a_5; return o; }(self->field_root_32_empty_47_max_width.get(), layout_info.max_percent, layout_info.min, layout_info.min_percent, self->field_root_32_empty_47_preferred_width.get(), layout_info.stretch); }()) ) }.data(), 2),[&](const auto &a_0, const auto &a_1){ slint::cbindgen_private::Padding o{}; o.begin = a_0; o.end = a_1; return o; }(0, 0));
                        });
    self->field_root_32_empty_33_layoutinfo_v.set_binding([this]() {
                            [[maybe_unused]] auto self = this;
                            return slint::private_api::box_layout_info(slint::private_api::make_slice<slint::cbindgen_private::LayoutItemInfo>(std::array<slint::cbindgen_private::LayoutItemInfo, 2>{ slint::cbindgen_private::LayoutItemInfo ( [&](const auto &a_0){ slint::cbindgen_private::LayoutItemInfo o{}; o.constraint = a_0; return o; }([&]{ [[maybe_unused]] auto layout_info = ([&](const auto &a_0, const auto &a_1, const auto &a_2, const auto &a_3, const auto &a_4, const auto &a_5){ slint::cbindgen_private::LayoutInfo o{}; o.max = a_0; o.max_percent = a_1; o.min = a_2; o.min_percent = a_3; o.preferred = a_4; o.stretch = a_5; return o; }(+3.4028234663852886e38, 100, 0, 0, 0, 1) + self->field_root_32_empty_35_layoutinfo_v.get());;return [&](const auto &a_0, const auto &a_1, const auto &a_2, const auto &a_3, const auto &a_4, const auto &a_5){ slint::cbindgen_private::LayoutInfo o{}; o.max = a_0; o.max_percent = a_1; o.min = a_2; o.min_percent = a_3; o.preferred = a_4; o.stretch = a_5; return o; }(64, layout_info.max_percent, 64, layout_info.min_percent, layout_info.preferred, layout_info.stretch); }()) ), slint::cbindgen_private::LayoutItemInfo ( [&](const auto &a_0){ slint::cbindgen_private::LayoutItemInfo o{}; o.constraint = a_0; return o; }([&]{ [[maybe_unused]] auto layout_info = slint::private_api::item_layout_info(SLINT_GET_ITEM_VTABLE(FlickableVTable), const_cast<slint::cbindgen_private::Flickable*>(&self->field_flickable_45), slint::cbindgen_private::Orientation::Vertical, -1, &self->globals->window().window_handle(), self->self_weak.lock()->into_dyn(), self->tree_index_of_first_child + 2 - 1);;return [&](const auto &a_0, const auto &a_1, const auto &a_2, const auto &a_3, const auto &a_4, const auto &a_5){ slint::cbindgen_private::LayoutInfo o{}; o.max = a_0; o.max_percent = a_1; o.min = a_2; o.min_percent = a_3; o.preferred = a_4; o.stretch = a_5; return o; }(self->field_root_32_empty_47_max_height.get(), layout_info.max_percent, layout_info.min, layout_info.min_percent, self->field_root_32_empty_47_preferred_height.get(), layout_info.stretch); }()) ) }.data(), 2),0,[&](const auto &a_0, const auto &a_1){ slint::cbindgen_private::Padding o{}; o.begin = a_0; o.end = a_1; return o; }(0, 0),slint::cbindgen_private::LayoutAlignment::Stretch);
                        });
    self->field_root_32_empty_33_width.set_binding([this]() {
                            [[maybe_unused]] auto self = this;
                            return self->field_root_32_width.get();
                        });
    self->field_root_32_empty_35_layout_cache.set_binding([this]() {
                            [[maybe_unused]] auto self = this;
                            return slint::private_api::solve_box_layout([&](const auto &a_0, const auto &a_1, const auto &a_2, const auto &a_3, const auto &a_4){ slint::cbindgen_private::BoxLayoutData o{}; o.alignment = a_0; o.cells = a_1; o.padding = a_2; o.size = a_3; o.spacing = a_4; return o; }(slint::cbindgen_private::LayoutAlignment::SpaceBetween, slint::private_api::make_slice<slint::cbindgen_private::LayoutItemInfo>(std::array<slint::cbindgen_private::LayoutItemInfo, 2>{ slint::cbindgen_private::LayoutItemInfo ( [&](const auto &a_0){ slint::cbindgen_private::LayoutItemInfo o{}; o.constraint = a_0; return o; }(self->field_root_32_empty_36_layoutinfo_h.get()) ), slint::cbindgen_private::LayoutItemInfo ( [&](const auto &a_0){ slint::cbindgen_private::LayoutItemInfo o{}; o.constraint = a_0; return o; }(self->field_root_32_empty_41_layoutinfo_h.get()) ) }.data(), 2), [&](const auto &a_0, const auto &a_1){ slint::cbindgen_private::Padding o{}; o.begin = a_0; o.end = a_1; return o; }(24, 24), self->field_root_32_rectangle_34_width.get(), 0),slint::private_api::make_slice<int>(std::array<int, 0>{  }.data(), 0));
                        });
    self->field_root_32_empty_35_layoutinfo_h.set_binding([this]() {
                            [[maybe_unused]] auto self = this;
                            return slint::private_api::box_layout_info(slint::private_api::make_slice<slint::cbindgen_private::LayoutItemInfo>(std::array<slint::cbindgen_private::LayoutItemInfo, 2>{ slint::cbindgen_private::LayoutItemInfo ( [&](const auto &a_0){ slint::cbindgen_private::LayoutItemInfo o{}; o.constraint = a_0; return o; }(self->field_root_32_empty_36_layoutinfo_h.get()) ), slint::cbindgen_private::LayoutItemInfo ( [&](const auto &a_0){ slint::cbindgen_private::LayoutItemInfo o{}; o.constraint = a_0; return o; }(self->field_root_32_empty_41_layoutinfo_h.get()) ) }.data(), 2),0,[&](const auto &a_0, const auto &a_1){ slint::cbindgen_private::Padding o{}; o.begin = a_0; o.end = a_1; return o; }(24, 24),slint::cbindgen_private::LayoutAlignment::SpaceBetween);
                        });
    self->field_root_32_empty_35_layoutinfo_v.set_binding([this]() {
                            [[maybe_unused]] auto self = this;
                            return slint::private_api::box_layout_info_ortho(slint::private_api::make_slice<slint::cbindgen_private::LayoutItemInfo>(std::array<slint::cbindgen_private::LayoutItemInfo, 2>{ slint::cbindgen_private::LayoutItemInfo ( [&](const auto &a_0){ slint::cbindgen_private::LayoutItemInfo o{}; o.constraint = a_0; return o; }(self->field_root_32_empty_36_layoutinfo_v.get()) ), slint::cbindgen_private::LayoutItemInfo ( [&](const auto &a_0){ slint::cbindgen_private::LayoutItemInfo o{}; o.constraint = a_0; return o; }(self->field_root_32_empty_41_layoutinfo_v.get()) ) }.data(), 2),[&](const auto &a_0, const auto &a_1){ slint::cbindgen_private::Padding o{}; o.begin = a_0; o.end = a_1; return o; }(0, 0));
                        });
    self->field_root_32_empty_36_layout_cache.set_binding([this]() {
                            [[maybe_unused]] auto self = this;
                            return slint::private_api::solve_box_layout([&](const auto &a_0, const auto &a_1, const auto &a_2, const auto &a_3, const auto &a_4){ slint::cbindgen_private::BoxLayoutData o{}; o.alignment = a_0; o.cells = a_1; o.padding = a_2; o.size = a_3; o.spacing = a_4; return o; }(slint::cbindgen_private::LayoutAlignment::Start, slint::private_api::make_slice<slint::cbindgen_private::LayoutItemInfo>(std::array<slint::cbindgen_private::LayoutItemInfo, 2>{ slint::cbindgen_private::LayoutItemInfo ( [&](const auto &a_0){ slint::cbindgen_private::LayoutItemInfo o{}; o.constraint = a_0; return o; }(slint::private_api::item_layout_info(SLINT_GET_ITEM_VTABLE(SimpleTextVTable), const_cast<slint::cbindgen_private::SimpleText*>(&self->field_text_37), slint::cbindgen_private::Orientation::Horizontal, -1, &self->globals->window().window_handle(), self->self_weak.lock()->into_dyn(), self->tree_index_of_first_child + 7 - 1)) ), slint::cbindgen_private::LayoutItemInfo ( [&](const auto &a_0){ slint::cbindgen_private::LayoutItemInfo o{}; o.constraint = a_0; return o; }(self->field_root_32_empty_38_layoutinfo_h.get()) ) }.data(), 2), [&](const auto &a_0, const auto &a_1){ slint::cbindgen_private::Padding o{}; o.begin = a_0; o.end = a_1; return o; }(0, 0), self->field_root_32_empty_35_layout_cache.get()[1], 10),slint::private_api::make_slice<int>(std::array<int, 0>{  }.data(), 0));
                        });
    self->field_root_32_empty_36_layoutinfo_h.set_binding([this]() {
                            [[maybe_unused]] auto self = this;
                            return slint::private_api::box_layout_info(slint::private_api::make_slice<slint::cbindgen_private::LayoutItemInfo>(std::array<slint::cbindgen_private::LayoutItemInfo, 2>{ slint::cbindgen_private::LayoutItemInfo ( [&](const auto &a_0){ slint::cbindgen_private::LayoutItemInfo o{}; o.constraint = a_0; return o; }(slint::private_api::item_layout_info(SLINT_GET_ITEM_VTABLE(SimpleTextVTable), const_cast<slint::cbindgen_private::SimpleText*>(&self->field_text_37), slint::cbindgen_private::Orientation::Horizontal, -1, &self->globals->window().window_handle(), self->self_weak.lock()->into_dyn(), self->tree_index_of_first_child + 7 - 1)) ), slint::cbindgen_private::LayoutItemInfo ( [&](const auto &a_0){ slint::cbindgen_private::LayoutItemInfo o{}; o.constraint = a_0; return o; }(self->field_root_32_empty_38_layoutinfo_h.get()) ) }.data(), 2),10,[&](const auto &a_0, const auto &a_1){ slint::cbindgen_private::Padding o{}; o.begin = a_0; o.end = a_1; return o; }(0, 0),slint::cbindgen_private::LayoutAlignment::Start);
                        });
    self->field_root_32_empty_36_layoutinfo_v.set_binding([this]() {
                            [[maybe_unused]] auto self = this;
                            return slint::private_api::box_layout_info_ortho(slint::private_api::make_slice<slint::cbindgen_private::LayoutItemInfo>(std::array<slint::cbindgen_private::LayoutItemInfo, 2>{ slint::cbindgen_private::LayoutItemInfo ( [&](const auto &a_0){ slint::cbindgen_private::LayoutItemInfo o{}; o.constraint = a_0; return o; }(slint::private_api::item_layout_info(SLINT_GET_ITEM_VTABLE(SimpleTextVTable), const_cast<slint::cbindgen_private::SimpleText*>(&self->field_text_37), slint::cbindgen_private::Orientation::Vertical, -1, &self->globals->window().window_handle(), self->self_weak.lock()->into_dyn(), self->tree_index_of_first_child + 7 - 1)) ), slint::cbindgen_private::LayoutItemInfo ( [&](const auto &a_0){ slint::cbindgen_private::LayoutItemInfo o{}; o.constraint = a_0; return o; }(self->field_root_32_empty_38_layoutinfo_v.get()) ) }.data(), 2),[&](const auto &a_0, const auto &a_1){ slint::cbindgen_private::Padding o{}; o.begin = a_0; o.end = a_1; return o; }(0, 0));
                        });
    self->field_root_32_empty_38_layout_cache.set_binding([this]() {
                            [[maybe_unused]] auto self = this;
                            return slint::private_api::solve_box_layout([&](const auto &a_0, const auto &a_1, const auto &a_2, const auto &a_3, const auto &a_4){ slint::cbindgen_private::BoxLayoutData o{}; o.alignment = a_0; o.cells = a_1; o.padding = a_2; o.size = a_3; o.spacing = a_4; return o; }(slint::cbindgen_private::LayoutAlignment::Center, slint::private_api::make_slice<slint::cbindgen_private::LayoutItemInfo>(std::array<slint::cbindgen_private::LayoutItemInfo, 2>{ slint::cbindgen_private::LayoutItemInfo ( [&](const auto &a_0){ slint::cbindgen_private::LayoutItemInfo o{}; o.constraint = a_0; return o; }(slint::private_api::item_layout_info(SLINT_GET_ITEM_VTABLE(SimpleTextVTable), const_cast<slint::cbindgen_private::SimpleText*>(&self->field_text_39), slint::cbindgen_private::Orientation::Vertical, -1, &self->globals->window().window_handle(), self->self_weak.lock()->into_dyn(), self->tree_index_of_first_child + 9 - 1)) ), slint::cbindgen_private::LayoutItemInfo ( [&](const auto &a_0){ slint::cbindgen_private::LayoutItemInfo o{}; o.constraint = a_0; return o; }(slint::private_api::item_layout_info(SLINT_GET_ITEM_VTABLE(SimpleTextVTable), const_cast<slint::cbindgen_private::SimpleText*>(&self->field_text_40), slint::cbindgen_private::Orientation::Vertical, -1, &self->globals->window().window_handle(), self->self_weak.lock()->into_dyn(), self->tree_index_of_first_child + 10 - 1)) ) }.data(), 2), [&](const auto &a_0, const auto &a_1){ slint::cbindgen_private::Padding o{}; o.begin = a_0; o.end = a_1; return o; }(0, 0), 64, 0),slint::private_api::make_slice<int>(std::array<int, 0>{  }.data(), 0));
                        });
    self->field_root_32_empty_38_layoutinfo_h.set_binding([this]() {
                            [[maybe_unused]] auto self = this;
                            return slint::private_api::box_layout_info_ortho(slint::private_api::make_slice<slint::cbindgen_private::LayoutItemInfo>(std::array<slint::cbindgen_private::LayoutItemInfo, 2>{ slint::cbindgen_private::LayoutItemInfo ( [&](const auto &a_0){ slint::cbindgen_private::LayoutItemInfo o{}; o.constraint = a_0; return o; }(slint::private_api::item_layout_info(SLINT_GET_ITEM_VTABLE(SimpleTextVTable), const_cast<slint::cbindgen_private::SimpleText*>(&self->field_text_39), slint::cbindgen_private::Orientation::Horizontal, -1, &self->globals->window().window_handle(), self->self_weak.lock()->into_dyn(), self->tree_index_of_first_child + 9 - 1)) ), slint::cbindgen_private::LayoutItemInfo ( [&](const auto &a_0){ slint::cbindgen_private::LayoutItemInfo o{}; o.constraint = a_0; return o; }(slint::private_api::item_layout_info(SLINT_GET_ITEM_VTABLE(SimpleTextVTable), const_cast<slint::cbindgen_private::SimpleText*>(&self->field_text_40), slint::cbindgen_private::Orientation::Horizontal, -1, &self->globals->window().window_handle(), self->self_weak.lock()->into_dyn(), self->tree_index_of_first_child + 10 - 1)) ) }.data(), 2),[&](const auto &a_0, const auto &a_1){ slint::cbindgen_private::Padding o{}; o.begin = a_0; o.end = a_1; return o; }(0, 0));
                        });
    self->field_root_32_empty_38_layoutinfo_v.set_binding([this]() {
                            [[maybe_unused]] auto self = this;
                            return slint::private_api::box_layout_info(slint::private_api::make_slice<slint::cbindgen_private::LayoutItemInfo>(std::array<slint::cbindgen_private::LayoutItemInfo, 2>{ slint::cbindgen_private::LayoutItemInfo ( [&](const auto &a_0){ slint::cbindgen_private::LayoutItemInfo o{}; o.constraint = a_0; return o; }(slint::private_api::item_layout_info(SLINT_GET_ITEM_VTABLE(SimpleTextVTable), const_cast<slint::cbindgen_private::SimpleText*>(&self->field_text_39), slint::cbindgen_private::Orientation::Vertical, -1, &self->globals->window().window_handle(), self->self_weak.lock()->into_dyn(), self->tree_index_of_first_child + 9 - 1)) ), slint::cbindgen_private::LayoutItemInfo ( [&](const auto &a_0){ slint::cbindgen_private::LayoutItemInfo o{}; o.constraint = a_0; return o; }(slint::private_api::item_layout_info(SLINT_GET_ITEM_VTABLE(SimpleTextVTable), const_cast<slint::cbindgen_private::SimpleText*>(&self->field_text_40), slint::cbindgen_private::Orientation::Vertical, -1, &self->globals->window().window_handle(), self->self_weak.lock()->into_dyn(), self->tree_index_of_first_child + 10 - 1)) ) }.data(), 2),0,[&](const auto &a_0, const auto &a_1){ slint::cbindgen_private::Padding o{}; o.begin = a_0; o.end = a_1; return o; }(0, 0),slint::cbindgen_private::LayoutAlignment::Center);
                        });
    self->field_root_32_empty_41_layout_cache.set_binding([this]() {
                            [[maybe_unused]] auto self = this;
                            return slint::private_api::solve_box_layout([&](const auto &a_0, const auto &a_1, const auto &a_2, const auto &a_3, const auto &a_4){ slint::cbindgen_private::BoxLayoutData o{}; o.alignment = a_0; o.cells = a_1; o.padding = a_2; o.size = a_3; o.spacing = a_4; return o; }(slint::cbindgen_private::LayoutAlignment::Stretch, slint::private_api::make_slice<slint::cbindgen_private::LayoutItemInfo>(std::array<slint::cbindgen_private::LayoutItemInfo, 1>{ slint::cbindgen_private::LayoutItemInfo ( [&](const auto &a_0){ slint::cbindgen_private::LayoutItemInfo o{}; o.constraint = a_0; return o; }([&]{ [[maybe_unused]] auto layout_info = self->field_root_32_rectangle_42_layoutinfo_h.get();;return [&](const auto &a_0, const auto &a_1, const auto &a_2, const auto &a_3, const auto &a_4, const auto &a_5){ slint::cbindgen_private::LayoutInfo o{}; o.max = a_0; o.max_percent = a_1; o.min = a_2; o.min_percent = a_3; o.preferred = a_4; o.stretch = a_5; return o; }(90, layout_info.max_percent, 90, layout_info.min_percent, layout_info.preferred, layout_info.stretch); }()) ) }.data(), 1), [&](const auto &a_0, const auto &a_1){ slint::cbindgen_private::Padding o{}; o.begin = a_0; o.end = a_1; return o; }(0, 0), self->field_root_32_empty_35_layout_cache.get()[3], 12),slint::private_api::make_slice<int>(std::array<int, 0>{  }.data(), 0));
                        });
    self->field_root_32_empty_41_layoutinfo_h.set_binding([this]() {
                            [[maybe_unused]] auto self = this;
                            return slint::private_api::box_layout_info(slint::private_api::make_slice<slint::cbindgen_private::LayoutItemInfo>(std::array<slint::cbindgen_private::LayoutItemInfo, 1>{ slint::cbindgen_private::LayoutItemInfo ( [&](const auto &a_0){ slint::cbindgen_private::LayoutItemInfo o{}; o.constraint = a_0; return o; }([&]{ [[maybe_unused]] auto layout_info = self->field_root_32_rectangle_42_layoutinfo_h.get();;return [&](const auto &a_0, const auto &a_1, const auto &a_2, const auto &a_3, const auto &a_4, const auto &a_5){ slint::cbindgen_private::LayoutInfo o{}; o.max = a_0; o.max_percent = a_1; o.min = a_2; o.min_percent = a_3; o.preferred = a_4; o.stretch = a_5; return o; }(90, layout_info.max_percent, 90, layout_info.min_percent, layout_info.preferred, layout_info.stretch); }()) ) }.data(), 1),12,[&](const auto &a_0, const auto &a_1){ slint::cbindgen_private::Padding o{}; o.begin = a_0; o.end = a_1; return o; }(0, 0),slint::cbindgen_private::LayoutAlignment::Stretch);
                        });
    self->field_root_32_empty_41_layoutinfo_v.set_binding([this]() {
                            [[maybe_unused]] auto self = this;
                            return slint::private_api::box_layout_info_ortho(slint::private_api::make_slice<slint::cbindgen_private::LayoutItemInfo>(std::array<slint::cbindgen_private::LayoutItemInfo, 1>{ slint::cbindgen_private::LayoutItemInfo ( [&](const auto &a_0){ slint::cbindgen_private::LayoutItemInfo o{}; o.constraint = a_0; return o; }([&]{ [[maybe_unused]] auto layout_info = self->field_root_32_rectangle_42_layoutinfo_v.get();;return [&](const auto &a_0, const auto &a_1, const auto &a_2, const auto &a_3, const auto &a_4, const auto &a_5){ slint::cbindgen_private::LayoutInfo o{}; o.max = a_0; o.max_percent = a_1; o.min = a_2; o.min_percent = a_3; o.preferred = a_4; o.stretch = a_5; return o; }(36, layout_info.max_percent, 36, layout_info.min_percent, layout_info.preferred, layout_info.stretch); }()) ) }.data(), 1),[&](const auto &a_0, const auto &a_1){ slint::cbindgen_private::Padding o{}; o.begin = a_0; o.end = a_1; return o; }(0, 0));
                        });
    self->field_root_32_empty_47_alignment.set(slint::cbindgen_private::LayoutAlignment::Start);
    self->field_root_32_empty_47_layout_cache.set_binding([this]() {
                            [[maybe_unused]] auto self = this;
                            return [&]{ std::array<int, 8> repeated_indices_array;  std::vector<slint::cbindgen_private::LayoutItemInfo> cells_vector;cells_vector.push_back({ [&](const auto &a_0){ slint::cbindgen_private::LayoutItemInfo o{}; o.constraint = a_0; return o; }(self->field_root_32_empty_48_layoutinfo_v.get()) });self->repeater_2.track_instance_changes();repeated_indices_array[0] = cells_vector.size();repeated_indices_array[1] = self->repeater_2.len();{
                                    auto start_offset = cells_vector.size();
                                    self->repeater_2.for_each([&](const auto &sub_comp){ cells_vector.push_back(sub_comp->layout_item_info(slint::cbindgen_private::Orientation::Vertical, std::nullopt)); });
                                    cells_vector.resize(start_offset + self->repeater_2.len());
                                }cells_vector.push_back({ [&](const auto &a_0){ slint::cbindgen_private::LayoutItemInfo o{}; o.constraint = a_0; return o; }(([&](const auto &a_0, const auto &a_1, const auto &a_2, const auto &a_3, const auto &a_4, const auto &a_5){ slint::cbindgen_private::LayoutInfo o{}; o.max = a_0; o.max_percent = a_1; o.min = a_2; o.min_percent = a_3; o.preferred = a_4; o.stretch = a_5; return o; }(+3.4028234663852886e38, 100, 0, 0, 0, 1) + self->field_root_32_empty_82_layoutinfo_v.get())) });self->repeater_6.track_instance_changes();repeated_indices_array[2] = cells_vector.size();repeated_indices_array[3] = self->repeater_6.len();{
                                    auto start_offset = cells_vector.size();
                                    self->repeater_6.for_each([&](const auto &sub_comp){ cells_vector.push_back(sub_comp->layout_item_info(slint::cbindgen_private::Orientation::Vertical, std::nullopt)); });
                                    cells_vector.resize(start_offset + self->repeater_6.len());
                                }self->repeater_7.track_instance_changes();repeated_indices_array[4] = cells_vector.size();repeated_indices_array[5] = self->repeater_7.len();{
                                    auto start_offset = cells_vector.size();
                                    self->repeater_7.for_each([&](const auto &sub_comp){ cells_vector.push_back(sub_comp->layout_item_info(slint::cbindgen_private::Orientation::Vertical, std::nullopt)); });
                                    cells_vector.resize(start_offset + self->repeater_7.len());
                                }self->repeater_8.track_instance_changes();repeated_indices_array[6] = cells_vector.size();repeated_indices_array[7] = self->repeater_8.len();{
                                    auto start_offset = cells_vector.size();
                                    self->repeater_8.for_each([&](const auto &sub_comp){ cells_vector.push_back(sub_comp->layout_item_info(slint::cbindgen_private::Orientation::Vertical, std::nullopt)); });
                                    cells_vector.resize(start_offset + self->repeater_8.len());
                                }slint::cbindgen_private::Slice<int> repeated_indices = slint::private_api::make_slice(std::span(repeated_indices_array)); slint::cbindgen_private::Slice<slint::cbindgen_private::LayoutItemInfo>cells = slint::private_api::make_slice(std::span(cells_vector)); return slint::private_api::solve_box_layout([&](const auto &a_0, const auto &a_1, const auto &a_2, const auto &a_3, const auto &a_4){ slint::cbindgen_private::BoxLayoutData o{}; o.alignment = a_0; o.cells = a_1; o.padding = a_2; o.size = a_3; o.spacing = a_4; return o; }(slint::cbindgen_private::LayoutAlignment::Start, cells, [&](const auto &a_0, const auto &a_1){ slint::cbindgen_private::Padding o{}; o.begin = a_0; o.end = a_1; return o; }(40, 64), self->field_flickable_45.viewport_height.get(), 32),repeated_indices); }();
                        });
    self->field_root_32_empty_47_layoutinfo_h.set_binding([this]() {
                            [[maybe_unused]] auto self = this;
                            return [&]{   std::vector<slint::cbindgen_private::LayoutItemInfo> cells_vector;cells_vector.push_back({ [&](const auto &a_0){ slint::cbindgen_private::LayoutItemInfo o{}; o.constraint = a_0; return o; }(self->field_root_32_empty_48_layoutinfo_h.get()) });self->repeater_2.track_instance_changes();{
                                    auto start_offset = cells_vector.size();
                                    self->repeater_2.for_each([&](const auto &sub_comp){ cells_vector.push_back(sub_comp->layout_item_info(slint::cbindgen_private::Orientation::Horizontal, std::nullopt)); });
                                    cells_vector.resize(start_offset + self->repeater_2.len());
                                }cells_vector.push_back({ [&](const auto &a_0){ slint::cbindgen_private::LayoutItemInfo o{}; o.constraint = a_0; return o; }(([&](const auto &a_0, const auto &a_1, const auto &a_2, const auto &a_3, const auto &a_4, const auto &a_5){ slint::cbindgen_private::LayoutInfo o{}; o.max = a_0; o.max_percent = a_1; o.min = a_2; o.min_percent = a_3; o.preferred = a_4; o.stretch = a_5; return o; }(+3.4028234663852886e38, 100, 0, 0, 0, 1) + self->field_root_32_empty_82_layoutinfo_h.get())) });self->repeater_6.track_instance_changes();{
                                    auto start_offset = cells_vector.size();
                                    self->repeater_6.for_each([&](const auto &sub_comp){ cells_vector.push_back(sub_comp->layout_item_info(slint::cbindgen_private::Orientation::Horizontal, std::nullopt)); });
                                    cells_vector.resize(start_offset + self->repeater_6.len());
                                }self->repeater_7.track_instance_changes();{
                                    auto start_offset = cells_vector.size();
                                    self->repeater_7.for_each([&](const auto &sub_comp){ cells_vector.push_back(sub_comp->layout_item_info(slint::cbindgen_private::Orientation::Horizontal, std::nullopt)); });
                                    cells_vector.resize(start_offset + self->repeater_7.len());
                                }self->repeater_8.track_instance_changes();{
                                    auto start_offset = cells_vector.size();
                                    self->repeater_8.for_each([&](const auto &sub_comp){ cells_vector.push_back(sub_comp->layout_item_info(slint::cbindgen_private::Orientation::Horizontal, std::nullopt)); });
                                    cells_vector.resize(start_offset + self->repeater_8.len());
                                } slint::cbindgen_private::Slice<slint::cbindgen_private::LayoutItemInfo>cells = slint::private_api::make_slice(std::span(cells_vector)); return slint::private_api::box_layout_info_ortho(cells,[&](const auto &a_0, const auto &a_1){ slint::cbindgen_private::Padding o{}; o.begin = a_0; o.end = a_1; return o; }(64, 64)); }();
                        });
    self->field_root_32_empty_47_layoutinfo_v.set_binding([this]() {
                            [[maybe_unused]] auto self = this;
                            return [&]{   std::vector<slint::cbindgen_private::LayoutItemInfo> cells_vector;cells_vector.push_back({ [&](const auto &a_0){ slint::cbindgen_private::LayoutItemInfo o{}; o.constraint = a_0; return o; }(self->field_root_32_empty_48_layoutinfo_v.get()) });self->repeater_2.track_instance_changes();{
                                    auto start_offset = cells_vector.size();
                                    self->repeater_2.for_each([&](const auto &sub_comp){ cells_vector.push_back(sub_comp->layout_item_info(slint::cbindgen_private::Orientation::Vertical, std::nullopt)); });
                                    cells_vector.resize(start_offset + self->repeater_2.len());
                                }cells_vector.push_back({ [&](const auto &a_0){ slint::cbindgen_private::LayoutItemInfo o{}; o.constraint = a_0; return o; }(([&](const auto &a_0, const auto &a_1, const auto &a_2, const auto &a_3, const auto &a_4, const auto &a_5){ slint::cbindgen_private::LayoutInfo o{}; o.max = a_0; o.max_percent = a_1; o.min = a_2; o.min_percent = a_3; o.preferred = a_4; o.stretch = a_5; return o; }(+3.4028234663852886e38, 100, 0, 0, 0, 1) + self->field_root_32_empty_82_layoutinfo_v.get())) });self->repeater_6.track_instance_changes();{
                                    auto start_offset = cells_vector.size();
                                    self->repeater_6.for_each([&](const auto &sub_comp){ cells_vector.push_back(sub_comp->layout_item_info(slint::cbindgen_private::Orientation::Vertical, std::nullopt)); });
                                    cells_vector.resize(start_offset + self->repeater_6.len());
                                }self->repeater_7.track_instance_changes();{
                                    auto start_offset = cells_vector.size();
                                    self->repeater_7.for_each([&](const auto &sub_comp){ cells_vector.push_back(sub_comp->layout_item_info(slint::cbindgen_private::Orientation::Vertical, std::nullopt)); });
                                    cells_vector.resize(start_offset + self->repeater_7.len());
                                }self->repeater_8.track_instance_changes();{
                                    auto start_offset = cells_vector.size();
                                    self->repeater_8.for_each([&](const auto &sub_comp){ cells_vector.push_back(sub_comp->layout_item_info(slint::cbindgen_private::Orientation::Vertical, std::nullopt)); });
                                    cells_vector.resize(start_offset + self->repeater_8.len());
                                } slint::cbindgen_private::Slice<slint::cbindgen_private::LayoutItemInfo>cells = slint::private_api::make_slice(std::span(cells_vector)); return slint::private_api::box_layout_info(cells,32,[&](const auto &a_0, const auto &a_1){ slint::cbindgen_private::Padding o{}; o.begin = a_0; o.end = a_1; return o; }(40, 64),slint::cbindgen_private::LayoutAlignment::Start); }();
                        });
    self->field_root_32_empty_47_max_height.set_binding([this]() {
                            [[maybe_unused]] auto self = this;
                            return self->field_root_32_empty_47_layoutinfo_v.get().max;
                        });
    self->field_root_32_empty_47_max_width.set_binding([this]() {
                            [[maybe_unused]] auto self = this;
                            return self->field_root_32_empty_47_layoutinfo_h.get().max;
                        });
    self->field_root_32_empty_47_padding_bottom.set(64);
    self->field_root_32_empty_47_padding_top.set(40);
    self->field_root_32_empty_47_preferred_height.set_binding([this]() {
                            [[maybe_unused]] auto self = this;
                            return self->field_root_32_empty_47_layoutinfo_v.get().preferred;
                        });
    self->field_root_32_empty_47_preferred_width.set_binding([this]() {
                            [[maybe_unused]] auto self = this;
                            return self->field_root_32_empty_47_layoutinfo_h.get().preferred;
                        });
    self->field_root_32_empty_47_spacing.set(32);
    self->field_root_32_empty_48_layout_cache.set_binding([this]() {
                            [[maybe_unused]] auto self = this;
                            return [&]{ std::array<int, 4> repeated_indices_array;  std::vector<slint::cbindgen_private::LayoutItemInfo> cells_vector;self->repeater_0.track_instance_changes();repeated_indices_array[0] = cells_vector.size();repeated_indices_array[1] = self->repeater_0.len();{
                                    auto start_offset = cells_vector.size();
                                    self->repeater_0.for_each([&](const auto &sub_comp){ cells_vector.push_back(sub_comp->layout_item_info(slint::cbindgen_private::Orientation::Horizontal, std::nullopt)); });
                                    cells_vector.resize(start_offset + self->repeater_0.len());
                                }self->repeater_1.track_instance_changes();repeated_indices_array[2] = cells_vector.size();repeated_indices_array[3] = self->repeater_1.len();{
                                    auto start_offset = cells_vector.size();
                                    self->repeater_1.for_each([&](const auto &sub_comp){ cells_vector.push_back(sub_comp->layout_item_info(slint::cbindgen_private::Orientation::Horizontal, std::nullopt)); });
                                    cells_vector.resize(start_offset + self->repeater_1.len());
                                }cells_vector.push_back({ [&](const auto &a_0){ slint::cbindgen_private::LayoutItemInfo o{}; o.constraint = a_0; return o; }(self->field_root_32_empty_53_layoutinfo_h.get()) });cells_vector.push_back({ [&](const auto &a_0){ slint::cbindgen_private::LayoutItemInfo o{}; o.constraint = a_0; return o; }([&]{ [[maybe_unused]] auto layout_info = slint::private_api::item_layout_info(SLINT_GET_ITEM_VTABLE(EmptyVTable), const_cast<slint::cbindgen_private::Empty*>(&self->field_rectangle_60), slint::cbindgen_private::Orientation::Horizontal, -1, &self->globals->window().window_handle(), self->self_weak.lock()->into_dyn(), self->tree_index_of_first_child + 24 - 1);;return [&](const auto &a_0, const auto &a_1, const auto &a_2, const auto &a_3, const auto &a_4, const auto &a_5){ slint::cbindgen_private::LayoutInfo o{}; o.max = a_0; o.max_percent = a_1; o.min = a_2; o.min_percent = a_3; o.preferred = a_4; o.stretch = a_5; return o; }(layout_info.max, layout_info.max_percent, layout_info.min, layout_info.min_percent, layout_info.preferred, 1); }()) });cells_vector.push_back({ [&](const auto &a_0){ slint::cbindgen_private::LayoutItemInfo o{}; o.constraint = a_0; return o; }(self->field_root_32_empty_61_layoutinfo_h.get()) });slint::cbindgen_private::Slice<int> repeated_indices = slint::private_api::make_slice(std::span(repeated_indices_array)); slint::cbindgen_private::Slice<slint::cbindgen_private::LayoutItemInfo>cells = slint::private_api::make_slice(std::span(cells_vector)); return slint::private_api::solve_box_layout([&](const auto &a_0, const auto &a_1, const auto &a_2, const auto &a_3, const auto &a_4){ slint::cbindgen_private::BoxLayoutData o{}; o.alignment = a_0; o.cells = a_1; o.padding = a_2; o.size = a_3; o.spacing = a_4; return o; }(slint::cbindgen_private::LayoutAlignment::Stretch, cells, [&](const auto &a_0, const auto &a_1){ slint::cbindgen_private::Padding o{}; o.begin = a_0; o.end = a_1; return o; }(0, 0), ((self->field_flickable_45.viewport_width.get() -(float) 64) -(float) 64), 26),repeated_indices); }();
                        });
    self->field_root_32_empty_48_layoutinfo_h.set_binding([this]() {
                            [[maybe_unused]] auto self = this;
                            return [&]{   std::vector<slint::cbindgen_private::LayoutItemInfo> cells_vector;self->repeater_0.track_instance_changes();{
                                    auto start_offset = cells_vector.size();
                                    self->repeater_0.for_each([&](const auto &sub_comp){ cells_vector.push_back(sub_comp->layout_item_info(slint::cbindgen_private::Orientation::Horizontal, std::nullopt)); });
                                    cells_vector.resize(start_offset + self->repeater_0.len());
                                }self->repeater_1.track_instance_changes();{
                                    auto start_offset = cells_vector.size();
                                    self->repeater_1.for_each([&](const auto &sub_comp){ cells_vector.push_back(sub_comp->layout_item_info(slint::cbindgen_private::Orientation::Horizontal, std::nullopt)); });
                                    cells_vector.resize(start_offset + self->repeater_1.len());
                                }cells_vector.push_back({ [&](const auto &a_0){ slint::cbindgen_private::LayoutItemInfo o{}; o.constraint = a_0; return o; }(self->field_root_32_empty_53_layoutinfo_h.get()) });cells_vector.push_back({ [&](const auto &a_0){ slint::cbindgen_private::LayoutItemInfo o{}; o.constraint = a_0; return o; }([&]{ [[maybe_unused]] auto layout_info = slint::private_api::item_layout_info(SLINT_GET_ITEM_VTABLE(EmptyVTable), const_cast<slint::cbindgen_private::Empty*>(&self->field_rectangle_60), slint::cbindgen_private::Orientation::Horizontal, -1, &self->globals->window().window_handle(), self->self_weak.lock()->into_dyn(), self->tree_index_of_first_child + 24 - 1);;return [&](const auto &a_0, const auto &a_1, const auto &a_2, const auto &a_3, const auto &a_4, const auto &a_5){ slint::cbindgen_private::LayoutInfo o{}; o.max = a_0; o.max_percent = a_1; o.min = a_2; o.min_percent = a_3; o.preferred = a_4; o.stretch = a_5; return o; }(layout_info.max, layout_info.max_percent, layout_info.min, layout_info.min_percent, layout_info.preferred, 1); }()) });cells_vector.push_back({ [&](const auto &a_0){ slint::cbindgen_private::LayoutItemInfo o{}; o.constraint = a_0; return o; }(self->field_root_32_empty_61_layoutinfo_h.get()) }); slint::cbindgen_private::Slice<slint::cbindgen_private::LayoutItemInfo>cells = slint::private_api::make_slice(std::span(cells_vector)); return slint::private_api::box_layout_info(cells,26,[&](const auto &a_0, const auto &a_1){ slint::cbindgen_private::Padding o{}; o.begin = a_0; o.end = a_1; return o; }(0, 0),slint::cbindgen_private::LayoutAlignment::Stretch); }();
                        });
    self->field_root_32_empty_48_layoutinfo_v.set_binding([this]() {
                            [[maybe_unused]] auto self = this;
                            return [&]{   std::vector<slint::cbindgen_private::LayoutItemInfo> cells_vector;self->repeater_0.track_instance_changes();{
                                    auto start_offset = cells_vector.size();
                                    self->repeater_0.for_each([&](const auto &sub_comp){ cells_vector.push_back(sub_comp->layout_item_info(slint::cbindgen_private::Orientation::Vertical, std::nullopt)); });
                                    cells_vector.resize(start_offset + self->repeater_0.len());
                                }self->repeater_1.track_instance_changes();{
                                    auto start_offset = cells_vector.size();
                                    self->repeater_1.for_each([&](const auto &sub_comp){ cells_vector.push_back(sub_comp->layout_item_info(slint::cbindgen_private::Orientation::Vertical, std::nullopt)); });
                                    cells_vector.resize(start_offset + self->repeater_1.len());
                                }cells_vector.push_back({ [&](const auto &a_0){ slint::cbindgen_private::LayoutItemInfo o{}; o.constraint = a_0; return o; }(self->field_root_32_empty_53_layoutinfo_v.get()) });cells_vector.push_back({ [&](const auto &a_0){ slint::cbindgen_private::LayoutItemInfo o{}; o.constraint = a_0; return o; }(slint::private_api::item_layout_info(SLINT_GET_ITEM_VTABLE(EmptyVTable), const_cast<slint::cbindgen_private::Empty*>(&self->field_rectangle_60), slint::cbindgen_private::Orientation::Vertical, -1, &self->globals->window().window_handle(), self->self_weak.lock()->into_dyn(), self->tree_index_of_first_child + 24 - 1)) });cells_vector.push_back({ [&](const auto &a_0){ slint::cbindgen_private::LayoutItemInfo o{}; o.constraint = a_0; return o; }(self->field_root_32_empty_61_layoutinfo_v.get()) }); slint::cbindgen_private::Slice<slint::cbindgen_private::LayoutItemInfo>cells = slint::private_api::make_slice(std::span(cells_vector)); return slint::private_api::box_layout_info_ortho(cells,[&](const auto &a_0, const auto &a_1){ slint::cbindgen_private::Padding o{}; o.begin = a_0; o.end = a_1; return o; }(0, 0)); }();
                        });
    self->field_root_32_empty_53_alignment.set(slint::cbindgen_private::LayoutAlignment::Center);
    self->field_root_32_empty_53_layout_cache.set_binding([this]() {
                            [[maybe_unused]] auto self = this;
                            return slint::private_api::solve_box_layout([&](const auto &a_0, const auto &a_1, const auto &a_2, const auto &a_3, const auto &a_4){ slint::cbindgen_private::BoxLayoutData o{}; o.alignment = a_0; o.cells = a_1; o.padding = a_2; o.size = a_3; o.spacing = a_4; return o; }(slint::cbindgen_private::LayoutAlignment::Center, slint::private_api::make_slice<slint::cbindgen_private::LayoutItemInfo>(std::array<slint::cbindgen_private::LayoutItemInfo, 3>{ slint::cbindgen_private::LayoutItemInfo ( [&](const auto &a_0){ slint::cbindgen_private::LayoutItemInfo o{}; o.constraint = a_0; return o; }(self->field_root_32_empty_54_layoutinfo_v.get()) ), slint::cbindgen_private::LayoutItemInfo ( [&](const auto &a_0){ slint::cbindgen_private::LayoutItemInfo o{}; o.constraint = a_0; return o; }(slint::private_api::item_layout_info(SLINT_GET_ITEM_VTABLE(ComplexTextVTable), const_cast<slint::cbindgen_private::ComplexText*>(&self->field_text_58), slint::cbindgen_private::Orientation::Vertical, -1, &self->globals->window().window_handle(), self->self_weak.lock()->into_dyn(), self->tree_index_of_first_child + 27 - 1)) ), slint::cbindgen_private::LayoutItemInfo ( [&](const auto &a_0){ slint::cbindgen_private::LayoutItemInfo o{}; o.constraint = a_0; return o; }(slint::private_api::item_layout_info(SLINT_GET_ITEM_VTABLE(SimpleTextVTable), const_cast<slint::cbindgen_private::SimpleText*>(&self->field_text_59), slint::cbindgen_private::Orientation::Vertical, -1, &self->globals->window().window_handle(), self->self_weak.lock()->into_dyn(), self->tree_index_of_first_child + 28 - 1)) ) }.data(), 3), [&](const auto &a_0, const auto &a_1){ slint::cbindgen_private::Padding o{}; o.begin = a_0; o.end = a_1; return o; }(0, 0), self->field_root_32_empty_47_layout_cache.get()[1], 8),slint::private_api::make_slice<int>(std::array<int, 0>{  }.data(), 0));
                        });
    self->field_root_32_empty_53_layoutinfo_h.set_binding([this]() {
                            [[maybe_unused]] auto self = this;
                            return slint::private_api::box_layout_info_ortho(slint::private_api::make_slice<slint::cbindgen_private::LayoutItemInfo>(std::array<slint::cbindgen_private::LayoutItemInfo, 3>{ slint::cbindgen_private::LayoutItemInfo ( [&](const auto &a_0){ slint::cbindgen_private::LayoutItemInfo o{}; o.constraint = a_0; return o; }(self->field_root_32_empty_54_layoutinfo_h.get()) ), slint::cbindgen_private::LayoutItemInfo ( [&](const auto &a_0){ slint::cbindgen_private::LayoutItemInfo o{}; o.constraint = a_0; return o; }([&]{ [[maybe_unused]] auto layout_info = slint::private_api::item_layout_info(SLINT_GET_ITEM_VTABLE(ComplexTextVTable), const_cast<slint::cbindgen_private::ComplexText*>(&self->field_text_58), slint::cbindgen_private::Orientation::Horizontal, -1, &self->globals->window().window_handle(), self->self_weak.lock()->into_dyn(), self->tree_index_of_first_child + 27 - 1);;return [&](const auto &a_0, const auto &a_1, const auto &a_2, const auto &a_3, const auto &a_4, const auto &a_5){ slint::cbindgen_private::LayoutInfo o{}; o.max = a_0; o.max_percent = a_1; o.min = a_2; o.min_percent = a_3; o.preferred = a_4; o.stretch = a_5; return o; }(560, layout_info.max_percent, layout_info.min, layout_info.min_percent, layout_info.preferred, layout_info.stretch); }()) ), slint::cbindgen_private::LayoutItemInfo ( [&](const auto &a_0){ slint::cbindgen_private::LayoutItemInfo o{}; o.constraint = a_0; return o; }(slint::private_api::item_layout_info(SLINT_GET_ITEM_VTABLE(SimpleTextVTable), const_cast<slint::cbindgen_private::SimpleText*>(&self->field_text_59), slint::cbindgen_private::Orientation::Horizontal, -1, &self->globals->window().window_handle(), self->self_weak.lock()->into_dyn(), self->tree_index_of_first_child + 28 - 1)) ) }.data(), 3),[&](const auto &a_0, const auto &a_1){ slint::cbindgen_private::Padding o{}; o.begin = a_0; o.end = a_1; return o; }(0, 0));
                        });
    self->field_root_32_empty_53_layoutinfo_v.set_binding([this]() {
                            [[maybe_unused]] auto self = this;
                            return slint::private_api::box_layout_info(slint::private_api::make_slice<slint::cbindgen_private::LayoutItemInfo>(std::array<slint::cbindgen_private::LayoutItemInfo, 3>{ slint::cbindgen_private::LayoutItemInfo ( [&](const auto &a_0){ slint::cbindgen_private::LayoutItemInfo o{}; o.constraint = a_0; return o; }(self->field_root_32_empty_54_layoutinfo_v.get()) ), slint::cbindgen_private::LayoutItemInfo ( [&](const auto &a_0){ slint::cbindgen_private::LayoutItemInfo o{}; o.constraint = a_0; return o; }(slint::private_api::item_layout_info(SLINT_GET_ITEM_VTABLE(ComplexTextVTable), const_cast<slint::cbindgen_private::ComplexText*>(&self->field_text_58), slint::cbindgen_private::Orientation::Vertical, -1, &self->globals->window().window_handle(), self->self_weak.lock()->into_dyn(), self->tree_index_of_first_child + 27 - 1)) ), slint::cbindgen_private::LayoutItemInfo ( [&](const auto &a_0){ slint::cbindgen_private::LayoutItemInfo o{}; o.constraint = a_0; return o; }(slint::private_api::item_layout_info(SLINT_GET_ITEM_VTABLE(SimpleTextVTable), const_cast<slint::cbindgen_private::SimpleText*>(&self->field_text_59), slint::cbindgen_private::Orientation::Vertical, -1, &self->globals->window().window_handle(), self->self_weak.lock()->into_dyn(), self->tree_index_of_first_child + 28 - 1)) ) }.data(), 3),8,[&](const auto &a_0, const auto &a_1){ slint::cbindgen_private::Padding o{}; o.begin = a_0; o.end = a_1; return o; }(0, 0),slint::cbindgen_private::LayoutAlignment::Center);
                        });
    self->field_root_32_empty_53_spacing.set(8);
    self->field_root_32_empty_53_width.set_binding([this]() {
                            [[maybe_unused]] auto self = this;
                            return self->field_root_32_empty_48_layout_cache.get()[5];
                        });
    self->field_root_32_empty_54_layout_cache.set_binding([this]() {
                            [[maybe_unused]] auto self = this;
                            return slint::private_api::solve_box_layout([&](const auto &a_0, const auto &a_1, const auto &a_2, const auto &a_3, const auto &a_4){ slint::cbindgen_private::BoxLayoutData o{}; o.alignment = a_0; o.cells = a_1; o.padding = a_2; o.size = a_3; o.spacing = a_4; return o; }(slint::cbindgen_private::LayoutAlignment::Start, slint::private_api::make_slice<slint::cbindgen_private::LayoutItemInfo>(std::array<slint::cbindgen_private::LayoutItemInfo, 2>{ slint::cbindgen_private::LayoutItemInfo ( [&](const auto &a_0){ slint::cbindgen_private::LayoutItemInfo o{}; o.constraint = a_0; return o; }(slint::private_api::item_layout_info(SLINT_GET_ITEM_VTABLE(ComplexTextVTable), const_cast<slint::cbindgen_private::ComplexText*>(&self->field_text_55), slint::cbindgen_private::Orientation::Horizontal, -1, &self->globals->window().window_handle(), self->self_weak.lock()->into_dyn(), self->tree_index_of_first_child + 29 - 1)) ), slint::cbindgen_private::LayoutItemInfo ( [&](const auto &a_0){ slint::cbindgen_private::LayoutItemInfo o{}; o.constraint = a_0; return o; }([&]{ [[maybe_unused]] auto layout_info = self->field_root_32_rectangle_56_layoutinfo_h.get();;return [&](const auto &a_0, const auto &a_1, const auto &a_2, const auto &a_3, const auto &a_4, const auto &a_5){ slint::cbindgen_private::LayoutInfo o{}; o.max = a_0; o.max_percent = a_1; o.min = a_2; o.min_percent = a_3; o.preferred = a_4; o.stretch = a_5; return o; }((self->field_instTxt_57.width.get() + 20), layout_info.max_percent, (self->field_instTxt_57.width.get() + 20), layout_info.min_percent, layout_info.preferred, layout_info.stretch); }()) ) }.data(), 2), [&](const auto &a_0, const auto &a_1){ slint::cbindgen_private::Padding o{}; o.begin = a_0; o.end = a_1; return o; }(0, 0), self->field_root_32_empty_53_width.get(), 14),slint::private_api::make_slice<int>(std::array<int, 0>{  }.data(), 0));
                        });
    self->field_root_32_empty_54_layoutinfo_h.set_binding([this]() {
                            [[maybe_unused]] auto self = this;
                            return slint::private_api::box_layout_info(slint::private_api::make_slice<slint::cbindgen_private::LayoutItemInfo>(std::array<slint::cbindgen_private::LayoutItemInfo, 2>{ slint::cbindgen_private::LayoutItemInfo ( [&](const auto &a_0){ slint::cbindgen_private::LayoutItemInfo o{}; o.constraint = a_0; return o; }(slint::private_api::item_layout_info(SLINT_GET_ITEM_VTABLE(ComplexTextVTable), const_cast<slint::cbindgen_private::ComplexText*>(&self->field_text_55), slint::cbindgen_private::Orientation::Horizontal, -1, &self->globals->window().window_handle(), self->self_weak.lock()->into_dyn(), self->tree_index_of_first_child + 29 - 1)) ), slint::cbindgen_private::LayoutItemInfo ( [&](const auto &a_0){ slint::cbindgen_private::LayoutItemInfo o{}; o.constraint = a_0; return o; }([&]{ [[maybe_unused]] auto layout_info = self->field_root_32_rectangle_56_layoutinfo_h.get();;return [&](const auto &a_0, const auto &a_1, const auto &a_2, const auto &a_3, const auto &a_4, const auto &a_5){ slint::cbindgen_private::LayoutInfo o{}; o.max = a_0; o.max_percent = a_1; o.min = a_2; o.min_percent = a_3; o.preferred = a_4; o.stretch = a_5; return o; }((self->field_instTxt_57.width.get() + 20), layout_info.max_percent, (self->field_instTxt_57.width.get() + 20), layout_info.min_percent, layout_info.preferred, layout_info.stretch); }()) ) }.data(), 2),14,[&](const auto &a_0, const auto &a_1){ slint::cbindgen_private::Padding o{}; o.begin = a_0; o.end = a_1; return o; }(0, 0),slint::cbindgen_private::LayoutAlignment::Start);
                        });
    self->field_root_32_empty_54_layoutinfo_v.set_binding([this]() {
                            [[maybe_unused]] auto self = this;
                            return slint::private_api::box_layout_info_ortho(slint::private_api::make_slice<slint::cbindgen_private::LayoutItemInfo>(std::array<slint::cbindgen_private::LayoutItemInfo, 2>{ slint::cbindgen_private::LayoutItemInfo ( [&](const auto &a_0){ slint::cbindgen_private::LayoutItemInfo o{}; o.constraint = a_0; return o; }(slint::private_api::item_layout_info(SLINT_GET_ITEM_VTABLE(ComplexTextVTable), const_cast<slint::cbindgen_private::ComplexText*>(&self->field_text_55), slint::cbindgen_private::Orientation::Vertical, -1, &self->globals->window().window_handle(), self->self_weak.lock()->into_dyn(), self->tree_index_of_first_child + 29 - 1)) ), slint::cbindgen_private::LayoutItemInfo ( [&](const auto &a_0){ slint::cbindgen_private::LayoutItemInfo o{}; o.constraint = a_0; return o; }([&]{ [[maybe_unused]] auto layout_info = self->field_root_32_rectangle_56_layoutinfo_v.get();;return [&](const auto &a_0, const auto &a_1, const auto &a_2, const auto &a_3, const auto &a_4, const auto &a_5){ slint::cbindgen_private::LayoutInfo o{}; o.max = a_0; o.max_percent = a_1; o.min = a_2; o.min_percent = a_3; o.preferred = a_4; o.stretch = a_5; return o; }(24, layout_info.max_percent, 24, layout_info.min_percent, layout_info.preferred, layout_info.stretch); }()) ) }.data(), 2),[&](const auto &a_0, const auto &a_1){ slint::cbindgen_private::Padding o{}; o.begin = a_0; o.end = a_1; return o; }(0, 0));
                        });
    self->field_root_32_empty_61_layout_cache.set_binding([this]() {
                            [[maybe_unused]] auto self = this;
                            return slint::private_api::solve_box_layout([&](const auto &a_0, const auto &a_1, const auto &a_2, const auto &a_3, const auto &a_4){ slint::cbindgen_private::BoxLayoutData o{}; o.alignment = a_0; o.cells = a_1; o.padding = a_2; o.size = a_3; o.spacing = a_4; return o; }(slint::cbindgen_private::LayoutAlignment::Center, slint::private_api::make_slice<slint::cbindgen_private::LayoutItemInfo>(std::array<slint::cbindgen_private::LayoutItemInfo, 1>{ slint::cbindgen_private::LayoutItemInfo ( [&](const auto &a_0){ slint::cbindgen_private::LayoutItemInfo o{}; o.constraint = a_0; return o; }([&]{ [[maybe_unused]] auto layout_info = self->field_root_32_rectangle_62_layoutinfo_v.get();;return [&](const auto &a_0, const auto &a_1, const auto &a_2, const auto &a_3, const auto &a_4, const auto &a_5){ slint::cbindgen_private::LayoutInfo o{}; o.max = a_0; o.max_percent = a_1; o.min = a_2; o.min_percent = a_3; o.preferred = a_4; o.stretch = a_5; return o; }(44, layout_info.max_percent, 44, layout_info.min_percent, layout_info.preferred, layout_info.stretch); }()) ) }.data(), 1), [&](const auto &a_0, const auto &a_1){ slint::cbindgen_private::Padding o{}; o.begin = a_0; o.end = a_1; return o; }(0, 0), self->field_root_32_empty_47_layout_cache.get()[1], 0),slint::private_api::make_slice<int>(std::array<int, 0>{  }.data(), 0));
                        });
    self->field_root_32_empty_61_layoutinfo_h.set_binding([this]() {
                            [[maybe_unused]] auto self = this;
                            return slint::private_api::box_layout_info_ortho(slint::private_api::make_slice<slint::cbindgen_private::LayoutItemInfo>(std::array<slint::cbindgen_private::LayoutItemInfo, 1>{ slint::cbindgen_private::LayoutItemInfo ( [&](const auto &a_0){ slint::cbindgen_private::LayoutItemInfo o{}; o.constraint = a_0; return o; }([&]{ [[maybe_unused]] auto layout_info = self->field_root_32_rectangle_62_layoutinfo_h.get();;return [&](const auto &a_0, const auto &a_1, const auto &a_2, const auto &a_3, const auto &a_4, const auto &a_5){ slint::cbindgen_private::LayoutInfo o{}; o.max = a_0; o.max_percent = a_1; o.min = a_2; o.min_percent = a_3; o.preferred = a_4; o.stretch = a_5; return o; }(152, layout_info.max_percent, 152, layout_info.min_percent, layout_info.preferred, layout_info.stretch); }()) ) }.data(), 1),[&](const auto &a_0, const auto &a_1){ slint::cbindgen_private::Padding o{}; o.begin = a_0; o.end = a_1; return o; }(0, 0));
                        });
    self->field_root_32_empty_61_layoutinfo_v.set_binding([this]() {
                            [[maybe_unused]] auto self = this;
                            return slint::private_api::box_layout_info(slint::private_api::make_slice<slint::cbindgen_private::LayoutItemInfo>(std::array<slint::cbindgen_private::LayoutItemInfo, 1>{ slint::cbindgen_private::LayoutItemInfo ( [&](const auto &a_0){ slint::cbindgen_private::LayoutItemInfo o{}; o.constraint = a_0; return o; }([&]{ [[maybe_unused]] auto layout_info = self->field_root_32_rectangle_62_layoutinfo_v.get();;return [&](const auto &a_0, const auto &a_1, const auto &a_2, const auto &a_3, const auto &a_4, const auto &a_5){ slint::cbindgen_private::LayoutInfo o{}; o.max = a_0; o.max_percent = a_1; o.min = a_2; o.min_percent = a_3; o.preferred = a_4; o.stretch = a_5; return o; }(44, layout_info.max_percent, 44, layout_info.min_percent, layout_info.preferred, layout_info.stretch); }()) ) }.data(), 1),0,[&](const auto &a_0, const auto &a_1){ slint::cbindgen_private::Padding o{}; o.begin = a_0; o.end = a_1; return o; }(0, 0),slint::cbindgen_private::LayoutAlignment::Center);
                        });
    self->field_root_32_empty_82_layout_cache.set_binding([this]() {
                            [[maybe_unused]] auto self = this;
                            return [&]{ std::array<int, 4> repeated_indices_array;  std::vector<slint::cbindgen_private::LayoutItemInfo> cells_vector;cells_vector.push_back({ [&](const auto &a_0){ slint::cbindgen_private::LayoutItemInfo o{}; o.constraint = a_0; return o; }(self->field_root_32_empty_83_layoutinfo_v.get()) });self->repeater_4.track_instance_changes();repeated_indices_array[0] = cells_vector.size();repeated_indices_array[1] = self->repeater_4.len();{
                                    auto start_offset = cells_vector.size();
                                    self->repeater_4.for_each([&](const auto &sub_comp){ cells_vector.push_back(sub_comp->layout_item_info(slint::cbindgen_private::Orientation::Vertical, std::nullopt)); });
                                    cells_vector.resize(start_offset + self->repeater_4.len());
                                }self->repeater_5.track_instance_changes();repeated_indices_array[2] = cells_vector.size();repeated_indices_array[3] = self->repeater_5.len();{
                                    auto start_offset = cells_vector.size();
                                    self->repeater_5.for_each([&](const auto &sub_comp){ cells_vector.push_back(sub_comp->layout_item_info(slint::cbindgen_private::Orientation::Vertical, std::nullopt)); });
                                    cells_vector.resize(start_offset + self->repeater_5.len());
                                }slint::cbindgen_private::Slice<int> repeated_indices = slint::private_api::make_slice(std::span(repeated_indices_array)); slint::cbindgen_private::Slice<slint::cbindgen_private::LayoutItemInfo>cells = slint::private_api::make_slice(std::span(cells_vector)); return slint::private_api::solve_box_layout([&](const auto &a_0, const auto &a_1, const auto &a_2, const auto &a_3, const auto &a_4){ slint::cbindgen_private::BoxLayoutData o{}; o.alignment = a_0; o.cells = a_1; o.padding = a_2; o.size = a_3; o.spacing = a_4; return o; }(slint::cbindgen_private::LayoutAlignment::Stretch, cells, [&](const auto &a_0, const auto &a_1){ slint::cbindgen_private::Padding o{}; o.begin = a_0; o.end = a_1; return o; }(26, 26), self->field_root_32_empty_47_layout_cache.get()[5], 18),repeated_indices); }();
                        });
    self->field_root_32_empty_82_layoutinfo_h.set_binding([this]() {
                            [[maybe_unused]] auto self = this;
                            return [&]{   std::vector<slint::cbindgen_private::LayoutItemInfo> cells_vector;cells_vector.push_back({ [&](const auto &a_0){ slint::cbindgen_private::LayoutItemInfo o{}; o.constraint = a_0; return o; }(self->field_root_32_empty_83_layoutinfo_h.get()) });self->repeater_4.track_instance_changes();{
                                    auto start_offset = cells_vector.size();
                                    self->repeater_4.for_each([&](const auto &sub_comp){ cells_vector.push_back(sub_comp->layout_item_info(slint::cbindgen_private::Orientation::Horizontal, std::nullopt)); });
                                    cells_vector.resize(start_offset + self->repeater_4.len());
                                }self->repeater_5.track_instance_changes();{
                                    auto start_offset = cells_vector.size();
                                    self->repeater_5.for_each([&](const auto &sub_comp){ cells_vector.push_back(sub_comp->layout_item_info(slint::cbindgen_private::Orientation::Horizontal, std::nullopt)); });
                                    cells_vector.resize(start_offset + self->repeater_5.len());
                                } slint::cbindgen_private::Slice<slint::cbindgen_private::LayoutItemInfo>cells = slint::private_api::make_slice(std::span(cells_vector)); return slint::private_api::box_layout_info_ortho(cells,[&](const auto &a_0, const auto &a_1){ slint::cbindgen_private::Padding o{}; o.begin = a_0; o.end = a_1; return o; }(26, 26)); }();
                        });
    self->field_root_32_empty_82_layoutinfo_v.set_binding([this]() {
                            [[maybe_unused]] auto self = this;
                            return [&]{   std::vector<slint::cbindgen_private::LayoutItemInfo> cells_vector;cells_vector.push_back({ [&](const auto &a_0){ slint::cbindgen_private::LayoutItemInfo o{}; o.constraint = a_0; return o; }(self->field_root_32_empty_83_layoutinfo_v.get()) });self->repeater_4.track_instance_changes();{
                                    auto start_offset = cells_vector.size();
                                    self->repeater_4.for_each([&](const auto &sub_comp){ cells_vector.push_back(sub_comp->layout_item_info(slint::cbindgen_private::Orientation::Vertical, std::nullopt)); });
                                    cells_vector.resize(start_offset + self->repeater_4.len());
                                }self->repeater_5.track_instance_changes();{
                                    auto start_offset = cells_vector.size();
                                    self->repeater_5.for_each([&](const auto &sub_comp){ cells_vector.push_back(sub_comp->layout_item_info(slint::cbindgen_private::Orientation::Vertical, std::nullopt)); });
                                    cells_vector.resize(start_offset + self->repeater_5.len());
                                } slint::cbindgen_private::Slice<slint::cbindgen_private::LayoutItemInfo>cells = slint::private_api::make_slice(std::span(cells_vector)); return slint::private_api::box_layout_info(cells,18,[&](const auto &a_0, const auto &a_1){ slint::cbindgen_private::Padding o{}; o.begin = a_0; o.end = a_1; return o; }(26, 26),slint::cbindgen_private::LayoutAlignment::Stretch); }();
                        });
    self->field_root_32_empty_83_layout_cache.set_binding([this]() {
                            [[maybe_unused]] auto self = this;
                            return [&]{ std::array<int, 2> repeated_indices_array;  std::vector<slint::cbindgen_private::LayoutItemInfo> cells_vector;cells_vector.push_back({ [&](const auto &a_0){ slint::cbindgen_private::LayoutItemInfo o{}; o.constraint = a_0; return o; }(slint::private_api::item_layout_info(SLINT_GET_ITEM_VTABLE(SimpleTextVTable), const_cast<slint::cbindgen_private::SimpleText*>(&self->field_text_84), slint::cbindgen_private::Orientation::Horizontal, -1, &self->globals->window().window_handle(), self->self_weak.lock()->into_dyn(), self->tree_index_of_first_child + 38 - 1)) });self->repeater_3.track_instance_changes();repeated_indices_array[0] = cells_vector.size();repeated_indices_array[1] = self->repeater_3.len();{
                                    auto start_offset = cells_vector.size();
                                    self->repeater_3.for_each([&](const auto &sub_comp){ cells_vector.push_back(sub_comp->layout_item_info(slint::cbindgen_private::Orientation::Horizontal, std::nullopt)); });
                                    cells_vector.resize(start_offset + self->repeater_3.len());
                                }slint::cbindgen_private::Slice<int> repeated_indices = slint::private_api::make_slice(std::span(repeated_indices_array)); slint::cbindgen_private::Slice<slint::cbindgen_private::LayoutItemInfo>cells = slint::private_api::make_slice(std::span(cells_vector)); return slint::private_api::solve_box_layout([&](const auto &a_0, const auto &a_1, const auto &a_2, const auto &a_3, const auto &a_4){ slint::cbindgen_private::BoxLayoutData o{}; o.alignment = a_0; o.cells = a_1; o.padding = a_2; o.size = a_3; o.spacing = a_4; return o; }(slint::cbindgen_private::LayoutAlignment::SpaceBetween, cells, [&](const auto &a_0, const auto &a_1){ slint::cbindgen_private::Padding o{}; o.begin = a_0; o.end = a_1; return o; }(0, 0), ((((self->field_flickable_45.viewport_width.get() -(float) 64) -(float) 64) -(float) 26) -(float) 26), 0),repeated_indices); }();
                        });
    self->field_root_32_empty_83_layoutinfo_h.set_binding([this]() {
                            [[maybe_unused]] auto self = this;
                            return [&]{   std::vector<slint::cbindgen_private::LayoutItemInfo> cells_vector;cells_vector.push_back({ [&](const auto &a_0){ slint::cbindgen_private::LayoutItemInfo o{}; o.constraint = a_0; return o; }(slint::private_api::item_layout_info(SLINT_GET_ITEM_VTABLE(SimpleTextVTable), const_cast<slint::cbindgen_private::SimpleText*>(&self->field_text_84), slint::cbindgen_private::Orientation::Horizontal, -1, &self->globals->window().window_handle(), self->self_weak.lock()->into_dyn(), self->tree_index_of_first_child + 38 - 1)) });self->repeater_3.track_instance_changes();{
                                    auto start_offset = cells_vector.size();
                                    self->repeater_3.for_each([&](const auto &sub_comp){ cells_vector.push_back(sub_comp->layout_item_info(slint::cbindgen_private::Orientation::Horizontal, std::nullopt)); });
                                    cells_vector.resize(start_offset + self->repeater_3.len());
                                } slint::cbindgen_private::Slice<slint::cbindgen_private::LayoutItemInfo>cells = slint::private_api::make_slice(std::span(cells_vector)); return slint::private_api::box_layout_info(cells,0,[&](const auto &a_0, const auto &a_1){ slint::cbindgen_private::Padding o{}; o.begin = a_0; o.end = a_1; return o; }(0, 0),slint::cbindgen_private::LayoutAlignment::SpaceBetween); }();
                        });
    self->field_root_32_empty_83_layoutinfo_v.set_binding([this]() {
                            [[maybe_unused]] auto self = this;
                            return [&]{   std::vector<slint::cbindgen_private::LayoutItemInfo> cells_vector;cells_vector.push_back({ [&](const auto &a_0){ slint::cbindgen_private::LayoutItemInfo o{}; o.constraint = a_0; return o; }(slint::private_api::item_layout_info(SLINT_GET_ITEM_VTABLE(SimpleTextVTable), const_cast<slint::cbindgen_private::SimpleText*>(&self->field_text_84), slint::cbindgen_private::Orientation::Vertical, -1, &self->globals->window().window_handle(), self->self_weak.lock()->into_dyn(), self->tree_index_of_first_child + 38 - 1)) });self->repeater_3.track_instance_changes();{
                                    auto start_offset = cells_vector.size();
                                    self->repeater_3.for_each([&](const auto &sub_comp){ cells_vector.push_back(sub_comp->layout_item_info(slint::cbindgen_private::Orientation::Vertical, std::nullopt)); });
                                    cells_vector.resize(start_offset + self->repeater_3.len());
                                } slint::cbindgen_private::Slice<slint::cbindgen_private::LayoutItemInfo>cells = slint::private_api::make_slice(std::span(cells_vector)); return slint::private_api::box_layout_info_ortho(cells,[&](const auto &a_0, const auto &a_1){ slint::cbindgen_private::Padding o{}; o.begin = a_0; o.end = a_1; return o; }(0, 0)); }();
                        });
    self->field_root_32_flickable_45_max_height.set_binding([this]() {
                            [[maybe_unused]] auto self = this;
                            return self->field_root_32_empty_47_layoutinfo_v.get().max;
                        });
    self->field_root_32_flickable_45_preferred_height.set_binding([this]() {
                            [[maybe_unused]] auto self = this;
                            return self->field_root_32_empty_47_layoutinfo_v.get().preferred;
                        });
    self->field_root_32_instTxt_57_min_height.set_binding([this]() {
                            [[maybe_unused]] auto self = this;
                            return slint::private_api::item_layout_info(SLINT_GET_ITEM_VTABLE(SimpleTextVTable), const_cast<slint::cbindgen_private::SimpleText*>(&self->field_instTxt_57), slint::cbindgen_private::Orientation::Vertical, -1, &self->globals->window().window_handle(), self->self_weak.lock()->into_dyn(), self->tree_index_of_first_child + 31 - 1).min;
                        });
    self->field_root_32_instTxt_57_min_width.set_binding([this]() {
                            [[maybe_unused]] auto self = this;
                            return slint::private_api::item_layout_info(SLINT_GET_ITEM_VTABLE(SimpleTextVTable), const_cast<slint::cbindgen_private::SimpleText*>(&self->field_instTxt_57), slint::cbindgen_private::Orientation::Horizontal, -1, &self->globals->window().window_handle(), self->self_weak.lock()->into_dyn(), self->tree_index_of_first_child + 31 - 1).min;
                        });
    self->field_root_32_instTxt_57_preferred_height.set_binding([this]() {
                            [[maybe_unused]] auto self = this;
                            return slint::private_api::item_layout_info(SLINT_GET_ITEM_VTABLE(SimpleTextVTable), const_cast<slint::cbindgen_private::SimpleText*>(&self->field_instTxt_57), slint::cbindgen_private::Orientation::Vertical, -1, &self->globals->window().window_handle(), self->self_weak.lock()->into_dyn(), self->tree_index_of_first_child + 31 - 1).preferred;
                        });
    self->field_root_32_instTxt_57_preferred_width.set_binding([this]() {
                            [[maybe_unused]] auto self = this;
                            return slint::private_api::item_layout_info(SLINT_GET_ITEM_VTABLE(SimpleTextVTable), const_cast<slint::cbindgen_private::SimpleText*>(&self->field_instTxt_57), slint::cbindgen_private::Orientation::Horizontal, -1, &self->globals->window().window_handle(), self->self_weak.lock()->into_dyn(), self->tree_index_of_first_child + 31 - 1).preferred;
                        });
    self->field_root_32_instTxt_57_x.set_binding([this]() {
                            [[maybe_unused]] auto self = this;
                            return (((self->field_instTxt_57.width.get() + 20) -(float) self->field_instTxt_57.width.get()) /(float) 2);
                        });
    self->field_root_32_rectangle_34_height.set(64);
    self->field_root_32_rectangle_34_layoutinfo_v.set_binding([this]() {
                            [[maybe_unused]] auto self = this;
                            return ([&](const auto &a_0, const auto &a_1, const auto &a_2, const auto &a_3, const auto &a_4, const auto &a_5){ slint::cbindgen_private::LayoutInfo o{}; o.max = a_0; o.max_percent = a_1; o.min = a_2; o.min_percent = a_3; o.preferred = a_4; o.stretch = a_5; return o; }(+3.4028234663852886e38, 100, 0, 0, 0, 1) + self->field_root_32_empty_35_layoutinfo_v.get());
                        });
    self->field_root_32_rectangle_34_width.set_binding([this]() {
                            [[maybe_unused]] auto self = this;
                            return self->field_root_32_width.get();
                        });
    self->field_root_32_rectangle_42_layoutinfo_h.set_binding([this]() {
                            [[maybe_unused]] auto self = this;
                            return ([&](const auto &a_0, const auto &a_1, const auto &a_2, const auto &a_3, const auto &a_4, const auto &a_5){ slint::cbindgen_private::LayoutInfo o{}; o.max = a_0; o.max_percent = a_1; o.min = a_2; o.min_percent = a_3; o.preferred = a_4; o.stretch = a_5; return o; }(+3.4028234663852886e38, 100, 0, 0, 0, 1) + slint::private_api::item_layout_info(SLINT_GET_ITEM_VTABLE(SimpleTextVTable), const_cast<slint::cbindgen_private::SimpleText*>(&self->field_text_44), slint::cbindgen_private::Orientation::Horizontal, -1, &self->globals->window().window_handle(), self->self_weak.lock()->into_dyn(), self->tree_index_of_first_child + 13 - 1));
                        });
    self->field_root_32_rectangle_42_layoutinfo_v.set_binding([this]() {
                            [[maybe_unused]] auto self = this;
                            return ([&](const auto &a_0, const auto &a_1, const auto &a_2, const auto &a_3, const auto &a_4, const auto &a_5){ slint::cbindgen_private::LayoutInfo o{}; o.max = a_0; o.max_percent = a_1; o.min = a_2; o.min_percent = a_3; o.preferred = a_4; o.stretch = a_5; return o; }(+3.4028234663852886e38, 100, 0, 0, 0, 1) + slint::private_api::item_layout_info(SLINT_GET_ITEM_VTABLE(SimpleTextVTable), const_cast<slint::cbindgen_private::SimpleText*>(&self->field_text_44), slint::cbindgen_private::Orientation::Vertical, -1, &self->globals->window().window_handle(), self->self_weak.lock()->into_dyn(), self->tree_index_of_first_child + 13 - 1));
                        });
    self->field_root_32_rectangle_56_layoutinfo_h.set_binding([this]() {
                            [[maybe_unused]] auto self = this;
                            return ([&](const auto &a_0, const auto &a_1, const auto &a_2, const auto &a_3, const auto &a_4, const auto &a_5){ slint::cbindgen_private::LayoutInfo o{}; o.max = a_0; o.max_percent = a_1; o.min = a_2; o.min_percent = a_3; o.preferred = a_4; o.stretch = a_5; return o; }(+3.4028234663852886e38, 100, 0, 0, 0, 1) + slint::private_api::item_layout_info(SLINT_GET_ITEM_VTABLE(SimpleTextVTable), const_cast<slint::cbindgen_private::SimpleText*>(&self->field_instTxt_57), slint::cbindgen_private::Orientation::Horizontal, -1, &self->globals->window().window_handle(), self->self_weak.lock()->into_dyn(), self->tree_index_of_first_child + 31 - 1));
                        });
    self->field_root_32_rectangle_56_layoutinfo_v.set_binding([this]() {
                            [[maybe_unused]] auto self = this;
                            return ([&](const auto &a_0, const auto &a_1, const auto &a_2, const auto &a_3, const auto &a_4, const auto &a_5){ slint::cbindgen_private::LayoutInfo o{}; o.max = a_0; o.max_percent = a_1; o.min = a_2; o.min_percent = a_3; o.preferred = a_4; o.stretch = a_5; return o; }(+3.4028234663852886e38, 100, 0, 0, 0, 1) + slint::private_api::item_layout_info(SLINT_GET_ITEM_VTABLE(SimpleTextVTable), const_cast<slint::cbindgen_private::SimpleText*>(&self->field_instTxt_57), slint::cbindgen_private::Orientation::Vertical, -1, &self->globals->window().window_handle(), self->self_weak.lock()->into_dyn(), self->tree_index_of_first_child + 31 - 1));
                        });
    self->field_root_32_rectangle_62_layoutinfo_h.set_binding([this]() {
                            [[maybe_unused]] auto self = this;
                            return ([&](const auto &a_0, const auto &a_1, const auto &a_2, const auto &a_3, const auto &a_4, const auto &a_5){ slint::cbindgen_private::LayoutInfo o{}; o.max = a_0; o.max_percent = a_1; o.min = a_2; o.min_percent = a_3; o.preferred = a_4; o.stretch = a_5; return o; }(+3.4028234663852886e38, 100, 0, 0, 0, 1) + slint::private_api::item_layout_info(SLINT_GET_ITEM_VTABLE(SimpleTextVTable), const_cast<slint::cbindgen_private::SimpleText*>(&self->field_text_64), slint::cbindgen_private::Orientation::Horizontal, -1, &self->globals->window().window_handle(), self->self_weak.lock()->into_dyn(), self->tree_index_of_first_child + 34 - 1));
                        });
    self->field_root_32_rectangle_62_layoutinfo_v.set_binding([this]() {
                            [[maybe_unused]] auto self = this;
                            return ([&](const auto &a_0, const auto &a_1, const auto &a_2, const auto &a_3, const auto &a_4, const auto &a_5){ slint::cbindgen_private::LayoutInfo o{}; o.max = a_0; o.max_percent = a_1; o.min = a_2; o.min_percent = a_3; o.preferred = a_4; o.stretch = a_5; return o; }(+3.4028234663852886e38, 100, 0, 0, 0, 1) + slint::private_api::item_layout_info(SLINT_GET_ITEM_VTABLE(SimpleTextVTable), const_cast<slint::cbindgen_private::SimpleText*>(&self->field_text_64), slint::cbindgen_private::Orientation::Vertical, -1, &self->globals->window().window_handle(), self->self_weak.lock()->into_dyn(), self->tree_index_of_first_child + 34 - 1));
                        });
    self->field_root_32_rectangle_81_layoutinfo_v.set_binding([this]() {
                            [[maybe_unused]] auto self = this;
                            return ([&](const auto &a_0, const auto &a_1, const auto &a_2, const auto &a_3, const auto &a_4, const auto &a_5){ slint::cbindgen_private::LayoutInfo o{}; o.max = a_0; o.max_percent = a_1; o.min = a_2; o.min_percent = a_3; o.preferred = a_4; o.stretch = a_5; return o; }(+3.4028234663852886e38, 100, 0, 0, 0, 1) + self->field_root_32_empty_82_layoutinfo_v.get());
                        });
    self->field_root_32_show_console.set(false);
    self->field_root_32_show_uninstall_modal.set(false);
    self->field_root_32_text_44_min_height.set_binding([this]() {
                            [[maybe_unused]] auto self = this;
                            return slint::private_api::item_layout_info(SLINT_GET_ITEM_VTABLE(SimpleTextVTable), const_cast<slint::cbindgen_private::SimpleText*>(&self->field_text_44), slint::cbindgen_private::Orientation::Vertical, -1, &self->globals->window().window_handle(), self->self_weak.lock()->into_dyn(), self->tree_index_of_first_child + 13 - 1).min;
                        });
    self->field_root_32_text_44_min_width.set_binding([this]() {
                            [[maybe_unused]] auto self = this;
                            return slint::private_api::item_layout_info(SLINT_GET_ITEM_VTABLE(SimpleTextVTable), const_cast<slint::cbindgen_private::SimpleText*>(&self->field_text_44), slint::cbindgen_private::Orientation::Horizontal, -1, &self->globals->window().window_handle(), self->self_weak.lock()->into_dyn(), self->tree_index_of_first_child + 13 - 1).min;
                        });
    self->field_root_32_text_44_preferred_height.set_binding([this]() {
                            [[maybe_unused]] auto self = this;
                            return slint::private_api::item_layout_info(SLINT_GET_ITEM_VTABLE(SimpleTextVTable), const_cast<slint::cbindgen_private::SimpleText*>(&self->field_text_44), slint::cbindgen_private::Orientation::Vertical, -1, &self->globals->window().window_handle(), self->self_weak.lock()->into_dyn(), self->tree_index_of_first_child + 13 - 1).preferred;
                        });
    self->field_root_32_text_44_preferred_width.set_binding([this]() {
                            [[maybe_unused]] auto self = this;
                            return slint::private_api::item_layout_info(SLINT_GET_ITEM_VTABLE(SimpleTextVTable), const_cast<slint::cbindgen_private::SimpleText*>(&self->field_text_44), slint::cbindgen_private::Orientation::Horizontal, -1, &self->globals->window().window_handle(), self->self_weak.lock()->into_dyn(), self->tree_index_of_first_child + 13 - 1).preferred;
                        });
    self->field_root_32_text_64_min_height.set_binding([this]() {
                            [[maybe_unused]] auto self = this;
                            return slint::private_api::item_layout_info(SLINT_GET_ITEM_VTABLE(SimpleTextVTable), const_cast<slint::cbindgen_private::SimpleText*>(&self->field_text_64), slint::cbindgen_private::Orientation::Vertical, -1, &self->globals->window().window_handle(), self->self_weak.lock()->into_dyn(), self->tree_index_of_first_child + 34 - 1).min;
                        });
    self->field_root_32_text_64_min_width.set_binding([this]() {
                            [[maybe_unused]] auto self = this;
                            return slint::private_api::item_layout_info(SLINT_GET_ITEM_VTABLE(SimpleTextVTable), const_cast<slint::cbindgen_private::SimpleText*>(&self->field_text_64), slint::cbindgen_private::Orientation::Horizontal, -1, &self->globals->window().window_handle(), self->self_weak.lock()->into_dyn(), self->tree_index_of_first_child + 34 - 1).min;
                        });
    self->field_root_32_text_64_preferred_height.set_binding([this]() {
                            [[maybe_unused]] auto self = this;
                            return slint::private_api::item_layout_info(SLINT_GET_ITEM_VTABLE(SimpleTextVTable), const_cast<slint::cbindgen_private::SimpleText*>(&self->field_text_64), slint::cbindgen_private::Orientation::Vertical, -1, &self->globals->window().window_handle(), self->self_weak.lock()->into_dyn(), self->tree_index_of_first_child + 34 - 1).preferred;
                        });
    self->field_root_32_text_64_preferred_width.set_binding([this]() {
                            [[maybe_unused]] auto self = this;
                            return slint::private_api::item_layout_info(SLINT_GET_ITEM_VTABLE(SimpleTextVTable), const_cast<slint::cbindgen_private::SimpleText*>(&self->field_text_64), slint::cbindgen_private::Orientation::Horizontal, -1, &self->globals->window().window_handle(), self->self_weak.lock()->into_dyn(), self->tree_index_of_first_child + 34 - 1).preferred;
                        });
    self->field_rectangle_34.background.set(slint::Brush(slint::Color::from_argb_encoded(+4.279769125e9)));
    self->field_rectangle_34.border_color.set(slint::Brush(slint::Color::from_argb_encoded(+4.281414212e9)));
    self->field_rectangle_34.border_width.set(1);
    self->field_text_37.color.set_binding([this]() {
                            [[maybe_unused]] auto self = this;
                            return self->globals->global_FluentPalette_221->field_foreground.get();
                        });
    self->field_text_37.font_size.set(22);
    self->field_text_37.height.set(64);
    self->field_text_37.text.set(slint::SharedString(u8"\U0001f427"));
    self->field_text_37.vertical_alignment.set(slint::cbindgen_private::TextVerticalAlignment::Center);
    self->field_text_37.width.set_binding([this]() {
                            [[maybe_unused]] auto self = this;
                            return self->field_root_32_empty_36_layout_cache.get()[1];
                        });
    self->field_text_39.color.set(slint::Brush(slint::Color::from_argb_encoded(+4.287214842e9)));
    self->field_text_39.font_size.set(18);
    self->field_text_39.font_weight.set(static_cast<int>(700));
    self->field_text_39.height.set_binding([this]() {
                            [[maybe_unused]] auto self = this;
                            return self->field_root_32_empty_38_layout_cache.get()[1];
                        });
    self->field_text_39.text.set(slint::SharedString(u8"Tux Store"));
    self->field_text_39.width.set_binding([this]() {
                            [[maybe_unused]] auto self = this;
                            return self->field_root_32_empty_36_layout_cache.get()[3];
                        });
    self->field_text_40.color.set(slint::Brush(slint::Color::from_argb_encoded(+4.2865471e9)));
    self->field_text_40.font_size.set(11);
    self->field_text_40.height.set_binding([this]() {
                            [[maybe_unused]] auto self = this;
                            return self->field_root_32_empty_38_layout_cache.get()[3];
                        });
    self->field_text_40.text.set(slint::SharedString(u8"for Arch Linux"));
    self->field_text_40.width.set_binding([this]() {
                            [[maybe_unused]] auto self = this;
                            return self->field_root_32_empty_36_layout_cache.get()[3];
                        });
    self->field_rectangle_42.background.set_binding([this]() {
                            [[maybe_unused]] auto self = this;
                            return slint::Brush((self->field_back_ta_43.has_hover.get() ? slint::Color::from_argb_encoded(+4.28273033e9) : slint::Color::from_argb_encoded(+4.281414212e9)));
                        });
    self->field_rectangle_42.border_color.set(slint::Brush(slint::Color::from_argb_encoded(+4.28273033e9)));
    self->field_rectangle_42.border_radius.set(10);
    self->field_rectangle_42.border_width.set(1);
    self->field_back_ta_43.clicked.set_handler(
                [this]() {
                    [[maybe_unused]] auto self = this;
                    self->field_root_32_back_clicked.call();
                });
    self->field_back_ta_43.enabled.set(true);
    self->field_text_44.color.set(slint::Brush(slint::Color::from_argb_encoded(+4.291679988e9)));
    self->field_text_44.font_size.set(13);
    self->field_text_44.font_weight.set(static_cast<int>(700));
    self->field_text_44.height.set_binding([this]() {
                            [[maybe_unused]] auto self = this;
                            return std::max<float>(self->field_root_32_text_44_preferred_height.get(), self->field_root_32_text_44_min_height.get());
                        });
    self->field_text_44.horizontal_alignment.set(slint::cbindgen_private::TextHorizontalAlignment::Center);
    self->field_text_44.text.set(slint::SharedString(u8"\U000027e8 Back"));
    self->field_text_44.vertical_alignment.set(slint::cbindgen_private::TextVerticalAlignment::Center);
    self->field_text_44.width.set_binding([this]() {
                            [[maybe_unused]] auto self = this;
                            return std::max<float>(self->field_root_32_text_44_preferred_width.get(), self->field_root_32_text_44_min_width.get());
                        });
    self->field_flickable_45.interactive.set(true);
    self->field_flickable_45.viewport_height.set_binding([this]() {
                            [[maybe_unused]] auto self = this;
                            return std::max<float>(self->field_root_32_empty_33_layout_cache.get()[3], self->field_root_32_empty_47_layoutinfo_v.get().min);
                        });
    self->field_flickable_45.viewport_width.set_binding([this]() {
                            [[maybe_unused]] auto self = this;
                            return std::max<float>(self->field_root_32_width.get(), self->field_root_32_empty_47_layoutinfo_h.get().min);
                        });
    self->field_text_55.color.set(slint::Brush(slint::Color::from_argb_encoded(+4.291679988e9)));
    self->field_text_55.font_size.set(30);
    self->field_text_55.font_weight.set(static_cast<int>(700));
    self->field_text_55.height.set_binding([this]() {
                            [[maybe_unused]] auto self = this;
                            return self->field_root_32_empty_53_layout_cache.get()[1];
                        });
    self->field_text_55.letter_spacing.set(-0.5);
    self->field_text_55.text.set_binding([this]() {
                            [[maybe_unused]] auto self = this;
                            return self->field_root_32_pkg.get().pretty_name;
                        });
    self->field_text_55.vertical_alignment.set(slint::cbindgen_private::TextVerticalAlignment::Center);
    self->field_text_55.width.set_binding([this]() {
                            [[maybe_unused]] auto self = this;
                            return self->field_root_32_empty_54_layout_cache.get()[1];
                        });
    self->field_rectangle_56.background.set_binding([this]() {
                            [[maybe_unused]] auto self = this;
                            return (self->field_root_32_pkg.get().installed ? slint::Brush(slint::Color::from_argb_encoded(+4.289127329e9)).transparentize(0.85) : slint::Brush(slint::Color::from_argb_encoded(+4.28273033e9)));
                        });
    self->field_rectangle_56.border_radius.set(12);
    self->field_instTxt_57.color.set_binding([this]() {
                            [[maybe_unused]] auto self = this;
                            return slint::Brush((self->field_root_32_pkg.get().installed ? slint::Color::from_argb_encoded(+4.289127329e9) : slint::Color::from_argb_encoded(+4.289113544e9)));
                        });
    self->field_instTxt_57.font_size.set(11);
    self->field_instTxt_57.font_weight.set(static_cast<int>(700));
    self->field_instTxt_57.height.set_binding([this]() {
                            [[maybe_unused]] auto self = this;
                            return std::max<float>(self->field_root_32_instTxt_57_preferred_height.get(), self->field_root_32_instTxt_57_min_height.get());
                        });
    self->field_instTxt_57.horizontal_alignment.set(slint::cbindgen_private::TextHorizontalAlignment::Center);
    self->field_instTxt_57.text.set_binding([this]() {
                            [[maybe_unused]] auto self = this;
                            return [&]{ [[maybe_unused]] auto tmp_root_32_pkg = self->field_root_32_pkg.get();;return (tmp_root_32_pkg.installed ? slint::SharedString(u8"Installed") : tmp_root_32_pkg.repo); }();
                        });
    self->field_instTxt_57.vertical_alignment.set(slint::cbindgen_private::TextVerticalAlignment::Center);
    self->field_instTxt_57.width.set_binding([this]() {
                            [[maybe_unused]] auto self = this;
                            return std::max<float>(self->field_root_32_instTxt_57_preferred_width.get(), self->field_root_32_instTxt_57_min_width.get());
                        });
    self->field_text_58.color.set(slint::Brush(slint::Color::from_argb_encoded(+4.289113544e9)));
    self->field_text_58.font_size.set(14);
    self->field_text_58.height.set_binding([this]() {
                            [[maybe_unused]] auto self = this;
                            return self->field_root_32_empty_53_layout_cache.get()[3];
                        });
    self->field_text_58.text.set_binding([this]() {
                            [[maybe_unused]] auto self = this;
                            return self->field_root_32_pkg.get().description;
                        });
    self->field_text_58.width.set_binding([this]() {
                            [[maybe_unused]] auto self = this;
                            return self->field_root_32_empty_48_layout_cache.get()[5];
                        });
    self->field_text_58.wrap.set(slint::cbindgen_private::TextWrap::WordWrap);
    self->field_text_59.color.set(slint::Brush(slint::Color::from_argb_encoded(+4.2865471e9)));
    self->field_text_59.font_size.set(12);
    self->field_text_59.height.set_binding([this]() {
                            [[maybe_unused]] auto self = this;
                            return self->field_root_32_empty_53_layout_cache.get()[5];
                        });
    self->field_text_59.text.set_binding([this]() {
                            [[maybe_unused]] auto self = this;
                            return (slint::SharedString(u8"Version ") + self->field_root_32_pkg.get().version);
                        });
    self->field_text_59.width.set_binding([this]() {
                            [[maybe_unused]] auto self = this;
                            return self->field_root_32_empty_48_layout_cache.get()[5];
                        });
    self->field_rectangle_62.background.set_binding([this]() {
                            [[maybe_unused]] auto self = this;
                            return slint::Brush((self->field_root_32_pkg.get().installed ? slint::Color::from_argb_encoded(+4.281414212e9) : self->field_root_32_accent.get()));
                        });
    self->field_rectangle_62.border_color.set_binding([this]() {
                            [[maybe_unused]] auto self = this;
                            return slint::Brush((self->field_root_32_pkg.get().installed ? slint::Color::from_argb_encoded(+4.29415108e9) : self->field_root_32_accent.get()));
                        });
    self->field_rectangle_62.border_radius.set(10);
    self->field_rectangle_62.border_width.set_binding([this]() {
                            [[maybe_unused]] auto self = this;
                            return (self->field_root_32_pkg.get().installed ? 1 : 0);
                        });
    self->field_toucharea_63.clicked.set_handler(
                [this]() {
                    [[maybe_unused]] auto self = this;
                    if (self->field_root_32_pkg.get().installed) { self->field_root_32_show_uninstall_modal.set(true); } else { self->field_root_32_install_clicked.call(); };
                });
    self->field_toucharea_63.enabled.set(true);
    self->field_text_64.color.set_binding([this]() {
                            [[maybe_unused]] auto self = this;
                            return slint::Brush((self->field_root_32_pkg.get().installed ? slint::Color::from_argb_encoded(+4.29415108e9) : slint::Color::from_argb_encoded(+4.279308571e9)));
                        });
    self->field_text_64.font_size.set(14);
    self->field_text_64.font_weight.set(static_cast<int>(700));
    self->field_text_64.height.set_binding([this]() {
                            [[maybe_unused]] auto self = this;
                            return std::max<float>(self->field_root_32_text_64_preferred_height.get(), self->field_root_32_text_64_min_height.get());
                        });
    self->field_text_64.horizontal_alignment.set(slint::cbindgen_private::TextHorizontalAlignment::Center);
    self->field_text_64.text.set_binding([this]() {
                            [[maybe_unused]] auto self = this;
                            return (self->field_root_32_pkg.get().installed ? (self->field_root_32_install_state.get().is_uninstalling ? slint::SharedString(u8"Uninstalling\U00002026") : slint::SharedString(u8"Remove")) : (self->field_root_32_install_state.get().is_installing ? slint::SharedString(u8"Installing\U00002026") : slint::SharedString(u8"Install")));
                        });
    self->field_text_64.vertical_alignment.set(slint::cbindgen_private::TextVerticalAlignment::Center);
    self->field_text_64.width.set_binding([this]() {
                            [[maybe_unused]] auto self = this;
                            return std::max<float>(self->field_root_32_text_64_preferred_width.get(), self->field_root_32_text_64_min_width.get());
                        });
    self->field_rectangle_81.background.set(slint::Brush(slint::Color::from_argb_encoded(+4.279769125e9)));
    self->field_rectangle_81.border_color.set(slint::Brush(slint::Color::from_argb_encoded(+4.281414212e9)));
    self->field_rectangle_81.border_radius.set(16);
    self->field_rectangle_81.border_width.set(1);
    self->field_text_84.color.set(slint::Brush(slint::Color::from_argb_encoded(+4.291679988e9)));
    self->field_text_84.font_size.set(16);
    self->field_text_84.font_weight.set(static_cast<int>(700));
    self->field_text_84.height.set_binding([this]() {
                            [[maybe_unused]] auto self = this;
                            return self->field_root_32_empty_82_layout_cache.get()[1];
                        });
    self->field_text_84.text.set(slint::SharedString(u8"What you'll download"));
    self->field_text_84.vertical_alignment.set(slint::cbindgen_private::TextVerticalAlignment::Center);
    self->field_text_84.width.set_binding([this]() {
                            [[maybe_unused]] auto self = this;
                            return self->field_root_32_empty_83_layout_cache.get()[1];
                        });
    self->field_root_32.background.set_constant();
    self->field_root_32_empty_47_alignment.set_constant();
    self->field_root_32_empty_47_padding_bottom.set_constant();
    self->field_root_32_empty_47_padding_top.set_constant();
    self->field_root_32_empty_47_spacing.set_constant();
    self->field_root_32_empty_53_alignment.set_constant();
    self->field_root_32_empty_53_spacing.set_constant();
    self->field_root_32_rectangle_34_height.set_constant();
    self->field_rectangle_34.background.set_constant();
    self->field_rectangle_34.border_color.set_constant();
    self->field_rectangle_34.border_radius.set_constant();
    self->field_rectangle_34.border_width.set_constant();
    self->field_text_37.font_size.set_constant();
    self->field_text_37.font_weight.set_constant();
    self->field_text_37.height.set_constant();
    self->field_text_37.horizontal_alignment.set_constant();
    self->field_text_37.text.set_constant();
    self->field_text_37.vertical_alignment.set_constant();
    self->field_text_39.color.set_constant();
    self->field_text_39.font_size.set_constant();
    self->field_text_39.font_weight.set_constant();
    self->field_text_39.horizontal_alignment.set_constant();
    self->field_text_39.text.set_constant();
    self->field_text_39.vertical_alignment.set_constant();
    self->field_text_40.color.set_constant();
    self->field_text_40.font_size.set_constant();
    self->field_text_40.font_weight.set_constant();
    self->field_text_40.horizontal_alignment.set_constant();
    self->field_text_40.text.set_constant();
    self->field_text_40.vertical_alignment.set_constant();
    self->field_rectangle_42.border_color.set_constant();
    self->field_rectangle_42.border_radius.set_constant();
    self->field_rectangle_42.border_width.set_constant();
    self->field_back_ta_43.enabled.set_constant();
    self->field_back_ta_43.mouse_cursor.set_constant();
    self->field_text_44.color.set_constant();
    self->field_text_44.font_size.set_constant();
    self->field_text_44.font_weight.set_constant();
    self->field_text_44.horizontal_alignment.set_constant();
    self->field_text_44.text.set_constant();
    self->field_text_44.vertical_alignment.set_constant();
    self->field_flickable_45.interactive.set_constant();
    self->field_text_55.color.set_constant();
    self->field_text_55.font_family.set_constant();
    self->field_text_55.font_italic.set_constant();
    self->field_text_55.font_size.set_constant();
    self->field_text_55.font_weight.set_constant();
    self->field_text_55.horizontal_alignment.set_constant();
    self->field_text_55.letter_spacing.set_constant();
    self->field_text_55.overflow.set_constant();
    self->field_text_55.stroke.set_constant();
    self->field_text_55.stroke_style.set_constant();
    self->field_text_55.stroke_width.set_constant();
    self->field_text_55.vertical_alignment.set_constant();
    self->field_text_55.wrap.set_constant();
    self->field_rectangle_56.border_color.set_constant();
    self->field_rectangle_56.border_radius.set_constant();
    self->field_rectangle_56.border_width.set_constant();
    self->field_instTxt_57.font_size.set_constant();
    self->field_instTxt_57.font_weight.set_constant();
    self->field_instTxt_57.horizontal_alignment.set_constant();
    self->field_instTxt_57.vertical_alignment.set_constant();
    self->field_text_58.color.set_constant();
    self->field_text_58.font_family.set_constant();
    self->field_text_58.font_italic.set_constant();
    self->field_text_58.font_size.set_constant();
    self->field_text_58.font_weight.set_constant();
    self->field_text_58.horizontal_alignment.set_constant();
    self->field_text_58.letter_spacing.set_constant();
    self->field_text_58.overflow.set_constant();
    self->field_text_58.stroke.set_constant();
    self->field_text_58.stroke_style.set_constant();
    self->field_text_58.stroke_width.set_constant();
    self->field_text_58.vertical_alignment.set_constant();
    self->field_text_58.wrap.set_constant();
    self->field_text_59.color.set_constant();
    self->field_text_59.font_size.set_constant();
    self->field_text_59.font_weight.set_constant();
    self->field_text_59.horizontal_alignment.set_constant();
    self->field_text_59.vertical_alignment.set_constant();
    self->field_rectangle_62.border_radius.set_constant();
    self->field_toucharea_63.enabled.set_constant();
    self->field_toucharea_63.mouse_cursor.set_constant();
    self->field_text_64.font_size.set_constant();
    self->field_text_64.font_weight.set_constant();
    self->field_text_64.horizontal_alignment.set_constant();
    self->field_text_64.vertical_alignment.set_constant();
    self->field_rectangle_81.background.set_constant();
    self->field_rectangle_81.border_color.set_constant();
    self->field_rectangle_81.border_radius.set_constant();
    self->field_rectangle_81.border_width.set_constant();
    self->field_text_84.color.set_constant();
    self->field_text_84.font_size.set_constant();
    self->field_text_84.font_weight.set_constant();
    self->field_text_84.horizontal_alignment.set_constant();
    self->field_text_84.text.set_constant();
    self->field_text_84.vertical_alignment.set_constant();
    self->repeater_0.set_model_binding([self] { (void)self; return (self->field_root_32_pkg.get().icon.size().width > 0); });
    self->repeater_1.set_model_binding([self] { (void)self; return (std::abs(float(self->field_root_32_pkg.get().icon.size().width - 0)) < std::numeric_limits<float>::epsilon()); });
    self->repeater_2.set_model_binding([self] { (void)self; return [&]{ [[maybe_unused]] auto tmp_root_32_install_state = self->field_root_32_install_state.get();;return ((tmp_root_32_install_state.is_installing || tmp_root_32_install_state.is_uninstalling) || tmp_root_32_install_state.finished); }(); });
    self->repeater_3.set_model_binding([self] { (void)self; return (! self->field_root_32_details.get().is_loading); });
    self->repeater_4.set_model_binding([self] { (void)self; return self->field_root_32_details.get().is_loading; });
    self->repeater_5.set_model_binding([self] { (void)self; return (! self->field_root_32_details.get().is_loading); });
    self->repeater_6.set_model_binding([self] { (void)self; return [&]{ [[maybe_unused]] auto tmp_root_32_details = self->field_root_32_details.get();;return ((! tmp_root_32_details.is_loading) && (slint::private_api::model_length(tmp_root_32_details.dependencies) > 0)); }(); });
    self->repeater_7.set_model_binding([self] { (void)self; return [&]{ [[maybe_unused]] auto tmp_root_32_details = self->field_root_32_details.get();;return ((! tmp_root_32_details.is_loading) && (std::abs(float(slint::private_api::model_length(tmp_root_32_details.dependencies) - 0)) < std::numeric_limits<float>::epsilon())); }(); });
    self->repeater_8.set_model_binding([self] { (void)self; return (slint::private_api::model_length(self->field_root_32_suggestions.get()) > 0); });
    self->repeater_9.set_model_binding([self] { (void)self; return self->field_root_32_show_console.get(); });
    self->repeater_10.set_model_binding([self] { (void)self; return self->field_root_32_show_uninstall_modal.get(); });
}

auto DetailsView_root_32::user_init () -> void{
    [[maybe_unused]] auto self = this;
}

auto DetailsView_root_32::layout_info (slint::cbindgen_private::Orientation o) const -> slint::cbindgen_private::LayoutInfo{
    [[maybe_unused]] auto self = this;
    return o == slint::cbindgen_private::Orientation::Horizontal ? ([&](const auto &a_0, const auto &a_1, const auto &a_2, const auto &a_3, const auto &a_4, const auto &a_5){ slint::cbindgen_private::LayoutInfo o{}; o.max = a_0; o.max_percent = a_1; o.min = a_2; o.min_percent = a_3; o.preferred = a_4; o.stretch = a_5; return o; }(+3.4028234663852886e38, 100, 0, 0, 0, 1) + self->field_root_32_empty_33_layoutinfo_h.get()) : ([&](const auto &a_0, const auto &a_1, const auto &a_2, const auto &a_3, const auto &a_4, const auto &a_5){ slint::cbindgen_private::LayoutInfo o{}; o.max = a_0; o.max_percent = a_1; o.min = a_2; o.min_percent = a_3; o.preferred = a_4; o.stretch = a_5; return o; }(+3.4028234663852886e38, 100, 0, 0, 0, 1) + self->field_root_32_empty_33_layoutinfo_v.get());
}

auto DetailsView_root_32::item_geometry (uint32_t index) const -> slint::cbindgen_private::Rect{
    [[maybe_unused]] auto self = this;
    switch (index) {
        case 0: return slint::private_api::convert_anonymous_rect(std::make_tuple(float(self->field_root_32_height.get()), float(self->field_root_32_width.get()), float(0), float(0)));
        case 1: return slint::private_api::convert_anonymous_rect(std::make_tuple(float(64), float(self->field_root_32_width.get()), float(0), float(self->field_root_32_empty_33_layout_cache.get()[0])));
        case 2: return slint::private_api::convert_anonymous_rect(std::make_tuple(float(self->field_root_32_empty_33_layout_cache.get()[3]), float(self->field_root_32_width.get()), float(0), float(self->field_root_32_empty_33_layout_cache.get()[2])));
        case 5: return slint::private_api::convert_anonymous_rect(std::make_tuple(float(64), float(self->field_root_32_empty_35_layout_cache.get()[1]), float(self->field_root_32_empty_35_layout_cache.get()[0]), float(0)));
        case 6: return slint::private_api::convert_anonymous_rect(std::make_tuple(float(64), float(self->field_root_32_empty_35_layout_cache.get()[3]), float(self->field_root_32_empty_35_layout_cache.get()[2]), float(14)));
        case 7: return slint::private_api::convert_anonymous_rect(std::make_tuple(float(64), float(self->field_root_32_empty_36_layout_cache.get()[1]), float(self->field_root_32_empty_36_layout_cache.get()[0]), float(0)));
        case 8: return slint::private_api::convert_anonymous_rect(std::make_tuple(float(64), float(self->field_root_32_empty_36_layout_cache.get()[3]), float(self->field_root_32_empty_36_layout_cache.get()[2]), float(0)));
        case 9: return slint::private_api::convert_anonymous_rect(std::make_tuple(float(self->field_root_32_empty_38_layout_cache.get()[1]), float(self->field_root_32_empty_36_layout_cache.get()[3]), float(0), float(self->field_root_32_empty_38_layout_cache.get()[0])));
        case 10: return slint::private_api::convert_anonymous_rect(std::make_tuple(float(self->field_root_32_empty_38_layout_cache.get()[3]), float(self->field_root_32_empty_36_layout_cache.get()[3]), float(0), float(self->field_root_32_empty_38_layout_cache.get()[2])));
        case 11: return slint::private_api::convert_anonymous_rect(std::make_tuple(float(36), float(90), float(self->field_root_32_empty_41_layout_cache.get()[0]), float(0)));
        case 12: return slint::private_api::convert_anonymous_rect(std::make_tuple(float(36), float(90), float(0), float(0)));
        case 13: return slint::private_api::convert_anonymous_rect(std::make_tuple(float(self->field_text_44.height.get()), float(self->field_text_44.width.get()), float(((90 -(float) self->field_text_44.width.get()) /(float) 2)), float(((36 -(float) self->field_text_44.height.get()) /(float) 2))));
        case 14: return slint::private_api::convert_anonymous_rect(std::make_tuple(float(self->field_flickable_45.viewport_height.get()), float(self->field_flickable_45.viewport_width.get()), float(self->field_flickable_45.viewport_x.get()), float(self->field_flickable_45.viewport_y.get())));
        case 15: return slint::private_api::convert_anonymous_rect(std::make_tuple(float(self->field_root_32_empty_47_layout_cache.get()[1]), float(((self->field_flickable_45.viewport_width.get() -(float) 64) -(float) 64)), float(64), float(self->field_root_32_empty_47_layout_cache.get()[0])));
        case 17: return slint::private_api::convert_anonymous_rect(std::make_tuple(float(self->field_root_32_empty_47_layout_cache.get()[5]), float(((self->field_flickable_45.viewport_width.get() -(float) 64) -(float) 64)), float(64), float(self->field_root_32_empty_47_layout_cache.get()[4])));
        case 23: return slint::private_api::convert_anonymous_rect(std::make_tuple(float(self->field_root_32_empty_47_layout_cache.get()[1]), float(self->field_root_32_empty_48_layout_cache.get()[5]), float(self->field_root_32_empty_48_layout_cache.get()[4]), float(0)));
        case 24: return slint::private_api::convert_anonymous_rect(std::make_tuple(float(self->field_root_32_empty_47_layout_cache.get()[1]), float(self->field_root_32_empty_48_layout_cache.get()[7]), float(self->field_root_32_empty_48_layout_cache.get()[6]), float(0)));
        case 25: return slint::private_api::convert_anonymous_rect(std::make_tuple(float(self->field_root_32_empty_47_layout_cache.get()[1]), float(self->field_root_32_empty_48_layout_cache.get()[9]), float(self->field_root_32_empty_48_layout_cache.get()[8]), float(0)));
        case 26: return slint::private_api::convert_anonymous_rect(std::make_tuple(float(self->field_root_32_empty_53_layout_cache.get()[1]), float(self->field_root_32_empty_48_layout_cache.get()[5]), float(0), float(self->field_root_32_empty_53_layout_cache.get()[0])));
        case 27: return slint::private_api::convert_anonymous_rect(std::make_tuple(float(self->field_root_32_empty_53_layout_cache.get()[3]), float(self->field_root_32_empty_48_layout_cache.get()[5]), float(0), float(self->field_root_32_empty_53_layout_cache.get()[2])));
        case 28: return slint::private_api::convert_anonymous_rect(std::make_tuple(float(self->field_root_32_empty_53_layout_cache.get()[5]), float(self->field_root_32_empty_48_layout_cache.get()[5]), float(0), float(self->field_root_32_empty_53_layout_cache.get()[4])));
        case 29: return slint::private_api::convert_anonymous_rect(std::make_tuple(float(self->field_root_32_empty_53_layout_cache.get()[1]), float(self->field_root_32_empty_54_layout_cache.get()[1]), float(self->field_root_32_empty_54_layout_cache.get()[0]), float(0)));
        case 30: return slint::private_api::convert_anonymous_rect(std::make_tuple(float(24), float((self->field_instTxt_57.width.get() + 20)), float(self->field_root_32_empty_54_layout_cache.get()[2]), float(3)));
        case 31: return slint::private_api::convert_anonymous_rect(std::make_tuple(float(self->field_instTxt_57.height.get()), float(self->field_instTxt_57.width.get()), float(self->field_root_32_instTxt_57_x.get()), float(((24 -(float) self->field_instTxt_57.height.get()) /(float) 2))));
        case 32: return slint::private_api::convert_anonymous_rect(std::make_tuple(float(44), float(152), float(0), float(self->field_root_32_empty_61_layout_cache.get()[0])));
        case 33: return slint::private_api::convert_anonymous_rect(std::make_tuple(float(44), float(152), float(0), float(0)));
        case 34: return slint::private_api::convert_anonymous_rect(std::make_tuple(float(self->field_text_64.height.get()), float(self->field_text_64.width.get()), float(((152 -(float) self->field_text_64.width.get()) /(float) 2)), float(((44 -(float) self->field_text_64.height.get()) /(float) 2))));
        case 35: return slint::private_api::convert_anonymous_rect(std::make_tuple(float(self->field_root_32_empty_82_layout_cache.get()[1]), float(((((self->field_flickable_45.viewport_width.get() -(float) 64) -(float) 64) -(float) 26) -(float) 26)), float(26), float(self->field_root_32_empty_82_layout_cache.get()[0])));
        case 38: return slint::private_api::convert_anonymous_rect(std::make_tuple(float(self->field_root_32_empty_82_layout_cache.get()[1]), float(self->field_root_32_empty_83_layout_cache.get()[1]), float(self->field_root_32_empty_83_layout_cache.get()[0]), float(0)));
    }
    return {};
}

auto DetailsView_root_32::accessible_role (uint32_t index) const -> slint::cbindgen_private::AccessibleRole{
    [[maybe_unused]] auto self = this;
    switch (index) {
        case 7: return slint::cbindgen_private::AccessibleRole::Text;
        case 9: return slint::cbindgen_private::AccessibleRole::Text;
        case 10: return slint::cbindgen_private::AccessibleRole::Text;
        case 13: return slint::cbindgen_private::AccessibleRole::Text;
        case 27: return slint::cbindgen_private::AccessibleRole::Text;
        case 28: return slint::cbindgen_private::AccessibleRole::Text;
        case 29: return slint::cbindgen_private::AccessibleRole::Text;
        case 31: return slint::cbindgen_private::AccessibleRole::Text;
        case 34: return slint::cbindgen_private::AccessibleRole::Text;
        case 38: return slint::cbindgen_private::AccessibleRole::Text;
    }
    return {};
}

auto DetailsView_root_32::accessible_string_property (uint32_t index, slint::cbindgen_private::AccessibleStringProperty what) const -> std::optional<slint::SharedString>{
    [[maybe_unused]] auto self = this;
    switch ((index << 8) | uintptr_t(what)) {
        case (7 << 8) | uintptr_t(slint::cbindgen_private::AccessibleStringProperty::Label): return slint::SharedString(u8"\U0001f427");
        case (9 << 8) | uintptr_t(slint::cbindgen_private::AccessibleStringProperty::Label): return slint::SharedString(u8"Tux Store");
        case (10 << 8) | uintptr_t(slint::cbindgen_private::AccessibleStringProperty::Label): return slint::SharedString(u8"for Arch Linux");
        case (13 << 8) | uintptr_t(slint::cbindgen_private::AccessibleStringProperty::Label): return slint::SharedString(u8"\U000027e8 Back");
        case (27 << 8) | uintptr_t(slint::cbindgen_private::AccessibleStringProperty::Label): return self->field_root_32_pkg.get().description;
        case (28 << 8) | uintptr_t(slint::cbindgen_private::AccessibleStringProperty::Label): return self->field_text_59.text.get();
        case (29 << 8) | uintptr_t(slint::cbindgen_private::AccessibleStringProperty::Label): return self->field_root_32_pkg.get().pretty_name;
        case (31 << 8) | uintptr_t(slint::cbindgen_private::AccessibleStringProperty::Label): return self->field_instTxt_57.text.get();
        case (34 << 8) | uintptr_t(slint::cbindgen_private::AccessibleStringProperty::Label): return self->field_text_64.text.get();
        case (38 << 8) | uintptr_t(slint::cbindgen_private::AccessibleStringProperty::Label): return slint::SharedString(u8"What you'll download");
    }
    return {};
}

auto DetailsView_root_32::accessibility_action (uint32_t index, const slint::cbindgen_private::AccessibilityAction &action) const -> void{
    [[maybe_unused]] auto self = this;
    switch ((index << 8) | uintptr_t(action.tag)) {
    }
    return ;
}

auto DetailsView_root_32::supported_accessibility_actions (uint32_t index) const -> uint32_t{
    [[maybe_unused]] auto self = this;
    switch (index) {
    }
    return {};
}

auto DetailsView_root_32::element_infos (uint32_t index) const -> std::optional<slint::SharedString>{
    [[maybe_unused]] auto self = this;
    switch (index) {
    }
    return {};
}

auto DetailsView_root_32::ensure_instantiated () const -> bool{
    [[maybe_unused]] auto self = this;
    bool _changed = false;
    _changed |= self->repeater_0.ensure_updated(self);
    _changed |= self->repeater_1.ensure_updated(self);
    _changed |= self->repeater_2.ensure_updated(self);
    _changed |= self->repeater_3.ensure_updated(self);
    _changed |= self->repeater_4.ensure_updated(self);
    _changed |= self->repeater_5.ensure_updated(self);
    _changed |= self->repeater_6.ensure_updated(self);
    _changed |= self->repeater_7.ensure_updated(self);
    _changed |= self->repeater_8.ensure_updated(self);
    _changed |= self->repeater_9.ensure_updated(self);
    _changed |= self->repeater_10.ensure_updated(self);
    return _changed;
}

auto DetailsView_root_32::visit_dynamic_children (uint32_t dyn_index, [[maybe_unused]] slint::private_api::TraversalOrder order, [[maybe_unused]] slint::private_api::ItemVisitorRefMut visitor) const -> uint64_t{
        auto self = this;
        switch(dyn_index) { 
        case 0: {
                return self->repeater_0.visit(order, visitor);
            }
        case 1: {
                return self->repeater_1.visit(order, visitor);
            }
        case 2: {
                return self->repeater_2.visit(order, visitor);
            }
        case 3: {
                return self->repeater_3.visit(order, visitor);
            }
        case 4: {
                return self->repeater_4.visit(order, visitor);
            }
        case 5: {
                return self->repeater_5.visit(order, visitor);
            }
        case 6: {
                return self->repeater_6.visit(order, visitor);
            }
        case 7: {
                return self->repeater_7.visit(order, visitor);
            }
        case 8: {
                return self->repeater_8.visit(order, visitor);
            }
        case 9: {
                return self->repeater_9.visit(order, visitor);
            }
        case 10: {
                return self->repeater_10.visit(order, visitor);
            } };
        std::abort();
}

auto DetailsView_root_32::subtree_range (uintptr_t dyn_index) const -> slint::private_api::IndexRange{
    [[maybe_unused]] auto self = this;
        switch(dyn_index) { 
        case 0: {
                self->repeater_0.track_instance_changes();
                return self->repeater_0.index_range();
            }
        case 1: {
                self->repeater_1.track_instance_changes();
                return self->repeater_1.index_range();
            }
        case 2: {
                self->repeater_2.track_instance_changes();
                return self->repeater_2.index_range();
            }
        case 3: {
                self->repeater_3.track_instance_changes();
                return self->repeater_3.index_range();
            }
        case 4: {
                self->repeater_4.track_instance_changes();
                return self->repeater_4.index_range();
            }
        case 5: {
                self->repeater_5.track_instance_changes();
                return self->repeater_5.index_range();
            }
        case 6: {
                self->repeater_6.track_instance_changes();
                return self->repeater_6.index_range();
            }
        case 7: {
                self->repeater_7.track_instance_changes();
                return self->repeater_7.index_range();
            }
        case 8: {
                self->repeater_8.track_instance_changes();
                return self->repeater_8.index_range();
            }
        case 9: {
                self->repeater_9.track_instance_changes();
                return self->repeater_9.index_range();
            }
        case 10: {
                self->repeater_10.track_instance_changes();
                return self->repeater_10.index_range();
            } };
        std::abort();
}

auto DetailsView_root_32::subtree_component (uintptr_t dyn_index, [[maybe_unused]] uintptr_t subtree_index, [[maybe_unused]] slint::private_api::ItemTreeWeak *result) const -> void{
    [[maybe_unused]] auto self = this;
        switch(dyn_index) { 
        case 0: {
                *result = self->repeater_0.instance_at(subtree_index);
                return;
            }
        case 1: {
                *result = self->repeater_1.instance_at(subtree_index);
                return;
            }
        case 2: {
                *result = self->repeater_2.instance_at(subtree_index);
                return;
            }
        case 3: {
                *result = self->repeater_3.instance_at(subtree_index);
                return;
            }
        case 4: {
                *result = self->repeater_4.instance_at(subtree_index);
                return;
            }
        case 5: {
                *result = self->repeater_5.instance_at(subtree_index);
                return;
            }
        case 6: {
                *result = self->repeater_6.instance_at(subtree_index);
                return;
            }
        case 7: {
                *result = self->repeater_7.instance_at(subtree_index);
                return;
            }
        case 8: {
                *result = self->repeater_8.instance_at(subtree_index);
                return;
            }
        case 9: {
                *result = self->repeater_9.instance_at(subtree_index);
                return;
            }
        case 10: {
                *result = self->repeater_10.instance_at(subtree_index);
                return;
            } };
        std::abort();
}

Theme_219::Theme_219 (const class SharedGlobals *globals)
 : globals(globals)
{
}

auto Theme_219::init () -> void{
    (void)this->globals;
    this->field_accents.set_binding([this]() {
                            [[maybe_unused]] auto self = this;
                            return std::make_shared<slint::private_api::ArrayModel<14,slint::Color>>(slint::Color ( slint::Color::from_argb_encoded(+4.287214842e9) ), slint::Color ( slint::Color::from_argb_encoded(+4.291536631e9) ), slint::Color ( slint::Color::from_argb_encoded(+4.285843436e9) ), slint::Color ( slint::Color::from_argb_encoded(+4.290035454e9) ), slint::Color ( slint::Color::from_argb_encoded(+4.287947477e9) ), slint::Color ( slint::Color::from_argb_encoded(+4.289127329e9) ), slint::Color ( slint::Color::from_argb_encoded(+4.294566575e9) ), slint::Color ( slint::Color::from_argb_encoded(+4.294620039e9) ), slint::Color ( slint::Color::from_argb_encoded(+4.293632172e9) ), slint::Color ( slint::Color::from_argb_encoded(+4.29415108e9) ), slint::Color ( slint::Color::from_argb_encoded(+4.294102477e9) ), slint::Color ( slint::Color::from_argb_encoded(+4.294296295e9) ), slint::Color ( slint::Color::from_argb_encoded(+4.287225067e9) ), slint::Color ( slint::Color::from_argb_encoded(+4.294303964e9) ));
                        });
}

FluentPalette_221::FluentPalette_221 (const class SharedGlobals *globals)
 : globals(globals)
{
}

auto FluentPalette_221::init () -> void{
    (void)this->globals;
    this->field_color_scheme.set_binding([this]() {
                            [[maybe_unused]] auto self = this;
                            return [&]{ auto _root = (*this->globals->root_weak.lock()).into_dyn(); return slint::cbindgen_private::slint_context_color_scheme(&_root); }();
                        });
    this->field_dark_color_scheme.set_binding([this]() {
                            [[maybe_unused]] auto self = this;
                            return [&]{ [[maybe_unused]] auto tmp_FluentPalette_221_color_scheme = this->field_color_scheme.get();;return (! (tmp_FluentPalette_221_color_scheme == slint::cbindgen_private::ColorScheme::Unknown) ? (tmp_FluentPalette_221_color_scheme == slint::cbindgen_private::ColorScheme::Dark) : ([&]{ auto _root = (*this->globals->root_weak.lock()).into_dyn(); return slint::cbindgen_private::slint_context_color_scheme(&_root); }() == slint::cbindgen_private::ColorScheme::Dark)); }();
                        });
    this->field_foreground.set_binding([this]() {
                            [[maybe_unused]] auto self = this;
                            return slint::Brush((this->field_dark_color_scheme.get() ? slint::Color::from_argb_encoded(+4.294967295e9) : slint::Color::from_argb_encoded(+3.85875968e9)));
                        });
    this->field_selection_background.set_binding([this]() {
                            [[maybe_unused]] auto self = this;
                            return slint::Brush(this->fn_accentify(slint::Color::from_argb_encoded(+4.278221012e9)));
                        });
    this->field_selection_foreground.set_binding([this]() {
                            [[maybe_unused]] auto self = this;
                            return slint::Brush((this->field_dark_color_scheme.get() ? slint::Color::from_argb_encoded(+4.27819008e9) : slint::Color::from_argb_encoded(+4.294967295e9)));
                        });
}

auto FluentPalette_221::fn_accentify ([[maybe_unused]] slint::Color arg_0) const -> slint::Color{
    [[maybe_unused]] auto self = this;
    return [&]{ [[maybe_unused]] auto local_accent_color = [&]{ auto _root = (*this->globals->root_weak.lock()).into_dyn(); slint::Color col; slint::cbindgen_private::slint_context_accent_color(&_root, &col); return col; }();;return (! (local_accent_color.to_argb_uint().alpha > 0) ? arg_0 : [&]{ [[maybe_unused]] auto local_default_lch = arg_0.to_oklch();;[[maybe_unused]] auto local_accent_lch = local_accent_color.to_oklch();;return slint::Color::from_oklch(std::clamp(static_cast<float>(local_default_lch.lightness), 0.f, 1.f), std::max(static_cast<float>(local_accent_lch.chroma), 0.f), static_cast<float>(local_accent_lch.hue), std::clamp(static_cast<float>(1), 0.f, 1.f)); }()); }();
}

const slint::private_api::ItemTreeVTable Component_appcard_214::static_vtable = { visit_children, get_item_ref, get_subtree_range, get_subtree, get_item_tree, parent_node, embed_component, subtree_index, layout_info, ensure_instantiated, item_geometry, accessible_role, accessible_string_property, accessibility_action, supported_accessibility_actions, element_infos, window_adapter, slint::private_api::drop_in_place<Component_appcard_214>, slint::private_api::dealloc };

auto Component_appcard_214::init (const class SharedGlobals* globals,slint::cbindgen_private::ItemTreeWeak enclosing_component,uint32_t tree_index,uint32_t tree_index_of_first_child,class Component_empty_197 const *parent) -> void{
    auto self = this;
    self->self_weak = enclosing_component;
    self->globals = globals;
    this->tree_index_of_first_child = tree_index_of_first_child;
    self->tree_index = tree_index;
    self->parent = vtable::VRcMapped<slint::private_api::ItemTreeVTable, const Component_empty_197>(parent->self_weak.lock().value(), parent);
    this->field_appcard_214.init(globals, self_weak.into_dyn(), tree_index, tree_index_of_first_child + 1 - 1);
    self->field_appcard_214.field_root_1_accent_idx.set_binding([this]() {
                            [[maybe_unused]] auto self = this;
                            return self->field_model_index.get();
                        });
    self->field_appcard_214.field_root_1_clicked.set_handler(
                [this]() {
                    [[maybe_unused]] auto self = this;
                    slint::private_api::optional_then(slint::private_api::optional_and_then(self->parent.lock(), [&](auto&&x) { return x->parent.lock(); }), [&](auto&&x) { x->field_root_196_app_clicked.call(self->field_model_data.get()); });
                });
    self->field_appcard_214.field_root_1_height.set(180);
    self->field_appcard_214.field_root_1_pkg.set_binding([this]() {
                            [[maybe_unused]] auto self = this;
                            return self->field_model_data.get();
                        });
    self->field_appcard_214.field_root_1_width.set(200);
    self->field_appcard_214.field_root_1_x.set_binding([this]() {
                            [[maybe_unused]] auto self = this;
                            return (24 + (([](float a, float b) { auto r = std::fmod(a, b); return r >= 0 ? r : r + std::abs(b); })(self->field_model_index.get(),static_cast<int>(std::max<float>(1, std::floor((((slint::private_api::optional_or_default(slint::private_api::optional_transform(slint::private_api::optional_and_then(self->parent.lock(), [&](auto&&x) { return x->parent.lock(); }), [&](auto&&x) { return x->field_root_196.width.get(); })) -(float) 48) + 16) /(float) 216))))) * 216));
                        });
    self->field_appcard_214.field_root_1_y.set_binding([this]() {
                            [[maybe_unused]] auto self = this;
                            return (24 + (std::floor((self->field_model_index.get() /(float) static_cast<int>(std::max<float>(1, std::floor((((slint::private_api::optional_or_default(slint::private_api::optional_transform(slint::private_api::optional_and_then(self->parent.lock(), [&](auto&&x) { return x->parent.lock(); }), [&](auto&&x) { return x->field_root_196.width.get(); })) -(float) 48) + 16) /(float) 216)))))) * 196));
                        });
    self->field_appcard_214.field_root_1.border_radius.set_constant();
    self->field_appcard_214.field_root_1.border_width.set_constant();
    self->field_appcard_214.field_root_1_empty_3_alignment.set_constant();
    self->field_appcard_214.field_root_1_empty_3_padding.set_constant();
    self->field_appcard_214.field_root_1_empty_3_spacing.set_constant();
    self->field_appcard_214.field_root_1_height.set_constant();
    self->field_appcard_214.field_root_1_width.set_constant();
}

auto Component_appcard_214::user_init () -> void{
    [[maybe_unused]] auto self = this;
    this->field_appcard_214.user_init();
}

auto Component_appcard_214::layout_info (slint::cbindgen_private::Orientation o) const -> slint::cbindgen_private::LayoutInfo{
    [[maybe_unused]] auto self = this;
    return o == slint::cbindgen_private::Orientation::Horizontal ? ([&](const auto &a_0, const auto &a_1, const auto &a_2, const auto &a_3, const auto &a_4, const auto &a_5){ slint::cbindgen_private::LayoutInfo o{}; o.max = a_0; o.max_percent = a_1; o.min = a_2; o.min_percent = a_3; o.preferred = a_4; o.stretch = a_5; return o; }(+3.4028234663852886e38, 100, 0, 0, 0, 1) + self->field_appcard_214.field_root_1_empty_3_layoutinfo_h.get()) : ([&](const auto &a_0, const auto &a_1, const auto &a_2, const auto &a_3, const auto &a_4, const auto &a_5){ slint::cbindgen_private::LayoutInfo o{}; o.max = a_0; o.max_percent = a_1; o.min = a_2; o.min_percent = a_3; o.preferred = a_4; o.stretch = a_5; return o; }(+3.4028234663852886e38, 100, 0, 0, 0, 1) + self->field_appcard_214.field_root_1_empty_3_layoutinfo_v.get());
}

auto Component_appcard_214::item_geometry (uint32_t index) const -> slint::cbindgen_private::Rect{
    [[maybe_unused]] auto self = this;
    switch (index) {
        case 0: return slint::private_api::convert_anonymous_rect(std::make_tuple(float(180), float(200), float(self->field_appcard_214.field_root_1_x.get()), float(self->field_appcard_214.field_root_1_y.get())));
    }
    if (index == 0) {
        return self->field_appcard_214.item_geometry(0);
    } else if (index >= 1 && index < 9) {
        return self->field_appcard_214.item_geometry(index - 0);
    } else return {};
}

auto Component_appcard_214::accessible_role (uint32_t index) const -> slint::cbindgen_private::AccessibleRole{
    [[maybe_unused]] auto self = this;
    switch (index) {
    }
    if (index == 0) {
        return self->field_appcard_214.accessible_role(0);
    } else if (index >= 1 && index < 9) {
        return self->field_appcard_214.accessible_role(index - 0);
    } else return {};
}

auto Component_appcard_214::accessible_string_property (uint32_t index, slint::cbindgen_private::AccessibleStringProperty what) const -> std::optional<slint::SharedString>{
    [[maybe_unused]] auto self = this;
    switch ((index << 8) | uintptr_t(what)) {
    }
    if (index == 0) {
        return self->field_appcard_214.accessible_string_property(0, what);
    } else if (index >= 1 && index < 9) {
        return self->field_appcard_214.accessible_string_property(index - 0, what);
    } else return {};
}

auto Component_appcard_214::accessibility_action (uint32_t index, const slint::cbindgen_private::AccessibilityAction &action) const -> void{
    [[maybe_unused]] auto self = this;
    switch ((index << 8) | uintptr_t(action.tag)) {
    }
    if (index == 0) {
        return self->field_appcard_214.accessibility_action(0, action);
    } else if (index >= 1 && index < 9) {
        return self->field_appcard_214.accessibility_action(index - 0, action);
    } else return ;
}

auto Component_appcard_214::supported_accessibility_actions (uint32_t index) const -> uint32_t{
    [[maybe_unused]] auto self = this;
    switch (index) {
    }
    if (index == 0) {
        return self->field_appcard_214.supported_accessibility_actions(0);
    } else if (index >= 1 && index < 9) {
        return self->field_appcard_214.supported_accessibility_actions(index - 0);
    } else return {};
}

auto Component_appcard_214::element_infos (uint32_t index) const -> std::optional<slint::SharedString>{
    [[maybe_unused]] auto self = this;
    switch (index) {
    }
    if (index == 0) {
        return self->field_appcard_214.element_infos(0);
    } else if (index >= 1 && index < 9) {
        return self->field_appcard_214.element_infos(index - 0);
    } else return {};
}

auto Component_appcard_214::ensure_instantiated () const -> bool{
    [[maybe_unused]] auto self = this;
    bool _changed = false;
    _changed |= self->field_appcard_214.ensure_instantiated();
    return _changed;
}

auto Component_appcard_214::visit_dynamic_children (uint32_t dyn_index, [[maybe_unused]] slint::private_api::TraversalOrder order, [[maybe_unused]] slint::private_api::ItemVisitorRefMut visitor) const -> uint64_t{
        auto self = this;
        switch(dyn_index) { 
        case 0: case 1:  {
                        return self->field_appcard_214.visit_dynamic_children(dyn_index - 0, order, visitor);
                    } };
        std::abort();
}

auto Component_appcard_214::subtree_range (uintptr_t dyn_index) const -> slint::private_api::IndexRange{
    [[maybe_unused]] auto self = this;
        switch(dyn_index) { 
        case 0: case 1:  {
                        return self->field_appcard_214.subtree_range(dyn_index - 0);
                    } };
        std::abort();
}

auto Component_appcard_214::subtree_component (uintptr_t dyn_index, [[maybe_unused]] uintptr_t subtree_index, [[maybe_unused]] slint::private_api::ItemTreeWeak *result) const -> void{
    [[maybe_unused]] auto self = this;
        switch(dyn_index) { 
        case 0: case 1:  {
                        self->field_appcard_214.subtree_component(dyn_index - 0, subtree_index, result);
                        return;
                    } };
        std::abort();
}

auto Component_appcard_214::visit_children (slint::private_api::ItemTreeRef component, intptr_t index, slint::private_api::TraversalOrder order, slint::private_api::ItemVisitorRefMut visitor) -> uint64_t{
    static const auto dyn_visit = [] (const void *base,  [[maybe_unused]] slint::private_api::TraversalOrder order, [[maybe_unused]] slint::private_api::ItemVisitorRefMut visitor, [[maybe_unused]] uint32_t dyn_index) -> uint64_t {
        [[maybe_unused]] auto self = reinterpret_cast<const Component_appcard_214*>(base);
        return self->visit_dynamic_children(dyn_index, order, visitor);
    };
    auto self_rc = reinterpret_cast<const Component_appcard_214*>(component.instance)->self_weak.lock()->into_dyn();
    return slint::cbindgen_private::slint_visit_item_tree(&self_rc, get_item_tree(component) , index, order, visitor, dyn_visit);
}

auto Component_appcard_214::get_item_ref (slint::private_api::ItemTreeRef component, uint32_t index) -> slint::private_api::ItemRef{
    return slint::private_api::get_item_ref(component, get_item_tree(component), item_array(), index);
}

auto Component_appcard_214::get_subtree_range ([[maybe_unused]] slint::private_api::ItemTreeRef component, [[maybe_unused]] uint32_t dyn_index) -> slint::private_api::IndexRange{
    auto self = reinterpret_cast<const Component_appcard_214*>(component.instance);
    return self->subtree_range(dyn_index);
}

auto Component_appcard_214::get_subtree ([[maybe_unused]] slint::private_api::ItemTreeRef component, [[maybe_unused]] uint32_t dyn_index, [[maybe_unused]] uintptr_t subtree_index, [[maybe_unused]] slint::private_api::ItemTreeWeak *result) -> void{
    auto self = reinterpret_cast<const Component_appcard_214*>(component.instance);
    self->subtree_component(dyn_index, subtree_index, result);
}

auto Component_appcard_214::get_item_tree (slint::private_api::ItemTreeRef) -> slint::cbindgen_private::Slice<slint::private_api::ItemTreeNode>{
    return item_tree();
}

auto Component_appcard_214::parent_node ([[maybe_unused]] slint::private_api::ItemTreeRef component, [[maybe_unused]] slint::private_api::ItemWeak *result) -> void{
    auto self = reinterpret_cast<const Component_appcard_214*>(component.instance);
    auto parent = self->parent.lock().value();
    *result = { parent->self_weak, parent->tree_index_of_first_child + 14 };
}

auto Component_appcard_214::embed_component ([[maybe_unused]] slint::private_api::ItemTreeRef component, [[maybe_unused]] const slint::private_api::ItemTreeWeak *parent_component, [[maybe_unused]] const uint32_t parent_index) -> bool{
    return false; /* todo! */
}

auto Component_appcard_214::subtree_index ([[maybe_unused]] slint::private_api::ItemTreeRef component) -> uintptr_t{
    auto self = reinterpret_cast<const Component_appcard_214*>(component.instance);
    return self->field_model_index.get();
}

auto Component_appcard_214::item_tree () -> slint::cbindgen_private::Slice<slint::private_api::ItemTreeNode>{
    static const slint::private_api::ItemTreeNode children[] {
        slint::private_api::make_item_node(3, 1, 0, 0, false), 
slint::private_api::make_item_node(0, 4, 0, 1, false), 
slint::private_api::make_item_node(2, 4, 0, 2, false), 
slint::private_api::make_item_node(3, 6, 0, 3, false), 
slint::private_api::make_dyn_node(0, 2), 
slint::private_api::make_dyn_node(1, 2), 
slint::private_api::make_item_node(0, 9, 3, 4, true), 
slint::private_api::make_item_node(0, 9, 3, 5, true), 
slint::private_api::make_item_node(0, 9, 3, 6, true) };
    return slint::private_api::make_slice(std::span(children));
}

auto Component_appcard_214::item_array () -> const slint::private_api::ItemArray{
    static const slint::private_api::ItemArrayEntry items[] {
        { SLINT_GET_ITEM_VTABLE(BasicBorderRectangleVTable), offsetof(Component_appcard_214, field_appcard_214) +  offsetof(AppCard_root_1, field_root_1) }, 
{ SLINT_GET_ITEM_VTABLE(TouchAreaVTable), offsetof(Component_appcard_214, field_appcard_214) +  offsetof(AppCard_root_1, field_ta_2) }, 
{ SLINT_GET_ITEM_VTABLE(EmptyVTable), offsetof(Component_appcard_214, field_appcard_214) +  offsetof(AppCard_root_1, field_empty_4) }, 
{ SLINT_GET_ITEM_VTABLE(EmptyVTable), offsetof(Component_appcard_214, field_appcard_214) +  offsetof(AppCard_root_1, field_empty_10) }, 
{ SLINT_GET_ITEM_VTABLE(ComplexTextVTable), offsetof(Component_appcard_214, field_appcard_214) +  offsetof(AppCard_root_1, field_text_11) }, 
{ SLINT_GET_ITEM_VTABLE(ComplexTextVTable), offsetof(Component_appcard_214, field_appcard_214) +  offsetof(AppCard_root_1, field_text_12) }, 
{ SLINT_GET_ITEM_VTABLE(SimpleTextVTable), offsetof(Component_appcard_214, field_appcard_214) +  offsetof(AppCard_root_1, field_text_13) } };
    return slint::private_api::make_slice(std::span(items));
}

auto Component_appcard_214::layout_info ([[maybe_unused]] slint::private_api::ItemTreeRef component, slint::cbindgen_private::Orientation o) -> slint::cbindgen_private::LayoutInfo{
    return reinterpret_cast<const Component_appcard_214*>(component.instance)->layout_info(o);
}

auto Component_appcard_214::ensure_instantiated ([[maybe_unused]] slint::private_api::ItemTreeRef component) -> bool{
    return reinterpret_cast<const Component_appcard_214*>(component.instance)->ensure_instantiated();
}

auto Component_appcard_214::item_geometry ([[maybe_unused]] slint::private_api::ItemTreeRef component, uint32_t index) -> slint::cbindgen_private::LogicalRect{
    return reinterpret_cast<const Component_appcard_214*>(component.instance)->item_geometry(index);
}

auto Component_appcard_214::accessible_role ([[maybe_unused]] slint::private_api::ItemTreeRef component, uint32_t index) -> slint::cbindgen_private::AccessibleRole{
    return reinterpret_cast<const Component_appcard_214*>(component.instance)->accessible_role(index);
}

auto Component_appcard_214::accessible_string_property ([[maybe_unused]] slint::private_api::ItemTreeRef component, uint32_t index, slint::cbindgen_private::AccessibleStringProperty what, slint::SharedString *result) -> bool{
    if (auto r = reinterpret_cast<const Component_appcard_214*>(component.instance)->accessible_string_property(index, what)) { *result = *r; return true; } else { return false; }
}

auto Component_appcard_214::accessibility_action ([[maybe_unused]] slint::private_api::ItemTreeRef component, uint32_t index, const slint::cbindgen_private::AccessibilityAction *action) -> void{
    reinterpret_cast<const Component_appcard_214*>(component.instance)->accessibility_action(index, *action);
}

auto Component_appcard_214::supported_accessibility_actions ([[maybe_unused]] slint::private_api::ItemTreeRef component, uint32_t index) -> uint32_t{
    return reinterpret_cast<const Component_appcard_214*>(component.instance)->supported_accessibility_actions(index);
}

auto Component_appcard_214::element_infos ([[maybe_unused]] slint::private_api::ItemTreeRef component, [[maybe_unused]] uint32_t index, [[maybe_unused]] slint::SharedString *result) -> bool{
    return false;
}

auto Component_appcard_214::window_adapter ([[maybe_unused]] slint::private_api::ItemTreeRef component, [[maybe_unused]] bool do_create, [[maybe_unused]] slint::cbindgen_private::Option<slint::private_api::WindowAdapterRc>* result) -> void{
    *reinterpret_cast<slint::private_api::WindowAdapterRc*>(result) = reinterpret_cast<const Component_appcard_214*>(component.instance)->globals->window().window_handle();
}

auto Component_appcard_214::create (class Component_empty_197 const * parent) -> slint::ComponentHandle<Component_appcard_214>{
    auto self_rc = vtable::VRc<slint::private_api::ItemTreeVTable, Component_appcard_214>::make();
    auto self = const_cast<Component_appcard_214 *>(&*self_rc);
    self->self_weak = vtable::VWeak(self_rc).into_dyn();
    slint::private_api::register_item_tree(&self_rc.into_dyn(), parent->globals->m_window);
    self->init(parent->globals, self->self_weak, 0, 1 , parent);
    return slint::ComponentHandle<Component_appcard_214>{ self_rc };
}

Component_appcard_214::~Component_appcard_214 (){
    if (auto &window = globals->m_window) window->window_handle().unregister_item_tree(this, item_array());
}

auto Component_appcard_214::update_data ([[maybe_unused]] int i, [[maybe_unused]] const UiPackage &data) const -> void{
    [[maybe_unused]] auto self = this;
    self->field_model_index.set(i);
    self->field_model_data.set(data);
}

auto Component_appcard_214::init () -> void{
    user_init();
}

auto Component_appcard_214::layout_item_info (slint::cbindgen_private::Orientation o, [[maybe_unused]] std::optional<size_t> child_index) const -> slint::cbindgen_private::LayoutItemInfo{
    return { layout_info({&static_vtable, const_cast<void *>(static_cast<const void *>(this))}, o) };
}

auto Component_appcard_214::flexbox_layout_item_info (slint::cbindgen_private::Orientation o, [[maybe_unused]] std::optional<size_t> child_index) const -> slint::cbindgen_private::FlexboxLayoutItemInfo{
    auto base = layout_item_info(o, child_index); return { base.constraint, 0.0f, 0.0f, -1.0f, slint::cbindgen_private::FlexboxLayoutAlignSelf::Auto, 0 };
}

const slint::private_api::ItemTreeVTable Component_empty_197::static_vtable = { visit_children, get_item_ref, get_subtree_range, get_subtree, get_item_tree, parent_node, embed_component, subtree_index, layout_info, ensure_instantiated, item_geometry, accessible_role, accessible_string_property, accessibility_action, supported_accessibility_actions, element_infos, window_adapter, slint::private_api::drop_in_place<Component_empty_197>, slint::private_api::dealloc };

auto Component_empty_197::fn_layoutinfo_v_with_constraint ([[maybe_unused]] float arg_0) const -> slint::cbindgen_private::LayoutInfo{
    [[maybe_unused]] auto self = this;
    return slint::private_api::box_layout_info(slint::private_api::make_slice<slint::cbindgen_private::LayoutItemInfo>(std::array<slint::cbindgen_private::LayoutItemInfo, 2>{ slint::cbindgen_private::LayoutItemInfo ( [&](const auto &a_0){ slint::cbindgen_private::LayoutItemInfo o{}; o.constraint = a_0; return o; }([&]{ [[maybe_unused]] auto layout_info = self->field_empty_197_rectangle_198_layoutinfo_v.get();;return [&](const auto &a_0, const auto &a_1, const auto &a_2, const auto &a_3, const auto &a_4, const auto &a_5){ slint::cbindgen_private::LayoutInfo o{}; o.max = a_0; o.max_percent = a_1; o.min = a_2; o.min_percent = a_3; o.preferred = a_4; o.stretch = a_5; return o; }(self->field_empty_197_rectangle_198_height.get(), layout_info.max_percent, self->field_empty_197_rectangle_198_height.get(), layout_info.min_percent, layout_info.preferred, layout_info.stretch); }()) ), slint::cbindgen_private::LayoutItemInfo ( [&](const auto &a_0){ slint::cbindgen_private::LayoutItemInfo o{}; o.constraint = a_0; return o; }(slint::private_api::item_layout_info(SLINT_GET_ITEM_VTABLE(FlickableVTable), const_cast<slint::cbindgen_private::Flickable*>(&self->field_grid_area_212), slint::cbindgen_private::Orientation::Vertical, arg_0, &self->globals->window().window_handle(), self->self_weak.lock()->into_dyn(), self->tree_index_of_first_child + 2 - 1)) ) }.data(), 2),0,[&](const auto &a_0, const auto &a_1){ slint::cbindgen_private::Padding o{}; o.begin = a_0; o.end = a_1; return o; }(0, 0),slint::cbindgen_private::LayoutAlignment::Stretch);
}

auto Component_empty_197::init (const class SharedGlobals* globals,slint::cbindgen_private::ItemTreeWeak enclosing_component,uint32_t tree_index,uint32_t tree_index_of_first_child,class MainWindow const *parent) -> void{
    auto self = this;
    self->self_weak = enclosing_component;
    self->globals = globals;
    this->tree_index_of_first_child = tree_index_of_first_child;
    self->tree_index = tree_index;
    self->parent = vtable::VRcMapped<slint::private_api::ItemTreeVTable, const MainWindow>(parent->self_weak.lock().value(), parent);
    slint::private_api::optional_then(self->parent.lock(), [&](auto&&x) { slint::private_api::Property<slint::SharedString>::link_two_way(&self->field_textinput_211.text, &x->field_root_196_search_query); });
    self->field_empty_197_empty_199_layout_cache.set_binding([this]() {
                            [[maybe_unused]] auto self = this;
                            return slint::private_api::solve_box_layout([&](const auto &a_0, const auto &a_1, const auto &a_2, const auto &a_3, const auto &a_4){ slint::cbindgen_private::BoxLayoutData o{}; o.alignment = a_0; o.cells = a_1; o.padding = a_2; o.size = a_3; o.spacing = a_4; return o; }(slint::cbindgen_private::LayoutAlignment::SpaceBetween, slint::private_api::make_slice<slint::cbindgen_private::LayoutItemInfo>(std::array<slint::cbindgen_private::LayoutItemInfo, 2>{ slint::cbindgen_private::LayoutItemInfo ( [&](const auto &a_0){ slint::cbindgen_private::LayoutItemInfo o{}; o.constraint = a_0; return o; }(self->field_empty_197_empty_200_layoutinfo_h.get()) ), slint::cbindgen_private::LayoutItemInfo ( [&](const auto &a_0){ slint::cbindgen_private::LayoutItemInfo o{}; o.constraint = a_0; return o; }(self->field_empty_197_empty_205_layoutinfo_h.get()) ) }.data(), 2), [&](const auto &a_0, const auto &a_1){ slint::cbindgen_private::Padding o{}; o.begin = a_0; o.end = a_1; return o; }(24, 24), self->field_empty_197_rectangle_198_width.get(), 0),slint::private_api::make_slice<int>(std::array<int, 0>{  }.data(), 0));
                        });
    self->field_empty_197_empty_199_layoutinfo_h.set_binding([this]() {
                            [[maybe_unused]] auto self = this;
                            return slint::private_api::box_layout_info(slint::private_api::make_slice<slint::cbindgen_private::LayoutItemInfo>(std::array<slint::cbindgen_private::LayoutItemInfo, 2>{ slint::cbindgen_private::LayoutItemInfo ( [&](const auto &a_0){ slint::cbindgen_private::LayoutItemInfo o{}; o.constraint = a_0; return o; }(self->field_empty_197_empty_200_layoutinfo_h.get()) ), slint::cbindgen_private::LayoutItemInfo ( [&](const auto &a_0){ slint::cbindgen_private::LayoutItemInfo o{}; o.constraint = a_0; return o; }(self->field_empty_197_empty_205_layoutinfo_h.get()) ) }.data(), 2),0,[&](const auto &a_0, const auto &a_1){ slint::cbindgen_private::Padding o{}; o.begin = a_0; o.end = a_1; return o; }(24, 24),slint::cbindgen_private::LayoutAlignment::SpaceBetween);
                        });
    self->field_empty_197_empty_199_layoutinfo_v.set_binding([this]() {
                            [[maybe_unused]] auto self = this;
                            return slint::private_api::box_layout_info_ortho(slint::private_api::make_slice<slint::cbindgen_private::LayoutItemInfo>(std::array<slint::cbindgen_private::LayoutItemInfo, 2>{ slint::cbindgen_private::LayoutItemInfo ( [&](const auto &a_0){ slint::cbindgen_private::LayoutItemInfo o{}; o.constraint = a_0; return o; }(self->field_empty_197_empty_200_layoutinfo_v.get()) ), slint::cbindgen_private::LayoutItemInfo ( [&](const auto &a_0){ slint::cbindgen_private::LayoutItemInfo o{}; o.constraint = a_0; return o; }(self->field_empty_197_empty_205_layoutinfo_v.get()) ) }.data(), 2),[&](const auto &a_0, const auto &a_1){ slint::cbindgen_private::Padding o{}; o.begin = a_0; o.end = a_1; return o; }(0, 0));
                        });
    self->field_empty_197_empty_200_layout_cache.set_binding([this]() {
                            [[maybe_unused]] auto self = this;
                            return slint::private_api::solve_box_layout([&](const auto &a_0, const auto &a_1, const auto &a_2, const auto &a_3, const auto &a_4){ slint::cbindgen_private::BoxLayoutData o{}; o.alignment = a_0; o.cells = a_1; o.padding = a_2; o.size = a_3; o.spacing = a_4; return o; }(slint::cbindgen_private::LayoutAlignment::Start, slint::private_api::make_slice<slint::cbindgen_private::LayoutItemInfo>(std::array<slint::cbindgen_private::LayoutItemInfo, 2>{ slint::cbindgen_private::LayoutItemInfo ( [&](const auto &a_0){ slint::cbindgen_private::LayoutItemInfo o{}; o.constraint = a_0; return o; }(slint::private_api::item_layout_info(SLINT_GET_ITEM_VTABLE(SimpleTextVTable), const_cast<slint::cbindgen_private::SimpleText*>(&self->field_text_201), slint::cbindgen_private::Orientation::Horizontal, -1, &self->globals->window().window_handle(), self->self_weak.lock()->into_dyn(), self->tree_index_of_first_child + 5 - 1)) ), slint::cbindgen_private::LayoutItemInfo ( [&](const auto &a_0){ slint::cbindgen_private::LayoutItemInfo o{}; o.constraint = a_0; return o; }(self->field_empty_197_empty_202_layoutinfo_h.get()) ) }.data(), 2), [&](const auto &a_0, const auto &a_1){ slint::cbindgen_private::Padding o{}; o.begin = a_0; o.end = a_1; return o; }(0, 0), self->field_empty_197_empty_199_layout_cache.get()[1], 10),slint::private_api::make_slice<int>(std::array<int, 0>{  }.data(), 0));
                        });
    self->field_empty_197_empty_200_layoutinfo_h.set_binding([this]() {
                            [[maybe_unused]] auto self = this;
                            return slint::private_api::box_layout_info(slint::private_api::make_slice<slint::cbindgen_private::LayoutItemInfo>(std::array<slint::cbindgen_private::LayoutItemInfo, 2>{ slint::cbindgen_private::LayoutItemInfo ( [&](const auto &a_0){ slint::cbindgen_private::LayoutItemInfo o{}; o.constraint = a_0; return o; }(slint::private_api::item_layout_info(SLINT_GET_ITEM_VTABLE(SimpleTextVTable), const_cast<slint::cbindgen_private::SimpleText*>(&self->field_text_201), slint::cbindgen_private::Orientation::Horizontal, -1, &self->globals->window().window_handle(), self->self_weak.lock()->into_dyn(), self->tree_index_of_first_child + 5 - 1)) ), slint::cbindgen_private::LayoutItemInfo ( [&](const auto &a_0){ slint::cbindgen_private::LayoutItemInfo o{}; o.constraint = a_0; return o; }(self->field_empty_197_empty_202_layoutinfo_h.get()) ) }.data(), 2),10,[&](const auto &a_0, const auto &a_1){ slint::cbindgen_private::Padding o{}; o.begin = a_0; o.end = a_1; return o; }(0, 0),slint::cbindgen_private::LayoutAlignment::Start);
                        });
    self->field_empty_197_empty_200_layoutinfo_v.set_binding([this]() {
                            [[maybe_unused]] auto self = this;
                            return slint::private_api::box_layout_info_ortho(slint::private_api::make_slice<slint::cbindgen_private::LayoutItemInfo>(std::array<slint::cbindgen_private::LayoutItemInfo, 2>{ slint::cbindgen_private::LayoutItemInfo ( [&](const auto &a_0){ slint::cbindgen_private::LayoutItemInfo o{}; o.constraint = a_0; return o; }(slint::private_api::item_layout_info(SLINT_GET_ITEM_VTABLE(SimpleTextVTable), const_cast<slint::cbindgen_private::SimpleText*>(&self->field_text_201), slint::cbindgen_private::Orientation::Vertical, -1, &self->globals->window().window_handle(), self->self_weak.lock()->into_dyn(), self->tree_index_of_first_child + 5 - 1)) ), slint::cbindgen_private::LayoutItemInfo ( [&](const auto &a_0){ slint::cbindgen_private::LayoutItemInfo o{}; o.constraint = a_0; return o; }(self->field_empty_197_empty_202_layoutinfo_v.get()) ) }.data(), 2),[&](const auto &a_0, const auto &a_1){ slint::cbindgen_private::Padding o{}; o.begin = a_0; o.end = a_1; return o; }(0, 0));
                        });
    self->field_empty_197_empty_202_layout_cache.set_binding([this]() {
                            [[maybe_unused]] auto self = this;
                            return slint::private_api::solve_box_layout([&](const auto &a_0, const auto &a_1, const auto &a_2, const auto &a_3, const auto &a_4){ slint::cbindgen_private::BoxLayoutData o{}; o.alignment = a_0; o.cells = a_1; o.padding = a_2; o.size = a_3; o.spacing = a_4; return o; }(slint::cbindgen_private::LayoutAlignment::Center, slint::private_api::make_slice<slint::cbindgen_private::LayoutItemInfo>(std::array<slint::cbindgen_private::LayoutItemInfo, 2>{ slint::cbindgen_private::LayoutItemInfo ( [&](const auto &a_0){ slint::cbindgen_private::LayoutItemInfo o{}; o.constraint = a_0; return o; }(slint::private_api::item_layout_info(SLINT_GET_ITEM_VTABLE(SimpleTextVTable), const_cast<slint::cbindgen_private::SimpleText*>(&self->field_text_203), slint::cbindgen_private::Orientation::Vertical, -1, &self->globals->window().window_handle(), self->self_weak.lock()->into_dyn(), self->tree_index_of_first_child + 7 - 1)) ), slint::cbindgen_private::LayoutItemInfo ( [&](const auto &a_0){ slint::cbindgen_private::LayoutItemInfo o{}; o.constraint = a_0; return o; }(slint::private_api::item_layout_info(SLINT_GET_ITEM_VTABLE(SimpleTextVTable), const_cast<slint::cbindgen_private::SimpleText*>(&self->field_text_204), slint::cbindgen_private::Orientation::Vertical, -1, &self->globals->window().window_handle(), self->self_weak.lock()->into_dyn(), self->tree_index_of_first_child + 8 - 1)) ) }.data(), 2), [&](const auto &a_0, const auto &a_1){ slint::cbindgen_private::Padding o{}; o.begin = a_0; o.end = a_1; return o; }(0, 0), 64, 0),slint::private_api::make_slice<int>(std::array<int, 0>{  }.data(), 0));
                        });
    self->field_empty_197_empty_202_layoutinfo_h.set_binding([this]() {
                            [[maybe_unused]] auto self = this;
                            return slint::private_api::box_layout_info_ortho(slint::private_api::make_slice<slint::cbindgen_private::LayoutItemInfo>(std::array<slint::cbindgen_private::LayoutItemInfo, 2>{ slint::cbindgen_private::LayoutItemInfo ( [&](const auto &a_0){ slint::cbindgen_private::LayoutItemInfo o{}; o.constraint = a_0; return o; }(slint::private_api::item_layout_info(SLINT_GET_ITEM_VTABLE(SimpleTextVTable), const_cast<slint::cbindgen_private::SimpleText*>(&self->field_text_203), slint::cbindgen_private::Orientation::Horizontal, -1, &self->globals->window().window_handle(), self->self_weak.lock()->into_dyn(), self->tree_index_of_first_child + 7 - 1)) ), slint::cbindgen_private::LayoutItemInfo ( [&](const auto &a_0){ slint::cbindgen_private::LayoutItemInfo o{}; o.constraint = a_0; return o; }(slint::private_api::item_layout_info(SLINT_GET_ITEM_VTABLE(SimpleTextVTable), const_cast<slint::cbindgen_private::SimpleText*>(&self->field_text_204), slint::cbindgen_private::Orientation::Horizontal, -1, &self->globals->window().window_handle(), self->self_weak.lock()->into_dyn(), self->tree_index_of_first_child + 8 - 1)) ) }.data(), 2),[&](const auto &a_0, const auto &a_1){ slint::cbindgen_private::Padding o{}; o.begin = a_0; o.end = a_1; return o; }(0, 0));
                        });
    self->field_empty_197_empty_202_layoutinfo_v.set_binding([this]() {
                            [[maybe_unused]] auto self = this;
                            return slint::private_api::box_layout_info(slint::private_api::make_slice<slint::cbindgen_private::LayoutItemInfo>(std::array<slint::cbindgen_private::LayoutItemInfo, 2>{ slint::cbindgen_private::LayoutItemInfo ( [&](const auto &a_0){ slint::cbindgen_private::LayoutItemInfo o{}; o.constraint = a_0; return o; }(slint::private_api::item_layout_info(SLINT_GET_ITEM_VTABLE(SimpleTextVTable), const_cast<slint::cbindgen_private::SimpleText*>(&self->field_text_203), slint::cbindgen_private::Orientation::Vertical, -1, &self->globals->window().window_handle(), self->self_weak.lock()->into_dyn(), self->tree_index_of_first_child + 7 - 1)) ), slint::cbindgen_private::LayoutItemInfo ( [&](const auto &a_0){ slint::cbindgen_private::LayoutItemInfo o{}; o.constraint = a_0; return o; }(slint::private_api::item_layout_info(SLINT_GET_ITEM_VTABLE(SimpleTextVTable), const_cast<slint::cbindgen_private::SimpleText*>(&self->field_text_204), slint::cbindgen_private::Orientation::Vertical, -1, &self->globals->window().window_handle(), self->self_weak.lock()->into_dyn(), self->tree_index_of_first_child + 8 - 1)) ) }.data(), 2),0,[&](const auto &a_0, const auto &a_1){ slint::cbindgen_private::Padding o{}; o.begin = a_0; o.end = a_1; return o; }(0, 0),slint::cbindgen_private::LayoutAlignment::Center);
                        });
    self->field_empty_197_empty_205_layout_cache.set_binding([this]() {
                            [[maybe_unused]] auto self = this;
                            return slint::private_api::solve_box_layout([&](const auto &a_0, const auto &a_1, const auto &a_2, const auto &a_3, const auto &a_4){ slint::cbindgen_private::BoxLayoutData o{}; o.alignment = a_0; o.cells = a_1; o.padding = a_2; o.size = a_3; o.spacing = a_4; return o; }(slint::cbindgen_private::LayoutAlignment::Stretch, slint::private_api::make_slice<slint::cbindgen_private::LayoutItemInfo>(std::array<slint::cbindgen_private::LayoutItemInfo, 2>{ slint::cbindgen_private::LayoutItemInfo ( [&](const auto &a_0){ slint::cbindgen_private::LayoutItemInfo o{}; o.constraint = a_0; return o; }([&]{ [[maybe_unused]] auto layout_info = self->field_empty_197_rectangle_206_layoutinfo_h.get();;return [&](const auto &a_0, const auto &a_1, const auto &a_2, const auto &a_3, const auto &a_4, const auto &a_5){ slint::cbindgen_private::LayoutInfo o{}; o.max = a_0; o.max_percent = a_1; o.min = a_2; o.min_percent = a_3; o.preferred = a_4; o.stretch = a_5; return o; }(40, layout_info.max_percent, 40, layout_info.min_percent, layout_info.preferred, layout_info.stretch); }()) ), slint::cbindgen_private::LayoutItemInfo ( [&](const auto &a_0){ slint::cbindgen_private::LayoutItemInfo o{}; o.constraint = a_0; return o; }([&]{ [[maybe_unused]] auto layout_info = ([&](const auto &a_0, const auto &a_1, const auto &a_2, const auto &a_3, const auto &a_4, const auto &a_5){ slint::cbindgen_private::LayoutInfo o{}; o.max = a_0; o.max_percent = a_1; o.min = a_2; o.min_percent = a_3; o.preferred = a_4; o.stretch = a_5; return o; }(+3.4028234663852886e38, 100, 0, 0, 0, 1) + self->field_empty_197_empty_210_layoutinfo_h.get());;return [&](const auto &a_0, const auto &a_1, const auto &a_2, const auto &a_3, const auto &a_4, const auto &a_5){ slint::cbindgen_private::LayoutInfo o{}; o.max = a_0; o.max_percent = a_1; o.min = a_2; o.min_percent = a_3; o.preferred = a_4; o.stretch = a_5; return o; }(260, layout_info.max_percent, 260, layout_info.min_percent, layout_info.preferred, layout_info.stretch); }()) ) }.data(), 2), [&](const auto &a_0, const auto &a_1){ slint::cbindgen_private::Padding o{}; o.begin = a_0; o.end = a_1; return o; }(0, 0), self->field_empty_197_empty_199_layout_cache.get()[3], 12),slint::private_api::make_slice<int>(std::array<int, 0>{  }.data(), 0));
                        });
    self->field_empty_197_empty_205_layoutinfo_h.set_binding([this]() {
                            [[maybe_unused]] auto self = this;
                            return slint::private_api::box_layout_info(slint::private_api::make_slice<slint::cbindgen_private::LayoutItemInfo>(std::array<slint::cbindgen_private::LayoutItemInfo, 2>{ slint::cbindgen_private::LayoutItemInfo ( [&](const auto &a_0){ slint::cbindgen_private::LayoutItemInfo o{}; o.constraint = a_0; return o; }([&]{ [[maybe_unused]] auto layout_info = self->field_empty_197_rectangle_206_layoutinfo_h.get();;return [&](const auto &a_0, const auto &a_1, const auto &a_2, const auto &a_3, const auto &a_4, const auto &a_5){ slint::cbindgen_private::LayoutInfo o{}; o.max = a_0; o.max_percent = a_1; o.min = a_2; o.min_percent = a_3; o.preferred = a_4; o.stretch = a_5; return o; }(40, layout_info.max_percent, 40, layout_info.min_percent, layout_info.preferred, layout_info.stretch); }()) ), slint::cbindgen_private::LayoutItemInfo ( [&](const auto &a_0){ slint::cbindgen_private::LayoutItemInfo o{}; o.constraint = a_0; return o; }([&]{ [[maybe_unused]] auto layout_info = ([&](const auto &a_0, const auto &a_1, const auto &a_2, const auto &a_3, const auto &a_4, const auto &a_5){ slint::cbindgen_private::LayoutInfo o{}; o.max = a_0; o.max_percent = a_1; o.min = a_2; o.min_percent = a_3; o.preferred = a_4; o.stretch = a_5; return o; }(+3.4028234663852886e38, 100, 0, 0, 0, 1) + self->field_empty_197_empty_210_layoutinfo_h.get());;return [&](const auto &a_0, const auto &a_1, const auto &a_2, const auto &a_3, const auto &a_4, const auto &a_5){ slint::cbindgen_private::LayoutInfo o{}; o.max = a_0; o.max_percent = a_1; o.min = a_2; o.min_percent = a_3; o.preferred = a_4; o.stretch = a_5; return o; }(260, layout_info.max_percent, 260, layout_info.min_percent, layout_info.preferred, layout_info.stretch); }()) ) }.data(), 2),12,[&](const auto &a_0, const auto &a_1){ slint::cbindgen_private::Padding o{}; o.begin = a_0; o.end = a_1; return o; }(0, 0),slint::cbindgen_private::LayoutAlignment::Stretch);
                        });
    self->field_empty_197_empty_205_layoutinfo_v.set_binding([this]() {
                            [[maybe_unused]] auto self = this;
                            return slint::private_api::box_layout_info_ortho(slint::private_api::make_slice<slint::cbindgen_private::LayoutItemInfo>(std::array<slint::cbindgen_private::LayoutItemInfo, 2>{ slint::cbindgen_private::LayoutItemInfo ( [&](const auto &a_0){ slint::cbindgen_private::LayoutItemInfo o{}; o.constraint = a_0; return o; }([&]{ [[maybe_unused]] auto layout_info = self->field_empty_197_rectangle_206_layoutinfo_v.get();;return [&](const auto &a_0, const auto &a_1, const auto &a_2, const auto &a_3, const auto &a_4, const auto &a_5){ slint::cbindgen_private::LayoutInfo o{}; o.max = a_0; o.max_percent = a_1; o.min = a_2; o.min_percent = a_3; o.preferred = a_4; o.stretch = a_5; return o; }(36, layout_info.max_percent, 36, layout_info.min_percent, layout_info.preferred, layout_info.stretch); }()) ), slint::cbindgen_private::LayoutItemInfo ( [&](const auto &a_0){ slint::cbindgen_private::LayoutItemInfo o{}; o.constraint = a_0; return o; }([&]{ [[maybe_unused]] auto layout_info = ([&](const auto &a_0, const auto &a_1, const auto &a_2, const auto &a_3, const auto &a_4, const auto &a_5){ slint::cbindgen_private::LayoutInfo o{}; o.max = a_0; o.max_percent = a_1; o.min = a_2; o.min_percent = a_3; o.preferred = a_4; o.stretch = a_5; return o; }(+3.4028234663852886e38, 100, 0, 0, 0, 1) + self->field_empty_197_empty_210_layoutinfo_v.get());;return [&](const auto &a_0, const auto &a_1, const auto &a_2, const auto &a_3, const auto &a_4, const auto &a_5){ slint::cbindgen_private::LayoutInfo o{}; o.max = a_0; o.max_percent = a_1; o.min = a_2; o.min_percent = a_3; o.preferred = a_4; o.stretch = a_5; return o; }(36, layout_info.max_percent, 36, layout_info.min_percent, layout_info.preferred, layout_info.stretch); }()) ) }.data(), 2),[&](const auto &a_0, const auto &a_1){ slint::cbindgen_private::Padding o{}; o.begin = a_0; o.end = a_1; return o; }(0, 0));
                        });
    self->field_empty_197_empty_210_layout_cache.set_binding([this]() {
                            [[maybe_unused]] auto self = this;
                            return slint::private_api::solve_box_layout([&](const auto &a_0, const auto &a_1, const auto &a_2, const auto &a_3, const auto &a_4){ slint::cbindgen_private::BoxLayoutData o{}; o.alignment = a_0; o.cells = a_1; o.padding = a_2; o.size = a_3; o.spacing = a_4; return o; }(slint::cbindgen_private::LayoutAlignment::Stretch, slint::private_api::make_slice<slint::cbindgen_private::LayoutItemInfo>(std::array<slint::cbindgen_private::LayoutItemInfo, 1>{ slint::cbindgen_private::LayoutItemInfo ( [&](const auto &a_0){ slint::cbindgen_private::LayoutItemInfo o{}; o.constraint = a_0; return o; }(slint::private_api::item_layout_info(SLINT_GET_ITEM_VTABLE(TextInputVTable), const_cast<slint::cbindgen_private::TextInput*>(&self->field_textinput_211), slint::cbindgen_private::Orientation::Horizontal, -1, &self->globals->window().window_handle(), self->self_weak.lock()->into_dyn(), self->tree_index_of_first_child + 13 - 1)) ) }.data(), 1), [&](const auto &a_0, const auto &a_1){ slint::cbindgen_private::Padding o{}; o.begin = a_0; o.end = a_1; return o; }(12, 12), 260, 0),slint::private_api::make_slice<int>(std::array<int, 0>{  }.data(), 0));
                        });
    self->field_empty_197_empty_210_layoutinfo_h.set_binding([this]() {
                            [[maybe_unused]] auto self = this;
                            return slint::private_api::box_layout_info(slint::private_api::make_slice<slint::cbindgen_private::LayoutItemInfo>(std::array<slint::cbindgen_private::LayoutItemInfo, 1>{ slint::cbindgen_private::LayoutItemInfo ( [&](const auto &a_0){ slint::cbindgen_private::LayoutItemInfo o{}; o.constraint = a_0; return o; }(slint::private_api::item_layout_info(SLINT_GET_ITEM_VTABLE(TextInputVTable), const_cast<slint::cbindgen_private::TextInput*>(&self->field_textinput_211), slint::cbindgen_private::Orientation::Horizontal, -1, &self->globals->window().window_handle(), self->self_weak.lock()->into_dyn(), self->tree_index_of_first_child + 13 - 1)) ) }.data(), 1),0,[&](const auto &a_0, const auto &a_1){ slint::cbindgen_private::Padding o{}; o.begin = a_0; o.end = a_1; return o; }(12, 12),slint::cbindgen_private::LayoutAlignment::Stretch);
                        });
    self->field_empty_197_empty_210_layoutinfo_v.set_binding([this]() {
                            [[maybe_unused]] auto self = this;
                            return slint::private_api::box_layout_info_ortho(slint::private_api::make_slice<slint::cbindgen_private::LayoutItemInfo>(std::array<slint::cbindgen_private::LayoutItemInfo, 1>{ slint::cbindgen_private::LayoutItemInfo ( [&](const auto &a_0){ slint::cbindgen_private::LayoutItemInfo o{}; o.constraint = a_0; return o; }(slint::private_api::item_layout_info(SLINT_GET_ITEM_VTABLE(TextInputVTable), const_cast<slint::cbindgen_private::TextInput*>(&self->field_textinput_211), slint::cbindgen_private::Orientation::Vertical, -1, &self->globals->window().window_handle(), self->self_weak.lock()->into_dyn(), self->tree_index_of_first_child + 13 - 1)) ) }.data(), 1),[&](const auto &a_0, const auto &a_1){ slint::cbindgen_private::Padding o{}; o.begin = a_0; o.end = a_1; return o; }(0, 0));
                        });
    self->field_empty_197_grid_area_212_total_rows.set_binding([this]() {
                            [[maybe_unused]] auto self = this;
                            return [&]{ [[maybe_unused]] auto tmp_root_196_packages = slint::private_api::optional_or_default(slint::private_api::optional_transform(self->parent.lock(), [&](auto&&x) { return x->field_root_196_packages.get(); }));;return static_cast<int>((slint::private_api::model_length(tmp_root_196_packages) > 0 ? [&]{ [[maybe_unused]] auto tmp_empty_197_grid_area_212_cols = static_cast<int>(std::max<float>(1, std::floor((((slint::private_api::optional_or_default(slint::private_api::optional_transform(self->parent.lock(), [&](auto&&x) { return x->field_root_196.width.get(); })) -(float) 48) + 16) /(float) 216))));;return std::floor((((slint::private_api::model_length(tmp_root_196_packages) + tmp_empty_197_grid_area_212_cols) -(float) 1) /(float) tmp_empty_197_grid_area_212_cols)); }() : 0)); }();
                        });
    self->field_empty_197_layout_cache.set_binding([this]() {
                            [[maybe_unused]] auto self = this;
                            return slint::private_api::solve_box_layout([&](const auto &a_0, const auto &a_1, const auto &a_2, const auto &a_3, const auto &a_4){ slint::cbindgen_private::BoxLayoutData o{}; o.alignment = a_0; o.cells = a_1; o.padding = a_2; o.size = a_3; o.spacing = a_4; return o; }(slint::cbindgen_private::LayoutAlignment::Stretch, slint::private_api::make_slice<slint::cbindgen_private::LayoutItemInfo>(std::array<slint::cbindgen_private::LayoutItemInfo, 2>{ slint::cbindgen_private::LayoutItemInfo ( [&](const auto &a_0){ slint::cbindgen_private::LayoutItemInfo o{}; o.constraint = a_0; return o; }([&]{ [[maybe_unused]] auto layout_info = ([&](const auto &a_0, const auto &a_1, const auto &a_2, const auto &a_3, const auto &a_4, const auto &a_5){ slint::cbindgen_private::LayoutInfo o{}; o.max = a_0; o.max_percent = a_1; o.min = a_2; o.min_percent = a_3; o.preferred = a_4; o.stretch = a_5; return o; }(+3.4028234663852886e38, 100, 0, 0, 0, 1) + self->field_empty_197_empty_199_layoutinfo_v.get());;return [&](const auto &a_0, const auto &a_1, const auto &a_2, const auto &a_3, const auto &a_4, const auto &a_5){ slint::cbindgen_private::LayoutInfo o{}; o.max = a_0; o.max_percent = a_1; o.min = a_2; o.min_percent = a_3; o.preferred = a_4; o.stretch = a_5; return o; }(64, layout_info.max_percent, 64, layout_info.min_percent, layout_info.preferred, layout_info.stretch); }()) ), slint::cbindgen_private::LayoutItemInfo ( [&](const auto &a_0){ slint::cbindgen_private::LayoutItemInfo o{}; o.constraint = a_0; return o; }(slint::private_api::item_layout_info(SLINT_GET_ITEM_VTABLE(FlickableVTable), const_cast<slint::cbindgen_private::Flickable*>(&self->field_grid_area_212), slint::cbindgen_private::Orientation::Vertical, -1, &self->globals->window().window_handle(), self->self_weak.lock()->into_dyn(), self->tree_index_of_first_child + 2 - 1)) ) }.data(), 2), [&](const auto &a_0, const auto &a_1){ slint::cbindgen_private::Padding o{}; o.begin = a_0; o.end = a_1; return o; }(0, 0), slint::private_api::optional_or_default(slint::private_api::optional_transform(self->parent.lock(), [&](auto&&x) { return x->field_root_196.height.get(); })), 0),slint::private_api::make_slice<int>(std::array<int, 0>{  }.data(), 0));
                        });
    self->field_empty_197_layoutinfo_h.set_binding([this]() {
                            [[maybe_unused]] auto self = this;
                            return slint::private_api::box_layout_info_ortho(slint::private_api::make_slice<slint::cbindgen_private::LayoutItemInfo>(std::array<slint::cbindgen_private::LayoutItemInfo, 2>{ slint::cbindgen_private::LayoutItemInfo ( [&](const auto &a_0){ slint::cbindgen_private::LayoutItemInfo o{}; o.constraint = a_0; return o; }(([&](const auto &a_0, const auto &a_1, const auto &a_2, const auto &a_3, const auto &a_4, const auto &a_5){ slint::cbindgen_private::LayoutInfo o{}; o.max = a_0; o.max_percent = a_1; o.min = a_2; o.min_percent = a_3; o.preferred = a_4; o.stretch = a_5; return o; }(+3.4028234663852886e38, 100, 0, 0, 0, 1) + self->field_empty_197_empty_199_layoutinfo_h.get())) ), slint::cbindgen_private::LayoutItemInfo ( [&](const auto &a_0){ slint::cbindgen_private::LayoutItemInfo o{}; o.constraint = a_0; return o; }(slint::private_api::item_layout_info(SLINT_GET_ITEM_VTABLE(FlickableVTable), const_cast<slint::cbindgen_private::Flickable*>(&self->field_grid_area_212), slint::cbindgen_private::Orientation::Horizontal, -1, &self->globals->window().window_handle(), self->self_weak.lock()->into_dyn(), self->tree_index_of_first_child + 2 - 1)) ) }.data(), 2),[&](const auto &a_0, const auto &a_1){ slint::cbindgen_private::Padding o{}; o.begin = a_0; o.end = a_1; return o; }(0, 0));
                        });
    self->field_empty_197_layoutinfo_v.set_binding([this]() {
                            [[maybe_unused]] auto self = this;
                            return slint::private_api::box_layout_info(slint::private_api::make_slice<slint::cbindgen_private::LayoutItemInfo>(std::array<slint::cbindgen_private::LayoutItemInfo, 2>{ slint::cbindgen_private::LayoutItemInfo ( [&](const auto &a_0){ slint::cbindgen_private::LayoutItemInfo o{}; o.constraint = a_0; return o; }([&]{ [[maybe_unused]] auto layout_info = ([&](const auto &a_0, const auto &a_1, const auto &a_2, const auto &a_3, const auto &a_4, const auto &a_5){ slint::cbindgen_private::LayoutInfo o{}; o.max = a_0; o.max_percent = a_1; o.min = a_2; o.min_percent = a_3; o.preferred = a_4; o.stretch = a_5; return o; }(+3.4028234663852886e38, 100, 0, 0, 0, 1) + self->field_empty_197_empty_199_layoutinfo_v.get());;return [&](const auto &a_0, const auto &a_1, const auto &a_2, const auto &a_3, const auto &a_4, const auto &a_5){ slint::cbindgen_private::LayoutInfo o{}; o.max = a_0; o.max_percent = a_1; o.min = a_2; o.min_percent = a_3; o.preferred = a_4; o.stretch = a_5; return o; }(64, layout_info.max_percent, 64, layout_info.min_percent, layout_info.preferred, layout_info.stretch); }()) ), slint::cbindgen_private::LayoutItemInfo ( [&](const auto &a_0){ slint::cbindgen_private::LayoutItemInfo o{}; o.constraint = a_0; return o; }(slint::private_api::item_layout_info(SLINT_GET_ITEM_VTABLE(FlickableVTable), const_cast<slint::cbindgen_private::Flickable*>(&self->field_grid_area_212), slint::cbindgen_private::Orientation::Vertical, -1, &self->globals->window().window_handle(), self->self_weak.lock()->into_dyn(), self->tree_index_of_first_child + 2 - 1)) ) }.data(), 2),0,[&](const auto &a_0, const auto &a_1){ slint::cbindgen_private::Padding o{}; o.begin = a_0; o.end = a_1; return o; }(0, 0),slint::cbindgen_private::LayoutAlignment::Stretch);
                        });
    self->field_empty_197_rectangle_198_height.set(64);
    self->field_empty_197_rectangle_198_layoutinfo_v.set_binding([this]() {
                            [[maybe_unused]] auto self = this;
                            return ([&](const auto &a_0, const auto &a_1, const auto &a_2, const auto &a_3, const auto &a_4, const auto &a_5){ slint::cbindgen_private::LayoutInfo o{}; o.max = a_0; o.max_percent = a_1; o.min = a_2; o.min_percent = a_3; o.preferred = a_4; o.stretch = a_5; return o; }(+3.4028234663852886e38, 100, 0, 0, 0, 1) + self->field_empty_197_empty_199_layoutinfo_v.get());
                        });
    self->field_empty_197_rectangle_198_width.set_binding([this]() {
                            [[maybe_unused]] auto self = this;
                            return slint::private_api::optional_or_default(slint::private_api::optional_transform(self->parent.lock(), [&](auto&&x) { return x->field_root_196.width.get(); }));
                        });
    self->field_empty_197_rectangle_206_layoutinfo_h.set_binding([this]() {
                            [[maybe_unused]] auto self = this;
                            return ([&](const auto &a_0, const auto &a_1, const auto &a_2, const auto &a_3, const auto &a_4, const auto &a_5){ slint::cbindgen_private::LayoutInfo o{}; o.max = a_0; o.max_percent = a_1; o.min = a_2; o.min_percent = a_3; o.preferred = a_4; o.stretch = a_5; return o; }(+3.4028234663852886e38, 100, 0, 0, 0, 1) + slint::private_api::item_layout_info(SLINT_GET_ITEM_VTABLE(SimpleTextVTable), const_cast<slint::cbindgen_private::SimpleText*>(&self->field_text_208), slint::cbindgen_private::Orientation::Horizontal, -1, &self->globals->window().window_handle(), self->self_weak.lock()->into_dyn(), self->tree_index_of_first_child + 12 - 1));
                        });
    self->field_empty_197_rectangle_206_layoutinfo_v.set_binding([this]() {
                            [[maybe_unused]] auto self = this;
                            return ([&](const auto &a_0, const auto &a_1, const auto &a_2, const auto &a_3, const auto &a_4, const auto &a_5){ slint::cbindgen_private::LayoutInfo o{}; o.max = a_0; o.max_percent = a_1; o.min = a_2; o.min_percent = a_3; o.preferred = a_4; o.stretch = a_5; return o; }(+3.4028234663852886e38, 100, 0, 0, 0, 1) + slint::private_api::item_layout_info(SLINT_GET_ITEM_VTABLE(SimpleTextVTable), const_cast<slint::cbindgen_private::SimpleText*>(&self->field_text_208), slint::cbindgen_private::Orientation::Vertical, -1, &self->globals->window().window_handle(), self->self_weak.lock()->into_dyn(), self->tree_index_of_first_child + 12 - 1));
                        });
    self->field_empty_197_text_208_min_height.set_binding([this]() {
                            [[maybe_unused]] auto self = this;
                            return slint::private_api::item_layout_info(SLINT_GET_ITEM_VTABLE(SimpleTextVTable), const_cast<slint::cbindgen_private::SimpleText*>(&self->field_text_208), slint::cbindgen_private::Orientation::Vertical, -1, &self->globals->window().window_handle(), self->self_weak.lock()->into_dyn(), self->tree_index_of_first_child + 12 - 1).min;
                        });
    self->field_empty_197_text_208_min_width.set_binding([this]() {
                            [[maybe_unused]] auto self = this;
                            return slint::private_api::item_layout_info(SLINT_GET_ITEM_VTABLE(SimpleTextVTable), const_cast<slint::cbindgen_private::SimpleText*>(&self->field_text_208), slint::cbindgen_private::Orientation::Horizontal, -1, &self->globals->window().window_handle(), self->self_weak.lock()->into_dyn(), self->tree_index_of_first_child + 12 - 1).min;
                        });
    self->field_empty_197_text_208_preferred_height.set_binding([this]() {
                            [[maybe_unused]] auto self = this;
                            return slint::private_api::item_layout_info(SLINT_GET_ITEM_VTABLE(SimpleTextVTable), const_cast<slint::cbindgen_private::SimpleText*>(&self->field_text_208), slint::cbindgen_private::Orientation::Vertical, -1, &self->globals->window().window_handle(), self->self_weak.lock()->into_dyn(), self->tree_index_of_first_child + 12 - 1).preferred;
                        });
    self->field_empty_197_text_208_preferred_width.set_binding([this]() {
                            [[maybe_unused]] auto self = this;
                            return slint::private_api::item_layout_info(SLINT_GET_ITEM_VTABLE(SimpleTextVTable), const_cast<slint::cbindgen_private::SimpleText*>(&self->field_text_208), slint::cbindgen_private::Orientation::Horizontal, -1, &self->globals->window().window_handle(), self->self_weak.lock()->into_dyn(), self->tree_index_of_first_child + 12 - 1).preferred;
                        });
    self->field_empty_197_textinput_211_accessible_action_set_value.set_handler(
                [this]([[maybe_unused]] slint::SharedString arg_0) {
                    [[maybe_unused]] auto self = this;
                    [&]{ self->field_textinput_211.text.set(arg_0);self->field_textinput_211.edited.call(); }();
                });
    self->field_empty_197_width.set_binding([this]() {
                            [[maybe_unused]] auto self = this;
                            return slint::private_api::optional_or_default(slint::private_api::optional_transform(self->parent.lock(), [&](auto&&x) { return x->field_root_196.width.get(); }));
                        });
    self->field_rectangle_198.background.set(slint::Brush(slint::Color::from_argb_encoded(+4.279769125e9)));
    self->field_rectangle_198.border_color.set(slint::Brush(slint::Color::from_argb_encoded(+4.281414212e9)));
    self->field_rectangle_198.border_width.set(1);
    self->field_text_201.color.set_binding([this]() {
                            [[maybe_unused]] auto self = this;
                            return self->globals->global_FluentPalette_221->field_foreground.get();
                        });
    self->field_text_201.font_size.set(22);
    self->field_text_201.height.set(64);
    self->field_text_201.text.set(slint::SharedString(u8"\U0001f427"));
    self->field_text_201.vertical_alignment.set(slint::cbindgen_private::TextVerticalAlignment::Center);
    self->field_text_201.width.set_binding([this]() {
                            [[maybe_unused]] auto self = this;
                            return self->field_empty_197_empty_200_layout_cache.get()[1];
                        });
    self->field_text_203.color.set(slint::Brush(slint::Color::from_argb_encoded(+4.287214842e9)));
    self->field_text_203.font_size.set(18);
    self->field_text_203.font_weight.set(static_cast<int>(700));
    self->field_text_203.height.set_binding([this]() {
                            [[maybe_unused]] auto self = this;
                            return self->field_empty_197_empty_202_layout_cache.get()[1];
                        });
    self->field_text_203.text.set(slint::SharedString(u8"Tux Store"));
    self->field_text_203.width.set_binding([this]() {
                            [[maybe_unused]] auto self = this;
                            return self->field_empty_197_empty_200_layout_cache.get()[3];
                        });
    self->field_text_204.color.set(slint::Brush(slint::Color::from_argb_encoded(+4.2865471e9)));
    self->field_text_204.font_size.set(11);
    self->field_text_204.height.set_binding([this]() {
                            [[maybe_unused]] auto self = this;
                            return self->field_empty_197_empty_202_layout_cache.get()[3];
                        });
    self->field_text_204.text.set(slint::SharedString(u8"for Arch Linux"));
    self->field_text_204.width.set_binding([this]() {
                            [[maybe_unused]] auto self = this;
                            return self->field_empty_197_empty_200_layout_cache.get()[3];
                        });
    self->field_rectangle_206.background.set_binding([this]() {
                            [[maybe_unused]] auto self = this;
                            return slint::Brush((self->field_home_ta_207.has_hover.get() ? slint::Color::from_argb_encoded(+4.28273033e9) : slint::Color::from_argb_encoded(+4.281414212e9)));
                        });
    self->field_rectangle_206.border_color.set(slint::Brush(slint::Color::from_argb_encoded(+4.28273033e9)));
    self->field_rectangle_206.border_radius.set(10);
    self->field_rectangle_206.border_width.set(1);
    self->field_home_ta_207.clicked.set_handler(
                [this]() {
                    [[maybe_unused]] auto self = this;
                    [&]{ slint::private_api::optional_then(self->parent.lock(), [&](auto&&x) { x->field_root_196_search_query.set(slint::SharedString(u8"")); });slint::private_api::optional_then(self->parent.lock(), [&](auto&&x) { x->field_root_196_search_changed.call(slint::SharedString(u8"")); }); }();
                });
    self->field_home_ta_207.enabled.set(true);
    self->field_text_208.color.set_binding([this]() {
                            [[maybe_unused]] auto self = this;
                            return self->globals->global_FluentPalette_221->field_foreground.get();
                        });
    self->field_text_208.font_size.set(16);
    self->field_text_208.height.set_binding([this]() {
                            [[maybe_unused]] auto self = this;
                            return std::max<float>(self->field_empty_197_text_208_preferred_height.get(), self->field_empty_197_text_208_min_height.get());
                        });
    self->field_text_208.horizontal_alignment.set(slint::cbindgen_private::TextHorizontalAlignment::Center);
    self->field_text_208.text.set(slint::SharedString(u8"\U0001f3e0"));
    self->field_text_208.vertical_alignment.set(slint::cbindgen_private::TextVerticalAlignment::Center);
    self->field_text_208.width.set_binding([this]() {
                            [[maybe_unused]] auto self = this;
                            return std::max<float>(self->field_empty_197_text_208_preferred_width.get(), self->field_empty_197_text_208_min_width.get());
                        });
    self->field_rectangle_209.background.set(slint::Brush(slint::Color::from_argb_encoded(+4.281414212e9)));
    self->field_rectangle_209.border_color.set(slint::Brush(slint::Color::from_argb_encoded(+4.28273033e9)));
    self->field_rectangle_209.border_radius.set(10);
    self->field_rectangle_209.border_width.set(1);
    self->field_textinput_211.accepted.set_handler(
                [this]() {
                    [[maybe_unused]] auto self = this;
                    slint::private_api::optional_then(self->parent.lock(), [&](auto&&x) { x->field_root_196_search_changed.call(self->field_textinput_211.text.get()); });
                });
    self->field_textinput_211.color.set(slint::Brush(slint::Color::from_argb_encoded(+4.291679988e9)));
    self->field_textinput_211.enabled.set(true);
    self->field_textinput_211.font_size.set(13);
    self->field_textinput_211.height.set(36);
    self->field_textinput_211.read_only.set(false);
    self->field_textinput_211.selection_background_color.set_binding([this]() {
                            [[maybe_unused]] auto self = this;
                            return self->globals->global_FluentPalette_221->field_selection_background.get().color();
                        });
    self->field_textinput_211.selection_foreground_color.set_binding([this]() {
                            [[maybe_unused]] auto self = this;
                            return self->globals->global_FluentPalette_221->field_selection_foreground.get().color();
                        });
    self->field_textinput_211.single_line.set(true);
    self->field_textinput_211.text_cursor_width.set(1);
    self->field_textinput_211.vertical_alignment.set(slint::cbindgen_private::TextVerticalAlignment::Center);
    self->field_textinput_211.width.set_binding([this]() {
                            [[maybe_unused]] auto self = this;
                            return self->field_empty_197_empty_210_layout_cache.get()[1];
                        });
    self->field_grid_area_212.interactive.set(true);
    self->field_grid_area_212.viewport_height.set_binding([this]() {
                            [[maybe_unused]] auto self = this;
                            return std::max<float>(self->field_empty_197_layout_cache.get()[3], (24 + (self->field_empty_197_grid_area_212_total_rows.get() * 196)));
                        });
    self->field_grid_area_212.viewport_width.set_binding([this]() {
                            [[maybe_unused]] auto self = this;
                            return slint::private_api::optional_or_default(slint::private_api::optional_transform(self->parent.lock(), [&](auto&&x) { return x->field_root_196.width.get(); }));
                        });
    self->field_empty_197_rectangle_198_height.set_constant();
    self->field_rectangle_198.background.set_constant();
    self->field_rectangle_198.border_color.set_constant();
    self->field_rectangle_198.border_radius.set_constant();
    self->field_rectangle_198.border_width.set_constant();
    self->field_text_201.font_size.set_constant();
    self->field_text_201.font_weight.set_constant();
    self->field_text_201.height.set_constant();
    self->field_text_201.horizontal_alignment.set_constant();
    self->field_text_201.text.set_constant();
    self->field_text_201.vertical_alignment.set_constant();
    self->field_text_203.color.set_constant();
    self->field_text_203.font_size.set_constant();
    self->field_text_203.font_weight.set_constant();
    self->field_text_203.horizontal_alignment.set_constant();
    self->field_text_203.text.set_constant();
    self->field_text_203.vertical_alignment.set_constant();
    self->field_text_204.color.set_constant();
    self->field_text_204.font_size.set_constant();
    self->field_text_204.font_weight.set_constant();
    self->field_text_204.horizontal_alignment.set_constant();
    self->field_text_204.text.set_constant();
    self->field_text_204.vertical_alignment.set_constant();
    self->field_rectangle_206.border_color.set_constant();
    self->field_rectangle_206.border_radius.set_constant();
    self->field_rectangle_206.border_width.set_constant();
    self->field_home_ta_207.enabled.set_constant();
    self->field_home_ta_207.mouse_cursor.set_constant();
    self->field_text_208.font_size.set_constant();
    self->field_text_208.font_weight.set_constant();
    self->field_text_208.horizontal_alignment.set_constant();
    self->field_text_208.text.set_constant();
    self->field_text_208.vertical_alignment.set_constant();
    self->field_rectangle_209.background.set_constant();
    self->field_rectangle_209.border_color.set_constant();
    self->field_rectangle_209.border_radius.set_constant();
    self->field_rectangle_209.border_width.set_constant();
    self->field_textinput_211.color.set_constant();
    self->field_textinput_211.enabled.set_constant();
    self->field_textinput_211.font_family.set_constant();
    self->field_textinput_211.font_italic.set_constant();
    self->field_textinput_211.font_size.set_constant();
    self->field_textinput_211.font_weight.set_constant();
    self->field_textinput_211.height.set_constant();
    self->field_textinput_211.horizontal_alignment.set_constant();
    self->field_textinput_211.input_type.set_constant();
    self->field_textinput_211.letter_spacing.set_constant();
    self->field_textinput_211.page_height.set_constant();
    self->field_textinput_211.read_only.set_constant();
    self->field_textinput_211.single_line.set_constant();
    self->field_textinput_211.text_cursor_width.set_constant();
    self->field_textinput_211.vertical_alignment.set_constant();
    self->field_textinput_211.wrap.set_constant();
    self->field_grid_area_212.interactive.set_constant();
    self->repeater_0.set_model_binding([self] { (void)self; return slint::private_api::optional_or_default(slint::private_api::optional_transform(self->parent.lock(), [&](auto&&x) { return x->field_root_196_packages.get(); })); });
}

auto Component_empty_197::user_init () -> void{
    [[maybe_unused]] auto self = this;
}

auto Component_empty_197::layout_info (slint::cbindgen_private::Orientation o) const -> slint::cbindgen_private::LayoutInfo{
    [[maybe_unused]] auto self = this;
    return o == slint::cbindgen_private::Orientation::Horizontal ? self->field_empty_197_layoutinfo_h.get() : self->field_empty_197_layoutinfo_v.get();
}

auto Component_empty_197::item_geometry (uint32_t index) const -> slint::cbindgen_private::Rect{
    [[maybe_unused]] auto self = this;
    switch (index) {
        case 0: return slint::private_api::convert_anonymous_rect(std::make_tuple(float(slint::private_api::optional_or_default(slint::private_api::optional_transform(self->parent.lock(), [&](auto&&x) { return x->field_root_196.height.get(); }))), float(slint::private_api::optional_or_default(slint::private_api::optional_transform(self->parent.lock(), [&](auto&&x) { return x->field_root_196.width.get(); }))), float(0), float(0)));
        case 1: return slint::private_api::convert_anonymous_rect(std::make_tuple(float(64), float(slint::private_api::optional_or_default(slint::private_api::optional_transform(self->parent.lock(), [&](auto&&x) { return x->field_root_196.width.get(); }))), float(0), float(self->field_empty_197_layout_cache.get()[0])));
        case 2: return slint::private_api::convert_anonymous_rect(std::make_tuple(float(self->field_empty_197_layout_cache.get()[3]), float(slint::private_api::optional_or_default(slint::private_api::optional_transform(self->parent.lock(), [&](auto&&x) { return x->field_root_196.width.get(); }))), float(0), float(self->field_empty_197_layout_cache.get()[2])));
        case 3: return slint::private_api::convert_anonymous_rect(std::make_tuple(float(64), float(self->field_empty_197_empty_199_layout_cache.get()[1]), float(self->field_empty_197_empty_199_layout_cache.get()[0]), float(0)));
        case 4: return slint::private_api::convert_anonymous_rect(std::make_tuple(float(64), float(self->field_empty_197_empty_199_layout_cache.get()[3]), float(self->field_empty_197_empty_199_layout_cache.get()[2]), float(14)));
        case 5: return slint::private_api::convert_anonymous_rect(std::make_tuple(float(64), float(self->field_empty_197_empty_200_layout_cache.get()[1]), float(self->field_empty_197_empty_200_layout_cache.get()[0]), float(0)));
        case 6: return slint::private_api::convert_anonymous_rect(std::make_tuple(float(64), float(self->field_empty_197_empty_200_layout_cache.get()[3]), float(self->field_empty_197_empty_200_layout_cache.get()[2]), float(0)));
        case 7: return slint::private_api::convert_anonymous_rect(std::make_tuple(float(self->field_empty_197_empty_202_layout_cache.get()[1]), float(self->field_empty_197_empty_200_layout_cache.get()[3]), float(0), float(self->field_empty_197_empty_202_layout_cache.get()[0])));
        case 8: return slint::private_api::convert_anonymous_rect(std::make_tuple(float(self->field_empty_197_empty_202_layout_cache.get()[3]), float(self->field_empty_197_empty_200_layout_cache.get()[3]), float(0), float(self->field_empty_197_empty_202_layout_cache.get()[2])));
        case 9: return slint::private_api::convert_anonymous_rect(std::make_tuple(float(36), float(40), float(self->field_empty_197_empty_205_layout_cache.get()[0]), float(0)));
        case 10: return slint::private_api::convert_anonymous_rect(std::make_tuple(float(36), float(260), float(self->field_empty_197_empty_205_layout_cache.get()[2]), float(0)));
        case 11: return slint::private_api::convert_anonymous_rect(std::make_tuple(float(36), float(40), float(0), float(0)));
        case 12: return slint::private_api::convert_anonymous_rect(std::make_tuple(float(self->field_text_208.height.get()), float(self->field_text_208.width.get()), float(((40 -(float) self->field_text_208.width.get()) /(float) 2)), float(((36 -(float) self->field_text_208.height.get()) /(float) 2))));
        case 13: return slint::private_api::convert_anonymous_rect(std::make_tuple(float(36), float(self->field_empty_197_empty_210_layout_cache.get()[1]), float(self->field_empty_197_empty_210_layout_cache.get()[0]), float(0)));
        case 14: return slint::private_api::convert_anonymous_rect(std::make_tuple(float(self->field_grid_area_212.viewport_height.get()), float(self->field_grid_area_212.viewport_width.get()), float(self->field_grid_area_212.viewport_x.get()), float(self->field_grid_area_212.viewport_y.get())));
    }
    return {};
}

auto Component_empty_197::accessible_role (uint32_t index) const -> slint::cbindgen_private::AccessibleRole{
    [[maybe_unused]] auto self = this;
    switch (index) {
        case 5: return slint::cbindgen_private::AccessibleRole::Text;
        case 7: return slint::cbindgen_private::AccessibleRole::Text;
        case 8: return slint::cbindgen_private::AccessibleRole::Text;
        case 12: return slint::cbindgen_private::AccessibleRole::Text;
        case 13: return slint::cbindgen_private::AccessibleRole::TextInput;
    }
    return {};
}

auto Component_empty_197::accessible_string_property (uint32_t index, slint::cbindgen_private::AccessibleStringProperty what) const -> std::optional<slint::SharedString>{
    [[maybe_unused]] auto self = this;
    switch ((index << 8) | uintptr_t(what)) {
        case (5 << 8) | uintptr_t(slint::cbindgen_private::AccessibleStringProperty::Label): return slint::SharedString(u8"\U0001f427");
        case (7 << 8) | uintptr_t(slint::cbindgen_private::AccessibleStringProperty::Label): return slint::SharedString(u8"Tux Store");
        case (8 << 8) | uintptr_t(slint::cbindgen_private::AccessibleStringProperty::Label): return slint::SharedString(u8"for Arch Linux");
        case (12 << 8) | uintptr_t(slint::cbindgen_private::AccessibleStringProperty::Label): return slint::SharedString(u8"\U0001f3e0");
        case (13 << 8) | uintptr_t(slint::cbindgen_private::AccessibleStringProperty::Enabled): return (true ? slint::SharedString(u8"true") : slint::SharedString(u8"false"));
        case (13 << 8) | uintptr_t(slint::cbindgen_private::AccessibleStringProperty::ReadOnly): return (false ? slint::SharedString(u8"true") : slint::SharedString(u8"false"));
        case (13 << 8) | uintptr_t(slint::cbindgen_private::AccessibleStringProperty::Value): return self->field_textinput_211.text.get();
    }
    return {};
}

auto Component_empty_197::accessibility_action (uint32_t index, const slint::cbindgen_private::AccessibilityAction &action) const -> void{
    [[maybe_unused]] auto self = this;
    switch ((index << 8) | uintptr_t(action.tag)) {
        case (13 << 8) | uintptr_t(slint::cbindgen_private::AccessibilityAction::Tag::SetValue): { auto arg_0 = action.set_value._0; return self->field_empty_197_textinput_211_accessible_action_set_value.call(arg_0); }
    }
    return ;
}

auto Component_empty_197::supported_accessibility_actions (uint32_t index) const -> uint32_t{
    [[maybe_unused]] auto self = this;
    switch (index) {
        case 13: return slint::cbindgen_private::SupportedAccessibilityAction_SetValue;
    }
    return {};
}

auto Component_empty_197::element_infos (uint32_t index) const -> std::optional<slint::SharedString>{
    [[maybe_unused]] auto self = this;
    switch (index) {
    }
    return {};
}

auto Component_empty_197::ensure_instantiated () const -> bool{
    [[maybe_unused]] auto self = this;
    bool _changed = false;
    _changed |= self->repeater_0.ensure_updated(self);
    return _changed;
}

auto Component_empty_197::visit_dynamic_children (uint32_t dyn_index, [[maybe_unused]] slint::private_api::TraversalOrder order, [[maybe_unused]] slint::private_api::ItemVisitorRefMut visitor) const -> uint64_t{
        auto self = this;
        switch(dyn_index) { 
        case 0: {
                return self->repeater_0.visit(order, visitor);
            } };
        std::abort();
}

auto Component_empty_197::subtree_range (uintptr_t dyn_index) const -> slint::private_api::IndexRange{
    [[maybe_unused]] auto self = this;
        switch(dyn_index) { 
        case 0: {
                self->repeater_0.track_instance_changes();
                return self->repeater_0.index_range();
            } };
        std::abort();
}

auto Component_empty_197::subtree_component (uintptr_t dyn_index, [[maybe_unused]] uintptr_t subtree_index, [[maybe_unused]] slint::private_api::ItemTreeWeak *result) const -> void{
    [[maybe_unused]] auto self = this;
        switch(dyn_index) { 
        case 0: {
                *result = self->repeater_0.instance_at(subtree_index);
                return;
            } };
        std::abort();
}

auto Component_empty_197::visit_children (slint::private_api::ItemTreeRef component, intptr_t index, slint::private_api::TraversalOrder order, slint::private_api::ItemVisitorRefMut visitor) -> uint64_t{
    static const auto dyn_visit = [] (const void *base,  [[maybe_unused]] slint::private_api::TraversalOrder order, [[maybe_unused]] slint::private_api::ItemVisitorRefMut visitor, [[maybe_unused]] uint32_t dyn_index) -> uint64_t {
        [[maybe_unused]] auto self = reinterpret_cast<const Component_empty_197*>(base);
        return self->visit_dynamic_children(dyn_index, order, visitor);
    };
    auto self_rc = reinterpret_cast<const Component_empty_197*>(component.instance)->self_weak.lock()->into_dyn();
    return slint::cbindgen_private::slint_visit_item_tree(&self_rc, get_item_tree(component) , index, order, visitor, dyn_visit);
}

auto Component_empty_197::get_item_ref (slint::private_api::ItemTreeRef component, uint32_t index) -> slint::private_api::ItemRef{
    return slint::private_api::get_item_ref(component, get_item_tree(component), item_array(), index);
}

auto Component_empty_197::get_subtree_range ([[maybe_unused]] slint::private_api::ItemTreeRef component, [[maybe_unused]] uint32_t dyn_index) -> slint::private_api::IndexRange{
    auto self = reinterpret_cast<const Component_empty_197*>(component.instance);
    return self->subtree_range(dyn_index);
}

auto Component_empty_197::get_subtree ([[maybe_unused]] slint::private_api::ItemTreeRef component, [[maybe_unused]] uint32_t dyn_index, [[maybe_unused]] uintptr_t subtree_index, [[maybe_unused]] slint::private_api::ItemTreeWeak *result) -> void{
    auto self = reinterpret_cast<const Component_empty_197*>(component.instance);
    self->subtree_component(dyn_index, subtree_index, result);
}

auto Component_empty_197::get_item_tree (slint::private_api::ItemTreeRef) -> slint::cbindgen_private::Slice<slint::private_api::ItemTreeNode>{
    return item_tree();
}

auto Component_empty_197::parent_node ([[maybe_unused]] slint::private_api::ItemTreeRef component, [[maybe_unused]] slint::private_api::ItemWeak *result) -> void{
    auto self = reinterpret_cast<const Component_empty_197*>(component.instance);
    auto parent = self->parent.lock().value();
    *result = { parent->self_weak, parent->tree_index_of_first_child + 0 };
}

auto Component_empty_197::embed_component ([[maybe_unused]] slint::private_api::ItemTreeRef component, [[maybe_unused]] const slint::private_api::ItemTreeWeak *parent_component, [[maybe_unused]] const uint32_t parent_index) -> bool{
    return false; /* todo! */
}

auto Component_empty_197::subtree_index ([[maybe_unused]] slint::private_api::ItemTreeRef component) -> uintptr_t{
    return std::numeric_limits<uintptr_t>::max();
}

auto Component_empty_197::item_tree () -> slint::cbindgen_private::Slice<slint::private_api::ItemTreeNode>{
    static const slint::private_api::ItemTreeNode children[] {
        slint::private_api::make_item_node(2, 1, 0, 0, false), 
slint::private_api::make_item_node(2, 3, 0, 1, false), 
slint::private_api::make_item_node(1, 14, 0, 2, false), 
slint::private_api::make_item_node(2, 5, 1, 3, false), 
slint::private_api::make_item_node(2, 9, 1, 4, false), 
slint::private_api::make_item_node(0, 7, 3, 5, true), 
slint::private_api::make_item_node(2, 7, 3, 6, false), 
slint::private_api::make_item_node(0, 9, 6, 7, true), 
slint::private_api::make_item_node(0, 9, 6, 8, true), 
slint::private_api::make_item_node(2, 11, 4, 9, false), 
slint::private_api::make_item_node(1, 13, 4, 10, false), 
slint::private_api::make_item_node(0, 13, 9, 11, false), 
slint::private_api::make_item_node(0, 13, 9, 12, true), 
slint::private_api::make_item_node(0, 14, 10, 13, true), 
slint::private_api::make_item_node(1, 15, 2, 14, false), 
slint::private_api::make_dyn_node(0, 14) };
    return slint::private_api::make_slice(std::span(children));
}

auto Component_empty_197::item_array () -> const slint::private_api::ItemArray{
    static const slint::private_api::ItemArrayEntry items[] {
        { SLINT_GET_ITEM_VTABLE(EmptyVTable),  offsetof(Component_empty_197, field_empty_197) }, 
{ SLINT_GET_ITEM_VTABLE(BasicBorderRectangleVTable),  offsetof(Component_empty_197, field_rectangle_198) }, 
{ SLINT_GET_ITEM_VTABLE(FlickableVTable),  offsetof(Component_empty_197, field_grid_area_212) }, 
{ SLINT_GET_ITEM_VTABLE(EmptyVTable),  offsetof(Component_empty_197, field_empty_200) }, 
{ SLINT_GET_ITEM_VTABLE(EmptyVTable),  offsetof(Component_empty_197, field_empty_205) }, 
{ SLINT_GET_ITEM_VTABLE(SimpleTextVTable),  offsetof(Component_empty_197, field_text_201) }, 
{ SLINT_GET_ITEM_VTABLE(EmptyVTable),  offsetof(Component_empty_197, field_empty_202) }, 
{ SLINT_GET_ITEM_VTABLE(SimpleTextVTable),  offsetof(Component_empty_197, field_text_203) }, 
{ SLINT_GET_ITEM_VTABLE(SimpleTextVTable),  offsetof(Component_empty_197, field_text_204) }, 
{ SLINT_GET_ITEM_VTABLE(BasicBorderRectangleVTable),  offsetof(Component_empty_197, field_rectangle_206) }, 
{ SLINT_GET_ITEM_VTABLE(BasicBorderRectangleVTable),  offsetof(Component_empty_197, field_rectangle_209) }, 
{ SLINT_GET_ITEM_VTABLE(TouchAreaVTable),  offsetof(Component_empty_197, field_home_ta_207) }, 
{ SLINT_GET_ITEM_VTABLE(SimpleTextVTable),  offsetof(Component_empty_197, field_text_208) }, 
{ SLINT_GET_ITEM_VTABLE(TextInputVTable),  offsetof(Component_empty_197, field_textinput_211) }, 
{ SLINT_GET_ITEM_VTABLE(EmptyVTable),  offsetof(Component_empty_197, field_grid_area_viewport_213) } };
    return slint::private_api::make_slice(std::span(items));
}

auto Component_empty_197::layout_info ([[maybe_unused]] slint::private_api::ItemTreeRef component, slint::cbindgen_private::Orientation o) -> slint::cbindgen_private::LayoutInfo{
    return reinterpret_cast<const Component_empty_197*>(component.instance)->layout_info(o);
}

auto Component_empty_197::ensure_instantiated ([[maybe_unused]] slint::private_api::ItemTreeRef component) -> bool{
    return reinterpret_cast<const Component_empty_197*>(component.instance)->ensure_instantiated();
}

auto Component_empty_197::item_geometry ([[maybe_unused]] slint::private_api::ItemTreeRef component, uint32_t index) -> slint::cbindgen_private::LogicalRect{
    return reinterpret_cast<const Component_empty_197*>(component.instance)->item_geometry(index);
}

auto Component_empty_197::accessible_role ([[maybe_unused]] slint::private_api::ItemTreeRef component, uint32_t index) -> slint::cbindgen_private::AccessibleRole{
    return reinterpret_cast<const Component_empty_197*>(component.instance)->accessible_role(index);
}

auto Component_empty_197::accessible_string_property ([[maybe_unused]] slint::private_api::ItemTreeRef component, uint32_t index, slint::cbindgen_private::AccessibleStringProperty what, slint::SharedString *result) -> bool{
    if (auto r = reinterpret_cast<const Component_empty_197*>(component.instance)->accessible_string_property(index, what)) { *result = *r; return true; } else { return false; }
}

auto Component_empty_197::accessibility_action ([[maybe_unused]] slint::private_api::ItemTreeRef component, uint32_t index, const slint::cbindgen_private::AccessibilityAction *action) -> void{
    reinterpret_cast<const Component_empty_197*>(component.instance)->accessibility_action(index, *action);
}

auto Component_empty_197::supported_accessibility_actions ([[maybe_unused]] slint::private_api::ItemTreeRef component, uint32_t index) -> uint32_t{
    return reinterpret_cast<const Component_empty_197*>(component.instance)->supported_accessibility_actions(index);
}

auto Component_empty_197::element_infos ([[maybe_unused]] slint::private_api::ItemTreeRef component, [[maybe_unused]] uint32_t index, [[maybe_unused]] slint::SharedString *result) -> bool{
    return false;
}

auto Component_empty_197::window_adapter ([[maybe_unused]] slint::private_api::ItemTreeRef component, [[maybe_unused]] bool do_create, [[maybe_unused]] slint::cbindgen_private::Option<slint::private_api::WindowAdapterRc>* result) -> void{
    *reinterpret_cast<slint::private_api::WindowAdapterRc*>(result) = reinterpret_cast<const Component_empty_197*>(component.instance)->globals->window().window_handle();
}

auto Component_empty_197::create (class MainWindow const * parent) -> slint::ComponentHandle<Component_empty_197>{
    auto self_rc = vtable::VRc<slint::private_api::ItemTreeVTable, Component_empty_197>::make();
    auto self = const_cast<Component_empty_197 *>(&*self_rc);
    self->self_weak = vtable::VWeak(self_rc).into_dyn();
    slint::private_api::register_item_tree(&self_rc.into_dyn(), parent->globals->m_window);
    self->init(parent->globals, self->self_weak, 0, 1 , parent);
    return slint::ComponentHandle<Component_empty_197>{ self_rc };
}

Component_empty_197::~Component_empty_197 (){
    if (auto &window = globals->m_window) window->window_handle().unregister_item_tree(this, item_array());
}

auto Component_empty_197::init () -> void{
    user_init();
}

auto Component_empty_197::layout_item_info (slint::cbindgen_private::Orientation o, [[maybe_unused]] std::optional<size_t> child_index) const -> slint::cbindgen_private::LayoutItemInfo{
    return { layout_info({&static_vtable, const_cast<void *>(static_cast<const void *>(this))}, o) };
}

auto Component_empty_197::flexbox_layout_item_info (slint::cbindgen_private::Orientation o, [[maybe_unused]] std::optional<size_t> child_index) const -> slint::cbindgen_private::FlexboxLayoutItemInfo{
    auto base = layout_item_info(o, child_index); return { base.constraint, 0.0f, 0.0f, -1.0f, slint::cbindgen_private::FlexboxLayoutAlignSelf::Auto, 0 };
}

const slint::private_api::ItemTreeVTable Component_detailsview_217::static_vtable = { visit_children, get_item_ref, get_subtree_range, get_subtree, get_item_tree, parent_node, embed_component, subtree_index, layout_info, ensure_instantiated, item_geometry, accessible_role, accessible_string_property, accessibility_action, supported_accessibility_actions, element_infos, window_adapter, slint::private_api::drop_in_place<Component_detailsview_217>, slint::private_api::dealloc };

auto Component_detailsview_217::init (const class SharedGlobals* globals,slint::cbindgen_private::ItemTreeWeak enclosing_component,uint32_t tree_index,uint32_t tree_index_of_first_child,class MainWindow const *parent) -> void{
    auto self = this;
    self->self_weak = enclosing_component;
    self->globals = globals;
    this->tree_index_of_first_child = tree_index_of_first_child;
    self->tree_index = tree_index;
    self->parent = vtable::VRcMapped<slint::private_api::ItemTreeVTable, const MainWindow>(parent->self_weak.lock().value(), parent);
    this->field_detailsview_217.init(globals, self_weak.into_dyn(), tree_index, tree_index_of_first_child + 1 - 1);
    self->field_detailsview_217.field_root_32_accent_idx.set(static_cast<int>(0));
    self->field_detailsview_217.field_root_32_back_clicked.set_handler(
                [this]() {
                    [[maybe_unused]] auto self = this;
                    slint::private_api::optional_then(self->parent.lock(), [&](auto&&x) { x->field_root_196_back_clicked.call(); });
                });
    self->field_detailsview_217.field_root_32_details.set_binding([this]() {
                            [[maybe_unused]] auto self = this;
                            return slint::private_api::optional_or_default(slint::private_api::optional_transform(self->parent.lock(), [&](auto&&x) { return x->field_root_196_current_details.get(); }));
                        });
    self->field_detailsview_217.field_root_32_height.set_binding([this]() {
                            [[maybe_unused]] auto self = this;
                            return slint::private_api::optional_or_default(slint::private_api::optional_transform(self->parent.lock(), [&](auto&&x) { return x->field_root_196.height.get(); }));
                        });
    self->field_detailsview_217.field_root_32_install_clicked.set_handler(
                [this]() {
                    [[maybe_unused]] auto self = this;
                    slint::private_api::optional_then(self->parent.lock(), [&](auto&&x) { x->field_root_196_install_clicked.call(slint::private_api::optional_or_default(slint::private_api::optional_transform(self->parent.lock(), [&](auto&&x) { return x->field_root_196_current_package.get(); }))); });
                });
    self->field_detailsview_217.field_root_32_install_state.set_binding([this]() {
                            [[maybe_unused]] auto self = this;
                            return slint::private_api::optional_or_default(slint::private_api::optional_transform(self->parent.lock(), [&](auto&&x) { return x->field_root_196_current_install.get(); }));
                        });
    self->field_detailsview_217.field_root_32_pkg.set_binding([this]() {
                            [[maybe_unused]] auto self = this;
                            return slint::private_api::optional_or_default(slint::private_api::optional_transform(self->parent.lock(), [&](auto&&x) { return x->field_root_196_current_package.get(); }));
                        });
    self->field_detailsview_217.field_root_32_remove_clicked.set_handler(
                [this]([[maybe_unused]] slint::SharedString arg_0) {
                    [[maybe_unused]] auto self = this;
                    slint::private_api::optional_then(self->parent.lock(), [&](auto&&x) { x->field_root_196_remove_clicked.call(slint::private_api::optional_or_default(slint::private_api::optional_transform(self->parent.lock(), [&](auto&&x) { return x->field_root_196_current_package.get(); })),arg_0); });
                });
    self->field_detailsview_217.field_root_32_suggestion_clicked.set_handler(
                [this]([[maybe_unused]] UiPackage arg_0) {
                    [[maybe_unused]] auto self = this;
                    slint::private_api::optional_then(self->parent.lock(), [&](auto&&x) { x->field_root_196_app_clicked.call(arg_0); });
                });
    self->field_detailsview_217.field_root_32_suggestions.set_binding([this]() {
                            [[maybe_unused]] auto self = this;
                            return slint::private_api::optional_or_default(slint::private_api::optional_transform(self->parent.lock(), [&](auto&&x) { return x->field_root_196_current_suggestions.get(); }));
                        });
    self->field_detailsview_217.field_root_32_width.set_binding([this]() {
                            [[maybe_unused]] auto self = this;
                            return slint::private_api::optional_or_default(slint::private_api::optional_transform(self->parent.lock(), [&](auto&&x) { return x->field_root_196.width.get(); }));
                        });
    self->field_detailsview_217.field_root_32_accent_idx.set_constant();
    self->field_detailsview_217.field_root_32.background.set_constant();
    self->field_detailsview_217.field_root_32_empty_47_alignment.set_constant();
    self->field_detailsview_217.field_root_32_empty_47_padding_bottom.set_constant();
    self->field_detailsview_217.field_root_32_empty_47_padding_top.set_constant();
    self->field_detailsview_217.field_root_32_empty_47_spacing.set_constant();
    self->field_detailsview_217.field_root_32_empty_53_alignment.set_constant();
    self->field_detailsview_217.field_root_32_empty_53_spacing.set_constant();
    self->field_detailsview_217.field_root_32_rectangle_34_height.set_constant();
}

auto Component_detailsview_217::user_init () -> void{
    [[maybe_unused]] auto self = this;
    this->field_detailsview_217.user_init();
}

auto Component_detailsview_217::layout_info (slint::cbindgen_private::Orientation o) const -> slint::cbindgen_private::LayoutInfo{
    [[maybe_unused]] auto self = this;
    return o == slint::cbindgen_private::Orientation::Horizontal ? ([&](const auto &a_0, const auto &a_1, const auto &a_2, const auto &a_3, const auto &a_4, const auto &a_5){ slint::cbindgen_private::LayoutInfo o{}; o.max = a_0; o.max_percent = a_1; o.min = a_2; o.min_percent = a_3; o.preferred = a_4; o.stretch = a_5; return o; }(+3.4028234663852886e38, 100, 0, 0, 0, 1) + self->field_detailsview_217.field_root_32_empty_33_layoutinfo_h.get()) : ([&](const auto &a_0, const auto &a_1, const auto &a_2, const auto &a_3, const auto &a_4, const auto &a_5){ slint::cbindgen_private::LayoutInfo o{}; o.max = a_0; o.max_percent = a_1; o.min = a_2; o.min_percent = a_3; o.preferred = a_4; o.stretch = a_5; return o; }(+3.4028234663852886e38, 100, 0, 0, 0, 1) + self->field_detailsview_217.field_root_32_empty_33_layoutinfo_v.get());
}

auto Component_detailsview_217::item_geometry (uint32_t index) const -> slint::cbindgen_private::Rect{
    [[maybe_unused]] auto self = this;
    switch (index) {
        case 0: return slint::private_api::convert_anonymous_rect(std::make_tuple(float(slint::private_api::optional_or_default(slint::private_api::optional_transform(self->parent.lock(), [&](auto&&x) { return x->field_root_196.height.get(); }))), float(slint::private_api::optional_or_default(slint::private_api::optional_transform(self->parent.lock(), [&](auto&&x) { return x->field_root_196.width.get(); }))), float(0), float(0)));
    }
    if (index == 0) {
        return self->field_detailsview_217.item_geometry(0);
    } else if (index >= 1 && index < 40) {
        return self->field_detailsview_217.item_geometry(index - 0);
    } else return {};
}

auto Component_detailsview_217::accessible_role (uint32_t index) const -> slint::cbindgen_private::AccessibleRole{
    [[maybe_unused]] auto self = this;
    switch (index) {
    }
    if (index == 0) {
        return self->field_detailsview_217.accessible_role(0);
    } else if (index >= 1 && index < 40) {
        return self->field_detailsview_217.accessible_role(index - 0);
    } else return {};
}

auto Component_detailsview_217::accessible_string_property (uint32_t index, slint::cbindgen_private::AccessibleStringProperty what) const -> std::optional<slint::SharedString>{
    [[maybe_unused]] auto self = this;
    switch ((index << 8) | uintptr_t(what)) {
    }
    if (index == 0) {
        return self->field_detailsview_217.accessible_string_property(0, what);
    } else if (index >= 1 && index < 40) {
        return self->field_detailsview_217.accessible_string_property(index - 0, what);
    } else return {};
}

auto Component_detailsview_217::accessibility_action (uint32_t index, const slint::cbindgen_private::AccessibilityAction &action) const -> void{
    [[maybe_unused]] auto self = this;
    switch ((index << 8) | uintptr_t(action.tag)) {
    }
    if (index == 0) {
        return self->field_detailsview_217.accessibility_action(0, action);
    } else if (index >= 1 && index < 40) {
        return self->field_detailsview_217.accessibility_action(index - 0, action);
    } else return ;
}

auto Component_detailsview_217::supported_accessibility_actions (uint32_t index) const -> uint32_t{
    [[maybe_unused]] auto self = this;
    switch (index) {
    }
    if (index == 0) {
        return self->field_detailsview_217.supported_accessibility_actions(0);
    } else if (index >= 1 && index < 40) {
        return self->field_detailsview_217.supported_accessibility_actions(index - 0);
    } else return {};
}

auto Component_detailsview_217::element_infos (uint32_t index) const -> std::optional<slint::SharedString>{
    [[maybe_unused]] auto self = this;
    switch (index) {
    }
    if (index == 0) {
        return self->field_detailsview_217.element_infos(0);
    } else if (index >= 1 && index < 40) {
        return self->field_detailsview_217.element_infos(index - 0);
    } else return {};
}

auto Component_detailsview_217::ensure_instantiated () const -> bool{
    [[maybe_unused]] auto self = this;
    bool _changed = false;
    _changed |= self->field_detailsview_217.ensure_instantiated();
    return _changed;
}

auto Component_detailsview_217::visit_dynamic_children (uint32_t dyn_index, [[maybe_unused]] slint::private_api::TraversalOrder order, [[maybe_unused]] slint::private_api::ItemVisitorRefMut visitor) const -> uint64_t{
        auto self = this;
        switch(dyn_index) { 
        case 0: case 1: case 2: case 3: case 4: case 5: case 6: case 7: case 8: case 9: case 10:  {
                        return self->field_detailsview_217.visit_dynamic_children(dyn_index - 0, order, visitor);
                    } };
        std::abort();
}

auto Component_detailsview_217::subtree_range (uintptr_t dyn_index) const -> slint::private_api::IndexRange{
    [[maybe_unused]] auto self = this;
        switch(dyn_index) { 
        case 0: case 1: case 2: case 3: case 4: case 5: case 6: case 7: case 8: case 9: case 10:  {
                        return self->field_detailsview_217.subtree_range(dyn_index - 0);
                    } };
        std::abort();
}

auto Component_detailsview_217::subtree_component (uintptr_t dyn_index, [[maybe_unused]] uintptr_t subtree_index, [[maybe_unused]] slint::private_api::ItemTreeWeak *result) const -> void{
    [[maybe_unused]] auto self = this;
        switch(dyn_index) { 
        case 0: case 1: case 2: case 3: case 4: case 5: case 6: case 7: case 8: case 9: case 10:  {
                        self->field_detailsview_217.subtree_component(dyn_index - 0, subtree_index, result);
                        return;
                    } };
        std::abort();
}

auto Component_detailsview_217::visit_children (slint::private_api::ItemTreeRef component, intptr_t index, slint::private_api::TraversalOrder order, slint::private_api::ItemVisitorRefMut visitor) -> uint64_t{
    static const auto dyn_visit = [] (const void *base,  [[maybe_unused]] slint::private_api::TraversalOrder order, [[maybe_unused]] slint::private_api::ItemVisitorRefMut visitor, [[maybe_unused]] uint32_t dyn_index) -> uint64_t {
        [[maybe_unused]] auto self = reinterpret_cast<const Component_detailsview_217*>(base);
        return self->visit_dynamic_children(dyn_index, order, visitor);
    };
    auto self_rc = reinterpret_cast<const Component_detailsview_217*>(component.instance)->self_weak.lock()->into_dyn();
    return slint::cbindgen_private::slint_visit_item_tree(&self_rc, get_item_tree(component) , index, order, visitor, dyn_visit);
}

auto Component_detailsview_217::get_item_ref (slint::private_api::ItemTreeRef component, uint32_t index) -> slint::private_api::ItemRef{
    return slint::private_api::get_item_ref(component, get_item_tree(component), item_array(), index);
}

auto Component_detailsview_217::get_subtree_range ([[maybe_unused]] slint::private_api::ItemTreeRef component, [[maybe_unused]] uint32_t dyn_index) -> slint::private_api::IndexRange{
    auto self = reinterpret_cast<const Component_detailsview_217*>(component.instance);
    return self->subtree_range(dyn_index);
}

auto Component_detailsview_217::get_subtree ([[maybe_unused]] slint::private_api::ItemTreeRef component, [[maybe_unused]] uint32_t dyn_index, [[maybe_unused]] uintptr_t subtree_index, [[maybe_unused]] slint::private_api::ItemTreeWeak *result) -> void{
    auto self = reinterpret_cast<const Component_detailsview_217*>(component.instance);
    self->subtree_component(dyn_index, subtree_index, result);
}

auto Component_detailsview_217::get_item_tree (slint::private_api::ItemTreeRef) -> slint::cbindgen_private::Slice<slint::private_api::ItemTreeNode>{
    return item_tree();
}

auto Component_detailsview_217::parent_node ([[maybe_unused]] slint::private_api::ItemTreeRef component, [[maybe_unused]] slint::private_api::ItemWeak *result) -> void{
    auto self = reinterpret_cast<const Component_detailsview_217*>(component.instance);
    auto parent = self->parent.lock().value();
    *result = { parent->self_weak, parent->tree_index_of_first_child + 1 };
}

auto Component_detailsview_217::embed_component ([[maybe_unused]] slint::private_api::ItemTreeRef component, [[maybe_unused]] const slint::private_api::ItemTreeWeak *parent_component, [[maybe_unused]] const uint32_t parent_index) -> bool{
    return false; /* todo! */
}

auto Component_detailsview_217::subtree_index ([[maybe_unused]] slint::private_api::ItemTreeRef component) -> uintptr_t{
    return std::numeric_limits<uintptr_t>::max();
}

auto Component_detailsview_217::item_tree () -> slint::cbindgen_private::Slice<slint::private_api::ItemTreeNode>{
    static const slint::private_api::ItemTreeNode children[] {
        slint::private_api::make_item_node(4, 1, 0, 0, false), 
slint::private_api::make_item_node(2, 5, 0, 1, false), 
slint::private_api::make_item_node(1, 14, 0, 2, false), 
slint::private_api::make_dyn_node(9, 0), 
slint::private_api::make_dyn_node(10, 0), 
slint::private_api::make_item_node(2, 7, 1, 3, false), 
slint::private_api::make_item_node(1, 11, 1, 4, false), 
slint::private_api::make_item_node(0, 9, 5, 5, true), 
slint::private_api::make_item_node(2, 9, 5, 6, false), 
slint::private_api::make_item_node(0, 11, 8, 7, true), 
slint::private_api::make_item_node(0, 11, 8, 8, true), 
slint::private_api::make_item_node(2, 12, 6, 9, false), 
slint::private_api::make_item_node(0, 14, 11, 10, false), 
slint::private_api::make_item_node(0, 14, 11, 11, true), 
slint::private_api::make_item_node(6, 15, 2, 12, false), 
slint::private_api::make_item_node(5, 21, 14, 13, false), 
slint::private_api::make_dyn_node(2, 14), 
slint::private_api::make_item_node(3, 35, 14, 14, false), 
slint::private_api::make_dyn_node(6, 14), 
slint::private_api::make_dyn_node(7, 14), 
slint::private_api::make_dyn_node(8, 14), 
slint::private_api::make_dyn_node(0, 15), 
slint::private_api::make_dyn_node(1, 15), 
slint::private_api::make_item_node(3, 26, 15, 15, false), 
slint::private_api::make_item_node(0, 32, 15, 16, false), 
slint::private_api::make_item_node(1, 32, 15, 17, false), 
slint::private_api::make_item_node(2, 29, 23, 18, false), 
slint::private_api::make_item_node(0, 32, 23, 19, true), 
slint::private_api::make_item_node(0, 32, 23, 20, true), 
slint::private_api::make_item_node(0, 31, 26, 21, true), 
slint::private_api::make_item_node(1, 31, 26, 22, false), 
slint::private_api::make_item_node(0, 32, 30, 23, true), 
slint::private_api::make_item_node(2, 33, 25, 24, false), 
slint::private_api::make_item_node(0, 35, 32, 25, false), 
slint::private_api::make_item_node(0, 35, 32, 26, true), 
slint::private_api::make_item_node(2, 38, 17, 27, false), 
slint::private_api::make_dyn_node(4, 17), 
slint::private_api::make_dyn_node(5, 17), 
slint::private_api::make_item_node(0, 40, 35, 28, true), 
slint::private_api::make_dyn_node(3, 35) };
    return slint::private_api::make_slice(std::span(children));
}

auto Component_detailsview_217::item_array () -> const slint::private_api::ItemArray{
    static const slint::private_api::ItemArrayEntry items[] {
        { SLINT_GET_ITEM_VTABLE(RectangleVTable), offsetof(Component_detailsview_217, field_detailsview_217) +  offsetof(DetailsView_root_32, field_root_32) }, 
{ SLINT_GET_ITEM_VTABLE(BasicBorderRectangleVTable), offsetof(Component_detailsview_217, field_detailsview_217) +  offsetof(DetailsView_root_32, field_rectangle_34) }, 
{ SLINT_GET_ITEM_VTABLE(FlickableVTable), offsetof(Component_detailsview_217, field_detailsview_217) +  offsetof(DetailsView_root_32, field_flickable_45) }, 
{ SLINT_GET_ITEM_VTABLE(EmptyVTable), offsetof(Component_detailsview_217, field_detailsview_217) +  offsetof(DetailsView_root_32, field_empty_36) }, 
{ SLINT_GET_ITEM_VTABLE(EmptyVTable), offsetof(Component_detailsview_217, field_detailsview_217) +  offsetof(DetailsView_root_32, field_empty_41) }, 
{ SLINT_GET_ITEM_VTABLE(SimpleTextVTable), offsetof(Component_detailsview_217, field_detailsview_217) +  offsetof(DetailsView_root_32, field_text_37) }, 
{ SLINT_GET_ITEM_VTABLE(EmptyVTable), offsetof(Component_detailsview_217, field_detailsview_217) +  offsetof(DetailsView_root_32, field_empty_38) }, 
{ SLINT_GET_ITEM_VTABLE(SimpleTextVTable), offsetof(Component_detailsview_217, field_detailsview_217) +  offsetof(DetailsView_root_32, field_text_39) }, 
{ SLINT_GET_ITEM_VTABLE(SimpleTextVTable), offsetof(Component_detailsview_217, field_detailsview_217) +  offsetof(DetailsView_root_32, field_text_40) }, 
{ SLINT_GET_ITEM_VTABLE(BasicBorderRectangleVTable), offsetof(Component_detailsview_217, field_detailsview_217) +  offsetof(DetailsView_root_32, field_rectangle_42) }, 
{ SLINT_GET_ITEM_VTABLE(TouchAreaVTable), offsetof(Component_detailsview_217, field_detailsview_217) +  offsetof(DetailsView_root_32, field_back_ta_43) }, 
{ SLINT_GET_ITEM_VTABLE(SimpleTextVTable), offsetof(Component_detailsview_217, field_detailsview_217) +  offsetof(DetailsView_root_32, field_text_44) }, 
{ SLINT_GET_ITEM_VTABLE(EmptyVTable), offsetof(Component_detailsview_217, field_detailsview_217) +  offsetof(DetailsView_root_32, field__viewport_46) }, 
{ SLINT_GET_ITEM_VTABLE(EmptyVTable), offsetof(Component_detailsview_217, field_detailsview_217) +  offsetof(DetailsView_root_32, field_empty_48) }, 
{ SLINT_GET_ITEM_VTABLE(BasicBorderRectangleVTable), offsetof(Component_detailsview_217, field_detailsview_217) +  offsetof(DetailsView_root_32, field_rectangle_81) }, 
{ SLINT_GET_ITEM_VTABLE(EmptyVTable), offsetof(Component_detailsview_217, field_detailsview_217) +  offsetof(DetailsView_root_32, field_empty_53) }, 
{ SLINT_GET_ITEM_VTABLE(EmptyVTable), offsetof(Component_detailsview_217, field_detailsview_217) +  offsetof(DetailsView_root_32, field_rectangle_60) }, 
{ SLINT_GET_ITEM_VTABLE(EmptyVTable), offsetof(Component_detailsview_217, field_detailsview_217) +  offsetof(DetailsView_root_32, field_empty_61) }, 
{ SLINT_GET_ITEM_VTABLE(EmptyVTable), offsetof(Component_detailsview_217, field_detailsview_217) +  offsetof(DetailsView_root_32, field_empty_54) }, 
{ SLINT_GET_ITEM_VTABLE(ComplexTextVTable), offsetof(Component_detailsview_217, field_detailsview_217) +  offsetof(DetailsView_root_32, field_text_58) }, 
{ SLINT_GET_ITEM_VTABLE(SimpleTextVTable), offsetof(Component_detailsview_217, field_detailsview_217) +  offsetof(DetailsView_root_32, field_text_59) }, 
{ SLINT_GET_ITEM_VTABLE(ComplexTextVTable), offsetof(Component_detailsview_217, field_detailsview_217) +  offsetof(DetailsView_root_32, field_text_55) }, 
{ SLINT_GET_ITEM_VTABLE(BasicBorderRectangleVTable), offsetof(Component_detailsview_217, field_detailsview_217) +  offsetof(DetailsView_root_32, field_rectangle_56) }, 
{ SLINT_GET_ITEM_VTABLE(SimpleTextVTable), offsetof(Component_detailsview_217, field_detailsview_217) +  offsetof(DetailsView_root_32, field_instTxt_57) }, 
{ SLINT_GET_ITEM_VTABLE(BasicBorderRectangleVTable), offsetof(Component_detailsview_217, field_detailsview_217) +  offsetof(DetailsView_root_32, field_rectangle_62) }, 
{ SLINT_GET_ITEM_VTABLE(TouchAreaVTable), offsetof(Component_detailsview_217, field_detailsview_217) +  offsetof(DetailsView_root_32, field_toucharea_63) }, 
{ SLINT_GET_ITEM_VTABLE(SimpleTextVTable), offsetof(Component_detailsview_217, field_detailsview_217) +  offsetof(DetailsView_root_32, field_text_64) }, 
{ SLINT_GET_ITEM_VTABLE(EmptyVTable), offsetof(Component_detailsview_217, field_detailsview_217) +  offsetof(DetailsView_root_32, field_empty_83) }, 
{ SLINT_GET_ITEM_VTABLE(SimpleTextVTable), offsetof(Component_detailsview_217, field_detailsview_217) +  offsetof(DetailsView_root_32, field_text_84) } };
    return slint::private_api::make_slice(std::span(items));
}

auto Component_detailsview_217::layout_info ([[maybe_unused]] slint::private_api::ItemTreeRef component, slint::cbindgen_private::Orientation o) -> slint::cbindgen_private::LayoutInfo{
    return reinterpret_cast<const Component_detailsview_217*>(component.instance)->layout_info(o);
}

auto Component_detailsview_217::ensure_instantiated ([[maybe_unused]] slint::private_api::ItemTreeRef component) -> bool{
    return reinterpret_cast<const Component_detailsview_217*>(component.instance)->ensure_instantiated();
}

auto Component_detailsview_217::item_geometry ([[maybe_unused]] slint::private_api::ItemTreeRef component, uint32_t index) -> slint::cbindgen_private::LogicalRect{
    return reinterpret_cast<const Component_detailsview_217*>(component.instance)->item_geometry(index);
}

auto Component_detailsview_217::accessible_role ([[maybe_unused]] slint::private_api::ItemTreeRef component, uint32_t index) -> slint::cbindgen_private::AccessibleRole{
    return reinterpret_cast<const Component_detailsview_217*>(component.instance)->accessible_role(index);
}

auto Component_detailsview_217::accessible_string_property ([[maybe_unused]] slint::private_api::ItemTreeRef component, uint32_t index, slint::cbindgen_private::AccessibleStringProperty what, slint::SharedString *result) -> bool{
    if (auto r = reinterpret_cast<const Component_detailsview_217*>(component.instance)->accessible_string_property(index, what)) { *result = *r; return true; } else { return false; }
}

auto Component_detailsview_217::accessibility_action ([[maybe_unused]] slint::private_api::ItemTreeRef component, uint32_t index, const slint::cbindgen_private::AccessibilityAction *action) -> void{
    reinterpret_cast<const Component_detailsview_217*>(component.instance)->accessibility_action(index, *action);
}

auto Component_detailsview_217::supported_accessibility_actions ([[maybe_unused]] slint::private_api::ItemTreeRef component, uint32_t index) -> uint32_t{
    return reinterpret_cast<const Component_detailsview_217*>(component.instance)->supported_accessibility_actions(index);
}

auto Component_detailsview_217::element_infos ([[maybe_unused]] slint::private_api::ItemTreeRef component, [[maybe_unused]] uint32_t index, [[maybe_unused]] slint::SharedString *result) -> bool{
    return false;
}

auto Component_detailsview_217::window_adapter ([[maybe_unused]] slint::private_api::ItemTreeRef component, [[maybe_unused]] bool do_create, [[maybe_unused]] slint::cbindgen_private::Option<slint::private_api::WindowAdapterRc>* result) -> void{
    *reinterpret_cast<slint::private_api::WindowAdapterRc*>(result) = reinterpret_cast<const Component_detailsview_217*>(component.instance)->globals->window().window_handle();
}

auto Component_detailsview_217::create (class MainWindow const * parent) -> slint::ComponentHandle<Component_detailsview_217>{
    auto self_rc = vtable::VRc<slint::private_api::ItemTreeVTable, Component_detailsview_217>::make();
    auto self = const_cast<Component_detailsview_217 *>(&*self_rc);
    self->self_weak = vtable::VWeak(self_rc).into_dyn();
    slint::private_api::register_item_tree(&self_rc.into_dyn(), parent->globals->m_window);
    self->init(parent->globals, self->self_weak, 0, 1 , parent);
    return slint::ComponentHandle<Component_detailsview_217>{ self_rc };
}

Component_detailsview_217::~Component_detailsview_217 (){
    if (auto &window = globals->m_window) window->window_handle().unregister_item_tree(this, item_array());
}

auto Component_detailsview_217::init () -> void{
    user_init();
}

auto Component_detailsview_217::layout_item_info (slint::cbindgen_private::Orientation o, [[maybe_unused]] std::optional<size_t> child_index) const -> slint::cbindgen_private::LayoutItemInfo{
    return { layout_info({&static_vtable, const_cast<void *>(static_cast<const void *>(this))}, o) };
}

auto Component_detailsview_217::flexbox_layout_item_info (slint::cbindgen_private::Orientation o, [[maybe_unused]] std::optional<size_t> child_index) const -> slint::cbindgen_private::FlexboxLayoutItemInfo{
    auto base = layout_item_info(o, child_index); return { base.constraint, 0.0f, 0.0f, -1.0f, slint::cbindgen_private::FlexboxLayoutAlignSelf::Auto, 0 };
}

const slint::private_api::ItemTreeVTable MainWindow::static_vtable = { visit_children, get_item_ref, get_subtree_range, get_subtree, get_item_tree, parent_node, embed_component, subtree_index, layout_info, ensure_instantiated, item_geometry, accessible_role, accessible_string_property, accessibility_action, supported_accessibility_actions, element_infos, window_adapter, slint::private_api::drop_in_place<MainWindow>, slint::private_api::dealloc };

auto MainWindow::init (const class SharedGlobals* globals,slint::cbindgen_private::ItemTreeWeak enclosing_component,uint32_t tree_index,uint32_t tree_index_of_first_child) -> void{
    auto self = this;
    self->self_weak = enclosing_component;
    self->globals = globals;
    this->tree_index_of_first_child = tree_index_of_first_child;
    self->tree_index = tree_index;
    self->field_root_196.background.set(slint::Brush(slint::Color::from_argb_encoded(+4.280163886e9)));
    self->field_root_196_current_suggestions.set_binding([this]() {
                            [[maybe_unused]] auto self = this;
                            return std::make_shared<slint::private_api::ArrayModel<0,UiPackage>>();
                        });
    self->field_root_196_is_showing_details.set(false);
    self->field_root_196_packages.set_binding([this]() {
                            [[maybe_unused]] auto self = this;
                            return std::make_shared<slint::private_api::ArrayModel<0,UiPackage>>();
                        });
    self->field_root_196_search_query.set(slint::SharedString(u8""));
    self->field_root_196.title.set(slint::SharedString(u8"Tux Store"));
    self->field_root_196.always_on_top.set_constant();
    self->field_root_196.background.set_constant();
    self->field_root_196.default_font_family.set_constant();
    self->field_root_196.default_font_size.set_constant();
    self->field_root_196.default_font_weight.set_constant();
    self->field_root_196.icon.set_constant();
    self->field_root_196.no_frame.set_constant();
    self->field_root_196.resize_border_width.set_constant();
    self->field_root_196.title.set_constant();
    self->repeater_0.set_model_binding([self] { (void)self; return (! self->field_root_196_is_showing_details.get()); });
    self->repeater_1.set_model_binding([self] { (void)self; return self->field_root_196_is_showing_details.get(); });
}

auto MainWindow::user_init () -> void{
    [[maybe_unused]] auto self = this;
}

auto MainWindow::layout_info (slint::cbindgen_private::Orientation o) const -> slint::cbindgen_private::LayoutInfo{
    [[maybe_unused]] auto self = this;
    return o == slint::cbindgen_private::Orientation::Horizontal ? [&]{ [[maybe_unused]] auto layout_info = slint::private_api::item_layout_info(SLINT_GET_ITEM_VTABLE(WindowItemVTable), const_cast<slint::cbindgen_private::WindowItem*>(&self->field_root_196), slint::cbindgen_private::Orientation::Horizontal, -1, &self->globals->window().window_handle(), self->self_weak.lock()->into_dyn(), self->tree_index);;return [&](const auto &a_0, const auto &a_1, const auto &a_2, const auto &a_3, const auto &a_4, const auto &a_5){ slint::cbindgen_private::LayoutInfo o{}; o.max = a_0; o.max_percent = a_1; o.min = a_2; o.min_percent = a_3; o.preferred = a_4; o.stretch = a_5; return o; }(layout_info.max, layout_info.max_percent, layout_info.min, layout_info.min_percent, 1100, layout_info.stretch); }() : [&]{ [[maybe_unused]] auto layout_info = slint::private_api::item_layout_info(SLINT_GET_ITEM_VTABLE(WindowItemVTable), const_cast<slint::cbindgen_private::WindowItem*>(&self->field_root_196), slint::cbindgen_private::Orientation::Vertical, -1, &self->globals->window().window_handle(), self->self_weak.lock()->into_dyn(), self->tree_index);;return [&](const auto &a_0, const auto &a_1, const auto &a_2, const auto &a_3, const auto &a_4, const auto &a_5){ slint::cbindgen_private::LayoutInfo o{}; o.max = a_0; o.max_percent = a_1; o.min = a_2; o.min_percent = a_3; o.preferred = a_4; o.stretch = a_5; return o; }(layout_info.max, layout_info.max_percent, layout_info.min, layout_info.min_percent, 800, layout_info.stretch); }();
}

auto MainWindow::item_geometry (uint32_t index) const -> slint::cbindgen_private::Rect{
    [[maybe_unused]] auto self = this;
    switch (index) {
        case 0: return slint::private_api::convert_anonymous_rect(std::make_tuple(float(self->field_root_196.height.get()), float(self->field_root_196.width.get()), float(0), float(0)));
    }
    return {};
}

auto MainWindow::accessible_role (uint32_t index) const -> slint::cbindgen_private::AccessibleRole{
    [[maybe_unused]] auto self = this;
    switch (index) {
    }
    return {};
}

auto MainWindow::accessible_string_property (uint32_t index, slint::cbindgen_private::AccessibleStringProperty what) const -> std::optional<slint::SharedString>{
    [[maybe_unused]] auto self = this;
    switch ((index << 8) | uintptr_t(what)) {
    }
    return {};
}

auto MainWindow::accessibility_action (uint32_t index, const slint::cbindgen_private::AccessibilityAction &action) const -> void{
    [[maybe_unused]] auto self = this;
    switch ((index << 8) | uintptr_t(action.tag)) {
    }
    return ;
}

auto MainWindow::supported_accessibility_actions (uint32_t index) const -> uint32_t{
    [[maybe_unused]] auto self = this;
    switch (index) {
    }
    return {};
}

auto MainWindow::element_infos (uint32_t index) const -> std::optional<slint::SharedString>{
    [[maybe_unused]] auto self = this;
    switch (index) {
    }
    return {};
}

auto MainWindow::ensure_instantiated () const -> bool{
    [[maybe_unused]] auto self = this;
    bool _changed = false;
    _changed |= self->repeater_0.ensure_updated(self);
    _changed |= self->repeater_1.ensure_updated(self);
    return _changed;
}

auto MainWindow::visit_dynamic_children (uint32_t dyn_index, [[maybe_unused]] slint::private_api::TraversalOrder order, [[maybe_unused]] slint::private_api::ItemVisitorRefMut visitor) const -> uint64_t{
        auto self = this;
        switch(dyn_index) { 
        case 0: {
                return self->repeater_0.visit(order, visitor);
            }
        case 1: {
                return self->repeater_1.visit(order, visitor);
            } };
        std::abort();
}

auto MainWindow::subtree_range (uintptr_t dyn_index) const -> slint::private_api::IndexRange{
    [[maybe_unused]] auto self = this;
        switch(dyn_index) { 
        case 0: {
                self->repeater_0.track_instance_changes();
                return self->repeater_0.index_range();
            }
        case 1: {
                self->repeater_1.track_instance_changes();
                return self->repeater_1.index_range();
            } };
        std::abort();
}

auto MainWindow::subtree_component (uintptr_t dyn_index, [[maybe_unused]] uintptr_t subtree_index, [[maybe_unused]] slint::private_api::ItemTreeWeak *result) const -> void{
    [[maybe_unused]] auto self = this;
        switch(dyn_index) { 
        case 0: {
                *result = self->repeater_0.instance_at(subtree_index);
                return;
            }
        case 1: {
                *result = self->repeater_1.instance_at(subtree_index);
                return;
            } };
        std::abort();
}

auto MainWindow::visit_children (slint::private_api::ItemTreeRef component, intptr_t index, slint::private_api::TraversalOrder order, slint::private_api::ItemVisitorRefMut visitor) -> uint64_t{
    static const auto dyn_visit = [] (const void *base,  [[maybe_unused]] slint::private_api::TraversalOrder order, [[maybe_unused]] slint::private_api::ItemVisitorRefMut visitor, [[maybe_unused]] uint32_t dyn_index) -> uint64_t {
        [[maybe_unused]] auto self = reinterpret_cast<const MainWindow*>(base);
        return self->visit_dynamic_children(dyn_index, order, visitor);
    };
    auto self_rc = reinterpret_cast<const MainWindow*>(component.instance)->self_weak.lock()->into_dyn();
    return slint::cbindgen_private::slint_visit_item_tree(&self_rc, get_item_tree(component) , index, order, visitor, dyn_visit);
}

auto MainWindow::get_item_ref (slint::private_api::ItemTreeRef component, uint32_t index) -> slint::private_api::ItemRef{
    return slint::private_api::get_item_ref(component, get_item_tree(component), item_array(), index);
}

auto MainWindow::get_subtree_range ([[maybe_unused]] slint::private_api::ItemTreeRef component, [[maybe_unused]] uint32_t dyn_index) -> slint::private_api::IndexRange{
    auto self = reinterpret_cast<const MainWindow*>(component.instance);
    return self->subtree_range(dyn_index);
}

auto MainWindow::get_subtree ([[maybe_unused]] slint::private_api::ItemTreeRef component, [[maybe_unused]] uint32_t dyn_index, [[maybe_unused]] uintptr_t subtree_index, [[maybe_unused]] slint::private_api::ItemTreeWeak *result) -> void{
    auto self = reinterpret_cast<const MainWindow*>(component.instance);
    self->subtree_component(dyn_index, subtree_index, result);
}

auto MainWindow::get_item_tree (slint::private_api::ItemTreeRef) -> slint::cbindgen_private::Slice<slint::private_api::ItemTreeNode>{
    return item_tree();
}

auto MainWindow::parent_node ([[maybe_unused]] slint::private_api::ItemTreeRef component, [[maybe_unused]] slint::private_api::ItemWeak *result) -> void{
}

auto MainWindow::embed_component ([[maybe_unused]] slint::private_api::ItemTreeRef component, [[maybe_unused]] const slint::private_api::ItemTreeWeak *parent_component, [[maybe_unused]] const uint32_t parent_index) -> bool{
    return false; /* todo! */
}

auto MainWindow::subtree_index ([[maybe_unused]] slint::private_api::ItemTreeRef component) -> uintptr_t{
    return std::numeric_limits<uintptr_t>::max();
}

auto MainWindow::item_tree () -> slint::cbindgen_private::Slice<slint::private_api::ItemTreeNode>{
    static const slint::private_api::ItemTreeNode children[] {
        slint::private_api::make_item_node(2, 1, 0, 0, false), 
slint::private_api::make_dyn_node(0, 0), 
slint::private_api::make_dyn_node(1, 0) };
    return slint::private_api::make_slice(std::span(children));
}

auto MainWindow::item_array () -> const slint::private_api::ItemArray{
    static const slint::private_api::ItemArrayEntry items[] {
        { SLINT_GET_ITEM_VTABLE(WindowItemVTable),  offsetof(MainWindow, field_root_196) } };
    return slint::private_api::make_slice(std::span(items));
}

auto MainWindow::layout_info ([[maybe_unused]] slint::private_api::ItemTreeRef component, slint::cbindgen_private::Orientation o) -> slint::cbindgen_private::LayoutInfo{
    return reinterpret_cast<const MainWindow*>(component.instance)->layout_info(o);
}

auto MainWindow::ensure_instantiated ([[maybe_unused]] slint::private_api::ItemTreeRef component) -> bool{
    return reinterpret_cast<const MainWindow*>(component.instance)->ensure_instantiated();
}

auto MainWindow::item_geometry ([[maybe_unused]] slint::private_api::ItemTreeRef component, uint32_t index) -> slint::cbindgen_private::LogicalRect{
    return reinterpret_cast<const MainWindow*>(component.instance)->item_geometry(index);
}

auto MainWindow::accessible_role ([[maybe_unused]] slint::private_api::ItemTreeRef component, uint32_t index) -> slint::cbindgen_private::AccessibleRole{
    return reinterpret_cast<const MainWindow*>(component.instance)->accessible_role(index);
}

auto MainWindow::accessible_string_property ([[maybe_unused]] slint::private_api::ItemTreeRef component, uint32_t index, slint::cbindgen_private::AccessibleStringProperty what, slint::SharedString *result) -> bool{
    if (auto r = reinterpret_cast<const MainWindow*>(component.instance)->accessible_string_property(index, what)) { *result = *r; return true; } else { return false; }
}

auto MainWindow::accessibility_action ([[maybe_unused]] slint::private_api::ItemTreeRef component, uint32_t index, const slint::cbindgen_private::AccessibilityAction *action) -> void{
    reinterpret_cast<const MainWindow*>(component.instance)->accessibility_action(index, *action);
}

auto MainWindow::supported_accessibility_actions ([[maybe_unused]] slint::private_api::ItemTreeRef component, uint32_t index) -> uint32_t{
    return reinterpret_cast<const MainWindow*>(component.instance)->supported_accessibility_actions(index);
}

auto MainWindow::element_infos ([[maybe_unused]] slint::private_api::ItemTreeRef component, [[maybe_unused]] uint32_t index, [[maybe_unused]] slint::SharedString *result) -> bool{
    return false;
}

auto MainWindow::window_adapter ([[maybe_unused]] slint::private_api::ItemTreeRef component, [[maybe_unused]] bool do_create, [[maybe_unused]] slint::cbindgen_private::Option<slint::private_api::WindowAdapterRc>* result) -> void{
    *reinterpret_cast<slint::private_api::WindowAdapterRc*>(result) = reinterpret_cast<const MainWindow*>(component.instance)->globals->window().window_handle();
}

auto MainWindow::create () -> slint::ComponentHandle<MainWindow>{
    auto self_rc = vtable::VRc<slint::private_api::ItemTreeVTable, MainWindow>::make();
    auto self = const_cast<MainWindow *>(&*self_rc);
    self->self_weak = vtable::VWeak(self_rc).into_dyn();
    slint::cbindgen_private::slint_ensure_backend();
    self->globals = &self->m_globals;
    self->m_globals.root_weak = self->self_weak;
    slint::private_api::register_item_tree(&self_rc.into_dyn(), self->globals->m_window);
    self->init(self->globals, self->self_weak, 0, 1 );
    auto &window = self->globals->window();
    self->user_init();
    self->m_globals.window();
    slint::cbindgen_private::slint_windowrc_ensure_tree_instantiated(reinterpret_cast<const slint::cbindgen_private::WindowAdapterRcOpaque*>(&window.window_handle()));
    return slint::ComponentHandle<MainWindow>{ self_rc };
}

MainWindow::~MainWindow (){
    if (auto &window = globals->m_window) window->window_handle().unregister_item_tree(this, item_array());
}

auto MainWindow::invoke_app_clicked (UiPackage arg_0) const -> void{
    slint::private_api::assert_main_thread();
    [[maybe_unused]] auto self = this;
    return self->field_root_196_app_clicked.call(arg_0);
}

auto MainWindow::invoke_back_clicked () const -> void{
    slint::private_api::assert_main_thread();
    [[maybe_unused]] auto self = this;
    return self->field_root_196_back_clicked.call();
}

auto MainWindow::get_current_details () const -> UiPackageDetails{
    slint::private_api::assert_main_thread();
    [[maybe_unused]] auto self = this;
    return self->field_root_196_current_details.get();
}

auto MainWindow::set_current_details (const UiPackageDetails &value) const -> void{
    slint::private_api::assert_main_thread();
    [[maybe_unused]] auto self = this;
    self->field_root_196_current_details.set(value);
}

auto MainWindow::get_current_install () const -> UiInstallState{
    slint::private_api::assert_main_thread();
    [[maybe_unused]] auto self = this;
    return self->field_root_196_current_install.get();
}

auto MainWindow::set_current_install (const UiInstallState &value) const -> void{
    slint::private_api::assert_main_thread();
    [[maybe_unused]] auto self = this;
    self->field_root_196_current_install.set(value);
}

auto MainWindow::get_current_package () const -> UiPackage{
    slint::private_api::assert_main_thread();
    [[maybe_unused]] auto self = this;
    return self->field_root_196_current_package.get();
}

auto MainWindow::set_current_package (const UiPackage &value) const -> void{
    slint::private_api::assert_main_thread();
    [[maybe_unused]] auto self = this;
    self->field_root_196_current_package.set(value);
}

auto MainWindow::get_current_suggestions () const -> std::shared_ptr<slint::Model<UiPackage>>{
    slint::private_api::assert_main_thread();
    [[maybe_unused]] auto self = this;
    return self->field_root_196_current_suggestions.get();
}

auto MainWindow::set_current_suggestions (const std::shared_ptr<slint::Model<UiPackage>> &value) const -> void{
    slint::private_api::assert_main_thread();
    [[maybe_unused]] auto self = this;
    self->field_root_196_current_suggestions.set(value);
}

auto MainWindow::invoke_install_clicked (UiPackage arg_0) const -> void{
    slint::private_api::assert_main_thread();
    [[maybe_unused]] auto self = this;
    return self->field_root_196_install_clicked.call(arg_0);
}

auto MainWindow::get_is_showing_details () const -> bool{
    slint::private_api::assert_main_thread();
    [[maybe_unused]] auto self = this;
    return self->field_root_196_is_showing_details.get();
}

auto MainWindow::set_is_showing_details (const bool &value) const -> void{
    slint::private_api::assert_main_thread();
    [[maybe_unused]] auto self = this;
    self->field_root_196_is_showing_details.set(value);
}

auto MainWindow::get_packages () const -> std::shared_ptr<slint::Model<UiPackage>>{
    slint::private_api::assert_main_thread();
    [[maybe_unused]] auto self = this;
    return self->field_root_196_packages.get();
}

auto MainWindow::set_packages (const std::shared_ptr<slint::Model<UiPackage>> &value) const -> void{
    slint::private_api::assert_main_thread();
    [[maybe_unused]] auto self = this;
    self->field_root_196_packages.set(value);
}

auto MainWindow::invoke_remove_clicked (UiPackage arg_0, slint::SharedString arg_1) const -> void{
    slint::private_api::assert_main_thread();
    [[maybe_unused]] auto self = this;
    return self->field_root_196_remove_clicked.call(arg_0, arg_1);
}

auto MainWindow::invoke_search_changed (slint::SharedString arg_0) const -> void{
    slint::private_api::assert_main_thread();
    [[maybe_unused]] auto self = this;
    return self->field_root_196_search_changed.call(arg_0);
}

auto MainWindow::get_search_query () const -> slint::SharedString{
    slint::private_api::assert_main_thread();
    [[maybe_unused]] auto self = this;
    return self->field_root_196_search_query.get();
}

auto MainWindow::set_search_query (const slint::SharedString &value) const -> void{
    slint::private_api::assert_main_thread();
    [[maybe_unused]] auto self = this;
    self->field_root_196_search_query.set(value);
}

auto MainWindow::show () -> void{
    m_globals.window().show();
}

auto MainWindow::hide () -> void{
    m_globals.window().hide();
}

auto MainWindow::window () const -> slint::Window&{
    return m_globals.window();
}

auto MainWindow::run () -> void{
    show();
    slint::run_event_loop();
    hide();
}
