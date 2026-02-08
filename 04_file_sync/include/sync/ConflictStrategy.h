#pragma once
#include <string>

namespace sync {
// File metadata including path and modification timestamp
struct FileMeta {
    std::string path; // file path
    long modifiedAt; // last modification time (timestamp)
};

// Strategy interface for resolving file conflicts during synchronization (Conflict Strategy pattern)
// This interface defines a strategy for resolving conflicts between local and remote file versions.
// Concrete implementations of this interface will provide specific conflict resolution logic.
class ConflictStrategy {
public:
    virtual ~ConflictStrategy() = default;
    // Resolve conflict between local and remote versions
    virtual FileMeta resolve(const FileMeta& local, const FileMeta& remote) = 0;
};
} // namespace sync
