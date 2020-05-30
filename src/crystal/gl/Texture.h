//
// Created by twome on 06/05/2020.
//

#ifndef CRYSTALUI_TEXTURE_H
#define CRYSTALUI_TEXTURE_H

#include <glad/glad.h>

namespace crystal {
    struct Texture {

        GLuint id;
        unsigned int width;
        unsigned int height;

        void bind() {
            glBindTexture(GL_TEXTURE_2D, id);
        }

    };
}

#endif //CRYSTALUI_TEXTURE_H
