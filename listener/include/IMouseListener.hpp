#ifndef _IMOUSE_LISTENER_SUBJECT_H_
#define _IMOUSE_LISTENER_SUBJECT_H_

class IMouseListener {
public:
    IMouseListener() = default;
    virtual ~IMouseListener() = default;
    virtual void onEvent(int cmd, int param1, int param2) = 0;
};

#endif