#pragma once
#include <chrono>
#include <string>

namespace snl {
// Dice component for rolling random numbers (1-6)
class Dice {
public:
    // Initialize with 6 sides (standard die)
    Dice();
    // Roll the die and return a random value in [1,6]
    int roll();

private:
    std::mt19937 rng_; // random number generator
    std::uniform_int_distribution<int> dist_; // uniform distribution [1,6]
};} // namespace snl
