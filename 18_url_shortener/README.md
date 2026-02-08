# URL Shortener (LLD) — Detailed Guide

## 1. Clarifying Requirements
### Functional Requirements
- Shorten long URLs into short codes.
- Resolve short codes to original URLs.

### Non-Functional Requirements
- In-memory storage for mappings.

## 2. Core Entities (and Why)
### IdGenerator
Generates unique codes (base-36).

### UrlRepository
Stores code → URL mappings.

### UrlShortener
Coordinates generation and lookup.

## 3. Class Design
### IdGenerator
- Uses atomic counter and base-36 encoding.

### UrlRepository
- `data_` map for code → url.

### UrlShortener
- Owns generator and repository.

## 4. Workflow Logic (Detailed)
1. `shorten(url)` generates a new code.
2. Repository saves code → url.
3. `resolve(code)` returns stored URL.

## 5. Design Patterns (Why These)
- **Generator**: isolates code creation.
- **Repository**: isolates storage.

## 6. Complexity
- Shorten/resolve: O(1) average.

## 7. UML
See `uml/shortener_uml.puml`.

## 8. Build & Run
```
g++ -std=c++17 -Iinclude src/*.cpp main.cpp -o shortener
./shortener
```
