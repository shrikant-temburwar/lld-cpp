#include "search/ContentCriteria.h"
#include "fs/FileNode.h"

namespace search {
// ContentCriteria matches only files (not directories) containing the term
bool ContentCriteria::match(const std::shared_ptr<fs::Node>& node) const {
    auto file = std::dynamic_pointer_cast<fs::FileNode>(node);
    if (!file) return false; // not a file
    return file->read().find(term_) != std::string::npos; // substring match in content
}
} // namespace search
