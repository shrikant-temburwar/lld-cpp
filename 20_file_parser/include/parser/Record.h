#pragma once
#include <string>
#include <unordered_map>

namespace parser {
// Parsed record with field name to value mapping
struct Record {
    std::unordered_map<std::string, std::string> fields; // column name -> value
};
} // namespace parser
