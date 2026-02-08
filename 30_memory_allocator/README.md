# Memory Allocator (LLD) — Detailed Guide

## 1. Clarifying Requirements
### Functional Requirements
- Allocate and free blocks from a fixed pool.

### Non-Functional Requirements
- First-fit policy, no coalescing.

## 2. Core Entities (and Why)
### MemoryBlock
Represents a free/allocated segment (offset, size).

### MemoryAllocator
Maintains free list and allocation policy.

## 3. Class Design
### MemoryAllocator
- `freeList_`: list of free ranges.
- `total_`: total size of pool.

## 4. Workflow Logic (Detailed)
1. `allocate`: scan free list and carve block.
2. `free`: return block to free list.

## 5. Design Patterns (Why These)
- **Encapsulation/SRP**: allocator owns free list and policy.

## 6. Complexity
- Allocate: O(n) over free list.
- Free: O(1).

## 7. UML
See `uml/allocator_uml.puml`.

## 8. Build & Run
```
g++ -std=c++17 -Iinclude src/*.cpp main.cpp -o alloc
./alloc
```
