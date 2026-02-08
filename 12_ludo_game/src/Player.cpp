#include "ludo/Player.h"

namespace ludo {
// Constructor creates the requested number of pieces for the player
Player::Player(std::string name, Color color, int pieceCount)
    : name_(std::move(name)), color_(color) {
    for (int i = 0; i < pieceCount; ++i) pieces_.emplace_back(color);
}

// Accessors
const std::string& Player::name() const { return name_; }
Color Player::color() const { return color_; }
std::vector<Piece>& Player::pieces() { return pieces_; }
} // namespace ludo
