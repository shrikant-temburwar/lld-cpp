#pragma once
#include "PermissionStrategy.h"

namespace perms {
// Strict Unix-like permission strategy (owner/group/others)
class StrictStrategy : public PermissionStrategy {
public:
    // Check if user is allowed to perform action based on Unix permissions
    bool allow(const User& user, const Permissions& perms, Action action,
               bool isOwner, bool inGroup) const override;
};
} // namespace perms
