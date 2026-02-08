# Parking Lot (LLD) — Detailed Guide

## 1. Clarifying Requirements
### Functional Requirements
- Park and unpark vehicles.
- Support spot types (compact/large).

### Non-Functional Requirements
- Single-floor in-memory lot.

## 2. Core Entities (and Why)
### Spot
Represents a physical spot and occupancy.

### ParkingLot
Allocates spots by type.

## 3. Class Design
### Spot
- `id_`, `type_`, `vehicleId_`.

### ParkingLot
- `spots_` list scanned for availability.

## 4. Workflow Logic (Detailed)
1. Add spots to lot.
2. `parkVehicle`: find first free spot of requested type.
3. `leaveSpot`: clear occupancy.

## 5. Design Patterns (Why These)
- **Encapsulation/SRP**: spot vs allocation logic separated.

## 6. Complexity
- Park/leave: O(n) scan.

## 7. UML
See `uml/parking_uml.puml`.

## 8. Build & Run
```
g++ -std=c++17 -Iinclude src/*.cpp main.cpp -o parking
./parking
```
