#include "fs/DirNode.h"

namespace fs {
// Constructor forwards name to base Node
DirNode::DirNode(std::string name) : Node(std::move(name)) {}

// Add a child node (file or subdirectory) to this directory
bool DirNode::addChild(const std::shared_ptr<Node>& node) {
    if (!node) return false; // null node not allowed
    if (children_.count(node->name())) return false; // duplicate name
    children_[node->name()] = node;
    node->setParent(shared_from_this()); // back-reference
    return true;
}

// Remove a child by name; returns true if a child was removed
bool DirNode::removeChild(const std::string& name) {
    return children_.erase(name) > 0;
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
} // namespace fs
