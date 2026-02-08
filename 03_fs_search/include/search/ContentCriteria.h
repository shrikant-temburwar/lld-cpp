#pragma once
#include "SearchCriteria.h"
#include <string>

namespace search {
// Search criteria that matches files by content (substring search in file data)
class ContentCriteria : public SearchCriteria {
public:
    explicit ContentCriteria(std::string term) : term_(std::move(term)) {}
    // Check if file content contains the search term (only applies to files)
    bool match(const std::shared_ptr<fs::Node>& node) const override;

private:
    std::string term_; // search term (substring)
};
} // namespace search
