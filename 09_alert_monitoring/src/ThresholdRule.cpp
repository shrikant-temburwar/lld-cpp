#include "alert/ThresholdRule.h"

namespace alert {
// Constructor stores metric name and numeric threshold
ThresholdRule::ThresholdRule(std::string metricName, double threshold)
    : metricName_(std::move(metricName)), threshold_(threshold) {}

// Check if the event matches this rule by name and exceeds threshold
bool ThresholdRule::matches(const MetricEvent& event) const {
    return event.name == metricName_ && event.value > threshold_;
}

// Generate a human-readable alert message for the event
std::string ThresholdRule::message(const MetricEvent& event) const {
    return "ALERT: " + event.name + " exceeded " + std::to_string(threshold_);
}
} // namespace alert
