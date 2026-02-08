# Tic Tac Toe (LLD) — Detailed Guide

## 1. Clarifying Requirements
### Functional Requirements
- Two-player turn-based play.
- Detect winner.

### Non-Functional Requirements
- 3x3 board, in-memory.

## 2. Core Entities (and Why)
### Board
Validates moves and checks winner.

### Game
Tracks current player and turn order.

## 3. Class Design
### Board
- 3x3 grid of chars.

### Game
- `current_` toggles between X/O.

## 4. Workflow Logic (Detailed)
1. `play`: place symbol if valid.
2. Toggle player turn.
3. `winner()` evaluates rows, cols, diagonals.

## 5. Design Patterns (Why These)
- **Encapsulation/SRP**: board rules separated from game flow.

## 6. Complexity
- Move: O(1); winner check: O(1).

## 7. UML
See `uml/tictactoe_uml.puml`.

## 8. Build & Run
```
g++ -std=c++17 -Iinclude src/*.cpp main.cpp -o ttt
./ttt
```
