//
// Created by twome on 09/05/2020.
//

#include <iostream>
#include "Button.h"
#include "../CrystalUI.h"

Button::Button(const std::string &id) : TextComponent(id) {
}

void Button::draw(Graphics &graphics) {
    graphics.begin();
    graphics.push_rectangle(position.x, position.y, size.x, size.y, color.get_value());
    graphics.end();

    graphics.draw_centered_text(text, position + (size * 0.5f), fontSize);
    color.update();
}

void Button::layout() {
    minimumSize = CrystalUI::get_instance()->get_font_renderer()->get_bounds(text, fontSize);
}

void Button::on_mouse_enter() {
    color = glm::vec3(0.1529, 0.6824, 0.3765);
}

void Button::on_mouse_leave() {
    color = glm::vec3(0.1804, 0.8, 0.4431);
}
