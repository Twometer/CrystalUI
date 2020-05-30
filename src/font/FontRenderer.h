//
// Created by twome on 07/05/2020.
//

#ifndef CRYSTALUI_FONTRENDERER_H
#define CRYSTALUI_FONTRENDERER_H

#include <glm/glm.hpp>
#include "Font.h"
#include "../shaders/FontShader.h"

constexpr glm::vec4 WHITE(1.0f, 1.0f, 1.0f, 1.0f);

class FontRenderer {
private:
    Font *font;

    FontShader shader;

    GLuint vao;
    GLuint vbo;

public:
    explicit FontRenderer(Font *font);

    glm::vec2 get_bounds(const std::string &text, float size = 1.0f) const;

    void draw(const std::string &text, glm::vec2 position, float size = 1.0f, glm::vec4 color = WHITE);

    void draw_centered(const std::string &text, glm::vec2 position, float size = 1.0f, glm::vec4 color = WHITE);

};


#endif //CRYSTALUI_FONTRENDERER_H
