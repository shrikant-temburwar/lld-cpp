# File Parser (LLD) — Detailed Guide

## 1. Clarifying Requirements
### Functional Requirements
- Parse file content into records.
- Support multiple formats via strategy.

### Non-Functional Requirements
- Simple CSV implementation for demo.

## 2. Core Entities (and Why)
### ParseStrategy
Encapsulates parsing behavior per format.

### FileParser
Delegates to the chosen strategy.

### CsvParser
Implements CSV parsing.

## 3. Class Design
### CsvParser
- Reads header row for field names.
- Splits each line by comma.

### FileParser
- `parse(content)` delegates to strategy.

## 4. Workflow Logic (Detailed)
1. Build parser with chosen strategy.
2. Strategy reads header and data rows.
3. Each row becomes `Record` with field map.

## 5. Design Patterns (Why These)
- **Strategy**: supports multiple formats.

## 6. Complexity
- O(n) over number of characters/rows.

## 7. UML
See `uml/parser_uml.puml`.

## 8. Build & Run
```
g++ -std=c++17 -Iinclude src/*.cpp main.cpp -o parser
./parser
```
