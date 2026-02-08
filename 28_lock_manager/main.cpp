#include "lockmgr/LockManager.h"
#include <cassert>
#include <iostream>

int main() {
    lockmgr::LockManager mgr;
    // u1 acquires shared lock successfully
    assert(mgr.acquireShared("r1", "u1"));
    // u2 cannot acquire exclusive while u1 holds shared lock
    assert(!mgr.acquireExclusive("r1", "u2"));
    // u1 releases shared lock
    mgr.release("r1", "u1");
    // Now u2 can acquire exclusive lock
    assert(mgr.acquireExclusive("r1", "u2"));
    std::cout << "LockManager tests passed\n";
}
