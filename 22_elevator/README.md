# Elevator System (LLD) — Detailed Guide

## 1. Clarifying Requirements
### Functional Requirements
- Accept floor requests.
- Move elevator toward queued targets.

### Non-Functional Requirements
- Simple single-elevator simulation.

## 2. Core Entities (and Why)
### Elevator
Owns current floor, direction, and request queue.

## 3. Class Design
- `targets_` queue of floor requests.
- `currentFloor_`, `direction_`, `door_` state.

## 4. Workflow Logic (Detailed)
1. `requestFloor` enqueues target.
2. `step()` moves one floor toward target.
3. On arrival, open/close door and pop request.

## 5. Design Patterns (Why These)
- **Encapsulation/SRP**: movement and state in one class.

## 6. Complexity
- Each step: O(1).

## 7. UML
See `uml/elevator_uml.puml`.

## 8. Build & Run
```
g++ -std=c++17 -Iinclude src/*.cpp main.cpp -o elevator
./elevator
```
