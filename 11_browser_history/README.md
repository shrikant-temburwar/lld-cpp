# Browser History (LLD) — Detailed Guide

## 1. Clarifying Requirements
### Functional Requirements
- Visit URLs and move back/forward.
- Clear forward history on new visit.

### Non-Functional Requirements
- O(1) navigation by index.

## 2. Core Entities (and Why)
### BrowserHistory
Owns history list and current index.

## 3. Class Design
- `history_`: vector of URLs.
- `index_`: current position.

## 4. Workflow Logic (Detailed)
1. `visit(url)`: truncate after index, push url, update index.
2. `back(steps)`: clamp index down to 0.
3. `forward(steps)`: clamp index to last.
4. `current()`: return current URL.

## 5. Design Patterns (Why These)
- **Encapsulation/SRP**: centralizes navigation logic.

## 6. Complexity
- `visit/back/forward/current`: O(1) amortized.

## 7. UML
See `uml/history_uml.puml`.

## 8. Build & Run
```
g++ -std=c++17 -Iinclude src/*.cpp main.cpp -o history
./history
```
