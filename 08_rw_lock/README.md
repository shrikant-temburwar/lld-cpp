# Read-Write Lock (LLD) — Detailed Guide

## 1. Clarifying Requirements
### Functional Requirements
- Allow multiple concurrent readers.
- Allow only one writer with exclusive access.

### Non-Functional Requirements
- Thread-safe with simple fairness.

## 2. Core Entities (and Why)
### ReadWriteLock
Encapsulates counters and conditions to coordinate readers/writers.

## 3. Class Design
### ReadWriteLock
- `readers_`: active reader count.
- `writer_`: whether a writer holds the lock.
- `mutex_` + `cv_`: synchronization primitives.

## 4. Workflow Logic (Detailed)
1. `lockRead`: wait while `writer_` is true; increment `readers_`.
2. `lockWrite`: wait until no writer and `readers_ == 0`; set `writer_`.
3. `unlockRead`: decrement and notify if last reader exits.
4. `unlockWrite`: clear writer flag and notify all.

## 5. Design Patterns (Why These)
- **Encapsulation/SRP**: lock owns synchronization policy.

## 6. Complexity
- Lock/unlock operations: O(1).

## 7. UML
See `uml/rwlock_uml.puml`.

## 8. Build & Run
```
g++ -std=c++17 -Iinclude src/*.cpp main.cpp -o rwlock
./rwlock
```
