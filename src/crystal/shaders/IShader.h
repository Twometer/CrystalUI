//
// Created by twome on 06/05/2020.
//

#ifndef CRYSTALUI_ISHADER_H
#define CRYSTALUI_ISHADER_H

#include <string>
#include <glad/glad.h>
#include <glm/glm.hpp>

namespace crystal {
    class IShader {
    protected:
        GLuint id = 0;

        void initialize(const std::string &vertex, const std::string &fragment);

        virtual void bind_uniforms() = 0;

        int get_location(const std::string &uniform) const;

        static void load_matrix(int loc, glm::mat4 matrix);

        static void load_float(int loc, float f);

        static void load_vec2(int loc, glm::vec2 vec);

        static void load_vec3(int loc, glm::vec3 vec);

        static void load_vec4(int loc, glm::vec4 vec);

    public:
        void bind() const;

        static void unbind();

    };
}

#endif //CRYSTALUI_ISHADER_H
