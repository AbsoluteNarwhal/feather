#pragma once

#include "feather/core.h"
#include "feather/event/event.h"
#include "feather/window/window.h"
#include <vector>

namespace ft {
    class AppEvent : public Event {
    protected:
        float delta;
        static std::vector<void(*)(float)> callbacks;

    public:
        AppEvent(EventType type, float delta) : delta(delta) {
            this->type = type;
        }

        const char *getName() const override;
        std::string toString() const override;

        inline static void registerCallback(void(*fptr)(float)) {
            callbacks.push_back(fptr);
        }

        inline void runCallbacks() override {
            for (int i = 0; i < callbacks.size(); i++) {
                callbacks[i](delta);
            }
        }
    };
}