#ifndef _MESSAGEQUEUE_H
#define _MESSAGEQUEUE_H

#include <condition_variable>
#include <mutex>
#include <queue>

using namespace std;

template <class T>
class MessageQueue {
private:
    std::queue<T> mQueue;
    mutable std::mutex mMutex;
    std::condition_variable mCondition;
    bool mIsLoop;

public:
    MessageQueue(void)
        : mQueue()
        , mMutex()
        , mCondition()
    {
        mIsLoop = true;
    }

    MessageQueue(MessageQueue const&) = delete;
    MessageQueue& operator=(MessageQueue const&) = delete;

    virtual ~MessageQueue(void) = default;

    void clear()
    {
        std::lock_guard<std::mutex> lock(mMutex);
        std::queue<T> emptyQueue;
        std::swap(mQueue, emptyQueue);
    }

    void enqueue(T t)
    {
        std::lock_guard<std::mutex> lock(mMutex);
        mQueue.push(t);
        mCondition.notify_one();
    }

    void destory()
    {
        mIsLoop = false;
        mCondition.notify_one();
    }

    T getMessage(void)
    {
        std::unique_lock<std::mutex> lock(mMutex);
        while ((mIsLoop) && (mQueue.empty())) {
        mCondition.wait(lock);
        }
        T val = mQueue.front();
        mQueue.pop();
        return val;
    }
};

#endif //_MESSAGEQUEUE_H