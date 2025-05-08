#pragma once
#include "feather/window/window.h"
#include "feather/core.h"

namespace ft {
    enum class GraphicsAPI {
        NONE = 0,
        OPENGL = 1,
        VULKAN = 2,
    };

    struct OpenGLContextInfo {
        int majorVersion;
        int minorVersion;
        char versionStr[64];
        char vendorStr[32];
        char rendererStr[64];
    };

    FEATHER_API GraphicsAPI getGraphicsAPI();
    int initAPI(Window *window);

    FEATHER_API OpenGLContextInfo *getOpenGLContextInfo();

#ifndef GRAPHICSAPI_OPENGL
    OpenGLContextInfo *getOpenGLContextInfo() { return nullptr; }
#endif
}