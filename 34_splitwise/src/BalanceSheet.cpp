#include "splitwise/BalanceSheet.h"

namespace splitwise {
// Record that 'from' owes 'to' a certain amount
void BalanceSheet::addDebt(const std::string& from, const std::string& to, int amount) {
    balances_[from][to] += amount; // accumulate debt
}

// Get the amount 'from' owes 'to'; 0 if no debt recorded
int BalanceSheet::getBalance(const std::string& from, const std::string& to) const {
    auto it = balances_.find(from);
    if (it == balances_.end()) return 0; // no debts from 'from'
    auto it2 = it->second.find(to);
    if (it2 == it->second.end()) return 0; // no debt to 'to'
    return it2->second;
}
} // namespace splitwise
