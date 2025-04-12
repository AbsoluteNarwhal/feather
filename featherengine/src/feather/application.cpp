#include "feather/application.h"
#include "feather/log.h"

namespace ft {
    Application::Application() {
        LoggerManager::init("sandbox");
    }

    void Application::run() {
        FT_CORE_LOG_SUCCESS("Feather Engine is running!");
    }

    Application::~Application() {
        
    }
}