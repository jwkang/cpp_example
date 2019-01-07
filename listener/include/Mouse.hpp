#ifndef _MOUSE_H_
#define _MOUSE_H_

#include "IMouseListener.hpp"
#include <memory>

using namespace std;

class Mouse {
private:
    int mId;
    shared_ptr<IMouseListener> mListener;

public:
    Mouse(int id)
        : mId(id)
    {
    }

    virtual ~Mouse() = default;    

    void addMouseListener(shared_ptr<IMouseListener> listener)
    {
        mListener = listener;
    }

    void doIt()
    {
        mListener->onEvent(mId, 1, 1);
    }
};

#endif
