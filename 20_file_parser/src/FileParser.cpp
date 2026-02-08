#include "parser/FileParser.h"

namespace parser {
// Constructor receives a parsing strategy (e.g., CSV, JSON)
FileParser::FileParser(std::unique_ptr<ParseStrategy> strategy)
    : strategy_(std::move(strategy)) {}

// Parse content using the injected strategy
std::vector<Record> FileParser::parse(const std::string& content) const {
    return strategy_->parse(content);
}
} // namespace parser
