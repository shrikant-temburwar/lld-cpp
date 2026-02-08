#include "distcache/DistributedCache.h"
#include <cassert>
#include <iostream>

int main() {
    distcache::DistributedCache dc;
    // Add two cache nodes to the ring
    dc.addNode("n1", std::make_shared<distcache::CacheNode>());
    dc.addNode("n2", std::make_shared<distcache::CacheNode>());

    // Store a key-value pair; should be routed to a node
    dc.put("k1", "v1");
    // Retrieve the value; should return the stored value
    assert(!dc.get("k1").empty());
    std::cout << "Distributed cache tests passed\n";
}
