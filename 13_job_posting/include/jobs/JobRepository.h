#pragma once
#include "Job.h"
#include <unordered_map>

namespace jobs {
// Repository for storing and retrieving job postings
class JobRepository {
public:
    // Save a job posting to storage
    bool save(const Job& job);
    // Retrieve a job posting by ID
    Job get(const std::string& id) const;

private:
    std::unordered_map<std::string, Job> jobs_; // job storage by ID
};
} // namespace jobs
