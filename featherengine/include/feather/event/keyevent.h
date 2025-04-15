#pragma once

#include "feather/event/event.h"
#include <sstream>

namespace ft {
    class KeyEvent : public Event {
    protected:
        int keycode;
        int scancode;
        int mods;

    public:
        KeyEvent(EventType type, int keycode, int scancode, int mods) 
            : keycode(keycode), scancode(scancode), mods(mods) {
            this->type = type;
        }

        const char *getName() const override;
        std::string toString() const override;
    };
}