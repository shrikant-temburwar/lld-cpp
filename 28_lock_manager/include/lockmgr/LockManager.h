#pragma once
#include "Lock.h"
#include <mutex>
#include <unordered_map>
#include <unordered_set>

namespace lockmgr {
// Lock manager implementing shared/exclusive lock semantics
class LockManager {
public:
    // Acquire a shared lock (multiple readers allowed)
    bool acquireShared(const std::string& resource, const std::string& owner);
    // Acquire an exclusive lock (single writer only)
    bool acquireExclusive(const std::string& resource, const std::string& owner);
    // Release a lock (shared or exclusive)
    void release(const std::string& resource, const std::string& owner);

private:
    // Lock state for a resource
    struct State {
        std::unordered_set<std::string> sharedOwners; // shared lock owners
        std::string exclusiveOwner; // exclusive lock owner (empty if none)
    };
    std::mutex mutex_; // protects lock state
    std::unordered_map<std::string, State> locks_; // resource -> lock state mapping
};
} // namespace lockmgr
