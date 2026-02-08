#include "pool/ThreadPool.h"

namespace pool {
// Constructor spawns worker threads
ThreadPool::ThreadPool(size_t threads) : stop_(false) {
    for (size_t i = 0; i < threads; ++i) {
        workers_.emplace_back([this]() { worker(); }); // start worker thread
    }
}

// Destructor signals stop and joins all workers
ThreadPool::~ThreadPool() {
    {
        std::lock_guard<std::mutex> lock(mutex_);
        stop_ = true; // signal stop to workers
    }
    cv_.notify_all(); // wake up all workers
    for (auto& w : workers_) w.join(); // wait for workers to finish
}

// Submit a task and return a future for the result
std::future<void> ThreadPool::submit(std::function<void()> task) {
    auto packaged = std::make_shared<std::packaged_task<void()>>(std::move(task));
    std::future<void> fut = packaged->get_future();
    {
        std::lock_guard<std::mutex> lock(mutex_);
        tasks_.push([packaged]() { (*packaged)(); }); // queue task
    }
    cv_.notify_one(); // wake one worker
    return fut;
}

// Worker thread: continuously fetch and execute tasks
void ThreadPool::worker() {
    while (true) {
        std::function<void()> task;
        {
            std::unique_lock<std::mutex> lock(mutex_);
            cv_.wait(lock, [this]() { return stop_ || !tasks_.empty(); }); // wait for work
            if (stop_ && tasks_.empty()) return; // exit if stopping and no tasks
            task = std::move(tasks_.front());
            tasks_.pop();
        }
        task(); // execute task outside lock
    }
}
} // namespace pool
