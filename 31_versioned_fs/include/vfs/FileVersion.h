#pragma once
#include <string>

namespace vfs {
// File version with version number and content
struct FileVersion {
    int version; // version number
    std::string content; // file content at this version
};
} // namespace vfs
