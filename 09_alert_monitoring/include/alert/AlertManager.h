#pragma once
#include "AlertChannel.h"
#include "AlertRule.h"
#include <memory>
#include <mutex>
#include <vector>

namespace alert {
// Alert manager that evaluates rules and sends notifications
class AlertManager {
public:
    // Add an alert rule for metric evaluation
    void addRule(std::unique_ptr<AlertRule> rule);
    // Add a channel for alert delivery
    void addChannel(std::unique_ptr<AlertChannel> channel);
    // Process a metric event and trigger alerts if rules are satisfied
    void onMetric(const MetricEvent& event);

private:
    std::mutex mutex_; // protects rules and channels
    std::vector<std::unique_ptr<AlertRule>> rules_; // alert evaluation rules
    std::vector<std::unique_ptr<AlertChannel>> channels_; // alert delivery channels
};
} // namespace alert
