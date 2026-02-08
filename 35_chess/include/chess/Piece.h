#pragma once

namespace chess {
// Chess piece types
enum class PieceType { None, King, Queen, Rook, Bishop, Knight, Pawn };
// Chess piece colors
enum class Color { White, Black };

// Chess piece with type and color
struct Piece {
    // Default constructor creates empty piece
    Piece();
    // Constructor creates piece with type and color
    Piece(PieceType type, Color color);
    
    PieceType type; // piece type
    Color color; // piece color
};
} // namespace chess
