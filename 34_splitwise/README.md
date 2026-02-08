# Splitwise (LLD) — Detailed Guide

## 1. Clarifying Requirements
### Functional Requirements
- Add expenses and split among participants.
- Query balances between users.

### Non-Functional Requirements
- Equal split only; in-memory.

## 2. Core Entities (and Why)
### BalanceSheet
Stores pairwise debts.

### SplitwiseService
Applies split rules and updates sheet.

## 3. Class Design
### BalanceSheet
- `balances_` map from user → user → amount.

### SplitwiseService
- `addExpense` computes share and adds debts.

## 4. Workflow Logic (Detailed)
1. Compute per-person share.
2. Each non-payer owes payer.
3. `balanceBetween` reads balances.

## 5. Design Patterns (Why These)
- **Encapsulation/SRP**: business logic vs storage.

## 6. Complexity
- Add expense: O(n) participants.
- Query: O(1).

## 7. UML
See `uml/splitwise_uml.puml`.

## 8. Build & Run
```
g++ -std=c++17 -Iinclude src/*.cpp main.cpp -o splitwise
./splitwise
```
