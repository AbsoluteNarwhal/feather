#include "glad/glad.h"
#include "GLFW/glfw3.h"
#include "feather/window/window.h"
#include "feather/log.h"

namespace ft {
    void framebufferSizeCallback(GLFWwindow* window, int width, int height);
    int initialiseForTheTriangle();

    int initOpenGL(Window *window) {
        if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
            FT_CORE_LOG_ERROR("Failed to initialize GLAD");
            return -1;
        }

        glViewport(0, 0, window->getOriginalWidth(), window->getOriginalHeight());
        glfwSetFramebufferSizeCallback(window->getWindow(), framebufferSizeCallback);

        return initialiseForTheTriangle();
    }

    void framebufferSizeCallback(GLFWwindow* window, int width, int height) {
        glViewport(0, 0, width, height);
    }  
}