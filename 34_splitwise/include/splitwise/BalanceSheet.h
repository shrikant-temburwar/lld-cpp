#pragma once
#include <string>
#include <unordered_map>

namespace splitwise {
// Balance sheet tracking debts between users
class BalanceSheet {
public:
    // Record a debt from one user to another
    void addDebt(const std::string& from, const std::string& to, int amount);
    // Get balance owed from one user to another
    int getBalance(const std::string& from, const std::string& to) const;

private:
    // Nested map: from user -> to user -> amount owed
    std::unordered_map<std::string, std::unordered_map<std::string, int>> balances_;
};
} // namespace splitwise
