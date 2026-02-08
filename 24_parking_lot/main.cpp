#include "parking/ParkingLot.h"
#include <cassert>
#include <iostream>

int main() {
    parking::ParkingLot lot;
    // Add a compact spot
    lot.addSpot({"S1", parking::SpotType::Compact});
    // Park a compact vehicle
    auto spotId = lot.parkVehicle("V1", parking::SpotType::Compact);
    assert(!spotId.empty()); // should succeed
    // Leave the spot
    lot.leaveSpot(spotId);
    std::cout << "Parking lot tests passed\n";
}
