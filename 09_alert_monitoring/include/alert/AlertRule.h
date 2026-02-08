#pragma once
#include <string>

namespace alert {
// Metric event containing name and value
struct MetricEvent {
    std::string name; // metric name
    double value; // metric value
};

// Abstract rule for evaluating metric events and generating alerts
class AlertRule {
public:
    virtual ~AlertRule() = default;
    // Check if metric event matches alert conditions
    virtual bool matches(const MetricEvent& event) const = 0;
    // Generate alert message for matching event
    virtual std::string message(const MetricEvent& event) const = 0;
};
} // namespace alert
