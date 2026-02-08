#include "atm/ATM.h"

namespace atm {
// Constructor receives a bank service dependency
ATM::ATM(BankService* bank) : bank_(bank) {}

// Withdraw money by delegating to the bank service
bool ATM::withdraw(const std::string& accountId, int amount) {
    return bank_->withdraw(accountId, amount);
}

// Check account balance by delegating to the bank service
int ATM::checkBalance(const std::string& accountId) const {
    return bank_->balance(accountId);
}
} // namespace atm
