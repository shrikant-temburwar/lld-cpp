#pragma once
#include <string>
#include <vector>

namespace history {
// Browser history with back/forward navigation support
class BrowserHistory {
public:
    BrowserHistory();

    // Add a URL to history (clears forward history)
    void visit(const std::string& url);
    // Go back specified number of steps
    std::string back(int steps);
    // Go forward specified number of steps
    std::string forward(int steps);
    // Get current URL
    std::string current() const;

private:
    std::vector<std::string> history_; // visited URLs
    size_t index_; // current position in history
};
} // namespace history
