# Task Scheduler (LLD) — Detailed Guide

## 1. Clarifying Requirements
### Functional Requirements
- Schedule tasks with a delay/priority.
- Execute tasks in order.

### Non-Functional Requirements
- Single-threaded demo.

## 2. Core Entities (and Why)
### Task
Holds id, delay, and action.

### TaskScheduler
Maintains priority queue of tasks.

## 3. Class Design
### TaskScheduler
- Min-heap via `priority_queue` with reversed comparator.

## 4. Workflow Logic (Detailed)
1. `schedule` inserts task into heap.
2. `runOnce` pops earliest task and runs it.

## 5. Design Patterns (Why These)
- **Encapsulation/SRP**: scheduler owns ordering/execution.

## 6. Complexity
- Schedule: O(log n)
- Run: O(log n)

## 7. UML
See `uml/scheduler_uml.puml`.

## 8. Build & Run
```
g++ -std=c++17 -Iinclude src/*.cpp main.cpp -o scheduler
./scheduler
```
