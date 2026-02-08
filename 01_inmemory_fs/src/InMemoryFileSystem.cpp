#include "fs/InMemoryFileSystem.h"
#include "fs/PathUtils.h"

namespace fs {
// Constructor: initialize root directory
InMemoryFileSystem::InMemoryFileSystem() {
    root_ = std::make_shared<DirNode>(""); // root has empty name
}

// Traverse to a directory node given path parts (excluding final name)
std::shared_ptr<DirNode> InMemoryFileSystem::traverseToDir(const std::vector<std::string>& parts) const {
    auto cur = root_;
    for (const auto& part : parts) {
        auto next = std::dynamic_pointer_cast<DirNode>(cur->getChild(part));
        if (!next) return nullptr; // path component not a directory
        cur = next;
    }
    return cur;
}

// General traversal: returns any node (file or dir) at absolute path
std::shared_ptr<Node> InMemoryFileSystem::traverse(const std::string& path) const {
    if (path == "/") return root_; // special case: root
    auto parts = splitPath(path);
    auto cur = std::static_pointer_cast<Node>(root_);
    for (const auto& part : parts) {
        auto dir = std::dynamic_pointer_cast<DirNode>(cur);
        if (!dir) return nullptr; // cannot descend into a file
        cur = dir->getChild(part);
        if (!cur) return nullptr; // component not found
    }
    return cur;
}

// Create a directory at the given absolute path
bool InMemoryFileSystem::createDir(const std::string& path) {
    auto parts = splitPath(path);
    if (parts.empty()) return false; // cannot create root
    std::vector<std::string> parentParts(parts.begin(), parts.end() - 1);
    auto parent = traverseToDir(parentParts);
    if (!parent) return false; // parent path invalid
    return parent->addChild(std::make_shared<DirNode>(parts.back()));
}

// Create a file at the given absolute path
bool InMemoryFileSystem::createFile(const std::string& path) {
    auto parts = splitPath(path);
    if (parts.empty()) return false; // cannot create root as file
    std::vector<std::string> parentParts(parts.begin(), parts.end() - 1);
    auto parent = traverseToDir(parentParts);
    if (!parent) return false; // parent path invalid
    return parent->addChild(std::make_shared<FileNode>(parts.back()));
}

// Write data to a file; overwrites existing content
bool InMemoryFileSystem::writeFile(const std::string& path, const std::string& data) {
    auto node = traverse(path);
    auto file = std::dynamic_pointer_cast<FileNode>(node);
    if (!file) return false; // not a file or does not exist
    file->write(data);
    return true;
}

// Read file content; returns empty string if not a file or missing
std::string InMemoryFileSystem::readFile(const std::string& path) const {
    auto node = traverse(path);
    auto file = std::dynamic_pointer_cast<FileNode>(node);
    if (!file) return ""; // not a file or does not exist
    return file->read();
}

// Remove a file or directory at the given path
bool InMemoryFileSystem::remove(const std::string& path) {
    auto parts = splitPath(path);
    if (parts.empty()) return false; // cannot remove root
    std::vector<std::string> parentParts(parts.begin(), parts.end() - 1);
    auto parent = traverseToDir(parentParts);
    if (!parent) return false; // parent path invalid
    return parent->removeChild(parts.back());
}

// List names of children in a directory
std::vector<std::string> InMemoryFileSystem::list(const std::string& path) const {
    auto node = traverse(path);
    auto dir = std::dynamic_pointer_cast<DirNode>(node);
    if (!dir) return {}; // not a directory
    return dir->list();
}
} // namespace fs
