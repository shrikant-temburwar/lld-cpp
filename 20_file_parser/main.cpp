#include "parser/FileParser.h"
#include "parser/CsvParser.h"
#include <cassert>
#include <iostream>

int main() {
    // Sample CSV content
    std::string csv = "name,age\nA,30\nB,40\n";
    // Parser configured with CSV strategy
    parser::FileParser fp(std::make_unique<parser::CsvParser>());
    auto records = fp.parse(csv);
    // Verify parsing results
    assert(records.size() == 2);
    assert(records[0].fields.at("name") == "A");
    std::cout << "File parser tests passed\n";
}
