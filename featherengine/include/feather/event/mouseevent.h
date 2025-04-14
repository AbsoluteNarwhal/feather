#pragma once

#include "feather/event/event.h"
#include <sstream>

namespace ft {
    class MouseButtonEvent : public Event {
    protected:
        int buttonCode;

    public:
        MouseButtonEvent(EventType type, int buttonCode) : buttonCode(buttonCode) {
            this->type = type;
        }

        const char *getName() const override {
            if (this->type == EventType::MouseButtonPressed) return "MouseEvent(ButtonPressed)";
            if (this->type == EventType::MouseButtonReleased) return "MouseEvent(ButtonReleased)";
            return "MouseEvent(Unknown)";
        }

        std::string toString() const override {
            std::stringstream ss;
            ss << this->getName() << ": Button " << this->buttonCode;
            return ss.str();
        }
    };

    class MouseMovedEvent : public Event {
    protected:
        int x, y;

    public:
        MouseMovedEvent(int x, int y) : x(x), y(y) {
            this->type = EventType::MouseMoved;
        }

        const char *getName() const override {
            return "MouseEvent(Moved)";
        }

        std::string toString() const override {
            std::stringstream ss;
            ss << this->getName() << ": Moved to (" << this->x << ", " << this->y << ")";
            return ss.str();
        }
    };

    class MouseScrolledEvent : public Event {
    protected:
        int xOffset, yOffset;

    public:
        MouseScrolledEvent(int xOffset, int yOffset) : xOffset(xOffset), yOffset(yOffset) {
            this->type = EventType::MouseScrolled;
        }

        const char *getName() const override {
            return "MouseEvent(Scrolled)";
        }

        std::string toString() const override {
            std::stringstream ss;
            ss << this->getName() << ": Scrolled by (" << this->xOffset << ", " << this->yOffset << ")";
            return ss.str();
        }
    };
}