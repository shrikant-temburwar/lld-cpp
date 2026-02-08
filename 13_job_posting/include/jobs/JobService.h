#pragma once
#include "JobRepository.h"
#include "JobValidator.h"
#include <memory>

namespace jobs {
// Service layer for job posting management with validation and storage
class JobService {
public:
    // Constructor receives validator and repository (Dependency Injection)
    JobService(std::unique_ptr<JobValidator> validator,
               std::unique_ptr<JobRepository> repo);

    // Post a job after validation
    bool postJob(const Job& job);
    // Retrieve a job by ID
    Job getJob(const std::string& id) const;

private:
    std::unique_ptr<JobValidator> validator_; // job validation strategy
    std::unique_ptr<JobRepository> repo_; // job storage repository
};
} // namespace jobs
