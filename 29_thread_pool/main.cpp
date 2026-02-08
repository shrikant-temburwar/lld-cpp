#include "pool/ThreadPool.h"
#include <cassert>
#include <iostream>

int main() {
    pool::ThreadPool tp(2); // 2 worker threads
    int value = 0;
    // Submit a task that sets value to 42
    auto fut = tp.submit([&]() { value = 42; });
    fut.get(); // wait for completion
    assert(value == 42);
    std::cout << "ThreadPool tests passed\n";
}
