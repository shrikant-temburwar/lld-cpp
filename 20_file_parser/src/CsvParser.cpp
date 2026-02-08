#include "parser/CsvParser.h"
#include <sstream>

namespace parser {
// Parse CSV content into records (first line = headers)
std::vector<Record> CsvParser::parse(const std::string& content) const {
    std::vector<Record> out;
    std::istringstream ss(content);
    std::string line;
    std::vector<std::string> headers;

    // Parse header line
    if (std::getline(ss, line)) {
        std::istringstream headerStream(line);
        std::string h;
        while (std::getline(headerStream, h, ',')) headers.push_back(h); // split by comma
    }

    // Parse data lines
    while (std::getline(ss, line)) {
        std::istringstream lineStream(line);
        std::string value;
        Record r;
        for (size_t i = 0; i < headers.size(); ++i) {
            if (!std::getline(lineStream, value, ',')) value = ""; // empty field if missing
            r.fields[headers[i]] = value;
        }
        out.push_back(r);
    }
    return out;
}
} // namespace parser
