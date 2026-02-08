#include "kv/KeyValueStore.h"
#include <cassert>
#include <iostream>

int main() {
    kv::KeyValueStore store;
    // Store a key-value pair
    store.put("k1", "v1");
    // Retrieve and verify
    assert(store.get("k1").value() == "v1");
    // Remove the key
    store.remove("k1");
    // Verify it's gone
    assert(!store.get("k1").has_value());
    std::cout << "KeyValueStore tests passed\n";
}
