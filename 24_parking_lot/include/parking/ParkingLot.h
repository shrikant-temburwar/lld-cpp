#pragma once
#include "Spot.h"
#include <vector>

namespace parking {
// Parking lot managing multiple parking spots
class ParkingLot {
public:
    // Add a parking spot to the lot
    void addSpot(const Spot& spot);
    // Park a vehicle and return the spot ID
    std::string parkVehicle(const std::string& vehicleId, SpotType type);
    // Vehicle leaves a specific spot
    void leaveSpot(const std::string& spotId);

private:
    std::vector<Spot> spots_; // all parking spots in the lot
};
} // namespace parking
