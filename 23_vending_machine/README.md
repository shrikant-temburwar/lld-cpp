# Vending Machine (LLD) — Detailed Guide

## 1. Clarifying Requirements
### Functional Requirements
- Accept coins and dispense products.
- Maintain inventory counts.

### Non-Functional Requirements
- Single coin type, in-memory storage.

## 2. Core Entities (and Why)
### Inventory
Tracks product info and stock levels.

### VendingMachine
Maintains balance and handles dispense.

## 3. Class Design
### Inventory
- `products_` map and `stock_` map.

### VendingMachine
- `balance_` and inventory instance.

## 4. Workflow Logic (Detailed)
1. `insertCoin`: increase balance.
2. `select`: check stock and balance.
3. Dispense and decrement inventory.
4. `refund`: return remaining balance.

## 5. Design Patterns (Why These)
- **Encapsulation/SRP**: inventory vs payment logic separated.

## 6. Complexity
- Select: O(1) average.

## 7. UML
See `uml/vending_uml.puml`.

## 8. Build & Run
```
g++ -std=c++17 -Iinclude src/*.cpp main.cpp -o vending
./vending
```
