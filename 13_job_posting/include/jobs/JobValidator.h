#pragma once
#include "Job.h"

namespace jobs {
// Abstract validator for job postings (Strategy pattern)
class JobValidator {
public:
    virtual ~JobValidator() = default;
    // Validate a job posting and return true if valid
    virtual bool validate(const Job& job) const = 0;
};
} // namespace jobs
