#ifndef THREAD_H
#define THREAD_H

#include <mutex>

#include <rct/EventLoop.h>

class Thread
{
public:
    Thread();
    virtual ~Thread();

    enum Priority { Idle, Normal };
    void start(Priority priority = Normal, size_t stackSize = 0);
    bool join();

    void setAutoDelete(bool on)
    {
        std::lock_guard<std::mutex> lock(mMutex);
        mAutoDelete = on;
    }

    bool isAutoDelete() const
    {
        std::lock_guard<std::mutex> lock(mMutex);
        return mAutoDelete;
    }

    const std::thread &self() const { return mThread; }

protected:
    virtual void run() = 0;

private:
    void finish();

    static void* localStart(void* arg);

private:
    bool mAutoDelete;
    mutable std::mutex mMutex;
    std::thread mThread;
    bool mRunning;
    EventLoop::WeakPtr mLoop;
};

#endif
