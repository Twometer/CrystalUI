//
// Created by twome on 08/05/2020.
//

#include "GuiRenderer.h"

namespace crystal {
    void GuiRenderer::show_screen(Screen *screen) {
        this->currentScreen = screen;

        if (screen != nullptr)
            screen->layout();
    }

    void GuiRenderer::show_dialog(Dialog *dialog) {
        this->currentDialog = dialog;

        if (dialog != nullptr)
            dialog->layout();
    }

    void GuiRenderer::draw() {
        if (currentScreen != nullptr)
            this->currentScreen->draw(graphics);
        if (currentDialog != nullptr)
            this->currentDialog->draw(graphics);
    }

    void GuiRenderer::layout() {
        if (currentScreen != nullptr)
            this->currentScreen->layout();
        if (currentDialog != nullptr)
            this->currentDialog->layout();
    }

    void GuiRenderer::on_mouse_down(glm::vec2 position) {
        if (currentScreen != nullptr)
            currentScreen->on_mouse_down(position);
        if (currentDialog != nullptr)
            this->currentDialog->on_mouse_down(position);
    }

    void GuiRenderer::on_mouse_up(glm::vec2 position) {
        if (currentScreen != nullptr)
            currentScreen->on_mouse_up(position);
        if (currentDialog != nullptr)
            this->currentDialog->on_mouse_up(position);
    }

    void GuiRenderer::on_mouse_move(glm::vec2 position) {
        if (currentScreen != nullptr)
            currentScreen->on_mouse_move(position);
        if (currentDialog != nullptr)
            this->currentDialog->on_mouse_move(position);
    }

    void GuiRenderer::on_character_typed(uint32_t codepoint) {
        if (currentScreen != nullptr)
            currentScreen->on_character_typed(codepoint);
        if (currentDialog != nullptr)
            this->currentDialog->on_character_typed(codepoint);
    }

    void GuiRenderer::on_key_event(int key, int action) {
        if (currentScreen != nullptr)
            currentScreen->on_key_event(key, action);
        if (currentDialog != nullptr)
            this->currentDialog->on_key_event(key, action);
    }

    bool GuiRenderer::is_input_blocked() const {
        return (currentScreen != nullptr && currentScreen->blocks_game_inputs()) || currentDialog != nullptr;
    }

    void GuiRenderer::focus_component(Component *component) {
        if (currentScreen != nullptr) {
            Component *currentFocus = currentScreen->get_focused_component();
            if (currentFocus != nullptr)
                currentFocus->on_lost_focus();

            currentScreen->set_focused_component(component);
            component->on_got_focus();
        }
    }
}