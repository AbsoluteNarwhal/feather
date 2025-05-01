#pragma once

#include "feather/event/event.h"
#include "feather/window/window.h"

namespace ft {
    class WindowResizedEvent : public Event {
    protected:
        Window *window;
        int width, height;
        static std::vector<void(*)(WindowResizedEvent*)> callbacks;

    public:
        WindowResizedEvent(int width, int height, Window *window) : window(window), width(width), height(height) {
            this->type = EventType::WindowResized;
        }

        inline Window *getWindow() const { return this->window; }
        inline int getWidth() const { return this->width; }
        inline int getHeight() const { return this->height; }

        const char *getName() const override;
        std::string toString() const override;

        inline static void registerCallback(void(*fptr)(WindowResizedEvent*)) {
            callbacks.push_back(fptr);
        }

        inline void runCallbacks() override {
            for (int i = 0; i < callbacks.size(); i++) {
                callbacks[i](this);
            }
        }
    };

    class WindowMovedEvent : public Event {
    protected:
        Window *window;
        int x, y;
        static std::vector<void(*)(WindowMovedEvent*)> callbacks;

    public:
        WindowMovedEvent(int x, int y, Window *window) : window(window), x(x), y(y) {
            this->type = EventType::WindowMoved;
        }

        inline Window *getWindow() const { return this->window; }
        inline int getX() const { return this->x; }
        inline int getY() const { return this->y; }

        const char *getName() const override;
        std::string toString() const override;

        inline static void registerCallback(void(*fptr)(WindowMovedEvent*)) {
            callbacks.push_back(fptr);
        }

        inline void runCallbacks() override {
            for (int i = 0; i < callbacks.size(); i++) {
                callbacks[i](this);
            }
        }
    };

    class WindowFocusedEvent : public Event {
    protected:
        Window *window;
        static std::vector<void(*)(WindowFocusedEvent*)> callbacks;

    public:
        WindowFocusedEvent(Window *window) : window(window) {
            this->type = EventType::WindowFocused;
        }

        inline Window *getWindow() const { return this->window; }

        const char *getName() const override;
        std::string toString() const override;

        inline static void registerCallback(void(*fptr)(WindowFocusedEvent*)) {
            callbacks.push_back(fptr);
        }

        inline void runCallbacks() override {
            for (int i = 0; i < callbacks.size(); i++) {
                callbacks[i](this);
            }
        }
    };

    class WindowUnfocusedEvent : public Event {
    protected:
        Window *window;
        static std::vector<void(*)(WindowUnfocusedEvent*)> callbacks;

    public:
        WindowUnfocusedEvent(Window *window) : window(window) {
            this->type = EventType::WindowUnfocused;
        }

        inline Window *getWindow() const { return this->window; }

        const char *getName() const override;
        std::string toString() const override;

        inline static void registerCallback(void(*fptr)(WindowUnfocusedEvent*)) {
            callbacks.push_back(fptr);
        }

        inline void runCallbacks() override {
            for (int i = 0; i < callbacks.size(); i++) {
                callbacks[i](this);
            }
        }
    };

    class WindowClosedEvent : public Event {
    protected:
        Window *window;
        static std::vector<void(*)(WindowClosedEvent*)> callbacks;

    public:
        WindowClosedEvent(Window *window) : window(window) {
            this->type = EventType::WindowClosed;
        }

        inline Window *getWindow() const { return this->window; }

        const char *getName() const override;
        std::string toString() const override;

        inline static void registerCallback(void(*fptr)(WindowClosedEvent*)) {
            callbacks.push_back(fptr);
        }

        inline void runCallbacks() override {
            for (int i = 0; i < callbacks.size(); i++) {
                callbacks[i](this);
            }
        }
    };
}