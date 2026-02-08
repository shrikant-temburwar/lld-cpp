#include "ludo/Piece.h"

namespace ludo {
// Constructor sets color and starts at home (-1)
Piece::Piece(Color color) : color_(color), position_(-1) {}

// Accessors
int Piece::position() const { return position_; }
Color Piece::color() const { return color_; }

// Move piece: enter board on a 6, otherwise advance
void Piece::move(int steps) {
    if (position_ == -1 && steps == 6) {
        position_ = 0; // enter board from home
        return;
    }
    if (position_ >= 0) position_ += steps; // advance on board
}
} // namespace ludo
