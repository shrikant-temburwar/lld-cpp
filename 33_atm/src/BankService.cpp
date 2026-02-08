#include "atm/BankService.h"

namespace atm {
// Add a new account to the bank
void BankService::addAccount(const Account& account) {
    accounts_[account.id] = account;
}

// Withdraw money from an account if sufficient funds
bool BankService::withdraw(const std::string& id, int amount) {
    auto it = accounts_.find(id);
    if (it == accounts_.end() || it->second.balance < amount) return false; // account not found or insufficient funds
    it->second.balance -= amount; // deduct amount
    return true;
}

// Get account balance; returns 0 if account not found
int BankService::balance(const std::string& id) const {
    auto it = accounts_.find(id);
    if (it == accounts_.end()) return 0; // account not found
    return it->second.balance;
}
} // namespace atm
