#include "vfs/VersionedFileSystem.h"

namespace vfs {
// Write content to a file; creates a new version
void VersionedFileSystem::write(const std::string& path, const std::string& content) {
    files_[path].write(content); // delegate to versioned file
}

// Read a specific version of a file; returns empty string if not found
std::string VersionedFileSystem::read(const std::string& path, int version) const {
    auto it = files_.find(path);
    if (it == files_.end()) return ""; // file not found
    return it->second.read(version); // delegate to versioned file
}

// Return the latest version number for a file; 0 if not found
int VersionedFileSystem::latestVersion(const std::string& path) const {
    auto it = files_.find(path);
    if (it == files_.end()) return 0; // file not found
    return it->second.latestVersion(); // delegate to versioned file
}
} // namespace vfs
