#pragma once
#include <chrono>
#include <mutex>
#include <unordered_map>

namespace ratelimit {
// Rate limiter using token bucket algorithm (per-client)
class RateLimiter {
public:
    // Initialize with max tokens and refill interval
    RateLimiter(int maxTokens, std::chrono::milliseconds refillInterval);

    // Check if request is allowed for a client (thread-safe)
    bool allow(const std::string& clientId);

private:
    // Token bucket for a specific client
    struct Bucket {
        int tokens; // current token count
        std::chrono::steady_clock::time_point lastRefill; // last refill time
    };

    int maxTokens_; // maximum tokens per bucket
    std::chrono::milliseconds refillInterval_; // time between refills
    mutable std::mutex mutex_; // protects bucket access
    std::unordered_map<std::string, Bucket> buckets_; // client -> bucket mapping

    // Refill tokens for a bucket if enough time has passed
    void refill(Bucket& b);
};
} // namespace ratelimit
