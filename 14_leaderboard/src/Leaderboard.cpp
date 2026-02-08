#include "leaderboard/Leaderboard.h"

namespace leaderboard {
// Submit or update a user's score; updates both maps
void Leaderboard::submitScore(const std::string& userId, int score) {
    // If user existed, remove from old score bucket
    auto it = userScores_.find(userId);
    if (it != userScores_.end()) {
        int oldScore = it->second;
        auto& users = scoreToUsers_[oldScore];
        users.erase(std::remove(users.begin(), users.end(), userId), users.end());
        if (users.empty()) scoreToUsers_.erase(oldScore); // clean up empty bucket
    }

    // Add to new score bucket
    userScores_[userId] = score;
    scoreToUsers_[score].push_back(userId);
}

// Compute 1-based rank of a user by iterating from highest score
int Leaderboard::getRank(const std::string& userId) const {
    auto it = userScores_.find(userId);
    if (it == userScores_.end()) return -1; // not found
    int score = it->second;
    int rank = 1;
    // Walk higher scores and accumulate user counts
    for (const auto& [s, users] : scoreToUsers_) {
        if (s == score) break; // reached user's score
        rank += static_cast<int>(users.size());
    }
    return rank;
}

// Return top N entries (highest scores first)
std::vector<Entry> Leaderboard::topN(size_t n) const {
    std::vector<Entry> out;
    for (const auto& [score, users] : scoreToUsers_) {
        for (const auto& uid : users) {
            out.push_back({uid, score});
            if (out.size() == n) return out; // limit reached
        }
    }
    return out;
}
} // namespace leaderboard
