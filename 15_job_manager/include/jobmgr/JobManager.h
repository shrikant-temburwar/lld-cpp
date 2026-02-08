#pragma once
#include "IdGenerator.h"
#include "JobRun.h"
#include "JobTypeConfig.h"
#include <mutex>
#include <unordered_map>

namespace jobmgr {
// Job manager that enforces parallelism limits per job type
class JobManager {
public:
    // Register a job type with its parallelism configuration
    void registerType(const JobTypeConfig& config);
    // Start a job of given type (returns run ID)
    JobRun startJob(const std::string& type);
    // Mark a job as finished and update counters
    void finishJob(const std::string& runId);

private:
    IdGenerator generator_; // generates unique run IDs
    std::mutex mutex_; // protects shared state
    std::unordered_map<std::string, JobTypeConfig> configs_; // job type configurations
    std::unordered_map<std::string, int> runningCount_; // running jobs count by type
    std::unordered_map<std::string, std::string> runToType_; // run ID to job type mapping
};
} // namespace jobmgr
