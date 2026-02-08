#pragma once
#include <string>
#include <chrono>

namespace chat {
// Chat message containing sender, text, and timestamp
struct Message {
    std::string from; // sender user ID
    std::string text; // message content
    std::chrono::system_clock::time_point timestamp; // message timestamp
};
} // namespace chat
