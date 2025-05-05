#pragma once

#include "feather/application.h"
#include "feather/log.h"
#include "feather/core.h"
#include "feather/files.h"

#include "feather/event/event.h"
#include "feather/event/windowevent.h"
#include "feather/event/keyevent.h"
#include "feather/event/mouseevent.h"
#include "feather/event/appevent.h"

#include "feather/renderer/renderer.h"

#ifdef GRAPHICSAPI_OPENGL
#include "feather/opengl/opengl.h"
#include "feather/opengl/shader.h"
#endif