#pragma once

#include "feather/event/event.h"
#include <vector>

namespace ft {
    class MouseButtonEvent : public Event {
    protected:
        int button;
        int mods;

        static std::vector<void(*)(MouseButtonEvent*)> callbacks;

    public:
        MouseButtonEvent(EventType type, int button, int mods) : button(button), mods(mods) {
            this->type = type;
        }

        const char *getName() const override;
        std::string toString() const override;

        inline static void registerCallback(void(*fptr)(MouseButtonEvent*)) {
            callbacks.push_back(fptr);
        }

        inline void runCallbacks() override {
            for (int i = 0; i < callbacks.size(); i++) {
                callbacks[i](this);
            }
        }
    };

    class MouseMovedEvent : public Event {
    protected:
        int x, y;

        static std::vector<void(*)(MouseMovedEvent*)> callbacks;

    public:
        MouseMovedEvent(int x, int y) : x(x), y(y) {
            this->type = EventType::MouseMoved;
        }

        const char *getName() const override;
        std::string toString() const override;

        inline static void registerCallback(void(*fptr)(MouseMovedEvent*)) {
            callbacks.push_back(fptr);
        }

        inline void runCallbacks() override {
            for (int i = 0; i < callbacks.size(); i++) {
                callbacks[i](this);
            }
        }
    };

    class MouseScrolledEvent : public Event {
    protected:
        double xOffset, yOffset;

        static std::vector<void(*)(MouseScrolledEvent*)> callbacks;

    public:
        MouseScrolledEvent(double xOffset, double yOffset) : xOffset(xOffset), yOffset(yOffset) {
            this->type = EventType::MouseScrolled;
        }

        const char *getName() const override;
        std::string toString() const override;

        inline static void registerCallback(void(*fptr)(MouseScrolledEvent*)) {
            callbacks.push_back(fptr);
        }

        inline void runCallbacks() override {
            for (int i = 0; i < callbacks.size(); i++) {
                callbacks[i](this);
            }
        }
    };
}