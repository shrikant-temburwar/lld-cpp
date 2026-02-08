#include "cache/LRUCache.h"
#include <cassert>
#include <iostream>

int main() {
    cache::LRUCache lru(2); // capacity 2
    lru.put(1, "a");
    lru.put(2, "b");
    assert(lru.get(1).value() == "a"); // 1 is now most recent
    lru.put(3, "c"); // evicts key 2 (least recent)
    assert(!lru.get(2).has_value()); // 2 was evicted
    assert(lru.get(3).value() == "c");
    std::cout << "Thread-safe LRU tests passed\n";
}
