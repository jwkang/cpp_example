#ifndef _MOUSE_HANDLER_OBSERVER_H_
#define _MOUSE_HANDLER_OBSERVER_H_

#include "Mouse.hpp"
#include "IMouseListener.hpp"
#include <iostream>
#include <memory>
#include <vector>
#include <map>

using namespace std;

class MouseHandler : public IMouseListener,
                    public enable_shared_from_this<MouseHandler> {
private:
    map<int, shared_ptr<Mouse>> mMouses;

public:
    MouseHandler() = default;
    virtual ~MouseHandler() = default;

    shared_ptr<Mouse> createNewMouse()
    {
        int id = mMouses.size() + 1;
        cout << id << endl;

        shared_ptr<Mouse> new_mouse_instance = make_shared<Mouse>(id);

        new_mouse_instance->addMouseListener(shared_from_this());

        mMouses[id] = new_mouse_instance;

        return new_mouse_instance;
    }

protected:
    void onEvent(int id, int param1, int param2) override
    {
        cout << "[MouseHandler] onEvent() called" << endl;
        cout << "[MouseHandler] id = " << id << endl;
    }
};

#endif
