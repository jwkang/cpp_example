#ifndef _SUBJECT_H_
#define _SUBJECT_H_

#include "Observer.hpp"
#include <algorithm>
#include <functional>
#include <iostream>
#include <stdexcept>
#include <vector>

class Subject {
public:
    void registerObserver(Observer& observer)
    {
        if (std::find(std::begin(observers), std::end(observers), &observer) == std::end(observers)) {
            // registerObserver
            observers.push_back(&observer);
        }
    }

    void unregisterObserver(Observer& observer)
    {
        observers.erase(std::remove(std::begin(observers), std::end(observers), &observer), std::end(observers));
    }

    void notifyEvent(Event const& event)
    {
        for (Observer* observer : observers) {
            observer->onNotify(*this, event);
        }
    }

private:
    std::vector<Observer*> observers;
};

#endif