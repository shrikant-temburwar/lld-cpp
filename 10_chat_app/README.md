# Chat Application (LLD) — Detailed Guide

## 1. Clarifying Requirements
### Functional Requirements
- Users join chat rooms.
- Messages broadcast to all members.

### Non-Functional Requirements
- Thread-safe room operations.

## 2. Core Entities (and Why)
### ChatRoom
Maintains observers and dispatches messages.

### User / ChatObserver
Receives messages and stores them in an inbox.

### ChatService
Creates and retrieves rooms by id.

## 3. Class Design
### ChatRoom
- `join`, `leave`, `send` APIs.
- Uses a mutex to guard observers list.

### User
- Implements `onMessage` to append to inbox.

### ChatService
- Map of roomId → room.

## 4. Workflow Logic (Detailed)
1. User joins room.
2. Sender posts message via `send`.
3. Room dispatches to all observers.
4. Users append to inbox.

## 5. Design Patterns (Why These)
- **Observer**: room broadcasts to users.

## 6. Complexity
- Send: O(number of observers).

## 7. UML
See `uml/chat_uml.puml`.

## 8. Build & Run
```
g++ -std=c++17 -Iinclude src/*.cpp main.cpp -o chat
./chat
```
