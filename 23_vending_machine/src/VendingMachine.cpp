#include "vending/VendingMachine.h"

namespace vending {
// Constructor takes ownership of inventory and starts with zero balance
VendingMachine::VendingMachine(Inventory inventory)
    : inventory_(std::move(inventory)), balance_(0) {}

// Add coin value to current balance
void VendingMachine::insertCoin(int amount) { balance_ += amount; }

// Attempt to purchase a product; returns status string
std::string VendingMachine::select(const std::string& productId) {
    if (!inventory_.hasStock(productId)) return "OUT_OF_STOCK"; // no stock
    auto p = inventory_.getProduct(productId);
    if (balance_ < p.price) return "INSUFFICIENT_FUNDS"; // not enough money
    balance_ -= p.price; // deduct price
    inventory_.removeOne(productId); // decrement stock
    return "DISPENSED";
}

// Refund remaining balance and reset to zero
int VendingMachine::refund() {
    int amount = balance_;
    balance_ = 0;
    return amount;
}
} // namespace vending
