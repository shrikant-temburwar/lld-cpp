# In-Memory File System (LLD) — Detailed Guide

## 1. Clarifying Requirements
### Functional Requirements
- Create directories and files by path.
- Read/write file contents.
- Delete files or directories by name.
- List directory contents.

### Non-Functional Requirements
- Operations should be O(depth of path).
- In-memory only; no persistence.

## 2. Core Entities (and Why)
### Need for Uniform Tree Nodes
Files and directories sit in the same hierarchy → use a common `Node` base.

### Need for Child Management
Directories must quickly add/remove/get children → `DirNode` with map storage.

### Need for API Boundary
Path parsing and traversal should be hidden behind a single service → `InMemoryFileSystem`.

## 3. Class Design
### Node
- Stores `name_` and weak `parent_`.

### FileNode
- Stores file data (`data_`) and exposes `read/write`.

### DirNode
- Maintains `children_` map of name → node.

### InMemoryFileSystem
- Owns root directory.
- Implements `createDir`, `createFile`, `readFile`, `writeFile`, `remove`, `list`.

## 4. Workflow Logic (Detailed)
### Path Parsing
`splitPath` converts `/a/b/c` → `[a, b, c]`.

### createDir/createFile
1. Split path; traverse to parent directory.
2. Verify parent exists.
3. Insert new `DirNode` or `FileNode` into parent.

### readFile/writeFile
1. Traverse to node.
2. Verify `FileNode` type.
3. Read or write content.

### remove
1. Traverse to parent directory.
2. Remove child entry by name.

### list
1. Traverse to directory.
2. Return all child names.

## 5. Design Patterns (Why These)
- **Composite**: `Node` allows uniform handling of file and directory nodes.
- **Encapsulation/SRP**: `InMemoryFileSystem` hides traversal and validation logic.

## 6. Complexity
- Create/read/write/remove/list: **O(depth)**
- Space: O(total nodes)

## 7. UML
See `uml/fs_uml.puml`.

## 8. Build & Run
```
g++ -std=c++17 -Iinclude src/*.cpp main.cpp -o fs
./fs
```
