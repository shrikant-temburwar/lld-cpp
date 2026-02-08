#pragma once
#include <string>
#include <vector>

namespace fs {
// Utility function to split an absolute path into components
std::vector<std::string> splitPath(const std::string& path);
} // namespace fs
