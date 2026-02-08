#pragma once
#include <vector>

namespace ttt {
// Tic-tac-toe game board managing cell states and win detection
class Board {
public:
    Board();
    // Place a symbol at the given position
    bool place(int r, int c, char symbol);
    // Get the winning symbol (0 if none)
    char winner() const;
    // Check if board is full
    bool isFull() const;

private:
    char grid_[3][3]; // 3x3 game board
};
} // namespace ttt
