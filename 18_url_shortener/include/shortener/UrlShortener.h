#pragma once
#include "IdGenerator.h"
#include "UrlRepository.h"
#include <string>

namespace shortener {
// URL shortener service that generates short codes and resolves URLs
class UrlShortener {
public:
    UrlShortener();
    // Generate a short code for a URL
    std::string shorten(const std::string& url);
    // Resolve a short code back to the original URL
    std::string resolve(const std::string& code) const;

private:
    IdGenerator generator_; // generates unique short codes
    UrlRepository repo_; // stores code to URL mappings
};
} // namespace shortener
