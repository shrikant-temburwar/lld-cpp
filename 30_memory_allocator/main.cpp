#include "alloc/MemoryAllocator.h"
#include <cassert>
#include <iostream>

int main() {
    alloc::MemoryAllocator ma(100); // 100-byte pool
    // Allocate 40 bytes
    auto b1 = ma.allocate(40);
    assert(b1.has_value());
    // Free the block
    ma.free(*b1);
    // Verify free bytes
    assert(ma.freeBytes() >= 40);
    std::cout << "Memory allocator tests passed\n";
}
