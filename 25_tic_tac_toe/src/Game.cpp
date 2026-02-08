#include "tictactoe/Game.h"

namespace ttt {
// Constructor starts with X as the current player
Game::Game() : current_('X') {}

// Place a mark for the current player; then switch player
bool Game::play(int r, int c) {
    if (!board_.place(r, c, current_)) return false; // invalid move
    current_ = (current_ == 'X') ? 'O' : 'X'; // toggle player
    return true;
}

// Return the winner symbol if any, or space for none
char Game::winner() const { return board_.winner(); }
} // namespace ttt
