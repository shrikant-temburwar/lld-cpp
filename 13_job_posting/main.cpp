#include "jobs/JobService.h"
#include "jobs/BasicValidator.h"
#include <cassert>
#include <iostream>

int main() {
    // Wire up dependencies
    auto repo = std::make_unique<jobs::JobRepository>();
    auto validator = std::make_unique<jobs::BasicValidator>();
    jobs::JobService service(std::move(validator), std::move(repo));

    // Create a sample job
    jobs::Job job{"1", "engineering", {{"title", "SDE"}}};
    // Post and retrieve
    assert(service.postJob(job));
    assert(service.getJob("1").type == "engineering");
    std::cout << "Job posting tests passed\n";
}
