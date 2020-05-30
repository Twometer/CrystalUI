//
// Created by twome on 09/05/2020.
//

#ifndef CRYSTALUI_GRAPHICS_H
#define CRYSTALUI_GRAPHICS_H


#include "gl/MeshBuilder.h"
#include "font/FontRenderer.h"
#include "gl/Vao.h"
#include "shaders/BasicShader.h"
#include "shaders/TexturedShader.h"

enum class GraphicsMode {
    Flat,
    Textured
};

class Graphics {
private:
    Vao *vao;
    MeshBuilder *builder;

    BasicShader *flatShader;

    TexturedShader *texturedShader;

    glm::vec2 origin;

public:
    Graphics(Vao *vao, MeshBuilder *builder, BasicShader *guiShader, TexturedShader *texturedShader, const glm::vec2 &origin);

    void begin();

    void push_rectangle(float x, float y, float width, float height, glm::vec3 color);

    void push_tex_rectangle(float x, float y, float width, float height);

    void draw_text(const std::string &text, glm::vec2 position, float size = 1.0f, glm::vec4 color = WHITE);

    void draw_centered_text(const std::string &text, glm::vec2 position, float size = 1.0f, glm::vec4 color = WHITE);

    void end(GraphicsMode mode = GraphicsMode::Flat);

    Graphics create_offset(glm::vec2 offset);
};


#endif //CRYSTALUI_GRAPHICS_H
