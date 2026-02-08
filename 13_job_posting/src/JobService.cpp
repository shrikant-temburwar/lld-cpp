#include "jobs/JobService.h"

namespace jobs {
// Constructor receives validator and repository dependencies
JobService::JobService(std::unique_ptr<JobValidator> validator,
                       std::unique_ptr<JobRepository> repo)
    : validator_(std::move(validator)), repo_(std::move(repo)) {}

// Post a job: validate first, then persist
bool JobService::postJob(const Job& job) {
    if (!validator_->validate(job)) return false; // validation failed
    return repo_->save(job); // store job
}

// Retrieve a job by its unique identifier
Job JobService::getJob(const std::string& id) const {
    return repo_->get(id);
}
} // namespace jobs
