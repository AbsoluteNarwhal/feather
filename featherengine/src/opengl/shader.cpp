#include "feather/opengl/shader.h"
#include "glad/glad.h"
#include "feather/core.h"
#include "feather/log.h"
#include <sstream>
#include <fstream>
#include <iostream>

namespace ft {
    int Shader::init(const char *vertexSource, const char *fragmentSource) {
        if (!vertexSource || !fragmentSource) {
            FT_CORE_LOG_ERROR("Vertex or fragment shader source is null.");
            return -1;
        }

        // vertex shader
        unsigned int vertexShader;
        vertexShader = glCreateShader(GL_VERTEX_SHADER);
        glShaderSource(vertexShader, 1, &vertexSource, NULL);
        glCompileShader(vertexShader);

        int success;
        char infoLog[512];
        glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
        if(!success) {
            glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
            FT_CORE_LOG_ERROR("Vertex shader compilation failed:\n{0}", infoLog);
            return -1;
        }

        // fragment shader
        unsigned int fragmentShader;
        fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
        glShaderSource(fragmentShader, 1, &fragmentSource, NULL);
        glCompileShader(fragmentShader);

        glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);
        if(!success) {
            glGetShaderInfoLog(fragmentShader, 512, NULL, infoLog);
            FT_CORE_LOG_ERROR("Fragment shader compilation failed:\n{0}", infoLog);
            return -1;
        }

        // link shaders
        this->ID = glCreateProgram();
        glAttachShader(this->ID, vertexShader);
        glAttachShader(this->ID, fragmentShader);
        glLinkProgram(this->ID);
        
        glGetProgramiv(this->ID, GL_LINK_STATUS, &success);
        if(!success) {
            glGetProgramInfoLog(this->ID, 512, NULL, infoLog);
            FT_CORE_LOG_ERROR("Failed to create shader program:\n{0}", infoLog);
            return -1;
        }

        glDeleteShader(vertexShader);
        glDeleteShader(fragmentShader); 
        return 0;
    }

    void Shader::use() {
        glUseProgram(this->ID);
    }

    void Shader::setBool(const std::string &name, bool value) const {
        glUniform1i(glGetUniformLocation(ID, name.c_str()), (int)value); 
    }

    void Shader::setInt(const std::string &name, int value) const {
        glUniform1i(glGetUniformLocation(ID, name.c_str()), value);
    }

    void Shader::setFloat(const std::string &name, float value) const {
        glUniform1f(glGetUniformLocation(ID, name.c_str()), value);
    }
}