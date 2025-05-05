#pragma once
#include "feather/window/window.h"

namespace ft {
    enum class GraphicsAPI {
        NONE = 0,
        OPENGL = 1,
        VULKAN = 2,
    };

    GraphicsAPI getGraphicsAPI();
    int initAPI(Window *window);
}