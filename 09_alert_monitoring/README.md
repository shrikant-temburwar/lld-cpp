# Alert Monitoring System (LLD) — Detailed Guide

## 1. Clarifying Requirements
### Functional Requirements
- Evaluate metric events against alert rules.
- Notify all registered channels on rule match.

### Non-Functional Requirements
- Thread-safe rule/channel registration and dispatch.

## 2. Core Entities (and Why)
### AlertRule
Encapsulates rule logic (e.g., threshold).

### AlertChannel
Encapsulates delivery mechanism (console, email, SMS).

### AlertManager
Coordinates rules + channels and dispatches alerts.

## 3. Class Design
### ThresholdRule
- Matches when metric exceeds configured threshold.

### ConsoleChannel
- Prints alert message to console.

### AlertManager
- Stores rules/channels and iterates on each metric event.

## 4. Workflow Logic (Detailed)
1. Register rules and channels.
2. `onMetric` receives `{name, value}`.
3. For each matching rule, generate message.
4. Send message to all channels.

## 5. Design Patterns (Why These)
- **Strategy**: rules are pluggable.
- **Observer-like**: manager broadcasts to channels.

## 6. Complexity
- On metric: O(rules × channels).

## 7. UML
See `uml/alert_uml.puml`.

## 8. Build & Run
```
g++ -std=c++17 -Iinclude src/*.cpp main.cpp -o alert
./alert
```
