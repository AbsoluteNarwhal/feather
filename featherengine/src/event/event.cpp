#include "feather/event/event.h"
#include "feather/core.h"

namespace ft {
    std::queue<Event> EventManager::eventQueue;
}