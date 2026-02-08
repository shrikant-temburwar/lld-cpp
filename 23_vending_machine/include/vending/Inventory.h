#pragma once
#include "Product.h"
#include <unordered_map>

namespace vending {
// Inventory management for vending machine products
class Inventory {
public:
    // Add a product with initial stock count
    void addProduct(const Product& product, int count);
    // Check if a product has available stock
    bool hasStock(const std::string& productId) const;
    // Remove one unit from stock
    void removeOne(const std::string& productId);
    // Get product details by ID
    Product getProduct(const std::string& productId) const;

private:
    std::unordered_map<std::string, Product> products_; // product catalog
    std::unordered_map<std::string, int> stock_; // stock count by product ID
};
} // namespace vending
