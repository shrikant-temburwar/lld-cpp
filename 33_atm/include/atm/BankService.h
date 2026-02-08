#pragma once
#include "Account.h"
#include <unordered_map>

namespace atm {
// Bank service managing accounts and transactions
class BankService {
public:
    // Add a new account to the bank
    void addAccount(const Account& account);
    // Withdraw money from an account if sufficient funds
    bool withdraw(const std::string& id, int amount);
    // Get account balance
    int balance(const std::string& id) const;

private:
    std::unordered_map<std::string, Account> accounts_; // account storage by ID
};
} // namespace atm
