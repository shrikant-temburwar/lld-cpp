#include "shop/Cart.h"
#include <cassert>
#include <iostream>

int main() {
    shop::Cart cart;
    // Add 2 books at 100 each
    cart.add({"p1", "Book", 100}, 2);
    // Total should be 200
    assert(cart.total() == 200);
    std::cout << "Shopping cart tests passed\n";
}
