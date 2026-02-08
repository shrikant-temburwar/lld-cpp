#pragma once
#include <cstddef>

namespace alloc {
// Memory block representing an allocated region
struct MemoryBlock {
    size_t offset; // offset from start of memory pool
    size_t size; // block size in bytes
};
} // namespace alloc
