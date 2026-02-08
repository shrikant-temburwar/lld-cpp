#include "fs/PathUtils.h"
#include <sstream>

namespace fs {
// Split absolute path into components, ignoring empty segments (e.g., leading slash)
std::vector<std::string> splitPath(const std::string& path) {
    std::vector<std::string> parts;
    std::stringstream ss(path);
    std::string item;
    while (std::getline(ss, item, '/')) {
        if (!item.empty()) parts.push_back(item); // skip empty parts from // or leading /
    }
    return parts;
}
} // namespace fs
