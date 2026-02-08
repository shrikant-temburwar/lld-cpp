#pragma once
#include <set>
#include <string>

namespace perms {
// User entity with ID and group memberships
struct User {
    std::string id; // unique user identifier
    std::set<std::string> groups; // groups the user belongs to
};
} // namespace perms
