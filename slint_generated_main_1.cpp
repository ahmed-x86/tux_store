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
                            return [&]{ [[maybe_unused]] auto tmp_Theme_76_accents = self->globals->global_Theme_76->field_accents.get();;return slint::Brush(slint::private_api::access_array_index(tmp_Theme_76_accents, ([](float a, float b) { auto r = std::fmod(a, b); return r >= 0 ? r : r + std::abs(b); })(slint::private_api::optional_or_default(slint::private_api::optional_transform(self->parent.lock(), [&](auto&&x) { return x->field_root_1_accent_idx.get(); })),slint::private_api::model_length(tmp_Theme_76_accents)))); }();
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

const slint::private_api::ItemTreeVTable Component_image_19::static_vtable = { visit_children, get_item_ref, get_subtree_range, get_subtree, get_item_tree, parent_node, embed_component, subtree_index, layout_info, ensure_instantiated, item_geometry, accessible_role, accessible_string_property, accessibility_action, supported_accessibility_actions, element_infos, window_adapter, slint::private_api::drop_in_place<Component_image_19>, slint::private_api::dealloc };

auto Component_image_19::init (const class SharedGlobals* globals,slint::cbindgen_private::ItemTreeWeak enclosing_component,uint32_t tree_index,uint32_t tree_index_of_first_child,class DetailsView_root_14 const *parent) -> void{
    auto self = this;
    self->self_weak = enclosing_component;
    self->globals = globals;
    this->tree_index_of_first_child = tree_index_of_first_child;
    self->tree_index = tree_index;
    self->parent = vtable::VRcMapped<slint::private_api::ItemTreeVTable, const DetailsView_root_14>(parent->self_weak.lock().value(), parent);
    self->field_image_19.height.set(100);
    self->field_image_19.source.set_binding([this]() {
                            [[maybe_unused]] auto self = this;
                            return slint::private_api::optional_or_default(slint::private_api::optional_transform(self->parent.lock(), [&](auto&&x) { return x->field_root_14_pkg.get(); })).icon;
                        });
    self->field_image_19.width.set(100);
    self->field_image_19.colorize.set_constant();
    self->field_image_19.height.set_constant();
    self->field_image_19.image_fit.set_constant();
    self->field_image_19.image_rendering.set_constant();
    self->field_image_19.width.set_constant();
}

auto Component_image_19::user_init () -> void{
    [[maybe_unused]] auto self = this;
}

auto Component_image_19::layout_info (slint::cbindgen_private::Orientation o) const -> slint::cbindgen_private::LayoutInfo{
    [[maybe_unused]] auto self = this;
    return o == slint::cbindgen_private::Orientation::Horizontal ? [&]{ [[maybe_unused]] auto layout_info = slint::private_api::item_layout_info(SLINT_GET_ITEM_VTABLE(ImageItemVTable), const_cast<slint::cbindgen_private::ImageItem*>(&self->field_image_19), slint::cbindgen_private::Orientation::Horizontal, -1, &self->globals->window().window_handle(), self->self_weak.lock()->into_dyn(), self->tree_index);;return [&](const auto &a_0, const auto &a_1, const auto &a_2, const auto &a_3, const auto &a_4, const auto &a_5){ slint::cbindgen_private::LayoutInfo o{}; o.max = a_0; o.max_percent = a_1; o.min = a_2; o.min_percent = a_3; o.preferred = a_4; o.stretch = a_5; return o; }(100, layout_info.max_percent, 100, layout_info.min_percent, layout_info.preferred, layout_info.stretch); }() : [&]{ [[maybe_unused]] auto layout_info = slint::private_api::item_layout_info(SLINT_GET_ITEM_VTABLE(ImageItemVTable), const_cast<slint::cbindgen_private::ImageItem*>(&self->field_image_19), slint::cbindgen_private::Orientation::Vertical, -1, &self->globals->window().window_handle(), self->self_weak.lock()->into_dyn(), self->tree_index);;return [&](const auto &a_0, const auto &a_1, const auto &a_2, const auto &a_3, const auto &a_4, const auto &a_5){ slint::cbindgen_private::LayoutInfo o{}; o.max = a_0; o.max_percent = a_1; o.min = a_2; o.min_percent = a_3; o.preferred = a_4; o.stretch = a_5; return o; }(100, layout_info.max_percent, 100, layout_info.min_percent, layout_info.preferred, layout_info.stretch); }();
}

auto Component_image_19::item_geometry (uint32_t index) const -> slint::cbindgen_private::Rect{
    [[maybe_unused]] auto self = this;
    switch (index) {
        case 0: return slint::private_api::convert_anonymous_rect(std::make_tuple(float(100), float(100), float(slint::private_api::optional_or_default(slint::private_api::optional_transform(self->parent.lock(), [&](auto&&x) { return slint::private_api::layout_cache_access(x->field_root_14_empty_18_layout_cache.get(), 0, 0, 2); }))), float(0)));
    }
    return {};
}

auto Component_image_19::accessible_role (uint32_t index) const -> slint::cbindgen_private::AccessibleRole{
    [[maybe_unused]] auto self = this;
    switch (index) {
        case 0: return slint::cbindgen_private::AccessibleRole::Image;
    }
    return {};
}

auto Component_image_19::accessible_string_property (uint32_t index, slint::cbindgen_private::AccessibleStringProperty what) const -> std::optional<slint::SharedString>{
    [[maybe_unused]] auto self = this;
    switch ((index << 8) | uintptr_t(what)) {
    }
    return {};
}

auto Component_image_19::accessibility_action (uint32_t index, const slint::cbindgen_private::AccessibilityAction &action) const -> void{
    [[maybe_unused]] auto self = this;
    switch ((index << 8) | uintptr_t(action.tag)) {
    }
    return ;
}

auto Component_image_19::supported_accessibility_actions (uint32_t index) const -> uint32_t{
    [[maybe_unused]] auto self = this;
    switch (index) {
    }
    return {};
}

auto Component_image_19::element_infos (uint32_t index) const -> std::optional<slint::SharedString>{
    [[maybe_unused]] auto self = this;
    switch (index) {
    }
    return {};
}

auto Component_image_19::ensure_instantiated () const -> bool{
    [[maybe_unused]] auto self = this;
    bool _changed = false;
    return _changed;
}

auto Component_image_19::visit_children (slint::private_api::ItemTreeRef component, intptr_t index, slint::private_api::TraversalOrder order, slint::private_api::ItemVisitorRefMut visitor) -> uint64_t{
    static const auto dyn_visit = [] (const void *base,  [[maybe_unused]] slint::private_api::TraversalOrder order, [[maybe_unused]] slint::private_api::ItemVisitorRefMut visitor, [[maybe_unused]] uint32_t dyn_index) -> uint64_t {
        [[maybe_unused]] auto self = reinterpret_cast<const Component_image_19*>(base);
        std::abort();
    };
    auto self_rc = reinterpret_cast<const Component_image_19*>(component.instance)->self_weak.lock()->into_dyn();
    return slint::cbindgen_private::slint_visit_item_tree(&self_rc, get_item_tree(component) , index, order, visitor, dyn_visit);
}

auto Component_image_19::get_item_ref (slint::private_api::ItemTreeRef component, uint32_t index) -> slint::private_api::ItemRef{
    return slint::private_api::get_item_ref(component, get_item_tree(component), item_array(), index);
}

auto Component_image_19::get_subtree_range ([[maybe_unused]] slint::private_api::ItemTreeRef component, [[maybe_unused]] uint32_t dyn_index) -> slint::private_api::IndexRange{
        std::abort();
}

auto Component_image_19::get_subtree ([[maybe_unused]] slint::private_api::ItemTreeRef component, [[maybe_unused]] uint32_t dyn_index, [[maybe_unused]] uintptr_t subtree_index, [[maybe_unused]] slint::private_api::ItemTreeWeak *result) -> void{
        std::abort();
}

auto Component_image_19::get_item_tree (slint::private_api::ItemTreeRef) -> slint::cbindgen_private::Slice<slint::private_api::ItemTreeNode>{
    return item_tree();
}

auto Component_image_19::parent_node ([[maybe_unused]] slint::private_api::ItemTreeRef component, [[maybe_unused]] slint::private_api::ItemWeak *result) -> void{
    auto self = reinterpret_cast<const Component_image_19*>(component.instance);
    auto parent = self->parent.lock().value();
    *result = { parent->self_weak, parent->tree_index_of_first_child + 7 };
}

auto Component_image_19::embed_component ([[maybe_unused]] slint::private_api::ItemTreeRef component, [[maybe_unused]] const slint::private_api::ItemTreeWeak *parent_component, [[maybe_unused]] const uint32_t parent_index) -> bool{
    return false; /* todo! */
}

auto Component_image_19::subtree_index ([[maybe_unused]] slint::private_api::ItemTreeRef component) -> uintptr_t{
    return std::numeric_limits<uintptr_t>::max();
}

auto Component_image_19::item_tree () -> slint::cbindgen_private::Slice<slint::private_api::ItemTreeNode>{
    static const slint::private_api::ItemTreeNode children[] {
        slint::private_api::make_item_node(0, 1, 0, 0, true) };
    return slint::private_api::make_slice(std::span(children));
}

auto Component_image_19::item_array () -> const slint::private_api::ItemArray{
    static const slint::private_api::ItemArrayEntry items[] {
        { SLINT_GET_ITEM_VTABLE(ImageItemVTable),  offsetof(Component_image_19, field_image_19) } };
    return slint::private_api::make_slice(std::span(items));
}

auto Component_image_19::layout_info ([[maybe_unused]] slint::private_api::ItemTreeRef component, slint::cbindgen_private::Orientation o) -> slint::cbindgen_private::LayoutInfo{
    return reinterpret_cast<const Component_image_19*>(component.instance)->layout_info(o);
}

auto Component_image_19::ensure_instantiated ([[maybe_unused]] slint::private_api::ItemTreeRef component) -> bool{
    return reinterpret_cast<const Component_image_19*>(component.instance)->ensure_instantiated();
}

auto Component_image_19::item_geometry ([[maybe_unused]] slint::private_api::ItemTreeRef component, uint32_t index) -> slint::cbindgen_private::LogicalRect{
    return reinterpret_cast<const Component_image_19*>(component.instance)->item_geometry(index);
}

auto Component_image_19::accessible_role ([[maybe_unused]] slint::private_api::ItemTreeRef component, uint32_t index) -> slint::cbindgen_private::AccessibleRole{
    return reinterpret_cast<const Component_image_19*>(component.instance)->accessible_role(index);
}

auto Component_image_19::accessible_string_property ([[maybe_unused]] slint::private_api::ItemTreeRef component, uint32_t index, slint::cbindgen_private::AccessibleStringProperty what, slint::SharedString *result) -> bool{
    if (auto r = reinterpret_cast<const Component_image_19*>(component.instance)->accessible_string_property(index, what)) { *result = *r; return true; } else { return false; }
}

auto Component_image_19::accessibility_action ([[maybe_unused]] slint::private_api::ItemTreeRef component, uint32_t index, const slint::cbindgen_private::AccessibilityAction *action) -> void{
    reinterpret_cast<const Component_image_19*>(component.instance)->accessibility_action(index, *action);
}

auto Component_image_19::supported_accessibility_actions ([[maybe_unused]] slint::private_api::ItemTreeRef component, uint32_t index) -> uint32_t{
    return reinterpret_cast<const Component_image_19*>(component.instance)->supported_accessibility_actions(index);
}

auto Component_image_19::element_infos ([[maybe_unused]] slint::private_api::ItemTreeRef component, [[maybe_unused]] uint32_t index, [[maybe_unused]] slint::SharedString *result) -> bool{
    return false;
}

auto Component_image_19::window_adapter ([[maybe_unused]] slint::private_api::ItemTreeRef component, [[maybe_unused]] bool do_create, [[maybe_unused]] slint::cbindgen_private::Option<slint::private_api::WindowAdapterRc>* result) -> void{
    *reinterpret_cast<slint::private_api::WindowAdapterRc*>(result) = reinterpret_cast<const Component_image_19*>(component.instance)->globals->window().window_handle();
}

auto Component_image_19::create (class DetailsView_root_14 const * parent) -> slint::ComponentHandle<Component_image_19>{
    auto self_rc = vtable::VRc<slint::private_api::ItemTreeVTable, Component_image_19>::make();
    auto self = const_cast<Component_image_19 *>(&*self_rc);
    self->self_weak = vtable::VWeak(self_rc).into_dyn();
    slint::private_api::register_item_tree(&self_rc.into_dyn(), parent->globals->m_window);
    self->init(parent->globals, self->self_weak, 0, 1 , parent);
    return slint::ComponentHandle<Component_image_19>{ self_rc };
}

Component_image_19::~Component_image_19 (){
    if (auto &window = globals->m_window) window->window_handle().unregister_item_tree(this, item_array());
}

auto Component_image_19::init () -> void{
    user_init();
}

auto Component_image_19::layout_item_info (slint::cbindgen_private::Orientation o, [[maybe_unused]] std::optional<size_t> child_index) const -> slint::cbindgen_private::LayoutItemInfo{
    return { layout_info({&static_vtable, const_cast<void *>(static_cast<const void *>(this))}, o) };
}

auto Component_image_19::flexbox_layout_item_info (slint::cbindgen_private::Orientation o, [[maybe_unused]] std::optional<size_t> child_index) const -> slint::cbindgen_private::FlexboxLayoutItemInfo{
    auto base = layout_item_info(o, child_index); return { base.constraint, 0.0f, 0.0f, -1.0f, slint::cbindgen_private::FlexboxLayoutAlignSelf::Auto, 0 };
}

const slint::private_api::ItemTreeVTable Component_rectangle_21::static_vtable = { visit_children, get_item_ref, get_subtree_range, get_subtree, get_item_tree, parent_node, embed_component, subtree_index, layout_info, ensure_instantiated, item_geometry, accessible_role, accessible_string_property, accessibility_action, supported_accessibility_actions, element_infos, window_adapter, slint::private_api::drop_in_place<Component_rectangle_21>, slint::private_api::dealloc };

auto Component_rectangle_21::init (const class SharedGlobals* globals,slint::cbindgen_private::ItemTreeWeak enclosing_component,uint32_t tree_index,uint32_t tree_index_of_first_child,class DetailsView_root_14 const *parent) -> void{
    auto self = this;
    self->self_weak = enclosing_component;
    self->globals = globals;
    this->tree_index_of_first_child = tree_index_of_first_child;
    self->tree_index = tree_index;
    self->parent = vtable::VRcMapped<slint::private_api::ItemTreeVTable, const DetailsView_root_14>(parent->self_weak.lock().value(), parent);
    self->field_rectangle_21.background.set_binding([this]() {
                            [[maybe_unused]] auto self = this;
                            return [&]{ [[maybe_unused]] auto tmp_Theme_76_accents = self->globals->global_Theme_76->field_accents.get();;return slint::Brush(slint::private_api::access_array_index(tmp_Theme_76_accents, ([](float a, float b) { auto r = std::fmod(a, b); return r >= 0 ? r : r + std::abs(b); })(slint::private_api::optional_or_default(slint::private_api::optional_transform(self->parent.lock(), [&](auto&&x) { return x->field_root_14_accent_idx.get(); })),slint::private_api::model_length(tmp_Theme_76_accents)))); }();
                        });
    self->field_rectangle_21.border_radius.set(20);
    self->field_rectangle_21.border_color.set_constant();
    self->field_rectangle_21.border_radius.set_constant();
    self->field_rectangle_21.border_width.set_constant();
}

auto Component_rectangle_21::user_init () -> void{
    [[maybe_unused]] auto self = this;
}

auto Component_rectangle_21::layout_info (slint::cbindgen_private::Orientation o) const -> slint::cbindgen_private::LayoutInfo{
    [[maybe_unused]] auto self = this;
    return o == slint::cbindgen_private::Orientation::Horizontal ? [&]{ [[maybe_unused]] auto layout_info = slint::private_api::item_layout_info(SLINT_GET_ITEM_VTABLE(BasicBorderRectangleVTable), const_cast<slint::cbindgen_private::BasicBorderRectangle*>(&self->field_rectangle_21), slint::cbindgen_private::Orientation::Horizontal, -1, &self->globals->window().window_handle(), self->self_weak.lock()->into_dyn(), self->tree_index);;return [&](const auto &a_0, const auto &a_1, const auto &a_2, const auto &a_3, const auto &a_4, const auto &a_5){ slint::cbindgen_private::LayoutInfo o{}; o.max = a_0; o.max_percent = a_1; o.min = a_2; o.min_percent = a_3; o.preferred = a_4; o.stretch = a_5; return o; }(100, layout_info.max_percent, 100, layout_info.min_percent, layout_info.preferred, layout_info.stretch); }() : [&]{ [[maybe_unused]] auto layout_info = slint::private_api::item_layout_info(SLINT_GET_ITEM_VTABLE(BasicBorderRectangleVTable), const_cast<slint::cbindgen_private::BasicBorderRectangle*>(&self->field_rectangle_21), slint::cbindgen_private::Orientation::Vertical, -1, &self->globals->window().window_handle(), self->self_weak.lock()->into_dyn(), self->tree_index);;return [&](const auto &a_0, const auto &a_1, const auto &a_2, const auto &a_3, const auto &a_4, const auto &a_5){ slint::cbindgen_private::LayoutInfo o{}; o.max = a_0; o.max_percent = a_1; o.min = a_2; o.min_percent = a_3; o.preferred = a_4; o.stretch = a_5; return o; }(100, layout_info.max_percent, 100, layout_info.min_percent, layout_info.preferred, layout_info.stretch); }();
}

auto Component_rectangle_21::item_geometry (uint32_t index) const -> slint::cbindgen_private::Rect{
    [[maybe_unused]] auto self = this;
    switch (index) {
        case 0: return slint::private_api::convert_anonymous_rect(std::make_tuple(float(100), float(100), float(slint::private_api::optional_or_default(slint::private_api::optional_transform(self->parent.lock(), [&](auto&&x) { return slint::private_api::layout_cache_access(x->field_root_14_empty_18_layout_cache.get(), 2, 0, 2); }))), float(0)));
    }
    return {};
}

auto Component_rectangle_21::accessible_role (uint32_t index) const -> slint::cbindgen_private::AccessibleRole{
    [[maybe_unused]] auto self = this;
    switch (index) {
    }
    return {};
}

auto Component_rectangle_21::accessible_string_property (uint32_t index, slint::cbindgen_private::AccessibleStringProperty what) const -> std::optional<slint::SharedString>{
    [[maybe_unused]] auto self = this;
    switch ((index << 8) | uintptr_t(what)) {
    }
    return {};
}

auto Component_rectangle_21::accessibility_action (uint32_t index, const slint::cbindgen_private::AccessibilityAction &action) const -> void{
    [[maybe_unused]] auto self = this;
    switch ((index << 8) | uintptr_t(action.tag)) {
    }
    return ;
}

auto Component_rectangle_21::supported_accessibility_actions (uint32_t index) const -> uint32_t{
    [[maybe_unused]] auto self = this;
    switch (index) {
    }
    return {};
}

auto Component_rectangle_21::element_infos (uint32_t index) const -> std::optional<slint::SharedString>{
    [[maybe_unused]] auto self = this;
    switch (index) {
    }
    return {};
}

auto Component_rectangle_21::ensure_instantiated () const -> bool{
    [[maybe_unused]] auto self = this;
    bool _changed = false;
    return _changed;
}

auto Component_rectangle_21::visit_children (slint::private_api::ItemTreeRef component, intptr_t index, slint::private_api::TraversalOrder order, slint::private_api::ItemVisitorRefMut visitor) -> uint64_t{
    static const auto dyn_visit = [] (const void *base,  [[maybe_unused]] slint::private_api::TraversalOrder order, [[maybe_unused]] slint::private_api::ItemVisitorRefMut visitor, [[maybe_unused]] uint32_t dyn_index) -> uint64_t {
        [[maybe_unused]] auto self = reinterpret_cast<const Component_rectangle_21*>(base);
        std::abort();
    };
    auto self_rc = reinterpret_cast<const Component_rectangle_21*>(component.instance)->self_weak.lock()->into_dyn();
    return slint::cbindgen_private::slint_visit_item_tree(&self_rc, get_item_tree(component) , index, order, visitor, dyn_visit);
}

auto Component_rectangle_21::get_item_ref (slint::private_api::ItemTreeRef component, uint32_t index) -> slint::private_api::ItemRef{
    return slint::private_api::get_item_ref(component, get_item_tree(component), item_array(), index);
}

auto Component_rectangle_21::get_subtree_range ([[maybe_unused]] slint::private_api::ItemTreeRef component, [[maybe_unused]] uint32_t dyn_index) -> slint::private_api::IndexRange{
        std::abort();
}

auto Component_rectangle_21::get_subtree ([[maybe_unused]] slint::private_api::ItemTreeRef component, [[maybe_unused]] uint32_t dyn_index, [[maybe_unused]] uintptr_t subtree_index, [[maybe_unused]] slint::private_api::ItemTreeWeak *result) -> void{
        std::abort();
}

auto Component_rectangle_21::get_item_tree (slint::private_api::ItemTreeRef) -> slint::cbindgen_private::Slice<slint::private_api::ItemTreeNode>{
    return item_tree();
}

auto Component_rectangle_21::parent_node ([[maybe_unused]] slint::private_api::ItemTreeRef component, [[maybe_unused]] slint::private_api::ItemWeak *result) -> void{
    auto self = reinterpret_cast<const Component_rectangle_21*>(component.instance);
    auto parent = self->parent.lock().value();
    *result = { parent->self_weak, parent->tree_index_of_first_child + 8 };
}

auto Component_rectangle_21::embed_component ([[maybe_unused]] slint::private_api::ItemTreeRef component, [[maybe_unused]] const slint::private_api::ItemTreeWeak *parent_component, [[maybe_unused]] const uint32_t parent_index) -> bool{
    return false; /* todo! */
}

auto Component_rectangle_21::subtree_index ([[maybe_unused]] slint::private_api::ItemTreeRef component) -> uintptr_t{
    return std::numeric_limits<uintptr_t>::max();
}

auto Component_rectangle_21::item_tree () -> slint::cbindgen_private::Slice<slint::private_api::ItemTreeNode>{
    static const slint::private_api::ItemTreeNode children[] {
        slint::private_api::make_item_node(0, 1, 0, 0, false) };
    return slint::private_api::make_slice(std::span(children));
}

auto Component_rectangle_21::item_array () -> const slint::private_api::ItemArray{
    static const slint::private_api::ItemArrayEntry items[] {
        { SLINT_GET_ITEM_VTABLE(BasicBorderRectangleVTable),  offsetof(Component_rectangle_21, field_rectangle_21) } };
    return slint::private_api::make_slice(std::span(items));
}

auto Component_rectangle_21::layout_info ([[maybe_unused]] slint::private_api::ItemTreeRef component, slint::cbindgen_private::Orientation o) -> slint::cbindgen_private::LayoutInfo{
    return reinterpret_cast<const Component_rectangle_21*>(component.instance)->layout_info(o);
}

auto Component_rectangle_21::ensure_instantiated ([[maybe_unused]] slint::private_api::ItemTreeRef component) -> bool{
    return reinterpret_cast<const Component_rectangle_21*>(component.instance)->ensure_instantiated();
}

auto Component_rectangle_21::item_geometry ([[maybe_unused]] slint::private_api::ItemTreeRef component, uint32_t index) -> slint::cbindgen_private::LogicalRect{
    return reinterpret_cast<const Component_rectangle_21*>(component.instance)->item_geometry(index);
}

auto Component_rectangle_21::accessible_role ([[maybe_unused]] slint::private_api::ItemTreeRef component, uint32_t index) -> slint::cbindgen_private::AccessibleRole{
    return reinterpret_cast<const Component_rectangle_21*>(component.instance)->accessible_role(index);
}

auto Component_rectangle_21::accessible_string_property ([[maybe_unused]] slint::private_api::ItemTreeRef component, uint32_t index, slint::cbindgen_private::AccessibleStringProperty what, slint::SharedString *result) -> bool{
    if (auto r = reinterpret_cast<const Component_rectangle_21*>(component.instance)->accessible_string_property(index, what)) { *result = *r; return true; } else { return false; }
}

auto Component_rectangle_21::accessibility_action ([[maybe_unused]] slint::private_api::ItemTreeRef component, uint32_t index, const slint::cbindgen_private::AccessibilityAction *action) -> void{
    reinterpret_cast<const Component_rectangle_21*>(component.instance)->accessibility_action(index, *action);
}

auto Component_rectangle_21::supported_accessibility_actions ([[maybe_unused]] slint::private_api::ItemTreeRef component, uint32_t index) -> uint32_t{
    return reinterpret_cast<const Component_rectangle_21*>(component.instance)->supported_accessibility_actions(index);
}

auto Component_rectangle_21::element_infos ([[maybe_unused]] slint::private_api::ItemTreeRef component, [[maybe_unused]] uint32_t index, [[maybe_unused]] slint::SharedString *result) -> bool{
    return false;
}

auto Component_rectangle_21::window_adapter ([[maybe_unused]] slint::private_api::ItemTreeRef component, [[maybe_unused]] bool do_create, [[maybe_unused]] slint::cbindgen_private::Option<slint::private_api::WindowAdapterRc>* result) -> void{
    *reinterpret_cast<slint::private_api::WindowAdapterRc*>(result) = reinterpret_cast<const Component_rectangle_21*>(component.instance)->globals->window().window_handle();
}

auto Component_rectangle_21::create (class DetailsView_root_14 const * parent) -> slint::ComponentHandle<Component_rectangle_21>{
    auto self_rc = vtable::VRc<slint::private_api::ItemTreeVTable, Component_rectangle_21>::make();
    auto self = const_cast<Component_rectangle_21 *>(&*self_rc);
    self->self_weak = vtable::VWeak(self_rc).into_dyn();
    slint::private_api::register_item_tree(&self_rc.into_dyn(), parent->globals->m_window);
    self->init(parent->globals, self->self_weak, 0, 1 , parent);
    return slint::ComponentHandle<Component_rectangle_21>{ self_rc };
}

Component_rectangle_21::~Component_rectangle_21 (){
    if (auto &window = globals->m_window) window->window_handle().unregister_item_tree(this, item_array());
}

auto Component_rectangle_21::init () -> void{
    user_init();
}

auto Component_rectangle_21::layout_item_info (slint::cbindgen_private::Orientation o, [[maybe_unused]] std::optional<size_t> child_index) const -> slint::cbindgen_private::LayoutItemInfo{
    return { layout_info({&static_vtable, const_cast<void *>(static_cast<const void *>(this))}, o) };
}

auto Component_rectangle_21::flexbox_layout_item_info (slint::cbindgen_private::Orientation o, [[maybe_unused]] std::optional<size_t> child_index) const -> slint::cbindgen_private::FlexboxLayoutItemInfo{
    auto base = layout_item_info(o, child_index); return { base.constraint, 0.0f, 0.0f, -1.0f, slint::cbindgen_private::FlexboxLayoutAlignSelf::Auto, 0 };
}

const slint::private_api::ItemTreeVTable Component_text_34::static_vtable = { visit_children, get_item_ref, get_subtree_range, get_subtree, get_item_tree, parent_node, embed_component, subtree_index, layout_info, ensure_instantiated, item_geometry, accessible_role, accessible_string_property, accessibility_action, supported_accessibility_actions, element_infos, window_adapter, slint::private_api::drop_in_place<Component_text_34>, slint::private_api::dealloc };

auto Component_text_34::init (const class SharedGlobals* globals,slint::cbindgen_private::ItemTreeWeak enclosing_component,uint32_t tree_index,uint32_t tree_index_of_first_child,class DetailsView_root_14 const *parent) -> void{
    auto self = this;
    self->self_weak = enclosing_component;
    self->globals = globals;
    this->tree_index_of_first_child = tree_index_of_first_child;
    self->tree_index = tree_index;
    self->parent = vtable::VRcMapped<slint::private_api::ItemTreeVTable, const DetailsView_root_14>(parent->self_weak.lock().value(), parent);
    self->field_text_34.color.set(slint::Brush(slint::Color::from_argb_encoded(+4.2865471e9)));
    self->field_text_34.font_size.set(13);
    self->field_text_34.height.set_binding([this]() {
                            [[maybe_unused]] auto self = this;
                            return slint::private_api::optional_or_default(slint::private_api::optional_transform(self->parent.lock(), [&](auto&&x) { return slint::private_api::layout_cache_access(x->field_root_14_empty_33_layout_cache.get(), 1, 0, 2); }));
                        });
    self->field_text_34.text.set(slint::SharedString(u8"Fetching package details..."));
    self->field_text_34.width.set_binding([this]() {
                            [[maybe_unused]] auto self = this;
                            return ((((slint::private_api::optional_or_default(slint::private_api::optional_transform(self->parent.lock(), [&](auto&&x) { return x->field_flickable_15.viewport_width.get(); })) -(float) 60) -(float) 60) -(float) 24) -(float) 24);
                        });
    self->field_text_34.color.set_constant();
    self->field_text_34.font_size.set_constant();
    self->field_text_34.font_weight.set_constant();
    self->field_text_34.horizontal_alignment.set_constant();
    self->field_text_34.text.set_constant();
    self->field_text_34.vertical_alignment.set_constant();
}

auto Component_text_34::user_init () -> void{
    [[maybe_unused]] auto self = this;
}

auto Component_text_34::layout_info (slint::cbindgen_private::Orientation o) const -> slint::cbindgen_private::LayoutInfo{
    [[maybe_unused]] auto self = this;
    return o == slint::cbindgen_private::Orientation::Horizontal ? slint::private_api::item_layout_info(SLINT_GET_ITEM_VTABLE(SimpleTextVTable), const_cast<slint::cbindgen_private::SimpleText*>(&self->field_text_34), slint::cbindgen_private::Orientation::Horizontal, -1, &self->globals->window().window_handle(), self->self_weak.lock()->into_dyn(), self->tree_index) : slint::private_api::item_layout_info(SLINT_GET_ITEM_VTABLE(SimpleTextVTable), const_cast<slint::cbindgen_private::SimpleText*>(&self->field_text_34), slint::cbindgen_private::Orientation::Vertical, -1, &self->globals->window().window_handle(), self->self_weak.lock()->into_dyn(), self->tree_index);
}

auto Component_text_34::item_geometry (uint32_t index) const -> slint::cbindgen_private::Rect{
    [[maybe_unused]] auto self = this;
    switch (index) {
        case 0: return slint::private_api::convert_anonymous_rect(std::make_tuple(float(slint::private_api::optional_or_default(slint::private_api::optional_transform(self->parent.lock(), [&](auto&&x) { return slint::private_api::layout_cache_access(x->field_root_14_empty_33_layout_cache.get(), 1, 0, 2); }))), float(((((slint::private_api::optional_or_default(slint::private_api::optional_transform(self->parent.lock(), [&](auto&&x) { return x->field_flickable_15.viewport_width.get(); })) -(float) 60) -(float) 60) -(float) 24) -(float) 24)), float(24), float(slint::private_api::optional_or_default(slint::private_api::optional_transform(self->parent.lock(), [&](auto&&x) { return slint::private_api::layout_cache_access(x->field_root_14_empty_33_layout_cache.get(), 0, 0, 2); })))));
    }
    return {};
}

auto Component_text_34::accessible_role (uint32_t index) const -> slint::cbindgen_private::AccessibleRole{
    [[maybe_unused]] auto self = this;
    switch (index) {
        case 0: return slint::cbindgen_private::AccessibleRole::Text;
    }
    return {};
}

auto Component_text_34::accessible_string_property (uint32_t index, slint::cbindgen_private::AccessibleStringProperty what) const -> std::optional<slint::SharedString>{
    [[maybe_unused]] auto self = this;
    switch ((index << 8) | uintptr_t(what)) {
        case (0 << 8) | uintptr_t(slint::cbindgen_private::AccessibleStringProperty::Label): return slint::SharedString(u8"Fetching package details...");
    }
    return {};
}

auto Component_text_34::accessibility_action (uint32_t index, const slint::cbindgen_private::AccessibilityAction &action) const -> void{
    [[maybe_unused]] auto self = this;
    switch ((index << 8) | uintptr_t(action.tag)) {
    }
    return ;
}

auto Component_text_34::supported_accessibility_actions (uint32_t index) const -> uint32_t{
    [[maybe_unused]] auto self = this;
    switch (index) {
    }
    return {};
}

auto Component_text_34::element_infos (uint32_t index) const -> std::optional<slint::SharedString>{
    [[maybe_unused]] auto self = this;
    switch (index) {
    }
    return {};
}

auto Component_text_34::ensure_instantiated () const -> bool{
    [[maybe_unused]] auto self = this;
    bool _changed = false;
    return _changed;
}

auto Component_text_34::visit_children (slint::private_api::ItemTreeRef component, intptr_t index, slint::private_api::TraversalOrder order, slint::private_api::ItemVisitorRefMut visitor) -> uint64_t{
    static const auto dyn_visit = [] (const void *base,  [[maybe_unused]] slint::private_api::TraversalOrder order, [[maybe_unused]] slint::private_api::ItemVisitorRefMut visitor, [[maybe_unused]] uint32_t dyn_index) -> uint64_t {
        [[maybe_unused]] auto self = reinterpret_cast<const Component_text_34*>(base);
        std::abort();
    };
    auto self_rc = reinterpret_cast<const Component_text_34*>(component.instance)->self_weak.lock()->into_dyn();
    return slint::cbindgen_private::slint_visit_item_tree(&self_rc, get_item_tree(component) , index, order, visitor, dyn_visit);
}

auto Component_text_34::get_item_ref (slint::private_api::ItemTreeRef component, uint32_t index) -> slint::private_api::ItemRef{
    return slint::private_api::get_item_ref(component, get_item_tree(component), item_array(), index);
}

auto Component_text_34::get_subtree_range ([[maybe_unused]] slint::private_api::ItemTreeRef component, [[maybe_unused]] uint32_t dyn_index) -> slint::private_api::IndexRange{
        std::abort();
}

auto Component_text_34::get_subtree ([[maybe_unused]] slint::private_api::ItemTreeRef component, [[maybe_unused]] uint32_t dyn_index, [[maybe_unused]] uintptr_t subtree_index, [[maybe_unused]] slint::private_api::ItemTreeWeak *result) -> void{
        std::abort();
}

auto Component_text_34::get_item_tree (slint::private_api::ItemTreeRef) -> slint::cbindgen_private::Slice<slint::private_api::ItemTreeNode>{
    return item_tree();
}

auto Component_text_34::parent_node ([[maybe_unused]] slint::private_api::ItemTreeRef component, [[maybe_unused]] slint::private_api::ItemWeak *result) -> void{
    auto self = reinterpret_cast<const Component_text_34*>(component.instance);
    auto parent = self->parent.lock().value();
    *result = { parent->self_weak, parent->tree_index_of_first_child + 16 };
}

auto Component_text_34::embed_component ([[maybe_unused]] slint::private_api::ItemTreeRef component, [[maybe_unused]] const slint::private_api::ItemTreeWeak *parent_component, [[maybe_unused]] const uint32_t parent_index) -> bool{
    return false; /* todo! */
}

auto Component_text_34::subtree_index ([[maybe_unused]] slint::private_api::ItemTreeRef component) -> uintptr_t{
    return std::numeric_limits<uintptr_t>::max();
}

auto Component_text_34::item_tree () -> slint::cbindgen_private::Slice<slint::private_api::ItemTreeNode>{
    static const slint::private_api::ItemTreeNode children[] {
        slint::private_api::make_item_node(0, 1, 0, 0, true) };
    return slint::private_api::make_slice(std::span(children));
}

auto Component_text_34::item_array () -> const slint::private_api::ItemArray{
    static const slint::private_api::ItemArrayEntry items[] {
        { SLINT_GET_ITEM_VTABLE(SimpleTextVTable),  offsetof(Component_text_34, field_text_34) } };
    return slint::private_api::make_slice(std::span(items));
}

auto Component_text_34::layout_info ([[maybe_unused]] slint::private_api::ItemTreeRef component, slint::cbindgen_private::Orientation o) -> slint::cbindgen_private::LayoutInfo{
    return reinterpret_cast<const Component_text_34*>(component.instance)->layout_info(o);
}

auto Component_text_34::ensure_instantiated ([[maybe_unused]] slint::private_api::ItemTreeRef component) -> bool{
    return reinterpret_cast<const Component_text_34*>(component.instance)->ensure_instantiated();
}

auto Component_text_34::item_geometry ([[maybe_unused]] slint::private_api::ItemTreeRef component, uint32_t index) -> slint::cbindgen_private::LogicalRect{
    return reinterpret_cast<const Component_text_34*>(component.instance)->item_geometry(index);
}

auto Component_text_34::accessible_role ([[maybe_unused]] slint::private_api::ItemTreeRef component, uint32_t index) -> slint::cbindgen_private::AccessibleRole{
    return reinterpret_cast<const Component_text_34*>(component.instance)->accessible_role(index);
}

auto Component_text_34::accessible_string_property ([[maybe_unused]] slint::private_api::ItemTreeRef component, uint32_t index, slint::cbindgen_private::AccessibleStringProperty what, slint::SharedString *result) -> bool{
    if (auto r = reinterpret_cast<const Component_text_34*>(component.instance)->accessible_string_property(index, what)) { *result = *r; return true; } else { return false; }
}

auto Component_text_34::accessibility_action ([[maybe_unused]] slint::private_api::ItemTreeRef component, uint32_t index, const slint::cbindgen_private::AccessibilityAction *action) -> void{
    reinterpret_cast<const Component_text_34*>(component.instance)->accessibility_action(index, *action);
}

auto Component_text_34::supported_accessibility_actions ([[maybe_unused]] slint::private_api::ItemTreeRef component, uint32_t index) -> uint32_t{
    return reinterpret_cast<const Component_text_34*>(component.instance)->supported_accessibility_actions(index);
}

auto Component_text_34::element_infos ([[maybe_unused]] slint::private_api::ItemTreeRef component, [[maybe_unused]] uint32_t index, [[maybe_unused]] slint::SharedString *result) -> bool{
    return false;
}

auto Component_text_34::window_adapter ([[maybe_unused]] slint::private_api::ItemTreeRef component, [[maybe_unused]] bool do_create, [[maybe_unused]] slint::cbindgen_private::Option<slint::private_api::WindowAdapterRc>* result) -> void{
    *reinterpret_cast<slint::private_api::WindowAdapterRc*>(result) = reinterpret_cast<const Component_text_34*>(component.instance)->globals->window().window_handle();
}

auto Component_text_34::create (class DetailsView_root_14 const * parent) -> slint::ComponentHandle<Component_text_34>{
    auto self_rc = vtable::VRc<slint::private_api::ItemTreeVTable, Component_text_34>::make();
    auto self = const_cast<Component_text_34 *>(&*self_rc);
    self->self_weak = vtable::VWeak(self_rc).into_dyn();
    slint::private_api::register_item_tree(&self_rc.into_dyn(), parent->globals->m_window);
    self->init(parent->globals, self->self_weak, 0, 1 , parent);
    return slint::ComponentHandle<Component_text_34>{ self_rc };
}

Component_text_34::~Component_text_34 (){
    if (auto &window = globals->m_window) window->window_handle().unregister_item_tree(this, item_array());
}

auto Component_text_34::init () -> void{
    user_init();
}

auto Component_text_34::layout_item_info (slint::cbindgen_private::Orientation o, [[maybe_unused]] std::optional<size_t> child_index) const -> slint::cbindgen_private::LayoutItemInfo{
    return { layout_info({&static_vtable, const_cast<void *>(static_cast<const void *>(this))}, o) };
}

auto Component_text_34::flexbox_layout_item_info (slint::cbindgen_private::Orientation o, [[maybe_unused]] std::optional<size_t> child_index) const -> slint::cbindgen_private::FlexboxLayoutItemInfo{
    auto base = layout_item_info(o, child_index); return { base.constraint, 0.0f, 0.0f, -1.0f, slint::cbindgen_private::FlexboxLayoutAlignSelf::Auto, 0 };
}

const slint::private_api::ItemTreeVTable Component_text_38::static_vtable = { visit_children, get_item_ref, get_subtree_range, get_subtree, get_item_tree, parent_node, embed_component, subtree_index, layout_info, ensure_instantiated, item_geometry, accessible_role, accessible_string_property, accessibility_action, supported_accessibility_actions, element_infos, window_adapter, slint::private_api::drop_in_place<Component_text_38>, slint::private_api::dealloc };

auto Component_text_38::init (const class SharedGlobals* globals,slint::cbindgen_private::ItemTreeWeak enclosing_component,uint32_t tree_index,uint32_t tree_index_of_first_child,class Component_empty_36 const *parent) -> void{
    auto self = this;
    self->self_weak = enclosing_component;
    self->globals = globals;
    this->tree_index_of_first_child = tree_index_of_first_child;
    self->tree_index = tree_index;
    self->parent = vtable::VRcMapped<slint::private_api::ItemTreeVTable, const Component_empty_36>(parent->self_weak.lock().value(), parent);
    self->field_text_38.color.set(slint::Brush(slint::Color::from_argb_encoded(+4.290429662e9)));
    self->field_text_38.font_size.set(13);
    self->field_text_38.height.set_binding([this]() {
                            [[maybe_unused]] auto self = this;
                            return slint::private_api::optional_or_default(slint::private_api::optional_transform(self->parent.lock(), [&](auto&&x) { return slint::private_api::layout_cache_access(x->field_empty_36_layout_cache.get(), 3, 0, 2); }));
                        });
    self->field_text_38.text.set(slint::SharedString(u8"No additional packages required."));
    self->field_text_38.width.set_binding([this]() {
                            [[maybe_unused]] auto self = this;
                            return ((((slint::private_api::optional_or_default(slint::private_api::optional_transform(slint::private_api::optional_and_then(self->parent.lock(), [&](auto&&x) { return x->parent.lock(); }), [&](auto&&x) { return x->field_flickable_15.viewport_width.get(); })) -(float) 60) -(float) 60) -(float) 24) -(float) 24);
                        });
    self->field_text_38.color.set_constant();
    self->field_text_38.font_size.set_constant();
    self->field_text_38.font_weight.set_constant();
    self->field_text_38.horizontal_alignment.set_constant();
    self->field_text_38.text.set_constant();
    self->field_text_38.vertical_alignment.set_constant();
}

auto Component_text_38::user_init () -> void{
    [[maybe_unused]] auto self = this;
}

auto Component_text_38::layout_info (slint::cbindgen_private::Orientation o) const -> slint::cbindgen_private::LayoutInfo{
    [[maybe_unused]] auto self = this;
    return o == slint::cbindgen_private::Orientation::Horizontal ? slint::private_api::item_layout_info(SLINT_GET_ITEM_VTABLE(SimpleTextVTable), const_cast<slint::cbindgen_private::SimpleText*>(&self->field_text_38), slint::cbindgen_private::Orientation::Horizontal, -1, &self->globals->window().window_handle(), self->self_weak.lock()->into_dyn(), self->tree_index) : slint::private_api::item_layout_info(SLINT_GET_ITEM_VTABLE(SimpleTextVTable), const_cast<slint::cbindgen_private::SimpleText*>(&self->field_text_38), slint::cbindgen_private::Orientation::Vertical, -1, &self->globals->window().window_handle(), self->self_weak.lock()->into_dyn(), self->tree_index);
}

auto Component_text_38::item_geometry (uint32_t index) const -> slint::cbindgen_private::Rect{
    [[maybe_unused]] auto self = this;
    switch (index) {
        case 0: return slint::private_api::convert_anonymous_rect(std::make_tuple(float(slint::private_api::optional_or_default(slint::private_api::optional_transform(self->parent.lock(), [&](auto&&x) { return slint::private_api::layout_cache_access(x->field_empty_36_layout_cache.get(), 3, 0, 2); }))), float(((((slint::private_api::optional_or_default(slint::private_api::optional_transform(slint::private_api::optional_and_then(self->parent.lock(), [&](auto&&x) { return x->parent.lock(); }), [&](auto&&x) { return x->field_flickable_15.viewport_width.get(); })) -(float) 60) -(float) 60) -(float) 24) -(float) 24)), float(0), float(slint::private_api::optional_or_default(slint::private_api::optional_transform(self->parent.lock(), [&](auto&&x) { return slint::private_api::layout_cache_access(x->field_empty_36_layout_cache.get(), 2, 0, 2); })))));
    }
    return {};
}

auto Component_text_38::accessible_role (uint32_t index) const -> slint::cbindgen_private::AccessibleRole{
    [[maybe_unused]] auto self = this;
    switch (index) {
        case 0: return slint::cbindgen_private::AccessibleRole::Text;
    }
    return {};
}

auto Component_text_38::accessible_string_property (uint32_t index, slint::cbindgen_private::AccessibleStringProperty what) const -> std::optional<slint::SharedString>{
    [[maybe_unused]] auto self = this;
    switch ((index << 8) | uintptr_t(what)) {
        case (0 << 8) | uintptr_t(slint::cbindgen_private::AccessibleStringProperty::Label): return slint::SharedString(u8"No additional packages required.");
    }
    return {};
}

auto Component_text_38::accessibility_action (uint32_t index, const slint::cbindgen_private::AccessibilityAction &action) const -> void{
    [[maybe_unused]] auto self = this;
    switch ((index << 8) | uintptr_t(action.tag)) {
    }
    return ;
}

auto Component_text_38::supported_accessibility_actions (uint32_t index) const -> uint32_t{
    [[maybe_unused]] auto self = this;
    switch (index) {
    }
    return {};
}

auto Component_text_38::element_infos (uint32_t index) const -> std::optional<slint::SharedString>{
    [[maybe_unused]] auto self = this;
    switch (index) {
    }
    return {};
}

auto Component_text_38::ensure_instantiated () const -> bool{
    [[maybe_unused]] auto self = this;
    bool _changed = false;
    return _changed;
}

auto Component_text_38::visit_children (slint::private_api::ItemTreeRef component, intptr_t index, slint::private_api::TraversalOrder order, slint::private_api::ItemVisitorRefMut visitor) -> uint64_t{
    static const auto dyn_visit = [] (const void *base,  [[maybe_unused]] slint::private_api::TraversalOrder order, [[maybe_unused]] slint::private_api::ItemVisitorRefMut visitor, [[maybe_unused]] uint32_t dyn_index) -> uint64_t {
        [[maybe_unused]] auto self = reinterpret_cast<const Component_text_38*>(base);
        std::abort();
    };
    auto self_rc = reinterpret_cast<const Component_text_38*>(component.instance)->self_weak.lock()->into_dyn();
    return slint::cbindgen_private::slint_visit_item_tree(&self_rc, get_item_tree(component) , index, order, visitor, dyn_visit);
}

auto Component_text_38::get_item_ref (slint::private_api::ItemTreeRef component, uint32_t index) -> slint::private_api::ItemRef{
    return slint::private_api::get_item_ref(component, get_item_tree(component), item_array(), index);
}

auto Component_text_38::get_subtree_range ([[maybe_unused]] slint::private_api::ItemTreeRef component, [[maybe_unused]] uint32_t dyn_index) -> slint::private_api::IndexRange{
        std::abort();
}

auto Component_text_38::get_subtree ([[maybe_unused]] slint::private_api::ItemTreeRef component, [[maybe_unused]] uint32_t dyn_index, [[maybe_unused]] uintptr_t subtree_index, [[maybe_unused]] slint::private_api::ItemTreeWeak *result) -> void{
        std::abort();
}

auto Component_text_38::get_item_tree (slint::private_api::ItemTreeRef) -> slint::cbindgen_private::Slice<slint::private_api::ItemTreeNode>{
    return item_tree();
}

auto Component_text_38::parent_node ([[maybe_unused]] slint::private_api::ItemTreeRef component, [[maybe_unused]] slint::private_api::ItemWeak *result) -> void{
    auto self = reinterpret_cast<const Component_text_38*>(component.instance);
    auto parent = self->parent.lock().value();
    *result = { parent->self_weak, parent->tree_index_of_first_child + 1 };
}

auto Component_text_38::embed_component ([[maybe_unused]] slint::private_api::ItemTreeRef component, [[maybe_unused]] const slint::private_api::ItemTreeWeak *parent_component, [[maybe_unused]] const uint32_t parent_index) -> bool{
    return false; /* todo! */
}

auto Component_text_38::subtree_index ([[maybe_unused]] slint::private_api::ItemTreeRef component) -> uintptr_t{
    return std::numeric_limits<uintptr_t>::max();
}

auto Component_text_38::item_tree () -> slint::cbindgen_private::Slice<slint::private_api::ItemTreeNode>{
    static const slint::private_api::ItemTreeNode children[] {
        slint::private_api::make_item_node(0, 1, 0, 0, true) };
    return slint::private_api::make_slice(std::span(children));
}

auto Component_text_38::item_array () -> const slint::private_api::ItemArray{
    static const slint::private_api::ItemArrayEntry items[] {
        { SLINT_GET_ITEM_VTABLE(SimpleTextVTable),  offsetof(Component_text_38, field_text_38) } };
    return slint::private_api::make_slice(std::span(items));
}

auto Component_text_38::layout_info ([[maybe_unused]] slint::private_api::ItemTreeRef component, slint::cbindgen_private::Orientation o) -> slint::cbindgen_private::LayoutInfo{
    return reinterpret_cast<const Component_text_38*>(component.instance)->layout_info(o);
}

auto Component_text_38::ensure_instantiated ([[maybe_unused]] slint::private_api::ItemTreeRef component) -> bool{
    return reinterpret_cast<const Component_text_38*>(component.instance)->ensure_instantiated();
}

auto Component_text_38::item_geometry ([[maybe_unused]] slint::private_api::ItemTreeRef component, uint32_t index) -> slint::cbindgen_private::LogicalRect{
    return reinterpret_cast<const Component_text_38*>(component.instance)->item_geometry(index);
}

auto Component_text_38::accessible_role ([[maybe_unused]] slint::private_api::ItemTreeRef component, uint32_t index) -> slint::cbindgen_private::AccessibleRole{
    return reinterpret_cast<const Component_text_38*>(component.instance)->accessible_role(index);
}

auto Component_text_38::accessible_string_property ([[maybe_unused]] slint::private_api::ItemTreeRef component, uint32_t index, slint::cbindgen_private::AccessibleStringProperty what, slint::SharedString *result) -> bool{
    if (auto r = reinterpret_cast<const Component_text_38*>(component.instance)->accessible_string_property(index, what)) { *result = *r; return true; } else { return false; }
}

auto Component_text_38::accessibility_action ([[maybe_unused]] slint::private_api::ItemTreeRef component, uint32_t index, const slint::cbindgen_private::AccessibilityAction *action) -> void{
    reinterpret_cast<const Component_text_38*>(component.instance)->accessibility_action(index, *action);
}

auto Component_text_38::supported_accessibility_actions ([[maybe_unused]] slint::private_api::ItemTreeRef component, uint32_t index) -> uint32_t{
    return reinterpret_cast<const Component_text_38*>(component.instance)->supported_accessibility_actions(index);
}

auto Component_text_38::element_infos ([[maybe_unused]] slint::private_api::ItemTreeRef component, [[maybe_unused]] uint32_t index, [[maybe_unused]] slint::SharedString *result) -> bool{
    return false;
}

auto Component_text_38::window_adapter ([[maybe_unused]] slint::private_api::ItemTreeRef component, [[maybe_unused]] bool do_create, [[maybe_unused]] slint::cbindgen_private::Option<slint::private_api::WindowAdapterRc>* result) -> void{
    *reinterpret_cast<slint::private_api::WindowAdapterRc*>(result) = reinterpret_cast<const Component_text_38*>(component.instance)->globals->window().window_handle();
}

auto Component_text_38::create (class Component_empty_36 const * parent) -> slint::ComponentHandle<Component_text_38>{
    auto self_rc = vtable::VRc<slint::private_api::ItemTreeVTable, Component_text_38>::make();
    auto self = const_cast<Component_text_38 *>(&*self_rc);
    self->self_weak = vtable::VWeak(self_rc).into_dyn();
    slint::private_api::register_item_tree(&self_rc.into_dyn(), parent->globals->m_window);
    self->init(parent->globals, self->self_weak, 0, 1 , parent);
    return slint::ComponentHandle<Component_text_38>{ self_rc };
}

Component_text_38::~Component_text_38 (){
    if (auto &window = globals->m_window) window->window_handle().unregister_item_tree(this, item_array());
}

auto Component_text_38::init () -> void{
    user_init();
}

auto Component_text_38::layout_item_info (slint::cbindgen_private::Orientation o, [[maybe_unused]] std::optional<size_t> child_index) const -> slint::cbindgen_private::LayoutItemInfo{
    return { layout_info({&static_vtable, const_cast<void *>(static_cast<const void *>(this))}, o) };
}

auto Component_text_38::flexbox_layout_item_info (slint::cbindgen_private::Orientation o, [[maybe_unused]] std::optional<size_t> child_index) const -> slint::cbindgen_private::FlexboxLayoutItemInfo{
    auto base = layout_item_info(o, child_index); return { base.constraint, 0.0f, 0.0f, -1.0f, slint::cbindgen_private::FlexboxLayoutAlignSelf::Auto, 0 };
}

const slint::private_api::ItemTreeVTable Component_empty_41::static_vtable = { visit_children, get_item_ref, get_subtree_range, get_subtree, get_item_tree, parent_node, embed_component, subtree_index, layout_info, ensure_instantiated, item_geometry, accessible_role, accessible_string_property, accessibility_action, supported_accessibility_actions, element_infos, window_adapter, slint::private_api::drop_in_place<Component_empty_41>, slint::private_api::dealloc };

auto Component_empty_41::init (const class SharedGlobals* globals,slint::cbindgen_private::ItemTreeWeak enclosing_component,uint32_t tree_index,uint32_t tree_index_of_first_child,class Component_empty_40 const *parent) -> void{
    auto self = this;
    self->self_weak = enclosing_component;
    self->globals = globals;
    this->tree_index_of_first_child = tree_index_of_first_child;
    self->tree_index = tree_index;
    self->parent = vtable::VRcMapped<slint::private_api::ItemTreeVTable, const Component_empty_40>(parent->self_weak.lock().value(), parent);
    self->field_empty_41_height.set_binding([this]() {
                            [[maybe_unused]] auto self = this;
                            return slint::private_api::optional_or_default(slint::private_api::optional_transform(self->parent.lock(), [&](auto&&x) { return slint::private_api::layout_cache_access(x->field_empty_40_layout_cache.get(), 1, self->field_model_index.get(), 2); }));
                        });
    self->field_empty_41_layout_cache.set_binding([this]() {
                            [[maybe_unused]] auto self = this;
                            return slint::private_api::solve_box_layout([&](const auto &a_0, const auto &a_1, const auto &a_2, const auto &a_3, const auto &a_4){ slint::cbindgen_private::BoxLayoutData o{}; o.alignment = a_0; o.cells = a_1; o.padding = a_2; o.size = a_3; o.spacing = a_4; return o; }(slint::cbindgen_private::LayoutAlignment::Stretch, slint::private_api::make_slice<slint::cbindgen_private::LayoutItemInfo>(std::array<slint::cbindgen_private::LayoutItemInfo, 2>{ slint::cbindgen_private::LayoutItemInfo ( [&](const auto &a_0){ slint::cbindgen_private::LayoutItemInfo o{}; o.constraint = a_0; return o; }([&]{ [[maybe_unused]] auto layout_info = slint::private_api::item_layout_info(SLINT_GET_ITEM_VTABLE(SimpleTextVTable), const_cast<slint::cbindgen_private::SimpleText*>(&self->field_text_42), slint::cbindgen_private::Orientation::Horizontal, -1, &self->globals->window().window_handle(), self->self_weak.lock()->into_dyn(), self->tree_index_of_first_child + 1 - 1);;return [&](const auto &a_0, const auto &a_1, const auto &a_2, const auto &a_3, const auto &a_4, const auto &a_5){ slint::cbindgen_private::LayoutInfo o{}; o.max = a_0; o.max_percent = a_1; o.min = a_2; o.min_percent = a_3; o.preferred = a_4; o.stretch = a_5; return o; }(layout_info.max, layout_info.max_percent, layout_info.min, layout_info.min_percent, layout_info.preferred, 1); }()) ), slint::cbindgen_private::LayoutItemInfo ( [&](const auto &a_0){ slint::cbindgen_private::LayoutItemInfo o{}; o.constraint = a_0; return o; }(slint::private_api::item_layout_info(SLINT_GET_ITEM_VTABLE(SimpleTextVTable), const_cast<slint::cbindgen_private::SimpleText*>(&self->field_text_43), slint::cbindgen_private::Orientation::Horizontal, -1, &self->globals->window().window_handle(), self->self_weak.lock()->into_dyn(), self->tree_index_of_first_child + 2 - 1)) ) }.data(), 2), [&](const auto &a_0, const auto &a_1){ slint::cbindgen_private::Padding o{}; o.begin = a_0; o.end = a_1; return o; }(0, 0), slint::private_api::optional_or_default(slint::private_api::optional_transform(self->parent.lock(), [&](auto&&x) { return x->field_empty_40_width.get(); })), 0),slint::private_api::make_slice<int>(std::array<int, 0>{  }.data(), 0));
                        });
    self->field_empty_41_layoutinfo_h.set_binding([this]() {
                            [[maybe_unused]] auto self = this;
                            return slint::private_api::box_layout_info(slint::private_api::make_slice<slint::cbindgen_private::LayoutItemInfo>(std::array<slint::cbindgen_private::LayoutItemInfo, 2>{ slint::cbindgen_private::LayoutItemInfo ( [&](const auto &a_0){ slint::cbindgen_private::LayoutItemInfo o{}; o.constraint = a_0; return o; }([&]{ [[maybe_unused]] auto layout_info = slint::private_api::item_layout_info(SLINT_GET_ITEM_VTABLE(SimpleTextVTable), const_cast<slint::cbindgen_private::SimpleText*>(&self->field_text_42), slint::cbindgen_private::Orientation::Horizontal, -1, &self->globals->window().window_handle(), self->self_weak.lock()->into_dyn(), self->tree_index_of_first_child + 1 - 1);;return [&](const auto &a_0, const auto &a_1, const auto &a_2, const auto &a_3, const auto &a_4, const auto &a_5){ slint::cbindgen_private::LayoutInfo o{}; o.max = a_0; o.max_percent = a_1; o.min = a_2; o.min_percent = a_3; o.preferred = a_4; o.stretch = a_5; return o; }(layout_info.max, layout_info.max_percent, layout_info.min, layout_info.min_percent, layout_info.preferred, 1); }()) ), slint::cbindgen_private::LayoutItemInfo ( [&](const auto &a_0){ slint::cbindgen_private::LayoutItemInfo o{}; o.constraint = a_0; return o; }(slint::private_api::item_layout_info(SLINT_GET_ITEM_VTABLE(SimpleTextVTable), const_cast<slint::cbindgen_private::SimpleText*>(&self->field_text_43), slint::cbindgen_private::Orientation::Horizontal, -1, &self->globals->window().window_handle(), self->self_weak.lock()->into_dyn(), self->tree_index_of_first_child + 2 - 1)) ) }.data(), 2),0,[&](const auto &a_0, const auto &a_1){ slint::cbindgen_private::Padding o{}; o.begin = a_0; o.end = a_1; return o; }(0, 0),slint::cbindgen_private::LayoutAlignment::Stretch);
                        });
    self->field_empty_41_layoutinfo_v.set_binding([this]() {
                            [[maybe_unused]] auto self = this;
                            return slint::private_api::box_layout_info_ortho(slint::private_api::make_slice<slint::cbindgen_private::LayoutItemInfo>(std::array<slint::cbindgen_private::LayoutItemInfo, 2>{ slint::cbindgen_private::LayoutItemInfo ( [&](const auto &a_0){ slint::cbindgen_private::LayoutItemInfo o{}; o.constraint = a_0; return o; }(slint::private_api::item_layout_info(SLINT_GET_ITEM_VTABLE(SimpleTextVTable), const_cast<slint::cbindgen_private::SimpleText*>(&self->field_text_42), slint::cbindgen_private::Orientation::Vertical, -1, &self->globals->window().window_handle(), self->self_weak.lock()->into_dyn(), self->tree_index_of_first_child + 1 - 1)) ), slint::cbindgen_private::LayoutItemInfo ( [&](const auto &a_0){ slint::cbindgen_private::LayoutItemInfo o{}; o.constraint = a_0; return o; }(slint::private_api::item_layout_info(SLINT_GET_ITEM_VTABLE(SimpleTextVTable), const_cast<slint::cbindgen_private::SimpleText*>(&self->field_text_43), slint::cbindgen_private::Orientation::Vertical, -1, &self->globals->window().window_handle(), self->self_weak.lock()->into_dyn(), self->tree_index_of_first_child + 2 - 1)) ) }.data(), 2),[&](const auto &a_0, const auto &a_1){ slint::cbindgen_private::Padding o{}; o.begin = a_0; o.end = a_1; return o; }(0, 0));
                        });
    self->field_empty_41_y.set_binding([this]() {
                            [[maybe_unused]] auto self = this;
                            return slint::private_api::optional_or_default(slint::private_api::optional_transform(self->parent.lock(), [&](auto&&x) { return slint::private_api::layout_cache_access(x->field_empty_40_layout_cache.get(), 0, self->field_model_index.get(), 2); }));
                        });
    self->field_text_42.color.set(slint::Brush(slint::Color::from_argb_encoded(+4.290429662e9)));
    self->field_text_42.font_size.set(13);
    self->field_text_42.height.set_binding([this]() {
                            [[maybe_unused]] auto self = this;
                            return self->field_empty_41_height.get();
                        });
    self->field_text_42.text.set_binding([this]() {
                            [[maybe_unused]] auto self = this;
                            return self->field_model_data.get().name;
                        });
    self->field_text_42.width.set_binding([this]() {
                            [[maybe_unused]] auto self = this;
                            return self->field_empty_41_layout_cache.get()[1];
                        });
    self->field_text_43.color.set(slint::Brush(slint::Color::from_argb_encoded(+4.289113544e9)));
    self->field_text_43.font_size.set(13);
    self->field_text_43.height.set_binding([this]() {
                            [[maybe_unused]] auto self = this;
                            return self->field_empty_41_height.get();
                        });
    self->field_text_43.text.set_binding([this]() {
                            [[maybe_unused]] auto self = this;
                            return self->field_model_data.get().size_str;
                        });
    self->field_text_43.width.set_binding([this]() {
                            [[maybe_unused]] auto self = this;
                            return self->field_empty_41_layout_cache.get()[3];
                        });
    self->field_text_42.color.set_constant();
    self->field_text_42.font_size.set_constant();
    self->field_text_42.font_weight.set_constant();
    self->field_text_42.horizontal_alignment.set_constant();
    self->field_text_42.vertical_alignment.set_constant();
    self->field_text_43.color.set_constant();
    self->field_text_43.font_size.set_constant();
    self->field_text_43.font_weight.set_constant();
    self->field_text_43.horizontal_alignment.set_constant();
    self->field_text_43.vertical_alignment.set_constant();
}

auto Component_empty_41::user_init () -> void{
    [[maybe_unused]] auto self = this;
}

auto Component_empty_41::layout_info (slint::cbindgen_private::Orientation o) const -> slint::cbindgen_private::LayoutInfo{
    [[maybe_unused]] auto self = this;
    return o == slint::cbindgen_private::Orientation::Horizontal ? self->field_empty_41_layoutinfo_h.get() : self->field_empty_41_layoutinfo_v.get();
}

auto Component_empty_41::item_geometry (uint32_t index) const -> slint::cbindgen_private::Rect{
    [[maybe_unused]] auto self = this;
    switch (index) {
        case 0: return slint::private_api::convert_anonymous_rect(std::make_tuple(float(self->field_empty_41_height.get()), float(((((slint::private_api::optional_or_default(slint::private_api::optional_transform(slint::private_api::optional_and_then(slint::private_api::optional_and_then(self->parent.lock(), [&](auto&&x) { return x->parent.lock(); }), [&](auto&&x) { return x->parent.lock(); }), [&](auto&&x) { return x->field_flickable_15.viewport_width.get(); })) -(float) 60) -(float) 60) -(float) 24) -(float) 24)), float(0), float(self->field_empty_41_y.get())));
        case 1: return slint::private_api::convert_anonymous_rect(std::make_tuple(float(self->field_empty_41_height.get()), float(self->field_empty_41_layout_cache.get()[1]), float(self->field_empty_41_layout_cache.get()[0]), float(0)));
        case 2: return slint::private_api::convert_anonymous_rect(std::make_tuple(float(self->field_empty_41_height.get()), float(self->field_empty_41_layout_cache.get()[3]), float(self->field_empty_41_layout_cache.get()[2]), float(0)));
    }
    return {};
}

auto Component_empty_41::accessible_role (uint32_t index) const -> slint::cbindgen_private::AccessibleRole{
    [[maybe_unused]] auto self = this;
    switch (index) {
        case 1: return slint::cbindgen_private::AccessibleRole::Text;
        case 2: return slint::cbindgen_private::AccessibleRole::Text;
    }
    return {};
}

auto Component_empty_41::accessible_string_property (uint32_t index, slint::cbindgen_private::AccessibleStringProperty what) const -> std::optional<slint::SharedString>{
    [[maybe_unused]] auto self = this;
    switch ((index << 8) | uintptr_t(what)) {
        case (1 << 8) | uintptr_t(slint::cbindgen_private::AccessibleStringProperty::Label): return self->field_model_data.get().name;
        case (2 << 8) | uintptr_t(slint::cbindgen_private::AccessibleStringProperty::Label): return self->field_model_data.get().size_str;
    }
    return {};
}

auto Component_empty_41::accessibility_action (uint32_t index, const slint::cbindgen_private::AccessibilityAction &action) const -> void{
    [[maybe_unused]] auto self = this;
    switch ((index << 8) | uintptr_t(action.tag)) {
    }
    return ;
}

auto Component_empty_41::supported_accessibility_actions (uint32_t index) const -> uint32_t{
    [[maybe_unused]] auto self = this;
    switch (index) {
    }
    return {};
}

auto Component_empty_41::element_infos (uint32_t index) const -> std::optional<slint::SharedString>{
    [[maybe_unused]] auto self = this;
    switch (index) {
    }
    return {};
}

auto Component_empty_41::ensure_instantiated () const -> bool{
    [[maybe_unused]] auto self = this;
    bool _changed = false;
    return _changed;
}

auto Component_empty_41::visit_children (slint::private_api::ItemTreeRef component, intptr_t index, slint::private_api::TraversalOrder order, slint::private_api::ItemVisitorRefMut visitor) -> uint64_t{
    static const auto dyn_visit = [] (const void *base,  [[maybe_unused]] slint::private_api::TraversalOrder order, [[maybe_unused]] slint::private_api::ItemVisitorRefMut visitor, [[maybe_unused]] uint32_t dyn_index) -> uint64_t {
        [[maybe_unused]] auto self = reinterpret_cast<const Component_empty_41*>(base);
        std::abort();
    };
    auto self_rc = reinterpret_cast<const Component_empty_41*>(component.instance)->self_weak.lock()->into_dyn();
    return slint::cbindgen_private::slint_visit_item_tree(&self_rc, get_item_tree(component) , index, order, visitor, dyn_visit);
}

auto Component_empty_41::get_item_ref (slint::private_api::ItemTreeRef component, uint32_t index) -> slint::private_api::ItemRef{
    return slint::private_api::get_item_ref(component, get_item_tree(component), item_array(), index);
}

auto Component_empty_41::get_subtree_range ([[maybe_unused]] slint::private_api::ItemTreeRef component, [[maybe_unused]] uint32_t dyn_index) -> slint::private_api::IndexRange{
        std::abort();
}

auto Component_empty_41::get_subtree ([[maybe_unused]] slint::private_api::ItemTreeRef component, [[maybe_unused]] uint32_t dyn_index, [[maybe_unused]] uintptr_t subtree_index, [[maybe_unused]] slint::private_api::ItemTreeWeak *result) -> void{
        std::abort();
}

auto Component_empty_41::get_item_tree (slint::private_api::ItemTreeRef) -> slint::cbindgen_private::Slice<slint::private_api::ItemTreeNode>{
    return item_tree();
}

auto Component_empty_41::parent_node ([[maybe_unused]] slint::private_api::ItemTreeRef component, [[maybe_unused]] slint::private_api::ItemWeak *result) -> void{
    auto self = reinterpret_cast<const Component_empty_41*>(component.instance);
    auto parent = self->parent.lock().value();
    *result = { parent->self_weak, parent->tree_index_of_first_child + 0 };
}

auto Component_empty_41::embed_component ([[maybe_unused]] slint::private_api::ItemTreeRef component, [[maybe_unused]] const slint::private_api::ItemTreeWeak *parent_component, [[maybe_unused]] const uint32_t parent_index) -> bool{
    return false; /* todo! */
}

auto Component_empty_41::subtree_index ([[maybe_unused]] slint::private_api::ItemTreeRef component) -> uintptr_t{
    auto self = reinterpret_cast<const Component_empty_41*>(component.instance);
    return self->field_model_index.get();
}

auto Component_empty_41::item_tree () -> slint::cbindgen_private::Slice<slint::private_api::ItemTreeNode>{
    static const slint::private_api::ItemTreeNode children[] {
        slint::private_api::make_item_node(2, 1, 0, 0, false), 
slint::private_api::make_item_node(0, 3, 0, 1, true), 
slint::private_api::make_item_node(0, 3, 0, 2, true) };
    return slint::private_api::make_slice(std::span(children));
}

auto Component_empty_41::item_array () -> const slint::private_api::ItemArray{
    static const slint::private_api::ItemArrayEntry items[] {
        { SLINT_GET_ITEM_VTABLE(EmptyVTable),  offsetof(Component_empty_41, field_empty_41) }, 
{ SLINT_GET_ITEM_VTABLE(SimpleTextVTable),  offsetof(Component_empty_41, field_text_42) }, 
{ SLINT_GET_ITEM_VTABLE(SimpleTextVTable),  offsetof(Component_empty_41, field_text_43) } };
    return slint::private_api::make_slice(std::span(items));
}

auto Component_empty_41::layout_info ([[maybe_unused]] slint::private_api::ItemTreeRef component, slint::cbindgen_private::Orientation o) -> slint::cbindgen_private::LayoutInfo{
    return reinterpret_cast<const Component_empty_41*>(component.instance)->layout_info(o);
}

auto Component_empty_41::ensure_instantiated ([[maybe_unused]] slint::private_api::ItemTreeRef component) -> bool{
    return reinterpret_cast<const Component_empty_41*>(component.instance)->ensure_instantiated();
}

auto Component_empty_41::item_geometry ([[maybe_unused]] slint::private_api::ItemTreeRef component, uint32_t index) -> slint::cbindgen_private::LogicalRect{
    return reinterpret_cast<const Component_empty_41*>(component.instance)->item_geometry(index);
}

auto Component_empty_41::accessible_role ([[maybe_unused]] slint::private_api::ItemTreeRef component, uint32_t index) -> slint::cbindgen_private::AccessibleRole{
    return reinterpret_cast<const Component_empty_41*>(component.instance)->accessible_role(index);
}

auto Component_empty_41::accessible_string_property ([[maybe_unused]] slint::private_api::ItemTreeRef component, uint32_t index, slint::cbindgen_private::AccessibleStringProperty what, slint::SharedString *result) -> bool{
    if (auto r = reinterpret_cast<const Component_empty_41*>(component.instance)->accessible_string_property(index, what)) { *result = *r; return true; } else { return false; }
}

auto Component_empty_41::accessibility_action ([[maybe_unused]] slint::private_api::ItemTreeRef component, uint32_t index, const slint::cbindgen_private::AccessibilityAction *action) -> void{
    reinterpret_cast<const Component_empty_41*>(component.instance)->accessibility_action(index, *action);
}

auto Component_empty_41::supported_accessibility_actions ([[maybe_unused]] slint::private_api::ItemTreeRef component, uint32_t index) -> uint32_t{
    return reinterpret_cast<const Component_empty_41*>(component.instance)->supported_accessibility_actions(index);
}

auto Component_empty_41::element_infos ([[maybe_unused]] slint::private_api::ItemTreeRef component, [[maybe_unused]] uint32_t index, [[maybe_unused]] slint::SharedString *result) -> bool{
    return false;
}

auto Component_empty_41::window_adapter ([[maybe_unused]] slint::private_api::ItemTreeRef component, [[maybe_unused]] bool do_create, [[maybe_unused]] slint::cbindgen_private::Option<slint::private_api::WindowAdapterRc>* result) -> void{
    *reinterpret_cast<slint::private_api::WindowAdapterRc*>(result) = reinterpret_cast<const Component_empty_41*>(component.instance)->globals->window().window_handle();
}

auto Component_empty_41::create (class Component_empty_40 const * parent) -> slint::ComponentHandle<Component_empty_41>{
    auto self_rc = vtable::VRc<slint::private_api::ItemTreeVTable, Component_empty_41>::make();
    auto self = const_cast<Component_empty_41 *>(&*self_rc);
    self->self_weak = vtable::VWeak(self_rc).into_dyn();
    slint::private_api::register_item_tree(&self_rc.into_dyn(), parent->globals->m_window);
    self->init(parent->globals, self->self_weak, 0, 1 , parent);
    return slint::ComponentHandle<Component_empty_41>{ self_rc };
}

Component_empty_41::~Component_empty_41 (){
    if (auto &window = globals->m_window) window->window_handle().unregister_item_tree(this, item_array());
}

auto Component_empty_41::update_data ([[maybe_unused]] int i, [[maybe_unused]] const UiPackageDependency &data) const -> void{
    [[maybe_unused]] auto self = this;
    self->field_model_index.set(i);
    self->field_model_data.set(data);
}

auto Component_empty_41::init () -> void{
    user_init();
}

auto Component_empty_41::layout_item_info (slint::cbindgen_private::Orientation o, [[maybe_unused]] std::optional<size_t> child_index) const -> slint::cbindgen_private::LayoutItemInfo{
    return { layout_info({&static_vtable, const_cast<void *>(static_cast<const void *>(this))}, o) };
}

auto Component_empty_41::flexbox_layout_item_info (slint::cbindgen_private::Orientation o, [[maybe_unused]] std::optional<size_t> child_index) const -> slint::cbindgen_private::FlexboxLayoutItemInfo{
    auto base = layout_item_info(o, child_index); return { base.constraint, 0.0f, 0.0f, -1.0f, slint::cbindgen_private::FlexboxLayoutAlignSelf::Auto, 0 };
}

const slint::private_api::ItemTreeVTable Component_empty_40::static_vtable = { visit_children, get_item_ref, get_subtree_range, get_subtree, get_item_tree, parent_node, embed_component, subtree_index, layout_info, ensure_instantiated, item_geometry, accessible_role, accessible_string_property, accessibility_action, supported_accessibility_actions, element_infos, window_adapter, slint::private_api::drop_in_place<Component_empty_40>, slint::private_api::dealloc };

auto Component_empty_40::init (const class SharedGlobals* globals,slint::cbindgen_private::ItemTreeWeak enclosing_component,uint32_t tree_index,uint32_t tree_index_of_first_child,class Component_empty_36 const *parent) -> void{
    auto self = this;
    self->self_weak = enclosing_component;
    self->globals = globals;
    this->tree_index_of_first_child = tree_index_of_first_child;
    self->tree_index = tree_index;
    self->parent = vtable::VRcMapped<slint::private_api::ItemTreeVTable, const Component_empty_36>(parent->self_weak.lock().value(), parent);
    self->field_empty_40_layout_cache.set_binding([this]() {
                            [[maybe_unused]] auto self = this;
                            return [&]{ std::array<int, 2> repeated_indices_array;  std::vector<slint::cbindgen_private::LayoutItemInfo> cells_vector;self->repeater_0.track_instance_changes();repeated_indices_array[0] = cells_vector.size();repeated_indices_array[1] = self->repeater_0.len();{
                                    auto start_offset = cells_vector.size();
                                    self->repeater_0.for_each([&](const auto &sub_comp){ cells_vector.push_back(sub_comp->layout_item_info(slint::cbindgen_private::Orientation::Vertical, std::nullopt)); });
                                    cells_vector.resize(start_offset + self->repeater_0.len());
                                }cells_vector.push_back({ [&](const auto &a_0){ slint::cbindgen_private::LayoutItemInfo o{}; o.constraint = a_0; return o; }([&]{ [[maybe_unused]] auto layout_info = slint::private_api::item_layout_info(SLINT_GET_ITEM_VTABLE(EmptyVTable), const_cast<slint::cbindgen_private::Empty*>(&self->field_rectangle_45), slint::cbindgen_private::Orientation::Vertical, -1, &self->globals->window().window_handle(), self->self_weak.lock()->into_dyn(), self->tree_index_of_first_child + 2 - 1);;return [&](const auto &a_0, const auto &a_1, const auto &a_2, const auto &a_3, const auto &a_4, const auto &a_5){ slint::cbindgen_private::LayoutInfo o{}; o.max = a_0; o.max_percent = a_1; o.min = a_2; o.min_percent = a_3; o.preferred = a_4; o.stretch = a_5; return o; }(6, layout_info.max_percent, 6, layout_info.min_percent, layout_info.preferred, layout_info.stretch); }()) });cells_vector.push_back({ [&](const auto &a_0){ slint::cbindgen_private::LayoutItemInfo o{}; o.constraint = a_0; return o; }(slint::private_api::item_layout_info(SLINT_GET_ITEM_VTABLE(SimpleTextVTable), const_cast<slint::cbindgen_private::SimpleText*>(&self->field_text_46), slint::cbindgen_private::Orientation::Vertical, -1, &self->globals->window().window_handle(), self->self_weak.lock()->into_dyn(), self->tree_index_of_first_child + 3 - 1)) });slint::cbindgen_private::Slice<int> repeated_indices = slint::private_api::make_slice(std::span(repeated_indices_array)); slint::cbindgen_private::Slice<slint::cbindgen_private::LayoutItemInfo>cells = slint::private_api::make_slice(std::span(cells_vector)); return slint::private_api::solve_box_layout([&](const auto &a_0, const auto &a_1, const auto &a_2, const auto &a_3, const auto &a_4){ slint::cbindgen_private::BoxLayoutData o{}; o.alignment = a_0; o.cells = a_1; o.padding = a_2; o.size = a_3; o.spacing = a_4; return o; }(slint::cbindgen_private::LayoutAlignment::Stretch, cells, [&](const auto &a_0, const auto &a_1){ slint::cbindgen_private::Padding o{}; o.begin = a_0; o.end = a_1; return o; }(0, 0), slint::private_api::optional_or_default(slint::private_api::optional_transform(self->parent.lock(), [&](auto&&x) { return slint::private_api::layout_cache_access(x->field_empty_36_layout_cache.get(), 5, 0, 2); })), 6),repeated_indices); }();
                        });
    self->field_empty_40_layoutinfo_h.set_binding([this]() {
                            [[maybe_unused]] auto self = this;
                            return [&]{   std::vector<slint::cbindgen_private::LayoutItemInfo> cells_vector;self->repeater_0.track_instance_changes();{
                                    auto start_offset = cells_vector.size();
                                    self->repeater_0.for_each([&](const auto &sub_comp){ cells_vector.push_back(sub_comp->layout_item_info(slint::cbindgen_private::Orientation::Horizontal, std::nullopt)); });
                                    cells_vector.resize(start_offset + self->repeater_0.len());
                                }cells_vector.push_back({ [&](const auto &a_0){ slint::cbindgen_private::LayoutItemInfo o{}; o.constraint = a_0; return o; }(slint::private_api::item_layout_info(SLINT_GET_ITEM_VTABLE(EmptyVTable), const_cast<slint::cbindgen_private::Empty*>(&self->field_rectangle_45), slint::cbindgen_private::Orientation::Horizontal, -1, &self->globals->window().window_handle(), self->self_weak.lock()->into_dyn(), self->tree_index_of_first_child + 2 - 1)) });cells_vector.push_back({ [&](const auto &a_0){ slint::cbindgen_private::LayoutItemInfo o{}; o.constraint = a_0; return o; }(slint::private_api::item_layout_info(SLINT_GET_ITEM_VTABLE(SimpleTextVTable), const_cast<slint::cbindgen_private::SimpleText*>(&self->field_text_46), slint::cbindgen_private::Orientation::Horizontal, -1, &self->globals->window().window_handle(), self->self_weak.lock()->into_dyn(), self->tree_index_of_first_child + 3 - 1)) }); slint::cbindgen_private::Slice<slint::cbindgen_private::LayoutItemInfo>cells = slint::private_api::make_slice(std::span(cells_vector)); return slint::private_api::box_layout_info_ortho(cells,[&](const auto &a_0, const auto &a_1){ slint::cbindgen_private::Padding o{}; o.begin = a_0; o.end = a_1; return o; }(0, 0)); }();
                        });
    self->field_empty_40_layoutinfo_v.set_binding([this]() {
                            [[maybe_unused]] auto self = this;
                            return [&]{   std::vector<slint::cbindgen_private::LayoutItemInfo> cells_vector;self->repeater_0.track_instance_changes();{
                                    auto start_offset = cells_vector.size();
                                    self->repeater_0.for_each([&](const auto &sub_comp){ cells_vector.push_back(sub_comp->layout_item_info(slint::cbindgen_private::Orientation::Vertical, std::nullopt)); });
                                    cells_vector.resize(start_offset + self->repeater_0.len());
                                }cells_vector.push_back({ [&](const auto &a_0){ slint::cbindgen_private::LayoutItemInfo o{}; o.constraint = a_0; return o; }([&]{ [[maybe_unused]] auto layout_info = slint::private_api::item_layout_info(SLINT_GET_ITEM_VTABLE(EmptyVTable), const_cast<slint::cbindgen_private::Empty*>(&self->field_rectangle_45), slint::cbindgen_private::Orientation::Vertical, -1, &self->globals->window().window_handle(), self->self_weak.lock()->into_dyn(), self->tree_index_of_first_child + 2 - 1);;return [&](const auto &a_0, const auto &a_1, const auto &a_2, const auto &a_3, const auto &a_4, const auto &a_5){ slint::cbindgen_private::LayoutInfo o{}; o.max = a_0; o.max_percent = a_1; o.min = a_2; o.min_percent = a_3; o.preferred = a_4; o.stretch = a_5; return o; }(6, layout_info.max_percent, 6, layout_info.min_percent, layout_info.preferred, layout_info.stretch); }()) });cells_vector.push_back({ [&](const auto &a_0){ slint::cbindgen_private::LayoutItemInfo o{}; o.constraint = a_0; return o; }(slint::private_api::item_layout_info(SLINT_GET_ITEM_VTABLE(SimpleTextVTable), const_cast<slint::cbindgen_private::SimpleText*>(&self->field_text_46), slint::cbindgen_private::Orientation::Vertical, -1, &self->globals->window().window_handle(), self->self_weak.lock()->into_dyn(), self->tree_index_of_first_child + 3 - 1)) }); slint::cbindgen_private::Slice<slint::cbindgen_private::LayoutItemInfo>cells = slint::private_api::make_slice(std::span(cells_vector)); return slint::private_api::box_layout_info(cells,6,[&](const auto &a_0, const auto &a_1){ slint::cbindgen_private::Padding o{}; o.begin = a_0; o.end = a_1; return o; }(0, 0),slint::cbindgen_private::LayoutAlignment::Stretch); }();
                        });
    self->field_empty_40_width.set_binding([this]() {
                            [[maybe_unused]] auto self = this;
                            return ((((slint::private_api::optional_or_default(slint::private_api::optional_transform(slint::private_api::optional_and_then(self->parent.lock(), [&](auto&&x) { return x->parent.lock(); }), [&](auto&&x) { return x->field_flickable_15.viewport_width.get(); })) -(float) 60) -(float) 60) -(float) 24) -(float) 24);
                        });
    self->field_text_46.color.set(slint::Brush(slint::Color::from_argb_encoded(+4.289113544e9)));
    self->field_text_46.font_size.set(13);
    self->field_text_46.font_weight.set(static_cast<int>(700));
    self->field_text_46.height.set_binding([this]() {
                            [[maybe_unused]] auto self = this;
                            return self->field_empty_40_layout_cache.get()[5];
                        });
    self->field_text_46.text.set_binding([this]() {
                            [[maybe_unused]] auto self = this;
                            return (slint::SharedString(u8"Total Dependencies Size: ") + slint::private_api::optional_or_default(slint::private_api::optional_transform(slint::private_api::optional_and_then(self->parent.lock(), [&](auto&&x) { return x->parent.lock(); }), [&](auto&&x) { return x->field_root_14_details.get(); })).total_deps_size_str);
                        });
    self->field_text_46.width.set_binding([this]() {
                            [[maybe_unused]] auto self = this;
                            return ((((slint::private_api::optional_or_default(slint::private_api::optional_transform(slint::private_api::optional_and_then(self->parent.lock(), [&](auto&&x) { return x->parent.lock(); }), [&](auto&&x) { return x->field_flickable_15.viewport_width.get(); })) -(float) 60) -(float) 60) -(float) 24) -(float) 24);
                        });
    self->field_text_46.color.set_constant();
    self->field_text_46.font_size.set_constant();
    self->field_text_46.font_weight.set_constant();
    self->field_text_46.horizontal_alignment.set_constant();
    self->field_text_46.vertical_alignment.set_constant();
    self->repeater_0.set_model_binding([self] { (void)self; return slint::private_api::optional_or_default(slint::private_api::optional_transform(slint::private_api::optional_and_then(self->parent.lock(), [&](auto&&x) { return x->parent.lock(); }), [&](auto&&x) { return x->field_root_14_details.get(); })).dependencies; });
}

auto Component_empty_40::user_init () -> void{
    [[maybe_unused]] auto self = this;
}

auto Component_empty_40::layout_info (slint::cbindgen_private::Orientation o) const -> slint::cbindgen_private::LayoutInfo{
    [[maybe_unused]] auto self = this;
    return o == slint::cbindgen_private::Orientation::Horizontal ? self->field_empty_40_layoutinfo_h.get() : self->field_empty_40_layoutinfo_v.get();
}

auto Component_empty_40::item_geometry (uint32_t index) const -> slint::cbindgen_private::Rect{
    [[maybe_unused]] auto self = this;
    switch (index) {
        case 0: return slint::private_api::convert_anonymous_rect(std::make_tuple(float(slint::private_api::optional_or_default(slint::private_api::optional_transform(self->parent.lock(), [&](auto&&x) { return slint::private_api::layout_cache_access(x->field_empty_36_layout_cache.get(), 5, 0, 2); }))), float(((((slint::private_api::optional_or_default(slint::private_api::optional_transform(slint::private_api::optional_and_then(self->parent.lock(), [&](auto&&x) { return x->parent.lock(); }), [&](auto&&x) { return x->field_flickable_15.viewport_width.get(); })) -(float) 60) -(float) 60) -(float) 24) -(float) 24)), float(0), float(slint::private_api::optional_or_default(slint::private_api::optional_transform(self->parent.lock(), [&](auto&&x) { return slint::private_api::layout_cache_access(x->field_empty_36_layout_cache.get(), 4, 0, 2); })))));
        case 2: return slint::private_api::convert_anonymous_rect(std::make_tuple(float(6), float(slint::private_api::optional_or_default(slint::private_api::optional_transform(self->parent.lock(), [&](auto&&x) { return x->field_empty_36_width.get(); }))), float(0), float(self->field_empty_40_layout_cache.get()[2])));
        case 3: return slint::private_api::convert_anonymous_rect(std::make_tuple(float(self->field_empty_40_layout_cache.get()[5]), float(((((slint::private_api::optional_or_default(slint::private_api::optional_transform(slint::private_api::optional_and_then(self->parent.lock(), [&](auto&&x) { return x->parent.lock(); }), [&](auto&&x) { return x->field_flickable_15.viewport_width.get(); })) -(float) 60) -(float) 60) -(float) 24) -(float) 24)), float(0), float(self->field_empty_40_layout_cache.get()[4])));
    }
    return {};
}

auto Component_empty_40::accessible_role (uint32_t index) const -> slint::cbindgen_private::AccessibleRole{
    [[maybe_unused]] auto self = this;
    switch (index) {
        case 3: return slint::cbindgen_private::AccessibleRole::Text;
    }
    return {};
}

auto Component_empty_40::accessible_string_property (uint32_t index, slint::cbindgen_private::AccessibleStringProperty what) const -> std::optional<slint::SharedString>{
    [[maybe_unused]] auto self = this;
    switch ((index << 8) | uintptr_t(what)) {
        case (3 << 8) | uintptr_t(slint::cbindgen_private::AccessibleStringProperty::Label): return self->field_text_46.text.get();
    }
    return {};
}

auto Component_empty_40::accessibility_action (uint32_t index, const slint::cbindgen_private::AccessibilityAction &action) const -> void{
    [[maybe_unused]] auto self = this;
    switch ((index << 8) | uintptr_t(action.tag)) {
    }
    return ;
}

auto Component_empty_40::supported_accessibility_actions (uint32_t index) const -> uint32_t{
    [[maybe_unused]] auto self = this;
    switch (index) {
    }
    return {};
}

auto Component_empty_40::element_infos (uint32_t index) const -> std::optional<slint::SharedString>{
    [[maybe_unused]] auto self = this;
    switch (index) {
    }
    return {};
}

auto Component_empty_40::ensure_instantiated () const -> bool{
    [[maybe_unused]] auto self = this;
    bool _changed = false;
    _changed |= self->repeater_0.ensure_updated(self);
    return _changed;
}

auto Component_empty_40::visit_dynamic_children (uint32_t dyn_index, [[maybe_unused]] slint::private_api::TraversalOrder order, [[maybe_unused]] slint::private_api::ItemVisitorRefMut visitor) const -> uint64_t{
        auto self = this;
        switch(dyn_index) { 
        case 0: {
                return self->repeater_0.visit(order, visitor);
            } };
        std::abort();
}

auto Component_empty_40::subtree_range (uintptr_t dyn_index) const -> slint::private_api::IndexRange{
    [[maybe_unused]] auto self = this;
        switch(dyn_index) { 
        case 0: {
                self->repeater_0.track_instance_changes();
                return self->repeater_0.index_range();
            } };
        std::abort();
}

auto Component_empty_40::subtree_component (uintptr_t dyn_index, [[maybe_unused]] uintptr_t subtree_index, [[maybe_unused]] slint::private_api::ItemTreeWeak *result) const -> void{
    [[maybe_unused]] auto self = this;
        switch(dyn_index) { 
        case 0: {
                *result = self->repeater_0.instance_at(subtree_index);
                return;
            } };
        std::abort();
}

auto Component_empty_40::visit_children (slint::private_api::ItemTreeRef component, intptr_t index, slint::private_api::TraversalOrder order, slint::private_api::ItemVisitorRefMut visitor) -> uint64_t{
    static const auto dyn_visit = [] (const void *base,  [[maybe_unused]] slint::private_api::TraversalOrder order, [[maybe_unused]] slint::private_api::ItemVisitorRefMut visitor, [[maybe_unused]] uint32_t dyn_index) -> uint64_t {
        [[maybe_unused]] auto self = reinterpret_cast<const Component_empty_40*>(base);
        return self->visit_dynamic_children(dyn_index, order, visitor);
    };
    auto self_rc = reinterpret_cast<const Component_empty_40*>(component.instance)->self_weak.lock()->into_dyn();
    return slint::cbindgen_private::slint_visit_item_tree(&self_rc, get_item_tree(component) , index, order, visitor, dyn_visit);
}

auto Component_empty_40::get_item_ref (slint::private_api::ItemTreeRef component, uint32_t index) -> slint::private_api::ItemRef{
    return slint::private_api::get_item_ref(component, get_item_tree(component), item_array(), index);
}

auto Component_empty_40::get_subtree_range ([[maybe_unused]] slint::private_api::ItemTreeRef component, [[maybe_unused]] uint32_t dyn_index) -> slint::private_api::IndexRange{
    auto self = reinterpret_cast<const Component_empty_40*>(component.instance);
    return self->subtree_range(dyn_index);
}

auto Component_empty_40::get_subtree ([[maybe_unused]] slint::private_api::ItemTreeRef component, [[maybe_unused]] uint32_t dyn_index, [[maybe_unused]] uintptr_t subtree_index, [[maybe_unused]] slint::private_api::ItemTreeWeak *result) -> void{
    auto self = reinterpret_cast<const Component_empty_40*>(component.instance);
    self->subtree_component(dyn_index, subtree_index, result);
}

auto Component_empty_40::get_item_tree (slint::private_api::ItemTreeRef) -> slint::cbindgen_private::Slice<slint::private_api::ItemTreeNode>{
    return item_tree();
}

auto Component_empty_40::parent_node ([[maybe_unused]] slint::private_api::ItemTreeRef component, [[maybe_unused]] slint::private_api::ItemWeak *result) -> void{
    auto self = reinterpret_cast<const Component_empty_40*>(component.instance);
    auto parent = self->parent.lock().value();
    *result = { parent->self_weak, parent->tree_index_of_first_child + 2 };
}

auto Component_empty_40::embed_component ([[maybe_unused]] slint::private_api::ItemTreeRef component, [[maybe_unused]] const slint::private_api::ItemTreeWeak *parent_component, [[maybe_unused]] const uint32_t parent_index) -> bool{
    return false; /* todo! */
}

auto Component_empty_40::subtree_index ([[maybe_unused]] slint::private_api::ItemTreeRef component) -> uintptr_t{
    return std::numeric_limits<uintptr_t>::max();
}

auto Component_empty_40::item_tree () -> slint::cbindgen_private::Slice<slint::private_api::ItemTreeNode>{
    static const slint::private_api::ItemTreeNode children[] {
        slint::private_api::make_item_node(3, 1, 0, 0, false), 
slint::private_api::make_dyn_node(0, 0), 
slint::private_api::make_item_node(0, 4, 0, 1, false), 
slint::private_api::make_item_node(0, 4, 0, 2, true) };
    return slint::private_api::make_slice(std::span(children));
}

auto Component_empty_40::item_array () -> const slint::private_api::ItemArray{
    static const slint::private_api::ItemArrayEntry items[] {
        { SLINT_GET_ITEM_VTABLE(EmptyVTable),  offsetof(Component_empty_40, field_empty_40) }, 
{ SLINT_GET_ITEM_VTABLE(EmptyVTable),  offsetof(Component_empty_40, field_rectangle_45) }, 
{ SLINT_GET_ITEM_VTABLE(SimpleTextVTable),  offsetof(Component_empty_40, field_text_46) } };
    return slint::private_api::make_slice(std::span(items));
}

auto Component_empty_40::layout_info ([[maybe_unused]] slint::private_api::ItemTreeRef component, slint::cbindgen_private::Orientation o) -> slint::cbindgen_private::LayoutInfo{
    return reinterpret_cast<const Component_empty_40*>(component.instance)->layout_info(o);
}

auto Component_empty_40::ensure_instantiated ([[maybe_unused]] slint::private_api::ItemTreeRef component) -> bool{
    return reinterpret_cast<const Component_empty_40*>(component.instance)->ensure_instantiated();
}

auto Component_empty_40::item_geometry ([[maybe_unused]] slint::private_api::ItemTreeRef component, uint32_t index) -> slint::cbindgen_private::LogicalRect{
    return reinterpret_cast<const Component_empty_40*>(component.instance)->item_geometry(index);
}

auto Component_empty_40::accessible_role ([[maybe_unused]] slint::private_api::ItemTreeRef component, uint32_t index) -> slint::cbindgen_private::AccessibleRole{
    return reinterpret_cast<const Component_empty_40*>(component.instance)->accessible_role(index);
}

auto Component_empty_40::accessible_string_property ([[maybe_unused]] slint::private_api::ItemTreeRef component, uint32_t index, slint::cbindgen_private::AccessibleStringProperty what, slint::SharedString *result) -> bool{
    if (auto r = reinterpret_cast<const Component_empty_40*>(component.instance)->accessible_string_property(index, what)) { *result = *r; return true; } else { return false; }
}

auto Component_empty_40::accessibility_action ([[maybe_unused]] slint::private_api::ItemTreeRef component, uint32_t index, const slint::cbindgen_private::AccessibilityAction *action) -> void{
    reinterpret_cast<const Component_empty_40*>(component.instance)->accessibility_action(index, *action);
}

auto Component_empty_40::supported_accessibility_actions ([[maybe_unused]] slint::private_api::ItemTreeRef component, uint32_t index) -> uint32_t{
    return reinterpret_cast<const Component_empty_40*>(component.instance)->supported_accessibility_actions(index);
}

auto Component_empty_40::element_infos ([[maybe_unused]] slint::private_api::ItemTreeRef component, [[maybe_unused]] uint32_t index, [[maybe_unused]] slint::SharedString *result) -> bool{
    return false;
}

auto Component_empty_40::window_adapter ([[maybe_unused]] slint::private_api::ItemTreeRef component, [[maybe_unused]] bool do_create, [[maybe_unused]] slint::cbindgen_private::Option<slint::private_api::WindowAdapterRc>* result) -> void{
    *reinterpret_cast<slint::private_api::WindowAdapterRc*>(result) = reinterpret_cast<const Component_empty_40*>(component.instance)->globals->window().window_handle();
}

auto Component_empty_40::create (class Component_empty_36 const * parent) -> slint::ComponentHandle<Component_empty_40>{
    auto self_rc = vtable::VRc<slint::private_api::ItemTreeVTable, Component_empty_40>::make();
    auto self = const_cast<Component_empty_40 *>(&*self_rc);
    self->self_weak = vtable::VWeak(self_rc).into_dyn();
    slint::private_api::register_item_tree(&self_rc.into_dyn(), parent->globals->m_window);
    self->init(parent->globals, self->self_weak, 0, 1 , parent);
    return slint::ComponentHandle<Component_empty_40>{ self_rc };
}

Component_empty_40::~Component_empty_40 (){
    if (auto &window = globals->m_window) window->window_handle().unregister_item_tree(this, item_array());
}

auto Component_empty_40::init () -> void{
    user_init();
}

auto Component_empty_40::layout_item_info (slint::cbindgen_private::Orientation o, [[maybe_unused]] std::optional<size_t> child_index) const -> slint::cbindgen_private::LayoutItemInfo{
    return { layout_info({&static_vtable, const_cast<void *>(static_cast<const void *>(this))}, o) };
}

auto Component_empty_40::flexbox_layout_item_info (slint::cbindgen_private::Orientation o, [[maybe_unused]] std::optional<size_t> child_index) const -> slint::cbindgen_private::FlexboxLayoutItemInfo{
    auto base = layout_item_info(o, child_index); return { base.constraint, 0.0f, 0.0f, -1.0f, slint::cbindgen_private::FlexboxLayoutAlignSelf::Auto, 0 };
}

const slint::private_api::ItemTreeVTable Component_empty_36::static_vtable = { visit_children, get_item_ref, get_subtree_range, get_subtree, get_item_tree, parent_node, embed_component, subtree_index, layout_info, ensure_instantiated, item_geometry, accessible_role, accessible_string_property, accessibility_action, supported_accessibility_actions, element_infos, window_adapter, slint::private_api::drop_in_place<Component_empty_36>, slint::private_api::dealloc };

auto Component_empty_36::init (const class SharedGlobals* globals,slint::cbindgen_private::ItemTreeWeak enclosing_component,uint32_t tree_index,uint32_t tree_index_of_first_child,class DetailsView_root_14 const *parent) -> void{
    auto self = this;
    self->self_weak = enclosing_component;
    self->globals = globals;
    this->tree_index_of_first_child = tree_index_of_first_child;
    self->tree_index = tree_index;
    self->parent = vtable::VRcMapped<slint::private_api::ItemTreeVTable, const DetailsView_root_14>(parent->self_weak.lock().value(), parent);
    self->field_empty_36_layout_cache.set_binding([this]() {
                            [[maybe_unused]] auto self = this;
                            return [&]{ std::array<int, 4> repeated_indices_array;  std::vector<slint::cbindgen_private::LayoutItemInfo> cells_vector;cells_vector.push_back({ [&](const auto &a_0){ slint::cbindgen_private::LayoutItemInfo o{}; o.constraint = a_0; return o; }(slint::private_api::item_layout_info(SLINT_GET_ITEM_VTABLE(SimpleTextVTable), const_cast<slint::cbindgen_private::SimpleText*>(&self->field_text_37), slint::cbindgen_private::Orientation::Vertical, -1, &self->globals->window().window_handle(), self->self_weak.lock()->into_dyn(), self->tree_index_of_first_child + 1 - 1)) });self->repeater_0.track_instance_changes();repeated_indices_array[0] = cells_vector.size();repeated_indices_array[1] = self->repeater_0.len();{
                                    auto start_offset = cells_vector.size();
                                    self->repeater_0.for_each([&](const auto &sub_comp){ cells_vector.push_back(sub_comp->layout_item_info(slint::cbindgen_private::Orientation::Vertical, std::nullopt)); });
                                    cells_vector.resize(start_offset + self->repeater_0.len());
                                }self->repeater_1.track_instance_changes();repeated_indices_array[2] = cells_vector.size();repeated_indices_array[3] = self->repeater_1.len();{
                                    auto start_offset = cells_vector.size();
                                    self->repeater_1.for_each([&](const auto &sub_comp){ cells_vector.push_back(sub_comp->layout_item_info(slint::cbindgen_private::Orientation::Vertical, std::nullopt)); });
                                    cells_vector.resize(start_offset + self->repeater_1.len());
                                }cells_vector.push_back({ [&](const auto &a_0){ slint::cbindgen_private::LayoutItemInfo o{}; o.constraint = a_0; return o; }([&]{ [[maybe_unused]] auto layout_info = slint::private_api::item_layout_info(SLINT_GET_ITEM_VTABLE(EmptyVTable), const_cast<slint::cbindgen_private::Empty*>(&self->field_rectangle_48), slint::cbindgen_private::Orientation::Vertical, -1, &self->globals->window().window_handle(), self->self_weak.lock()->into_dyn(), self->tree_index_of_first_child + 4 - 1);;return [&](const auto &a_0, const auto &a_1, const auto &a_2, const auto &a_3, const auto &a_4, const auto &a_5){ slint::cbindgen_private::LayoutInfo o{}; o.max = a_0; o.max_percent = a_1; o.min = a_2; o.min_percent = a_3; o.preferred = a_4; o.stretch = a_5; return o; }(8, layout_info.max_percent, 8, layout_info.min_percent, layout_info.preferred, layout_info.stretch); }()) });cells_vector.push_back({ [&](const auto &a_0){ slint::cbindgen_private::LayoutItemInfo o{}; o.constraint = a_0; return o; }([&]{ [[maybe_unused]] auto layout_info = slint::private_api::item_layout_info(SLINT_GET_ITEM_VTABLE(RectangleVTable), const_cast<slint::cbindgen_private::Rectangle*>(&self->field_rectangle_49), slint::cbindgen_private::Orientation::Vertical, -1, &self->globals->window().window_handle(), self->self_weak.lock()->into_dyn(), self->tree_index_of_first_child + 5 - 1);;return [&](const auto &a_0, const auto &a_1, const auto &a_2, const auto &a_3, const auto &a_4, const auto &a_5){ slint::cbindgen_private::LayoutInfo o{}; o.max = a_0; o.max_percent = a_1; o.min = a_2; o.min_percent = a_3; o.preferred = a_4; o.stretch = a_5; return o; }(1, layout_info.max_percent, 1, layout_info.min_percent, layout_info.preferred, layout_info.stretch); }()) });cells_vector.push_back({ [&](const auto &a_0){ slint::cbindgen_private::LayoutItemInfo o{}; o.constraint = a_0; return o; }([&]{ [[maybe_unused]] auto layout_info = slint::private_api::item_layout_info(SLINT_GET_ITEM_VTABLE(EmptyVTable), const_cast<slint::cbindgen_private::Empty*>(&self->field_rectangle_50), slint::cbindgen_private::Orientation::Vertical, -1, &self->globals->window().window_handle(), self->self_weak.lock()->into_dyn(), self->tree_index_of_first_child + 6 - 1);;return [&](const auto &a_0, const auto &a_1, const auto &a_2, const auto &a_3, const auto &a_4, const auto &a_5){ slint::cbindgen_private::LayoutInfo o{}; o.max = a_0; o.max_percent = a_1; o.min = a_2; o.min_percent = a_3; o.preferred = a_4; o.stretch = a_5; return o; }(8, layout_info.max_percent, 8, layout_info.min_percent, layout_info.preferred, layout_info.stretch); }()) });cells_vector.push_back({ [&](const auto &a_0){ slint::cbindgen_private::LayoutItemInfo o{}; o.constraint = a_0; return o; }(slint::private_api::item_layout_info(SLINT_GET_ITEM_VTABLE(SimpleTextVTable), const_cast<slint::cbindgen_private::SimpleText*>(&self->field_text_51), slint::cbindgen_private::Orientation::Vertical, -1, &self->globals->window().window_handle(), self->self_weak.lock()->into_dyn(), self->tree_index_of_first_child + 7 - 1)) });cells_vector.push_back({ [&](const auto &a_0){ slint::cbindgen_private::LayoutItemInfo o{}; o.constraint = a_0; return o; }(slint::private_api::item_layout_info(SLINT_GET_ITEM_VTABLE(SimpleTextVTable), const_cast<slint::cbindgen_private::SimpleText*>(&self->field_text_52), slint::cbindgen_private::Orientation::Vertical, -1, &self->globals->window().window_handle(), self->self_weak.lock()->into_dyn(), self->tree_index_of_first_child + 8 - 1)) });slint::cbindgen_private::Slice<int> repeated_indices = slint::private_api::make_slice(std::span(repeated_indices_array)); slint::cbindgen_private::Slice<slint::cbindgen_private::LayoutItemInfo>cells = slint::private_api::make_slice(std::span(cells_vector)); return slint::private_api::solve_box_layout([&](const auto &a_0, const auto &a_1, const auto &a_2, const auto &a_3, const auto &a_4){ slint::cbindgen_private::BoxLayoutData o{}; o.alignment = a_0; o.cells = a_1; o.padding = a_2; o.size = a_3; o.spacing = a_4; return o; }(slint::cbindgen_private::LayoutAlignment::Stretch, cells, [&](const auto &a_0, const auto &a_1){ slint::cbindgen_private::Padding o{}; o.begin = a_0; o.end = a_1; return o; }(0, 0), slint::private_api::optional_or_default(slint::private_api::optional_transform(self->parent.lock(), [&](auto&&x) { return slint::private_api::layout_cache_access(x->field_root_14_empty_33_layout_cache.get(), 3, 0, 2); })), 10),repeated_indices); }();
                        });
    self->field_empty_36_layoutinfo_h.set_binding([this]() {
                            [[maybe_unused]] auto self = this;
                            return [&]{   std::vector<slint::cbindgen_private::LayoutItemInfo> cells_vector;cells_vector.push_back({ [&](const auto &a_0){ slint::cbindgen_private::LayoutItemInfo o{}; o.constraint = a_0; return o; }(slint::private_api::item_layout_info(SLINT_GET_ITEM_VTABLE(SimpleTextVTable), const_cast<slint::cbindgen_private::SimpleText*>(&self->field_text_37), slint::cbindgen_private::Orientation::Horizontal, -1, &self->globals->window().window_handle(), self->self_weak.lock()->into_dyn(), self->tree_index_of_first_child + 1 - 1)) });self->repeater_0.track_instance_changes();{
                                    auto start_offset = cells_vector.size();
                                    self->repeater_0.for_each([&](const auto &sub_comp){ cells_vector.push_back(sub_comp->layout_item_info(slint::cbindgen_private::Orientation::Horizontal, std::nullopt)); });
                                    cells_vector.resize(start_offset + self->repeater_0.len());
                                }self->repeater_1.track_instance_changes();{
                                    auto start_offset = cells_vector.size();
                                    self->repeater_1.for_each([&](const auto &sub_comp){ cells_vector.push_back(sub_comp->layout_item_info(slint::cbindgen_private::Orientation::Horizontal, std::nullopt)); });
                                    cells_vector.resize(start_offset + self->repeater_1.len());
                                }cells_vector.push_back({ [&](const auto &a_0){ slint::cbindgen_private::LayoutItemInfo o{}; o.constraint = a_0; return o; }(slint::private_api::item_layout_info(SLINT_GET_ITEM_VTABLE(EmptyVTable), const_cast<slint::cbindgen_private::Empty*>(&self->field_rectangle_48), slint::cbindgen_private::Orientation::Horizontal, -1, &self->globals->window().window_handle(), self->self_weak.lock()->into_dyn(), self->tree_index_of_first_child + 4 - 1)) });cells_vector.push_back({ [&](const auto &a_0){ slint::cbindgen_private::LayoutItemInfo o{}; o.constraint = a_0; return o; }(slint::private_api::item_layout_info(SLINT_GET_ITEM_VTABLE(RectangleVTable), const_cast<slint::cbindgen_private::Rectangle*>(&self->field_rectangle_49), slint::cbindgen_private::Orientation::Horizontal, -1, &self->globals->window().window_handle(), self->self_weak.lock()->into_dyn(), self->tree_index_of_first_child + 5 - 1)) });cells_vector.push_back({ [&](const auto &a_0){ slint::cbindgen_private::LayoutItemInfo o{}; o.constraint = a_0; return o; }(slint::private_api::item_layout_info(SLINT_GET_ITEM_VTABLE(EmptyVTable), const_cast<slint::cbindgen_private::Empty*>(&self->field_rectangle_50), slint::cbindgen_private::Orientation::Horizontal, -1, &self->globals->window().window_handle(), self->self_weak.lock()->into_dyn(), self->tree_index_of_first_child + 6 - 1)) });cells_vector.push_back({ [&](const auto &a_0){ slint::cbindgen_private::LayoutItemInfo o{}; o.constraint = a_0; return o; }(slint::private_api::item_layout_info(SLINT_GET_ITEM_VTABLE(SimpleTextVTable), const_cast<slint::cbindgen_private::SimpleText*>(&self->field_text_51), slint::cbindgen_private::Orientation::Horizontal, -1, &self->globals->window().window_handle(), self->self_weak.lock()->into_dyn(), self->tree_index_of_first_child + 7 - 1)) });cells_vector.push_back({ [&](const auto &a_0){ slint::cbindgen_private::LayoutItemInfo o{}; o.constraint = a_0; return o; }(slint::private_api::item_layout_info(SLINT_GET_ITEM_VTABLE(SimpleTextVTable), const_cast<slint::cbindgen_private::SimpleText*>(&self->field_text_52), slint::cbindgen_private::Orientation::Horizontal, -1, &self->globals->window().window_handle(), self->self_weak.lock()->into_dyn(), self->tree_index_of_first_child + 8 - 1)) }); slint::cbindgen_private::Slice<slint::cbindgen_private::LayoutItemInfo>cells = slint::private_api::make_slice(std::span(cells_vector)); return slint::private_api::box_layout_info_ortho(cells,[&](const auto &a_0, const auto &a_1){ slint::cbindgen_private::Padding o{}; o.begin = a_0; o.end = a_1; return o; }(0, 0)); }();
                        });
    self->field_empty_36_layoutinfo_v.set_binding([this]() {
                            [[maybe_unused]] auto self = this;
                            return [&]{   std::vector<slint::cbindgen_private::LayoutItemInfo> cells_vector;cells_vector.push_back({ [&](const auto &a_0){ slint::cbindgen_private::LayoutItemInfo o{}; o.constraint = a_0; return o; }(slint::private_api::item_layout_info(SLINT_GET_ITEM_VTABLE(SimpleTextVTable), const_cast<slint::cbindgen_private::SimpleText*>(&self->field_text_37), slint::cbindgen_private::Orientation::Vertical, -1, &self->globals->window().window_handle(), self->self_weak.lock()->into_dyn(), self->tree_index_of_first_child + 1 - 1)) });self->repeater_0.track_instance_changes();{
                                    auto start_offset = cells_vector.size();
                                    self->repeater_0.for_each([&](const auto &sub_comp){ cells_vector.push_back(sub_comp->layout_item_info(slint::cbindgen_private::Orientation::Vertical, std::nullopt)); });
                                    cells_vector.resize(start_offset + self->repeater_0.len());
                                }self->repeater_1.track_instance_changes();{
                                    auto start_offset = cells_vector.size();
                                    self->repeater_1.for_each([&](const auto &sub_comp){ cells_vector.push_back(sub_comp->layout_item_info(slint::cbindgen_private::Orientation::Vertical, std::nullopt)); });
                                    cells_vector.resize(start_offset + self->repeater_1.len());
                                }cells_vector.push_back({ [&](const auto &a_0){ slint::cbindgen_private::LayoutItemInfo o{}; o.constraint = a_0; return o; }([&]{ [[maybe_unused]] auto layout_info = slint::private_api::item_layout_info(SLINT_GET_ITEM_VTABLE(EmptyVTable), const_cast<slint::cbindgen_private::Empty*>(&self->field_rectangle_48), slint::cbindgen_private::Orientation::Vertical, -1, &self->globals->window().window_handle(), self->self_weak.lock()->into_dyn(), self->tree_index_of_first_child + 4 - 1);;return [&](const auto &a_0, const auto &a_1, const auto &a_2, const auto &a_3, const auto &a_4, const auto &a_5){ slint::cbindgen_private::LayoutInfo o{}; o.max = a_0; o.max_percent = a_1; o.min = a_2; o.min_percent = a_3; o.preferred = a_4; o.stretch = a_5; return o; }(8, layout_info.max_percent, 8, layout_info.min_percent, layout_info.preferred, layout_info.stretch); }()) });cells_vector.push_back({ [&](const auto &a_0){ slint::cbindgen_private::LayoutItemInfo o{}; o.constraint = a_0; return o; }([&]{ [[maybe_unused]] auto layout_info = slint::private_api::item_layout_info(SLINT_GET_ITEM_VTABLE(RectangleVTable), const_cast<slint::cbindgen_private::Rectangle*>(&self->field_rectangle_49), slint::cbindgen_private::Orientation::Vertical, -1, &self->globals->window().window_handle(), self->self_weak.lock()->into_dyn(), self->tree_index_of_first_child + 5 - 1);;return [&](const auto &a_0, const auto &a_1, const auto &a_2, const auto &a_3, const auto &a_4, const auto &a_5){ slint::cbindgen_private::LayoutInfo o{}; o.max = a_0; o.max_percent = a_1; o.min = a_2; o.min_percent = a_3; o.preferred = a_4; o.stretch = a_5; return o; }(1, layout_info.max_percent, 1, layout_info.min_percent, layout_info.preferred, layout_info.stretch); }()) });cells_vector.push_back({ [&](const auto &a_0){ slint::cbindgen_private::LayoutItemInfo o{}; o.constraint = a_0; return o; }([&]{ [[maybe_unused]] auto layout_info = slint::private_api::item_layout_info(SLINT_GET_ITEM_VTABLE(EmptyVTable), const_cast<slint::cbindgen_private::Empty*>(&self->field_rectangle_50), slint::cbindgen_private::Orientation::Vertical, -1, &self->globals->window().window_handle(), self->self_weak.lock()->into_dyn(), self->tree_index_of_first_child + 6 - 1);;return [&](const auto &a_0, const auto &a_1, const auto &a_2, const auto &a_3, const auto &a_4, const auto &a_5){ slint::cbindgen_private::LayoutInfo o{}; o.max = a_0; o.max_percent = a_1; o.min = a_2; o.min_percent = a_3; o.preferred = a_4; o.stretch = a_5; return o; }(8, layout_info.max_percent, 8, layout_info.min_percent, layout_info.preferred, layout_info.stretch); }()) });cells_vector.push_back({ [&](const auto &a_0){ slint::cbindgen_private::LayoutItemInfo o{}; o.constraint = a_0; return o; }(slint::private_api::item_layout_info(SLINT_GET_ITEM_VTABLE(SimpleTextVTable), const_cast<slint::cbindgen_private::SimpleText*>(&self->field_text_51), slint::cbindgen_private::Orientation::Vertical, -1, &self->globals->window().window_handle(), self->self_weak.lock()->into_dyn(), self->tree_index_of_first_child + 7 - 1)) });cells_vector.push_back({ [&](const auto &a_0){ slint::cbindgen_private::LayoutItemInfo o{}; o.constraint = a_0; return o; }(slint::private_api::item_layout_info(SLINT_GET_ITEM_VTABLE(SimpleTextVTable), const_cast<slint::cbindgen_private::SimpleText*>(&self->field_text_52), slint::cbindgen_private::Orientation::Vertical, -1, &self->globals->window().window_handle(), self->self_weak.lock()->into_dyn(), self->tree_index_of_first_child + 8 - 1)) }); slint::cbindgen_private::Slice<slint::cbindgen_private::LayoutItemInfo>cells = slint::private_api::make_slice(std::span(cells_vector)); return slint::private_api::box_layout_info(cells,10,[&](const auto &a_0, const auto &a_1){ slint::cbindgen_private::Padding o{}; o.begin = a_0; o.end = a_1; return o; }(0, 0),slint::cbindgen_private::LayoutAlignment::Stretch); }();
                        });
    self->field_empty_36_width.set_binding([this]() {
                            [[maybe_unused]] auto self = this;
                            return ((((slint::private_api::optional_or_default(slint::private_api::optional_transform(self->parent.lock(), [&](auto&&x) { return x->field_flickable_15.viewport_width.get(); })) -(float) 60) -(float) 60) -(float) 24) -(float) 24);
                        });
    self->field_text_37.color.set(slint::Brush(slint::Color::from_argb_encoded(+4.291679988e9)));
    self->field_text_37.font_size.set(17);
    self->field_text_37.font_weight.set(static_cast<int>(600));
    self->field_text_37.height.set_binding([this]() {
                            [[maybe_unused]] auto self = this;
                            return self->field_empty_36_layout_cache.get()[1];
                        });
    self->field_text_37.text.set(slint::SharedString(u8"Dependencies"));
    self->field_text_37.width.set_binding([this]() {
                            [[maybe_unused]] auto self = this;
                            return ((((slint::private_api::optional_or_default(slint::private_api::optional_transform(self->parent.lock(), [&](auto&&x) { return x->field_flickable_15.viewport_width.get(); })) -(float) 60) -(float) 60) -(float) 24) -(float) 24);
                        });
    self->field_rectangle_49.background.set(slint::Brush(slint::Color::from_argb_encoded(+4.281414212e9)));
    self->field_text_51.color.set(slint::Brush(slint::Color::from_argb_encoded(+4.290429662e9)));
    self->field_text_51.font_size.set(15);
    self->field_text_51.font_weight.set(static_cast<int>(600));
    self->field_text_51.height.set_binding([this]() {
                            [[maybe_unused]] auto self = this;
                            return self->field_empty_36_layout_cache.get()[13];
                        });
    self->field_text_51.text.set_binding([this]() {
                            [[maybe_unused]] auto self = this;
                            return (slint::SharedString(u8"App Size: ") + slint::private_api::optional_or_default(slint::private_api::optional_transform(self->parent.lock(), [&](auto&&x) { return x->field_root_14_details.get(); })).app_size_str);
                        });
    self->field_text_51.width.set_binding([this]() {
                            [[maybe_unused]] auto self = this;
                            return ((((slint::private_api::optional_or_default(slint::private_api::optional_transform(self->parent.lock(), [&](auto&&x) { return x->field_flickable_15.viewport_width.get(); })) -(float) 60) -(float) 60) -(float) 24) -(float) 24);
                        });
    self->field_text_52.color.set_binding([this]() {
                            [[maybe_unused]] auto self = this;
                            return [&]{ [[maybe_unused]] auto tmp_Theme_76_accents = self->globals->global_Theme_76->field_accents.get();;return slint::Brush(slint::private_api::access_array_index(tmp_Theme_76_accents, ([](float a, float b) { auto r = std::fmod(a, b); return r >= 0 ? r : r + std::abs(b); })(slint::private_api::optional_or_default(slint::private_api::optional_transform(self->parent.lock(), [&](auto&&x) { return x->field_root_14_accent_idx.get(); })),slint::private_api::model_length(tmp_Theme_76_accents)))); }();
                        });
    self->field_text_52.font_size.set(15);
    self->field_text_52.font_weight.set(static_cast<int>(600));
    self->field_text_52.height.set_binding([this]() {
                            [[maybe_unused]] auto self = this;
                            return self->field_empty_36_layout_cache.get()[15];
                        });
    self->field_text_52.text.set_binding([this]() {
                            [[maybe_unused]] auto self = this;
                            return (slint::SharedString(u8"Total (App + Deps): ") + slint::private_api::optional_or_default(slint::private_api::optional_transform(self->parent.lock(), [&](auto&&x) { return x->field_root_14_details.get(); })).total_size_str);
                        });
    self->field_text_52.width.set_binding([this]() {
                            [[maybe_unused]] auto self = this;
                            return ((((slint::private_api::optional_or_default(slint::private_api::optional_transform(self->parent.lock(), [&](auto&&x) { return x->field_flickable_15.viewport_width.get(); })) -(float) 60) -(float) 60) -(float) 24) -(float) 24);
                        });
    self->field_text_37.color.set_constant();
    self->field_text_37.font_size.set_constant();
    self->field_text_37.font_weight.set_constant();
    self->field_text_37.horizontal_alignment.set_constant();
    self->field_text_37.text.set_constant();
    self->field_text_37.vertical_alignment.set_constant();
    self->field_rectangle_49.background.set_constant();
    self->field_text_51.color.set_constant();
    self->field_text_51.font_size.set_constant();
    self->field_text_51.font_weight.set_constant();
    self->field_text_51.horizontal_alignment.set_constant();
    self->field_text_51.vertical_alignment.set_constant();
    self->field_text_52.font_size.set_constant();
    self->field_text_52.font_weight.set_constant();
    self->field_text_52.horizontal_alignment.set_constant();
    self->field_text_52.vertical_alignment.set_constant();
    self->repeater_0.set_model_binding([self] { (void)self; return (std::abs(float(slint::private_api::model_length(slint::private_api::optional_or_default(slint::private_api::optional_transform(self->parent.lock(), [&](auto&&x) { return x->field_root_14_details.get(); })).dependencies) - 0)) < std::numeric_limits<float>::epsilon()); });
    self->repeater_1.set_model_binding([self] { (void)self; return (slint::private_api::model_length(slint::private_api::optional_or_default(slint::private_api::optional_transform(self->parent.lock(), [&](auto&&x) { return x->field_root_14_details.get(); })).dependencies) > 0); });
}

auto Component_empty_36::user_init () -> void{
    [[maybe_unused]] auto self = this;
}

auto Component_empty_36::layout_info (slint::cbindgen_private::Orientation o) const -> slint::cbindgen_private::LayoutInfo{
    [[maybe_unused]] auto self = this;
    return o == slint::cbindgen_private::Orientation::Horizontal ? self->field_empty_36_layoutinfo_h.get() : self->field_empty_36_layoutinfo_v.get();
}

auto Component_empty_36::item_geometry (uint32_t index) const -> slint::cbindgen_private::Rect{
    [[maybe_unused]] auto self = this;
    switch (index) {
        case 0: return slint::private_api::convert_anonymous_rect(std::make_tuple(float(slint::private_api::optional_or_default(slint::private_api::optional_transform(self->parent.lock(), [&](auto&&x) { return slint::private_api::layout_cache_access(x->field_root_14_empty_33_layout_cache.get(), 3, 0, 2); }))), float(((((slint::private_api::optional_or_default(slint::private_api::optional_transform(self->parent.lock(), [&](auto&&x) { return x->field_flickable_15.viewport_width.get(); })) -(float) 60) -(float) 60) -(float) 24) -(float) 24)), float(24), float(slint::private_api::optional_or_default(slint::private_api::optional_transform(self->parent.lock(), [&](auto&&x) { return slint::private_api::layout_cache_access(x->field_root_14_empty_33_layout_cache.get(), 2, 0, 2); })))));
        case 1: return slint::private_api::convert_anonymous_rect(std::make_tuple(float(self->field_empty_36_layout_cache.get()[1]), float(((((slint::private_api::optional_or_default(slint::private_api::optional_transform(self->parent.lock(), [&](auto&&x) { return x->field_flickable_15.viewport_width.get(); })) -(float) 60) -(float) 60) -(float) 24) -(float) 24)), float(0), float(self->field_empty_36_layout_cache.get()[0])));
        case 4: return slint::private_api::convert_anonymous_rect(std::make_tuple(float(8), float(((((slint::private_api::optional_or_default(slint::private_api::optional_transform(self->parent.lock(), [&](auto&&x) { return x->field_flickable_15.viewport_width.get(); })) -(float) 60) -(float) 60) -(float) 24) -(float) 24)), float(0), float(self->field_empty_36_layout_cache.get()[6])));
        case 5: return slint::private_api::convert_anonymous_rect(std::make_tuple(float(1), float(((((slint::private_api::optional_or_default(slint::private_api::optional_transform(self->parent.lock(), [&](auto&&x) { return x->field_flickable_15.viewport_width.get(); })) -(float) 60) -(float) 60) -(float) 24) -(float) 24)), float(0), float(self->field_empty_36_layout_cache.get()[8])));
        case 6: return slint::private_api::convert_anonymous_rect(std::make_tuple(float(8), float(((((slint::private_api::optional_or_default(slint::private_api::optional_transform(self->parent.lock(), [&](auto&&x) { return x->field_flickable_15.viewport_width.get(); })) -(float) 60) -(float) 60) -(float) 24) -(float) 24)), float(0), float(self->field_empty_36_layout_cache.get()[10])));
        case 7: return slint::private_api::convert_anonymous_rect(std::make_tuple(float(self->field_empty_36_layout_cache.get()[13]), float(((((slint::private_api::optional_or_default(slint::private_api::optional_transform(self->parent.lock(), [&](auto&&x) { return x->field_flickable_15.viewport_width.get(); })) -(float) 60) -(float) 60) -(float) 24) -(float) 24)), float(0), float(self->field_empty_36_layout_cache.get()[12])));
        case 8: return slint::private_api::convert_anonymous_rect(std::make_tuple(float(self->field_empty_36_layout_cache.get()[15]), float(((((slint::private_api::optional_or_default(slint::private_api::optional_transform(self->parent.lock(), [&](auto&&x) { return x->field_flickable_15.viewport_width.get(); })) -(float) 60) -(float) 60) -(float) 24) -(float) 24)), float(0), float(self->field_empty_36_layout_cache.get()[14])));
    }
    return {};
}

auto Component_empty_36::accessible_role (uint32_t index) const -> slint::cbindgen_private::AccessibleRole{
    [[maybe_unused]] auto self = this;
    switch (index) {
        case 1: return slint::cbindgen_private::AccessibleRole::Text;
        case 7: return slint::cbindgen_private::AccessibleRole::Text;
        case 8: return slint::cbindgen_private::AccessibleRole::Text;
    }
    return {};
}

auto Component_empty_36::accessible_string_property (uint32_t index, slint::cbindgen_private::AccessibleStringProperty what) const -> std::optional<slint::SharedString>{
    [[maybe_unused]] auto self = this;
    switch ((index << 8) | uintptr_t(what)) {
        case (1 << 8) | uintptr_t(slint::cbindgen_private::AccessibleStringProperty::Label): return slint::SharedString(u8"Dependencies");
        case (7 << 8) | uintptr_t(slint::cbindgen_private::AccessibleStringProperty::Label): return self->field_text_51.text.get();
        case (8 << 8) | uintptr_t(slint::cbindgen_private::AccessibleStringProperty::Label): return self->field_text_52.text.get();
    }
    return {};
}

auto Component_empty_36::accessibility_action (uint32_t index, const slint::cbindgen_private::AccessibilityAction &action) const -> void{
    [[maybe_unused]] auto self = this;
    switch ((index << 8) | uintptr_t(action.tag)) {
    }
    return ;
}

auto Component_empty_36::supported_accessibility_actions (uint32_t index) const -> uint32_t{
    [[maybe_unused]] auto self = this;
    switch (index) {
    }
    return {};
}

auto Component_empty_36::element_infos (uint32_t index) const -> std::optional<slint::SharedString>{
    [[maybe_unused]] auto self = this;
    switch (index) {
    }
    return {};
}

auto Component_empty_36::ensure_instantiated () const -> bool{
    [[maybe_unused]] auto self = this;
    bool _changed = false;
    _changed |= self->repeater_0.ensure_updated(self);
    _changed |= self->repeater_1.ensure_updated(self);
    return _changed;
}

auto Component_empty_36::visit_dynamic_children (uint32_t dyn_index, [[maybe_unused]] slint::private_api::TraversalOrder order, [[maybe_unused]] slint::private_api::ItemVisitorRefMut visitor) const -> uint64_t{
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

auto Component_empty_36::subtree_range (uintptr_t dyn_index) const -> slint::private_api::IndexRange{
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

auto Component_empty_36::subtree_component (uintptr_t dyn_index, [[maybe_unused]] uintptr_t subtree_index, [[maybe_unused]] slint::private_api::ItemTreeWeak *result) const -> void{
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

auto Component_empty_36::visit_children (slint::private_api::ItemTreeRef component, intptr_t index, slint::private_api::TraversalOrder order, slint::private_api::ItemVisitorRefMut visitor) -> uint64_t{
    static const auto dyn_visit = [] (const void *base,  [[maybe_unused]] slint::private_api::TraversalOrder order, [[maybe_unused]] slint::private_api::ItemVisitorRefMut visitor, [[maybe_unused]] uint32_t dyn_index) -> uint64_t {
        [[maybe_unused]] auto self = reinterpret_cast<const Component_empty_36*>(base);
        return self->visit_dynamic_children(dyn_index, order, visitor);
    };
    auto self_rc = reinterpret_cast<const Component_empty_36*>(component.instance)->self_weak.lock()->into_dyn();
    return slint::cbindgen_private::slint_visit_item_tree(&self_rc, get_item_tree(component) , index, order, visitor, dyn_visit);
}

auto Component_empty_36::get_item_ref (slint::private_api::ItemTreeRef component, uint32_t index) -> slint::private_api::ItemRef{
    return slint::private_api::get_item_ref(component, get_item_tree(component), item_array(), index);
}

auto Component_empty_36::get_subtree_range ([[maybe_unused]] slint::private_api::ItemTreeRef component, [[maybe_unused]] uint32_t dyn_index) -> slint::private_api::IndexRange{
    auto self = reinterpret_cast<const Component_empty_36*>(component.instance);
    return self->subtree_range(dyn_index);
}

auto Component_empty_36::get_subtree ([[maybe_unused]] slint::private_api::ItemTreeRef component, [[maybe_unused]] uint32_t dyn_index, [[maybe_unused]] uintptr_t subtree_index, [[maybe_unused]] slint::private_api::ItemTreeWeak *result) -> void{
    auto self = reinterpret_cast<const Component_empty_36*>(component.instance);
    self->subtree_component(dyn_index, subtree_index, result);
}

auto Component_empty_36::get_item_tree (slint::private_api::ItemTreeRef) -> slint::cbindgen_private::Slice<slint::private_api::ItemTreeNode>{
    return item_tree();
}

auto Component_empty_36::parent_node ([[maybe_unused]] slint::private_api::ItemTreeRef component, [[maybe_unused]] slint::private_api::ItemWeak *result) -> void{
    auto self = reinterpret_cast<const Component_empty_36*>(component.instance);
    auto parent = self->parent.lock().value();
    *result = { parent->self_weak, parent->tree_index_of_first_child + 17 };
}

auto Component_empty_36::embed_component ([[maybe_unused]] slint::private_api::ItemTreeRef component, [[maybe_unused]] const slint::private_api::ItemTreeWeak *parent_component, [[maybe_unused]] const uint32_t parent_index) -> bool{
    return false; /* todo! */
}

auto Component_empty_36::subtree_index ([[maybe_unused]] slint::private_api::ItemTreeRef component) -> uintptr_t{
    return std::numeric_limits<uintptr_t>::max();
}

auto Component_empty_36::item_tree () -> slint::cbindgen_private::Slice<slint::private_api::ItemTreeNode>{
    static const slint::private_api::ItemTreeNode children[] {
        slint::private_api::make_item_node(8, 1, 0, 0, false), 
slint::private_api::make_item_node(0, 9, 0, 1, true), 
slint::private_api::make_dyn_node(0, 0), 
slint::private_api::make_dyn_node(1, 0), 
slint::private_api::make_item_node(0, 9, 0, 2, false), 
slint::private_api::make_item_node(0, 9, 0, 3, false), 
slint::private_api::make_item_node(0, 9, 0, 4, false), 
slint::private_api::make_item_node(0, 9, 0, 5, true), 
slint::private_api::make_item_node(0, 9, 0, 6, true) };
    return slint::private_api::make_slice(std::span(children));
}

auto Component_empty_36::item_array () -> const slint::private_api::ItemArray{
    static const slint::private_api::ItemArrayEntry items[] {
        { SLINT_GET_ITEM_VTABLE(EmptyVTable),  offsetof(Component_empty_36, field_empty_36) }, 
{ SLINT_GET_ITEM_VTABLE(SimpleTextVTable),  offsetof(Component_empty_36, field_text_37) }, 
{ SLINT_GET_ITEM_VTABLE(EmptyVTable),  offsetof(Component_empty_36, field_rectangle_48) }, 
{ SLINT_GET_ITEM_VTABLE(RectangleVTable),  offsetof(Component_empty_36, field_rectangle_49) }, 
{ SLINT_GET_ITEM_VTABLE(EmptyVTable),  offsetof(Component_empty_36, field_rectangle_50) }, 
{ SLINT_GET_ITEM_VTABLE(SimpleTextVTable),  offsetof(Component_empty_36, field_text_51) }, 
{ SLINT_GET_ITEM_VTABLE(SimpleTextVTable),  offsetof(Component_empty_36, field_text_52) } };
    return slint::private_api::make_slice(std::span(items));
}

auto Component_empty_36::layout_info ([[maybe_unused]] slint::private_api::ItemTreeRef component, slint::cbindgen_private::Orientation o) -> slint::cbindgen_private::LayoutInfo{
    return reinterpret_cast<const Component_empty_36*>(component.instance)->layout_info(o);
}

auto Component_empty_36::ensure_instantiated ([[maybe_unused]] slint::private_api::ItemTreeRef component) -> bool{
    return reinterpret_cast<const Component_empty_36*>(component.instance)->ensure_instantiated();
}

auto Component_empty_36::item_geometry ([[maybe_unused]] slint::private_api::ItemTreeRef component, uint32_t index) -> slint::cbindgen_private::LogicalRect{
    return reinterpret_cast<const Component_empty_36*>(component.instance)->item_geometry(index);
}

auto Component_empty_36::accessible_role ([[maybe_unused]] slint::private_api::ItemTreeRef component, uint32_t index) -> slint::cbindgen_private::AccessibleRole{
    return reinterpret_cast<const Component_empty_36*>(component.instance)->accessible_role(index);
}

auto Component_empty_36::accessible_string_property ([[maybe_unused]] slint::private_api::ItemTreeRef component, uint32_t index, slint::cbindgen_private::AccessibleStringProperty what, slint::SharedString *result) -> bool{
    if (auto r = reinterpret_cast<const Component_empty_36*>(component.instance)->accessible_string_property(index, what)) { *result = *r; return true; } else { return false; }
}

auto Component_empty_36::accessibility_action ([[maybe_unused]] slint::private_api::ItemTreeRef component, uint32_t index, const slint::cbindgen_private::AccessibilityAction *action) -> void{
    reinterpret_cast<const Component_empty_36*>(component.instance)->accessibility_action(index, *action);
}

auto Component_empty_36::supported_accessibility_actions ([[maybe_unused]] slint::private_api::ItemTreeRef component, uint32_t index) -> uint32_t{
    return reinterpret_cast<const Component_empty_36*>(component.instance)->supported_accessibility_actions(index);
}

auto Component_empty_36::element_infos ([[maybe_unused]] slint::private_api::ItemTreeRef component, [[maybe_unused]] uint32_t index, [[maybe_unused]] slint::SharedString *result) -> bool{
    return false;
}

auto Component_empty_36::window_adapter ([[maybe_unused]] slint::private_api::ItemTreeRef component, [[maybe_unused]] bool do_create, [[maybe_unused]] slint::cbindgen_private::Option<slint::private_api::WindowAdapterRc>* result) -> void{
    *reinterpret_cast<slint::private_api::WindowAdapterRc*>(result) = reinterpret_cast<const Component_empty_36*>(component.instance)->globals->window().window_handle();
}

auto Component_empty_36::create (class DetailsView_root_14 const * parent) -> slint::ComponentHandle<Component_empty_36>{
    auto self_rc = vtable::VRc<slint::private_api::ItemTreeVTable, Component_empty_36>::make();
    auto self = const_cast<Component_empty_36 *>(&*self_rc);
    self->self_weak = vtable::VWeak(self_rc).into_dyn();
    slint::private_api::register_item_tree(&self_rc.into_dyn(), parent->globals->m_window);
    self->init(parent->globals, self->self_weak, 0, 1 , parent);
    return slint::ComponentHandle<Component_empty_36>{ self_rc };
}

Component_empty_36::~Component_empty_36 (){
    if (auto &window = globals->m_window) window->window_handle().unregister_item_tree(this, item_array());
}

auto Component_empty_36::init () -> void{
    user_init();
}

auto Component_empty_36::layout_item_info (slint::cbindgen_private::Orientation o, [[maybe_unused]] std::optional<size_t> child_index) const -> slint::cbindgen_private::LayoutItemInfo{
    return { layout_info({&static_vtable, const_cast<void *>(static_cast<const void *>(this))}, o) };
}

auto Component_empty_36::flexbox_layout_item_info (slint::cbindgen_private::Orientation o, [[maybe_unused]] std::optional<size_t> child_index) const -> slint::cbindgen_private::FlexboxLayoutItemInfo{
    auto base = layout_item_info(o, child_index); return { base.constraint, 0.0f, 0.0f, -1.0f, slint::cbindgen_private::FlexboxLayoutAlignSelf::Auto, 0 };
}

auto DetailsView_root_14::fn_empty_17_layoutinfo_v_with_constraint ([[maybe_unused]] float arg_0) const -> slint::cbindgen_private::LayoutInfo{
    [[maybe_unused]] auto self = this;
    return slint::private_api::box_layout_info(slint::private_api::make_slice<slint::cbindgen_private::LayoutItemInfo>(std::array<slint::cbindgen_private::LayoutItemInfo, 4>{ slint::cbindgen_private::LayoutItemInfo ( [&](const auto &a_0){ slint::cbindgen_private::LayoutItemInfo o{}; o.constraint = a_0; return o; }(self->fn_empty_18_layoutinfo_v_with_constraint(arg_0)) ), slint::cbindgen_private::LayoutItemInfo ( [&](const auto &a_0){ slint::cbindgen_private::LayoutItemInfo o{}; o.constraint = a_0; return o; }([&]{ [[maybe_unused]] auto layout_info = slint::private_api::item_layout_info(SLINT_GET_ITEM_VTABLE(RectangleVTable), const_cast<slint::cbindgen_private::Rectangle*>(&self->field_rectangle_30), slint::cbindgen_private::Orientation::Vertical, arg_0, &self->globals->window().window_handle(), self->self_weak.lock()->into_dyn(), self->tree_index_of_first_child + 5 - 1);;return [&](const auto &a_0, const auto &a_1, const auto &a_2, const auto &a_3, const auto &a_4, const auto &a_5){ slint::cbindgen_private::LayoutInfo o{}; o.max = a_0; o.max_percent = a_1; o.min = a_2; o.min_percent = a_3; o.preferred = a_4; o.stretch = a_5; return o; }(self->field_root_14_rectangle_30_height.get(), layout_info.max_percent, self->field_root_14_rectangle_30_height.get(), layout_info.min_percent, layout_info.preferred, layout_info.stretch); }()) ), slint::cbindgen_private::LayoutItemInfo ( [&](const auto &a_0){ slint::cbindgen_private::LayoutItemInfo o{}; o.constraint = a_0; return o; }(slint::private_api::item_layout_info(SLINT_GET_ITEM_VTABLE(ComplexTextVTable), const_cast<slint::cbindgen_private::ComplexText*>(&self->field_text_31), slint::cbindgen_private::Orientation::Vertical, arg_0, &self->globals->window().window_handle(), self->self_weak.lock()->into_dyn(), self->tree_index_of_first_child + 6 - 1)) ), slint::cbindgen_private::LayoutItemInfo ( [&](const auto &a_0){ slint::cbindgen_private::LayoutItemInfo o{}; o.constraint = a_0; return o; }(self->field_root_14_rectangle_32_layoutinfo_v.get()) ) }.data(), 4),self->field_root_14_empty_17_spacing.get(),[&](const auto &a_0, const auto &a_1){ slint::cbindgen_private::Padding o{}; o.begin = a_0; o.end = a_1; return o; }(self->field_root_14_empty_17_padding_top.get(), self->field_root_14_empty_17_padding_bottom.get()),slint::cbindgen_private::LayoutAlignment::Stretch);
}

auto DetailsView_root_14::fn_empty_18_layoutinfo_v_with_constraint ([[maybe_unused]] float arg_0) const -> slint::cbindgen_private::LayoutInfo{
    [[maybe_unused]] auto self = this;
    return [&]{   std::vector<slint::cbindgen_private::LayoutItemInfo> cells_vector;self->repeater_0.track_instance_changes();{
                                    auto start_offset = cells_vector.size();
                                    self->repeater_0.for_each([&](const auto &sub_comp){ cells_vector.push_back(sub_comp->layout_item_info(slint::cbindgen_private::Orientation::Vertical, std::nullopt)); });
                                    cells_vector.resize(start_offset + self->repeater_0.len());
                                }self->repeater_1.track_instance_changes();{
                                    auto start_offset = cells_vector.size();
                                    self->repeater_1.for_each([&](const auto &sub_comp){ cells_vector.push_back(sub_comp->layout_item_info(slint::cbindgen_private::Orientation::Vertical, std::nullopt)); });
                                    cells_vector.resize(start_offset + self->repeater_1.len());
                                }cells_vector.push_back({ [&](const auto &a_0){ slint::cbindgen_private::LayoutItemInfo o{}; o.constraint = a_0; return o; }(self->field_root_14_empty_23_layoutinfo_v.get()) }); slint::cbindgen_private::Slice<slint::cbindgen_private::LayoutItemInfo>cells = slint::private_api::make_slice(std::span(cells_vector)); return slint::private_api::box_layout_info_ortho(cells,[&](const auto &a_0, const auto &a_1){ slint::cbindgen_private::Padding o{}; o.begin = a_0; o.end = a_1; return o; }(0, 0)); }();
}

auto DetailsView_root_14::fn_layoutinfo_v_with_constraint ([[maybe_unused]] float arg_0) const -> slint::cbindgen_private::LayoutInfo{
    [[maybe_unused]] auto self = this;
    return ([&](const auto &a_0, const auto &a_1, const auto &a_2, const auto &a_3, const auto &a_4, const auto &a_5){ slint::cbindgen_private::LayoutInfo o{}; o.max = a_0; o.max_percent = a_1; o.min = a_2; o.min_percent = a_3; o.preferred = a_4; o.stretch = a_5; return o; }(+3.4028234663852886e38, 100, 0, 0, 0, 1) + [&](const auto &a_0, const auto &a_1, const auto &a_2, const auto &a_3, const auto &a_4, const auto &a_5){ slint::cbindgen_private::LayoutInfo o{}; o.max = a_0; o.max_percent = a_1; o.min = a_2; o.min_percent = a_3; o.preferred = a_4; o.stretch = a_5; return o; }(self->field_root_14_flickable_15_max_height.get(), 100, self->field_root_14_flickable_15_min_height.get(), 0, self->field_root_14_flickable_15_preferred_height.get(), self->field_root_14_flickable_15_vertical_stretch.get()));
}

auto DetailsView_root_14::init (const class SharedGlobals* globals,slint::cbindgen_private::ItemTreeWeak enclosing_component,uint32_t tree_index,uint32_t tree_index_of_first_child) -> void{
    auto self = this;
    self->self_weak = enclosing_component;
    self->globals = globals;
    this->tree_index_of_first_child = tree_index_of_first_child;
    self->tree_index = tree_index;
    self->field_root_14.background.set(slint::Brush(slint::Color::from_argb_encoded(+4.280163886e9)));
    self->field_root_14_empty_17_layout_cache.set_binding([this]() {
                            [[maybe_unused]] auto self = this;
                            return slint::private_api::solve_box_layout([&](const auto &a_0, const auto &a_1, const auto &a_2, const auto &a_3, const auto &a_4){ slint::cbindgen_private::BoxLayoutData o{}; o.alignment = a_0; o.cells = a_1; o.padding = a_2; o.size = a_3; o.spacing = a_4; return o; }(slint::cbindgen_private::LayoutAlignment::Stretch, slint::private_api::make_slice<slint::cbindgen_private::LayoutItemInfo>(std::array<slint::cbindgen_private::LayoutItemInfo, 4>{ slint::cbindgen_private::LayoutItemInfo ( [&](const auto &a_0){ slint::cbindgen_private::LayoutItemInfo o{}; o.constraint = a_0; return o; }(self->field_root_14_empty_18_layoutinfo_v.get()) ), slint::cbindgen_private::LayoutItemInfo ( [&](const auto &a_0){ slint::cbindgen_private::LayoutItemInfo o{}; o.constraint = a_0; return o; }([&]{ [[maybe_unused]] auto layout_info = slint::private_api::item_layout_info(SLINT_GET_ITEM_VTABLE(RectangleVTable), const_cast<slint::cbindgen_private::Rectangle*>(&self->field_rectangle_30), slint::cbindgen_private::Orientation::Vertical, -1, &self->globals->window().window_handle(), self->self_weak.lock()->into_dyn(), self->tree_index_of_first_child + 5 - 1);;return [&](const auto &a_0, const auto &a_1, const auto &a_2, const auto &a_3, const auto &a_4, const auto &a_5){ slint::cbindgen_private::LayoutInfo o{}; o.max = a_0; o.max_percent = a_1; o.min = a_2; o.min_percent = a_3; o.preferred = a_4; o.stretch = a_5; return o; }(1, layout_info.max_percent, 1, layout_info.min_percent, layout_info.preferred, layout_info.stretch); }()) ), slint::cbindgen_private::LayoutItemInfo ( [&](const auto &a_0){ slint::cbindgen_private::LayoutItemInfo o{}; o.constraint = a_0; return o; }(slint::private_api::item_layout_info(SLINT_GET_ITEM_VTABLE(ComplexTextVTable), const_cast<slint::cbindgen_private::ComplexText*>(&self->field_text_31), slint::cbindgen_private::Orientation::Vertical, -1, &self->globals->window().window_handle(), self->self_weak.lock()->into_dyn(), self->tree_index_of_first_child + 6 - 1)) ), slint::cbindgen_private::LayoutItemInfo ( [&](const auto &a_0){ slint::cbindgen_private::LayoutItemInfo o{}; o.constraint = a_0; return o; }(([&](const auto &a_0, const auto &a_1, const auto &a_2, const auto &a_3, const auto &a_4, const auto &a_5){ slint::cbindgen_private::LayoutInfo o{}; o.max = a_0; o.max_percent = a_1; o.min = a_2; o.min_percent = a_3; o.preferred = a_4; o.stretch = a_5; return o; }(+3.4028234663852886e38, 100, 0, 0, 0, 1) + self->field_root_14_empty_33_layoutinfo_v.get())) ) }.data(), 4), [&](const auto &a_0, const auto &a_1){ slint::cbindgen_private::Padding o{}; o.begin = a_0; o.end = a_1; return o; }(80, 60), self->field_flickable_15.viewport_height.get(), 28),slint::private_api::make_slice<int>(std::array<int, 0>{  }.data(), 0));
                        });
    self->field_root_14_empty_17_layoutinfo_h.set_binding([this]() {
                            [[maybe_unused]] auto self = this;
                            return slint::private_api::box_layout_info_ortho(slint::private_api::make_slice<slint::cbindgen_private::LayoutItemInfo>(std::array<slint::cbindgen_private::LayoutItemInfo, 4>{ slint::cbindgen_private::LayoutItemInfo ( [&](const auto &a_0){ slint::cbindgen_private::LayoutItemInfo o{}; o.constraint = a_0; return o; }(self->field_root_14_empty_18_layoutinfo_h.get()) ), slint::cbindgen_private::LayoutItemInfo ( [&](const auto &a_0){ slint::cbindgen_private::LayoutItemInfo o{}; o.constraint = a_0; return o; }(slint::private_api::item_layout_info(SLINT_GET_ITEM_VTABLE(RectangleVTable), const_cast<slint::cbindgen_private::Rectangle*>(&self->field_rectangle_30), slint::cbindgen_private::Orientation::Horizontal, -1, &self->globals->window().window_handle(), self->self_weak.lock()->into_dyn(), self->tree_index_of_first_child + 5 - 1)) ), slint::cbindgen_private::LayoutItemInfo ( [&](const auto &a_0){ slint::cbindgen_private::LayoutItemInfo o{}; o.constraint = a_0; return o; }(slint::private_api::item_layout_info(SLINT_GET_ITEM_VTABLE(ComplexTextVTable), const_cast<slint::cbindgen_private::ComplexText*>(&self->field_text_31), slint::cbindgen_private::Orientation::Horizontal, -1, &self->globals->window().window_handle(), self->self_weak.lock()->into_dyn(), self->tree_index_of_first_child + 6 - 1)) ), slint::cbindgen_private::LayoutItemInfo ( [&](const auto &a_0){ slint::cbindgen_private::LayoutItemInfo o{}; o.constraint = a_0; return o; }(([&](const auto &a_0, const auto &a_1, const auto &a_2, const auto &a_3, const auto &a_4, const auto &a_5){ slint::cbindgen_private::LayoutInfo o{}; o.max = a_0; o.max_percent = a_1; o.min = a_2; o.min_percent = a_3; o.preferred = a_4; o.stretch = a_5; return o; }(+3.4028234663852886e38, 100, 0, 0, 0, 1) + self->field_root_14_empty_33_layoutinfo_h.get())) ) }.data(), 4),[&](const auto &a_0, const auto &a_1){ slint::cbindgen_private::Padding o{}; o.begin = a_0; o.end = a_1; return o; }(60, 60));
                        });
    self->field_root_14_empty_17_layoutinfo_v.set_binding([this]() {
                            [[maybe_unused]] auto self = this;
                            return slint::private_api::box_layout_info(slint::private_api::make_slice<slint::cbindgen_private::LayoutItemInfo>(std::array<slint::cbindgen_private::LayoutItemInfo, 4>{ slint::cbindgen_private::LayoutItemInfo ( [&](const auto &a_0){ slint::cbindgen_private::LayoutItemInfo o{}; o.constraint = a_0; return o; }(self->field_root_14_empty_18_layoutinfo_v.get()) ), slint::cbindgen_private::LayoutItemInfo ( [&](const auto &a_0){ slint::cbindgen_private::LayoutItemInfo o{}; o.constraint = a_0; return o; }([&]{ [[maybe_unused]] auto layout_info = slint::private_api::item_layout_info(SLINT_GET_ITEM_VTABLE(RectangleVTable), const_cast<slint::cbindgen_private::Rectangle*>(&self->field_rectangle_30), slint::cbindgen_private::Orientation::Vertical, -1, &self->globals->window().window_handle(), self->self_weak.lock()->into_dyn(), self->tree_index_of_first_child + 5 - 1);;return [&](const auto &a_0, const auto &a_1, const auto &a_2, const auto &a_3, const auto &a_4, const auto &a_5){ slint::cbindgen_private::LayoutInfo o{}; o.max = a_0; o.max_percent = a_1; o.min = a_2; o.min_percent = a_3; o.preferred = a_4; o.stretch = a_5; return o; }(1, layout_info.max_percent, 1, layout_info.min_percent, layout_info.preferred, layout_info.stretch); }()) ), slint::cbindgen_private::LayoutItemInfo ( [&](const auto &a_0){ slint::cbindgen_private::LayoutItemInfo o{}; o.constraint = a_0; return o; }(slint::private_api::item_layout_info(SLINT_GET_ITEM_VTABLE(ComplexTextVTable), const_cast<slint::cbindgen_private::ComplexText*>(&self->field_text_31), slint::cbindgen_private::Orientation::Vertical, -1, &self->globals->window().window_handle(), self->self_weak.lock()->into_dyn(), self->tree_index_of_first_child + 6 - 1)) ), slint::cbindgen_private::LayoutItemInfo ( [&](const auto &a_0){ slint::cbindgen_private::LayoutItemInfo o{}; o.constraint = a_0; return o; }(([&](const auto &a_0, const auto &a_1, const auto &a_2, const auto &a_3, const auto &a_4, const auto &a_5){ slint::cbindgen_private::LayoutInfo o{}; o.max = a_0; o.max_percent = a_1; o.min = a_2; o.min_percent = a_3; o.preferred = a_4; o.stretch = a_5; return o; }(+3.4028234663852886e38, 100, 0, 0, 0, 1) + self->field_root_14_empty_33_layoutinfo_v.get())) ) }.data(), 4),28,[&](const auto &a_0, const auto &a_1){ slint::cbindgen_private::Padding o{}; o.begin = a_0; o.end = a_1; return o; }(80, 60),slint::cbindgen_private::LayoutAlignment::Stretch);
                        });
    self->field_root_14_empty_17_padding_bottom.set(60);
    self->field_root_14_empty_17_padding_top.set(80);
    self->field_root_14_empty_17_spacing.set(28);
    self->field_root_14_empty_18_layout_cache.set_binding([this]() {
                            [[maybe_unused]] auto self = this;
                            return [&]{ std::array<int, 4> repeated_indices_array;  std::vector<slint::cbindgen_private::LayoutItemInfo> cells_vector;self->repeater_0.track_instance_changes();repeated_indices_array[0] = cells_vector.size();repeated_indices_array[1] = self->repeater_0.len();{
                                    auto start_offset = cells_vector.size();
                                    self->repeater_0.for_each([&](const auto &sub_comp){ cells_vector.push_back(sub_comp->layout_item_info(slint::cbindgen_private::Orientation::Horizontal, std::nullopt)); });
                                    cells_vector.resize(start_offset + self->repeater_0.len());
                                }self->repeater_1.track_instance_changes();repeated_indices_array[2] = cells_vector.size();repeated_indices_array[3] = self->repeater_1.len();{
                                    auto start_offset = cells_vector.size();
                                    self->repeater_1.for_each([&](const auto &sub_comp){ cells_vector.push_back(sub_comp->layout_item_info(slint::cbindgen_private::Orientation::Horizontal, std::nullopt)); });
                                    cells_vector.resize(start_offset + self->repeater_1.len());
                                }cells_vector.push_back({ [&](const auto &a_0){ slint::cbindgen_private::LayoutItemInfo o{}; o.constraint = a_0; return o; }(self->field_root_14_empty_23_layoutinfo_h.get()) });slint::cbindgen_private::Slice<int> repeated_indices = slint::private_api::make_slice(std::span(repeated_indices_array)); slint::cbindgen_private::Slice<slint::cbindgen_private::LayoutItemInfo>cells = slint::private_api::make_slice(std::span(cells_vector)); return slint::private_api::solve_box_layout([&](const auto &a_0, const auto &a_1, const auto &a_2, const auto &a_3, const auto &a_4){ slint::cbindgen_private::BoxLayoutData o{}; o.alignment = a_0; o.cells = a_1; o.padding = a_2; o.size = a_3; o.spacing = a_4; return o; }(slint::cbindgen_private::LayoutAlignment::Stretch, cells, [&](const auto &a_0, const auto &a_1){ slint::cbindgen_private::Padding o{}; o.begin = a_0; o.end = a_1; return o; }(0, 0), ((self->field_flickable_15.viewport_width.get() -(float) 60) -(float) 60), 24),repeated_indices); }();
                        });
    self->field_root_14_empty_18_layoutinfo_h.set_binding([this]() {
                            [[maybe_unused]] auto self = this;
                            return [&]{   std::vector<slint::cbindgen_private::LayoutItemInfo> cells_vector;self->repeater_0.track_instance_changes();{
                                    auto start_offset = cells_vector.size();
                                    self->repeater_0.for_each([&](const auto &sub_comp){ cells_vector.push_back(sub_comp->layout_item_info(slint::cbindgen_private::Orientation::Horizontal, std::nullopt)); });
                                    cells_vector.resize(start_offset + self->repeater_0.len());
                                }self->repeater_1.track_instance_changes();{
                                    auto start_offset = cells_vector.size();
                                    self->repeater_1.for_each([&](const auto &sub_comp){ cells_vector.push_back(sub_comp->layout_item_info(slint::cbindgen_private::Orientation::Horizontal, std::nullopt)); });
                                    cells_vector.resize(start_offset + self->repeater_1.len());
                                }cells_vector.push_back({ [&](const auto &a_0){ slint::cbindgen_private::LayoutItemInfo o{}; o.constraint = a_0; return o; }(self->field_root_14_empty_23_layoutinfo_h.get()) }); slint::cbindgen_private::Slice<slint::cbindgen_private::LayoutItemInfo>cells = slint::private_api::make_slice(std::span(cells_vector)); return slint::private_api::box_layout_info(cells,24,[&](const auto &a_0, const auto &a_1){ slint::cbindgen_private::Padding o{}; o.begin = a_0; o.end = a_1; return o; }(0, 0),slint::cbindgen_private::LayoutAlignment::Stretch); }();
                        });
    self->field_root_14_empty_18_layoutinfo_v.set_binding([this]() {
                            [[maybe_unused]] auto self = this;
                            return [&]{   std::vector<slint::cbindgen_private::LayoutItemInfo> cells_vector;self->repeater_0.track_instance_changes();{
                                    auto start_offset = cells_vector.size();
                                    self->repeater_0.for_each([&](const auto &sub_comp){ cells_vector.push_back(sub_comp->layout_item_info(slint::cbindgen_private::Orientation::Vertical, std::nullopt)); });
                                    cells_vector.resize(start_offset + self->repeater_0.len());
                                }self->repeater_1.track_instance_changes();{
                                    auto start_offset = cells_vector.size();
                                    self->repeater_1.for_each([&](const auto &sub_comp){ cells_vector.push_back(sub_comp->layout_item_info(slint::cbindgen_private::Orientation::Vertical, std::nullopt)); });
                                    cells_vector.resize(start_offset + self->repeater_1.len());
                                }cells_vector.push_back({ [&](const auto &a_0){ slint::cbindgen_private::LayoutItemInfo o{}; o.constraint = a_0; return o; }(self->field_root_14_empty_23_layoutinfo_v.get()) }); slint::cbindgen_private::Slice<slint::cbindgen_private::LayoutItemInfo>cells = slint::private_api::make_slice(std::span(cells_vector)); return slint::private_api::box_layout_info_ortho(cells,[&](const auto &a_0, const auto &a_1){ slint::cbindgen_private::Padding o{}; o.begin = a_0; o.end = a_1; return o; }(0, 0)); }();
                        });
    self->field_root_14_empty_23_layout_cache.set_binding([this]() {
                            [[maybe_unused]] auto self = this;
                            return slint::private_api::solve_box_layout([&](const auto &a_0, const auto &a_1, const auto &a_2, const auto &a_3, const auto &a_4){ slint::cbindgen_private::BoxLayoutData o{}; o.alignment = a_0; o.cells = a_1; o.padding = a_2; o.size = a_3; o.spacing = a_4; return o; }(slint::cbindgen_private::LayoutAlignment::Center, slint::private_api::make_slice<slint::cbindgen_private::LayoutItemInfo>(std::array<slint::cbindgen_private::LayoutItemInfo, 3>{ slint::cbindgen_private::LayoutItemInfo ( [&](const auto &a_0){ slint::cbindgen_private::LayoutItemInfo o{}; o.constraint = a_0; return o; }(slint::private_api::item_layout_info(SLINT_GET_ITEM_VTABLE(ComplexTextVTable), const_cast<slint::cbindgen_private::ComplexText*>(&self->field_text_24), slint::cbindgen_private::Orientation::Vertical, -1, &self->globals->window().window_handle(), self->self_weak.lock()->into_dyn(), self->tree_index_of_first_child + 11 - 1)) ), slint::cbindgen_private::LayoutItemInfo ( [&](const auto &a_0){ slint::cbindgen_private::LayoutItemInfo o{}; o.constraint = a_0; return o; }(slint::private_api::item_layout_info(SLINT_GET_ITEM_VTABLE(SimpleTextVTable), const_cast<slint::cbindgen_private::SimpleText*>(&self->field_text_25), slint::cbindgen_private::Orientation::Vertical, -1, &self->globals->window().window_handle(), self->self_weak.lock()->into_dyn(), self->tree_index_of_first_child + 12 - 1)) ), slint::cbindgen_private::LayoutItemInfo ( [&](const auto &a_0){ slint::cbindgen_private::LayoutItemInfo o{}; o.constraint = a_0; return o; }(self->field_root_14_empty_26_layoutinfo_v.get()) ) }.data(), 3), [&](const auto &a_0, const auto &a_1){ slint::cbindgen_private::Padding o{}; o.begin = a_0; o.end = a_1; return o; }(0, 0), self->field_root_14_empty_17_layout_cache.get()[1], 6),slint::private_api::make_slice<int>(std::array<int, 0>{  }.data(), 0));
                        });
    self->field_root_14_empty_23_layoutinfo_h.set_binding([this]() {
                            [[maybe_unused]] auto self = this;
                            return slint::private_api::box_layout_info_ortho(slint::private_api::make_slice<slint::cbindgen_private::LayoutItemInfo>(std::array<slint::cbindgen_private::LayoutItemInfo, 3>{ slint::cbindgen_private::LayoutItemInfo ( [&](const auto &a_0){ slint::cbindgen_private::LayoutItemInfo o{}; o.constraint = a_0; return o; }(slint::private_api::item_layout_info(SLINT_GET_ITEM_VTABLE(ComplexTextVTable), const_cast<slint::cbindgen_private::ComplexText*>(&self->field_text_24), slint::cbindgen_private::Orientation::Horizontal, -1, &self->globals->window().window_handle(), self->self_weak.lock()->into_dyn(), self->tree_index_of_first_child + 11 - 1)) ), slint::cbindgen_private::LayoutItemInfo ( [&](const auto &a_0){ slint::cbindgen_private::LayoutItemInfo o{}; o.constraint = a_0; return o; }(slint::private_api::item_layout_info(SLINT_GET_ITEM_VTABLE(SimpleTextVTable), const_cast<slint::cbindgen_private::SimpleText*>(&self->field_text_25), slint::cbindgen_private::Orientation::Horizontal, -1, &self->globals->window().window_handle(), self->self_weak.lock()->into_dyn(), self->tree_index_of_first_child + 12 - 1)) ), slint::cbindgen_private::LayoutItemInfo ( [&](const auto &a_0){ slint::cbindgen_private::LayoutItemInfo o{}; o.constraint = a_0; return o; }(self->field_root_14_empty_26_layoutinfo_h.get()) ) }.data(), 3),[&](const auto &a_0, const auto &a_1){ slint::cbindgen_private::Padding o{}; o.begin = a_0; o.end = a_1; return o; }(0, 0));
                        });
    self->field_root_14_empty_23_layoutinfo_v.set_binding([this]() {
                            [[maybe_unused]] auto self = this;
                            return slint::private_api::box_layout_info(slint::private_api::make_slice<slint::cbindgen_private::LayoutItemInfo>(std::array<slint::cbindgen_private::LayoutItemInfo, 3>{ slint::cbindgen_private::LayoutItemInfo ( [&](const auto &a_0){ slint::cbindgen_private::LayoutItemInfo o{}; o.constraint = a_0; return o; }(slint::private_api::item_layout_info(SLINT_GET_ITEM_VTABLE(ComplexTextVTable), const_cast<slint::cbindgen_private::ComplexText*>(&self->field_text_24), slint::cbindgen_private::Orientation::Vertical, -1, &self->globals->window().window_handle(), self->self_weak.lock()->into_dyn(), self->tree_index_of_first_child + 11 - 1)) ), slint::cbindgen_private::LayoutItemInfo ( [&](const auto &a_0){ slint::cbindgen_private::LayoutItemInfo o{}; o.constraint = a_0; return o; }(slint::private_api::item_layout_info(SLINT_GET_ITEM_VTABLE(SimpleTextVTable), const_cast<slint::cbindgen_private::SimpleText*>(&self->field_text_25), slint::cbindgen_private::Orientation::Vertical, -1, &self->globals->window().window_handle(), self->self_weak.lock()->into_dyn(), self->tree_index_of_first_child + 12 - 1)) ), slint::cbindgen_private::LayoutItemInfo ( [&](const auto &a_0){ slint::cbindgen_private::LayoutItemInfo o{}; o.constraint = a_0; return o; }(self->field_root_14_empty_26_layoutinfo_v.get()) ) }.data(), 3),6,[&](const auto &a_0, const auto &a_1){ slint::cbindgen_private::Padding o{}; o.begin = a_0; o.end = a_1; return o; }(0, 0),slint::cbindgen_private::LayoutAlignment::Center);
                        });
    self->field_root_14_empty_23_width.set_binding([this]() {
                            [[maybe_unused]] auto self = this;
                            return self->field_root_14_empty_18_layout_cache.get()[5];
                        });
    self->field_root_14_empty_26_layout_cache.set_binding([this]() {
                            [[maybe_unused]] auto self = this;
                            return slint::private_api::solve_box_layout([&](const auto &a_0, const auto &a_1, const auto &a_2, const auto &a_3, const auto &a_4){ slint::cbindgen_private::BoxLayoutData o{}; o.alignment = a_0; o.cells = a_1; o.padding = a_2; o.size = a_3; o.spacing = a_4; return o; }(slint::cbindgen_private::LayoutAlignment::Start, slint::private_api::make_slice<slint::cbindgen_private::LayoutItemInfo>(std::array<slint::cbindgen_private::LayoutItemInfo, 1>{ slint::cbindgen_private::LayoutItemInfo ( [&](const auto &a_0){ slint::cbindgen_private::LayoutItemInfo o{}; o.constraint = a_0; return o; }([&]{ [[maybe_unused]] auto layout_info = self->field_root_14_rectangle_27_layoutinfo_h.get();;return [&](const auto &a_0, const auto &a_1, const auto &a_2, const auto &a_3, const auto &a_4, const auto &a_5){ slint::cbindgen_private::LayoutInfo o{}; o.max = a_0; o.max_percent = a_1; o.min = a_2; o.min_percent = a_3; o.preferred = a_4; o.stretch = a_5; return o; }(130, layout_info.max_percent, 130, layout_info.min_percent, layout_info.preferred, layout_info.stretch); }()) ) }.data(), 1), [&](const auto &a_0, const auto &a_1){ slint::cbindgen_private::Padding o{}; o.begin = a_0; o.end = a_1; return o; }(0, 0), self->field_root_14_empty_23_width.get(), 0),slint::private_api::make_slice<int>(std::array<int, 0>{  }.data(), 0));
                        });
    self->field_root_14_empty_26_layoutinfo_h.set_binding([this]() {
                            [[maybe_unused]] auto self = this;
                            return slint::private_api::box_layout_info(slint::private_api::make_slice<slint::cbindgen_private::LayoutItemInfo>(std::array<slint::cbindgen_private::LayoutItemInfo, 1>{ slint::cbindgen_private::LayoutItemInfo ( [&](const auto &a_0){ slint::cbindgen_private::LayoutItemInfo o{}; o.constraint = a_0; return o; }([&]{ [[maybe_unused]] auto layout_info = self->field_root_14_rectangle_27_layoutinfo_h.get();;return [&](const auto &a_0, const auto &a_1, const auto &a_2, const auto &a_3, const auto &a_4, const auto &a_5){ slint::cbindgen_private::LayoutInfo o{}; o.max = a_0; o.max_percent = a_1; o.min = a_2; o.min_percent = a_3; o.preferred = a_4; o.stretch = a_5; return o; }(130, layout_info.max_percent, 130, layout_info.min_percent, layout_info.preferred, layout_info.stretch); }()) ) }.data(), 1),0,[&](const auto &a_0, const auto &a_1){ slint::cbindgen_private::Padding o{}; o.begin = a_0; o.end = a_1; return o; }(0, 0),slint::cbindgen_private::LayoutAlignment::Start);
                        });
    self->field_root_14_empty_26_layoutinfo_v.set_binding([this]() {
                            [[maybe_unused]] auto self = this;
                            return slint::private_api::box_layout_info_ortho(slint::private_api::make_slice<slint::cbindgen_private::LayoutItemInfo>(std::array<slint::cbindgen_private::LayoutItemInfo, 1>{ slint::cbindgen_private::LayoutItemInfo ( [&](const auto &a_0){ slint::cbindgen_private::LayoutItemInfo o{}; o.constraint = a_0; return o; }([&]{ [[maybe_unused]] auto layout_info = self->field_root_14_rectangle_27_layoutinfo_v.get();;return [&](const auto &a_0, const auto &a_1, const auto &a_2, const auto &a_3, const auto &a_4, const auto &a_5){ slint::cbindgen_private::LayoutInfo o{}; o.max = a_0; o.max_percent = a_1; o.min = a_2; o.min_percent = a_3; o.preferred = a_4; o.stretch = a_5; return o; }(38, layout_info.max_percent, 38, layout_info.min_percent, layout_info.preferred, layout_info.stretch); }()) ) }.data(), 1),[&](const auto &a_0, const auto &a_1){ slint::cbindgen_private::Padding o{}; o.begin = a_0; o.end = a_1; return o; }(10, 0));
                        });
    self->field_root_14_empty_33_layout_cache.set_binding([this]() {
                            [[maybe_unused]] auto self = this;
                            return [&]{ std::array<int, 4> repeated_indices_array;  std::vector<slint::cbindgen_private::LayoutItemInfo> cells_vector;self->repeater_2.track_instance_changes();repeated_indices_array[0] = cells_vector.size();repeated_indices_array[1] = self->repeater_2.len();{
                                    auto start_offset = cells_vector.size();
                                    self->repeater_2.for_each([&](const auto &sub_comp){ cells_vector.push_back(sub_comp->layout_item_info(slint::cbindgen_private::Orientation::Vertical, std::nullopt)); });
                                    cells_vector.resize(start_offset + self->repeater_2.len());
                                }self->repeater_3.track_instance_changes();repeated_indices_array[2] = cells_vector.size();repeated_indices_array[3] = self->repeater_3.len();{
                                    auto start_offset = cells_vector.size();
                                    self->repeater_3.for_each([&](const auto &sub_comp){ cells_vector.push_back(sub_comp->layout_item_info(slint::cbindgen_private::Orientation::Vertical, std::nullopt)); });
                                    cells_vector.resize(start_offset + self->repeater_3.len());
                                }slint::cbindgen_private::Slice<int> repeated_indices = slint::private_api::make_slice(std::span(repeated_indices_array)); slint::cbindgen_private::Slice<slint::cbindgen_private::LayoutItemInfo>cells = slint::private_api::make_slice(std::span(cells_vector)); return slint::private_api::solve_box_layout([&](const auto &a_0, const auto &a_1, const auto &a_2, const auto &a_3, const auto &a_4){ slint::cbindgen_private::BoxLayoutData o{}; o.alignment = a_0; o.cells = a_1; o.padding = a_2; o.size = a_3; o.spacing = a_4; return o; }(slint::cbindgen_private::LayoutAlignment::Stretch, cells, [&](const auto &a_0, const auto &a_1){ slint::cbindgen_private::Padding o{}; o.begin = a_0; o.end = a_1; return o; }(24, 24), self->field_root_14_empty_17_layout_cache.get()[7], 12),repeated_indices); }();
                        });
    self->field_root_14_empty_33_layoutinfo_h.set_binding([this]() {
                            [[maybe_unused]] auto self = this;
                            return [&]{   std::vector<slint::cbindgen_private::LayoutItemInfo> cells_vector;self->repeater_2.track_instance_changes();{
                                    auto start_offset = cells_vector.size();
                                    self->repeater_2.for_each([&](const auto &sub_comp){ cells_vector.push_back(sub_comp->layout_item_info(slint::cbindgen_private::Orientation::Horizontal, std::nullopt)); });
                                    cells_vector.resize(start_offset + self->repeater_2.len());
                                }self->repeater_3.track_instance_changes();{
                                    auto start_offset = cells_vector.size();
                                    self->repeater_3.for_each([&](const auto &sub_comp){ cells_vector.push_back(sub_comp->layout_item_info(slint::cbindgen_private::Orientation::Horizontal, std::nullopt)); });
                                    cells_vector.resize(start_offset + self->repeater_3.len());
                                } slint::cbindgen_private::Slice<slint::cbindgen_private::LayoutItemInfo>cells = slint::private_api::make_slice(std::span(cells_vector)); return slint::private_api::box_layout_info_ortho(cells,[&](const auto &a_0, const auto &a_1){ slint::cbindgen_private::Padding o{}; o.begin = a_0; o.end = a_1; return o; }(24, 24)); }();
                        });
    self->field_root_14_empty_33_layoutinfo_v.set_binding([this]() {
                            [[maybe_unused]] auto self = this;
                            return [&]{   std::vector<slint::cbindgen_private::LayoutItemInfo> cells_vector;self->repeater_2.track_instance_changes();{
                                    auto start_offset = cells_vector.size();
                                    self->repeater_2.for_each([&](const auto &sub_comp){ cells_vector.push_back(sub_comp->layout_item_info(slint::cbindgen_private::Orientation::Vertical, std::nullopt)); });
                                    cells_vector.resize(start_offset + self->repeater_2.len());
                                }self->repeater_3.track_instance_changes();{
                                    auto start_offset = cells_vector.size();
                                    self->repeater_3.for_each([&](const auto &sub_comp){ cells_vector.push_back(sub_comp->layout_item_info(slint::cbindgen_private::Orientation::Vertical, std::nullopt)); });
                                    cells_vector.resize(start_offset + self->repeater_3.len());
                                } slint::cbindgen_private::Slice<slint::cbindgen_private::LayoutItemInfo>cells = slint::private_api::make_slice(std::span(cells_vector)); return slint::private_api::box_layout_info(cells,12,[&](const auto &a_0, const auto &a_1){ slint::cbindgen_private::Padding o{}; o.begin = a_0; o.end = a_1; return o; }(24, 24),slint::cbindgen_private::LayoutAlignment::Stretch); }();
                        });
    self->field_root_14_flickable_15_horizontal_stretch.set_binding([this]() {
                            [[maybe_unused]] auto self = this;
                            return slint::private_api::item_layout_info(SLINT_GET_ITEM_VTABLE(FlickableVTable), const_cast<slint::cbindgen_private::Flickable*>(&self->field_flickable_15), slint::cbindgen_private::Orientation::Horizontal, -1, &self->globals->window().window_handle(), self->self_weak.lock()->into_dyn(), self->tree_index_of_first_child + 1 - 1).stretch;
                        });
    self->field_root_14_flickable_15_max_height.set_binding([this]() {
                            [[maybe_unused]] auto self = this;
                            return self->field_root_14_empty_17_layoutinfo_v.get().max;
                        });
    self->field_root_14_flickable_15_min_height.set_binding([this]() {
                            [[maybe_unused]] auto self = this;
                            return slint::private_api::item_layout_info(SLINT_GET_ITEM_VTABLE(FlickableVTable), const_cast<slint::cbindgen_private::Flickable*>(&self->field_flickable_15), slint::cbindgen_private::Orientation::Vertical, -1, &self->globals->window().window_handle(), self->self_weak.lock()->into_dyn(), self->tree_index_of_first_child + 1 - 1).min;
                        });
    self->field_root_14_flickable_15_min_width.set_binding([this]() {
                            [[maybe_unused]] auto self = this;
                            return slint::private_api::item_layout_info(SLINT_GET_ITEM_VTABLE(FlickableVTable), const_cast<slint::cbindgen_private::Flickable*>(&self->field_flickable_15), slint::cbindgen_private::Orientation::Horizontal, -1, &self->globals->window().window_handle(), self->self_weak.lock()->into_dyn(), self->tree_index_of_first_child + 1 - 1).min;
                        });
    self->field_root_14_flickable_15_preferred_height.set_binding([this]() {
                            [[maybe_unused]] auto self = this;
                            return self->field_root_14_empty_17_layoutinfo_v.get().preferred;
                        });
    self->field_root_14_flickable_15_vertical_stretch.set_binding([this]() {
                            [[maybe_unused]] auto self = this;
                            return slint::private_api::item_layout_info(SLINT_GET_ITEM_VTABLE(FlickableVTable), const_cast<slint::cbindgen_private::Flickable*>(&self->field_flickable_15), slint::cbindgen_private::Orientation::Vertical, -1, &self->globals->window().window_handle(), self->self_weak.lock()->into_dyn(), self->tree_index_of_first_child + 1 - 1).stretch;
                        });
    self->field_root_14_layoutinfo_h.set_binding([this]() {
                            [[maybe_unused]] auto self = this;
                            return ([&](const auto &a_0, const auto &a_1, const auto &a_2, const auto &a_3, const auto &a_4, const auto &a_5){ slint::cbindgen_private::LayoutInfo o{}; o.max = a_0; o.max_percent = a_1; o.min = a_2; o.min_percent = a_3; o.preferred = a_4; o.stretch = a_5; return o; }(+3.4028234663852886e38, 100, 0, 0, 0, 1) + [&](const auto &a_0, const auto &a_1, const auto &a_2, const auto &a_3, const auto &a_4, const auto &a_5){ slint::cbindgen_private::LayoutInfo o{}; o.max = a_0; o.max_percent = a_1; o.min = a_2; o.min_percent = a_3; o.preferred = a_4; o.stretch = a_5; return o; }(self->field_root_14_empty_17_layoutinfo_h.get().max, 100, self->field_root_14_flickable_15_min_width.get(), 0, self->field_root_14_empty_17_layoutinfo_h.get().preferred, self->field_root_14_flickable_15_horizontal_stretch.get()));
                        });
    self->field_root_14_layoutinfo_v.set_binding([this]() {
                            [[maybe_unused]] auto self = this;
                            return ([&](const auto &a_0, const auto &a_1, const auto &a_2, const auto &a_3, const auto &a_4, const auto &a_5){ slint::cbindgen_private::LayoutInfo o{}; o.max = a_0; o.max_percent = a_1; o.min = a_2; o.min_percent = a_3; o.preferred = a_4; o.stretch = a_5; return o; }(+3.4028234663852886e38, 100, 0, 0, 0, 1) + [&](const auto &a_0, const auto &a_1, const auto &a_2, const auto &a_3, const auto &a_4, const auto &a_5){ slint::cbindgen_private::LayoutInfo o{}; o.max = a_0; o.max_percent = a_1; o.min = a_2; o.min_percent = a_3; o.preferred = a_4; o.stretch = a_5; return o; }(self->field_root_14_empty_17_layoutinfo_v.get().max, 100, self->field_root_14_flickable_15_min_height.get(), 0, self->field_root_14_empty_17_layoutinfo_v.get().preferred, self->field_root_14_flickable_15_vertical_stretch.get()));
                        });
    self->field_root_14_rectangle_27_layoutinfo_h.set_binding([this]() {
                            [[maybe_unused]] auto self = this;
                            return ([&](const auto &a_0, const auto &a_1, const auto &a_2, const auto &a_3, const auto &a_4, const auto &a_5){ slint::cbindgen_private::LayoutInfo o{}; o.max = a_0; o.max_percent = a_1; o.min = a_2; o.min_percent = a_3; o.preferred = a_4; o.stretch = a_5; return o; }(+3.4028234663852886e38, 100, 0, 0, 0, 1) + slint::private_api::item_layout_info(SLINT_GET_ITEM_VTABLE(SimpleTextVTable), const_cast<slint::cbindgen_private::SimpleText*>(&self->field_text_29), slint::cbindgen_private::Orientation::Horizontal, -1, &self->globals->window().window_handle(), self->self_weak.lock()->into_dyn(), self->tree_index_of_first_child + 16 - 1));
                        });
    self->field_root_14_rectangle_27_layoutinfo_v.set_binding([this]() {
                            [[maybe_unused]] auto self = this;
                            return ([&](const auto &a_0, const auto &a_1, const auto &a_2, const auto &a_3, const auto &a_4, const auto &a_5){ slint::cbindgen_private::LayoutInfo o{}; o.max = a_0; o.max_percent = a_1; o.min = a_2; o.min_percent = a_3; o.preferred = a_4; o.stretch = a_5; return o; }(+3.4028234663852886e38, 100, 0, 0, 0, 1) + slint::private_api::item_layout_info(SLINT_GET_ITEM_VTABLE(SimpleTextVTable), const_cast<slint::cbindgen_private::SimpleText*>(&self->field_text_29), slint::cbindgen_private::Orientation::Vertical, -1, &self->globals->window().window_handle(), self->self_weak.lock()->into_dyn(), self->tree_index_of_first_child + 16 - 1));
                        });
    self->field_root_14_rectangle_30_height.set(1);
    self->field_root_14_rectangle_32_layoutinfo_v.set_binding([this]() {
                            [[maybe_unused]] auto self = this;
                            return ([&](const auto &a_0, const auto &a_1, const auto &a_2, const auto &a_3, const auto &a_4, const auto &a_5){ slint::cbindgen_private::LayoutInfo o{}; o.max = a_0; o.max_percent = a_1; o.min = a_2; o.min_percent = a_3; o.preferred = a_4; o.stretch = a_5; return o; }(+3.4028234663852886e38, 100, 0, 0, 0, 1) + self->field_root_14_empty_33_layoutinfo_v.get());
                        });
    self->field_root_14_text_29_min_height.set_binding([this]() {
                            [[maybe_unused]] auto self = this;
                            return slint::private_api::item_layout_info(SLINT_GET_ITEM_VTABLE(SimpleTextVTable), const_cast<slint::cbindgen_private::SimpleText*>(&self->field_text_29), slint::cbindgen_private::Orientation::Vertical, -1, &self->globals->window().window_handle(), self->self_weak.lock()->into_dyn(), self->tree_index_of_first_child + 16 - 1).min;
                        });
    self->field_root_14_text_29_min_width.set_binding([this]() {
                            [[maybe_unused]] auto self = this;
                            return slint::private_api::item_layout_info(SLINT_GET_ITEM_VTABLE(SimpleTextVTable), const_cast<slint::cbindgen_private::SimpleText*>(&self->field_text_29), slint::cbindgen_private::Orientation::Horizontal, -1, &self->globals->window().window_handle(), self->self_weak.lock()->into_dyn(), self->tree_index_of_first_child + 16 - 1).min;
                        });
    self->field_root_14_text_29_preferred_height.set_binding([this]() {
                            [[maybe_unused]] auto self = this;
                            return slint::private_api::item_layout_info(SLINT_GET_ITEM_VTABLE(SimpleTextVTable), const_cast<slint::cbindgen_private::SimpleText*>(&self->field_text_29), slint::cbindgen_private::Orientation::Vertical, -1, &self->globals->window().window_handle(), self->self_weak.lock()->into_dyn(), self->tree_index_of_first_child + 16 - 1).preferred;
                        });
    self->field_root_14_text_29_preferred_width.set_binding([this]() {
                            [[maybe_unused]] auto self = this;
                            return slint::private_api::item_layout_info(SLINT_GET_ITEM_VTABLE(SimpleTextVTable), const_cast<slint::cbindgen_private::SimpleText*>(&self->field_text_29), slint::cbindgen_private::Orientation::Horizontal, -1, &self->globals->window().window_handle(), self->self_weak.lock()->into_dyn(), self->tree_index_of_first_child + 16 - 1).preferred;
                        });
    self->field_root_14_text_56_min_height.set_binding([this]() {
                            [[maybe_unused]] auto self = this;
                            return slint::private_api::item_layout_info(SLINT_GET_ITEM_VTABLE(SimpleTextVTable), const_cast<slint::cbindgen_private::SimpleText*>(&self->field_text_56), slint::cbindgen_private::Orientation::Vertical, -1, &self->globals->window().window_handle(), self->self_weak.lock()->into_dyn(), self->tree_index_of_first_child + 20 - 1).min;
                        });
    self->field_root_14_text_56_min_width.set_binding([this]() {
                            [[maybe_unused]] auto self = this;
                            return slint::private_api::item_layout_info(SLINT_GET_ITEM_VTABLE(SimpleTextVTable), const_cast<slint::cbindgen_private::SimpleText*>(&self->field_text_56), slint::cbindgen_private::Orientation::Horizontal, -1, &self->globals->window().window_handle(), self->self_weak.lock()->into_dyn(), self->tree_index_of_first_child + 20 - 1).min;
                        });
    self->field_root_14_text_56_preferred_height.set_binding([this]() {
                            [[maybe_unused]] auto self = this;
                            return slint::private_api::item_layout_info(SLINT_GET_ITEM_VTABLE(SimpleTextVTable), const_cast<slint::cbindgen_private::SimpleText*>(&self->field_text_56), slint::cbindgen_private::Orientation::Vertical, -1, &self->globals->window().window_handle(), self->self_weak.lock()->into_dyn(), self->tree_index_of_first_child + 20 - 1).preferred;
                        });
    self->field_root_14_text_56_preferred_width.set_binding([this]() {
                            [[maybe_unused]] auto self = this;
                            return slint::private_api::item_layout_info(SLINT_GET_ITEM_VTABLE(SimpleTextVTable), const_cast<slint::cbindgen_private::SimpleText*>(&self->field_text_56), slint::cbindgen_private::Orientation::Horizontal, -1, &self->globals->window().window_handle(), self->self_weak.lock()->into_dyn(), self->tree_index_of_first_child + 20 - 1).preferred;
                        });
    self->field_flickable_15.interactive.set(true);
    self->field_flickable_15.viewport_height.set_binding([this]() {
                            [[maybe_unused]] auto self = this;
                            return std::max<float>(self->field_root_14_height.get(), self->field_root_14_empty_17_layoutinfo_v.get().min);
                        });
    self->field_flickable_15.viewport_width.set_binding([this]() {
                            [[maybe_unused]] auto self = this;
                            return std::max<float>(self->field_root_14_width.get(), self->field_root_14_empty_17_layoutinfo_h.get().min);
                        });
    self->field_text_24.color.set(slint::Brush(slint::Color::from_argb_encoded(+4.291679988e9)));
    self->field_text_24.font_size.set(32);
    self->field_text_24.font_weight.set(static_cast<int>(400));
    self->field_text_24.height.set_binding([this]() {
                            [[maybe_unused]] auto self = this;
                            return self->field_root_14_empty_23_layout_cache.get()[1];
                        });
    self->field_text_24.letter_spacing.set(-0.5);
    self->field_text_24.text.set_binding([this]() {
                            [[maybe_unused]] auto self = this;
                            return self->field_root_14_pkg.get().pretty_name;
                        });
    self->field_text_24.width.set_binding([this]() {
                            [[maybe_unused]] auto self = this;
                            return self->field_root_14_empty_18_layout_cache.get()[5];
                        });
    self->field_text_25.color.set(slint::Brush(slint::Color::from_argb_encoded(+4.289113544e9)));
    self->field_text_25.font_size.set(15);
    self->field_text_25.font_weight.set(static_cast<int>(600));
    self->field_text_25.height.set_binding([this]() {
                            [[maybe_unused]] auto self = this;
                            return self->field_root_14_empty_23_layout_cache.get()[3];
                        });
    self->field_text_25.text.set_binding([this]() {
                            [[maybe_unused]] auto self = this;
                            return [&]{ [[maybe_unused]] auto tmp_root_14_pkg = self->field_root_14_pkg.get();;return ((tmp_root_14_pkg.repo + slint::SharedString(u8" \U00002022 ")) + tmp_root_14_pkg.version); }();
                        });
    self->field_text_25.width.set_binding([this]() {
                            [[maybe_unused]] auto self = this;
                            return self->field_root_14_empty_18_layout_cache.get()[5];
                        });
    self->field_rectangle_27.background.set_binding([this]() {
                            [[maybe_unused]] auto self = this;
                            return slint::Brush((self->field_root_14_pkg.get().installed ? slint::Color::from_argb_encoded(+4.29415108e9) : [&]{ [[maybe_unused]] auto tmp_Theme_76_accents = self->globals->global_Theme_76->field_accents.get();;return slint::private_api::access_array_index(tmp_Theme_76_accents, ([](float a, float b) { auto r = std::fmod(a, b); return r >= 0 ? r : r + std::abs(b); })(self->field_root_14_accent_idx.get(),slint::private_api::model_length(tmp_Theme_76_accents))); }()));
                        });
    self->field_rectangle_27.border_radius.set(8);
    self->field_toucharea_28.clicked.set_handler(
                [this]() {
                    [[maybe_unused]] auto self = this;
                    if (self->field_root_14_pkg.get().installed) { self->field_root_14_remove_clicked.call(); } else { self->field_root_14_install_clicked.call(); };
                });
    self->field_toucharea_28.enabled.set(true);
    self->field_text_29.color.set(slint::Brush(slint::Color::from_argb_encoded(+4.279308571e9)));
    self->field_text_29.font_size.set(14);
    self->field_text_29.font_weight.set(static_cast<int>(700));
    self->field_text_29.height.set_binding([this]() {
                            [[maybe_unused]] auto self = this;
                            return std::max<float>(self->field_root_14_text_29_preferred_height.get(), self->field_root_14_text_29_min_height.get());
                        });
    self->field_text_29.horizontal_alignment.set(slint::cbindgen_private::TextHorizontalAlignment::Center);
    self->field_text_29.text.set_binding([this]() {
                            [[maybe_unused]] auto self = this;
                            return (self->field_root_14_pkg.get().installed ? slint::SharedString(u8"Remove \U00002717") : slint::SharedString(u8"Install \U00002713"));
                        });
    self->field_text_29.vertical_alignment.set(slint::cbindgen_private::TextVerticalAlignment::Center);
    self->field_text_29.width.set_binding([this]() {
                            [[maybe_unused]] auto self = this;
                            return std::max<float>(self->field_root_14_text_29_preferred_width.get(), self->field_root_14_text_29_min_width.get());
                        });
    self->field_rectangle_30.background.set(slint::Brush(slint::Color::from_argb_encoded(+4.281414212e9)));
    self->field_text_31.color.set(slint::Brush(slint::Color::from_argb_encoded(+4.290429662e9)));
    self->field_text_31.font_size.set(15);
    self->field_text_31.height.set_binding([this]() {
                            [[maybe_unused]] auto self = this;
                            return self->field_root_14_empty_17_layout_cache.get()[5];
                        });
    self->field_text_31.text.set_binding([this]() {
                            [[maybe_unused]] auto self = this;
                            return self->field_root_14_pkg.get().description;
                        });
    self->field_text_31.width.set_binding([this]() {
                            [[maybe_unused]] auto self = this;
                            return ((self->field_flickable_15.viewport_width.get() -(float) 60) -(float) 60);
                        });
    self->field_text_31.wrap.set(slint::cbindgen_private::TextWrap::WordWrap);
    self->field_rectangle_32.background.set(slint::Brush(slint::Color::from_argb_encoded(+4.279769125e9)));
    self->field_rectangle_32.border_color.set(slint::Brush(slint::Color::from_argb_encoded(+4.281414212e9)));
    self->field_rectangle_32.border_radius.set(12);
    self->field_rectangle_32.border_width.set(1);
    self->field_rectangle_54.background.set_binding([this]() {
                            [[maybe_unused]] auto self = this;
                            return slint::Brush((self->field_btn_ta_55.has_hover.get() ? slint::Color::from_argb_encoded(+4.28273033e9) : slint::Color::from_argb_encoded(+4.281414212e9)));
                        });
    self->field_rectangle_54.border_color.set(slint::Brush(slint::Color::from_argb_encoded(+4.28273033e9)));
    self->field_rectangle_54.border_radius.set(8);
    self->field_rectangle_54.border_width.set(1);
    self->field_btn_ta_55.clicked.set_handler(
                [this]() {
                    [[maybe_unused]] auto self = this;
                    self->field_root_14_back_clicked.call();
                });
    self->field_btn_ta_55.enabled.set(true);
    self->field_text_56.color.set(slint::Brush(slint::Color::from_argb_encoded(+4.291679988e9)));
    self->field_text_56.font_size.set(13);
    self->field_text_56.height.set_binding([this]() {
                            [[maybe_unused]] auto self = this;
                            return std::max<float>(self->field_root_14_text_56_preferred_height.get(), self->field_root_14_text_56_min_height.get());
                        });
    self->field_text_56.horizontal_alignment.set(slint::cbindgen_private::TextHorizontalAlignment::Center);
    self->field_text_56.text.set(slint::SharedString(u8"\U000027e8 Back"));
    self->field_text_56.vertical_alignment.set(slint::cbindgen_private::TextVerticalAlignment::Center);
    self->field_text_56.width.set_binding([this]() {
                            [[maybe_unused]] auto self = this;
                            return std::max<float>(self->field_root_14_text_56_preferred_width.get(), self->field_root_14_text_56_min_width.get());
                        });
    self->field_root_14.background.set_constant();
    self->field_root_14_empty_17_padding_bottom.set_constant();
    self->field_root_14_empty_17_padding_top.set_constant();
    self->field_root_14_empty_17_spacing.set_constant();
    self->field_root_14_rectangle_30_height.set_constant();
    self->field_flickable_15.interactive.set_constant();
    self->field_text_24.color.set_constant();
    self->field_text_24.font_family.set_constant();
    self->field_text_24.font_italic.set_constant();
    self->field_text_24.font_size.set_constant();
    self->field_text_24.font_weight.set_constant();
    self->field_text_24.horizontal_alignment.set_constant();
    self->field_text_24.letter_spacing.set_constant();
    self->field_text_24.overflow.set_constant();
    self->field_text_24.stroke.set_constant();
    self->field_text_24.stroke_style.set_constant();
    self->field_text_24.stroke_width.set_constant();
    self->field_text_24.vertical_alignment.set_constant();
    self->field_text_24.wrap.set_constant();
    self->field_text_25.color.set_constant();
    self->field_text_25.font_size.set_constant();
    self->field_text_25.font_weight.set_constant();
    self->field_text_25.horizontal_alignment.set_constant();
    self->field_text_25.vertical_alignment.set_constant();
    self->field_rectangle_27.border_color.set_constant();
    self->field_rectangle_27.border_radius.set_constant();
    self->field_rectangle_27.border_width.set_constant();
    self->field_toucharea_28.enabled.set_constant();
    self->field_toucharea_28.mouse_cursor.set_constant();
    self->field_text_29.color.set_constant();
    self->field_text_29.font_size.set_constant();
    self->field_text_29.font_weight.set_constant();
    self->field_text_29.horizontal_alignment.set_constant();
    self->field_text_29.vertical_alignment.set_constant();
    self->field_rectangle_30.background.set_constant();
    self->field_text_31.color.set_constant();
    self->field_text_31.font_family.set_constant();
    self->field_text_31.font_italic.set_constant();
    self->field_text_31.font_size.set_constant();
    self->field_text_31.font_weight.set_constant();
    self->field_text_31.horizontal_alignment.set_constant();
    self->field_text_31.letter_spacing.set_constant();
    self->field_text_31.overflow.set_constant();
    self->field_text_31.stroke.set_constant();
    self->field_text_31.stroke_style.set_constant();
    self->field_text_31.stroke_width.set_constant();
    self->field_text_31.vertical_alignment.set_constant();
    self->field_text_31.wrap.set_constant();
    self->field_rectangle_32.background.set_constant();
    self->field_rectangle_32.border_color.set_constant();
    self->field_rectangle_32.border_radius.set_constant();
    self->field_rectangle_32.border_width.set_constant();
    self->field_rectangle_54.border_color.set_constant();
    self->field_rectangle_54.border_radius.set_constant();
    self->field_rectangle_54.border_width.set_constant();
    self->field_btn_ta_55.enabled.set_constant();
    self->field_btn_ta_55.mouse_cursor.set_constant();
    self->field_text_56.color.set_constant();
    self->field_text_56.font_size.set_constant();
    self->field_text_56.font_weight.set_constant();
    self->field_text_56.horizontal_alignment.set_constant();
    self->field_text_56.text.set_constant();
    self->field_text_56.vertical_alignment.set_constant();
    self->repeater_0.set_model_binding([self] { (void)self; return (self->field_root_14_pkg.get().icon.size().width > 0); });
    self->repeater_1.set_model_binding([self] { (void)self; return (std::abs(float(self->field_root_14_pkg.get().icon.size().width - 0)) < std::numeric_limits<float>::epsilon()); });
    self->repeater_2.set_model_binding([self] { (void)self; return self->field_root_14_details.get().is_loading; });
    self->repeater_3.set_model_binding([self] { (void)self; return (! self->field_root_14_details.get().is_loading); });
}

auto DetailsView_root_14::user_init () -> void{
    [[maybe_unused]] auto self = this;
}

auto DetailsView_root_14::layout_info (slint::cbindgen_private::Orientation o) const -> slint::cbindgen_private::LayoutInfo{
    [[maybe_unused]] auto self = this;
    return o == slint::cbindgen_private::Orientation::Horizontal ? self->field_root_14_layoutinfo_h.get() : self->field_root_14_layoutinfo_v.get();
}

auto DetailsView_root_14::item_geometry (uint32_t index) const -> slint::cbindgen_private::Rect{
    [[maybe_unused]] auto self = this;
    switch (index) {
        case 0: return slint::private_api::convert_anonymous_rect(std::make_tuple(float(self->field_root_14_height.get()), float(self->field_root_14_width.get()), float(0), float(0)));
        case 1: return slint::private_api::convert_anonymous_rect(std::make_tuple(float(self->field_root_14_height.get()), float(self->field_root_14_width.get()), float(0), float(0)));
        case 2: return slint::private_api::convert_anonymous_rect(std::make_tuple(float(34), float(76), float(24), float(24)));
        case 3: return slint::private_api::convert_anonymous_rect(std::make_tuple(float(self->field_flickable_15.viewport_height.get()), float(self->field_flickable_15.viewport_width.get()), float(self->field_flickable_15.viewport_x.get()), float(self->field_flickable_15.viewport_y.get())));
        case 4: return slint::private_api::convert_anonymous_rect(std::make_tuple(float(self->field_root_14_empty_17_layout_cache.get()[1]), float(((self->field_flickable_15.viewport_width.get() -(float) 60) -(float) 60)), float(60), float(self->field_root_14_empty_17_layout_cache.get()[0])));
        case 5: return slint::private_api::convert_anonymous_rect(std::make_tuple(float(1), float(((self->field_flickable_15.viewport_width.get() -(float) 60) -(float) 60)), float(60), float(self->field_root_14_empty_17_layout_cache.get()[2])));
        case 6: return slint::private_api::convert_anonymous_rect(std::make_tuple(float(self->field_root_14_empty_17_layout_cache.get()[5]), float(((self->field_flickable_15.viewport_width.get() -(float) 60) -(float) 60)), float(60), float(self->field_root_14_empty_17_layout_cache.get()[4])));
        case 7: return slint::private_api::convert_anonymous_rect(std::make_tuple(float(self->field_root_14_empty_17_layout_cache.get()[7]), float(((self->field_flickable_15.viewport_width.get() -(float) 60) -(float) 60)), float(60), float(self->field_root_14_empty_17_layout_cache.get()[6])));
        case 10: return slint::private_api::convert_anonymous_rect(std::make_tuple(float(self->field_root_14_empty_17_layout_cache.get()[1]), float(self->field_root_14_empty_18_layout_cache.get()[5]), float(self->field_root_14_empty_18_layout_cache.get()[4]), float(0)));
        case 11: return slint::private_api::convert_anonymous_rect(std::make_tuple(float(self->field_root_14_empty_23_layout_cache.get()[1]), float(self->field_root_14_empty_18_layout_cache.get()[5]), float(0), float(self->field_root_14_empty_23_layout_cache.get()[0])));
        case 12: return slint::private_api::convert_anonymous_rect(std::make_tuple(float(self->field_root_14_empty_23_layout_cache.get()[3]), float(self->field_root_14_empty_18_layout_cache.get()[5]), float(0), float(self->field_root_14_empty_23_layout_cache.get()[2])));
        case 13: return slint::private_api::convert_anonymous_rect(std::make_tuple(float(self->field_root_14_empty_23_layout_cache.get()[5]), float(self->field_root_14_empty_18_layout_cache.get()[5]), float(0), float(self->field_root_14_empty_23_layout_cache.get()[4])));
        case 14: return slint::private_api::convert_anonymous_rect(std::make_tuple(float(38), float(130), float(self->field_root_14_empty_26_layout_cache.get()[0]), float(10)));
        case 15: return slint::private_api::convert_anonymous_rect(std::make_tuple(float(38), float(130), float(0), float(0)));
        case 16: return slint::private_api::convert_anonymous_rect(std::make_tuple(float(self->field_text_29.height.get()), float(self->field_text_29.width.get()), float(((130 -(float) self->field_text_29.width.get()) /(float) 2)), float(((38 -(float) self->field_text_29.height.get()) /(float) 2))));
        case 19: return slint::private_api::convert_anonymous_rect(std::make_tuple(float(34), float(76), float(0), float(0)));
        case 20: return slint::private_api::convert_anonymous_rect(std::make_tuple(float(self->field_text_56.height.get()), float(self->field_text_56.width.get()), float(((76 -(float) self->field_text_56.width.get()) /(float) 2)), float(((34 -(float) self->field_text_56.height.get()) /(float) 2))));
    }
    return {};
}

auto DetailsView_root_14::accessible_role (uint32_t index) const -> slint::cbindgen_private::AccessibleRole{
    [[maybe_unused]] auto self = this;
    switch (index) {
        case 6: return slint::cbindgen_private::AccessibleRole::Text;
        case 11: return slint::cbindgen_private::AccessibleRole::Text;
        case 12: return slint::cbindgen_private::AccessibleRole::Text;
        case 16: return slint::cbindgen_private::AccessibleRole::Text;
        case 20: return slint::cbindgen_private::AccessibleRole::Text;
    }
    return {};
}

auto DetailsView_root_14::accessible_string_property (uint32_t index, slint::cbindgen_private::AccessibleStringProperty what) const -> std::optional<slint::SharedString>{
    [[maybe_unused]] auto self = this;
    switch ((index << 8) | uintptr_t(what)) {
        case (6 << 8) | uintptr_t(slint::cbindgen_private::AccessibleStringProperty::Label): return self->field_root_14_pkg.get().description;
        case (11 << 8) | uintptr_t(slint::cbindgen_private::AccessibleStringProperty::Label): return self->field_root_14_pkg.get().pretty_name;
        case (12 << 8) | uintptr_t(slint::cbindgen_private::AccessibleStringProperty::Label): return self->field_text_25.text.get();
        case (16 << 8) | uintptr_t(slint::cbindgen_private::AccessibleStringProperty::Label): return self->field_text_29.text.get();
        case (20 << 8) | uintptr_t(slint::cbindgen_private::AccessibleStringProperty::Label): return slint::SharedString(u8"\U000027e8 Back");
    }
    return {};
}

auto DetailsView_root_14::accessibility_action (uint32_t index, const slint::cbindgen_private::AccessibilityAction &action) const -> void{
    [[maybe_unused]] auto self = this;
    switch ((index << 8) | uintptr_t(action.tag)) {
    }
    return ;
}

auto DetailsView_root_14::supported_accessibility_actions (uint32_t index) const -> uint32_t{
    [[maybe_unused]] auto self = this;
    switch (index) {
    }
    return {};
}

auto DetailsView_root_14::element_infos (uint32_t index) const -> std::optional<slint::SharedString>{
    [[maybe_unused]] auto self = this;
    switch (index) {
    }
    return {};
}

auto DetailsView_root_14::ensure_instantiated () const -> bool{
    [[maybe_unused]] auto self = this;
    bool _changed = false;
    _changed |= self->repeater_0.ensure_updated(self);
    _changed |= self->repeater_1.ensure_updated(self);
    _changed |= self->repeater_2.ensure_updated(self);
    _changed |= self->repeater_3.ensure_updated(self);
    return _changed;
}

auto DetailsView_root_14::visit_dynamic_children (uint32_t dyn_index, [[maybe_unused]] slint::private_api::TraversalOrder order, [[maybe_unused]] slint::private_api::ItemVisitorRefMut visitor) const -> uint64_t{
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
            } };
        std::abort();
}

auto DetailsView_root_14::subtree_range (uintptr_t dyn_index) const -> slint::private_api::IndexRange{
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
            } };
        std::abort();
}

auto DetailsView_root_14::subtree_component (uintptr_t dyn_index, [[maybe_unused]] uintptr_t subtree_index, [[maybe_unused]] slint::private_api::ItemTreeWeak *result) const -> void{
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
            } };
        std::abort();
}

Theme_76::Theme_76 (const class SharedGlobals *globals)
 : globals(globals)
{
}

auto Theme_76::init () -> void{
    (void)this->globals;
    this->field_accents.set_binding([this]() {
                            [[maybe_unused]] auto self = this;
                            return std::make_shared<slint::private_api::ArrayModel<14,slint::Color>>(slint::Color ( slint::Color::from_argb_encoded(+4.287214842e9) ), slint::Color ( slint::Color::from_argb_encoded(+4.291536631e9) ), slint::Color ( slint::Color::from_argb_encoded(+4.285843436e9) ), slint::Color ( slint::Color::from_argb_encoded(+4.290035454e9) ), slint::Color ( slint::Color::from_argb_encoded(+4.287947477e9) ), slint::Color ( slint::Color::from_argb_encoded(+4.289127329e9) ), slint::Color ( slint::Color::from_argb_encoded(+4.294566575e9) ), slint::Color ( slint::Color::from_argb_encoded(+4.294620039e9) ), slint::Color ( slint::Color::from_argb_encoded(+4.293632172e9) ), slint::Color ( slint::Color::from_argb_encoded(+4.29415108e9) ), slint::Color ( slint::Color::from_argb_encoded(+4.294102477e9) ), slint::Color ( slint::Color::from_argb_encoded(+4.294296295e9) ), slint::Color ( slint::Color::from_argb_encoded(+4.287225067e9) ), slint::Color ( slint::Color::from_argb_encoded(+4.294303964e9) ));
                        });
}

FluentPalette_78::FluentPalette_78 (const class SharedGlobals *globals)
 : globals(globals)
{
}

auto FluentPalette_78::init () -> void{
    (void)this->globals;
    this->field_color_scheme.set_binding([this]() {
                            [[maybe_unused]] auto self = this;
                            return [&]{ auto _root = (*this->globals->root_weak.lock()).into_dyn(); return slint::cbindgen_private::slint_context_color_scheme(&_root); }();
                        });
    this->field_dark_color_scheme.set_binding([this]() {
                            [[maybe_unused]] auto self = this;
                            return [&]{ [[maybe_unused]] auto tmp_FluentPalette_78_color_scheme = this->field_color_scheme.get();;return (! (tmp_FluentPalette_78_color_scheme == slint::cbindgen_private::ColorScheme::Unknown) ? (tmp_FluentPalette_78_color_scheme == slint::cbindgen_private::ColorScheme::Dark) : ([&]{ auto _root = (*this->globals->root_weak.lock()).into_dyn(); return slint::cbindgen_private::slint_context_color_scheme(&_root); }() == slint::cbindgen_private::ColorScheme::Dark)); }();
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

auto FluentPalette_78::fn_accentify ([[maybe_unused]] slint::Color arg_0) const -> slint::Color{
    [[maybe_unused]] auto self = this;
    return [&]{ [[maybe_unused]] auto local_accent_color = [&]{ auto _root = (*this->globals->root_weak.lock()).into_dyn(); slint::Color col; slint::cbindgen_private::slint_context_accent_color(&_root, &col); return col; }();;return (! (local_accent_color.to_argb_uint().alpha > 0) ? arg_0 : [&]{ [[maybe_unused]] auto local_default_lch = arg_0.to_oklch();;[[maybe_unused]] auto local_accent_lch = local_accent_color.to_oklch();;return slint::Color::from_oklch(std::clamp(static_cast<float>(local_default_lch.lightness), 0.f, 1.f), std::max(static_cast<float>(local_accent_lch.chroma), 0.f), static_cast<float>(local_accent_lch.hue), std::clamp(static_cast<float>(1), 0.f, 1.f)); }()); }();
}

const slint::private_api::ItemTreeVTable Component_appcard_71::static_vtable = { visit_children, get_item_ref, get_subtree_range, get_subtree, get_item_tree, parent_node, embed_component, subtree_index, layout_info, ensure_instantiated, item_geometry, accessible_role, accessible_string_property, accessibility_action, supported_accessibility_actions, element_infos, window_adapter, slint::private_api::drop_in_place<Component_appcard_71>, slint::private_api::dealloc };

auto Component_appcard_71::init (const class SharedGlobals* globals,slint::cbindgen_private::ItemTreeWeak enclosing_component,uint32_t tree_index,uint32_t tree_index_of_first_child,class Component_empty_58 const *parent) -> void{
    auto self = this;
    self->self_weak = enclosing_component;
    self->globals = globals;
    this->tree_index_of_first_child = tree_index_of_first_child;
    self->tree_index = tree_index;
    self->parent = vtable::VRcMapped<slint::private_api::ItemTreeVTable, const Component_empty_58>(parent->self_weak.lock().value(), parent);
    this->field_appcard_71.init(globals, self_weak.into_dyn(), tree_index, tree_index_of_first_child + 1 - 1);
    self->field_appcard_71.field_root_1_accent_idx.set_binding([this]() {
                            [[maybe_unused]] auto self = this;
                            return self->field_model_index.get();
                        });
    self->field_appcard_71.field_root_1_clicked.set_handler(
                [this]() {
                    [[maybe_unused]] auto self = this;
                    slint::private_api::optional_then(slint::private_api::optional_and_then(self->parent.lock(), [&](auto&&x) { return x->parent.lock(); }), [&](auto&&x) { x->field_root_57_app_clicked.call(self->field_model_data.get()); });
                });
    self->field_appcard_71.field_root_1_height.set(180);
    self->field_appcard_71.field_root_1_pkg.set_binding([this]() {
                            [[maybe_unused]] auto self = this;
                            return self->field_model_data.get();
                        });
    self->field_appcard_71.field_root_1_width.set(200);
    self->field_appcard_71.field_root_1_x.set_binding([this]() {
                            [[maybe_unused]] auto self = this;
                            return (24 + (([](float a, float b) { auto r = std::fmod(a, b); return r >= 0 ? r : r + std::abs(b); })(self->field_model_index.get(),static_cast<int>(std::max<float>(1, std::floor((((slint::private_api::optional_or_default(slint::private_api::optional_transform(slint::private_api::optional_and_then(self->parent.lock(), [&](auto&&x) { return x->parent.lock(); }), [&](auto&&x) { return x->field_root_57.width.get(); })) -(float) 48) + 16) /(float) 216))))) * 216));
                        });
    self->field_appcard_71.field_root_1_y.set_binding([this]() {
                            [[maybe_unused]] auto self = this;
                            return (24 + (std::floor((self->field_model_index.get() /(float) static_cast<int>(std::max<float>(1, std::floor((((slint::private_api::optional_or_default(slint::private_api::optional_transform(slint::private_api::optional_and_then(self->parent.lock(), [&](auto&&x) { return x->parent.lock(); }), [&](auto&&x) { return x->field_root_57.width.get(); })) -(float) 48) + 16) /(float) 216)))))) * 196));
                        });
    self->field_appcard_71.field_root_1.border_radius.set_constant();
    self->field_appcard_71.field_root_1.border_width.set_constant();
    self->field_appcard_71.field_root_1_empty_3_alignment.set_constant();
    self->field_appcard_71.field_root_1_empty_3_padding.set_constant();
    self->field_appcard_71.field_root_1_empty_3_spacing.set_constant();
    self->field_appcard_71.field_root_1_height.set_constant();
    self->field_appcard_71.field_root_1_width.set_constant();
}

auto Component_appcard_71::user_init () -> void{
    [[maybe_unused]] auto self = this;
    this->field_appcard_71.user_init();
}

auto Component_appcard_71::layout_info (slint::cbindgen_private::Orientation o) const -> slint::cbindgen_private::LayoutInfo{
    [[maybe_unused]] auto self = this;
    return o == slint::cbindgen_private::Orientation::Horizontal ? ([&](const auto &a_0, const auto &a_1, const auto &a_2, const auto &a_3, const auto &a_4, const auto &a_5){ slint::cbindgen_private::LayoutInfo o{}; o.max = a_0; o.max_percent = a_1; o.min = a_2; o.min_percent = a_3; o.preferred = a_4; o.stretch = a_5; return o; }(+3.4028234663852886e38, 100, 0, 0, 0, 1) + self->field_appcard_71.field_root_1_empty_3_layoutinfo_h.get()) : ([&](const auto &a_0, const auto &a_1, const auto &a_2, const auto &a_3, const auto &a_4, const auto &a_5){ slint::cbindgen_private::LayoutInfo o{}; o.max = a_0; o.max_percent = a_1; o.min = a_2; o.min_percent = a_3; o.preferred = a_4; o.stretch = a_5; return o; }(+3.4028234663852886e38, 100, 0, 0, 0, 1) + self->field_appcard_71.field_root_1_empty_3_layoutinfo_v.get());
}

auto Component_appcard_71::item_geometry (uint32_t index) const -> slint::cbindgen_private::Rect{
    [[maybe_unused]] auto self = this;
    switch (index) {
        case 0: return slint::private_api::convert_anonymous_rect(std::make_tuple(float(180), float(200), float(self->field_appcard_71.field_root_1_x.get()), float(self->field_appcard_71.field_root_1_y.get())));
    }
    if (index == 0) {
        return self->field_appcard_71.item_geometry(0);
    } else if (index >= 1 && index < 9) {
        return self->field_appcard_71.item_geometry(index - 0);
    } else return {};
}

auto Component_appcard_71::accessible_role (uint32_t index) const -> slint::cbindgen_private::AccessibleRole{
    [[maybe_unused]] auto self = this;
    switch (index) {
    }
    if (index == 0) {
        return self->field_appcard_71.accessible_role(0);
    } else if (index >= 1 && index < 9) {
        return self->field_appcard_71.accessible_role(index - 0);
    } else return {};
}

auto Component_appcard_71::accessible_string_property (uint32_t index, slint::cbindgen_private::AccessibleStringProperty what) const -> std::optional<slint::SharedString>{
    [[maybe_unused]] auto self = this;
    switch ((index << 8) | uintptr_t(what)) {
    }
    if (index == 0) {
        return self->field_appcard_71.accessible_string_property(0, what);
    } else if (index >= 1 && index < 9) {
        return self->field_appcard_71.accessible_string_property(index - 0, what);
    } else return {};
}

auto Component_appcard_71::accessibility_action (uint32_t index, const slint::cbindgen_private::AccessibilityAction &action) const -> void{
    [[maybe_unused]] auto self = this;
    switch ((index << 8) | uintptr_t(action.tag)) {
    }
    if (index == 0) {
        return self->field_appcard_71.accessibility_action(0, action);
    } else if (index >= 1 && index < 9) {
        return self->field_appcard_71.accessibility_action(index - 0, action);
    } else return ;
}

auto Component_appcard_71::supported_accessibility_actions (uint32_t index) const -> uint32_t{
    [[maybe_unused]] auto self = this;
    switch (index) {
    }
    if (index == 0) {
        return self->field_appcard_71.supported_accessibility_actions(0);
    } else if (index >= 1 && index < 9) {
        return self->field_appcard_71.supported_accessibility_actions(index - 0);
    } else return {};
}

auto Component_appcard_71::element_infos (uint32_t index) const -> std::optional<slint::SharedString>{
    [[maybe_unused]] auto self = this;
    switch (index) {
    }
    if (index == 0) {
        return self->field_appcard_71.element_infos(0);
    } else if (index >= 1 && index < 9) {
        return self->field_appcard_71.element_infos(index - 0);
    } else return {};
}

auto Component_appcard_71::ensure_instantiated () const -> bool{
    [[maybe_unused]] auto self = this;
    bool _changed = false;
    _changed |= self->field_appcard_71.ensure_instantiated();
    return _changed;
}

auto Component_appcard_71::visit_dynamic_children (uint32_t dyn_index, [[maybe_unused]] slint::private_api::TraversalOrder order, [[maybe_unused]] slint::private_api::ItemVisitorRefMut visitor) const -> uint64_t{
        auto self = this;
        switch(dyn_index) { 
        case 0: case 1:  {
                        return self->field_appcard_71.visit_dynamic_children(dyn_index - 0, order, visitor);
                    } };
        std::abort();
}

auto Component_appcard_71::subtree_range (uintptr_t dyn_index) const -> slint::private_api::IndexRange{
    [[maybe_unused]] auto self = this;
        switch(dyn_index) { 
        case 0: case 1:  {
                        return self->field_appcard_71.subtree_range(dyn_index - 0);
                    } };
        std::abort();
}

auto Component_appcard_71::subtree_component (uintptr_t dyn_index, [[maybe_unused]] uintptr_t subtree_index, [[maybe_unused]] slint::private_api::ItemTreeWeak *result) const -> void{
    [[maybe_unused]] auto self = this;
        switch(dyn_index) { 
        case 0: case 1:  {
                        self->field_appcard_71.subtree_component(dyn_index - 0, subtree_index, result);
                        return;
                    } };
        std::abort();
}

auto Component_appcard_71::visit_children (slint::private_api::ItemTreeRef component, intptr_t index, slint::private_api::TraversalOrder order, slint::private_api::ItemVisitorRefMut visitor) -> uint64_t{
    static const auto dyn_visit = [] (const void *base,  [[maybe_unused]] slint::private_api::TraversalOrder order, [[maybe_unused]] slint::private_api::ItemVisitorRefMut visitor, [[maybe_unused]] uint32_t dyn_index) -> uint64_t {
        [[maybe_unused]] auto self = reinterpret_cast<const Component_appcard_71*>(base);
        return self->visit_dynamic_children(dyn_index, order, visitor);
    };
    auto self_rc = reinterpret_cast<const Component_appcard_71*>(component.instance)->self_weak.lock()->into_dyn();
    return slint::cbindgen_private::slint_visit_item_tree(&self_rc, get_item_tree(component) , index, order, visitor, dyn_visit);
}

auto Component_appcard_71::get_item_ref (slint::private_api::ItemTreeRef component, uint32_t index) -> slint::private_api::ItemRef{
    return slint::private_api::get_item_ref(component, get_item_tree(component), item_array(), index);
}

auto Component_appcard_71::get_subtree_range ([[maybe_unused]] slint::private_api::ItemTreeRef component, [[maybe_unused]] uint32_t dyn_index) -> slint::private_api::IndexRange{
    auto self = reinterpret_cast<const Component_appcard_71*>(component.instance);
    return self->subtree_range(dyn_index);
}

auto Component_appcard_71::get_subtree ([[maybe_unused]] slint::private_api::ItemTreeRef component, [[maybe_unused]] uint32_t dyn_index, [[maybe_unused]] uintptr_t subtree_index, [[maybe_unused]] slint::private_api::ItemTreeWeak *result) -> void{
    auto self = reinterpret_cast<const Component_appcard_71*>(component.instance);
    self->subtree_component(dyn_index, subtree_index, result);
}

auto Component_appcard_71::get_item_tree (slint::private_api::ItemTreeRef) -> slint::cbindgen_private::Slice<slint::private_api::ItemTreeNode>{
    return item_tree();
}

auto Component_appcard_71::parent_node ([[maybe_unused]] slint::private_api::ItemTreeRef component, [[maybe_unused]] slint::private_api::ItemWeak *result) -> void{
    auto self = reinterpret_cast<const Component_appcard_71*>(component.instance);
    auto parent = self->parent.lock().value();
    *result = { parent->self_weak, parent->tree_index_of_first_child + 10 };
}

auto Component_appcard_71::embed_component ([[maybe_unused]] slint::private_api::ItemTreeRef component, [[maybe_unused]] const slint::private_api::ItemTreeWeak *parent_component, [[maybe_unused]] const uint32_t parent_index) -> bool{
    return false; /* todo! */
}

auto Component_appcard_71::subtree_index ([[maybe_unused]] slint::private_api::ItemTreeRef component) -> uintptr_t{
    auto self = reinterpret_cast<const Component_appcard_71*>(component.instance);
    return self->field_model_index.get();
}

auto Component_appcard_71::item_tree () -> slint::cbindgen_private::Slice<slint::private_api::ItemTreeNode>{
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

auto Component_appcard_71::item_array () -> const slint::private_api::ItemArray{
    static const slint::private_api::ItemArrayEntry items[] {
        { SLINT_GET_ITEM_VTABLE(BasicBorderRectangleVTable), offsetof(Component_appcard_71, field_appcard_71) +  offsetof(AppCard_root_1, field_root_1) }, 
{ SLINT_GET_ITEM_VTABLE(TouchAreaVTable), offsetof(Component_appcard_71, field_appcard_71) +  offsetof(AppCard_root_1, field_ta_2) }, 
{ SLINT_GET_ITEM_VTABLE(EmptyVTable), offsetof(Component_appcard_71, field_appcard_71) +  offsetof(AppCard_root_1, field_empty_4) }, 
{ SLINT_GET_ITEM_VTABLE(EmptyVTable), offsetof(Component_appcard_71, field_appcard_71) +  offsetof(AppCard_root_1, field_empty_10) }, 
{ SLINT_GET_ITEM_VTABLE(ComplexTextVTable), offsetof(Component_appcard_71, field_appcard_71) +  offsetof(AppCard_root_1, field_text_11) }, 
{ SLINT_GET_ITEM_VTABLE(ComplexTextVTable), offsetof(Component_appcard_71, field_appcard_71) +  offsetof(AppCard_root_1, field_text_12) }, 
{ SLINT_GET_ITEM_VTABLE(SimpleTextVTable), offsetof(Component_appcard_71, field_appcard_71) +  offsetof(AppCard_root_1, field_text_13) } };
    return slint::private_api::make_slice(std::span(items));
}

auto Component_appcard_71::layout_info ([[maybe_unused]] slint::private_api::ItemTreeRef component, slint::cbindgen_private::Orientation o) -> slint::cbindgen_private::LayoutInfo{
    return reinterpret_cast<const Component_appcard_71*>(component.instance)->layout_info(o);
}

auto Component_appcard_71::ensure_instantiated ([[maybe_unused]] slint::private_api::ItemTreeRef component) -> bool{
    return reinterpret_cast<const Component_appcard_71*>(component.instance)->ensure_instantiated();
}

auto Component_appcard_71::item_geometry ([[maybe_unused]] slint::private_api::ItemTreeRef component, uint32_t index) -> slint::cbindgen_private::LogicalRect{
    return reinterpret_cast<const Component_appcard_71*>(component.instance)->item_geometry(index);
}

auto Component_appcard_71::accessible_role ([[maybe_unused]] slint::private_api::ItemTreeRef component, uint32_t index) -> slint::cbindgen_private::AccessibleRole{
    return reinterpret_cast<const Component_appcard_71*>(component.instance)->accessible_role(index);
}

auto Component_appcard_71::accessible_string_property ([[maybe_unused]] slint::private_api::ItemTreeRef component, uint32_t index, slint::cbindgen_private::AccessibleStringProperty what, slint::SharedString *result) -> bool{
    if (auto r = reinterpret_cast<const Component_appcard_71*>(component.instance)->accessible_string_property(index, what)) { *result = *r; return true; } else { return false; }
}

auto Component_appcard_71::accessibility_action ([[maybe_unused]] slint::private_api::ItemTreeRef component, uint32_t index, const slint::cbindgen_private::AccessibilityAction *action) -> void{
    reinterpret_cast<const Component_appcard_71*>(component.instance)->accessibility_action(index, *action);
}

auto Component_appcard_71::supported_accessibility_actions ([[maybe_unused]] slint::private_api::ItemTreeRef component, uint32_t index) -> uint32_t{
    return reinterpret_cast<const Component_appcard_71*>(component.instance)->supported_accessibility_actions(index);
}

auto Component_appcard_71::element_infos ([[maybe_unused]] slint::private_api::ItemTreeRef component, [[maybe_unused]] uint32_t index, [[maybe_unused]] slint::SharedString *result) -> bool{
    return false;
}

auto Component_appcard_71::window_adapter ([[maybe_unused]] slint::private_api::ItemTreeRef component, [[maybe_unused]] bool do_create, [[maybe_unused]] slint::cbindgen_private::Option<slint::private_api::WindowAdapterRc>* result) -> void{
    *reinterpret_cast<slint::private_api::WindowAdapterRc*>(result) = reinterpret_cast<const Component_appcard_71*>(component.instance)->globals->window().window_handle();
}

auto Component_appcard_71::create (class Component_empty_58 const * parent) -> slint::ComponentHandle<Component_appcard_71>{
    auto self_rc = vtable::VRc<slint::private_api::ItemTreeVTable, Component_appcard_71>::make();
    auto self = const_cast<Component_appcard_71 *>(&*self_rc);
    self->self_weak = vtable::VWeak(self_rc).into_dyn();
    slint::private_api::register_item_tree(&self_rc.into_dyn(), parent->globals->m_window);
    self->init(parent->globals, self->self_weak, 0, 1 , parent);
    return slint::ComponentHandle<Component_appcard_71>{ self_rc };
}

Component_appcard_71::~Component_appcard_71 (){
    if (auto &window = globals->m_window) window->window_handle().unregister_item_tree(this, item_array());
}

auto Component_appcard_71::update_data ([[maybe_unused]] int i, [[maybe_unused]] const UiPackage &data) const -> void{
    [[maybe_unused]] auto self = this;
    self->field_model_index.set(i);
    self->field_model_data.set(data);
}

auto Component_appcard_71::init () -> void{
    user_init();
}

auto Component_appcard_71::layout_item_info (slint::cbindgen_private::Orientation o, [[maybe_unused]] std::optional<size_t> child_index) const -> slint::cbindgen_private::LayoutItemInfo{
    return { layout_info({&static_vtable, const_cast<void *>(static_cast<const void *>(this))}, o) };
}

auto Component_appcard_71::flexbox_layout_item_info (slint::cbindgen_private::Orientation o, [[maybe_unused]] std::optional<size_t> child_index) const -> slint::cbindgen_private::FlexboxLayoutItemInfo{
    auto base = layout_item_info(o, child_index); return { base.constraint, 0.0f, 0.0f, -1.0f, slint::cbindgen_private::FlexboxLayoutAlignSelf::Auto, 0 };
}

const slint::private_api::ItemTreeVTable Component_empty_58::static_vtable = { visit_children, get_item_ref, get_subtree_range, get_subtree, get_item_tree, parent_node, embed_component, subtree_index, layout_info, ensure_instantiated, item_geometry, accessible_role, accessible_string_property, accessibility_action, supported_accessibility_actions, element_infos, window_adapter, slint::private_api::drop_in_place<Component_empty_58>, slint::private_api::dealloc };

auto Component_empty_58::fn_layoutinfo_v_with_constraint ([[maybe_unused]] float arg_0) const -> slint::cbindgen_private::LayoutInfo{
    [[maybe_unused]] auto self = this;
    return slint::private_api::box_layout_info(slint::private_api::make_slice<slint::cbindgen_private::LayoutItemInfo>(std::array<slint::cbindgen_private::LayoutItemInfo, 2>{ slint::cbindgen_private::LayoutItemInfo ( [&](const auto &a_0){ slint::cbindgen_private::LayoutItemInfo o{}; o.constraint = a_0; return o; }([&]{ [[maybe_unused]] auto layout_info = self->field_empty_58_rectangle_59_layoutinfo_v.get();;return [&](const auto &a_0, const auto &a_1, const auto &a_2, const auto &a_3, const auto &a_4, const auto &a_5){ slint::cbindgen_private::LayoutInfo o{}; o.max = a_0; o.max_percent = a_1; o.min = a_2; o.min_percent = a_3; o.preferred = a_4; o.stretch = a_5; return o; }(self->field_empty_58_rectangle_59_height.get(), layout_info.max_percent, self->field_empty_58_rectangle_59_height.get(), layout_info.min_percent, layout_info.preferred, layout_info.stretch); }()) ), slint::cbindgen_private::LayoutItemInfo ( [&](const auto &a_0){ slint::cbindgen_private::LayoutItemInfo o{}; o.constraint = a_0; return o; }(slint::private_api::item_layout_info(SLINT_GET_ITEM_VTABLE(FlickableVTable), const_cast<slint::cbindgen_private::Flickable*>(&self->field_grid_area_69), slint::cbindgen_private::Orientation::Vertical, arg_0, &self->globals->window().window_handle(), self->self_weak.lock()->into_dyn(), self->tree_index_of_first_child + 2 - 1)) ) }.data(), 2),0,[&](const auto &a_0, const auto &a_1){ slint::cbindgen_private::Padding o{}; o.begin = a_0; o.end = a_1; return o; }(0, 0),slint::cbindgen_private::LayoutAlignment::Stretch);
}

auto Component_empty_58::init (const class SharedGlobals* globals,slint::cbindgen_private::ItemTreeWeak enclosing_component,uint32_t tree_index,uint32_t tree_index_of_first_child,class MainWindow const *parent) -> void{
    auto self = this;
    self->self_weak = enclosing_component;
    self->globals = globals;
    this->tree_index_of_first_child = tree_index_of_first_child;
    self->tree_index = tree_index;
    self->parent = vtable::VRcMapped<slint::private_api::ItemTreeVTable, const MainWindow>(parent->self_weak.lock().value(), parent);
    self->field_empty_58_empty_60_layout_cache.set_binding([this]() {
                            [[maybe_unused]] auto self = this;
                            return slint::private_api::solve_box_layout([&](const auto &a_0, const auto &a_1, const auto &a_2, const auto &a_3, const auto &a_4){ slint::cbindgen_private::BoxLayoutData o{}; o.alignment = a_0; o.cells = a_1; o.padding = a_2; o.size = a_3; o.spacing = a_4; return o; }(slint::cbindgen_private::LayoutAlignment::SpaceBetween, slint::private_api::make_slice<slint::cbindgen_private::LayoutItemInfo>(std::array<slint::cbindgen_private::LayoutItemInfo, 2>{ slint::cbindgen_private::LayoutItemInfo ( [&](const auto &a_0){ slint::cbindgen_private::LayoutItemInfo o{}; o.constraint = a_0; return o; }(self->field_empty_58_empty_61_layoutinfo_h.get()) ), slint::cbindgen_private::LayoutItemInfo ( [&](const auto &a_0){ slint::cbindgen_private::LayoutItemInfo o{}; o.constraint = a_0; return o; }([&]{ [[maybe_unused]] auto layout_info = ([&](const auto &a_0, const auto &a_1, const auto &a_2, const auto &a_3, const auto &a_4, const auto &a_5){ slint::cbindgen_private::LayoutInfo o{}; o.max = a_0; o.max_percent = a_1; o.min = a_2; o.min_percent = a_3; o.preferred = a_4; o.stretch = a_5; return o; }(+3.4028234663852886e38, 100, 0, 0, 0, 1) + self->field_empty_58_empty_67_layoutinfo_h.get());;return [&](const auto &a_0, const auto &a_1, const auto &a_2, const auto &a_3, const auto &a_4, const auto &a_5){ slint::cbindgen_private::LayoutInfo o{}; o.max = a_0; o.max_percent = a_1; o.min = a_2; o.min_percent = a_3; o.preferred = a_4; o.stretch = a_5; return o; }(260, layout_info.max_percent, 260, layout_info.min_percent, layout_info.preferred, layout_info.stretch); }()) ) }.data(), 2), [&](const auto &a_0, const auto &a_1){ slint::cbindgen_private::Padding o{}; o.begin = a_0; o.end = a_1; return o; }(24, 24), self->field_empty_58_rectangle_59_width.get(), 0),slint::private_api::make_slice<int>(std::array<int, 0>{  }.data(), 0));
                        });
    self->field_empty_58_empty_60_layoutinfo_h.set_binding([this]() {
                            [[maybe_unused]] auto self = this;
                            return slint::private_api::box_layout_info(slint::private_api::make_slice<slint::cbindgen_private::LayoutItemInfo>(std::array<slint::cbindgen_private::LayoutItemInfo, 2>{ slint::cbindgen_private::LayoutItemInfo ( [&](const auto &a_0){ slint::cbindgen_private::LayoutItemInfo o{}; o.constraint = a_0; return o; }(self->field_empty_58_empty_61_layoutinfo_h.get()) ), slint::cbindgen_private::LayoutItemInfo ( [&](const auto &a_0){ slint::cbindgen_private::LayoutItemInfo o{}; o.constraint = a_0; return o; }([&]{ [[maybe_unused]] auto layout_info = ([&](const auto &a_0, const auto &a_1, const auto &a_2, const auto &a_3, const auto &a_4, const auto &a_5){ slint::cbindgen_private::LayoutInfo o{}; o.max = a_0; o.max_percent = a_1; o.min = a_2; o.min_percent = a_3; o.preferred = a_4; o.stretch = a_5; return o; }(+3.4028234663852886e38, 100, 0, 0, 0, 1) + self->field_empty_58_empty_67_layoutinfo_h.get());;return [&](const auto &a_0, const auto &a_1, const auto &a_2, const auto &a_3, const auto &a_4, const auto &a_5){ slint::cbindgen_private::LayoutInfo o{}; o.max = a_0; o.max_percent = a_1; o.min = a_2; o.min_percent = a_3; o.preferred = a_4; o.stretch = a_5; return o; }(260, layout_info.max_percent, 260, layout_info.min_percent, layout_info.preferred, layout_info.stretch); }()) ) }.data(), 2),0,[&](const auto &a_0, const auto &a_1){ slint::cbindgen_private::Padding o{}; o.begin = a_0; o.end = a_1; return o; }(24, 24),slint::cbindgen_private::LayoutAlignment::SpaceBetween);
                        });
    self->field_empty_58_empty_60_layoutinfo_v.set_binding([this]() {
                            [[maybe_unused]] auto self = this;
                            return slint::private_api::box_layout_info_ortho(slint::private_api::make_slice<slint::cbindgen_private::LayoutItemInfo>(std::array<slint::cbindgen_private::LayoutItemInfo, 2>{ slint::cbindgen_private::LayoutItemInfo ( [&](const auto &a_0){ slint::cbindgen_private::LayoutItemInfo o{}; o.constraint = a_0; return o; }(self->field_empty_58_empty_61_layoutinfo_v.get()) ), slint::cbindgen_private::LayoutItemInfo ( [&](const auto &a_0){ slint::cbindgen_private::LayoutItemInfo o{}; o.constraint = a_0; return o; }([&]{ [[maybe_unused]] auto layout_info = ([&](const auto &a_0, const auto &a_1, const auto &a_2, const auto &a_3, const auto &a_4, const auto &a_5){ slint::cbindgen_private::LayoutInfo o{}; o.max = a_0; o.max_percent = a_1; o.min = a_2; o.min_percent = a_3; o.preferred = a_4; o.stretch = a_5; return o; }(+3.4028234663852886e38, 100, 0, 0, 0, 1) + self->field_empty_58_empty_67_layoutinfo_v.get());;return [&](const auto &a_0, const auto &a_1, const auto &a_2, const auto &a_3, const auto &a_4, const auto &a_5){ slint::cbindgen_private::LayoutInfo o{}; o.max = a_0; o.max_percent = a_1; o.min = a_2; o.min_percent = a_3; o.preferred = a_4; o.stretch = a_5; return o; }(36, layout_info.max_percent, 36, layout_info.min_percent, layout_info.preferred, layout_info.stretch); }()) ) }.data(), 2),[&](const auto &a_0, const auto &a_1){ slint::cbindgen_private::Padding o{}; o.begin = a_0; o.end = a_1; return o; }(0, 0));
                        });
    self->field_empty_58_empty_61_layout_cache.set_binding([this]() {
                            [[maybe_unused]] auto self = this;
                            return slint::private_api::solve_box_layout([&](const auto &a_0, const auto &a_1, const auto &a_2, const auto &a_3, const auto &a_4){ slint::cbindgen_private::BoxLayoutData o{}; o.alignment = a_0; o.cells = a_1; o.padding = a_2; o.size = a_3; o.spacing = a_4; return o; }(slint::cbindgen_private::LayoutAlignment::Start, slint::private_api::make_slice<slint::cbindgen_private::LayoutItemInfo>(std::array<slint::cbindgen_private::LayoutItemInfo, 2>{ slint::cbindgen_private::LayoutItemInfo ( [&](const auto &a_0){ slint::cbindgen_private::LayoutItemInfo o{}; o.constraint = a_0; return o; }(slint::private_api::item_layout_info(SLINT_GET_ITEM_VTABLE(SimpleTextVTable), const_cast<slint::cbindgen_private::SimpleText*>(&self->field_text_62), slint::cbindgen_private::Orientation::Horizontal, -1, &self->globals->window().window_handle(), self->self_weak.lock()->into_dyn(), self->tree_index_of_first_child + 5 - 1)) ), slint::cbindgen_private::LayoutItemInfo ( [&](const auto &a_0){ slint::cbindgen_private::LayoutItemInfo o{}; o.constraint = a_0; return o; }(self->field_empty_58_empty_63_layoutinfo_h.get()) ) }.data(), 2), [&](const auto &a_0, const auto &a_1){ slint::cbindgen_private::Padding o{}; o.begin = a_0; o.end = a_1; return o; }(0, 0), self->field_empty_58_empty_60_layout_cache.get()[1], 10),slint::private_api::make_slice<int>(std::array<int, 0>{  }.data(), 0));
                        });
    self->field_empty_58_empty_61_layoutinfo_h.set_binding([this]() {
                            [[maybe_unused]] auto self = this;
                            return slint::private_api::box_layout_info(slint::private_api::make_slice<slint::cbindgen_private::LayoutItemInfo>(std::array<slint::cbindgen_private::LayoutItemInfo, 2>{ slint::cbindgen_private::LayoutItemInfo ( [&](const auto &a_0){ slint::cbindgen_private::LayoutItemInfo o{}; o.constraint = a_0; return o; }(slint::private_api::item_layout_info(SLINT_GET_ITEM_VTABLE(SimpleTextVTable), const_cast<slint::cbindgen_private::SimpleText*>(&self->field_text_62), slint::cbindgen_private::Orientation::Horizontal, -1, &self->globals->window().window_handle(), self->self_weak.lock()->into_dyn(), self->tree_index_of_first_child + 5 - 1)) ), slint::cbindgen_private::LayoutItemInfo ( [&](const auto &a_0){ slint::cbindgen_private::LayoutItemInfo o{}; o.constraint = a_0; return o; }(self->field_empty_58_empty_63_layoutinfo_h.get()) ) }.data(), 2),10,[&](const auto &a_0, const auto &a_1){ slint::cbindgen_private::Padding o{}; o.begin = a_0; o.end = a_1; return o; }(0, 0),slint::cbindgen_private::LayoutAlignment::Start);
                        });
    self->field_empty_58_empty_61_layoutinfo_v.set_binding([this]() {
                            [[maybe_unused]] auto self = this;
                            return slint::private_api::box_layout_info_ortho(slint::private_api::make_slice<slint::cbindgen_private::LayoutItemInfo>(std::array<slint::cbindgen_private::LayoutItemInfo, 2>{ slint::cbindgen_private::LayoutItemInfo ( [&](const auto &a_0){ slint::cbindgen_private::LayoutItemInfo o{}; o.constraint = a_0; return o; }(slint::private_api::item_layout_info(SLINT_GET_ITEM_VTABLE(SimpleTextVTable), const_cast<slint::cbindgen_private::SimpleText*>(&self->field_text_62), slint::cbindgen_private::Orientation::Vertical, -1, &self->globals->window().window_handle(), self->self_weak.lock()->into_dyn(), self->tree_index_of_first_child + 5 - 1)) ), slint::cbindgen_private::LayoutItemInfo ( [&](const auto &a_0){ slint::cbindgen_private::LayoutItemInfo o{}; o.constraint = a_0; return o; }(self->field_empty_58_empty_63_layoutinfo_v.get()) ) }.data(), 2),[&](const auto &a_0, const auto &a_1){ slint::cbindgen_private::Padding o{}; o.begin = a_0; o.end = a_1; return o; }(0, 0));
                        });
    self->field_empty_58_empty_63_layout_cache.set_binding([this]() {
                            [[maybe_unused]] auto self = this;
                            return slint::private_api::solve_box_layout([&](const auto &a_0, const auto &a_1, const auto &a_2, const auto &a_3, const auto &a_4){ slint::cbindgen_private::BoxLayoutData o{}; o.alignment = a_0; o.cells = a_1; o.padding = a_2; o.size = a_3; o.spacing = a_4; return o; }(slint::cbindgen_private::LayoutAlignment::Center, slint::private_api::make_slice<slint::cbindgen_private::LayoutItemInfo>(std::array<slint::cbindgen_private::LayoutItemInfo, 2>{ slint::cbindgen_private::LayoutItemInfo ( [&](const auto &a_0){ slint::cbindgen_private::LayoutItemInfo o{}; o.constraint = a_0; return o; }(slint::private_api::item_layout_info(SLINT_GET_ITEM_VTABLE(SimpleTextVTable), const_cast<slint::cbindgen_private::SimpleText*>(&self->field_text_64), slint::cbindgen_private::Orientation::Vertical, -1, &self->globals->window().window_handle(), self->self_weak.lock()->into_dyn(), self->tree_index_of_first_child + 7 - 1)) ), slint::cbindgen_private::LayoutItemInfo ( [&](const auto &a_0){ slint::cbindgen_private::LayoutItemInfo o{}; o.constraint = a_0; return o; }(slint::private_api::item_layout_info(SLINT_GET_ITEM_VTABLE(SimpleTextVTable), const_cast<slint::cbindgen_private::SimpleText*>(&self->field_text_65), slint::cbindgen_private::Orientation::Vertical, -1, &self->globals->window().window_handle(), self->self_weak.lock()->into_dyn(), self->tree_index_of_first_child + 8 - 1)) ) }.data(), 2), [&](const auto &a_0, const auto &a_1){ slint::cbindgen_private::Padding o{}; o.begin = a_0; o.end = a_1; return o; }(0, 0), 64, 0),slint::private_api::make_slice<int>(std::array<int, 0>{  }.data(), 0));
                        });
    self->field_empty_58_empty_63_layoutinfo_h.set_binding([this]() {
                            [[maybe_unused]] auto self = this;
                            return slint::private_api::box_layout_info_ortho(slint::private_api::make_slice<slint::cbindgen_private::LayoutItemInfo>(std::array<slint::cbindgen_private::LayoutItemInfo, 2>{ slint::cbindgen_private::LayoutItemInfo ( [&](const auto &a_0){ slint::cbindgen_private::LayoutItemInfo o{}; o.constraint = a_0; return o; }(slint::private_api::item_layout_info(SLINT_GET_ITEM_VTABLE(SimpleTextVTable), const_cast<slint::cbindgen_private::SimpleText*>(&self->field_text_64), slint::cbindgen_private::Orientation::Horizontal, -1, &self->globals->window().window_handle(), self->self_weak.lock()->into_dyn(), self->tree_index_of_first_child + 7 - 1)) ), slint::cbindgen_private::LayoutItemInfo ( [&](const auto &a_0){ slint::cbindgen_private::LayoutItemInfo o{}; o.constraint = a_0; return o; }(slint::private_api::item_layout_info(SLINT_GET_ITEM_VTABLE(SimpleTextVTable), const_cast<slint::cbindgen_private::SimpleText*>(&self->field_text_65), slint::cbindgen_private::Orientation::Horizontal, -1, &self->globals->window().window_handle(), self->self_weak.lock()->into_dyn(), self->tree_index_of_first_child + 8 - 1)) ) }.data(), 2),[&](const auto &a_0, const auto &a_1){ slint::cbindgen_private::Padding o{}; o.begin = a_0; o.end = a_1; return o; }(0, 0));
                        });
    self->field_empty_58_empty_63_layoutinfo_v.set_binding([this]() {
                            [[maybe_unused]] auto self = this;
                            return slint::private_api::box_layout_info(slint::private_api::make_slice<slint::cbindgen_private::LayoutItemInfo>(std::array<slint::cbindgen_private::LayoutItemInfo, 2>{ slint::cbindgen_private::LayoutItemInfo ( [&](const auto &a_0){ slint::cbindgen_private::LayoutItemInfo o{}; o.constraint = a_0; return o; }(slint::private_api::item_layout_info(SLINT_GET_ITEM_VTABLE(SimpleTextVTable), const_cast<slint::cbindgen_private::SimpleText*>(&self->field_text_64), slint::cbindgen_private::Orientation::Vertical, -1, &self->globals->window().window_handle(), self->self_weak.lock()->into_dyn(), self->tree_index_of_first_child + 7 - 1)) ), slint::cbindgen_private::LayoutItemInfo ( [&](const auto &a_0){ slint::cbindgen_private::LayoutItemInfo o{}; o.constraint = a_0; return o; }(slint::private_api::item_layout_info(SLINT_GET_ITEM_VTABLE(SimpleTextVTable), const_cast<slint::cbindgen_private::SimpleText*>(&self->field_text_65), slint::cbindgen_private::Orientation::Vertical, -1, &self->globals->window().window_handle(), self->self_weak.lock()->into_dyn(), self->tree_index_of_first_child + 8 - 1)) ) }.data(), 2),0,[&](const auto &a_0, const auto &a_1){ slint::cbindgen_private::Padding o{}; o.begin = a_0; o.end = a_1; return o; }(0, 0),slint::cbindgen_private::LayoutAlignment::Center);
                        });
    self->field_empty_58_empty_67_layout_cache.set_binding([this]() {
                            [[maybe_unused]] auto self = this;
                            return slint::private_api::solve_box_layout([&](const auto &a_0, const auto &a_1, const auto &a_2, const auto &a_3, const auto &a_4){ slint::cbindgen_private::BoxLayoutData o{}; o.alignment = a_0; o.cells = a_1; o.padding = a_2; o.size = a_3; o.spacing = a_4; return o; }(slint::cbindgen_private::LayoutAlignment::Stretch, slint::private_api::make_slice<slint::cbindgen_private::LayoutItemInfo>(std::array<slint::cbindgen_private::LayoutItemInfo, 1>{ slint::cbindgen_private::LayoutItemInfo ( [&](const auto &a_0){ slint::cbindgen_private::LayoutItemInfo o{}; o.constraint = a_0; return o; }(slint::private_api::item_layout_info(SLINT_GET_ITEM_VTABLE(TextInputVTable), const_cast<slint::cbindgen_private::TextInput*>(&self->field_textinput_68), slint::cbindgen_private::Orientation::Horizontal, -1, &self->globals->window().window_handle(), self->self_weak.lock()->into_dyn(), self->tree_index_of_first_child + 9 - 1)) ) }.data(), 1), [&](const auto &a_0, const auto &a_1){ slint::cbindgen_private::Padding o{}; o.begin = a_0; o.end = a_1; return o; }(12, 12), 260, 0),slint::private_api::make_slice<int>(std::array<int, 0>{  }.data(), 0));
                        });
    self->field_empty_58_empty_67_layoutinfo_h.set_binding([this]() {
                            [[maybe_unused]] auto self = this;
                            return slint::private_api::box_layout_info(slint::private_api::make_slice<slint::cbindgen_private::LayoutItemInfo>(std::array<slint::cbindgen_private::LayoutItemInfo, 1>{ slint::cbindgen_private::LayoutItemInfo ( [&](const auto &a_0){ slint::cbindgen_private::LayoutItemInfo o{}; o.constraint = a_0; return o; }(slint::private_api::item_layout_info(SLINT_GET_ITEM_VTABLE(TextInputVTable), const_cast<slint::cbindgen_private::TextInput*>(&self->field_textinput_68), slint::cbindgen_private::Orientation::Horizontal, -1, &self->globals->window().window_handle(), self->self_weak.lock()->into_dyn(), self->tree_index_of_first_child + 9 - 1)) ) }.data(), 1),0,[&](const auto &a_0, const auto &a_1){ slint::cbindgen_private::Padding o{}; o.begin = a_0; o.end = a_1; return o; }(12, 12),slint::cbindgen_private::LayoutAlignment::Stretch);
                        });
    self->field_empty_58_empty_67_layoutinfo_v.set_binding([this]() {
                            [[maybe_unused]] auto self = this;
                            return slint::private_api::box_layout_info_ortho(slint::private_api::make_slice<slint::cbindgen_private::LayoutItemInfo>(std::array<slint::cbindgen_private::LayoutItemInfo, 1>{ slint::cbindgen_private::LayoutItemInfo ( [&](const auto &a_0){ slint::cbindgen_private::LayoutItemInfo o{}; o.constraint = a_0; return o; }(slint::private_api::item_layout_info(SLINT_GET_ITEM_VTABLE(TextInputVTable), const_cast<slint::cbindgen_private::TextInput*>(&self->field_textinput_68), slint::cbindgen_private::Orientation::Vertical, -1, &self->globals->window().window_handle(), self->self_weak.lock()->into_dyn(), self->tree_index_of_first_child + 9 - 1)) ) }.data(), 1),[&](const auto &a_0, const auto &a_1){ slint::cbindgen_private::Padding o{}; o.begin = a_0; o.end = a_1; return o; }(0, 0));
                        });
    self->field_empty_58_grid_area_69_total_rows.set_binding([this]() {
                            [[maybe_unused]] auto self = this;
                            return [&]{ [[maybe_unused]] auto tmp_root_57_packages = slint::private_api::optional_or_default(slint::private_api::optional_transform(self->parent.lock(), [&](auto&&x) { return x->field_root_57_packages.get(); }));;return static_cast<int>((slint::private_api::model_length(tmp_root_57_packages) > 0 ? [&]{ [[maybe_unused]] auto tmp_empty_58_grid_area_69_cols = static_cast<int>(std::max<float>(1, std::floor((((slint::private_api::optional_or_default(slint::private_api::optional_transform(self->parent.lock(), [&](auto&&x) { return x->field_root_57.width.get(); })) -(float) 48) + 16) /(float) 216))));;return std::floor((((slint::private_api::model_length(tmp_root_57_packages) + tmp_empty_58_grid_area_69_cols) -(float) 1) /(float) tmp_empty_58_grid_area_69_cols)); }() : 0)); }();
                        });
    self->field_empty_58_layout_cache.set_binding([this]() {
                            [[maybe_unused]] auto self = this;
                            return slint::private_api::solve_box_layout([&](const auto &a_0, const auto &a_1, const auto &a_2, const auto &a_3, const auto &a_4){ slint::cbindgen_private::BoxLayoutData o{}; o.alignment = a_0; o.cells = a_1; o.padding = a_2; o.size = a_3; o.spacing = a_4; return o; }(slint::cbindgen_private::LayoutAlignment::Stretch, slint::private_api::make_slice<slint::cbindgen_private::LayoutItemInfo>(std::array<slint::cbindgen_private::LayoutItemInfo, 2>{ slint::cbindgen_private::LayoutItemInfo ( [&](const auto &a_0){ slint::cbindgen_private::LayoutItemInfo o{}; o.constraint = a_0; return o; }([&]{ [[maybe_unused]] auto layout_info = ([&](const auto &a_0, const auto &a_1, const auto &a_2, const auto &a_3, const auto &a_4, const auto &a_5){ slint::cbindgen_private::LayoutInfo o{}; o.max = a_0; o.max_percent = a_1; o.min = a_2; o.min_percent = a_3; o.preferred = a_4; o.stretch = a_5; return o; }(+3.4028234663852886e38, 100, 0, 0, 0, 1) + self->field_empty_58_empty_60_layoutinfo_v.get());;return [&](const auto &a_0, const auto &a_1, const auto &a_2, const auto &a_3, const auto &a_4, const auto &a_5){ slint::cbindgen_private::LayoutInfo o{}; o.max = a_0; o.max_percent = a_1; o.min = a_2; o.min_percent = a_3; o.preferred = a_4; o.stretch = a_5; return o; }(64, layout_info.max_percent, 64, layout_info.min_percent, layout_info.preferred, layout_info.stretch); }()) ), slint::cbindgen_private::LayoutItemInfo ( [&](const auto &a_0){ slint::cbindgen_private::LayoutItemInfo o{}; o.constraint = a_0; return o; }(slint::private_api::item_layout_info(SLINT_GET_ITEM_VTABLE(FlickableVTable), const_cast<slint::cbindgen_private::Flickable*>(&self->field_grid_area_69), slint::cbindgen_private::Orientation::Vertical, -1, &self->globals->window().window_handle(), self->self_weak.lock()->into_dyn(), self->tree_index_of_first_child + 2 - 1)) ) }.data(), 2), [&](const auto &a_0, const auto &a_1){ slint::cbindgen_private::Padding o{}; o.begin = a_0; o.end = a_1; return o; }(0, 0), slint::private_api::optional_or_default(slint::private_api::optional_transform(self->parent.lock(), [&](auto&&x) { return x->field_root_57.height.get(); })), 0),slint::private_api::make_slice<int>(std::array<int, 0>{  }.data(), 0));
                        });
    self->field_empty_58_layoutinfo_h.set_binding([this]() {
                            [[maybe_unused]] auto self = this;
                            return slint::private_api::box_layout_info_ortho(slint::private_api::make_slice<slint::cbindgen_private::LayoutItemInfo>(std::array<slint::cbindgen_private::LayoutItemInfo, 2>{ slint::cbindgen_private::LayoutItemInfo ( [&](const auto &a_0){ slint::cbindgen_private::LayoutItemInfo o{}; o.constraint = a_0; return o; }(([&](const auto &a_0, const auto &a_1, const auto &a_2, const auto &a_3, const auto &a_4, const auto &a_5){ slint::cbindgen_private::LayoutInfo o{}; o.max = a_0; o.max_percent = a_1; o.min = a_2; o.min_percent = a_3; o.preferred = a_4; o.stretch = a_5; return o; }(+3.4028234663852886e38, 100, 0, 0, 0, 1) + self->field_empty_58_empty_60_layoutinfo_h.get())) ), slint::cbindgen_private::LayoutItemInfo ( [&](const auto &a_0){ slint::cbindgen_private::LayoutItemInfo o{}; o.constraint = a_0; return o; }(slint::private_api::item_layout_info(SLINT_GET_ITEM_VTABLE(FlickableVTable), const_cast<slint::cbindgen_private::Flickable*>(&self->field_grid_area_69), slint::cbindgen_private::Orientation::Horizontal, -1, &self->globals->window().window_handle(), self->self_weak.lock()->into_dyn(), self->tree_index_of_first_child + 2 - 1)) ) }.data(), 2),[&](const auto &a_0, const auto &a_1){ slint::cbindgen_private::Padding o{}; o.begin = a_0; o.end = a_1; return o; }(0, 0));
                        });
    self->field_empty_58_layoutinfo_v.set_binding([this]() {
                            [[maybe_unused]] auto self = this;
                            return slint::private_api::box_layout_info(slint::private_api::make_slice<slint::cbindgen_private::LayoutItemInfo>(std::array<slint::cbindgen_private::LayoutItemInfo, 2>{ slint::cbindgen_private::LayoutItemInfo ( [&](const auto &a_0){ slint::cbindgen_private::LayoutItemInfo o{}; o.constraint = a_0; return o; }([&]{ [[maybe_unused]] auto layout_info = ([&](const auto &a_0, const auto &a_1, const auto &a_2, const auto &a_3, const auto &a_4, const auto &a_5){ slint::cbindgen_private::LayoutInfo o{}; o.max = a_0; o.max_percent = a_1; o.min = a_2; o.min_percent = a_3; o.preferred = a_4; o.stretch = a_5; return o; }(+3.4028234663852886e38, 100, 0, 0, 0, 1) + self->field_empty_58_empty_60_layoutinfo_v.get());;return [&](const auto &a_0, const auto &a_1, const auto &a_2, const auto &a_3, const auto &a_4, const auto &a_5){ slint::cbindgen_private::LayoutInfo o{}; o.max = a_0; o.max_percent = a_1; o.min = a_2; o.min_percent = a_3; o.preferred = a_4; o.stretch = a_5; return o; }(64, layout_info.max_percent, 64, layout_info.min_percent, layout_info.preferred, layout_info.stretch); }()) ), slint::cbindgen_private::LayoutItemInfo ( [&](const auto &a_0){ slint::cbindgen_private::LayoutItemInfo o{}; o.constraint = a_0; return o; }(slint::private_api::item_layout_info(SLINT_GET_ITEM_VTABLE(FlickableVTable), const_cast<slint::cbindgen_private::Flickable*>(&self->field_grid_area_69), slint::cbindgen_private::Orientation::Vertical, -1, &self->globals->window().window_handle(), self->self_weak.lock()->into_dyn(), self->tree_index_of_first_child + 2 - 1)) ) }.data(), 2),0,[&](const auto &a_0, const auto &a_1){ slint::cbindgen_private::Padding o{}; o.begin = a_0; o.end = a_1; return o; }(0, 0),slint::cbindgen_private::LayoutAlignment::Stretch);
                        });
    self->field_empty_58_rectangle_59_height.set(64);
    self->field_empty_58_rectangle_59_layoutinfo_v.set_binding([this]() {
                            [[maybe_unused]] auto self = this;
                            return ([&](const auto &a_0, const auto &a_1, const auto &a_2, const auto &a_3, const auto &a_4, const auto &a_5){ slint::cbindgen_private::LayoutInfo o{}; o.max = a_0; o.max_percent = a_1; o.min = a_2; o.min_percent = a_3; o.preferred = a_4; o.stretch = a_5; return o; }(+3.4028234663852886e38, 100, 0, 0, 0, 1) + self->field_empty_58_empty_60_layoutinfo_v.get());
                        });
    self->field_empty_58_rectangle_59_width.set_binding([this]() {
                            [[maybe_unused]] auto self = this;
                            return slint::private_api::optional_or_default(slint::private_api::optional_transform(self->parent.lock(), [&](auto&&x) { return x->field_root_57.width.get(); }));
                        });
    self->field_empty_58_textinput_68_accessible_action_set_value.set_handler(
                [this]([[maybe_unused]] slint::SharedString arg_0) {
                    [[maybe_unused]] auto self = this;
                    [&]{ self->field_textinput_68.text.set(arg_0);self->field_textinput_68.edited.call(); }();
                });
    self->field_empty_58_width.set_binding([this]() {
                            [[maybe_unused]] auto self = this;
                            return slint::private_api::optional_or_default(slint::private_api::optional_transform(self->parent.lock(), [&](auto&&x) { return x->field_root_57.width.get(); }));
                        });
    self->field_rectangle_59.background.set(slint::Brush(slint::Color::from_argb_encoded(+4.279769125e9)));
    self->field_rectangle_59.border_color.set(slint::Brush(slint::Color::from_argb_encoded(+4.281414212e9)));
    self->field_rectangle_59.border_width.set(1);
    self->field_text_62.color.set_binding([this]() {
                            [[maybe_unused]] auto self = this;
                            return self->globals->global_FluentPalette_78->field_foreground.get();
                        });
    self->field_text_62.font_size.set(22);
    self->field_text_62.height.set(64);
    self->field_text_62.text.set(slint::SharedString(u8"\U0001f427"));
    self->field_text_62.vertical_alignment.set(slint::cbindgen_private::TextVerticalAlignment::Center);
    self->field_text_62.width.set_binding([this]() {
                            [[maybe_unused]] auto self = this;
                            return self->field_empty_58_empty_61_layout_cache.get()[1];
                        });
    self->field_text_64.color.set(slint::Brush(slint::Color::from_argb_encoded(+4.287214842e9)));
    self->field_text_64.font_size.set(18);
    self->field_text_64.font_weight.set(static_cast<int>(700));
    self->field_text_64.height.set_binding([this]() {
                            [[maybe_unused]] auto self = this;
                            return self->field_empty_58_empty_63_layout_cache.get()[1];
                        });
    self->field_text_64.text.set(slint::SharedString(u8"Tux Store"));
    self->field_text_64.width.set_binding([this]() {
                            [[maybe_unused]] auto self = this;
                            return self->field_empty_58_empty_61_layout_cache.get()[3];
                        });
    self->field_text_65.color.set(slint::Brush(slint::Color::from_argb_encoded(+4.2865471e9)));
    self->field_text_65.font_size.set(11);
    self->field_text_65.height.set_binding([this]() {
                            [[maybe_unused]] auto self = this;
                            return self->field_empty_58_empty_63_layout_cache.get()[3];
                        });
    self->field_text_65.text.set(slint::SharedString(u8"for Arch Linux"));
    self->field_text_65.width.set_binding([this]() {
                            [[maybe_unused]] auto self = this;
                            return self->field_empty_58_empty_61_layout_cache.get()[3];
                        });
    self->field_rectangle_66.background.set(slint::Brush(slint::Color::from_argb_encoded(+4.281414212e9)));
    self->field_rectangle_66.border_color.set(slint::Brush(slint::Color::from_argb_encoded(+4.28273033e9)));
    self->field_rectangle_66.border_radius.set(10);
    self->field_rectangle_66.border_width.set(1);
    self->field_textinput_68.accepted.set_handler(
                [this]() {
                    [[maybe_unused]] auto self = this;
                    slint::private_api::optional_then(self->parent.lock(), [&](auto&&x) { x->field_root_57_search_changed.call(self->field_textinput_68.text.get()); });
                });
    self->field_textinput_68.color.set(slint::Brush(slint::Color::from_argb_encoded(+4.291679988e9)));
    self->field_textinput_68.enabled.set(true);
    self->field_textinput_68.font_size.set(13);
    self->field_textinput_68.height.set(36);
    self->field_textinput_68.read_only.set(false);
    self->field_textinput_68.selection_background_color.set_binding([this]() {
                            [[maybe_unused]] auto self = this;
                            return self->globals->global_FluentPalette_78->field_selection_background.get().color();
                        });
    self->field_textinput_68.selection_foreground_color.set_binding([this]() {
                            [[maybe_unused]] auto self = this;
                            return self->globals->global_FluentPalette_78->field_selection_foreground.get().color();
                        });
    self->field_textinput_68.single_line.set(true);
    self->field_textinput_68.text.set_binding([this]() {
                            [[maybe_unused]] auto self = this;
                            return slint::private_api::optional_or_default(slint::private_api::optional_transform(self->parent.lock(), [&](auto&&x) { return x->field_root_57_search_query.get(); }));
                        });
    self->field_textinput_68.text_cursor_width.set(1);
    self->field_textinput_68.vertical_alignment.set(slint::cbindgen_private::TextVerticalAlignment::Center);
    self->field_textinput_68.width.set_binding([this]() {
                            [[maybe_unused]] auto self = this;
                            return self->field_empty_58_empty_67_layout_cache.get()[1];
                        });
    self->field_grid_area_69.interactive.set(true);
    self->field_grid_area_69.viewport_height.set_binding([this]() {
                            [[maybe_unused]] auto self = this;
                            return std::max<float>(self->field_empty_58_layout_cache.get()[3], (24 + (self->field_empty_58_grid_area_69_total_rows.get() * 196)));
                        });
    self->field_grid_area_69.viewport_width.set_binding([this]() {
                            [[maybe_unused]] auto self = this;
                            return slint::private_api::optional_or_default(slint::private_api::optional_transform(self->parent.lock(), [&](auto&&x) { return x->field_root_57.width.get(); }));
                        });
    self->field_empty_58_rectangle_59_height.set_constant();
    self->field_rectangle_59.background.set_constant();
    self->field_rectangle_59.border_color.set_constant();
    self->field_rectangle_59.border_radius.set_constant();
    self->field_rectangle_59.border_width.set_constant();
    self->field_text_62.font_size.set_constant();
    self->field_text_62.font_weight.set_constant();
    self->field_text_62.height.set_constant();
    self->field_text_62.horizontal_alignment.set_constant();
    self->field_text_62.text.set_constant();
    self->field_text_62.vertical_alignment.set_constant();
    self->field_text_64.color.set_constant();
    self->field_text_64.font_size.set_constant();
    self->field_text_64.font_weight.set_constant();
    self->field_text_64.horizontal_alignment.set_constant();
    self->field_text_64.text.set_constant();
    self->field_text_64.vertical_alignment.set_constant();
    self->field_text_65.color.set_constant();
    self->field_text_65.font_size.set_constant();
    self->field_text_65.font_weight.set_constant();
    self->field_text_65.horizontal_alignment.set_constant();
    self->field_text_65.text.set_constant();
    self->field_text_65.vertical_alignment.set_constant();
    self->field_rectangle_66.background.set_constant();
    self->field_rectangle_66.border_color.set_constant();
    self->field_rectangle_66.border_radius.set_constant();
    self->field_rectangle_66.border_width.set_constant();
    self->field_textinput_68.color.set_constant();
    self->field_textinput_68.enabled.set_constant();
    self->field_textinput_68.font_family.set_constant();
    self->field_textinput_68.font_italic.set_constant();
    self->field_textinput_68.font_size.set_constant();
    self->field_textinput_68.font_weight.set_constant();
    self->field_textinput_68.height.set_constant();
    self->field_textinput_68.horizontal_alignment.set_constant();
    self->field_textinput_68.input_type.set_constant();
    self->field_textinput_68.letter_spacing.set_constant();
    self->field_textinput_68.page_height.set_constant();
    self->field_textinput_68.read_only.set_constant();
    self->field_textinput_68.single_line.set_constant();
    self->field_textinput_68.text_cursor_width.set_constant();
    self->field_textinput_68.vertical_alignment.set_constant();
    self->field_textinput_68.wrap.set_constant();
    self->field_grid_area_69.interactive.set_constant();
    self->repeater_0.set_model_binding([self] { (void)self; return slint::private_api::optional_or_default(slint::private_api::optional_transform(self->parent.lock(), [&](auto&&x) { return x->field_root_57_packages.get(); })); });
}

auto Component_empty_58::user_init () -> void{
    [[maybe_unused]] auto self = this;
}

auto Component_empty_58::layout_info (slint::cbindgen_private::Orientation o) const -> slint::cbindgen_private::LayoutInfo{
    [[maybe_unused]] auto self = this;
    return o == slint::cbindgen_private::Orientation::Horizontal ? self->field_empty_58_layoutinfo_h.get() : self->field_empty_58_layoutinfo_v.get();
}

auto Component_empty_58::item_geometry (uint32_t index) const -> slint::cbindgen_private::Rect{
    [[maybe_unused]] auto self = this;
    switch (index) {
        case 0: return slint::private_api::convert_anonymous_rect(std::make_tuple(float(slint::private_api::optional_or_default(slint::private_api::optional_transform(self->parent.lock(), [&](auto&&x) { return x->field_root_57.height.get(); }))), float(slint::private_api::optional_or_default(slint::private_api::optional_transform(self->parent.lock(), [&](auto&&x) { return x->field_root_57.width.get(); }))), float(0), float(0)));
        case 1: return slint::private_api::convert_anonymous_rect(std::make_tuple(float(64), float(slint::private_api::optional_or_default(slint::private_api::optional_transform(self->parent.lock(), [&](auto&&x) { return x->field_root_57.width.get(); }))), float(0), float(self->field_empty_58_layout_cache.get()[0])));
        case 2: return slint::private_api::convert_anonymous_rect(std::make_tuple(float(self->field_empty_58_layout_cache.get()[3]), float(slint::private_api::optional_or_default(slint::private_api::optional_transform(self->parent.lock(), [&](auto&&x) { return x->field_root_57.width.get(); }))), float(0), float(self->field_empty_58_layout_cache.get()[2])));
        case 3: return slint::private_api::convert_anonymous_rect(std::make_tuple(float(64), float(self->field_empty_58_empty_60_layout_cache.get()[1]), float(self->field_empty_58_empty_60_layout_cache.get()[0]), float(0)));
        case 4: return slint::private_api::convert_anonymous_rect(std::make_tuple(float(36), float(260), float(self->field_empty_58_empty_60_layout_cache.get()[2]), float(14)));
        case 5: return slint::private_api::convert_anonymous_rect(std::make_tuple(float(64), float(self->field_empty_58_empty_61_layout_cache.get()[1]), float(self->field_empty_58_empty_61_layout_cache.get()[0]), float(0)));
        case 6: return slint::private_api::convert_anonymous_rect(std::make_tuple(float(64), float(self->field_empty_58_empty_61_layout_cache.get()[3]), float(self->field_empty_58_empty_61_layout_cache.get()[2]), float(0)));
        case 7: return slint::private_api::convert_anonymous_rect(std::make_tuple(float(self->field_empty_58_empty_63_layout_cache.get()[1]), float(self->field_empty_58_empty_61_layout_cache.get()[3]), float(0), float(self->field_empty_58_empty_63_layout_cache.get()[0])));
        case 8: return slint::private_api::convert_anonymous_rect(std::make_tuple(float(self->field_empty_58_empty_63_layout_cache.get()[3]), float(self->field_empty_58_empty_61_layout_cache.get()[3]), float(0), float(self->field_empty_58_empty_63_layout_cache.get()[2])));
        case 9: return slint::private_api::convert_anonymous_rect(std::make_tuple(float(36), float(self->field_empty_58_empty_67_layout_cache.get()[1]), float(self->field_empty_58_empty_67_layout_cache.get()[0]), float(0)));
        case 10: return slint::private_api::convert_anonymous_rect(std::make_tuple(float(self->field_grid_area_69.viewport_height.get()), float(self->field_grid_area_69.viewport_width.get()), float(self->field_grid_area_69.viewport_x.get()), float(self->field_grid_area_69.viewport_y.get())));
    }
    return {};
}

auto Component_empty_58::accessible_role (uint32_t index) const -> slint::cbindgen_private::AccessibleRole{
    [[maybe_unused]] auto self = this;
    switch (index) {
        case 5: return slint::cbindgen_private::AccessibleRole::Text;
        case 7: return slint::cbindgen_private::AccessibleRole::Text;
        case 8: return slint::cbindgen_private::AccessibleRole::Text;
        case 9: return slint::cbindgen_private::AccessibleRole::TextInput;
    }
    return {};
}

auto Component_empty_58::accessible_string_property (uint32_t index, slint::cbindgen_private::AccessibleStringProperty what) const -> std::optional<slint::SharedString>{
    [[maybe_unused]] auto self = this;
    switch ((index << 8) | uintptr_t(what)) {
        case (5 << 8) | uintptr_t(slint::cbindgen_private::AccessibleStringProperty::Label): return slint::SharedString(u8"\U0001f427");
        case (7 << 8) | uintptr_t(slint::cbindgen_private::AccessibleStringProperty::Label): return slint::SharedString(u8"Tux Store");
        case (8 << 8) | uintptr_t(slint::cbindgen_private::AccessibleStringProperty::Label): return slint::SharedString(u8"for Arch Linux");
        case (9 << 8) | uintptr_t(slint::cbindgen_private::AccessibleStringProperty::Enabled): return (true ? slint::SharedString(u8"true") : slint::SharedString(u8"false"));
        case (9 << 8) | uintptr_t(slint::cbindgen_private::AccessibleStringProperty::ReadOnly): return (false ? slint::SharedString(u8"true") : slint::SharedString(u8"false"));
        case (9 << 8) | uintptr_t(slint::cbindgen_private::AccessibleStringProperty::Value): return self->field_textinput_68.text.get();
    }
    return {};
}

auto Component_empty_58::accessibility_action (uint32_t index, const slint::cbindgen_private::AccessibilityAction &action) const -> void{
    [[maybe_unused]] auto self = this;
    switch ((index << 8) | uintptr_t(action.tag)) {
        case (9 << 8) | uintptr_t(slint::cbindgen_private::AccessibilityAction::Tag::SetValue): { auto arg_0 = action.set_value._0; return self->field_empty_58_textinput_68_accessible_action_set_value.call(arg_0); }
    }
    return ;
}

auto Component_empty_58::supported_accessibility_actions (uint32_t index) const -> uint32_t{
    [[maybe_unused]] auto self = this;
    switch (index) {
        case 9: return slint::cbindgen_private::SupportedAccessibilityAction_SetValue;
    }
    return {};
}

auto Component_empty_58::element_infos (uint32_t index) const -> std::optional<slint::SharedString>{
    [[maybe_unused]] auto self = this;
    switch (index) {
    }
    return {};
}

auto Component_empty_58::ensure_instantiated () const -> bool{
    [[maybe_unused]] auto self = this;
    bool _changed = false;
    _changed |= self->repeater_0.ensure_updated(self);
    return _changed;
}

auto Component_empty_58::visit_dynamic_children (uint32_t dyn_index, [[maybe_unused]] slint::private_api::TraversalOrder order, [[maybe_unused]] slint::private_api::ItemVisitorRefMut visitor) const -> uint64_t{
        auto self = this;
        switch(dyn_index) { 
        case 0: {
                return self->repeater_0.visit(order, visitor);
            } };
        std::abort();
}

auto Component_empty_58::subtree_range (uintptr_t dyn_index) const -> slint::private_api::IndexRange{
    [[maybe_unused]] auto self = this;
        switch(dyn_index) { 
        case 0: {
                self->repeater_0.track_instance_changes();
                return self->repeater_0.index_range();
            } };
        std::abort();
}

auto Component_empty_58::subtree_component (uintptr_t dyn_index, [[maybe_unused]] uintptr_t subtree_index, [[maybe_unused]] slint::private_api::ItemTreeWeak *result) const -> void{
    [[maybe_unused]] auto self = this;
        switch(dyn_index) { 
        case 0: {
                *result = self->repeater_0.instance_at(subtree_index);
                return;
            } };
        std::abort();
}

auto Component_empty_58::visit_children (slint::private_api::ItemTreeRef component, intptr_t index, slint::private_api::TraversalOrder order, slint::private_api::ItemVisitorRefMut visitor) -> uint64_t{
    static const auto dyn_visit = [] (const void *base,  [[maybe_unused]] slint::private_api::TraversalOrder order, [[maybe_unused]] slint::private_api::ItemVisitorRefMut visitor, [[maybe_unused]] uint32_t dyn_index) -> uint64_t {
        [[maybe_unused]] auto self = reinterpret_cast<const Component_empty_58*>(base);
        return self->visit_dynamic_children(dyn_index, order, visitor);
    };
    auto self_rc = reinterpret_cast<const Component_empty_58*>(component.instance)->self_weak.lock()->into_dyn();
    return slint::cbindgen_private::slint_visit_item_tree(&self_rc, get_item_tree(component) , index, order, visitor, dyn_visit);
}

auto Component_empty_58::get_item_ref (slint::private_api::ItemTreeRef component, uint32_t index) -> slint::private_api::ItemRef{
    return slint::private_api::get_item_ref(component, get_item_tree(component), item_array(), index);
}

auto Component_empty_58::get_subtree_range ([[maybe_unused]] slint::private_api::ItemTreeRef component, [[maybe_unused]] uint32_t dyn_index) -> slint::private_api::IndexRange{
    auto self = reinterpret_cast<const Component_empty_58*>(component.instance);
    return self->subtree_range(dyn_index);
}

auto Component_empty_58::get_subtree ([[maybe_unused]] slint::private_api::ItemTreeRef component, [[maybe_unused]] uint32_t dyn_index, [[maybe_unused]] uintptr_t subtree_index, [[maybe_unused]] slint::private_api::ItemTreeWeak *result) -> void{
    auto self = reinterpret_cast<const Component_empty_58*>(component.instance);
    self->subtree_component(dyn_index, subtree_index, result);
}

auto Component_empty_58::get_item_tree (slint::private_api::ItemTreeRef) -> slint::cbindgen_private::Slice<slint::private_api::ItemTreeNode>{
    return item_tree();
}

auto Component_empty_58::parent_node ([[maybe_unused]] slint::private_api::ItemTreeRef component, [[maybe_unused]] slint::private_api::ItemWeak *result) -> void{
    auto self = reinterpret_cast<const Component_empty_58*>(component.instance);
    auto parent = self->parent.lock().value();
    *result = { parent->self_weak, parent->tree_index_of_first_child + 0 };
}

auto Component_empty_58::embed_component ([[maybe_unused]] slint::private_api::ItemTreeRef component, [[maybe_unused]] const slint::private_api::ItemTreeWeak *parent_component, [[maybe_unused]] const uint32_t parent_index) -> bool{
    return false; /* todo! */
}

auto Component_empty_58::subtree_index ([[maybe_unused]] slint::private_api::ItemTreeRef component) -> uintptr_t{
    return std::numeric_limits<uintptr_t>::max();
}

auto Component_empty_58::item_tree () -> slint::cbindgen_private::Slice<slint::private_api::ItemTreeNode>{
    static const slint::private_api::ItemTreeNode children[] {
        slint::private_api::make_item_node(2, 1, 0, 0, false), 
slint::private_api::make_item_node(2, 3, 0, 1, false), 
slint::private_api::make_item_node(1, 10, 0, 2, false), 
slint::private_api::make_item_node(2, 5, 1, 3, false), 
slint::private_api::make_item_node(1, 9, 1, 4, false), 
slint::private_api::make_item_node(0, 7, 3, 5, true), 
slint::private_api::make_item_node(2, 7, 3, 6, false), 
slint::private_api::make_item_node(0, 9, 6, 7, true), 
slint::private_api::make_item_node(0, 9, 6, 8, true), 
slint::private_api::make_item_node(0, 10, 4, 9, true), 
slint::private_api::make_item_node(1, 11, 2, 10, false), 
slint::private_api::make_dyn_node(0, 10) };
    return slint::private_api::make_slice(std::span(children));
}

auto Component_empty_58::item_array () -> const slint::private_api::ItemArray{
    static const slint::private_api::ItemArrayEntry items[] {
        { SLINT_GET_ITEM_VTABLE(EmptyVTable),  offsetof(Component_empty_58, field_empty_58) }, 
{ SLINT_GET_ITEM_VTABLE(BasicBorderRectangleVTable),  offsetof(Component_empty_58, field_rectangle_59) }, 
{ SLINT_GET_ITEM_VTABLE(FlickableVTable),  offsetof(Component_empty_58, field_grid_area_69) }, 
{ SLINT_GET_ITEM_VTABLE(EmptyVTable),  offsetof(Component_empty_58, field_empty_61) }, 
{ SLINT_GET_ITEM_VTABLE(BasicBorderRectangleVTable),  offsetof(Component_empty_58, field_rectangle_66) }, 
{ SLINT_GET_ITEM_VTABLE(SimpleTextVTable),  offsetof(Component_empty_58, field_text_62) }, 
{ SLINT_GET_ITEM_VTABLE(EmptyVTable),  offsetof(Component_empty_58, field_empty_63) }, 
{ SLINT_GET_ITEM_VTABLE(SimpleTextVTable),  offsetof(Component_empty_58, field_text_64) }, 
{ SLINT_GET_ITEM_VTABLE(SimpleTextVTable),  offsetof(Component_empty_58, field_text_65) }, 
{ SLINT_GET_ITEM_VTABLE(TextInputVTable),  offsetof(Component_empty_58, field_textinput_68) }, 
{ SLINT_GET_ITEM_VTABLE(EmptyVTable),  offsetof(Component_empty_58, field_grid_area_viewport_70) } };
    return slint::private_api::make_slice(std::span(items));
}

auto Component_empty_58::layout_info ([[maybe_unused]] slint::private_api::ItemTreeRef component, slint::cbindgen_private::Orientation o) -> slint::cbindgen_private::LayoutInfo{
    return reinterpret_cast<const Component_empty_58*>(component.instance)->layout_info(o);
}

auto Component_empty_58::ensure_instantiated ([[maybe_unused]] slint::private_api::ItemTreeRef component) -> bool{
    return reinterpret_cast<const Component_empty_58*>(component.instance)->ensure_instantiated();
}

auto Component_empty_58::item_geometry ([[maybe_unused]] slint::private_api::ItemTreeRef component, uint32_t index) -> slint::cbindgen_private::LogicalRect{
    return reinterpret_cast<const Component_empty_58*>(component.instance)->item_geometry(index);
}

auto Component_empty_58::accessible_role ([[maybe_unused]] slint::private_api::ItemTreeRef component, uint32_t index) -> slint::cbindgen_private::AccessibleRole{
    return reinterpret_cast<const Component_empty_58*>(component.instance)->accessible_role(index);
}

auto Component_empty_58::accessible_string_property ([[maybe_unused]] slint::private_api::ItemTreeRef component, uint32_t index, slint::cbindgen_private::AccessibleStringProperty what, slint::SharedString *result) -> bool{
    if (auto r = reinterpret_cast<const Component_empty_58*>(component.instance)->accessible_string_property(index, what)) { *result = *r; return true; } else { return false; }
}

auto Component_empty_58::accessibility_action ([[maybe_unused]] slint::private_api::ItemTreeRef component, uint32_t index, const slint::cbindgen_private::AccessibilityAction *action) -> void{
    reinterpret_cast<const Component_empty_58*>(component.instance)->accessibility_action(index, *action);
}

auto Component_empty_58::supported_accessibility_actions ([[maybe_unused]] slint::private_api::ItemTreeRef component, uint32_t index) -> uint32_t{
    return reinterpret_cast<const Component_empty_58*>(component.instance)->supported_accessibility_actions(index);
}

auto Component_empty_58::element_infos ([[maybe_unused]] slint::private_api::ItemTreeRef component, [[maybe_unused]] uint32_t index, [[maybe_unused]] slint::SharedString *result) -> bool{
    return false;
}

auto Component_empty_58::window_adapter ([[maybe_unused]] slint::private_api::ItemTreeRef component, [[maybe_unused]] bool do_create, [[maybe_unused]] slint::cbindgen_private::Option<slint::private_api::WindowAdapterRc>* result) -> void{
    *reinterpret_cast<slint::private_api::WindowAdapterRc*>(result) = reinterpret_cast<const Component_empty_58*>(component.instance)->globals->window().window_handle();
}

auto Component_empty_58::create (class MainWindow const * parent) -> slint::ComponentHandle<Component_empty_58>{
    auto self_rc = vtable::VRc<slint::private_api::ItemTreeVTable, Component_empty_58>::make();
    auto self = const_cast<Component_empty_58 *>(&*self_rc);
    self->self_weak = vtable::VWeak(self_rc).into_dyn();
    slint::private_api::register_item_tree(&self_rc.into_dyn(), parent->globals->m_window);
    self->init(parent->globals, self->self_weak, 0, 1 , parent);
    return slint::ComponentHandle<Component_empty_58>{ self_rc };
}

Component_empty_58::~Component_empty_58 (){
    if (auto &window = globals->m_window) window->window_handle().unregister_item_tree(this, item_array());
}

auto Component_empty_58::init () -> void{
    user_init();
}

auto Component_empty_58::layout_item_info (slint::cbindgen_private::Orientation o, [[maybe_unused]] std::optional<size_t> child_index) const -> slint::cbindgen_private::LayoutItemInfo{
    return { layout_info({&static_vtable, const_cast<void *>(static_cast<const void *>(this))}, o) };
}

auto Component_empty_58::flexbox_layout_item_info (slint::cbindgen_private::Orientation o, [[maybe_unused]] std::optional<size_t> child_index) const -> slint::cbindgen_private::FlexboxLayoutItemInfo{
    auto base = layout_item_info(o, child_index); return { base.constraint, 0.0f, 0.0f, -1.0f, slint::cbindgen_private::FlexboxLayoutAlignSelf::Auto, 0 };
}

const slint::private_api::ItemTreeVTable Component_detailsview_74::static_vtable = { visit_children, get_item_ref, get_subtree_range, get_subtree, get_item_tree, parent_node, embed_component, subtree_index, layout_info, ensure_instantiated, item_geometry, accessible_role, accessible_string_property, accessibility_action, supported_accessibility_actions, element_infos, window_adapter, slint::private_api::drop_in_place<Component_detailsview_74>, slint::private_api::dealloc };

auto Component_detailsview_74::init (const class SharedGlobals* globals,slint::cbindgen_private::ItemTreeWeak enclosing_component,uint32_t tree_index,uint32_t tree_index_of_first_child,class MainWindow const *parent) -> void{
    auto self = this;
    self->self_weak = enclosing_component;
    self->globals = globals;
    this->tree_index_of_first_child = tree_index_of_first_child;
    self->tree_index = tree_index;
    self->parent = vtable::VRcMapped<slint::private_api::ItemTreeVTable, const MainWindow>(parent->self_weak.lock().value(), parent);
    this->field_detailsview_74.init(globals, self_weak.into_dyn(), tree_index, tree_index_of_first_child + 1 - 1);
    self->field_detailsview_74.field_root_14_accent_idx.set(static_cast<int>(0));
    self->field_detailsview_74.field_root_14_back_clicked.set_handler(
                [this]() {
                    [[maybe_unused]] auto self = this;
                    slint::private_api::optional_then(self->parent.lock(), [&](auto&&x) { x->field_root_57_back_clicked.call(); });
                });
    self->field_detailsview_74.field_root_14_details.set_binding([this]() {
                            [[maybe_unused]] auto self = this;
                            return slint::private_api::optional_or_default(slint::private_api::optional_transform(self->parent.lock(), [&](auto&&x) { return x->field_root_57_current_details.get(); }));
                        });
    self->field_detailsview_74.field_root_14_height.set_binding([this]() {
                            [[maybe_unused]] auto self = this;
                            return slint::private_api::optional_or_default(slint::private_api::optional_transform(self->parent.lock(), [&](auto&&x) { return x->field_root_57.height.get(); }));
                        });
    self->field_detailsview_74.field_root_14_install_clicked.set_handler(
                [this]() {
                    [[maybe_unused]] auto self = this;
                    slint::private_api::optional_then(self->parent.lock(), [&](auto&&x) { x->field_root_57_install_clicked.call(slint::private_api::optional_or_default(slint::private_api::optional_transform(self->parent.lock(), [&](auto&&x) { return x->field_root_57_current_package.get(); }))); });
                });
    self->field_detailsview_74.field_root_14_pkg.set_binding([this]() {
                            [[maybe_unused]] auto self = this;
                            return slint::private_api::optional_or_default(slint::private_api::optional_transform(self->parent.lock(), [&](auto&&x) { return x->field_root_57_current_package.get(); }));
                        });
    self->field_detailsview_74.field_root_14_remove_clicked.set_handler(
                [this]() {
                    [[maybe_unused]] auto self = this;
                    slint::private_api::optional_then(self->parent.lock(), [&](auto&&x) { x->field_root_57_remove_clicked.call(slint::private_api::optional_or_default(slint::private_api::optional_transform(self->parent.lock(), [&](auto&&x) { return x->field_root_57_current_package.get(); }))); });
                });
    self->field_detailsview_74.field_root_14_width.set_binding([this]() {
                            [[maybe_unused]] auto self = this;
                            return slint::private_api::optional_or_default(slint::private_api::optional_transform(self->parent.lock(), [&](auto&&x) { return x->field_root_57.width.get(); }));
                        });
    self->field_detailsview_74.field_root_14_accent_idx.set_constant();
    self->field_detailsview_74.field_root_14.background.set_constant();
    self->field_detailsview_74.field_root_14_empty_17_padding_bottom.set_constant();
    self->field_detailsview_74.field_root_14_empty_17_padding_top.set_constant();
    self->field_detailsview_74.field_root_14_empty_17_spacing.set_constant();
    self->field_detailsview_74.field_root_14_rectangle_30_height.set_constant();
}

auto Component_detailsview_74::user_init () -> void{
    [[maybe_unused]] auto self = this;
    this->field_detailsview_74.user_init();
}

auto Component_detailsview_74::layout_info (slint::cbindgen_private::Orientation o) const -> slint::cbindgen_private::LayoutInfo{
    [[maybe_unused]] auto self = this;
    return o == slint::cbindgen_private::Orientation::Horizontal ? self->field_detailsview_74.field_root_14_layoutinfo_h.get() : self->field_detailsview_74.field_root_14_layoutinfo_v.get();
}

auto Component_detailsview_74::item_geometry (uint32_t index) const -> slint::cbindgen_private::Rect{
    [[maybe_unused]] auto self = this;
    switch (index) {
        case 0: return slint::private_api::convert_anonymous_rect(std::make_tuple(float(slint::private_api::optional_or_default(slint::private_api::optional_transform(self->parent.lock(), [&](auto&&x) { return x->field_root_57.height.get(); }))), float(slint::private_api::optional_or_default(slint::private_api::optional_transform(self->parent.lock(), [&](auto&&x) { return x->field_root_57.width.get(); }))), float(0), float(0)));
    }
    if (index == 0) {
        return self->field_detailsview_74.item_geometry(0);
    } else if (index >= 1 && index < 21) {
        return self->field_detailsview_74.item_geometry(index - 0);
    } else return {};
}

auto Component_detailsview_74::accessible_role (uint32_t index) const -> slint::cbindgen_private::AccessibleRole{
    [[maybe_unused]] auto self = this;
    switch (index) {
    }
    if (index == 0) {
        return self->field_detailsview_74.accessible_role(0);
    } else if (index >= 1 && index < 21) {
        return self->field_detailsview_74.accessible_role(index - 0);
    } else return {};
}

auto Component_detailsview_74::accessible_string_property (uint32_t index, slint::cbindgen_private::AccessibleStringProperty what) const -> std::optional<slint::SharedString>{
    [[maybe_unused]] auto self = this;
    switch ((index << 8) | uintptr_t(what)) {
    }
    if (index == 0) {
        return self->field_detailsview_74.accessible_string_property(0, what);
    } else if (index >= 1 && index < 21) {
        return self->field_detailsview_74.accessible_string_property(index - 0, what);
    } else return {};
}

auto Component_detailsview_74::accessibility_action (uint32_t index, const slint::cbindgen_private::AccessibilityAction &action) const -> void{
    [[maybe_unused]] auto self = this;
    switch ((index << 8) | uintptr_t(action.tag)) {
    }
    if (index == 0) {
        return self->field_detailsview_74.accessibility_action(0, action);
    } else if (index >= 1 && index < 21) {
        return self->field_detailsview_74.accessibility_action(index - 0, action);
    } else return ;
}

auto Component_detailsview_74::supported_accessibility_actions (uint32_t index) const -> uint32_t{
    [[maybe_unused]] auto self = this;
    switch (index) {
    }
    if (index == 0) {
        return self->field_detailsview_74.supported_accessibility_actions(0);
    } else if (index >= 1 && index < 21) {
        return self->field_detailsview_74.supported_accessibility_actions(index - 0);
    } else return {};
}

auto Component_detailsview_74::element_infos (uint32_t index) const -> std::optional<slint::SharedString>{
    [[maybe_unused]] auto self = this;
    switch (index) {
    }
    if (index == 0) {
        return self->field_detailsview_74.element_infos(0);
    } else if (index >= 1 && index < 21) {
        return self->field_detailsview_74.element_infos(index - 0);
    } else return {};
}

auto Component_detailsview_74::ensure_instantiated () const -> bool{
    [[maybe_unused]] auto self = this;
    bool _changed = false;
    _changed |= self->field_detailsview_74.ensure_instantiated();
    return _changed;
}

auto Component_detailsview_74::visit_dynamic_children (uint32_t dyn_index, [[maybe_unused]] slint::private_api::TraversalOrder order, [[maybe_unused]] slint::private_api::ItemVisitorRefMut visitor) const -> uint64_t{
        auto self = this;
        switch(dyn_index) { 
        case 0: case 1: case 2: case 3:  {
                        return self->field_detailsview_74.visit_dynamic_children(dyn_index - 0, order, visitor);
                    } };
        std::abort();
}

auto Component_detailsview_74::subtree_range (uintptr_t dyn_index) const -> slint::private_api::IndexRange{
    [[maybe_unused]] auto self = this;
        switch(dyn_index) { 
        case 0: case 1: case 2: case 3:  {
                        return self->field_detailsview_74.subtree_range(dyn_index - 0);
                    } };
        std::abort();
}

auto Component_detailsview_74::subtree_component (uintptr_t dyn_index, [[maybe_unused]] uintptr_t subtree_index, [[maybe_unused]] slint::private_api::ItemTreeWeak *result) const -> void{
    [[maybe_unused]] auto self = this;
        switch(dyn_index) { 
        case 0: case 1: case 2: case 3:  {
                        self->field_detailsview_74.subtree_component(dyn_index - 0, subtree_index, result);
                        return;
                    } };
        std::abort();
}

auto Component_detailsview_74::visit_children (slint::private_api::ItemTreeRef component, intptr_t index, slint::private_api::TraversalOrder order, slint::private_api::ItemVisitorRefMut visitor) -> uint64_t{
    static const auto dyn_visit = [] (const void *base,  [[maybe_unused]] slint::private_api::TraversalOrder order, [[maybe_unused]] slint::private_api::ItemVisitorRefMut visitor, [[maybe_unused]] uint32_t dyn_index) -> uint64_t {
        [[maybe_unused]] auto self = reinterpret_cast<const Component_detailsview_74*>(base);
        return self->visit_dynamic_children(dyn_index, order, visitor);
    };
    auto self_rc = reinterpret_cast<const Component_detailsview_74*>(component.instance)->self_weak.lock()->into_dyn();
    return slint::cbindgen_private::slint_visit_item_tree(&self_rc, get_item_tree(component) , index, order, visitor, dyn_visit);
}

auto Component_detailsview_74::get_item_ref (slint::private_api::ItemTreeRef component, uint32_t index) -> slint::private_api::ItemRef{
    return slint::private_api::get_item_ref(component, get_item_tree(component), item_array(), index);
}

auto Component_detailsview_74::get_subtree_range ([[maybe_unused]] slint::private_api::ItemTreeRef component, [[maybe_unused]] uint32_t dyn_index) -> slint::private_api::IndexRange{
    auto self = reinterpret_cast<const Component_detailsview_74*>(component.instance);
    return self->subtree_range(dyn_index);
}

auto Component_detailsview_74::get_subtree ([[maybe_unused]] slint::private_api::ItemTreeRef component, [[maybe_unused]] uint32_t dyn_index, [[maybe_unused]] uintptr_t subtree_index, [[maybe_unused]] slint::private_api::ItemTreeWeak *result) -> void{
    auto self = reinterpret_cast<const Component_detailsview_74*>(component.instance);
    self->subtree_component(dyn_index, subtree_index, result);
}

auto Component_detailsview_74::get_item_tree (slint::private_api::ItemTreeRef) -> slint::cbindgen_private::Slice<slint::private_api::ItemTreeNode>{
    return item_tree();
}

auto Component_detailsview_74::parent_node ([[maybe_unused]] slint::private_api::ItemTreeRef component, [[maybe_unused]] slint::private_api::ItemWeak *result) -> void{
    auto self = reinterpret_cast<const Component_detailsview_74*>(component.instance);
    auto parent = self->parent.lock().value();
    *result = { parent->self_weak, parent->tree_index_of_first_child + 1 };
}

auto Component_detailsview_74::embed_component ([[maybe_unused]] slint::private_api::ItemTreeRef component, [[maybe_unused]] const slint::private_api::ItemTreeWeak *parent_component, [[maybe_unused]] const uint32_t parent_index) -> bool{
    return false; /* todo! */
}

auto Component_detailsview_74::subtree_index ([[maybe_unused]] slint::private_api::ItemTreeRef component) -> uintptr_t{
    return std::numeric_limits<uintptr_t>::max();
}

auto Component_detailsview_74::item_tree () -> slint::cbindgen_private::Slice<slint::private_api::ItemTreeNode>{
    static const slint::private_api::ItemTreeNode children[] {
        slint::private_api::make_item_node(2, 1, 0, 0, false), 
slint::private_api::make_item_node(1, 3, 0, 1, false), 
slint::private_api::make_item_node(2, 19, 0, 2, false), 
slint::private_api::make_item_node(4, 4, 1, 3, false), 
slint::private_api::make_item_node(3, 8, 3, 4, false), 
slint::private_api::make_item_node(0, 17, 3, 5, false), 
slint::private_api::make_item_node(0, 17, 3, 6, true), 
slint::private_api::make_item_node(2, 17, 3, 7, false), 
slint::private_api::make_dyn_node(0, 4), 
slint::private_api::make_dyn_node(1, 4), 
slint::private_api::make_item_node(3, 11, 4, 8, false), 
slint::private_api::make_item_node(0, 14, 10, 9, true), 
slint::private_api::make_item_node(0, 14, 10, 10, true), 
slint::private_api::make_item_node(1, 14, 10, 11, false), 
slint::private_api::make_item_node(2, 15, 13, 12, false), 
slint::private_api::make_item_node(0, 17, 14, 13, false), 
slint::private_api::make_item_node(0, 17, 14, 14, true), 
slint::private_api::make_dyn_node(2, 7), 
slint::private_api::make_dyn_node(3, 7), 
slint::private_api::make_item_node(0, 21, 2, 15, false), 
slint::private_api::make_item_node(0, 21, 2, 16, true) };
    return slint::private_api::make_slice(std::span(children));
}

auto Component_detailsview_74::item_array () -> const slint::private_api::ItemArray{
    static const slint::private_api::ItemArrayEntry items[] {
        { SLINT_GET_ITEM_VTABLE(RectangleVTable), offsetof(Component_detailsview_74, field_detailsview_74) +  offsetof(DetailsView_root_14, field_root_14) }, 
{ SLINT_GET_ITEM_VTABLE(FlickableVTable), offsetof(Component_detailsview_74, field_detailsview_74) +  offsetof(DetailsView_root_14, field_flickable_15) }, 
{ SLINT_GET_ITEM_VTABLE(BasicBorderRectangleVTable), offsetof(Component_detailsview_74, field_detailsview_74) +  offsetof(DetailsView_root_14, field_rectangle_54) }, 
{ SLINT_GET_ITEM_VTABLE(EmptyVTable), offsetof(Component_detailsview_74, field_detailsview_74) +  offsetof(DetailsView_root_14, field__viewport_16) }, 
{ SLINT_GET_ITEM_VTABLE(EmptyVTable), offsetof(Component_detailsview_74, field_detailsview_74) +  offsetof(DetailsView_root_14, field_empty_18) }, 
{ SLINT_GET_ITEM_VTABLE(RectangleVTable), offsetof(Component_detailsview_74, field_detailsview_74) +  offsetof(DetailsView_root_14, field_rectangle_30) }, 
{ SLINT_GET_ITEM_VTABLE(ComplexTextVTable), offsetof(Component_detailsview_74, field_detailsview_74) +  offsetof(DetailsView_root_14, field_text_31) }, 
{ SLINT_GET_ITEM_VTABLE(BasicBorderRectangleVTable), offsetof(Component_detailsview_74, field_detailsview_74) +  offsetof(DetailsView_root_14, field_rectangle_32) }, 
{ SLINT_GET_ITEM_VTABLE(EmptyVTable), offsetof(Component_detailsview_74, field_detailsview_74) +  offsetof(DetailsView_root_14, field_empty_23) }, 
{ SLINT_GET_ITEM_VTABLE(ComplexTextVTable), offsetof(Component_detailsview_74, field_detailsview_74) +  offsetof(DetailsView_root_14, field_text_24) }, 
{ SLINT_GET_ITEM_VTABLE(SimpleTextVTable), offsetof(Component_detailsview_74, field_detailsview_74) +  offsetof(DetailsView_root_14, field_text_25) }, 
{ SLINT_GET_ITEM_VTABLE(EmptyVTable), offsetof(Component_detailsview_74, field_detailsview_74) +  offsetof(DetailsView_root_14, field_empty_26) }, 
{ SLINT_GET_ITEM_VTABLE(BasicBorderRectangleVTable), offsetof(Component_detailsview_74, field_detailsview_74) +  offsetof(DetailsView_root_14, field_rectangle_27) }, 
{ SLINT_GET_ITEM_VTABLE(TouchAreaVTable), offsetof(Component_detailsview_74, field_detailsview_74) +  offsetof(DetailsView_root_14, field_toucharea_28) }, 
{ SLINT_GET_ITEM_VTABLE(SimpleTextVTable), offsetof(Component_detailsview_74, field_detailsview_74) +  offsetof(DetailsView_root_14, field_text_29) }, 
{ SLINT_GET_ITEM_VTABLE(TouchAreaVTable), offsetof(Component_detailsview_74, field_detailsview_74) +  offsetof(DetailsView_root_14, field_btn_ta_55) }, 
{ SLINT_GET_ITEM_VTABLE(SimpleTextVTable), offsetof(Component_detailsview_74, field_detailsview_74) +  offsetof(DetailsView_root_14, field_text_56) } };
    return slint::private_api::make_slice(std::span(items));
}

auto Component_detailsview_74::layout_info ([[maybe_unused]] slint::private_api::ItemTreeRef component, slint::cbindgen_private::Orientation o) -> slint::cbindgen_private::LayoutInfo{
    return reinterpret_cast<const Component_detailsview_74*>(component.instance)->layout_info(o);
}

auto Component_detailsview_74::ensure_instantiated ([[maybe_unused]] slint::private_api::ItemTreeRef component) -> bool{
    return reinterpret_cast<const Component_detailsview_74*>(component.instance)->ensure_instantiated();
}

auto Component_detailsview_74::item_geometry ([[maybe_unused]] slint::private_api::ItemTreeRef component, uint32_t index) -> slint::cbindgen_private::LogicalRect{
    return reinterpret_cast<const Component_detailsview_74*>(component.instance)->item_geometry(index);
}

auto Component_detailsview_74::accessible_role ([[maybe_unused]] slint::private_api::ItemTreeRef component, uint32_t index) -> slint::cbindgen_private::AccessibleRole{
    return reinterpret_cast<const Component_detailsview_74*>(component.instance)->accessible_role(index);
}

auto Component_detailsview_74::accessible_string_property ([[maybe_unused]] slint::private_api::ItemTreeRef component, uint32_t index, slint::cbindgen_private::AccessibleStringProperty what, slint::SharedString *result) -> bool{
    if (auto r = reinterpret_cast<const Component_detailsview_74*>(component.instance)->accessible_string_property(index, what)) { *result = *r; return true; } else { return false; }
}

auto Component_detailsview_74::accessibility_action ([[maybe_unused]] slint::private_api::ItemTreeRef component, uint32_t index, const slint::cbindgen_private::AccessibilityAction *action) -> void{
    reinterpret_cast<const Component_detailsview_74*>(component.instance)->accessibility_action(index, *action);
}

auto Component_detailsview_74::supported_accessibility_actions ([[maybe_unused]] slint::private_api::ItemTreeRef component, uint32_t index) -> uint32_t{
    return reinterpret_cast<const Component_detailsview_74*>(component.instance)->supported_accessibility_actions(index);
}

auto Component_detailsview_74::element_infos ([[maybe_unused]] slint::private_api::ItemTreeRef component, [[maybe_unused]] uint32_t index, [[maybe_unused]] slint::SharedString *result) -> bool{
    return false;
}

auto Component_detailsview_74::window_adapter ([[maybe_unused]] slint::private_api::ItemTreeRef component, [[maybe_unused]] bool do_create, [[maybe_unused]] slint::cbindgen_private::Option<slint::private_api::WindowAdapterRc>* result) -> void{
    *reinterpret_cast<slint::private_api::WindowAdapterRc*>(result) = reinterpret_cast<const Component_detailsview_74*>(component.instance)->globals->window().window_handle();
}

auto Component_detailsview_74::create (class MainWindow const * parent) -> slint::ComponentHandle<Component_detailsview_74>{
    auto self_rc = vtable::VRc<slint::private_api::ItemTreeVTable, Component_detailsview_74>::make();
    auto self = const_cast<Component_detailsview_74 *>(&*self_rc);
    self->self_weak = vtable::VWeak(self_rc).into_dyn();
    slint::private_api::register_item_tree(&self_rc.into_dyn(), parent->globals->m_window);
    self->init(parent->globals, self->self_weak, 0, 1 , parent);
    return slint::ComponentHandle<Component_detailsview_74>{ self_rc };
}

Component_detailsview_74::~Component_detailsview_74 (){
    if (auto &window = globals->m_window) window->window_handle().unregister_item_tree(this, item_array());
}

auto Component_detailsview_74::init () -> void{
    user_init();
}

auto Component_detailsview_74::layout_item_info (slint::cbindgen_private::Orientation o, [[maybe_unused]] std::optional<size_t> child_index) const -> slint::cbindgen_private::LayoutItemInfo{
    return { layout_info({&static_vtable, const_cast<void *>(static_cast<const void *>(this))}, o) };
}

auto Component_detailsview_74::flexbox_layout_item_info (slint::cbindgen_private::Orientation o, [[maybe_unused]] std::optional<size_t> child_index) const -> slint::cbindgen_private::FlexboxLayoutItemInfo{
    auto base = layout_item_info(o, child_index); return { base.constraint, 0.0f, 0.0f, -1.0f, slint::cbindgen_private::FlexboxLayoutAlignSelf::Auto, 0 };
}

const slint::private_api::ItemTreeVTable MainWindow::static_vtable = { visit_children, get_item_ref, get_subtree_range, get_subtree, get_item_tree, parent_node, embed_component, subtree_index, layout_info, ensure_instantiated, item_geometry, accessible_role, accessible_string_property, accessibility_action, supported_accessibility_actions, element_infos, window_adapter, slint::private_api::drop_in_place<MainWindow>, slint::private_api::dealloc };

auto MainWindow::init (const class SharedGlobals* globals,slint::cbindgen_private::ItemTreeWeak enclosing_component,uint32_t tree_index,uint32_t tree_index_of_first_child) -> void{
    auto self = this;
    self->self_weak = enclosing_component;
    self->globals = globals;
    this->tree_index_of_first_child = tree_index_of_first_child;
    self->tree_index = tree_index;
    self->field_root_57.background.set(slint::Brush(slint::Color::from_argb_encoded(+4.280163886e9)));
    self->field_root_57_is_showing_details.set(false);
    self->field_root_57_packages.set_binding([this]() {
                            [[maybe_unused]] auto self = this;
                            return std::make_shared<slint::private_api::ArrayModel<0,UiPackage>>();
                        });
    self->field_root_57_search_query.set(slint::SharedString(u8""));
    self->field_root_57.title.set(slint::SharedString(u8"Tux Store"));
    self->field_root_57.always_on_top.set_constant();
    self->field_root_57.background.set_constant();
    self->field_root_57.default_font_family.set_constant();
    self->field_root_57.default_font_size.set_constant();
    self->field_root_57.default_font_weight.set_constant();
    self->field_root_57.icon.set_constant();
    self->field_root_57.no_frame.set_constant();
    self->field_root_57.resize_border_width.set_constant();
    self->field_root_57.title.set_constant();
    self->repeater_0.set_model_binding([self] { (void)self; return (! self->field_root_57_is_showing_details.get()); });
    self->repeater_1.set_model_binding([self] { (void)self; return self->field_root_57_is_showing_details.get(); });
}

auto MainWindow::user_init () -> void{
    [[maybe_unused]] auto self = this;
}

auto MainWindow::layout_info (slint::cbindgen_private::Orientation o) const -> slint::cbindgen_private::LayoutInfo{
    [[maybe_unused]] auto self = this;
    return o == slint::cbindgen_private::Orientation::Horizontal ? [&]{ [[maybe_unused]] auto layout_info = slint::private_api::item_layout_info(SLINT_GET_ITEM_VTABLE(WindowItemVTable), const_cast<slint::cbindgen_private::WindowItem*>(&self->field_root_57), slint::cbindgen_private::Orientation::Horizontal, -1, &self->globals->window().window_handle(), self->self_weak.lock()->into_dyn(), self->tree_index);;return [&](const auto &a_0, const auto &a_1, const auto &a_2, const auto &a_3, const auto &a_4, const auto &a_5){ slint::cbindgen_private::LayoutInfo o{}; o.max = a_0; o.max_percent = a_1; o.min = a_2; o.min_percent = a_3; o.preferred = a_4; o.stretch = a_5; return o; }(layout_info.max, layout_info.max_percent, layout_info.min, layout_info.min_percent, 1100, layout_info.stretch); }() : [&]{ [[maybe_unused]] auto layout_info = slint::private_api::item_layout_info(SLINT_GET_ITEM_VTABLE(WindowItemVTable), const_cast<slint::cbindgen_private::WindowItem*>(&self->field_root_57), slint::cbindgen_private::Orientation::Vertical, -1, &self->globals->window().window_handle(), self->self_weak.lock()->into_dyn(), self->tree_index);;return [&](const auto &a_0, const auto &a_1, const auto &a_2, const auto &a_3, const auto &a_4, const auto &a_5){ slint::cbindgen_private::LayoutInfo o{}; o.max = a_0; o.max_percent = a_1; o.min = a_2; o.min_percent = a_3; o.preferred = a_4; o.stretch = a_5; return o; }(layout_info.max, layout_info.max_percent, layout_info.min, layout_info.min_percent, 800, layout_info.stretch); }();
}

auto MainWindow::item_geometry (uint32_t index) const -> slint::cbindgen_private::Rect{
    [[maybe_unused]] auto self = this;
    switch (index) {
        case 0: return slint::private_api::convert_anonymous_rect(std::make_tuple(float(self->field_root_57.height.get()), float(self->field_root_57.width.get()), float(0), float(0)));
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
        { SLINT_GET_ITEM_VTABLE(WindowItemVTable),  offsetof(MainWindow, field_root_57) } };
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
    return self->field_root_57_app_clicked.call(arg_0);
}

auto MainWindow::invoke_back_clicked () const -> void{
    slint::private_api::assert_main_thread();
    [[maybe_unused]] auto self = this;
    return self->field_root_57_back_clicked.call();
}

auto MainWindow::get_current_details () const -> UiPackageDetails{
    slint::private_api::assert_main_thread();
    [[maybe_unused]] auto self = this;
    return self->field_root_57_current_details.get();
}

auto MainWindow::set_current_details (const UiPackageDetails &value) const -> void{
    slint::private_api::assert_main_thread();
    [[maybe_unused]] auto self = this;
    self->field_root_57_current_details.set(value);
}

auto MainWindow::get_current_package () const -> UiPackage{
    slint::private_api::assert_main_thread();
    [[maybe_unused]] auto self = this;
    return self->field_root_57_current_package.get();
}

auto MainWindow::set_current_package (const UiPackage &value) const -> void{
    slint::private_api::assert_main_thread();
    [[maybe_unused]] auto self = this;
    self->field_root_57_current_package.set(value);
}

auto MainWindow::invoke_install_clicked (UiPackage arg_0) const -> void{
    slint::private_api::assert_main_thread();
    [[maybe_unused]] auto self = this;
    return self->field_root_57_install_clicked.call(arg_0);
}

auto MainWindow::get_is_showing_details () const -> bool{
    slint::private_api::assert_main_thread();
    [[maybe_unused]] auto self = this;
    return self->field_root_57_is_showing_details.get();
}

auto MainWindow::set_is_showing_details (const bool &value) const -> void{
    slint::private_api::assert_main_thread();
    [[maybe_unused]] auto self = this;
    self->field_root_57_is_showing_details.set(value);
}

auto MainWindow::get_packages () const -> std::shared_ptr<slint::Model<UiPackage>>{
    slint::private_api::assert_main_thread();
    [[maybe_unused]] auto self = this;
    return self->field_root_57_packages.get();
}

auto MainWindow::set_packages (const std::shared_ptr<slint::Model<UiPackage>> &value) const -> void{
    slint::private_api::assert_main_thread();
    [[maybe_unused]] auto self = this;
    self->field_root_57_packages.set(value);
}

auto MainWindow::invoke_remove_clicked (UiPackage arg_0) const -> void{
    slint::private_api::assert_main_thread();
    [[maybe_unused]] auto self = this;
    return self->field_root_57_remove_clicked.call(arg_0);
}

auto MainWindow::invoke_search_changed (slint::SharedString arg_0) const -> void{
    slint::private_api::assert_main_thread();
    [[maybe_unused]] auto self = this;
    return self->field_root_57_search_changed.call(arg_0);
}

auto MainWindow::get_search_query () const -> slint::SharedString{
    slint::private_api::assert_main_thread();
    [[maybe_unused]] auto self = this;
    return self->field_root_57_search_query.get();
}

auto MainWindow::set_search_query (const slint::SharedString &value) const -> void{
    slint::private_api::assert_main_thread();
    [[maybe_unused]] auto self = this;
    self->field_root_57_search_query.set(value);
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
