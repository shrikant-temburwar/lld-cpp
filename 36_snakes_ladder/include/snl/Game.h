#pragma once
#include "Board.h"
#include "Dice.h"
#include <vector>

namespace snl {
// Snakes and Ladders game managing players and turns
class Game {
public:
    // Initialize with board
    explicit Game(Board board);
    // Add a player with starting position (default 0)
    void addPlayer(int startPos = 0);
    // Play a turn for current player
    bool playTurn(int roll);
    // Get winner index (-1 if none)
    int winner() const;

private:
    Board board_; // game board with jumps
    std::vector<int> positions_; // player positions
    int winnerIndex_; // winner player index
    Dice dice_; // game dice for rolling
};
} // namespace snl
