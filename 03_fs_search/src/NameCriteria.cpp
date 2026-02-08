#include "search/NameCriteria.h"
#include "fs/Node.h"

namespace search {
// NameCriteria matches if the search term is a substring of the node name
bool NameCriteria::match(const std::shared_ptr<fs::Node>& node) const {
    return node && node->name().find(term_) != std::string::npos;
}
} // namespace search
