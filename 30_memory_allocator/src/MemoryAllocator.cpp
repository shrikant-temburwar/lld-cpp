#include "alloc/MemoryAllocator.h"

namespace alloc {
// Constructor initializes the entire pool as a single free block
MemoryAllocator::MemoryAllocator(size_t totalSize) : total_(totalSize) {
    freeList_.push_back({0, totalSize}); // one free block covering all memory
}

// First-fit allocation: find the first free block that fits
std::optional<MemoryBlock> MemoryAllocator::allocate(size_t size) {
    for (auto it = freeList_.begin(); it != freeList_.end(); ++it) {
        if (it->size >= size) {
            MemoryBlock block{it->offset, size}; // allocate from this block
            it->offset += size; // advance offset
            it->size -= size; // shrink free block
            if (it->size == 0) freeList_.erase(it); // remove empty block
            return block;
        }
    }
    return std::nullopt; // no suitable block
}

// Return a block to the free list (no coalescing for simplicity)
void MemoryAllocator::free(const MemoryBlock& block) {
    freeList_.push_back(block); // add back to free list
}

// Return total free bytes in the pool
size_t MemoryAllocator::freeBytes() const {
    size_t sum = 0;
    for (const auto& b : freeList_) sum += b.size; // sum sizes of all free blocks
    return sum;
}
} // namespace alloc
