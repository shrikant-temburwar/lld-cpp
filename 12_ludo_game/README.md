# Ludo Board Game (LLD) — Detailed Guide

## 1. Clarifying Requirements
### Functional Requirements
- Multiple players with colored pieces.
- Dice roll decides movement.
- Winner when all pieces reach goal.

### Non-Functional Requirements
- Minimal rules for interview scope.

## 2. Core Entities (and Why)
### Piece
Tracks position and color.

### Player
Owns a set of pieces.

### Dice
Generates random move values.

### LudoGame
Orchestrates turn flow.

## 3. Class Design
### Piece
- `position_` (-1 = home).

### Player
- Vector of pieces.

### Dice
- Random number generator.

### LudoGame
- Player list, current index, and dice.

## 4. Workflow Logic (Detailed)
1. Add players and start game.
2. Each turn: roll dice, move first piece.
3. Win when all pieces reach 56+.

## 5. Design Patterns (Why These)
- **Encapsulation/SRP**: game flow and randomness separated.

## 6. Complexity
- Turn: O(1) for this simplified model.

## 7. UML
See `uml/ludo_uml.puml`.

## 8. Build & Run
```
g++ -std=c++17 -Iinclude src/*.cpp main.cpp -o ludo
./ludo
```
