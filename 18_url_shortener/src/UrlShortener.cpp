#include "shortener/UrlShortener.h"

namespace shortener {
// Default constructor uses default IdGenerator and UrlRepository
UrlShortener::UrlShortener() = default;

// Shorten a URL: generate a code and store the mapping
std::string UrlShortener::shorten(const std::string& url) {
    std::string code = generator_.next(); // generate unique code
    repo_.save(code, url); // persist mapping
    return code;
}

// Resolve a short code back to the original URL
std::string UrlShortener::resolve(const std::string& code) const {
    return repo_.get(code);
}
} // namespace shortener
