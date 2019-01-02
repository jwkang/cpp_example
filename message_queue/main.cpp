#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <MessageHandler.hpp>
#include <Message.hpp>
#include <memory>
#include <unistd.h>
#include "_macro.hpp"

class TestMessageHandler : public MessageHandler {
//protected:
    void handleMessage(std::shared_ptr<Message> message)
    {
        LOG("handleMessage is called");

        switch(message->what) {
            case 0:
                break;
            case 1:
                break;
        }
    }
};


int main()
{
    MessageHandler *handler = new TestMessageHandler();
    handler->start();

    handler->sendMessage(std::make_shared<Message>());
    handler->sendMessage(std::make_shared<Message>());
    handler->sendMessage(std::make_shared<Message>());
    handler->sendMessage(std::make_shared<Message>());
    handler->sendMessage(std::make_shared<Message>());
    handler->sendMessage(std::make_shared<Message>());
    handler->sendMessage(std::make_shared<Message>());
    handler->sendMessage(std::make_shared<Message>());

    LOG("hihihi");
    sleep(3);
    
    delete handler;
}
