#pragma once

#include "feather/core.h"
#include <queue>
#include <string>
#include <memory>

// TODO: Make Event::getName() and Event::toString() only exist on debug builds

namespace ft {
    enum class EventType {
        None = 0,
        AppTick, AppUpdate, AppRender,
        WindowResized, WindowMoved, WindowFocused, WindowUnfocused, WindowClosed,
        KeyPressed, KeyRepeated, KeyReleased,
        MouseButtonPressed, MouseButtonReleased, MouseMoved, MouseScrolled,
        CustomEvent
    };

    class Event {
        friend class EventManager;

    protected:
        EventType type = EventType::None;

    public:
        EventType getType() const { return type; }
        virtual const char* getName() const;
        virtual std::string toString() const;
        virtual void runCallbacks() {}

        virtual ~Event() = default;
    };

    class EventManager {
    private:
        static std::queue<std::unique_ptr<Event>> eventQueue;    

    public:
        inline static void init() {
            eventQueue = std::queue<std::unique_ptr<Event>>();
        }

        inline static int getQueueLength() {
            return eventQueue.size();
        }

        inline static void dispatchEvent(std::unique_ptr<Event> event) {
            EventManager::eventQueue.push(std::move(event));
        }

        static void handleAllEvents();
        static void handleEvent(Event *event);
    };
}