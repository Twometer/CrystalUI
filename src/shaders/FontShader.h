//
// Created by twome on 07/05/2020.
//

#ifndef CRYSTALUI_FONTSHADER_H
#define CRYSTALUI_FONTSHADER_H

#include "IShader.h"

class FontShader : public IShader {
private:
    GLuint loc_projectionMatrix;
    GLuint loc_color;

    const std::string vertex = "#version 330 core\n"
                               "\n"
                               "// This vec4 packs the location in XY and the texture coordinates in ZW\n"
                               "layout(location = 0) in vec4 data;\n"
                               "\n"
                               "out vec2 textureCoords;\n"
                               "\n"
                               "uniform mat4 projectionMatrix;\n"
                               "\n"
                               "void main(void) {\n"
                               "    gl_Position = projectionMatrix * vec4(data.xy, 0.0, 1.0);\n"
                               "    textureCoords = data.zw;\n"
                               "}";
    const std::string fragment = "#version 330 core\n"
                                 "\n"
                                 "uniform sampler2D colorTexture;\n"
                                 "uniform vec4 color;\n"
                                 "\n"
                                 "in vec2 textureCoords;\n"
                                 "out vec4 outColor;\n"
                                 "\n"
                                 "const float width = 0.5;\n"
                                 "const float edge = 0.11;\n"
                                 "\n"
                                 "void main(void) {\n"
                                 "    float distance = 1.0 - texture(colorTexture, textureCoords).a;\n"
                                 "    float alpha = 1.0 - smoothstep(width, width + edge, distance);\n"
                                 "\n"
                                 "    outColor = vec4(1.0f, 1.0f, 1.0f, alpha) * color;\n"
                                 "}";

public:
    FontShader() {
        initialize(vertex, fragment);
    }

    void bind_uniforms() override {
        loc_projectionMatrix = get_location("projectionMatrix");
        loc_color = get_location("color");
    }

    void set_projection_matrix(glm::mat4 matrix) {
        load_matrix(loc_projectionMatrix, matrix);
    }

    void set_color(glm::vec4 color) {
        load_vec4(loc_color, color);
    }

};

#endif //CRYSTALUI_FONTSHADER_H
