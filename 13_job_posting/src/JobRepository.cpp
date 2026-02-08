#include "jobs/JobRepository.h"

namespace jobs {
// Save a job to in-memory store; reject if id is missing
bool JobRepository::save(const Job& job) {
    if (job.id.empty()) return false; // invalid job
    jobs_[job.id] = job; // store/overwrite
    return true;
}

// Retrieve a job by id; returns empty Job if not found
Job JobRepository::get(const std::string& id) const {
    auto it = jobs_.find(id);
    if (it == jobs_.end()) return {}; // not found
    return it->second; // return stored job
}
} // namespace jobs
