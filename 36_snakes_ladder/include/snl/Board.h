#pragma once
#include <unordered_map>

namespace snl {
// Snakes and Ladders board with jumps and boundaries
class Board {
public:
    // Initialize board with specified size
    Board(int size);
    // Add a snake (go down) jump
    void addSnake(int from, int to);
    // Add a ladder (go up) jump
    void addLadder(int from, int to);
    // Move token by roll respecting jumps and boundaries
    int move(int position, int roll) const;

private:
    int size_; // board size (typically 100)
    std::unordered_map<int, int> jumps_; // position -> destination (snakes/ladders)
};
} // namespace snl
