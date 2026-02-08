#pragma once
#include "Piece.h"
#include <string>
#include <vector>

namespace ludo {
// Player in Ludo game with multiple pieces
class Player {
public:
    // Initialize player with name, color, and number of pieces
    Player(std::string name, Color color, int pieceCount);

    // Get player name
    const std::string& name() const;
    // Get player color
    Color color() const;
    // Get player's pieces
    std::vector<Piece>& pieces();

private:
    std::string name_; // player name
    Color color_; // player color
    std::vector<Piece> pieces_; // player's game pieces
};
} // namespace ludo
