#include "shortener/UrlRepository.h"

namespace shortener {
// Store a short code to URL mapping
void UrlRepository::save(const std::string& code, const std::string& url) {
    data_[code] = url;
}

// Retrieve a URL by short code; returns empty string if not found
std::string UrlRepository::get(const std::string& code) const {
    auto it = data_.find(code);
    if (it == data_.end()) return ""; // not found
    return it->second;
}
} // namespace shortener
