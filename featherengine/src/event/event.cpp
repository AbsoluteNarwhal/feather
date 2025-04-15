#include "feather/event/event.h"
#include "feather/core.h"
#include "feather/log.h"

namespace ft {
    std::queue<std::unique_ptr<Event>> EventManager::eventQueue;

    void EventManager::handleAllEvents() {
        while (EventManager::getQueueLength() > 0) {
            EventManager::handleFirstEvent();
        }
    }

    void EventManager::handleFirstEvent() {
        FT_CORE_LOG("{0}", eventQueue.front()->toString());
        eventQueue.pop();
    }

    const char* Event::getName() const {
        return "Event(null)";
    }

    std::string Event::toString() const {
        return std::string(this->getName());
    }
}