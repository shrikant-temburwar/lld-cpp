# ATM (LLD) — Detailed Guide

## 1. Clarifying Requirements
### Functional Requirements
- Withdraw cash.
- Check account balance.

### Non-Functional Requirements
- In-memory accounts, no auth flow.

## 2. Core Entities (and Why)
### BankService
Owns account data and balance updates.

### ATM
Facade for bank operations.

## 3. Class Design
### BankService
- `accounts_` map of id → Account.

### ATM
- Delegates to `BankService` for balance and withdraw.

## 4. Workflow Logic (Detailed)
1. ATM calls `BankService::withdraw` or `balance`.
2. Bank validates funds and updates balance.

## 5. Design Patterns (Why These)
- **Facade**: ATM hides bank complexity.
- **Encapsulation/SRP**: bank owns data updates.

## 6. Complexity
- Withdraw/balance: O(1) average.

## 7. UML
See `uml/atm_uml.puml`.

## 8. Build & Run
```
g++ -std=c++17 -Iinclude src/*.cpp main.cpp -o atm
./atm
```
