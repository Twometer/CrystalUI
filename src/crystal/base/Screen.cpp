//
// Created by twome on 08/05/2020.
//

#include "Screen.h"
#include "../CrystalUI.h"

namespace crystal {
    void Screen::draw(Graphics &graphics) {
        for (auto component : components)
            component->draw(graphics);
    }

    Screen::Screen(const std::string &id) : Container(id) {
        set_vertical_alignment(Alignment::STRETCH);
        set_horizontal_alignment(Alignment::STRETCH);
    }

    void Screen::layout() {
        this->minimumSize = CrystalUI::get_instance()->get_viewport_size();
        this->maximumSize = CrystalUI::get_instance()->get_viewport_size();
        Container::layout();
    }

    bool Screen::blocks_game_inputs() const {
        return true;
    }

    Component *Screen::get_focused_component() const {
        return focusedComponent;
    }

    void Screen::set_focused_component(Component *focusedComponent) {
        this->focusedComponent = focusedComponent;
    }
}