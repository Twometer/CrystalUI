//
// Created by twome on 06/05/2020.
//

#ifndef CRYSTALUI_BASICSHADER_H
#define CRYSTALUI_BASICSHADER_H

#include "IShader.h"

class BasicShader : public IShader {
private:
    GLuint loc_cameraMatrix;

    const std::string vertex = "#version 330 core\n"
                               "\n"
                               "layout(location = 0) in vec2 pos;\n"
                               "layout(location = 1) in vec3 color;\n"
                               "\n"
                               "out vec3 fragmentColor;\n"
                               "\n"
                               "uniform mat4 cameraMatrix;\n"
                               "\n"
                               "void main(void) {\n"
                               "    gl_Position = cameraMatrix * vec4(pos.xy, 0.0f, 1.0f);\n"
                               "    fragmentColor = color;\n"
                               "}";
    const std::string fragment = "#version 330 core\n"
                                 "\n"
                                 "in vec3 fragmentColor;\n"
                                 "out vec4 outColor;\n"
                                 "\n"
                                 "void main(void) {\n"
                                 "    outColor = vec4(fragmentColor, 1.0f);\n"
                                 "}";

public:
    BasicShader() {
        initialize(vertex, fragment);
    }

    void bind_uniforms() override {
        loc_cameraMatrix = get_location("cameraMatrix");
    }

    void set_camera_matrix(glm::mat4 matrix) {
        load_matrix(loc_cameraMatrix, matrix);
    }

};

#endif //CRYSTALUI_BASICSHADER_H
