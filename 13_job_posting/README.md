# Job Posting Service (LLD) — Detailed Guide

## 1. Clarifying Requirements
### Functional Requirements
- Post jobs with flexible attributes.
- Validate job entries.
- Retrieve job by id.

### Non-Functional Requirements
- In-memory storage.
- Extensible validation rules.

## 2. Core Entities (and Why)
### Job
Holds id, type, and attributes.

### JobValidator
Encapsulates validation logic.

### JobRepository
Stores and retrieves jobs.

### JobService
Coordinates validation and persistence.

## 3. Class Design
### BasicValidator
- Simple required field checks.

### JobRepository
- Map id → Job.

### JobService
- `postJob` validates then saves.
- `getJob` fetches from repository.

## 4. Workflow Logic (Detailed)
1. Caller builds a `Job`.
2. `postJob` validates via validator.
3. If valid, repository saves job.
4. `getJob` returns by id.

## 5. Design Patterns (Why These)
- **Strategy**: validators are swappable.
- **Repository**: storage isolated from service logic.

## 6. Complexity
- Post/get: O(1).

## 7. UML
See `uml/job_posting_uml.puml`.

## 8. Build & Run
```
g++ -std=c++17 -Iinclude src/*.cpp main.cpp -o jobs
./jobs
```
