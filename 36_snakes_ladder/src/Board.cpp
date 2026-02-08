#include "snl/Board.h"

namespace snl {
// Constructor sets board size
Board::Board(int size) : size_(size) {}

// Add a snake (go down) and ladder (go up) jump
void Board::addSnake(int from, int to) { jumps_[from] = to; }
void Board::addLadder(int from, int to) { jumps_[from] = to; }

// Move a token by roll, respecting board boundaries and jumps
int Board::move(int position, int roll) const {
    int next = position + roll;
    if (next > size_) return position; // cannot exceed board size
    auto it = jumps_.find(next);
    if (it != jumps_.end()) next = it->second; // apply snake or ladder
    return next;
}
} // namespace snl
