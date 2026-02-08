#include "history/BrowserHistory.h"

namespace history {
// Constructor starts with a blank page
BrowserHistory::BrowserHistory() : index_(0) {
    history_.push_back("about:blank");
}

// Visit a new URL: truncate forward history and add new entry
void BrowserHistory::visit(const std::string& url) {
    history_.resize(index_ + 1); // discard forward history
    history_.push_back(url); // add new page
    index_ = history_.size() - 1; // move to new page
}

// Move back by steps (clamped to start of history)
std::string BrowserHistory::back(int steps) {
    if (steps < 0) return current();
    size_t s = static_cast<size_t>(steps);
    if (s > index_) index_ = 0; // clamp to start
    else index_ -= s;
    return current();
}

// Move forward by steps (clamped to end of history)
std::string BrowserHistory::forward(int steps) {
    if (steps < 0) return current();
    size_t s = static_cast<size_t>(steps);
    size_t maxIndex = history_.size() - 1;
    index_ = (index_ + s > maxIndex) ? maxIndex : index_ + s; // clamp to end
    return current();
}

// Return the URL at the current index
std::string BrowserHistory::current() const {
    return history_[index_];
}
} // namespace history
