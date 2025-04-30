#ifdef GRAPHICSAPI_OPENGL
#include "glad/glad.h"
#endif
#include "GLFW/glfw3.h"

#include "feather/core.h"
#include "feather/event/keyevent.h"
#include <memory>
#include <sstream>

namespace ft {
    std::vector<void(*)(KeyEvent*)> KeyEvent::callbacks;

    void keyCallback(GLFWwindow *window, int key, int scancode, int action, int mods) {
        if (action == GLFW_PRESS) {
            EventManager::dispatchEvent(std::make_unique<KeyEvent>(EventType::KeyPressed, key, scancode, mods));
        } else if (action == GLFW_REPEAT) {
            EventManager::dispatchEvent(std::make_unique<KeyEvent>(EventType::KeyRepeated, key, scancode, mods));
        } else if (action == GLFW_RELEASE) {
            EventManager::dispatchEvent(std::make_unique<KeyEvent>(EventType::KeyRepeated, key, scancode, mods));
        }
    }

    const char *KeyEvent::getName() const {
        if (this->type == EventType::KeyPressed) return "KeyEvent(KeyPressed)";
        if (this->type == EventType::KeyRepeated) return "KeyEvent(KeyRepeated)";
        if (this->type == EventType::KeyReleased) return "KeyEvent(KeyReleased)";
        return "KeyEvent(Unknown)";
    }

    std::string KeyEvent::toString() const {
        std::stringstream ss;
        ss << this->getName() << ": Keycode " << this->keycode;
        return ss.str();
    }
}