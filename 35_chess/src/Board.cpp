#include "chess/Board.h"

namespace chess {
// Constructor initializes an 8x8 board and places two rooks
Board::Board() {
    // Clear board: all cells empty
    for (auto& row : grid_) {
        for (auto& cell : row) cell = {PieceType::None, Color::White};
    }
    // Place white rook at (0,0) and black rook at (7,7)
    grid_[0][0] = {PieceType::Rook, Color::White};
    grid_[7][7] = {PieceType::Rook, Color::Black};
}

// Check if coordinates are within the 8x8 board
bool Board::inBounds(int r, int c) const { return r >= 0 && r < 8 && c >= 0 && c < 8; }

// Move a piece from (r1,c1) to (r2,c2); basic validation only
bool Board::move(int r1, int c1, int r2, int c2) {
    if (!inBounds(r1, c1) || !inBounds(r2, c2)) return false; // out of bounds
    if (grid_[r1][c1].type == PieceType::None) return false; // no piece to move
    grid_[r2][c2] = grid_[r1][c1]; // place piece at destination
    grid_[r1][c1] = {PieceType::None, Color::White}; // clear source
    return true;
}

// Get the piece at the given coordinates
Piece Board::at(int r, int c) const { return grid_[r][c]; }
} // namespace chess
