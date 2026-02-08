#include "search/SearchService.h"
#include "fs/DirNode.h"

namespace search {
// Public entry point: search from a root directory using a criteria
std::vector<std::shared_ptr<fs::Node>> SearchService::search(
    const std::shared_ptr<fs::DirNode>& root, const SearchCriteria& criteria) const {
    std::vector<std::shared_ptr<fs::Node>> out;
    dfs(root, criteria, out); // depth-first traversal
    return out;
}

// Depth-first search: collect nodes matching the criteria
void SearchService::dfs(const std::shared_ptr<fs::Node>& node,
                        const SearchCriteria& criteria,
                        std::vector<std::shared_ptr<fs::Node>>& out) const {
    if (!node) return;
    if (criteria.match(node)) out.push_back(node); // add if matches
    auto dir = std::dynamic_pointer_cast<fs::DirNode>(node);
    if (!dir) return; // not a directory => no children
    for (const auto& name : dir->list()) {
        auto child = dir->getChild(name);
        dfs(child, criteria, out); // recurse into child
    }
}
} // namespace search
