#include "sync/SyncService.h"
#include <iostream>

namespace sync {
// Constructor accepts a conflict resolution strategy
SyncService::SyncService(std::unique_ptr<ConflictStrategy> strategy)
    : strategy_(std::move(strategy)) {}

// Called when a file change is detected (demo: just log)
void SyncService::onChange(const std::string& path) {
    std::cout << "Change detected: " << path << "\n";
}

// Resolve conflict between local and remote file versions using strategy
void SyncService::sync(const FileMeta& local, const FileMeta& remote) {
    auto winner = strategy_->resolve(local, remote);
    std::cout << "Sync winner: " << winner.path << "\n";
}
} // namespace sync
