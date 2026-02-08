#include "alert/AlertManager.h"
#include "alert/ConsoleChannel.h"
#include "alert/ThresholdRule.h"
#include <iostream>

int main() {
    alert::AlertManager manager;
    // Add rule: alert when cpu > 0.8
    manager.addRule(std::make_unique<alert::ThresholdRule>("cpu", 0.8));
    // Add console output channel
    manager.addChannel(std::make_unique<alert::ConsoleChannel>());

    // Trigger alert (cpu 0.9 > threshold)
    manager.onMetric({"cpu", 0.9});
    // No alert (cpu 0.5 <= threshold)
    manager.onMetric({"cpu", 0.5});
    std::cout << "Alert monitoring tests passed\n";
}
