//
// Created by twome on 10/05/2020.
//

#include "CheckBox.h"
#include "../CrystalUI.h"

CheckBox::CheckBox(const std::string &id) : TextComponent(id) {
}

void CheckBox::draw(Graphics &graphics) {
    float offset = size.y + 16;

    graphics.begin();
    graphics.push_rectangle(position.x, position.y, size.y, size.y, glm::vec3(0.2157, 0.2549, 0.2745));
    graphics.push_rectangle(position.x + 1, position.y + 1, size.y - 2, size.y - 2, glm::vec3(0.1529, 0.1922, 0.2118));

    checkContentColor.update();
    graphics.push_rectangle(position.x + 8, position.y + 8, size.y - 16, size.y - 16, checkContentColor.get_value());
    graphics.end();

    graphics.draw_text(text, position + glm::vec2(offset, 0), fontSize);
}

void CheckBox::layout() {
    minimumSize = CrystalUI::get_instance()->get_font_renderer()->get_bounds(text, fontSize);
    minimumSize += glm::vec2(minimumSize.y + 16, 0);
}

void CheckBox::on_click(glm::vec2 position) {
    checked = !checked;
    if (checked)
        checkContentColor = glm::vec3(0.0, 0.6588, 1.0);
    else
        checkContentColor = glm::vec3(0.1529, 0.1922, 0.2118);
}

bool CheckBox::is_checked() const {
    return checked;
}

