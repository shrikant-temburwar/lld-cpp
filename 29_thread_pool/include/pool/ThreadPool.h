#pragma once
#include <condition_variable>
#include <functional>
#include <future>
#include <mutex>
#include <queue>
#include <thread>
#include <vector>

namespace pool {
// Thread pool for concurrent task execution
class ThreadPool {
public:
    // Initialize with specified number of worker threads
    explicit ThreadPool(size_t threads);
    ~ThreadPool();

    // Submit a task for execution and return a future
    std::future<void> submit(std::function<void()> task);

private:
    // Worker thread function that processes tasks
    void worker();

    std::vector<std::thread> workers_; // worker threads
    std::queue<std::function<void()>> tasks_; // task queue
    std::mutex mutex_; // protects task queue
    std::condition_variable cv_; // notifies workers of new tasks
    bool stop_; // shutdown flag
};
} // namespace pool
