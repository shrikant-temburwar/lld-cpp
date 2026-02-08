#pragma once
#include <condition_variable>
#include <mutex>
#include <queue>
#include <stdexcept>

namespace tsq {
template <typename T>
class ThreadSafeQueue {
public:
    // Default constructor creates empty queue
    ThreadSafeQueue();
    // Destructor sets stop flag and notifies all waiting threads
    ~ThreadSafeQueue();
    
    // Push an item onto the queue and notify one waiting thread
    void push(const T& item);

    // Pop an item from the queue; blocks if queue is empty
    T pop();

    // Check if queue is empty (thread-safe)
    bool empty() const;

private:
    mutable std::mutex mutex_; // protects queue access
    std::condition_variable cv_; // for blocking pop when empty
    std::queue<T> queue_; // underlying queue
    bool stop_ = false; // shutdown flag
};
} // namespace tsq
