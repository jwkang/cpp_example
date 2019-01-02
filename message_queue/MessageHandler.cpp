#include "MessageHandler.hpp"

void MessageHandler::start()
{
    mIsRunning = true;
    mLooper = std::thread(&MessageHandler::loop, this);
}

void MessageHandler::stop()
{
    mIsRunning = false;
    mMessageQueue.destory();

    if (mLooper.joinable()) {
        mLooper.join();
    }
}

void MessageHandler::sendMessage(std::shared_ptr<Message> message)
{
    mMessageQueue.enqueue(message);
}

void MessageHandler::clear()
{
    mMessageQueue.clear();
}

void MessageHandler::loop()
{
    while( mIsRunning ) {
        std::shared_ptr<Message> message = mMessageQueue.getMessage(500);

        if (mIsRunning == false ) {
            break;
        }

        handleMessage(message);
    }
}

// This function is declared as a pure virtual function in the header file. 
// In other words, the following code should not be actually executed, but must be overridden.
void MessageHandler::handleMessage(std::shared_ptr<Message> message)
{
    switch (message->what) {
    case 1:
        break;

    case 2:
        break;
    }
}
