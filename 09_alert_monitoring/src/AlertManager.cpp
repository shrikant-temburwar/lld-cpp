#include "alert/AlertManager.h"

namespace alert {
// Register a new alert rule (thread-safe)
void AlertManager::addRule(std::unique_ptr<AlertRule> rule) {
    std::lock_guard<std::mutex> lock(mutex_);
    rules_.push_back(std::move(rule));
}

// Register a new notification channel (thread-safe)
void AlertManager::addChannel(std::unique_ptr<AlertChannel> channel) {
    std::lock_guard<std::mutex> lock(mutex_);
    channels_.push_back(std::move(channel));
}

// Process an incoming metric event and trigger matching alerts
void AlertManager::onMetric(const MetricEvent& event) {
    std::lock_guard<std::mutex> lock(mutex_);
    for (const auto& rule : rules_) {
        if (rule->matches(event)) {
            // Rule matched: send alert message to all channels
            for (const auto& channel : channels_) {
                channel->send(rule->message(event));
            }
        }
    }
}
} // namespace alert
