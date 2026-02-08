#pragma once
#include <string>

namespace sync {
// Observer interface for file change notifications
class FileEventListener {
public:
    virtual ~FileEventListener() = default;
    // Called when a file change occurs at the given path
    virtual void onChange(const std::string& path) = 0;
};
} // namespace sync
