#pragma once
#include <list>
#include <mutex>
#include <optional>
#include <string>
#include <unordered_map>

namespace cache {
// Thread-safe LRU (Least Recently Used) cache implementation
class LRUCache {
public:
    explicit LRUCache(size_t capacity);

    // Get value by key (thread-safe)
    std::optional<std::string> get(int key);
    // Insert or update key-value pair (thread-safe)
    void put(int key, const std::string& value);
    // Get current number of entries (thread-safe)
    size_t size() const;

private:
    using ListIt = std::list<int>::iterator;

    size_t capacity_; // maximum number of entries
    mutable std::mutex mutex_; // protects all operations
    std::list<int> order_; // recency order: front = most recent
    std::unordered_map<int, std::pair<std::string, ListIt>> map_; // key -> (value, iterator in order list)

    // Move key to front of recency order
    void touch(ListIt it);
    // Evict least recently used entries if over capacity
    void evictIfNeeded();
};
} // namespace cache
