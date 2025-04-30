#include "feather/core.h"
#include "feather/event/appevent.h"
#include <sstream>

namespace ft {
    std::vector<void(*)(float)> AppEvent::callbacks;

    const char *AppEvent::getName() const {
        if (this->type == EventType::AppTick) return "AppEvent(AppTick)";
        if (this->type == EventType::AppUpdate) return "AppEvent(AppUpdate)";
        if (this->type == EventType::AppRender) return "AppEvent(AppRender)";
        return "AppEvent(Unknown)";
    }

    std::string AppEvent::toString() const {
        std::stringstream ss;
        ss << this->getName() << ": Delta " << this->delta;
        return ss.str();
    }
}