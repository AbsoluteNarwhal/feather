#include "feather/core.h"
#include "feather/event/windowevent.h"
#include <sstream>

namespace ft {

    std::vector<void(*)(WindowResizedEvent*)> WindowResizedEvent::callbacks;
    std::vector<void(*)(WindowMovedEvent*)> WindowMovedEvent::callbacks;
    std::vector<void(*)(WindowFocusedEvent*)> WindowFocusedEvent::callbacks;
    std::vector<void(*)(WindowUnfocusedEvent*)> WindowUnfocusedEvent::callbacks;
    std::vector<void(*)(WindowClosedEvent*)> WindowClosedEvent::callbacks;

    const char *WindowResizedEvent::getName() const {
        return "WindowEvent(WindowResized)";
    }

    std::string WindowResizedEvent::toString() const {
        std::stringstream ss;
        ss << this->getName() << ": Resized to " << this->width << "x" << this->height;
        return ss.str();
    }

    const char *WindowMovedEvent::getName() const {
        return "WindowEvent(WindowMoved)";
    }

    std::string WindowMovedEvent::toString() const {
        std::stringstream ss;
        ss << this->getName() << ": Moved to (" << this->x << ", " << this->y << ")";
        return ss.str();
    }

    const char *WindowFocusedEvent::getName() const {
        return "WindowEvent(WindowFocused)";
    }

    std::string WindowFocusedEvent::toString() const {
        return this->getName();
    }

    const char *WindowUnfocusedEvent::getName() const {
        return "WindowEvent(WindowFocused)";
    }

    std::string WindowUnfocusedEvent::toString() const {
        return this->getName();
    }

    const char *WindowClosedEvent::getName() const {
        return "WindowEvent(WindowFocused)";
    }

    std::string WindowClosedEvent::toString() const {
        return this->getName();
    }
}