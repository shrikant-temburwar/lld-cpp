#include "chess/Piece.h"

namespace chess {
// Default constructor creates an empty piece
Piece::Piece() : type_(PieceType::None), color_(Color::White) {}

// Constructor creates a piece with specific type and color
Piece::Piece(PieceType type, Color color) : type_(type), color_(color) {}

// Get piece type
PieceType Piece::type() const { return type_; }

// Get piece color
Color Piece::color() const { return color_; }
} // namespace chess
