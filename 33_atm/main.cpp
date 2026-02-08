#include "atm/ATM.h"
#include <cassert>
#include <iostream>

int main() {
    // Set up bank with an account
    atm::BankService bank;
    bank.addAccount({"a1", 100});
    // Create ATM connected to the bank
    atm::ATM atm(&bank);
    // Verify initial balance
    assert(atm.checkBalance("a1") == 100);
    // Withdraw money
    assert(atm.withdraw("a1", 40));
    // Verify updated balance
    assert(atm.checkBalance("a1") == 60);
    std::cout << "ATM tests passed\n";
}
