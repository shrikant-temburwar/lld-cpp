#pragma once
#include "Board.h"

namespace ttt {
// Tic-tac-toe game controller managing turns and game state
class Game {
public:
    Game();
    // Play a move at the given position for current player
    bool play(int r, int c);
    // Get the winning symbol (0 if none)
    char winner() const;

private:
    Board board_; // game board
    char current_; // current player symbol ('X' or 'O')
};
} // namespace ttt
