#pragma once
#include <string>

namespace atm {
// Bank account with ID and balance
struct Account {
    std::string id; // unique account identifier
    int balance; // account balance in cents
};
} // namespace atm
