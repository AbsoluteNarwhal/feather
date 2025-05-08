#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "opengl/opengl.h"
#include "feather/window/window.h"
#include "feather/log.h"
#include "feather/core.h"
#include "feather/renderer/renderer.h"

namespace ft {
    bool isContextInfoReady = false;
    OpenGLContextInfo contextInfo;

    int initialiseForTheTriangle();
    
    void framebufferSizeCallback(GLFWwindow* window, int width, int height) {
        glViewport(0, 0, width, height);
    }

    OpenGLContextInfo *getOpenGLContextInfo() {
        if (!isContextInfoReady) {
            glGetIntegerv(GL_MAJOR_VERSION, &contextInfo.majorVersion);
            glGetIntegerv(GL_MINOR_VERSION, &contextInfo.minorVersion);
            snprintf(contextInfo.versionStr, sizeof(contextInfo.versionStr), "%s", glGetString(GL_VERSION));
            snprintf(contextInfo.vendorStr, sizeof(contextInfo.vendorStr), "%s", glGetString(GL_VENDOR));
            snprintf(contextInfo.rendererStr, sizeof(contextInfo.rendererStr), "%s", glGetString(GL_RENDERER));
            isContextInfoReady = true;
        }
        return &contextInfo;
    }

    int initOpenGL(Window *window) {
        if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
            FT_CORE_LOG_ERROR("Failed to initialize GLAD");
            return -1;
        }

        glViewport(0, 0, window->getOriginalWidth(), window->getOriginalHeight());
        glfwSetFramebufferSizeCallback(window->getWindow(), framebufferSizeCallback);

        return initialiseForTheTriangle();
    }

}