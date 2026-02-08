#pragma once
#include <memory>

namespace fs { class Node; }

namespace search {
// Abstract criteria for filtering file system nodes during search
class SearchCriteria {
public:
    virtual ~SearchCriteria() = default;
    // Check if a node matches this criteria
    virtual bool match(const std::shared_ptr<fs::Node>& node) const = 0;
};
} // namespace search
