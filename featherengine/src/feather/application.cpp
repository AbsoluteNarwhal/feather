#include "feather/application.h"
#include "feather/core.h"
#include "feather/log.h"
#include "feather/event/event.h"

namespace ft {
    Application::Application() {
        LoggerManager::init("sandbox");
        this->window = std::make_unique<Window>();
        int success = this->window->initWindow("Feather Engine", 1280, 720);
    }

    void Application::run() {
        FT_CORE_LOG_SUCCESS("Feather Engine is running!");
        while (true) {
            this->window->swapAndPoll();
            EventManager::handleAllEvents();
            if (this->window->shouldClose()) break;
        }
    }

    Application::~Application() {
        Window::cleanupAll();
    }
}