#pragma once

#include <string>

namespace ft {
    class Shader {
    public:
        unsigned int ID;
    
        Shader() : ID(0) {}

        int init(const char *vertexSource, const char *fragmentSource);
        void use();
        // for uniforms
        void setBool(const std::string &name, bool value) const;  
        void setInt(const std::string &name, int value) const;   
        void setFloat(const std::string &name, float value) const;
    };
}
