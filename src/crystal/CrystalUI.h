//
// Created by twome on 30/05/2020.
//

#ifndef CRYSTALUI_CRYSTALUI_H
#define CRYSTALUI_CRYSTALUI_H


#include "GuiRenderer.h"
#include "IGuiHandler.h"

namespace crystal {
    class CrystalUI {
    private:
        static CrystalUI *instance;

        GuiRenderer *guiRenderer = nullptr;

        FontRenderer *fontRenderer = nullptr;

        IGuiHandler *guiHandler = nullptr;

        glm::mat4 guiMatrix{};

    public:
        static CrystalUI *get_instance();

        static void initialize(IGuiHandler *handler, const std::string &fontPath);

        IGuiHandler *get_gui_handler() const;

        GuiRenderer *get_gui_renderer() const;

        FontRenderer *get_font_renderer() const;

        glm::vec2 get_viewport_size() const;

        const glm::mat4 &get_gui_matrix() const;

        void set_cursor(Cursor cursor);

        Texture *load_texture(const std::string &path);

        void draw();
    };
}

#endif //CRYSTALUI_CRYSTALUI_H
