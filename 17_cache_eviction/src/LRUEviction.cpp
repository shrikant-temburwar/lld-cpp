#include "cache/LRUEviction.h"

namespace cache {
// Move a key to the front of the recency order (most recently used)
void LRUEviction::touch(const std::string& key) {
    auto it = pos_.find(key);
    if (it != pos_.end()) {
        order_.erase(it->second); // remove from current position
    }
    order_.push_front(key); // add to front (mark as recently used)
    pos_[key] = order_.begin(); // update iterator in map
}

// Callback when a key is accessed (mark as recently used)
void LRUEviction::onGet(const std::string& key) { touch(key); }

// Callback when a key is inserted (mark as recently used)
void LRUEviction::onPut(const std::string& key) { touch(key); }

// Callback when a key is removed; clean up tracking
void LRUEviction::onRemove(const std::string& key) {
    auto it = pos_.find(key);
    if (it == pos_.end()) return; // not found
    order_.erase(it->second); // remove from order list
    pos_.erase(it); // remove from position map
}

// Return the least recently used key (at the back of order list)
std::string LRUEviction::evictKey() {
    if (order_.empty()) return ""; // no keys to evict
    return order_.back(); // LRU key
}
} // namespace cache
