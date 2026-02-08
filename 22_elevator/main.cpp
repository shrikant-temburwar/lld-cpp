#include "elevator/Elevator.h"
#include <cassert>
#include <iostream>

int main() {
    elevator::Elevator e;
    // Request floor 2
    e.requestFloor(2);
    // Simulate movement: 0 -> 1 -> 2
    e.step();
    e.step();
    assert(e.currentFloor() == 2); // should be at floor 2 now
    std::cout << "Elevator tests passed\n";
}
