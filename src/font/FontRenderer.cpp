//
// Created by twome on 07/05/2020.
//

#include "FontRenderer.h"
#include "../shaders/FontShader.h"
#include "../CrystalUI.h"

FontRenderer::FontRenderer(Font *font) : font(font) {
    glGenVertexArrays(1, &vao);
    glGenBuffers(1, &vbo);
}

glm::vec2 FontRenderer::get_bounds(const std::string &text, float size) const {
    float x = 0;
    float minY = 9999999;
    float maxY = 0;
    for (char c : text) {
        Glyph *glyph = font->glyphs[static_cast<int>(c)];
        if (glyph == nullptr)
            continue;
        x += (glyph->advance - 14.0f) * size;

        float y0 = glyph->yOffset * size;
        float y1 = y0 + glyph->height * size;

        if (y0 < minY)
            minY = y0;
        if (y1 > maxY)
            maxY = y1;

    }
    return glm::vec2(x, maxY - minY);
}

void FontRenderer::draw(const std::string &text, glm::vec2 position, float size, glm::vec4 color) {
    glBindVertexArray(vao);
    glEnableVertexAttribArray(0);
    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    glVertexAttribPointer(0, 4, GL_FLOAT, GL_FALSE, 0, nullptr);

    shader.bind();
    shader.set_projection_matrix(CrystalUI::get_instance()->get_gui_matrix());
    shader.set_color(color);

    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, font->atlas.id);

    float tw = font->atlas.width;
    float th = font->atlas.height;

    // Calculate how far down all characters will be
    float totalYOffset = 999;
    for (char c : text) {
        Glyph *glyph = font->glyphs[static_cast<int>(c)];
        if (glyph == nullptr)
            continue;

        if (glyph->yOffset < totalYOffset)
            totalYOffset = glyph->yOffset;
    }

    // Then draw the text
    for (char c : text) {
        Glyph *glyph = font->glyphs[static_cast<int>(c)];
        if (glyph == nullptr)
            continue;

        float x0 = position.x + glyph->xOffset * size;
        float y0 = position.y + glyph->yOffset * size - totalYOffset * size;
        float x1 = x0 + glyph->width * size;
        float y1 = y0 + glyph->height * size;

        float u0 = glyph->x / tw;
        float v0 = glyph->y / th;
        float u1 = (glyph->x + glyph->width) / tw;
        float v1 = (glyph->y + glyph->height) / th;

        GLfloat box[4][4] = {
                x0, y0, u0, v0,
                x1, y0, u1, v0,
                x0, y1, u0, v1,
                x1, y1, u1, v1
        };
        glBufferData(GL_ARRAY_BUFFER, sizeof box, box, GL_DYNAMIC_DRAW);
        glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);

        position.x += (glyph->advance - 14) * size;
    }

    shader.unbind();

    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glDisableVertexAttribArray(0);
    glBindVertexArray(0);
}

void FontRenderer::draw_centered(const std::string &text, glm::vec2 position, float size, glm::vec4 color) {
    glm::vec2 center = get_bounds(text, size) * 0.5f;
    draw(text, position - center, size, color);
}
