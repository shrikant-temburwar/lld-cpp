# Thread Pool (LLD) — Detailed Guide

## 1. Clarifying Requirements
### Functional Requirements
- Execute tasks with a fixed number of workers.
- Allow task submission and shutdown.

### Non-Functional Requirements
- Thread-safe task queue.

## 2. Core Entities (and Why)
### ThreadPool
Owns workers and task queue.

## 3. Class Design
### ThreadPool
- `workers_`, `tasks_`, `mutex_`, `cv_`, `stop_`.

## 4. Workflow Logic (Detailed)
1. Constructor spawns workers.
2. `submit` enqueues task and notifies worker.
3. Worker waits on condition variable, executes task.
4. Destructor sets stop flag and joins workers.

## 5. Design Patterns (Why These)
- **Producer/Consumer**: queue + worker threads.
- **Encapsulation/SRP**: centralizes scheduling.

## 6. Complexity
- Submit: O(1)
- Execute: O(1) dequeue

## 7. UML
See `uml/threadpool_uml.puml`.

## 8. Build & Run
```
g++ -std=c++17 -Iinclude src/*.cpp main.cpp -o threadpool
./threadpool
```
