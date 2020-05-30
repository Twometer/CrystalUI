//
// Created by twome on 08/05/2020.
//

#include "Component.h"
#include "../CrystalUI.h"

Component::Component(const std::string &id) {
    this->id = id;
}

const std::string &Component::get_id() const {
    return id;
}

void Component::set_row(int r) {
    this->row = r;
}

int Component::get_row() const {
    return row;
}

void Component::set_row_span(int rowSpan) {
    this->rowSpan = rowSpan;
}

int Component::get_row_span() const {
    return rowSpan;
}

void Component::set_col(int c) {
    this->column = c;
}

int Component::get_col() const {
    return column;
}

void Component::set_col_span(int colSpan) {
    this->columnSpan = colSpan;
}

int Component::get_col_span() const {
    return columnSpan;
}

void Component::set_position(glm::vec2 position) {
    this->position = position;
}

glm::vec2 Component::get_position() const {
    return position;
}

glm::vec2 Component::get_minimum_size() const {
    return minimumSize + padding * 2.f;
}

void Component::set_maximum_size(glm::vec2 maxSize) {
    this->maximumSize = maxSize;
}

glm::vec2 Component::get_maximum_size() const {
    return maximumSize;
}

void Component::set_size(glm::vec2 size) {
    this->size = size;
}

glm::vec2 Component::get_size() const {
    return size;
}

void Component::set_margin(glm::vec2 margin) {
    this->margin = margin;
}

glm::vec2 Component::get_margin() const {
    return margin;
}

void Component::set_padding(glm::vec2 padding) {
    this->padding = padding;
}

void Component::set_vertical_alignment(Alignment verticalAlignment) {
    this->verticalAlignment = verticalAlignment;
}

Alignment Component::get_vertical_alignment() const {
    return verticalAlignment;
}

void Component::set_horizontal_alignment(Alignment horizontalAlignment) {
    this->horizontalAlignment = horizontalAlignment;
}

Alignment Component::get_horizontal_alignment() const {
    return horizontalAlignment;
}

Cursor Component::get_cursor() {
    return Cursor::STANDARD;
}

bool Component::is_inside(glm::vec2 vec) const {
    return vec.x >= this->position.x && vec.y >= this->position.y
           && vec.x < this->position.x + this->size.x && vec.y < this->position.y + this->size.y;
}

bool Component::is_mouse_over() const {
    return isMouseOver;
}

bool Component::is_mouse_down() const {
    return isMouseDown;
}

bool Component::is_focused() const {
    return isFocused;
}

void Component::set_click_listener(std::function<void()> listener) {
    this->clickListener = listener;
}

void Component::on_mouse_down(glm::vec2 vec) {
    if (is_inside(vec))
        isMouseDown = true;
}

void Component::on_mouse_up(glm::vec2 vec) {
    isMouseDown = false;
    if (is_inside(vec))
        on_click(vec);
}

void Component::on_click(glm::vec2 position) {
    if (clickListener)
        clickListener();
    CrystalUI::get_instance()->get_gui_renderer()->focus_component(this);
}

void Component::on_mouse_move(glm::vec2 position) {
    bool isInside = is_inside(position);

    if (isInside && !isMouseOver) {
        isMouseOver = true;
        on_mouse_enter();
    } else if (!isInside && isMouseOver) {
        isMouseOver = false;
        on_mouse_leave();
    }
}

void Component::on_mouse_enter() {
    CrystalUI::get_instance()->set_cursor(get_cursor());
}

void Component::on_mouse_leave() {
    CrystalUI::get_instance()->set_cursor(Cursor::STANDARD);
}

void Component::on_got_focus() {
    isFocused = true;
}

void Component::on_lost_focus() {
    isFocused = false;
}

void Component::on_character_typed(uint32_t codepoint) {
    // Do nothing by default
}

void Component::on_key_event(int key, int action) {
    // Do nothing by default
}

