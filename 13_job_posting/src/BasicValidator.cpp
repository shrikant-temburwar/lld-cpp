#include "jobs/BasicValidator.h"

namespace jobs {
// Validate required fields: id and type must be non-empty
bool BasicValidator::validate(const Job& job) const {
    return !job.id.empty() && !job.type.empty();
}
} // namespace jobs
