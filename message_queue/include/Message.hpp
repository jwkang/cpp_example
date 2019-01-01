#ifndef _MESSAGE_H
#define _MESSAGE_H

class Message {
private:
    int what;
    int arg1;
    int arg2;

public:
    Message(int _what)
        : what(_what)
        , arg1(0)
        , arg2(0)
    {
    }
    Message(int _what, int _arg1)
        : what(_what)
        , arg1(_arg1)
        , arg2(0)
    {
    }
    Message(int _what, int _arg1, int _arg2)
        : what(_what)
        , arg1(_arg1)
        , arg2(_arg2)
    {
    }

    virtual ~Message() {}
};

#endif //_MESSAGE_H