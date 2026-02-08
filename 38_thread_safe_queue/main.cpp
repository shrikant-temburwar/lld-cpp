#include "tsq/ThreadSafeQueue.h"
#include <cassert>
#include <iostream>
#include <thread>

int main() {
    tsq::ThreadSafeQueue<int> q;
    // Push an element
    q.push(1);
    // Pop and verify
    assert(q.pop() == 1);
    std::cout << "Thread-safe queue tests passed\n";
}
