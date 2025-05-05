#pragma once
#include "feather/window/window.h"

namespace ft {
    struct OpenGLContextInfo {
        int majorVersion;
        int minorVersion;
        const char versionStr[64];
        const char vendorStr[32];
        const char rendererStr[64];
    };

    int initAPI(Window *window);
}