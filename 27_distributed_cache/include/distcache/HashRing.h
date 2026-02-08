#pragma once
#include <map>
#include <string>
#include <vector>

namespace distcache {
// Consistent hash ring for distributing keys across nodes
class HashRing {
public:
    // Add a cache node to the ring
    void addNode(const std::string& nodeId);
    // Get the node responsible for a key
    std::string getNode(const std::string& key) const;

private:
    std::map<int, std::string> ring_; // hash -> node mapping (sorted)
    // Simple hash function for consistent hashing
    int hash(const std::string& key) const;
};
} // namespace distcache
