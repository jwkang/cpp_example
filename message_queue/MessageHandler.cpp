#include "MessageHandler.hpp"

void MessageHandler::start()
{
    mIsRunning = true;
    mLooper = std::thread(&MessageHandler::loop, this);
}

void MessageHandler::stop()
{
    mIsRunning = false;
    if (mLooper.joinable()) {
        mLooper.join();
    }
    clear();
    mMessageQueue.destory();
}

void MessageHandler::sendMessage(shared_ptr<Message> message)
{
    mMessageQueue.enqueue(message);
}

void MessageHandler::clear()
{
    mMessageQueue.clear();
}

void MessageHandler::loop()
{
    while (mIsRunning) {
        std::shared_ptr<Message> message = mMessageQueue.getMessage();

        if (mIsRunning == false) {
            break;
        }

        switch (message->what) {
        case 1:
            break;

        case 2:
            break;
        }
    }
}