#pragma once
#include "Dice.h"
#include "Player.h"
#include "Enums.h"
#include <vector>

namespace ludo {
// Main Ludo game controller managing players and game flow
class LudoGame {
public:
    LudoGame();

    // Add a player to the game
    void addPlayer(const Player& player);
    // Start the game (transitions to InProgress)
    void start();
    // Execute one turn for current player
    bool playTurn();
    // Get current game state
    GameState state() const;

private:
    GameState state_; // current game state
    std::vector<Player> players_; // players in the game
    size_t current_; // index of current player
    Dice dice_; // game dice

    // Check if player has won (all pieces home)
    bool hasWinner(const Player& player) const;
};
} // namespace ludo
