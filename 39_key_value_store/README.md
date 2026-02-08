# Key Value Store (LLD) — Detailed Guide

## 1. Clarifying Requirements
### Functional Requirements
- Put/get/remove API.

### Non-Functional Requirements
- In-memory storage.

## 2. Core Entities (and Why)
### KeyValueStore
Owns key/value map.

## 3. Class Design
- `data_` map stores key → value.

## 4. Workflow Logic (Detailed)
1. `put`: insert/update value.
2. `get`: return value or empty.
3. `remove`: delete key.

## 5. Design Patterns (Why These)
- **Encapsulation/SRP**: store owns data.

## 6. Complexity
- put/get/remove: O(1) average.

## 7. UML
See `uml/kv_uml.puml`.

## 8. Build & Run
```
g++ -std=c++17 -Iinclude src/*.cpp main.cpp -o kv
./kv
```
