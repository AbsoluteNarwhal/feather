#include "feather/application.h"
#include <iostream>

namespace ft {
    Application::Application() {
        
    }

    void Application::run() {
        std::cout << "Hello World!" << std::endl;
    }

    Application::~Application() {
        
    }
}