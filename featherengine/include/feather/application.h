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
        void run();
        ~Application();
    };
}