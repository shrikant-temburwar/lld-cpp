#pragma once
#include <string>
#include <unordered_map>

namespace jobs {
// Job posting with ID, type, and flexible attributes
struct Job {
    std::string id; // unique job identifier
    std::string type; // job type/category
    std::unordered_map<std::string, std::string> attributes; // flexible job attributes
};
} // namespace jobs
