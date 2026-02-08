#include "cache/Cache.h"
#include "cache/LRUEviction.h"
#include <cassert>
#include <iostream>

int main() {
    // Cache with capacity 2 using LRU eviction
    cache::Cache c(2, std::make_unique<cache::LRUEviction>());
    c.put("a", "1");
    c.put("b", "2");
    // Access 'a' to mark it as recently used
    assert(c.get("a").value() == "1");
    // Insert 'c'; should evict 'b' (least recent)
    c.put("c", "3");
    assert(!c.get("b").has_value()); // 'b' was evicted
    std::cout << "Cache eviction tests passed\n";
}
