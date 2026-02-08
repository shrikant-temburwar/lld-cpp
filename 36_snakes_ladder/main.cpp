#include "snl/Game.h"
#include <cassert>
#include <iostream>

int main() {
    // Create a 100-cell board with a ladder from 2 to 38
    snl::Board board(100);
    board.addLadder(2, 38);
    snl::Game game(board);
    game.addPlayer(); // add player at default start
    // Roll 2: should move to 38 via ladder
    game.playTurn(2);
    assert(game.winner() == -1); // not yet won
    std::cout << "Snakes & Ladder tests passed\n";
}
