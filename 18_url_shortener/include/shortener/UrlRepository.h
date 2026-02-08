#pragma once
#include <string>
#include <unordered_map>

namespace shortener {
// Repository for storing short code to URL mappings
class UrlRepository {
public:
    // Store a short code to URL mapping
    void save(const std::string& code, const std::string& url);
    // Retrieve a URL by short code
    std::string get(const std::string& code) const;

private:
    std::unordered_map<std::string, std::string> data_; // code -> URL mapping
};
} // namespace shortener
