#pragma once

#include "feather/window/window.h"
#include <memory>

namespace ft {
    class Application {
    private:
        std::unique_ptr<Window> window;

    public:
        Application();
        void run();
        ~Application();
    };
}