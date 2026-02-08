#include "ratelimit/RateLimiter.h"
#include <cassert>
#include <iostream>

int main() {
    // 2 tokens per second (refill every 1000ms)
    ratelimit::RateLimiter rl(2, std::chrono::milliseconds(1000));
    // First two requests should be allowed
    assert(rl.allow("u1"));
    assert(rl.allow("u1"));
    // Third request exceeds rate limit
    assert(!rl.allow("u1"));
    std::cout << "RateLimiter tests passed\n";
}
