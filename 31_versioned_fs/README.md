# Versioned File System (LLD) — Detailed Guide

## 1. Clarifying Requirements
### Functional Requirements
- Store multiple versions per file.
- Read specific version.

### Non-Functional Requirements
- Sequential versioning starting at 1.

## 2. Core Entities (and Why)
### VersionedFile
Maintains versions for a single file.

### VersionedFileSystem
Routes operations by path.

## 3. Class Design
### VersionedFile
- `versions_` vector of `{version, content}`.

### VersionedFileSystem
- `files_` map of path → file.

## 4. Workflow Logic (Detailed)
1. `write`: append version.
2. `read`: return content for version.
3. `latestVersion`: return size.

## 5. Design Patterns (Why These)
- **Encapsulation/SRP**: file vs filesystem responsibilities.

## 6. Complexity
- Write/read: O(1).

## 7. UML
See `uml/versioned_fs_uml.puml`.

## 8. Build & Run
```
g++ -std=c++17 -Iinclude src/*.cpp main.cpp -o vfs
./vfs
```
