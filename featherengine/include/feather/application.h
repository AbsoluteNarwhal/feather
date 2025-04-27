#pragma once

#include "feather/core.h"
#include "feather/window/window.h"
#include <memory>

namespace ft {
    class FEATHER_API Application {
    private:
        std::unique_ptr<Window> window;

    public:
        Application();
        void init();
        void run();
        ~Application();

        virtual const char *getClientName() const; // used for the name of the logger
        virtual const char *getWindowTitle() const; // used for the window title (self explanatory, right?)
    };
}