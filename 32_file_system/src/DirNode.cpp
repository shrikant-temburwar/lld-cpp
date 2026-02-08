#include "fs/DirNode.h"

namespace fsbasic {
// Constructor forwards name to base Node
DirNode::DirNode(std::string name) : Node(std::move(name)) {}

// Add a child node (file or subdirectory) to this directory
bool DirNode::addChild(const std::shared_ptr<Node>& node) {
    if (!node || children_.count(node->name())) return false; // null node or duplicate name
    children_[node->name()] = node;
    node->setParent(shared_from_this()); // back-reference
    return true;
}

// Retrieve a child node by name; nullptr if not found
std::shared_ptr<Node> DirNode::getChild(const std::string& name) const {
    auto it = children_.find(name);
    if (it == children_.end()) return nullptr;
    return it->second;
}

// Return a list of child names (directory entries)
std::vector<std::string> DirNode::list() const {
    std::vector<std::string> names;
    for (const auto& kv : children_) names.push_back(kv.first);
    return names;
}
} // namespace fsbasic
