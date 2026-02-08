#pragma once
#include "Enums.h"

namespace ludo {
// Game piece representing a player's token on the board
class Piece {
public:
    explicit Piece(Color color);
    // Get current position (-1 = home)
    int position() const;
    // Move piece forward by specified steps
    void move(int steps);
    // Get piece color
    Color color() const;

private:
    Color color_; // player color
    int position_; // position on board (-1 = home)
};
} // namespace ludo
