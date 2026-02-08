#pragma once
#include "Node.h"
#include <unordered_map>
#include <vector>

namespace fsbasic {
// Directory node representing a folder in the file system
class DirNode : public Node, public std::enable_shared_from_this<DirNode> {
public:
    explicit DirNode(std::string name);
    // Add a child node (file or subdirectory)
    bool addChild(const std::shared_ptr<Node>& node);
    // Get a child node by name
    std::shared_ptr<Node> getChild(const std::string& name) const;
    // List all child names in this directory
    std::vector<std::string> list() const;

private:
    std::unordered_map<std::string, std::shared_ptr<Node>> children_; // child nodes by name
};
} // namespace fsbasic
