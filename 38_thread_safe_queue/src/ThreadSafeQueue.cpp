#include "tsq/ThreadSafeQueue.h"

namespace tsq {
// Default constructor creates empty queue
template <typename T>
ThreadSafeQueue<T>::ThreadSafeQueue() : stop_(false) {}

// Destructor sets stop flag and notifies all waiting threads
template <typename T>
ThreadSafeQueue<T>::~ThreadSafeQueue() {
    {
        std::lock_guard<std::mutex> lock(mutex_);
        stop_ = true;
    }
    cv_.notify_all();
}

// Push an item onto the queue and notify one waiting thread
template <typename T>
void ThreadSafeQueue<T>::push(const T& item) {
    {
        std::lock_guard<std::mutex> lock(mutex_);
        queue_.push(item);
    }
    cv_.notify_one(); // wake one waiting consumer
}

// Pop an item from the queue; blocks if queue is empty
template <typename T>
T ThreadSafeQueue<T>::pop() {
    std::unique_lock<std::mutex> lock(mutex_);
    cv_.wait(lock, [this]() { return !queue_.empty() || stop_; }); // wait until queue not empty or stopped
    if (stop_ && queue_.empty()) {
        throw std::runtime_error("Queue is stopped and empty");
    }
    T item = queue_.front();
    queue_.pop();
    return item;
}

// Check if queue is empty (thread-safe)
template <typename T>
bool ThreadSafeQueue<T>::empty() const {
    std::lock_guard<std::mutex> lock(mutex_);
    return queue_.empty();
}

// Explicit template instantiation for common types
template class ThreadSafeQueue<int>;
template class ThreadSafeQueue<std::string>;
template class ThreadSafeQueue<std::function<void()>>;
} // namespace tsq
