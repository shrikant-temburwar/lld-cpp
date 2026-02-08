#include "shortener/IdGenerator.h"

namespace shortener {
// Generate the next unique short code using base-62 encoding
// Base-62 encoding uses a 62-character alphabet (0-9, a-z, A-Z) to represent numbers
std::string IdGenerator::next() {
    long value = ++counter_;
    std::string code;
    while (value > 0) {
        // encode digit in base-62 using the alphabet_
        code.push_back(alphabet_[value % alphabet_.size()]); 
        value /= alphabet_.size();
    }
    if (code.empty()) code = "0"; // fallback if something went wrong
    return code;
}
} // namespace shortener
