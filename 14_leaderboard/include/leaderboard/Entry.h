#pragma once
#include <string>

namespace leaderboard {
// Leaderboard entry with user ID and score
struct Entry {
    std::string userId; // unique user identifier
    int score; // user's score
};
} // namespace leaderboard
