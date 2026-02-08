#include "chess/Board.h"
#include <cassert>
#include <iostream>

int main() {
    chess::Board b;
    // Move white rook from (0,0) to (0,1)
    assert(b.move(0,0,0,1));
    // Verify rook is now at (0,1)
    assert(b.at(0,1).type == chess::PieceType::Rook);
    std::cout << "Chess tests passed\n";
}
