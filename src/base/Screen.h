//
// Created by twome on 08/05/2020.
//

#ifndef CRYSTALUI_SCREEN_H
#define CRYSTALUI_SCREEN_H

#include "Container.h"

/**
 * The base class for all GUI screens
 */
class Screen : public Container {
private:
    Component *focusedComponent = nullptr;

public:
    explicit Screen(const std::string &id);

    void draw(Graphics &graphics) override;

    void layout() override;

    void set_focused_component(Component *focusedComponent);

    Component *get_focused_component() const;

    /**
     * This may be true for e.g. the menu screen, but false for the ingame HUD screen
     * @return Whether the current screen should block inputs to the game such as zooming and moving the field.
     */
    virtual bool blocks_game_inputs() const;

};

#endif //CRYSTALUI_SCREEN_H
