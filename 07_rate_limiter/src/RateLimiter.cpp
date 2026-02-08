#include "ratelimit/RateLimiter.h"

namespace ratelimit {
// Constructor configures max tokens per bucket and refill interval
RateLimiter::RateLimiter(int maxTokens, std::chrono::milliseconds refillInterval)
    : maxTokens_(maxTokens), refillInterval_(refillInterval) {}

// Check if a client request is allowed under rate limit
bool RateLimiter::allow(const std::string& clientId) {
    std::lock_guard<std::mutex> lock(mutex_);
    auto& b = buckets_[clientId]; // get/create bucket
    if (b.lastRefill.time_since_epoch().count() == 0) {
        b.tokens = maxTokens_; // initialize bucket
        b.lastRefill = std::chrono::steady_clock::now();
    }
    refill(b); // add tokens based on elapsed time
    if (b.tokens > 0) {
        --b.tokens; // consume one token
        return true; // request allowed
    }
    return false; // no tokens -> request denied
}

// Refill bucket tokens based on elapsed intervals
void RateLimiter::refill(Bucket& b) {
    auto now = std::chrono::steady_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(now - b.lastRefill);
    if (elapsed >= refillInterval_) {
        // Number of full intervals elapsed since last refill
        int intervals = static_cast<int>(elapsed.count() / refillInterval_.count());
        b.tokens = std::min(maxTokens_, b.tokens + intervals); // cap at max
        b.lastRefill = now; // update timestamp
    }
}
} // namespace ratelimit
