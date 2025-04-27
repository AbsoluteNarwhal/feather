#include "featherengine.h"

// Note: in the future, the main function should be in the engine, not here. This is just a test to see if the engine works.

class Sandbox : public ft::Application {
public:
    const char *getClientName() const override {
        return "Sandbox";
    }

    const char *getWindowTitle() const override {
        return "Sandbox";
    }
};

int main() {
    Sandbox app;
    app.init();
    app.run();

    FT_LOG_WARN("Hello from Sandbox!");
}