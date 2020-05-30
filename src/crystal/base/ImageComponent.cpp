//
// Created by twome on 10/05/2020.
//

#include "ImageComponent.h"
#include "../CrystalUI.h"

namespace crystal {
    void ImageComponent::set_texture(const std::string &texturePath) {
        if (texturePath != this->texturePath) {
            this->texturePath = texturePath;
            texture = CrystalUI::get_instance()->load_texture(texturePath);
        }
    }
}