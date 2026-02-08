#pragma once
#include "ParseStrategy.h"
#include <memory>

namespace parser {
// File parser that delegates to a parsing strategy (Strategy pattern)
class FileParser {
public:
    // Initialize with a parsing strategy (e.g., CSV, JSON, XML)
    explicit FileParser(std::unique_ptr<ParseStrategy> strategy);
    // Parse content using the injected strategy
    std::vector<Record> parse(const std::string& content) const;

private:
    std::unique_ptr<ParseStrategy> strategy_; // parsing strategy to use
};
} // namespace parser
