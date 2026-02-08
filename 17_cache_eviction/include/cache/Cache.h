#pragma once
#include "EvictionStrategy.h"
#include <memory>
#include <mutex>
#include <optional>
#include <string>
#include <unordered_map>

namespace cache {
// Cache with pluggable eviction strategy (Strategy pattern)
class Cache {
public:
    // Initialize with capacity and eviction strategy
    Cache(size_t capacity, std::unique_ptr<EvictionStrategy> strategy);

    // Get value by key (thread-safe)
    std::optional<std::string> get(const std::string& key);
    // Insert or update key-value pair (thread-safe)
    void put(const std::string& key, const std::string& value);
    // Get current number of entries (thread-safe)
    size_t size() const;

private:
    size_t capacity_; // maximum number of entries
    std::unique_ptr<EvictionStrategy> strategy_; // eviction strategy
    mutable std::mutex mutex_; // protects all operations
    std::unordered_map<std::string, std::string> data_; // key-value storage

    // Evict entries if over capacity
    void evictIfNeeded();
};
} // namespace cache
