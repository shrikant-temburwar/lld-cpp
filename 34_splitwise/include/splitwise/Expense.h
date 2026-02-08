#pragma once
#include <string>
#include <vector>

namespace splitwise {
// Expense with payer, amount, and participants for splitting
struct Expense {
    std::string id; // unique expense identifier
    std::string paidBy; // user who paid the expense
    int amount; // total expense amount in cents
    std::vector<std::string> participants; // users involved in expense
};
} // namespace splitwise
