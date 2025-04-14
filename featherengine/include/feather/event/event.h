#pragma once

#include "feather/core.h"
#include <queue>

namespace ft {
    enum class EventType {
        None = 0,
        AppTick, AppUpdate, AppRender,
        WindowClosed, WindowResized, WindowFocused, WindowUnfocused, WindowMoved,
        KeyPressed, KeyReleased,
        MouseButtonPressed, MouseButtonReleased, MouseMoved, MouseScrolled,
    };

    class Event {
        friend class EventManager;

    protected:
        bool handled = false;
        EventType type = EventType::None;

    public:
        virtual const char* getName() const = 0;
    };

    class EventManager {
    private:
        static std::queue<Event> eventQueue;    

    public:
        inline static void init() {
            eventQueue = std::queue<Event>();
        }

        inline static int getQueueLength() {
            return eventQueue.size();
        }

        inline static void dispatchEvent(const Event event) {
            EventManager::eventQueue.push(event);
        }
    };
}