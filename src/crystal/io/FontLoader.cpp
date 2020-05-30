//
// Created by twome on 30/05/2020.
//

#include <fstream>
#include "FontLoader.h"
#include "../CrystalUI.h"

namespace crystal {
    Font *FontLoader::load_font(const std::string &path) {
        std::string pngPath = path + ".png";
        std::string fntPath = path + ".fnt";

        std::ifstream stream(fntPath);
        Font *font = read_font(stream);
        font->atlas = *CrystalUI::get_instance()->load_texture(pngPath);

        return font;
    }

    int FontLoader::parse_property(const std::string &line, const std::string &property) {
        std::string key = property + "=";
        int offset = line.find(key);
        if (offset == std::string::npos)
            throw std::runtime_error("Failed to read invalid font file");

        std::string substr = line.substr(offset + key.length());
        std::string value = substr.substr(0, substr.find(" "));

        return std::stoi(value);
    }

    Glyph *FontLoader::parse_glyph(const std::string &line) {
        auto *glyph = new Glyph();
        glyph->id = parse_property(line, "id");
        glyph->x = parse_property(line, "x");
        glyph->y = parse_property(line, "y");
        glyph->width = parse_property(line, "width");
        glyph->height = parse_property(line, "height");
        glyph->xOffset = parse_property(line, "xoffset");
        glyph->yOffset = parse_property(line, "yoffset");
        glyph->advance = parse_property(line, "xadvance");
        return glyph;
    }

    bool FontLoader::is_glyph(const std::string &line) {
        return line.find("char ") == 0;
    }

    Font *FontLoader::read_font(std::ifstream &stream) {
        auto *font = new Font();
        std::string line;
        while (std::getline(stream, line)) {
            if (!is_glyph(line)) continue;

            Glyph *glyph = parse_glyph(line);
            font->glyphs[glyph->id] = glyph;
        }

        return font;
    }
}