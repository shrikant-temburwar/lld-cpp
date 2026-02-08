#include "vending/Inventory.h"

namespace vending {
// Add a product to inventory with initial stock count
void Inventory::addProduct(const Product& product, int count) {
    products_[product.id] = product; // store product info
    stock_[product.id] += count; // add to stock
}

// Check if a product has stock available
bool Inventory::hasStock(const std::string& productId) const {
    auto it = stock_.find(productId);
    return it != stock_.end() && it->second > 0; // product exists and stock > 0
}

// Remove one unit from stock (if available)
void Inventory::removeOne(const std::string& productId) {
    if (stock_[productId] > 0) stock_[productId] -= 1; // decrement stock
}

// Get product details by ID; returns empty Product if not found
Product Inventory::getProduct(const std::string& productId) const {
    auto it = products_.find(productId);
    if (it == products_.end()) return {}; // not found
    return it->second;
}
} // namespace vending
