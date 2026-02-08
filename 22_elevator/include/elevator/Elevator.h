#pragma once
#include "Enums.h"
#include <queue>

namespace elevator {
// Elevator system managing floor requests and movement
class Elevator {
public:
    Elevator();
    // Request to go to a specific floor
    void requestFloor(int floor);
    // Move one step in the current direction
    void step();
    // Get current floor number
    int currentFloor() const;
    // Get current movement direction
    Direction direction() const;

private:
    int currentFloor_; // current floor position
    Direction direction_; // current movement direction
    DoorState door_; // door state (open/closed)
    std::queue<int> targets_; // pending floor requests
};
} // namespace elevator
