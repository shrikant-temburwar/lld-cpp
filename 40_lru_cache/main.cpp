#include "lru/LRUCache.h"
#include <cassert>
#include <iostream>

int main() {
    // Cache with capacity 2
    lru::LRUCache cache(2);
    cache.put("a", "1");
    cache.put("b", "2");
    // Access 'a' to mark it as most recent
    assert(cache.get("a").value() == "1");
    // Insert 'c'; should evict 'b' (least recent)
    cache.put("c", "3");
    assert(!cache.get("b").has_value()); // 'b' was evicted
    std::cout << "LRU cache tests passed\n";
}
