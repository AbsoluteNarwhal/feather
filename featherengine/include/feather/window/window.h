#pragma once

#include "GLFW/glfw3.h"
#include <string>

namespace ft {
    class Window {
    private:
        static bool isGLFWInitialized;
        GLFWwindow *window;
        std::string title;
        int width;
        int height;
        bool isVSync;

    public:
        int initWindow(const char *title, int width, int height);
        inline GLFWwindow *getWindow() { return this->window; }
        void setVSync(bool enabled);
        bool isVSyncEnabled() const { return this->isVSync; }
    };
}
