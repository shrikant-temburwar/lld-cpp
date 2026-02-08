#pragma once
#include "ConflictStrategy.h"

namespace sync {
// Conflict resolution strategy: keep the file with the latest timestamp
class LastWriteWins : public ConflictStrategy {
public:
    // Resolve conflict by selecting the file with the most recent modification time
    FileMeta resolve(const FileMeta& local, const FileMeta& remote) override;
};
} // namespace sync
