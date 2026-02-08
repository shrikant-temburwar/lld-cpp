#pragma once
#include "ParseStrategy.h"

namespace parser {
// CSV parser implementation using comma-separated values
class CsvParser : public ParseStrategy {
public:
    // Parse CSV content into records (first line = headers)
    std::vector<Record> parse(const std::string& content) const override;
};
} // namespace parser
