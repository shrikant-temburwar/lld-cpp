#pragma once
#include "Permissions.h"
#include "Types.h"

namespace perms {
// Strategy interface for permission checking (Strategy pattern)
class PermissionStrategy {
public:
    virtual ~PermissionStrategy() = default;
    // Check if user is allowed to perform action on resource
    virtual bool allow(const User& user, const Permissions& perms, Action action,
                       bool isOwner, bool inGroup) const = 0;
};
} // namespace perms
