# Chess (LLD) — Detailed Guide

## 1. Clarifying Requirements
### Functional Requirements
- Represent a chess board.
- Move pieces between squares.

### Non-Functional Requirements
- Minimal rules (bounds + non-empty source).

## 2. Core Entities (and Why)
### Board
Owns board state and move validation.

### Piece
Represents type and color.

## 3. Class Design
### Board
- `grid_` 8x8 of `Piece`.

### Piece
- `type` and `color`.

## 4. Workflow Logic (Detailed)
1. Validate bounds and source piece.
2. Move piece and clear source.

## 5. Design Patterns (Why These)
- **Encapsulation/SRP**: board owns rules.

## 6. Complexity
- Move: O(1).

## 7. UML
See `uml/chess_uml.puml`.

## 8. Build & Run
```
g++ -std=c++17 -Iinclude src/*.cpp main.cpp -o chess
./chess
```
