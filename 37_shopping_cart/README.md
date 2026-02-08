# Online Shopping Cart (LLD) — Detailed Guide

## 1. Clarifying Requirements
### Functional Requirements
- Add/remove items.
- Compute cart total.

### Non-Functional Requirements
- No discounts/taxes.

## 2. Core Entities (and Why)
### Cart
Stores items and quantities.

### Product
Holds id, name, price.

## 3. Class Design
### Cart
- `items_` map from productId → (Product, qty).

## 4. Workflow Logic (Detailed)
1. `add`: insert product/qty.
2. `remove`: delete productId.
3. `total`: sum price * qty.

## 5. Design Patterns (Why These)
- **Encapsulation/SRP**: cart owns pricing logic.

## 6. Complexity
- Add/remove: O(1); total: O(n).

## 7. UML
See `uml/cart_uml.puml`.

## 8. Build & Run
```
g++ -std=c++17 -Iinclude src/*.cpp main.cpp -o cart
./cart
```
