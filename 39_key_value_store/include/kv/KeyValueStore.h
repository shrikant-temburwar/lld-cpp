#pragma once
#include <optional>
#include <string>
#include <unordered_map>

namespace kv {
// Simple key-value store with basic operations
class KeyValueStore {
public:
    // Store a key-value pair (overwrites existing)
    void put(const std::string& key, const std::string& value);
    // Retrieve a value by key; returns nullopt if not found
    std::optional<std::string> get(const std::string& key) const;
    // Remove a key-value pair by key
    void remove(const std::string& key);

private:
    std::unordered_map<std::string, std::string> data_; // key-value storage
};
} // namespace kv
