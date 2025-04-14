#pragma once

#include "feather/event/event.h"
#include <sstream>

namespace ft {
    class WindowResizedEvent : public Event {
    protected:
        int width, height;

    public:
        WindowResizedEvent(int width, int height) : width(width), height(height) {
            this->type = EventType::WindowResized;
        }

        const char *getName() const override {
            return "WindowEvent(WindowResized)";
        }

        std::string toString() const override {
            std::stringstream ss;
            ss << this->getName() << ": Resized to " << this->width << "x" << this->height;
            return ss.str();
        }
    };

    class WindowMovedEvent : public Event {
    protected:
        int x, y;

    public:
        WindowMovedEvent(int x, int y) : x(x), y(y) {
            this->type = EventType::WindowMoved;
        }

        const char *getName() const override {
            return "WindowEvent(WindowMoved)";
        }

        std::string toString() const override {
            std::stringstream ss;
            ss << this->getName() << ": Moved to (" << this->x << ", " << this->y << ")";
            return ss.str();
        }
    };

    class WindowFocusedEvent : public Event {
    public:
        WindowFocusedEvent() {
            this->type = EventType::WindowFocused;
        }

        const char *getName() const override {
            return "WindowEvent(WindowFocused)";
        }

        std::string toString() const override {
            return this->getName();
        }
    };

    class WindowUnfocusedEvent : public Event {
    public:
        WindowUnfocusedEvent() {
            this->type = EventType::WindowUnfocused;
        }

        const char *getName() const override {
            return "WindowEvent(WindowUnfocused)";
        }

        std::string toString() const override {
            return this->getName();
        }
    };

    class WindowClosedEvent : public Event {
    public:
        WindowClosedEvent() {
            this->type = EventType::WindowClosed;
        }

        const char *getName() const override {
            return "WindowEvent(WindowClosed)";
        }

        std::string toString() const override {
            return this->getName();
        }
    };
}