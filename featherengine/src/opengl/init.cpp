#include "glad/glad.h"
#include "GLFW/glfw3.h"
#include "opengl/opengl.h"
#include "feather/window/window.h"
#include "feather/log.h"

namespace ft {
    OpenGLContextInfo contextInfo;

    int initialiseForTheTriangle();
    
    void framebufferSizeCallback(GLFWwindow* window, int width, int height) {
        glViewport(0, 0, width, height);
    }

    void getOpenGLContextInfo(OpenGLContextInfo *info) {
        glGetIntegerv(GL_MAJOR_VERSION, &info->majorVersion);
        glGetIntegerv(GL_MINOR_VERSION, &info->minorVersion);
        snprintf(info->versionStr, sizeof(info->versionStr), "%s", glGetString(GL_VERSION));
        snprintf(info->vendorStr, sizeof(info->vendorStr), "%s", glGetString(GL_VENDOR));
        snprintf(info->rendererStr, sizeof(info->rendererStr), "%s", glGetString(GL_RENDERER));
    }

    int initOpenGL(Window *window) {
        if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
            FT_CORE_LOG_ERROR("Failed to initialize GLAD");
            return -1;
        }

        getOpenGLContextInfo(&contextInfo);

        glViewport(0, 0, window->getOriginalWidth(), window->getOriginalHeight());
        glfwSetFramebufferSizeCallback(window->getWindow(), framebufferSizeCallback);

        return initialiseForTheTriangle();
    }

}