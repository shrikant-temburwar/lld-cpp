#include "jobmgr/IdGenerator.h"

namespace jobmgr {
// Generate the next unique run identifier
std::string IdGenerator::next() {
    int id = ++counter_; // increment and format
    return "run-" + std::to_string(id);
}
} // namespace jobmgr
