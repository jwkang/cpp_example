#ifndef _MESSAGE_HANDLER_H
#define _MESSAGE_HANDLER_H

#include "Message.hpp"
#include "MessageQueue.hpp"
#include <memory>
#include <thread>

class MessageHandler {
private:
    MessageQueue<std::shared_ptr<Message>> mMessageQueue;
    bool mIsRunning;
    std::thread mLooper;
    void loop();

protected:
    virtual void handleMessage(std::shared_ptr<Message> message) = 0;

public:
    MessageHandler()
        : mIsRunning(false)
    {
    }

    virtual ~MessageHandler() { stop(); }

    void start();
    void stop();
    void clear();
    void sendMessage(std::shared_ptr<Message> message);
};

#endif //_MESSAGE_HANDLER_H
