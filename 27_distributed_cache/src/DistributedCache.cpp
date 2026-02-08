#include "distcache/DistributedCache.h"

namespace distcache {
// Add a cache node and update the hash ring
void DistributedCache::addNode(const std::string& nodeId, std::shared_ptr<CacheNode> node) {
    nodes_[nodeId] = std::move(node);
    ring_.addNode(nodeId); // add node to consistent hash ring
}

// Route put to the node responsible for the key
void DistributedCache::put(const std::string& key, const std::string& value) {
    auto nodeId = ring_.getNode(key); // find responsible node
    if (nodeId.empty()) return; // no node for this key
    nodes_[nodeId]->put(key, value); // store on that node
}

// Route get to the node responsible for the key
std::string DistributedCache::get(const std::string& key) const {
    auto nodeId = ring_.getNode(key); // find responsible node
    if (nodeId.empty()) return ""; // no node for this key
    return nodes_.at(nodeId)->get(key); // retrieve from that node
}
} // namespace distcache
