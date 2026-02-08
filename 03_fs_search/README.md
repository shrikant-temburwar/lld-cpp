# File System Search (LLD) — Detailed Guide

## 1. Clarifying Requirements
### Functional Requirements
- Search by **file/dir name** substring.
- Search **file content** substring.
- Traverse entire file system tree.

### Non-Functional Requirements
- Simple DFS traversal.
- Pluggable matching logic.

## 2. Core Entities (and Why)
### SearchCriteria
Defines matching logic (name, content, etc.).

### SearchService
Performs traversal and applies criteria.

## 3. Class Design
### SearchCriteria
- `match(node)` interface.

### NameCriteria / ContentCriteria
- Implement name and content matching respectively.

### SearchService
- DFS traversal; collects matches.

## 4. Workflow Logic (Detailed)
1. Caller chooses a `SearchCriteria` implementation.
2. `SearchService::search` runs DFS from root.
3. Each node is evaluated via `criteria.match`.
4. Matches are collected and returned.

## 5. Design Patterns (Why These)
- **Strategy**: matching logic is pluggable.
- **Visitor-like traversal**: separates traversal from matching.

## 6. Complexity
- O(n) traversal over all nodes.

## 7. UML
See `uml/search_uml.puml`.

## 8. Build & Run
```
g++ -std=c++17 -Iinclude -I..\01_inmemory_fs\include src/*.cpp ..\01_inmemory_fs\src\*.cpp main.cpp -o search
./search
```
