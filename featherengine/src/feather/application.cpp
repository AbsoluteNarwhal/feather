#include "feather/application.h"
#include "feather/core.h"
#include "feather/log.h"
#include "feather/event/keyevent.h"

namespace ft {
    Application::Application() {
        
    }

    void Application::init() {
        LoggerManager::init(this->getClientName());
        this->window = std::make_unique<Window>();
        int success = this->window->initWindow(this->getWindowTitle(), 1280, 720);
        FT_CORE_ASSERT(success == 0, "Failed to create window!");
        success = this->window->initAPI();
        FT_CORE_ASSERT(success == 0, "Failed to initialize OpenGL!");
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

    const char *Application::getClientName() const {
        return "client";
    }

    const char *Application::getWindowTitle() const {
        return "Feather Engine";
    }
}