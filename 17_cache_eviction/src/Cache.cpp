#include "cache/Cache.h"

namespace cache {
// Constructor accepts capacity and a pluggable eviction strategy
Cache::Cache(size_t capacity, std::unique_ptr<EvictionStrategy> strategy)
    : capacity_(capacity), strategy_(std::move(strategy)) {}

// Retrieve value by key; notify strategy of access
std::optional<std::string> Cache::get(const std::string& key) {
    std::lock_guard<std::mutex> lock(mutex_);
    auto it = data_.find(key);
    if (it == data_.end()) return std::nullopt; // not found
    strategy_->onGet(key); // inform strategy (e.g., LRU update)
    return it->second;
}

// Insert or update a key-value pair; notify strategy and enforce capacity
void Cache::put(const std::string& key, const std::string& value) {
    std::lock_guard<std::mutex> lock(mutex_);
    data_[key] = value; // store/overwrite
    strategy_->onPut(key); // inform strategy
    evictIfNeeded(); // evict if over capacity
}

// Return current number of entries (thread-safe)
size_t Cache::size() const {
    std::lock_guard<std::mutex> lock(mutex_);
    return data_.size();
}

// Evict entries using the strategy until capacity is satisfied
void Cache::evictIfNeeded() {
    while (data_.size() > capacity_) {
        std::string key = strategy_->evictKey(); // ask strategy for victim
        if (key.empty()) return; // no key to evict
        data_.erase(key); // remove from cache
        strategy_->onRemove(key); // inform strategy of removal
    }
}
} // namespace cache
