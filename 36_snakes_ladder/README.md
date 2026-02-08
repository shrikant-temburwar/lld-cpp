# Snakes and Ladder (LLD) — Detailed Guide

## 1. Clarifying Requirements
### Functional Requirements
- Model snakes/ladder jumps.
- Move players and detect winner.

### Non-Functional Requirements
- Single-player demo.

## 2. Core Entities (and Why)
### Board
Stores jump rules and applies moves.

### Game
Owns player positions and winner.

## 3. Class Design
### Board
- `jumps_` map for snakes/ladders.

### Game
- `positions_` vector, `winnerIndex_`.

## 4. Workflow Logic (Detailed)
1. Roll dice and compute next position.
2. Apply jump if present.
3. Winner when position reaches 100.

## 5. Design Patterns (Why These)
- **Encapsulation/SRP**: board rules vs game flow.

## 6. Complexity
- Move: O(1).

## 7. UML
See `uml/snl_uml.puml`.

## 8. Build & Run
```
g++ -std=c++17 -Iinclude src/*.cpp main.cpp -o snl
./snl
```
