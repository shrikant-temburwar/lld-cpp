# Job Manager (LLD) — Detailed Guide

## 1. Clarifying Requirements
### Functional Requirements
- Register job types with concurrency rules.
- Start jobs with unique run ids.
- Prevent parallel runs when not allowed.

### Non-Functional Requirements
- Thread-safe bookkeeping.

## 2. Core Entities (and Why)
### JobTypeConfig
Defines type and whether parallel runs are allowed.

### IdGenerator
Generates unique run ids.

### JobManager
Tracks running counts and enforces constraints.

## 3. Class Design
### JobManager
- `configs_`, `runningCount_`, `runToType_` maps.

## 4. Workflow Logic (Detailed)
1. Register types.
2. `startJob`: validate type and parallel rule.
3. Generate `runId`, update counts.
4. `finishJob`: decrement counts and clear mapping.

## 5. Design Patterns (Why These)
- **Generator**: unique ids.
- **Encapsulation/SRP**: manager owns concurrency rules.

## 6. Complexity
- Start/finish: O(1).

## 7. UML
See `uml/job_manager_uml.puml`.

## 8. Build & Run
```
g++ -std=c++17 -Iinclude src/*.cpp main.cpp -o jobmgr
./jobmgr
```
