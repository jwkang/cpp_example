#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unistd.h>
#include <stdio.h>
#include <thread>
#include <future>
#include "_macro.hpp"

using namespace std;

class Test
{
  public:
    Test() : mIsRunning(false), mGreeting("Hello"), mT1(NULL), mT2(NULL) {}
    ~Test()
    {
        cout << "destructing" << endl;

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

    void runMultiThread();
    void runMultiThreadAynsc();
    void stopThread() { mIsRunning = false; }

  private:
    bool mIsRunning;
    const std::string mGreeting;

    std::thread *mT1;
    std::thread *mT2;

  private:
    int run()
    {
        mIsRunning = true;
        while (mIsRunning)
        {
            sleep(1);
            cout << mGreeting << endl;
        }

        return 0;
    }
};

void Test::runMultiThread()
{
    mT1 = new std::thread(&Test::run, this);
    mT2 = new std::thread(&Test::run, this);
}

void Test::runMultiThreadAynsc()
{
    auto f1 = std::async(&Test::run, this);
    auto f2 = std::async(&Test::run, this);

    auto res1 = f1.get();
    auto res2 = f2.get();
}

int main()
{
    Test t;

    LOG("start thread");
    t.runMultiThread();

    for (int i = 0; i < 10; i++)
    {
        LOG("%d", i);
        sleep(1);
    }

    t.stopThread();

    return 0;
}
