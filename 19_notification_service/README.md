# Notification Service (LLD) — Detailed Guide

## 1. Clarifying Requirements
### Functional Requirements
- Send notifications to multiple channels.
- Add new channels dynamically.

### Non-Functional Requirements
- In-memory dispatch; no retries.

## 2. Core Entities (and Why)
### Channel
Encapsulates delivery medium.

### NotificationService
Broadcasts to registered channels.

## 3. Class Design
### EmailChannel
- Prints message in demo.

### NotificationService
- `channels_` vector and mutex for thread-safety.

## 4. Workflow Logic (Detailed)
1. Register channels.
2. `notify` iterates channels and sends message.

## 5. Design Patterns (Why These)
- **Strategy/Polymorphism**: channel implementations are pluggable.
- **Observer-like**: broadcast to all channels.

## 6. Complexity
- Notify: O(number of channels).

## 7. UML
See `uml/notify_uml.puml`.

## 8. Build & Run
```
g++ -std=c++17 -Iinclude src/*.cpp main.cpp -o notify
./notify
```
