#pragma once

#include "feather/event/event.h"
#include <sstream>

namespace ft {
    class MouseButtonEvent : public Event {
    protected:
        int button;
        int mods;

    public:
        MouseButtonEvent(EventType type, int button, int mods) : button(button), mods(mods) {
            this->type = type;
        }

        const char *getName() const override;
        std::string toString() const override;
    };

    class MouseMovedEvent : public Event {
    protected:
        int x, y;

    public:
        MouseMovedEvent(int x, int y) : x(x), y(y) {
            this->type = EventType::MouseMoved;
        }

        const char *getName() const override;
        std::string toString() const override;
    };

    class MouseScrolledEvent : public Event {
    protected:
        double xOffset, yOffset;

    public:
        MouseScrolledEvent(double xOffset, double yOffset) : xOffset(xOffset), yOffset(yOffset) {
            this->type = EventType::MouseScrolled;
        }

        const char *getName() const override;
        std::string toString() const override;
    };
}