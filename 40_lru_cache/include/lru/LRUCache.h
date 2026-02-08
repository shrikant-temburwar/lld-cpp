#pragma once
#include <list>
#include <optional>
#include <string>
#include <unordered_map>

namespace lru {
// LRU (Least Recently Used) cache implementation
class LRUCache {
public:
    explicit LRUCache(size_t capacity);
    // Get value by key; updates recency order
    std::optional<std::string> get(const std::string& key);
    // Insert or update key-value pair; updates recency
    void put(const std::string& key, const std::string& value);
    // Get current number of entries
    size_t size() const;

private:
    using ListIt = std::list<std::string>::iterator;
    size_t capacity_; // maximum number of entries
    std::list<std::string> order_; // recency order: front = most recent
    std::unordered_map<std::string, std::pair<std::string, ListIt>> map_; // key -> (value, iterator in order list)

    // Move key to front of recency order (most recently used)
    void touch(ListIt it);
    // Evict least recently used entries if over capacity
    void evictIfNeeded();
};
} // namespace lru
