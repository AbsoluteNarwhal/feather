#include "glad/glad.h"
#include "GLFW/glfw3.h"
#include "feather/window/window.h"
#include "feather/log.h"

namespace ft {
    void framebuffer_size_callback(GLFWwindow* window, int width, int height);

    int Window::initAPI() {
        if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
            FT_CORE_LOG_ERROR("Failed to initialize GLAD");
            return -1;
        }

        glViewport(0, 0, this->width, this->height);
        glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
        return 0;
    }

    void framebuffer_size_callback(GLFWwindow* window, int width, int height) {
        glViewport(0, 0, width, height);
    }  
}