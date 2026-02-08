# Resumable Upload (LLD) — Detailed Guide

## 1. Clarifying Requirements
### Functional Requirements
- Upload file in **chunks**.
- Resume after interruption.
- Track which chunks were received.

### Non-Functional Requirements
- Simple in-memory session state.

## 2. Core Entities (and Why)
### UploadSession
Tracks upload state and received chunk set.

### UploadManager
Creates and manages sessions by `fileId`.

## 3. Class Design
### UploadSession
- State: `Init`, `InProgress`, `Complete`.
- `received_` set records chunk indices.

### UploadManager
- `createSession` and `getSession` APIs.

## 4. Workflow Logic (Detailed)
1. Client creates session with fileId and total chunks.
2. `start()` moves session to InProgress.
3. `uploadChunk(i)` validates and inserts index.
4. `complete()` validates all chunks received.

## 5. Design Patterns (Why These)
- **State**: enforces legal transitions.
- **Factory-like**: manager centralizes session creation.

## 6. Complexity
- `uploadChunk`: O(1)
- `complete`: O(1) (size check)

## 7. UML
See `uml/upload_uml.puml`.

## 8. Build & Run
```
g++ -std=c++17 -Iinclude src/*.cpp main.cpp -o upload
./upload
```

## Test Coverage
- Upload all chunks
- Complete session successfully
