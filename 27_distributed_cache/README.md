# Distributed Cache (LLD) — Detailed Guide

## 1. Clarifying Requirements
### Functional Requirements
- Distribute keys across cache nodes.
- Route get/put using consistent hashing.

### Non-Functional Requirements
- Simple hash ring without virtual nodes.

## 2. Core Entities (and Why)
### HashRing
Determines node for a key.

### CacheNode
Stores key/value pairs on a node.

### DistributedCache
Routes requests via ring.

## 3. Class Design
### HashRing
- `ring_`: map of hash → nodeId.

### DistributedCache
- `nodes_` map and `ring_` instance.

## 4. Workflow Logic (Detailed)
1. Add nodes to ring.
2. `put/get` determine node via ring.
3. Forward to node.

## 5. Design Patterns (Why These)
- **Encapsulation/SRP**: ring handles placement; cache handles routing.

## 6. Complexity
- put/get: O(log n) for ring lookup.

## 7. UML
See `uml/distcache_uml.puml`.

## 8. Build & Run
```
g++ -std=c++17 -Iinclude src/*.cpp main.cpp -o distcache
./distcache
```
