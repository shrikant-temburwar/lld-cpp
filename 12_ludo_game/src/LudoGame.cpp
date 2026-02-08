#include "ludo/LudoGame.h"

namespace ludo {
// Constructor initializes game state and a 6-sided die
LudoGame::LudoGame() : state_(GameState::NotStarted), current_(0), dice_(6) {}

// Add a player to the game
void LudoGame::addPlayer(const Player& player) { players_.push_back(player); }

// Start the game and reset turn index
void LudoGame::start() {
    state_ = GameState::InProgress;
    current_ = 0;
}

// Execute one turn for the current player
bool LudoGame::playTurn() {
    if (state_ != GameState::InProgress || players_.empty()) return false;
    auto& player = players_[current_];
    int roll = dice_.roll();

    // Simplified: move the first piece if it exists
    if (!player.pieces().empty()) {
        player.pieces()[0].move(roll);
    }

    // Check win condition
    if (hasWinner(player)) {
        state_ = GameState::Finished;
        return true;
    }

    // Advance to next player
    current_ = (current_ + 1) % players_.size();
    return true;
}

// Get current game state
GameState LudoGame::state() const { return state_; }

// Check if a player has won (all pieces reached or beyond 56)
bool LudoGame::hasWinner(const Player& player) const {
    for (const auto& piece : player.pieces()) {
        if (piece.position() < 56) return false; // not all pieces home
    }
    return true;
}
} // namespace ludo
