#include "feather/window/window.h"
#include "feather/log.h"

namespace ft {
    bool Window::isGLFWInitialized = false;

    int Window::initWindow(const char *title, int width, int height) {
        if (!isGLFWInitialized) {
            int success = glfwInit();
            FT_CORE_ASSERT(success, "Failed to initialize GLFW");
            // glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
            // glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
            // glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

            isGLFWInitialized = true;
        }

        this->window = glfwCreateWindow(width, height, title, NULL, NULL);
        this->title = title;
        this->width = width;
        this->height = height;

        if (this->window == nullptr) {
            FT_CORE_LOG_ERROR("Failed to create GLFW window");
            glfwTerminate();
            return -1;
        }

        glfwMakeContextCurrent(this->window);
        this->setVSync(true);

        return 0;
    }

    void Window::setVSync(bool enabled) {
        // OpenGL only, move this somewhere else when we have vulkan
        this->isVSync = enabled;
        if (enabled) {
            glfwSwapInterval(1);
            this->isVSync = true;
        } else {
            glfwSwapInterval(0);
            this->isVSync = false;
        }
    }

    void Window::swapAndPoll() {
        glfwSwapBuffers(this->window);
        glfwPollEvents(); 
        
        if (glfwWindowShouldClose(this->window)) {
            this->shouldEnd = true;
        }
    }
}