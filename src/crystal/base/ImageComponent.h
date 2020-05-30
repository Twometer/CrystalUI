//
// Created by twome on 10/05/2020.
//

#ifndef CRYSTALUI_IMAGECOMPONENT_H
#define CRYSTALUI_IMAGECOMPONENT_H

#include "Component.h"
#include "../gl/Texture.h"

namespace crystal {
/**
 * The ImageComponent provides a base
 * class for all textured components. It
 * handles texture loading and ID mapping
 */
    class ImageComponent : public Component {
    protected:
        std::string texturePath = "";
        Texture *texture = nullptr;

    public:
        explicit ImageComponent(const std::string &id) : Component(id) {}

        void set_texture(const std::string &texturePath);

    };
};

#endif //CRYSTALUI_IMAGECOMPONENT_H
