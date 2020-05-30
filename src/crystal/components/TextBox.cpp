//
// Created by twome on 09/05/2020.
//

#include <iostream>
#include "TextBox.h"
#include "../CrystalUI.h"

#define GLFW_PRESS                  1
#define GLFW_REPEAT                 2
#define GLFW_KEY_BACKSPACE          259
#define GLFW_KEY_RIGHT              262
#define GLFW_KEY_LEFT               263
#define GLFW_KEY_HOME               268
#define GLFW_KEY_END                269

namespace crystal {
    TextBox::TextBox(const std::string &id) : TextComponent(id) {
    }

    void TextBox::draw(Graphics &graphics) {
        graphics.begin();
        graphics.push_rectangle(position.x, position.y, size.x, size.y, borderColor.get_value());
        graphics.push_rectangle(position.x + 1, position.y + 1, size.x - 2, size.y - 2,
                                glm::vec3(0.1529, 0.1922, 0.2118));

        if (is_focused()) {
            glm::vec2 textBounds = CrystalUI::get_instance()->get_font_renderer()->get_bounds(text, fontSize);
            glm::vec2 textUntil = CrystalUI::get_instance()->get_font_renderer()->get_bounds(text.substr(0, cursorPos),
                                                                                             fontSize);

            float cursorX = size.x / 2.f - textBounds.x / 2.f + textUntil.x + 2.f;
            graphics.push_rectangle(position.x + cursorX, position.y + 10, 0.5f, size.y - 20,
                                    glm::vec3(1.0f, 1.0f, 1.0f));
        }

        graphics.end();

        if (!placeholder.empty() && text.empty())
            graphics.draw_centered_text(placeholder, position + size * .5f, fontSize,
                                        glm::vec4(0.498, 0.549, 0.5529, 0.8f));

        if (!text.empty())
            graphics.draw_centered_text(text, position + size * .5f, fontSize, glm::vec4(0.7412, 0.7647, 0.7804, 1.0f));


        borderColor.update();
    }

    void TextBox::layout() {
        minimumSize = CrystalUI::get_instance()->get_font_renderer()->get_bounds("WW", fontSize);
    }

    void TextBox::on_got_focus() {
        Component::on_got_focus();
        borderColor = glm::vec3(0.0, 0.6588, 1.0);
    }

    void TextBox::on_lost_focus() {
        Component::on_lost_focus();
        borderColor = glm::vec3(0.2157, 0.2549, 0.2745);
    }

    void TextBox::set_placeholder(const std::string &placeholder) {
        this->placeholder = placeholder;
    }

    Cursor TextBox::get_cursor() {
        return Cursor::IBEAM;
    }

    void TextBox::on_character_typed(uint32_t codepoint) {
        if (is_focused()) {
            text.insert(cursorPos, 1, (char) codepoint);
            cursorPos++;
        }
    }

    void TextBox::on_key_event(int key, int action) {
        if (is_focused() && (action == GLFW_PRESS || action == GLFW_REPEAT)) {
            switch (key) {
                case GLFW_KEY_BACKSPACE:
                    if (!text.empty() && cursorPos > 0) {
                        text.erase(cursorPos - 1, 1);
                        cursorPos--;
                    }
                    break;
                case GLFW_KEY_LEFT:
                    if (cursorPos > 0)
                        cursorPos--;
                    break;
                case GLFW_KEY_RIGHT:
                    if (cursorPos < text.length())
                        cursorPos++;
                    break;
                case GLFW_KEY_END:
                    cursorPos = text.length();
                    break;
                case GLFW_KEY_HOME:
                    cursorPos = 0;
                    break;
                default:
                    break;
            }
        }
    }

    void TextBox::on_text_changed() {
        cursorPos = text.length();
    }
}