#include "perms/StrictStrategy.h"

namespace perms {
// Helper: convert Action to its rwx bit mask (read=4, write=2, execute=1)
static int mask(Action a) {
    if (a == Action::Read) return 4;
    if (a == Action::Write) return 2;
    return 1; // Execute
}

// Strict Unix-like permission check: owner -> group -> other
bool StrictStrategy::allow(const User&, const Permissions& perms, Action action,
                           bool isOwner, bool inGroup) const {
    int m = mask(action); // bit mask for the requested action
    if (isOwner) return (perms.user & m) != 0; // check owner bits
    if (inGroup) return (perms.group & m) != 0; // check group bits
    return (perms.other & m) != 0; // check other bits
}
} // namespace perms
