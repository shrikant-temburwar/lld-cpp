#pragma once
#include "SearchCriteria.h"
#include <vector>

namespace fs { class DirNode; class Node; }

namespace search {
// Search service that performs DFS traversal with criteria matching
class SearchService {
public:
    // Search file system from root using given criteria
    std::vector<std::shared_ptr<fs::Node>> search(
        const std::shared_ptr<fs::DirNode>& root,
        const SearchCriteria& criteria) const;

private:
    // Depth-first search traversal with criteria matching
    void dfs(const std::shared_ptr<fs::Node>& node,
             const SearchCriteria& criteria,
             std::vector<std::shared_ptr<fs::Node>>& out) const;
};
} // namespace search
