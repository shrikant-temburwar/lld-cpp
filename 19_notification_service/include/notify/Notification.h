#pragma once
#include <string>

namespace notify {
// Notification message containing user ID and message content
struct Notification {
    std::string userId; // target user identifier
    std::string message; // notification message content
};
} // namespace notify
