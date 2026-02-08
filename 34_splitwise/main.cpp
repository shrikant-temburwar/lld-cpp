#include "splitwise/SplitwiseService.h"
#include <cassert>
#include <iostream>

int main() {
    splitwise::SplitwiseService s;
    // Expense: u1 paid 90 for u1, u2, u3 (equal split => 30 each)
    splitwise::Expense e{"e1", "u1", 90, {"u1", "u2", "u3"}};
    s.addExpense(e);
    // u2 owes u1 30
    assert(s.balanceBetween("u2", "u1") == 30);
    std::cout << "Splitwise tests passed\n";
}
