# File Permission System (LLD) — Detailed Guide

## 1. Clarifying Requirements
### Functional Requirements
- Validate **read/write/execute** permissions for a user.
- Support **user**, **group**, and **other** scopes (Unix-style).
- Allow alternative policies via strategies.

### Non-Functional Requirements
- O(1) permission check.
- Clear separation of policy vs. usage.

## 2. Core Entities (and Why)
### Permissions
Bitmask holder for `user`, `group`, `other` scopes.

### PermissionStrategy
Encapsulates the evaluation policy (e.g., strict Unix).

### PermissionManager
Single entry point used by callers.

## 3. Class Design
### Permissions
- Fields: `user`, `group`, `other` bitmasks (r=4, w=2, x=1).

### PermissionStrategy
- `allow(user, perms, action, isOwner, inGroup)` interface.

### StrictStrategy
- Implements standard Unix semantics.

### PermissionManager
- Owns strategy and delegates checks.

## 4. Workflow Logic (Detailed)
1. Caller builds `Permissions` and identifies `isOwner`/`inGroup`.
2. `PermissionManager::canAccess` delegates to strategy.
3. Strategy maps `Action` to a bitmask.
4. Owner > group > other check order determines allow/deny.

## 5. Design Patterns (Why These)
- **Strategy**: policies can be swapped without changing callers.
- **Encapsulation/SRP**: manager hides policy details.

## 6. Complexity
- `canAccess`: O(1)

## 7. UML
See `uml/perms_uml.puml`.

## 8. Build & Run
```
g++ -std=c++17 -Iinclude src/*.cpp main.cpp -o perms
./perms
```
