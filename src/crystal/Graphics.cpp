//
// Created by twome on 09/05/2020.
//

#include "Graphics.h"
#include "CrystalUI.h"

namespace crystal {
    Graphics::Graphics(Vao *vao, MeshBuilder *builder, BasicShader *flatShader, TexturedShader *texturedShader,
                       const glm::vec2 &origin) : vao(vao),
                                                  builder(builder),
                                                  flatShader(flatShader),
                                                  texturedShader(texturedShader),
                                                  origin(origin) {
    }

    void Graphics::push_rectangle(float x, float y, float width, float height, glm::vec3 color) {
        builder->push_rectangle(x + origin.x, y + origin.y, width, height, color);
    }

    void Graphics::push_tex_rectangle(float x, float y, float width, float height) {
        builder->push_tex_rectangle(x + origin.x, y + origin.y, width, height);
    }

    Graphics Graphics::create_offset(glm::vec2 offset) {
        return {vao, builder, flatShader, texturedShader, origin + offset};
    }

    void Graphics::draw_text(const std::string &text, glm::vec2 position, float size, glm::vec4 color) {
        CrystalUI::get_instance()->get_font_renderer()->draw(text, position + origin, size, color);
    }

    void Graphics::draw_centered_text(const std::string &text, glm::vec2 position, float size, glm::vec4 color) {
        CrystalUI::get_instance()->get_font_renderer()->draw_centered(text, position + origin, size, color);
    }

    void Graphics::begin() {
        builder->clear();
    }

    void Graphics::end(GraphicsMode mode) {
        int d;
        if (mode == GraphicsMode::Flat) {
            flatShader->bind();
            flatShader->set_camera_matrix(CrystalUI::get_instance()->get_gui_matrix());
            d = 3;
        } else {
            texturedShader->bind();
            texturedShader->set_camera_matrix(CrystalUI::get_instance()->get_gui_matrix());
            d = 2;
        }

        vao->set_data(builder->get_vertices(), builder->get_vertex_count(), builder->get_meta(),
                      builder->get_meta_count(), d);
        vao->render();
    }
}