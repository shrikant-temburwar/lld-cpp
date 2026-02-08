#include "distcache/HashRing.h"
#include <functional>

namespace distcache {
// Simple hash function (mod 1000) for consistent hashing
int HashRing::hash(const std::string& key) const {
    return static_cast<int>(std::hash<std::string>{}(key) % 1000);
}

// Add a node to the hash ring at its hash position
void HashRing::addNode(const std::string& nodeId) {
    ring_[hash(nodeId)] = nodeId;
}

// Find the node responsible for a key using consistent hashing
std::string HashRing::getNode(const std::string& key) const {
    if (ring_.empty()) return ""; // no nodes
    int h = hash(key);
    auto it = ring_.lower_bound(h); // find first node with hash >= h
    if (it == ring_.end()) return ring_.begin()->second; // wrap around
    return it->second;
}
} // namespace distcache
