#include "ludo/LudoGame.h"
#include <cassert>
#include <iostream>

int main() {
    ludo::LudoGame game;
    // Add two players with one piece each
    game.addPlayer(ludo::Player("A", ludo::Color::Red, 1));
    game.addPlayer(ludo::Player("B", ludo::Color::Blue, 1));
    game.start();
    assert(game.state() == ludo::GameState::InProgress);
    // Simulate one turn
    game.playTurn();
    std::cout << "Ludo tests passed\n";
}
