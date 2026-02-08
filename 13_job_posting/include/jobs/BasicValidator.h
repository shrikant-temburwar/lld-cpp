#pragma once
#include "JobValidator.h"

namespace jobs {
// Basic job validator that checks for required fields
class BasicValidator : public JobValidator {
public:
    // Validate job has required fields (ID and type)
    bool validate(const Job& job) const override;
};
} // namespace jobs
