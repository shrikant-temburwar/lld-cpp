# LRU Cache (LLD) — Detailed Guide

## 1. Clarifying Requirements
### Functional Requirements
- `get(key)`: return value if present; otherwise return empty/`null`.
- `put(key, value)`: insert or update key.
- On capacity overflow, evict **least recently used** (LRU) entry.
- Both `get` and `put` should update recency (move to MRU).

### Non-Functional Requirements
- **O(1)** average time for `get` and `put`.
- Clean, modular design (separation of lookup vs ordering).
- Thread-safety is optional here (see item 06 for thread-safe version).

## 2. Core Entities (and Why)
### Need for Fast Lookup
We need O(1) key access → **hash map** for key → node lookup.

### Need for Fast Ordering
We must move accessed entries to MRU and evict LRU in O(1) → **doubly linked list**.

### Combining Both
- **Hash map** gives O(1) access to list nodes.
- **Doubly linked list** maintains MRU→LRU order.

## 3. Class Design
### LRUCache
- Owns `capacity_`, `order_` (list), and `map_`.
- `order_` front = MRU, back = LRU.
- `map_` stores key → (value, list iterator).

### Why store iterators?
The iterator allows O(1) removal/move inside the list without searching.

## 4. Workflow Logic (Detailed)
### get(key)
1. Look up key in map.
2. If missing, return empty.
3. Move node to front (MRU).
4. Return value.

### put(key, value)
1. If key exists: update value and move to front.
2. If new: push key to front and add map entry.
3. If size > capacity: evict from back (LRU) and remove from map.

## 5. Design Patterns (Why These)
- **Composition**: the cache composes a list + map.
- **Encapsulation/SRP**: LRUCache hides internal ordering logic behind `get/put`.
- **No Strategy Pattern**: eviction is fixed (LRU), so extra abstraction is unnecessary.

## 6. Complexity
- `get`: O(1)
- `put`: O(1)
- Space: O(capacity)

## 7. UML
See `uml/lru_uml.puml`.

## 8. Build & Run
```
g++ -std=c++17 -Iinclude src/*.cpp main.cpp -o lru
./lru
```
