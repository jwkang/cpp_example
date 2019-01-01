#ifndef _MESSAGE_H
#define _MESSAGE_H

#include "MessageQueue.hpp"
#include "Message.hpp"

class MessageHandler {
private:
    MessageQueue mMessageQueue;
    bool mIsRunning;
    void loop();

public:
    MessageHandler() : mIsRunning(false) {}
    virtual ~MessageHandler() {}

    void start();
    void stop();
    void clear();
    void sendMessage(std::shared_ptr<Message> message);
};

#endif //_MESSAGE_H