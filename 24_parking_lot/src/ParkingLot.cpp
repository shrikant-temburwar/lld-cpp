#include "parking/ParkingLot.h"

namespace parking {
// Add a parking spot to the lot
void ParkingLot::addSpot(const Spot& spot) { spots_.push_back(spot); }

// Find a free spot of the requested type and park the vehicle
std::string ParkingLot::parkVehicle(const std::string& vehicleId, SpotType type) {
    for (auto& spot : spots_) {
        if (spot.isFree() && spot.type() == type) {
            spot.park(vehicleId);
            return spot.id(); // return spot ID for reference
        }
    }
    return ""; // no suitable spot
}

// Free a spot by its ID
void ParkingLot::leaveSpot(const std::string& spotId) {
    for (auto& spot : spots_) {
        if (spot.id() == spotId) {
            spot.leave();
            return;
        }
    }
}
} // namespace parking
