//
// Created by twome on 30/05/2020.
//

#ifndef CRYSTALUI_FONTLOADER_H
#define CRYSTALUI_FONTLOADER_H


#include "../font/Font.h"

namespace crystal {
    class FontLoader {
    public:
        static Font *load_font(const std::string &path);

    private:
        static Font *read_font(std::ifstream &stream);

        static int parse_property(const std::string &line, const std::string &property);

        static Glyph *parse_glyph(const std::string &line);

        static bool is_glyph(const std::string &line);
    };
}

#endif //CRYSTALUI_FONTLOADER_H
