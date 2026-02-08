#pragma once
#include "Piece.h"

namespace chess {
// Chess board managing pieces and moves
class Board {
public:
    Board();
    // Move a piece from (r1,c1) to (r2,c2)
    bool move(int r1, int c1, int r2, int c2);
    // Get piece at position (r,c)
    Piece at(int r, int c) const;

private:
    Piece grid_[8][8]; // 8x8 chess board
    // Check if coordinates are within board bounds
    bool inBounds(int r, int c) const;
};
} // namespace chess
