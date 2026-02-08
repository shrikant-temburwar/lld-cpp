#pragma once
#include "Task.h"
#include <queue>
#include <vector>

namespace scheduler {
// Task scheduler with priority queue for delayed execution
class TaskScheduler {
public:
    // Schedule a task for delayed execution
    void schedule(const Task& task);
    // Execute all tasks whose delay has expired
    void runOnce();

private:
    // Internal queue item with delay and task
    struct Item {
        int delayMs; // remaining delay in milliseconds
        Task task; // task to execute
        // Comparison for min-heap (shorter delay has higher priority)
        bool operator<(const Item& other) const { return delayMs > other.delayMs; }
    };
    std::priority_queue<Item> queue_; // min-heap ordered by delay
};
} // namespace scheduler
