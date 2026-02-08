#pragma once
#include "SearchCriteria.h"
#include <string>

namespace search {
// Search criteria that matches nodes by name (substring search)
class NameCriteria : public SearchCriteria {
public:
    explicit NameCriteria(std::string term) : term_(std::move(term)) {}
    // Check if node name contains the search term
    bool match(const std::shared_ptr<fs::Node>& node) const override;

private:
    std::string term_; // search term (substring)
};
} // namespace search
