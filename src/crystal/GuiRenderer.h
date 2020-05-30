//
// Created by twome on 08/05/2020.
//

#ifndef CRYSTALUI_GUIRENDERER_H
#define CRYSTALUI_GUIRENDERER_H

#include "base/Screen.h"
#include "shaders/BasicShader.h"
#include "shaders/TexturedShader.h"
#include "Graphics.h"
#include "gl/Vao.h"
#include "base/Dialog.h"

namespace crystal {
    class GuiRenderer {
    private:
        Screen *currentScreen = nullptr;
        Dialog *currentDialog = nullptr;

        Vao vao = Vao(2);
        MeshBuilder meshBuilder;
        Graphics graphics = Graphics(&vao, &meshBuilder, &flatShader, &texturedShader, glm::vec2(0, 0));

        // We can reuse the main game shader here
        BasicShader flatShader;
        TexturedShader texturedShader;

    public:
        void show_screen(Screen *screen);

        void show_dialog(Dialog *dialog);

        void draw();

        void layout();

        void on_mouse_down(glm::vec2 position);

        void on_mouse_up(glm::vec2 position);

        void on_mouse_move(glm::vec2 position);

        void on_character_typed(uint32_t codepoint);

        void on_key_event(int key, int action);

        bool is_input_blocked() const;

        void focus_component(Component *component);

    };
}

#endif //CRYSTALUI_GUIRENDERER_H

