#include "perms/PermissionManager.h"
#include "perms/StrictStrategy.h"
#include <cassert>
#include <iostream>

int main() {
    perms::User u{"u1", {"g1"}}; // user u1 belongs to group g1
    perms::Permissions p{6, 4, 0}; // user: rw, group: r, other: none (octal 640)
    perms::PermissionManager mgr(std::make_unique<perms::StrictStrategy>());

    // Owner can read
    assert(mgr.canAccess(u, p, perms::Action::Read, true, false));
    // Owner cannot execute (no execute bit)
    assert(!mgr.canAccess(u, p, perms::Action::Execute, true, false));
    std::cout << "Permission tests passed\n";
}
