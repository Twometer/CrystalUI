//
// Created by twome on 10/05/2020.
//

#include "ToolButton.h"

namespace crystal {
    ToolButton::ToolButton(const std::string &id) : ImageComponent(id) {

    }

    void ToolButton::draw(Graphics &graphics) {
        texture->bind();
        graphics.begin();

        expansion.update();
        float exp = expansion.get_value();
        graphics.push_tex_rectangle(position.x - exp, position.y - exp, texture->width + 2 * exp,
                                    texture->height + 2 * exp);
        graphics.end(GraphicsMode::Textured);
    }

    void ToolButton::layout() {
        minimumSize = glm::vec2(texture->width, texture->height);
    }

    void ToolButton::on_mouse_enter() {
        expansion = 2.5f;
    }

    void ToolButton::on_mouse_leave() {
        expansion = 0.0f;
    }
}