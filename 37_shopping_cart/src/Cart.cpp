#include "shop/Cart.h"

namespace shop {
// Add a product with quantity to the cart (overwrites existing)
void Cart::add(const Product& product, int qty) {
    items_[product.id] = {product, qty};
}

// Remove a product from the cart by its ID
void Cart::remove(const std::string& productId) {
    items_.erase(productId);
}

// Calculate total price of all items in the cart
int Cart::total() const {
    int sum = 0;
    for (const auto& kv : items_) sum += kv.second.first.price * kv.second.second; // price * quantity
    return sum;
}
} // namespace shop
