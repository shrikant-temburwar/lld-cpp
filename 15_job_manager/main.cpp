#include "jobmgr/JobManager.h"
#include <cassert>
#include <iostream>

int main() {
    jobmgr::JobManager mgr;
    // Register type A that does NOT allow parallel runs
    mgr.registerType({"A", false});
    auto run1 = mgr.startJob("A");
    assert(!run1.runId.empty()); // first run should succeed
    auto run2 = mgr.startJob("A");
    assert(run2.runId.empty()); // second run should be rejected
    mgr.finishJob(run1.runId); // finish first run
    auto run3 = mgr.startJob("A");
    assert(!run3.runId.empty()); // now a new run can start
    std::cout << "JobManager tests passed\n";
}
