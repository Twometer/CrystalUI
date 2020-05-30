//
// Created by twome on 10/05/2020.
//

#ifndef CRYSTALUI_TOOLBUTTON_H
#define CRYSTALUI_TOOLBUTTON_H


#include "../gl/Texture.h"
#include "../base/ImageComponent.h"
#include "../anim/Animated.h"

class ToolButton : public ImageComponent {
private:
    Animated expansion = 0.0f;

public:
    explicit ToolButton(const std::string &id);

    void draw(Graphics &graphics) override;

    void layout() override;

    void on_mouse_enter() override;

    void on_mouse_leave() override;

};


#endif //CRYSTALUI_TOOLBUTTON_H
