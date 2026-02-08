#pragma once
#include "Enums.h"
#include <string>

namespace parking {
// Individual parking spot with state management
class Spot {
public:
    // Initialize spot with ID and type
    Spot(std::string id, SpotType type);
    // Check if spot is available
    bool isFree() const;
    // Park a vehicle in this spot
    void park(const std::string& vehicleId);
    // Vehicle leaves the spot
    void leave();
    // Get spot type
    SpotType type() const;
    // Get spot ID
    const std::string& id() const;

private:
    std::string id_; // unique spot identifier
    SpotType type_; // spot type (compact/large)
    std::string vehicleId_; // parked vehicle ID (empty if free)
};
} // namespace parking
