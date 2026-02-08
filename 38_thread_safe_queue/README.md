# Thread-Safe Queue (LLD) — Detailed Guide

## 1. Clarifying Requirements
### Functional Requirements
- Concurrent enqueue/dequeue.
- Blocking `pop`.

### Non-Functional Requirements
- Thread-safe operations.

## 2. Core Entities (and Why)
### ThreadSafeQueue
Owns queue and synchronization primitives.

## 3. Class Design
- `queue_`, `mutex_`, `cv_` for blocking pop.

## 4. Workflow Logic (Detailed)
1. `push`: lock, enqueue, notify.
2. `pop`: wait until queue non-empty, dequeue.

## 5. Design Patterns (Why These)
- **Encapsulation/SRP**: synchronization is internal.

## 6. Complexity
- Push/pop: O(1).

## 7. UML
See `uml/tsq_uml.puml`.

## 8. Build & Run
```
g++ -std=c++17 -Iinclude main.cpp -o tsq
./tsq
```
