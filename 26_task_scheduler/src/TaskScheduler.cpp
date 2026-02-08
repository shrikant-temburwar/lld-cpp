#include "scheduler/TaskScheduler.h"

namespace scheduler {
// Schedule a task; priority queue orders by delay
void TaskScheduler::schedule(const Task& task) {
    queue_.push({task.delayMs, task});
}

// Execute the task with the smallest delay (if any)
void TaskScheduler::runOnce() {
    if (queue_.empty()) return; // no tasks
    auto item = queue_.top(); // peek earliest task
    queue_.pop(); // remove from queue
    item.task.action(); // execute
}
} // namespace scheduler
