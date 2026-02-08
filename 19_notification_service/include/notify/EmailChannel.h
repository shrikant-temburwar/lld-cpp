#pragma once
#include "Channel.h"

namespace notify {
// Email channel implementation that prints to stdout (demo)
class EmailChannel : public Channel {
public:
    // Send notification via email (demo implementation)
    void send(const Notification& notification) override;
};
} // namespace notify
