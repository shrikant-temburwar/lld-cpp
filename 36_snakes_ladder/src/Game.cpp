#include "snl/Game.h"
#include "snl/Dice.h"

namespace snl {
// Constructor takes board and initializes winner state
Game::Game(Board board) : board_(std::move(board)), winnerIndex_(-1) {}

// Add a player with a starting position
void Game::addPlayer(int startPos) { positions_.push_back(startPos); }

// Simulate a turn for the first player (simplified)
bool Game::playTurn(int roll) {
    if (winnerIndex_ != -1 || positions_.empty()) return false; // game already won or no players
    int idx = 0; // always first player for simplicity
    positions_[idx] = board_.move(positions_[idx], roll); // apply board rules (snakes/ladders)
    if (positions_[idx] == 100) winnerIndex_ = idx; // check win condition
    return true;
}

// Return the index of the winning player; -1 if none
int Game::winner() const { return winnerIndex_; }
} // namespace snl
