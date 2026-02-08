#pragma once
#include "BalanceSheet.h"
#include "Expense.h"

namespace splitwise {
// Splitwise service managing expenses and balance calculations
class SplitwiseService {
public:
    // Add an expense and split it among participants
    void addExpense(const Expense& expense);
    // Calculate net balance between two users
    int balanceBetween(const std::string& a, const std::string& b) const;

private:
    BalanceSheet sheet_; // balance sheet for debt tracking
};
} // namespace splitwise
