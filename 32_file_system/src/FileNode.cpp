#include "fs/FileNode.h"

namespace fsbasic {
// Constructor forwards name to base Node
FileNode::FileNode(std::string name) : Node(std::move(name)) {}

// Return file content (read-only)
const std::string& FileNode::read() const { return data_; }

// Overwrite file content
void FileNode::write(const std::string& data) { data_ = data; }
} // namespace fsbasic
