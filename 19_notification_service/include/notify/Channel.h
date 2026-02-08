#pragma once
#include "Notification.h"

namespace notify {
// Abstract channel for delivering notifications (Strategy pattern)
class Channel {
public:
    virtual ~Channel() = default;
    // Send a notification through this channel
    virtual void send(const Notification& notification) = 0;
};
} // namespace notify
