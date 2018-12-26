#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unistd.h>
#include <stdio.h>
#include "_macro.hpp"
#include "Test.hpp"
#include "MyClass.hpp"

using namespace std;

void Test::runMultiThread()
{
    mIsRunning = true;

    mT1 = new std::thread(&Test::run, this);
    mT2 = new std::thread(&Test::run, this);
}

int Test::run()
{
    while (mIsRunning)
    {
        sleep(1);
        cout << mGreeting << endl;

        // call callback function
        if (cb)
        {
            cb(true, mId);
        }
    }

    return 0;
}

Test::~Test()
{
    LOG("destructing(%d)", mId);

    mIsRunning = false;

    if (mT1 && mT1->joinable())
    {
        cout << "wait for T1" << endl;
        mT1->join();
        delete mT1;
    }

    if (mT2 && mT2->joinable())
    {
        cout << "wait for T2" << endl;
        mT2->join();
        delete mT2;
    }
}

// C Style
void Test::registerCallback(void (*const fun)(bool, int))
{
    cb = fun;
}

// C++ Style
void Test::registerCallback(Callable callback)
{
    cb = std::move(callback);
}