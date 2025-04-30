#ifdef GRAPHICSAPI_OPENGL
#include "glad/glad.h"
#endif
#include "GLFW/glfw3.h"

#include "feather/core.h"
#include "feather/event/mouseevent.h"
#include <memory>
#include <sstream>

namespace ft {

    std::vector<void(*)(MouseButtonEvent*)> MouseButtonEvent::callbacks;
    std::vector<void(*)(MouseMovedEvent*)> MouseMovedEvent::callbacks;
    std::vector<void(*)(MouseScrolledEvent*)> MouseScrolledEvent::callbacks;

    void mouseButtonCallback(GLFWwindow* window, int button, int action, int mods) {
        if (action == GLFW_PRESS) {
            EventManager::dispatchEvent(std::make_unique<MouseButtonEvent>(EventType::MouseButtonPressed, button, mods));
        } else if (action == GLFW_RELEASE) {
            EventManager::dispatchEvent(std::make_unique<MouseButtonEvent>(EventType::MouseButtonReleased, button, mods));
        }
    }

    void cursorPositionCallback(GLFWwindow* window, double xpos, double ypos) {
        EventManager::dispatchEvent(std::make_unique<MouseMovedEvent>(xpos, ypos));
    }

    void scrollCallback(GLFWwindow* window, double xoffset, double yoffset) {
        EventManager::dispatchEvent(std::make_unique<MouseScrolledEvent>(xoffset, yoffset));
    }

    const char *MouseButtonEvent::getName() const {
        if (this->type == EventType::MouseButtonPressed) return "MouseEvent(ButtonPressed)";
        if (this->type == EventType::MouseButtonReleased) return "MouseEvent(ButtonReleased)";
        return "MouseEvent(Unknown)";
    }

    std::string MouseButtonEvent::toString() const {
        std::stringstream ss;
        ss << this->getName() << ": Button " << this->button;
        return ss.str();
    }

    const char *MouseMovedEvent::getName() const {
        return "MouseEvent(Moved)";
    }

    std::string MouseMovedEvent::toString() const {
        std::stringstream ss;
        ss << this->getName() << ": Moved to (" << this->x << ", " << this->y << ")";
        return ss.str();
    }

    const char *MouseScrolledEvent::getName() const {
        return "MouseEvent(Scrolled)";
    }

    std::string MouseScrolledEvent::toString() const {
        std::stringstream ss;
        ss << this->getName() << ": Scrolled by (" << this->xOffset << ", " << this->yOffset << ")";
        return ss.str();
    }
}