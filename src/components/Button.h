//
// Created by twome on 09/05/2020.
//

#ifndef CRYSTALUI_BUTTON_H
#define CRYSTALUI_BUTTON_H


#include "../base/TextComponent.h"
#include "../gl/Vao.h"
#include "../gl/MeshBuilder.h"
#include "../anim/AnimatedColor.h"

class Button : public TextComponent {
private:
    AnimatedColor color = glm::vec3(0.1804, 0.8, 0.4431);

public:
    explicit Button(const std::string &id);

    void draw(Graphics &graphics) override;

    void layout() override;

    void on_mouse_enter() override;

    void on_mouse_leave() override;
};


#endif //CRYSTALUI_BUTTON_H
