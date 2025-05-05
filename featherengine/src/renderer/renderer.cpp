#include "feather/renderer/renderer.h"
#include "feather/core.h"
#include "feather/log.h"

#ifdef GRAPHICSAPI_OPENGL
#include "opengl/opengl.h"
#endif

namespace ft {
    GraphicsAPI getGraphicsAPI() {
#ifdef GRAPHICSAPI_OPENGL
        return GraphicsAPI::OPENGL;
#elif defined(GRAPHICSAPI_VULKAN)
        return GraphicsAPI::VULKAN;
#else
        return GraphicsAPI::NONE;
#endif
    }

    int initAPI(Window *window) {
#ifdef GRAPHICSAPI_OPENGL
        return initOpenGL(window);
#endif
        return -1;
    }
}