#include "ludo/Dice.h"
#include <chrono>

namespace ludo {
// Constructor seeds RNG and sets uniform distribution for given sides
Dice::Dice(int sides)
    : sides_(sides), rng_(static_cast<unsigned>(
          std::chrono::steady_clock::now().time_since_epoch().count())),
      dist_(1, sides) {}

// Roll the die and return a random value in [1, sides]
int Dice::roll() { return dist_(rng_); }
} // namespace ludo
