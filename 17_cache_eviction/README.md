# Cache Service with Pluggable Eviction (LLD) — Detailed Guide

## 1. Clarifying Requirements
### Functional Requirements
- Store key/value pairs with capacity.
- Evict using a pluggable strategy.

### Non-Functional Requirements
- Thread-safe access.

## 2. Core Entities (and Why)
### EvictionStrategy
Encapsulates eviction policy.

### Cache
Owns storage and delegates eviction.

## 3. Class Design
### LRUEviction
- Maintains order list and key positions.

### Cache
- `data_` map and `strategy_` pointer.

## 4. Workflow Logic (Detailed)
1. `put`: store/update, notify strategy.
2. If over capacity, ask strategy for evict key.
3. Remove entry and notify strategy.
4. `get`: return value and notify strategy.

## 5. Design Patterns (Why These)
- **Strategy**: eviction is replaceable.
- **Encapsulation/SRP**: cache isolates storage.

## 6. Complexity
- get/put: O(1) average.

## 7. UML
See `uml/cache_uml.puml`.

## 8. Build & Run
```
g++ -std=c++17 -Iinclude src/*.cpp main.cpp -o cache
./cache
```
