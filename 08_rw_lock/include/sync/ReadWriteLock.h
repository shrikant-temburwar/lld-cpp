#pragma once
#include <condition_variable>
#include <mutex>

namespace sync {
// Read-Write lock allowing multiple readers or exclusive writer
class ReadWriteLock {
public:
    // Acquire read lock (shared access)
    void lockRead();
    // Release read lock
    void unlockRead();
    // Acquire write lock (exclusive access)
    void lockWrite();
    // Release write lock
    void unlockWrite();

private:
    std::mutex mutex_; // protects state
    std::condition_variable cv_; // for waiting on state changes
    int readers_ = 0; // current number of readers
    bool writer_ = false; // whether writer holds the lock
};
} // namespace sync
