#include "tictactoe/Game.h"
#include <cassert>
#include <iostream>

int main() {
    ttt::Game g;
    // Simulate a winning diagonal for X
    g.play(0,0); g.play(1,0); g.play(0,1); g.play(1,1); g.play(0,2);
    assert(g.winner() == 'X');
    std::cout << "TicTacToe tests passed\n";
}
