#pragma once
#include "PermissionStrategy.h"
#include <memory>

namespace perms {
// Permission manager that delegates to a strategy for access control
class PermissionManager {
public:
    // Constructor receives the permission strategy to use
    explicit PermissionManager(std::unique_ptr<PermissionStrategy> strategy);
    // Check if user can perform action on resource with given permissions
    bool canAccess(const User& user, const Permissions& perms, Action action,
                   bool isOwner, bool inGroup) const;

private:
    std::unique_ptr<PermissionStrategy> strategy_; // injected permission strategy
};
} // namespace perms
