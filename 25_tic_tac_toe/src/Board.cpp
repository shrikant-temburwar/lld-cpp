#include "tictactoe/Board.h"

namespace ttt {
// Constructor initializes an empty 3x3 board with '.' for empty cells
Board::Board() {
    for (auto& row : grid_) for (auto& c : row) c = '.'; // fill with empty markers
}

// Place a symbol on the board if the cell is empty and within bounds
bool Board::place(int r, int c, char symbol) {
    if (r < 0 || r >= 3 || c < 0 || c >= 3) return false; // out of bounds
    if (grid_[r][c] != '.') return false; // cell not empty
    grid_[r][c] = symbol;
    return true;
}

// Check for a winner; returns the winning symbol or '.' if none
char Board::winner() const {
    // Check rows and columns
    for (int i = 0; i < 3; ++i) {
        if (grid_[i][0] != '.' && grid_[i][0] == grid_[i][1] && grid_[i][1] == grid_[i][2]) return grid_[i][0]; // row
        if (grid_[0][i] != '.' && grid_[0][i] == grid_[1][i] && grid_[1][i] == grid_[2][i]) return grid_[0][i]; // column
    }
    // Check diagonals
    if (grid_[0][0] != '.' && grid_[0][0] == grid_[1][1] && grid_[1][1] == grid_[2][2]) return grid_[0][0]; // main diagonal
    if (grid_[0][2] != '.' && grid_[0][2] == grid_[1][1] && grid_[1][1] == grid_[2][0]) return grid_[0][2]; // anti-diagonal
    return '.'; // no winner
}

// Check if the board is completely filled (no empty cells)
bool Board::isFull() const {
    for (auto& row : grid_) for (auto& c : row) if (c == '.') return false; // found empty cell
    return true; // all cells filled
}
} // namespace ttt
