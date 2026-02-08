#include "snl/Dice.h"
#include <chrono>

namespace snl {
// Initialize with 6 sides (standard die)
Dice::Dice() : rng_(static_cast<unsigned>(
          std::chrono::steady_clock::now().time_since_epoch().count())),
      dist_(1, 6) {}

// Roll the die and return a random value in [1,6]
int Dice::roll() { return dist_(rng_); }
} // namespace snl
