//
// Created by twome on 06/05/2020.
//

#include "IShader.h"
#include "../util/Logger.h"

namespace crystal {
    int IShader::get_location(const std::string &uniform) const {
        return glGetUniformLocation(id, uniform.c_str());
    }

    void IShader::load_matrix(int loc, glm::mat4 matrix) {
        glUniformMatrix4fv(loc, 1, GL_FALSE, &matrix[0][0]);
    }

    void IShader::load_float(int loc, float f) {
        glUniform1f(loc, f);
    }

    void IShader::load_vec2(int loc, glm::vec2 vec) {
        glUniform2f(loc, vec.x, vec.y);
    }

    void IShader::load_vec3(int loc, glm::vec3 vec) {
        glUniform3f(loc, vec.x, vec.y, vec.z);
    }

    void IShader::load_vec4(int loc, glm::vec4 vec) {
        glUniform4f(loc, vec.x, vec.y, vec.z, vec.w);
    }

    void IShader::unbind() {
        glUseProgram(0);
    }

    void IShader::bind() const {
        glUseProgram(id);
    }

    void IShader::initialize(const std::string &vertex, const std::string &fragment) {
        Logger::info("Loading shader");
        auto vertexSourcePtr = vertex.c_str();
        auto fragmentSourcePtr = fragment.c_str();

        auto program = glCreateProgram();

        auto vertexShader = glCreateShader(GL_VERTEX_SHADER);
        glShaderSource(vertexShader, 1, &vertexSourcePtr, nullptr);
        glCompileShader(vertexShader);
        check_shader(vertex, vertexShader);

        auto fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
        glShaderSource(fragmentShader, 1, &fragmentSourcePtr, nullptr);
        glCompileShader(fragmentShader);
        check_shader(fragment, fragmentShader);

        glAttachShader(program, vertexShader);
        glAttachShader(program, fragmentShader);

        glLinkProgram(program);

        glDetachShader(program, vertexShader);
        glDetachShader(program, fragmentShader);

        glDeleteShader(vertexShader);
        glDeleteShader(fragmentShader);

        id = program;

        bind_uniforms();
    }

    void IShader::check_shader(const std::string &name, GLuint shader) {
        int infoLogLength;
        glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &infoLogLength);
        if (infoLogLength > 0) {
            char errorMsg[infoLogLength + 1];
            glGetShaderInfoLog(shader, infoLogLength, nullptr, errorMsg);
            Logger::error(name + ": " + std::string(errorMsg));
        }
    }
}