#pragma once
#include "DirNode.h"
#include "FileNode.h"
#include <memory>
#include <string>
#include <vector>

namespace fsbasic {
// In-memory file system with basic operations
class FileSystem {
public:
    FileSystem();
    // Create a file at the given absolute path
    bool createFile(const std::string& path);
    // Create a directory at the given absolute path
    bool createDir(const std::string& path);
    // List contents of a directory
    std::vector<std::string> list(const std::string& path) const;

private:
    std::shared_ptr<DirNode> root_; // root directory of the file system
    // Helper: traverse to a directory by path components
    std::shared_ptr<DirNode> traverseToDir(const std::vector<std::string>& parts) const;
};
} // namespace fsbasic
