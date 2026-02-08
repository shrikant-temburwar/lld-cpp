#pragma once
#include <functional>
#include <string>

namespace scheduler {
// Task with ID, delay, and executable action
struct Task {
    std::string id; // unique task identifier
    int delayMs; // delay before execution in milliseconds
    std::function<void()> action; // task executable function
};
} // namespace scheduler
