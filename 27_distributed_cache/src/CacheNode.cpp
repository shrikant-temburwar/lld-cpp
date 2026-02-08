#include "distcache/CacheNode.h"

namespace distcache {
// Store a key-value pair in this cache node
void CacheNode::put(const std::string& key, const std::string& value) {
    data_[key] = value;
}

// Retrieve a value by key; returns empty string if not found
std::string CacheNode::get(const std::string& key) const {
    auto it = data_.find(key);
    if (it == data_.end()) return ""; // not found
    return it->second;
}
} // namespace distcache
