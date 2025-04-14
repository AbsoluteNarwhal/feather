#pragma once

#include "feather/event/event.h"
#include <sstream>

namespace ft {
    class KeyEvent : public Event {
    protected:
        int keyCode;

    public:
        KeyEvent(EventType type, int keyCode) : keyCode(keyCode) {
            this->type = type;
        }

        const char *getName() const override {
            if (this->type == EventType::KeyPressed) return "KeyEvent(KeyPressed)";
            if (this->type == EventType::KeyRepeated) return "KeyEvent(KeyRepeated)";
            if (this->type == EventType::KeyReleased) return "KeyEvent(KeyReleased)";
            return "KeyEvent(Unknown)";
        }

        std::string toString() const override {
            std::stringstream ss;
            ss << this->getName() << ": Keycode " << this->keyCode;
            return ss.str();
        }
    };
}