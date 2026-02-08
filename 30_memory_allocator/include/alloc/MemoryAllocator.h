#pragma once
#include "MemoryBlock.h"
#include <list>
#include <optional>

namespace alloc {
// Simple memory allocator using first-fit algorithm
class MemoryAllocator {
public:
    // Initialize with total memory pool size
    explicit MemoryAllocator(size_t totalSize);

    // Allocate a block of memory (first-fit)
    std::optional<MemoryBlock> allocate(size_t size);
    // Free a previously allocated block
    void free(const MemoryBlock& block);
    // Get total free bytes available
    size_t freeBytes() const;

private:
    size_t total_; // total memory pool size
    std::list<MemoryBlock> freeList_; // list of free blocks
};
} // namespace alloc
