#include "perms/PermissionManager.h"

namespace perms {
// Constructor accepts a strategy (e.g., strict or permissive)
PermissionManager::PermissionManager(std::unique_ptr<PermissionStrategy> strategy)
    : strategy_(std::move(strategy)) {}

// Delegate access check to the injected strategy
bool PermissionManager::canAccess(const User& user, const Permissions& perms,
                                  Action action, bool isOwner, bool inGroup) const {
    return strategy_->allow(user, perms, action, isOwner, inGroup);
}
} // namespace perms
