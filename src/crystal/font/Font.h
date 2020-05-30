//
// Created by twome on 07/05/2020.
//

#ifndef CRYSTALUI_FONT_H
#define CRYSTALUI_FONT_H

#include <map>
#include "../gl/Texture.h"
#include "Glyph.h"

namespace crystal {
    struct Font {
        Texture atlas;
        std::map<int, Glyph *> glyphs;
    };
}

#endif //CRYSTALUI_FONT_H
