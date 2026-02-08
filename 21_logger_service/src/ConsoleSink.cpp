#include "logger/ConsoleSink.h"
#include <iostream>

namespace logger {
// Console sink: prints log messages to stdout (ignores log level)
void ConsoleSink::write(LogLevel, const std::string& msg) {
    std::cout << msg << "\n";
}
} // namespace logger
