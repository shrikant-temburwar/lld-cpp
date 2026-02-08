#pragma once
#include <string>

namespace lockmgr {
// Lock types for concurrent access control
enum class LockType { Shared, Exclusive };
// Lock representation with resource, type, and owner
struct Lock {
    std::string resource; // resource being locked
    LockType type; // lock type (shared/exclusive)
    std::string owner; // lock owner identifier
};
} // namespace lockmgr
