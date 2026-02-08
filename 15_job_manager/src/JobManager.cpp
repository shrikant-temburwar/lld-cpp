#include "jobmgr/JobManager.h"

namespace jobmgr {
// Register a job type with its concurrency configuration (thread-safe)
void JobManager::registerType(const JobTypeConfig& config) {
    std::lock_guard<std::mutex> lock(mutex_);
    configs_[config.type] = config;
}

// Start a job of the given type; returns JobRun with runId or empty if rejected
JobRun JobManager::startJob(const std::string& type) {
    std::lock_guard<std::mutex> lock(mutex_);
    auto it = configs_.find(type);
    if (it == configs_.end()) return {"", type}; // unknown type

    // Enforce parallelism rule
    if (!it->second.allowParallel && runningCount_[type] > 0) {
        return {"", type}; // reject: parallel runs not allowed
    }

    // Allocate unique runId and track
    std::string runId = generator_.next();
    runningCount_[type] += 1;
    runToType_[runId] = type;
    return {runId, type};
}

// Mark a job as finished; cleans up tracking (thread-safe)
void JobManager::finishJob(const std::string& runId) {
    std::lock_guard<std::mutex> lock(mutex_);
    auto it = runToType_.find(runId);
    if (it == runToType_.end()) return; // unknown runId
    const auto& type = it->second;
    if (runningCount_[type] > 0) runningCount_[type] -= 1; // decrement count
    runToType_.erase(it); // remove mapping
}
} // namespace jobmgr
