#include "notify/NotificationService.h"

namespace notify {
// Register a delivery channel (thread-safe)
void NotificationService::addChannel(std::unique_ptr<Channel> channel) {
    std::lock_guard<std::mutex> lock(mutex_);
    channels_.push_back(std::move(channel));
}

// Broadcast a notification to all registered channels
void NotificationService::notify(const Notification& notification) {
    std::lock_guard<std::mutex> lock(mutex_);
    for (const auto& c : channels_) c->send(notification); // send via each channel
}
} // namespace notify
