#pragma once
#include "VersionedFile.h"
#include <string>
#include <unordered_map>

namespace vfs {
// Versioned file system managing multiple versioned files
class VersionedFileSystem {
public:
    // Write content to a file (creates new version)
    void write(const std::string& path, const std::string& content);
    // Read content from a file at specific version
    std::string read(const std::string& path, int version) const;
    // Get latest version number for a file
    int latestVersion(const std::string& path) const;

private:
    std::unordered_map<std::string, VersionedFile> files_; // path -> versioned file mapping
};
} // namespace vfs
