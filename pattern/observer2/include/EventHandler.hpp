#ifndef _EVENTHANDLER_H_
#define _EVENTHANDLER_H_

#include "Observer.hpp"
#include <functional>
#include <iostream>
#include <stdio.h>
#include <typeindex>
#include <unordered_map>

template <typename T>
class EventHandler : public Observer {
public:
    NotifyAction onNotify(Subject& subject, Event const& event) override
    {
        auto find = handlers.find(std::type_index(typeid(T)));

        if (find != handlers.end()) {
            find->second(subject, event);
        }

        return NotifyAction::Done;
    }

    void registerEventHandler(std::function<void(Subject&, Event const&)> handler)
    {
        handlers[std::type_index(typeid(T))] = handler;
    }

private:
    std::unordered_map<std::type_index, std::function<void(Subject&, Event const&)>> handlers;
};

#endif
