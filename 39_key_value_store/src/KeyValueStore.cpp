#include "kv/KeyValueStore.h"

namespace kv {
// Store a key-value pair (overwrites existing)
void KeyValueStore::put(const std::string& key, const std::string& value) {
    data_[key] = value;
}

// Retrieve a value by key; returns nullopt if not found
std::optional<std::string> KeyValueStore::get(const std::string& key) const {
    auto it = data_.find(key);
    if (it == data_.end()) return std::nullopt; // not found
    return it->second;
}

// Remove a key-value pair by key
void KeyValueStore::remove(const std::string& key) {
    data_.erase(key);
}
} // namespace kv
