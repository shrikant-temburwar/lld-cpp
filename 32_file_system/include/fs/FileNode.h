#pragma once
#include "Node.h"
#include <string>

namespace fsbasic {
// File node representing a file in the file system
class FileNode : public Node {
public:
    explicit FileNode(std::string name);
    // Read file content
    const std::string& read() const;
    // Write file content (overwrites existing)
    void write(const std::string& data);

private:
    std::string data_; // file content
};
} // namespace fsbasic
