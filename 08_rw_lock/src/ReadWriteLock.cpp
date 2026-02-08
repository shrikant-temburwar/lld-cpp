#include "sync/ReadWriteLock.h"

namespace sync {
// Acquire a shared read lock; blocks while a writer holds the lock
void ReadWriteLock::lockRead() {
    std::unique_lock<std::mutex> lock(mutex_);
    cv_.wait(lock, [this]() { return !writer_; }); // wait until no writer
    ++readers_; // increment reader count
}

// Release a read lock; notify waiting writers if this was the last reader
void ReadWriteLock::unlockRead() {
    std::lock_guard<std::mutex> lock(mutex_);
    --readers_;
    if (readers_ == 0) cv_.notify_all(); // wake writers when no readers remain
}

// Acquire an exclusive write lock; blocks while any reader or writer is active
void ReadWriteLock::lockWrite() {
    std::unique_lock<std::mutex> lock(mutex_);
    cv_.wait(lock, [this]() { return !writer_ && readers_ == 0; }); // wait for exclusive access
    writer_ = true; // mark as writer
}

// Release a write lock; notify all waiting readers and writers
void ReadWriteLock::unlockWrite() {
    std::lock_guard<std::mutex> lock(mutex_);
    writer_ = false;
    cv_.notify_all(); // wake everyone
}
} // namespace sync
