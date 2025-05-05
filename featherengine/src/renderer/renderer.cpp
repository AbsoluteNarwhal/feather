#include "feather/renderer/renderer.h"
#include "feather/core.h"
#include "feather/log.h"

#ifdef GRAPHICSAPI_OPENGL
#include "feather/opengl/opengl.h"
#endif

namespace ft {
    int initAPI(Window *window) {
#ifdef GRAPHICSAPI_OPENGL
        return initOpenGL(window);
#endif
        return -1;
    }
}