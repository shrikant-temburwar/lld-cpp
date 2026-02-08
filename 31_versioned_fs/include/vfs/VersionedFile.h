#pragma once
#include "FileVersion.h"
#include <vector>

namespace vfs {
// Versioned file maintaining history of all changes
class VersionedFile {
public:
    // Write content as a new version (auto-increments version number)
    void write(const std::string& content);
    // Read content from a specific version
    std::string read(int version) const;
    // Get the latest version number
    int latestVersion() const;

private:
    std::vector<FileVersion> versions_; // all file versions in order
};
} // namespace vfs
