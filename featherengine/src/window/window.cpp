#include "feather/window/window.h"
#include "feather/log.h"
#include "feather/core.h"
#include "feather/event/appevent.h"
#include "feather/event/windowevent.h"
#include <memory>

namespace ft {
    void keyCallback(GLFWwindow *window, int key, int scancode, int action, int mods);
    void cursorPositionCallback(GLFWwindow* window, double xpos, double ypos);
    void mouseButtonCallback(GLFWwindow* window, int button, int action, int mods);
    void scrollCallback(GLFWwindow* window, double xoffset, double yoffset);
    void renderTriangle();

    bool Window::isGLFWInitialized = false;

    int Window::initWindow(const char *title, int width, int height) {
        if (!isGLFWInitialized) {
            int success = glfwInit();
            FT_CORE_ASSERT(success, "Failed to initialize GLFW");

            glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
            glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
            glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

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

        // input callbacks for event system
        glfwSetKeyCallback(this->window, keyCallback);
        glfwSetCursorPosCallback(this->window, cursorPositionCallback);
        glfwSetMouseButtonCallback(this->window, mouseButtonCallback);
        glfwSetScrollCallback(this->window, scrollCallback);

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
        renderTriangle();
        glfwSwapBuffers(this->window);

        AppEvent renderEvent(EventType::AppRender, 0.0f);
        EventManager::handleEvent(&renderEvent); // handle it immediately instead of queueing it

        glfwPollEvents(); 
        
        if (glfwWindowShouldClose(this->window)) {
            EventManager::dispatchEvent(std::make_unique<WindowClosedEvent>(this));
            this->shouldEnd = true;
        }
    }
}