#pragma once

#include "feather/core.h"
#include <queue>

// TODO: Make Event::getName() and Event::toString() only exist on debug builds

namespace ft {
    enum class EventType {
        None = 0,
        AppTick, AppUpdate, AppRender,
        WindowResized, WindowMoved, WindowFocused, WindowUnfocused, WindowClosed,
        KeyPressed, KeyRepeated, KeyReleased,
        MouseButtonPressed, MouseButtonReleased, MouseMoved, MouseScrolled,
    };

    class Event {
        friend class EventManager;

    protected:
        EventType type = EventType::None;

    public:
        virtual const char* getName() const {
            return "Event(null)";
        }

        virtual std::string toString() const {
            return std::string(this->getName());
        }
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

        inline static void dispatchEvent(const Event& event) {
            EventManager::eventQueue.push(event);
        }

        static void handleAllEvents();
        static void handleFirstEvent();
    };
}