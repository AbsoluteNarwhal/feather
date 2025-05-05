#pragma once
#include "feather/window/window.h"
#include "feather/log.h"
#include "feather/core.h"

namespace ft {
    struct OpenGLContextInfo {
        int majorVersion;
        int minorVersion;
        char versionStr[64];
        char vendorStr[32];
        char rendererStr[64];
    };

    int initOpenGL(Window *window);
}