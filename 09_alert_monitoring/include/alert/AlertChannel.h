#pragma once
#include <string>

namespace alert {
// Abstract channel for delivering alert notifications
class AlertChannel {
public:
    virtual ~AlertChannel() = default;
    // Send an alert message through this channel
    virtual void send(const std::string& alertMessage) = 0;
};
} // namespace alert
