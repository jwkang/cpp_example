#include "MouseHandler.hpp"
#include "_macro.hpp"
#include <algorithm>
#include <functional>
#include <iostream>
#include <string>
#include <thread>
#include <unistd.h>
#include <vector>

void run()
{
    for( int i=0; i<10; i++ ) {
        sleep(1);
    }
}

int main()
{
    std::thread t(&run);
    std::shared_ptr<MouseHandler> mouseHandler = make_shared<MouseHandler>();

    std::shared_ptr<Mouse> new_mouse1 = mouseHandler->createNewMouse();
    std::shared_ptr<Mouse> new_mouse2 = mouseHandler->createNewMouse();
    std::shared_ptr<Mouse> new_mouse3 = mouseHandler->createNewMouse();
    std::shared_ptr<Mouse> new_mouse4 = mouseHandler->createNewMouse();

    new_mouse1->doIt();
    new_mouse2->doIt();
    new_mouse3->doIt();
    new_mouse4->doIt();
    
    t.join();


    return 0;
}
