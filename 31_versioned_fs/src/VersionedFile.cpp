#include "vfs/VersionedFile.h"

namespace vfs {
// Write content as a new version (auto-increments version number)
void VersionedFile::write(const std::string& content) {
    int v = static_cast<int>(versions_.size()) + 1; // next version number
    versions_.push_back({v, content});
}

// Read a specific version; returns empty string if invalid version
std::string VersionedFile::read(int version) const {
    if (version <= 0 || version > static_cast<int>(versions_.size())) return ""; // invalid version
    return versions_[version - 1].content; // versions are 1-indexed
}

// Return the latest version number (0 if no versions)
int VersionedFile::latestVersion() const { return static_cast<int>(versions_.size()); }
} // namespace vfs
