#pragma once
#include <string>

namespace cache {
// Abstract strategy for cache eviction (Strategy pattern)
class EvictionStrategy {
public:
    virtual ~EvictionStrategy() = default;
    // Called when a key is accessed (update recency)
    virtual void onGet(const std::string& key) = 0;
    // Called when a key is inserted or updated
    virtual void onPut(const std::string& key) = 0;
    // Called when a key is removed
    virtual void onRemove(const std::string& key) = 0;
    // Return the key to evict (empty string if none)
    virtual std::string evictKey() = 0;
};
} // namespace cache
