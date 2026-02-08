#pragma once
#include "Entry.h"
#include <map>
#include <string>
#include <unordered_map>
#include <vector>

namespace leaderboard {
// Leaderboard that maintains rankings and supports top-N queries
class Leaderboard {
public:
    // Submit or update a user's score
    void submitScore(const std::string& userId, int score);
    // Get the rank of a specific user
    int getRank(const std::string& userId) const;
    // Get top N entries by score
    std::vector<Entry> topN(size_t n) const;

private:
    // Score -> list of users (sorted descending) for efficient rank calculation
    std::map<int, std::vector<std::string>, std::greater<int>> scoreToUsers_;
    // User -> current score for quick lookups
    std::unordered_map<std::string, int> userScores_;
};
} // namespace leaderboard
