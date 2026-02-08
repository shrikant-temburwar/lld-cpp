#pragma once
#include "DirNode.h"
#include "FileNode.h"
#include <memory>
#include <string>
#include <vector>

namespace fs {
// In-memory file system implementation with basic operations
class InMemoryFileSystem {
public:
    InMemoryFileSystem();

    // Create a directory at the given absolute path
    bool createDir(const std::string& path);
    // Create a file at the given absolute path
    bool createFile(const std::string& path);
    // Write data to a file (creates file if it doesn't exist)
    bool writeFile(const std::string& path, const std::string& data);
    // Read data from a file
    std::string readFile(const std::string& path) const;
    // Remove a file or directory
    bool remove(const std::string& path);
    // List contents of a directory
    std::vector<std::string> list(const std::string& path) const;

    // Get root directory (for testing)
    std::shared_ptr<DirNode> root() const { return root_; }

private:
    std::shared_ptr<DirNode> root_; // root directory of the file system
    // Helper: traverse to a directory by path components
    std::shared_ptr<DirNode> traverseToDir(const std::vector<std::string>& parts) const;
    // Helper: traverse to any node by path
    std::shared_ptr<Node> traverse(const std::string& path) const;
};
} // namespace fs
