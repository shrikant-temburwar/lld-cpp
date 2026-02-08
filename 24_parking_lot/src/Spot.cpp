#include "parking/Spot.h"

namespace parking {
// Constructor initializes spot ID and type
Spot::Spot(std::string id, SpotType type)
    : id_(std::move(id)), type_(type) {}

// Check if spot is free (no vehicle parked)
bool Spot::isFree() const { return vehicleId_.empty(); }

// Park a vehicle in this spot
void Spot::park(const std::string& vehicleId) { vehicleId_ = vehicleId; }

// Vehicle leaves the spot (clears the vehicle ID)
void Spot::leave() { vehicleId_.clear(); }

// Accessors
SpotType Spot::type() const { return type_; }
const std::string& Spot::id() const { return id_; }
} // namespace parking
