#include "lockmgr/LockManager.h"

namespace lockmgr {
// Acquire a shared lock: allow multiple readers, no writers
bool LockManager::acquireShared(const std::string& resource, const std::string& owner) {
    std::lock_guard<std::mutex> lock(mutex_);
    auto& state = locks_[resource];
    // Reject if a writer holds the lock or a different writer owns it
    if (!state.exclusiveOwner.empty() && state.exclusiveOwner != owner) return false;
    state.sharedOwners.insert(owner);
    return true;
}

// Acquire an exclusive lock: no other shared or exclusive owners allowed
bool LockManager::acquireExclusive(const std::string& resource, const std::string& owner) {
    std::lock_guard<std::mutex> lock(mutex_);
    auto& state = locks_[resource];
    // Reject if another exclusive owner exists or shared owners exist (except sole shared owner)
    if ((!state.exclusiveOwner.empty() && state.exclusiveOwner != owner) ||
        (!state.sharedOwners.empty() && !(state.sharedOwners.size() == 1 && state.sharedOwners.count(owner)))) {
        return false;
    }
    // Grant exclusive ownership and clear any shared owners
    state.exclusiveOwner = owner; // set exclusive owner
    state.sharedOwners.clear(); // clear shared owners
    return true;
}

// Release a lock (shared or exclusive) for the given owner
void LockManager::release(const std::string& resource, const std::string& owner) {
    std::lock_guard<std::mutex> lock(mutex_);
    auto it = locks_.find(resource);
    if (it == locks_.end()) return; // unknown resource
    it->second.sharedOwners.erase(owner); // remove from shared owners
    if (it->second.exclusiveOwner == owner) it->second.exclusiveOwner.clear(); // clear exclusive ownership
}
} // namespace lockmgr
