#include "shortener/UrlShortener.h"
#include <cassert>
#include <iostream>

int main() {
    shortener::UrlShortener s;
    // Shorten a long URL
    auto code = s.shorten("https://example.com");
    // Resolve back to original URL
    assert(s.resolve(code) == "https://example.com");
    std::cout << "URL shortener tests passed\n";
}
