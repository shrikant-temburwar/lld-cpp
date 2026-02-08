# Rate Limiter (LLD) — Detailed Guide

## 1. Clarifying Requirements
### Functional Requirements
- Limit requests per client.
- Allow burst up to `maxTokens`.

### Non-Functional Requirements
- Thread-safe.
- O(1) average per request.

## 2. Core Entities (and Why)
### Bucket
Stores tokens and last refill timestamp per client.

### RateLimiter
Maintains buckets and enforces rules.

## 3. Class Design
### RateLimiter
- `maxTokens_`, `refillInterval_`.
- `buckets_`: client → Bucket.
- `mutex_`: guards bucket access.

## 4. Workflow Logic (Detailed)
1. On `allow(clientId)`, load bucket (or create).
2. Refill tokens based on elapsed time.
3. If token available, decrement and allow.

## 5. Design Patterns (Why These)
- **Encapsulation/SRP**: policy is centralized in one class.

## 6. Complexity
- `allow`: O(1)

## 7. UML
See `uml/ratelimiter_uml.puml`.

## 8. Build & Run
```
g++ -std=c++17 -Iinclude src/*.cpp main.cpp -o ratelimit
./ratelimit
```
