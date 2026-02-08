# IP Address Management (LLD) — Detailed Guide

## 1. Clarifying Requirements
### Functional Requirements
- Allocate an IP for a client.
- Release IP when client disconnects.

### Non-Functional Requirements
- In-memory and simple range management.

## 2. Core Entities (and Why)
### IpPool
Manages free IP addresses.

### IpManager
Tracks client → IP leases.

## 3. Class Design
### IpPool
- `free_` set stores available IPs.

### IpManager
- `leases_` map for client leases.

## 4. Workflow Logic (Detailed)
1. `requestIp`: return existing lease or allocate from pool.
2. `releaseIp`: return IP to pool and remove lease.

## 5. Design Patterns (Why These)
- **Encapsulation/SRP**: separate pool vs lease responsibilities.

## 6. Complexity
- Allocate/release: O(log n) due to set.

## 7. UML
See `uml/ipam_uml.puml`.

## 8. Build & Run
```
g++ -std=c++17 -Iinclude src/*.cpp main.cpp -o ipam
./ipam
```
