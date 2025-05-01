#pragma once

#include "feather/event/event.h"
#include "feather/window/window.h"
#include <vector>

namespace ft {
    class KeyEvent : public Event {
    protected:
        int keycode;
        int scancode;
        int mods;

        static std::vector<void(*)(KeyEvent*)> callbacks;

    public:
        KeyEvent(EventType type, int keycode, int scancode, int mods) 
            : keycode(keycode), scancode(scancode), mods(mods) {
            this->type = type;
        }

        const char *getName() const override;
        std::string toString() const override;

        inline int getKeycode() const { return keycode; }
        inline int getScancode() const { return scancode; }
        inline int getMods() const { return mods; }

        inline static void registerCallback(void(*fptr)(KeyEvent*)) {
            callbacks.push_back(fptr);
        }

        inline void runCallbacks() override {
            for (int i = 0; i < callbacks.size(); i++) {
                callbacks[i](this);
            }
        }
    };
}