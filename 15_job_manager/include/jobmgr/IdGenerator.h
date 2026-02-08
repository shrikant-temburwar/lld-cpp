#pragma once
#include <atomic>
#include <string>

namespace jobmgr {
// Thread-safe ID generator for unique run IDs
class IdGenerator {
public:
    // Generate next unique ID
    std::string next();

private:
    std::atomic<int> counter_{0}; // atomic counter for thread safety
};
} // namespace jobmgr
