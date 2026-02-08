#pragma once
#include "EvictionStrategy.h"
#include <list>
#include <unordered_map>

namespace cache {
// LRU (Least Recently Used) eviction strategy implementation
class LRUEviction : public EvictionStrategy {
public:
    // Mark key as recently used (called on access)
    void onGet(const std::string& key) override;
    // Mark key as recently used (called on insert/update)
    void onPut(const std::string& key) override;
    // Remove key from tracking
    void onRemove(const std::string& key) override;
    // Return least recently used key for eviction
    std::string evictKey() override;

private:
    using ListIt = std::list<std::string>::iterator;
    std::list<std::string> order_; // recency order: front = most recent
    std::unordered_map<std::string, ListIt> pos_; // key -> position in order list

    // Move key to front of recency order
    void touch(const std::string& key);
};
} // namespace cache
