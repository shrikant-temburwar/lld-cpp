# Lock Manager (LLD) — Detailed Guide

## 1. Clarifying Requirements
### Functional Requirements
- Provide shared and exclusive locks per resource.
- Release locks by owner.

### Non-Functional Requirements
- No wait queues; acquisition fails if incompatible.

## 2. Core Entities (and Why)
### LockManager
Tracks lock state per resource.

## 3. Class Design
### LockManager
- `locks_`: resource → state (shared owners + exclusive owner).
- `mutex_`: guards all access.

## 4. Workflow Logic (Detailed)
1. Shared acquire: fail if another owner holds exclusive.
2. Exclusive acquire: fail if other shared owners exist.
3. Release clears shared or exclusive ownership.

## 5. Design Patterns (Why These)
- **Encapsulation/SRP**: manager owns lock policy.

## 6. Complexity
- Acquire/release: O(1) average.

## 7. UML
See `uml/lockmgr_uml.puml`.

## 8. Build & Run
```
g++ -std=c++17 -Iinclude src/*.cpp main.cpp -o lockmgr
./lockmgr
```
