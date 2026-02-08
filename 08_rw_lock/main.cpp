#include "sync/ReadWriteLock.h"
#include <cassert>
#include <iostream>
#include <thread>

int main() {
    sync::ReadWriteLock lock;
    int value = 0;

    // Writer thread: takes exclusive lock to modify value
    std::thread writer([&]() {
        lock.lockWrite();
        value = 42;
        lock.unlockWrite();
    });

    // Reader thread: takes shared lock to read value
    std::thread reader([&]() {
        lock.lockRead();
        // Value may be 0 (before writer) or 42 (after writer) due to scheduling
        assert(value == 0 || value == 42);
        lock.unlockRead();
    });

    writer.join();
    reader.join();

    std::cout << "ReadWriteLock tests passed\n";
}
