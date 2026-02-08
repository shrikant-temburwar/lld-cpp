# Leaderboard (LLD) — Detailed Guide

## 1. Clarifying Requirements
### Functional Requirements
- Submit/update user scores.
- Query rank of a user.
- Fetch top N players.

### Non-Functional Requirements
- In-memory; order by score.

## 2. Core Entities (and Why)
### Leaderboard
Maintains score buckets and user score map.

## 3. Class Design
- `scoreToUsers_`: score → list of users (sorted by score).
- `userScores_`: user → score.

## 4. Workflow Logic (Detailed)
1. `submitScore`: remove old score bucket entry, insert new one.
2. `getRank`: iterate from highest score until user score bucket.
3. `topN`: walk buckets until N entries collected.

## 5. Design Patterns (Why These)
- **Encapsulation/SRP**: centralizes ranking logic.

## 6. Complexity
- Submit: O(log n)
- Get rank/topN: O(n) in worst case.

## 7. UML
See `uml/leaderboard_uml.puml`.

## 8. Build & Run
```
g++ -std=c++17 -Iinclude src/*.cpp main.cpp -o leaderboard
./leaderboard
```
