//
// Created by twome on 30/05/2020.
//

#include <glm/gtc/matrix_transform.hpp>

#include "CrystalUI.h"
#include "io/FontLoader.h"

namespace crystal {
    CrystalUI *CrystalUI::get_instance() {
        return instance;
    }

    void CrystalUI::initialize(IGuiHandler *handler, const std::string &fontPath) {
        instance = new CrystalUI();
        instance->guiHandler = handler;
        Font *font = FontLoader::load_font(fontPath);
        instance->fontRenderer = new FontRenderer(font);
        instance->guiRenderer = new GuiRenderer();
    }

    GuiRenderer *CrystalUI::get_gui_renderer() const {
        return guiRenderer;
    }

    FontRenderer *CrystalUI::get_font_renderer() const {
        return fontRenderer;
    }

    glm::vec2 CrystalUI::get_viewport_size() const {
        return guiHandler->get_viewport_size();
    }

    const glm::mat4 &CrystalUI::get_gui_matrix() const {
        return guiMatrix;
    }

    void CrystalUI::set_cursor(Cursor cursor) {
        guiHandler->set_cursor(cursor);
    }

    Texture *CrystalUI::load_texture(const std::string &path) {
        return guiHandler->load_texture(path);
    }

    void CrystalUI::draw() {
        glm::vec2 viewportSize = get_viewport_size();
        guiMatrix = glm::ortho(0.0f, viewportSize.x, viewportSize.y, 0.0f);
        guiRenderer->draw();
    }
}