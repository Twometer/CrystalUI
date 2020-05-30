//
// Created by twome on 08/05/2020.
//

#include "Label.h"

#include "../CrystalUI.h"

namespace crystal {
    Label::Label(const std::string &id) : TextComponent(id) {
    }

    void Label::draw(Graphics &graphics) {
        graphics.draw_text(text, position, fontSize);
    }

    void Label::layout() {
        minimumSize = CrystalUI::get_instance()->get_font_renderer()->get_bounds(text, fontSize);
    }
}