#pragma once
#include <string>

namespace shop {
// Product entity with ID, name, and price
struct Product {
    std::string id; // unique product identifier
    std::string name; // product name
    int price; // product price in cents
};
} // namespace shop
