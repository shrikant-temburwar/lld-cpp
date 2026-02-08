#include "fs/FileSystem.h"
#include <sstream>

namespace fsbasic {
// Helper: split path into components, ignoring empty segments
static std::vector<std::string> splitPath(const std::string& path) {
    std::vector<std::string> parts;
    std::stringstream ss(path);
    std::string item;
    while (std::getline(ss, item, '/')) {
        if (!item.empty()) parts.push_back(item);
    }
    return parts;
}

// Constructor creates root directory
FileSystem::FileSystem() { root_ = std::make_shared<DirNode>(""); }

// Traverse to a directory node by path parts
std::shared_ptr<DirNode> FileSystem::traverseToDir(const std::vector<std::string>& parts) const {
    auto cur = root_;
    for (const auto& part : parts) {
        auto next = std::dynamic_pointer_cast<DirNode>(cur->getChild(part));
        if (!next) return nullptr; // not a directory or not found
        cur = next;
    }
    return cur;
}

// Create a file at the given absolute path
bool FileSystem::createFile(const std::string& path) {
    auto parts = splitPath(path);
    if (parts.empty()) return false; // cannot create root as file
    std::vector<std::string> parent(parts.begin(), parts.end() - 1);
    auto dir = traverseToDir(parent);
    if (!dir) return false; // parent path invalid
    return dir->addChild(std::make_shared<FileNode>(parts.back()));
}

// Create a directory at the given absolute path
bool FileSystem::createDir(const std::string& path) {
    auto parts = splitPath(path);
    if (parts.empty()) return false; // cannot create root
    std::vector<std::string> parent(parts.begin(), parts.end() - 1);
    auto dir = traverseToDir(parent);
    if (!dir) return false; // parent path invalid
    return dir->addChild(std::make_shared<DirNode>(parts.back()));
}

// List entries in a directory
std::vector<std::string> FileSystem::list(const std::string& path) const {
    auto parts = splitPath(path);
    auto dir = traverseToDir(parts);
    if (!dir) return {}; // not a directory
    return dir->list();
}
} // namespace fsbasic
