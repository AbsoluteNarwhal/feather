#include "feather/event/event.h"
#include "feather/core.h"
#include "feather/log.h"

namespace ft {
    std::queue<std::unique_ptr<Event>> EventManager::eventQueue;

    void EventManager::handleAllEvents() {
        while (EventManager::getQueueLength() > 0) {
            EventManager::handleEvent(eventQueue.front().get());
            eventQueue.pop();
        }
    }

    void EventManager::handleEvent(Event *event) {
        event->runCallbacks();
    }

    const char* Event::getName() const {
        return "Event(Unknown)";
    }

    std::string Event::toString() const {
        return std::string(this->getName());
    }
}