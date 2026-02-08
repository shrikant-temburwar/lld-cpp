#pragma once
#include <string>

namespace jobmgr {
// Represents a running job instance
struct JobRun {
    std::string runId; // unique run identifier
    std::string type; // job type
};
} // namespace jobmgr
