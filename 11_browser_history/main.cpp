#include "history/BrowserHistory.h"
#include <cassert>
#include <iostream>

int main() {
    history::BrowserHistory bh;
    bh.visit("a.com");
    bh.visit("b.com");
    // Go back one step
    assert(bh.back(1) == "a.com");
    // Forward one step
    assert(bh.forward(1) == "b.com");
    // New visit truncates forward history
    bh.visit("c.com");
    // Forward should stay at c.com (no forward history)
    assert(bh.forward(1) == "c.com");
    std::cout << "BrowserHistory tests passed\n";
}
