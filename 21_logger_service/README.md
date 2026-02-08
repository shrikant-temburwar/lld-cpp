# Logger Service (LLD) — Detailed Guide

## 1. Clarifying Requirements
### Functional Requirements
- Log messages to multiple sinks.
- Add sinks dynamically.

### Non-Functional Requirements
- Thread-safe logging.

## 2. Core Entities (and Why)
### LogSink
Abstracts output destination.

### Logger
Broadcasts messages to all sinks.

## 3. Class Design
### ConsoleSink
- Prints log messages to console.

### Logger
- `sinks_` list guarded by mutex.

## 4. Workflow Logic (Detailed)
1. Register sinks.
2. `log` iterates sinks and writes message.

## 5. Design Patterns (Why These)
- **Strategy/Polymorphism**: sink implementations are pluggable.
- **Observer-like**: broadcast to all sinks.

## 6. Complexity
- Logging: O(number of sinks).

## 7. UML
See `uml/logger_uml.puml`.

## 8. Build & Run
```
g++ -std=c++17 -Iinclude src/*.cpp main.cpp -o logger
./logger
```
