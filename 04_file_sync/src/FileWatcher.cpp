#include "sync/FileWatcher.h"

namespace sync {
// Register a listener to be notified of file changes
void FileWatcher::addListener(FileEventListener* l) { listeners_.push_back(l); }

// Notify all registered listeners about a change at the given path
void FileWatcher::notifyChange(const std::string& path) {
    for (auto* l : listeners_) l->onChange(path);
}
} // namespace sync
