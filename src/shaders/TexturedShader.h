//
// Created by twome on 10/05/2020.
//

#ifndef CRYSTALUI_TEXTUREDSHADER_H
#define CRYSTALUI_TEXTUREDSHADER_H

#include "IShader.h"

class TexturedShader : public IShader {
private:
    GLuint loc_cameraMatrix;

    const std::string vertex = "#version 330 core\n"
                               "\n"
                               "layout(location = 0) in vec2 pos;\n"
                               "layout(location = 1) in vec2 uv;\n"
                               "\n"
                               "out vec2 fragmentUv;\n"
                               "\n"
                               "uniform mat4 cameraMatrix;\n"
                               "\n"
                               "void main(void) {\n"
                               "    gl_Position = cameraMatrix * vec4(pos.xy, 0.0f, 1.0f);\n"
                               "    fragmentUv = uv;\n"
                               "}";
    const std::string fragment = "#version 330 core\n"
                                 "\n"
                                 "in vec2 fragmentUv;\n"
                                 "out vec4 outColor;\n"
                                 "\n"
                                 "uniform sampler2D colorTexture;\n"
                                 "\n"
                                 "void main(void) {\n"
                                 "    outColor = texture(colorTexture, fragmentUv);\n"
                                 "}";

public:
    TexturedShader() {
        initialize(vertex, fragment);
    }

    void bind_uniforms() override {
        loc_cameraMatrix = get_location("cameraMatrix");
    }

    void set_camera_matrix(glm::mat4 matrix) {
        load_matrix(loc_cameraMatrix, matrix);
    }

};

#endif //CRYSTALUI_TEXTUREDSHADER_H
