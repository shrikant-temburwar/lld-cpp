#pragma once
#include "CacheNode.h"
#include "HashRing.h"
#include <memory>
#include <unordered_map>

namespace distcache {
// Distributed cache using consistent hashing for key distribution
class DistributedCache {
public:
    // Add a cache node to the distributed system
    void addNode(const std::string& nodeId, std::shared_ptr<CacheNode> node);
    // Store a key-value pair (routes to appropriate node)
    void put(const std::string& key, const std::string& value);
    // Retrieve a value by key (routes to appropriate node)
    std::string get(const std::string& key) const;

private:
    HashRing ring_; // consistent hash ring for key routing
    std::unordered_map<std::string, std::shared_ptr<CacheNode>> nodes_; // node ID -> node mapping
};
} // namespace distcache
