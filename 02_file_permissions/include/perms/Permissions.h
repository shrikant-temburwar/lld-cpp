#pragma once

namespace perms {
// Unix-style permissions using bitmasks (r=4,w=2,x=1)
struct Permissions {
    int user;  // owner permissions bitmask
    int group; // group permissions bitmask
    int other; // others permissions bitmask
};

// File access actions
enum class Action { Read, Write, Execute };
} // namespace perms
