# Thread-Safe LRU Cache (LLD) — Detailed Guide

## 1. Clarifying Requirements
### Functional Requirements
- Fixed-capacity LRU cache with `get` and `put`.
- Evict least-recently-used on overflow.

### Non-Functional Requirements
- Thread-safe operations.
- O(1) average-time operations.

## 2. Core Entities (and Why)
### Hash Map + List
- Map for O(1) lookup.
- List for O(1) recency updates.

### Mutex
Ensures atomic `get/put` in concurrent use.

## 3. Class Design
### LRUCache
- `order_`: list of keys (front = MRU).
- `map_`: key → (value, list iterator).
- `mutex_`: protects all access.

## 4. Workflow Logic (Detailed)
1. `get`: lock → lookup → move to front → return.
2. `put`: lock → update/insert → evict from back if needed.

## 5. Design Patterns (Why These)
- **Encapsulation/SRP**: cache owns ordering + synchronization.

## 6. Complexity
- `get/put`: O(1) average.

## 7. UML
See `uml/lru_uml.puml`.

## 8. Build & Run
```
g++ -std=c++17 -Iinclude src/*.cpp main.cpp -o lru
./lru
```
