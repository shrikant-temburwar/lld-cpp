# File Sync Service (LLD) — Detailed Guide

## 1. Clarifying Requirements
### Functional Requirements
- Detect file change events.
- Resolve conflicts between local and remote metadata.
- Support pluggable conflict policies.

### Non-Functional Requirements
- Decoupled watcher and sync logic.

## 2. Core Entities (and Why)
### FileWatcher / FileEventListener
Observer pair to propagate change events.

### ConflictStrategy
Encapsulates resolution policy (e.g., last-write-wins).

### SyncService
Orchestrates event handling and conflict resolution.

## 3. Class Design
### FileWatcher
- Maintains list of listeners and notifies them.

### ConflictStrategy / LastWriteWins
- `resolve(local, remote)` chooses winner by timestamp.

### SyncService
- Implements `onChange` and delegates to strategy.

## 4. Workflow Logic (Detailed)
1. Watcher detects a change and calls `notifyChange`.
2. `SyncService` receives the path.
3. Local/remote metadata are compared (modeled via `FileMeta`).
4. Strategy chooses the winning version.
5. Sync action is triggered (printed in demo).

## 5. Design Patterns (Why These)
- **Observer**: decouples detection from reaction.
- **Strategy**: allows multiple conflict policies.

## 6. Complexity
- Event notification: O(listeners)

## 7. UML
See `uml/sync_uml.puml`.

## 8. Build & Run
```
g++ -std=c++17 -Iinclude src/*.cpp main.cpp -o sync
./sync
```

## Test Coverage
- Verify event notification
- Verify conflict strategy selection
