#pragma once
#include <atomic>
#include <string>

namespace shortener {
// Thread-safe unique ID generator using base-62 encoding
class IdGenerator {
public:
    // Generate next unique short code
    std::string next();

private:
    std::atomic<long> counter_{0}; // atomic counter for thread safety
    const std::string alphabet_ = "0123456789abcdefghijklmnopqrstuvwxyz"; // base-62 alphabet
};
} // namespace shortener
