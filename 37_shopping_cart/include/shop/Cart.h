#pragma once
#include "Product.h"
#include <unordered_map>

namespace shop {
// Shopping cart managing items and quantities
class Cart {
public:
    // Add a product with quantity to the cart
    void add(const Product& product, int qty);
    // Remove a product from the cart by ID
    void remove(const std::string& productId);
    // Calculate total price of all items
    int total() const;

private:
    std::unordered_map<std::string, std::pair<Product, int>> items_; // product ID -> (product, quantity)
};
} // namespace shop
