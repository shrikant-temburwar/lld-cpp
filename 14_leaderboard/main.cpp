#include "leaderboard/Leaderboard.h"
#include <cassert>
#include <iostream>

int main() {
    leaderboard::Leaderboard lb;
    // Submit scores
    lb.submitScore("u1", 50);
    lb.submitScore("u2", 100);
    lb.submitScore("u3", 75);

    // u2 should be rank 1 (highest score)
    assert(lb.getRank("u2") == 1);
    // Top 2 entries should be returned
    assert(lb.topN(2).size() == 2);
    std::cout << "Leaderboard tests passed\n";
}
