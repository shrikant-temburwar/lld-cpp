#pragma once
#include "FileEventListener.h"
#include <vector>

namespace sync {
// File watcher that notifies listeners of file changes (Observer pattern)
class FileWatcher {
public:
    // Register a listener for file change notifications
    void addListener(FileEventListener* l);
    // Notify all listeners about a change at the given path
    void notifyChange(const std::string& path);

private:
    std::vector<FileEventListener*> listeners_; // registered listeners
};
} // namespace sync
