#pragma once
#include "Inventory.h"
#include <string>

namespace vending {
// Vending machine managing inventory and balance
class VendingMachine {
public:
    // Initialize with product inventory
    explicit VendingMachine(Inventory inventory);
    // Insert coins (adds to balance)
    void insertCoin(int amount);
    // Select a product and attempt purchase
    std::string select(const std::string& productId);
    // Refund remaining balance
    int refund();

private:
    Inventory inventory_; // product inventory
    int balance_; // current balance in cents
};
} // namespace vending
