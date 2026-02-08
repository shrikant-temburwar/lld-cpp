#include "splitwise/SplitwiseService.h"

namespace splitwise {
// Add an expense and split it equally among participants
void SplitwiseService::addExpense(const Expense& expense) {
    int share = expense.amount / static_cast<int>(expense.participants.size()); // equal split
    for (const auto& p : expense.participants) {
        if (p == expense.paidBy) continue; // payer doesn't owe themselves
        sheet_.addDebt(p, expense.paidBy, share); // record debt from participant to payer
    }
}

// Query net balance from a to b (positive if a owes b)
int SplitwiseService::balanceBetween(const std::string& a, const std::string& b) const {
    return sheet_.getBalance(a, b);
}
} // namespace splitwise
