#include <iostream>
#include <string>
#include <algorithm>
#include <unistd.h>
#include "_macro.hpp"
#include "MyClass.hpp"

using namespace std;
using namespace std::placeholders;

MyClass::MyClass() : private_x(2019)
{
    // create 10 instances and give them an id.
    for (int i = 0; i < 10; i++)
    {
        shared_ptr<Test> ptr = std::make_shared<Test>(i); // i is an id.
        ptr->registerCallback(std::bind(&MyClass::Callback, this, _1, _2));
        ptr->runMultiThread();
        mTests.push_back(ptr);
    }
}

void MyClass::Callback(bool x, int id)
{
    LOG("MyClass Callback called");
    LOG("parameters(%d). id(%d). private_x(%d)", x, id, private_x);
}
