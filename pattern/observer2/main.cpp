#include "EventHandler.hpp"
#include "Subject.hpp"
#include "_macro.hpp"
#include <algorithm>
#include <functional>
#include <iostream>
#include <string>
#include <thread>
#include <unistd.h>
#include <vector>

class MouseMoveEvent : public Event {
};



class MouseEventHandler : public EventHandler<MouseClickEvent> {
private:
    void handleEvent(Subject&, Event const&)
    {
        std::cout << "Mouse Clicked\n";
    }

public:
    MouseEventHandler()
    {
        // Register a call to a member method
        using namespace std::placeholders;

        std::function<void(Subject&, Event const&)> handler
            = std::bind(&MouseEventHandler::handleEvent, this, _1, _2);

        registerEventHandler(handler);
    }
};

class Mouse : public Subject {
};

struct A {
    virtual ~A() {}
};

struct B : A {
};
struct C : A {
};

int main()
{
    MouseEventHandler mouseEventHandler;

    // Tpye2. Register a call to a lambda
    //mouseEventHandler.registerEventHandler<MouseMoveEvent>([](Subject&, Event const&) { std::cout << "Mouse Moved\n"; });
    //mouseEventHandler.registerEventHandler<MouseClickEvent>()

    Mouse mouse;
    mouse.registerObserver(mouseEventHandler);

    // Occur MouseMoveEvent (not working)
    Event event;
    mouse.notifyEvent(event);

    std::cout << "================================" << std::endl;

    // Type2 Register a call to member method
    MouseClickEvent mouseClicked;
    mouse.notifyEvent(mouseClicked);

#if 0
    // Test type_index
    std::unordered_map<std::type_index, std::string> type_names;

    type_names[std::type_index(typeid(int))] = "int";
    type_names[std::type_index(typeid(double))] = "double";
    type_names[std::type_index(typeid(A))] = "A";
    type_names[std::type_index(typeid(B))] = "B";
    type_names[std::type_index(typeid(C))] = "C";

    // note that we're storing pointer to type A
    std::unique_ptr<A> b(new B);
    std::unique_ptr<A> c(new C);

    int i;
    double d;
    A a;
    
    std::cout << "i is " << type_names[std::type_index(typeid(i))] << '\n';
    std::cout << "d is " << type_names[std::type_index(typeid(d))] << '\n';
    std::cout << "a is " << type_names[std::type_index(typeid(a))] << '\n';
    std::cout << "b is " << type_names[std::type_index(typeid(*b))] << '\n';
    std::cout << "c is " << type_names[std::type_index(typeid(*c))] << '\n';

    std::cout << "int is " << type_names[std::type_index(typeid(int))] << '\n';
    std::cout << "double is " << type_names[std::type_index(typeid(double))] << '\n';
#endif
}
