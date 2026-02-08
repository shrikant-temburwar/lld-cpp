#pragma once
#include <string>

namespace jobmgr {
// Configuration for a job type including parallelism settings
struct JobTypeConfig {
    std::string type; // job type name
    bool allowParallel; // whether multiple instances can run concurrently
};
} // namespace jobmgr
