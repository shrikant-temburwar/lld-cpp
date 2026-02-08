#pragma once
#include "BankService.h"

namespace atm {
// ATM machine that delegates to bank service for operations
class ATM {
public:
    // Initialize with bank service (dependency injection)
    explicit ATM(BankService* bank);
    // Withdraw money from account (delegates to bank)
    bool withdraw(const std::string& accountId, int amount);
    // Check account balance (delegates to bank)
    int checkBalance(const std::string& accountId) const;

private:
    BankService* bank_; // bank service for account operations
};
} // namespace atm
