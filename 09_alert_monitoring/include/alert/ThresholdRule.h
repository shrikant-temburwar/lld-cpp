#pragma once
#include "AlertRule.h"

namespace alert {
// Alert rule that triggers when metric exceeds threshold
class ThresholdRule : public AlertRule {
public:
    // Initialize with metric name and threshold value
    ThresholdRule(std::string metricName, double threshold);
    // Check if metric value exceeds threshold
    bool matches(const MetricEvent& event) const override;
    // Generate alert message for threshold breach
    std::string message(const MetricEvent& event) const override;

private:
    std::string metricName_; // name of metric to monitor
    double threshold_; // alert threshold value
};
} // namespace alert
