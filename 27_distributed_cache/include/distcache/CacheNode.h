#pragma once
#include <string>
#include <unordered_map>

namespace distcache {
// Individual cache node in distributed system
class CacheNode {
public:
    // Store a key-value pair
    void put(const std::string& key, const std::string& value);
    // Retrieve a value by key
    std::string get(const std::string& key) const;

private:
    std::unordered_map<std::string, std::string> data_; // local cache storage
};
} // namespace distcache
