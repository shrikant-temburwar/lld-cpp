#include "logger/Logger.h"
#include "logger/ConsoleSink.h"
#include <iostream>

int main() {
    logger::Logger log;
    // Add console output sink
    log.addSink(std::make_unique<logger::ConsoleSink>());
    // Log an info-level message
    log.log(logger::LogLevel::Info, "Hello Logger");
    std::cout << "Logger tests passed\n";
}
