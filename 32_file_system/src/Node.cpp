#include "fs/Node.h"

namespace fsbasic {
// Base class constructor stores node name
Node::Node(std::string name) : name_(std::move(name)) {}

// Accessor for node name
const std::string& Node::name() const { return name_; }

// Set weak reference to parent directory (used for path resolution)
void Node::setParent(std::shared_ptr<DirNode> parent) { parent_ = parent; }
} // namespace fsbasic
