# File System (LLD) — Detailed Guide

## 1. Clarifying Requirements
### Functional Requirements
- Create files and directories.
- List directory contents.

### Non-Functional Requirements
- In-memory operations.

## 2. Core Entities (and Why)
### Node
Base abstraction for file/dir nodes.

### DirNode
Manages child nodes.

### FileSystem
Public API for creation and listing.

## 3. Class Design
### DirNode
- `children_` map of name → node.

### FileSystem
- `root_` and `traverseToDir` helper.

## 4. Workflow Logic (Detailed)
1. Split path and locate parent directory.
2. Create node and attach to parent.
3. `list` returns children names.

## 5. Design Patterns (Why These)
- **Composite**: uniform node handling.
- **Encapsulation/SRP**: FS hides traversal logic.

## 6. Complexity
- Create/list: O(depth).

## 7. UML
See `uml/filesystem_uml.puml`.

## 8. Build & Run
```
g++ -std=c++17 -Iinclude src/*.cpp main.cpp -o fsbasic
./fsbasic
```
