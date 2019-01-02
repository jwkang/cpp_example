#ifndef _MESSAGE_H
#define _MESSAGE_H

#include <memory>

class Message {
public:
    int what;
    int arg1;
    int arg2;
    void* object;

    Message()
        : what(0)
        , arg1(0)
        , arg2(0)
        , object(nullptr)
    {
    }

    Message(int _what, int _arg1 = 0, int _arg2 = 0, void* _object = nullptr)
        : what(_what)
        , arg1(_arg1)
        , arg2(_arg2)
        , object(_object)
    {
    }

    virtual ~Message() {}

    // virtual void reset()
    // {
    //     what = arg1 = arg2 = 0;
    //     object = nullptr;
    // }
};

#endif //_MESSAGE_H