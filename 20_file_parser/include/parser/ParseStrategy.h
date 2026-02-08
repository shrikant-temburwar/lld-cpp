#pragma once
#include "Record.h"
#include <string>
#include <vector>

namespace parser {
// Abstract strategy for parsing different file formats (Strategy pattern)
class ParseStrategy {
public:
    virtual ~ParseStrategy() = default;
    // Parse content into records
    virtual std::vector<Record> parse(const std::string& content) const = 0;
};
} // namespace parser
