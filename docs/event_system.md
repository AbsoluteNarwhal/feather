# Feather Event System

Events are actions that can happen during the course of the application, such as a key being pressed or the mouse being moved. Events can be subscribed to using callback functions in order to be notified when one of these events are triggered. For example, you could add a callback for KeyPressedEvents that checks if the space bar is pressed, and makes the player jump if so.

There are multiple kinds of event (see below section), each with a more specific EventType which can be queried with the method `Event::getType()`. Kinds of event usually have different data or callback parameters while EventType is simply used to categorise events. For example, `KeyEvent` is a kind of event and `KeyPressed` is an EventType.

In general, events are dispatched using `EventManager::dispatchEvent(std::unique_ptr<Event> event)` and added to a queue. At the end of the frame, all callback functions associated with the event are called and the event is deleted afterwards. Callback functions can be registered using the static method `registerCallback()` implemented by every event type. The client should not use `dispatchEvent()` on non-custom events as it may break parts of the engine.

For debugging purposes, all events expose the methods `getName()` and `toString()`.

This example creates an event callback to run code when the spacebar is released:

```c++
void keyPressed(KeyEvent *event) {
    if (event->getType() == EventType::KeyReleased && event->getKeycode() == GLFW_KEY_SPACE) {
        // do something!
    }
}

int main() {
    // ...
    KeyEvent::registerCallback(keyPressed);
    // ...
}
```

## Kinds of Event

### AppEvent

AppEvents are events dispatched at set intervals. Callbacks take one `float` argument called `delta` (amount of time since last event of this type) and return `void`. There are three EventTypes of AppEvent: `AppTick`, `AppUpdate` and `AppRender`.

- `AppTick` is dispatched every tick (1 tick = 1/20 seconds).

- `AppUpdate` is dispatched every frame.

- `AppRender` is invoked immediately (not dispatched to the event queue) after buffers are swapped during rendering. These events are blocking and all `AppRender` callbacks must be dealt with immediately before rendering can continue.

### KeyEvent

KeyEvents are dispatched when keys are pressed. Callbacks take one `KeyEvent*` argument (the event) and return `void`. There are three EventTypes of KeyEvent: `KeyPressed`, `KeyRepeated` and `KeyReleased`, which are dispatched when a key is first pressed, held down and released respectively. `KeyEvent` has several methods for getting information about the event:

- `getKeycode()` returns the platform-agnostic GLFW keycode of the key.
- `getScancode()` returns the platform-specific scancode of the key.
- `getMods()` returns the mods while the key was pressed, eg. for checking if shift was pressed.

### MouseButtonEvent

MouseButtonEvents are dispatched when mouse buttons are pressed. Callbacks take one `MouseButtonEvent*` argument (the event) and return `void`. There are two types of MouseButtonEvent: `MouseButtonPressed` and `MouseButtonReleased`. `MouseButtonEvent` has two methods for getting information about the event:

- `getButton()` returns the mouse button that was pressed.
- `getMods()` returns the mods while the button was pressed.

### MouseMovedEvent

MouseMovedEvents are dispatched when the mouse is moved across the window. Callbacks take one `MouseMovedEvent*` argument (the event) and return `void`. `MouseMovedEvent` has two methods for getting information about the event:

- `getX()` returns the new X position of the mouse on the window.
- `getY()` returns the new Y position of the mouse on the window.

### MouseScrolledEvent

MouseScrolledEvents are dispatched when the mouse is scrolled over the window. Callbacks take one `MouseScrolledEvent*` argument (the event) and return `void`. `MouseScrolledEvent` has two methods for getting information about the event:

- `getXOffset()` returns the X offset caused by the scroll (relevant for touchpads).
- `getYOffset()` returns the Y offset caused by the scroll.

### WindowResizedEvent

WindowResizedEvents are dispatched when a window is resized. Callbacks take one `WindowResizedEvent*` argument (the event) and return `void`. `WindowResizedEvent` has three methods for getting information about the event:

- `getWindow()` returns a pointer to the `Window` in question.
- `getWidth()` returns the new width of the window.
- `getHeight()` returns the new height of the window.

### WindowMovedEvent

WindowMovedEvents are dispatched when a window is moved. Callbacks take one `WindowMovedEvent*` argument (the event) and return `void`. `WindowMovedEvent` has three methods for getting information about the event:

- `getWindow()` returns a pointer to the `Window` in question.
- `getX()` returns the new X position of the window.
- `getY()` returns the new Y position of the window.

### WindowFocusedEvent

WindowFocusedEvents are dispatched when a window is focused. Callbacks take one `WindowFocusedEvent*` argument (the event) and return `void`. WindowFocusedEvents expose `getWindow()` which returns a pointer to the `Window` in question.

### WindowUnfocusedEvent

WindowUnfocusedEvents are dispatched when a window is focused. Callbacks take one `WindowUnfocusedEvent*` argument (the event) and return `void`. WindowUnfocusedEvents expose `getWindow()` which returns a pointer to the `Window` in question.

### WindowClosedEvent

WindowClosedEvents are dispatched when a window is closed. Callbacks take one `WindowClosedEvent*` argument (the event) and return `void`. WindowClosedEvents expose `getWindow()` which returns a pointer to the `Window` in question.

## Adding new event types

Feather Engine allows you to define custom events and dispatch them from your own code. Doing this, you can decide:

- The data stored by the event.
- The parameters of the callback function.
- How callback functions are called.
- Results of debug methods `getName()` and `toString()`.

Custom events should use an EventType of `CustomEvent`.

Below is a full example of a custom event:

```c++
#include "featherengine.h"
#include <vector>

class MyCustomEvent : public Event {
protected:
    // Events can have data
    int foo;

    // Here, you can define the parameters of the callback function
    // In this case, we pass a pointer to this event
    static std::vector<void(*)(MyCustomEvent*)> callbacks;

public:
    MyCustomEvent(int foo) : foo(foo) {
        // Always use CustomEvent for custom events.
        this->type = EventType::CustomEvent;
    }

    inline int getFoo() { return foo; }

    inline static void registerCallback(void(*fptr)(MyCustomEvent*)) {
        callbacks.push_back(fptr);
    }

    // This function is automatically called by EventManager::handleEvent() at the end of each frame
    inline void runCallbacks() override {
        for (int i = 0; i < callbacks.size(); i++) {
            callbacks[i](this);
        }
    }
}
```

To dispatch this event:
```c++
EventManager::dispatchEvent(std::make_unique<MyCustomEvent>(foo));
```