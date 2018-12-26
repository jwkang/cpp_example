#ifndef _TEST_H_
#define _TEST_H_

#include <thread>
#include <functional>

typedef std::function<void(bool, int)> Callable;

class Test
{
  public:
    Test(int id) : mId(id), mIsRunning(false), mGreeting("Hello"), mT1(NULL), mT2(NULL) {}
    //Test() = delete;
    virtual ~Test();

    void runMultiThread();
    void registerCallback(void (*const fun)(bool, int)); // c sytle but it is unable to call member function as a callback. So, It can't be used.
    void registerCallback(Callable callback);

  private:
    int mId;
    bool mIsRunning;
    const std::string mGreeting;

    std::thread *mT1;
    std::thread *mT2;

    Callable cb; // callback function where upper layer funcation will be called.

  private:
    int run();
};

#endif // _TEST_H_
