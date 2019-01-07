#ifndef _OBSERVER_H_
#define _OBSERVER_H_

#include "Event.hpp"

class Subject;

enum class NotifyAction { Done, UnRegister };

class Observer {
public:
    virtual ~Observer() {}
    virtual NotifyAction onNotify(Subject& subject, Event const& event) = 0;
};

#endif
