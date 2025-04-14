#pragma once

#ifdef GRAPHICSAPI_OPENGL
#include "glad/glad.h"
#endif
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
        bool shouldEnd = false;

    public:
        int initWindow(const char *title, int width, int height);
        inline GLFWwindow *getWindow() { return this->window; }
        void setVSync(bool enabled);
        inline bool isVSyncEnabled() const { return this->isVSync; }
        int initAPI(); // Initialize OpenGL/Vulkan for this window
        void swapAndPoll();
        inline bool shouldClose() const { return this->shouldEnd; }

        static inline int cleanupAll() {
            glfwTerminate();
            return 0;
        }
    };
}
