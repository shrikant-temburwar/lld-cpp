#pragma once
#include "Channel.h"
#include <memory>
#include <mutex>
#include <vector>

namespace notify {
// Notification service that manages multiple delivery channels
class NotificationService {
public:
    // Add a delivery channel (e.g., email, SMS, push)
    void addChannel(std::unique_ptr<Channel> channel);
    // Broadcast notification to all registered channels
    void notify(const Notification& notification);

private:
    std::mutex mutex_; // protects channel list
    std::vector<std::unique_ptr<Channel>> channels_; // registered delivery channels
};
} // namespace notify
