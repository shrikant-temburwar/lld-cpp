#include "cache/LRUCache.h"

namespace cache {
// Constructor sets capacity
LRUCache::LRUCache(size_t capacity) : capacity_(capacity) {}

// Retrieve value by key; updates recency order; returns nullopt if not found
std::optional<std::string> LRUCache::get(int key) {
    std::lock_guard<std::mutex> lock(mutex_);
    auto it = map_.find(key);
    if (it == map_.end()) return std::nullopt;
    touch(it->second.second); // move key to front (most recently used)
    return it->second.first;
}

// Insert or update a key-value pair; updates recency; evicts if over capacity
void LRUCache::put(int key, const std::string& value) {
    std::lock_guard<std::mutex> lock(mutex_);
    auto it = map_.find(key);
    if (it != map_.end()) {
        it->second.first = value; // update value
        touch(it->second.second); // mark as recently used
        return;
    }
    // Insert new key at front of order list
    order_.push_front(key);
    map_[key] = {value, order_.begin()};
    evictIfNeeded(); // enforce capacity
}

// Return current number of entries (thread-safe)
size_t LRUCache::size() const {
    std::lock_guard<std::mutex> lock(mutex_);
    return map_.size();
}

// Move a key to the front of the recency order (most recently used)
void LRUCache::touch(ListIt it) {
    int key = *it;
    order_.erase(it); // remove from current position
    order_.push_front(key); // insert at front
    map_[key].second = order_.begin(); // update iterator in map
}

// Evict least recently used entries until capacity is satisfied
void LRUCache::evictIfNeeded() {
    while (map_.size() > capacity_) {
        int key = order_.back(); // LRU key at back
        order_.pop_back();
        map_.erase(key); // remove from map
    }
}
} // namespace cache
