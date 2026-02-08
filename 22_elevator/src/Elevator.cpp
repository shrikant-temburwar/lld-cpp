#include "elevator/Elevator.h"

namespace elevator {
// Constructor starts at floor 0, idle, with doors closed
Elevator::Elevator() : currentFloor_(0), direction_(Direction::Idle), door_(DoorState::Closed) {}

// Queue a floor request (no deduplication for simplicity)
void Elevator::requestFloor(int floor) {
    targets_.push(floor);
}

// Simulate one step of elevator movement or door operation
void Elevator::step() {
    if (targets_.empty()) {
        direction_ = Direction::Idle; // nothing to do
        return;
    }
    int target = targets_.front();
    // Move toward target floor
    if (currentFloor_ < target) {
        direction_ = Direction::Up;
        ++currentFloor_;
    } else if (currentFloor_ > target) {
        direction_ = Direction::Down;
        --currentFloor_;
    } else {
        // Arrived at target: open/close doors, then pop request
        door_ = DoorState::Open;
        targets_.pop();
        door_ = DoorState::Closed;
        direction_ = Direction::Idle;
    }
}

// Accessors
int Elevator::currentFloor() const { return currentFloor_; }
Direction Elevator::direction() const { return direction_; }
} // namespace elevator
