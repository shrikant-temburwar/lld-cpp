#include "fs/Node.h"
#include "fs/DirNode.h"

namespace fs {
// Base class constructor stores node name
Node::Node(std::string name) : name_(std::move(name)) {}

// Accessor for node name
const std::string& Node::name() const { return name_; }

// Set weak reference to parent directory (used for path resolution)
void Node::setParent(std::shared_ptr<DirNode> parent) { parent_ = parent; }

// Build absolute path from root to this node
std::string Node::path() const {
    auto p = parent_.lock(); // try to lock weak_ptr
    if (!p) return "/" + name_; // no parent => root-level
    if (p->path() == "/") return "/" + name_; // parent is root
    return p->path() + "/" + name_; // concatenate parent path
}
} // namespace fs
