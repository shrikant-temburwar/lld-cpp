#pragma once
#include <memory>
#include <string>

namespace fsbasic {
class DirNode;

// Base class for file system nodes (files and directories)
class Node {
public:
    explicit Node(std::string name);
    virtual ~Node() = default;

    // Get node name
    const std::string& name() const;
    // Set parent directory (used for path resolution)
    void setParent(std::shared_ptr<DirNode> parent);

protected:
    std::string name_; // node name
    std::weak_ptr<DirNode> parent_; // parent directory (weak to avoid cycles)
};
} // namespace fsbasic
