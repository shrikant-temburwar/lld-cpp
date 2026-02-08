#pragma once
#include <random>

namespace ludo {
// Dice component for generating random rolls
class Dice {
public:
    explicit Dice(int sides = 6);
    // Roll the dice and return result (1 to sides)
    int roll();

private:
    int sides_; // number of sides on the dice
    std::mt19937 rng_; // random number generator
    std::uniform_int_distribution<int> dist_; // uniform distribution for rolls
};
} // namespace ludo
