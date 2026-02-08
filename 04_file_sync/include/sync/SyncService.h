#pragma once
#include "ConflictStrategy.h"
#include "FileEventListener.h"
#include <memory>

namespace sync {
// Synchronization service that resolves conflicts using a strategy pattern
class SyncService : public FileEventListener {
public:
    // Constructor receives conflict resolution strategy
    explicit SyncService(std::unique_ptr<ConflictStrategy> strategy);
    // Handle file change notifications (implements observer)
    void onChange(const std::string& path) override;
    // Synchronize local and remote file metadata using strategy
    void sync(const FileMeta& local, const FileMeta& remote);

private:
    std::unique_ptr<ConflictStrategy> strategy_; // conflict resolution strategy
};
} // namespace sync
