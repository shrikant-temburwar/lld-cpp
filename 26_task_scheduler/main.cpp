#include "scheduler/TaskScheduler.h"
#include <cassert>
#include <iostream>

int main() {
    scheduler::TaskScheduler sched;
    bool ran = false;
    // Schedule a task with delay 10ms
    sched.schedule({"t1", 10, [&]() { ran = true; }});
    // Run one iteration (should execute the task)
    sched.runOnce();
    assert(ran);
    std::cout << "Task scheduler tests passed\n";
}
