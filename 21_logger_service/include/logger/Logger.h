#pragma once
#include "LogSink.h"
#include <memory>
#include <mutex>
#include <vector>

namespace logger {
// Logger that broadcasts messages to multiple sinks (Observer pattern)
class Logger {
public:
    // Add a log sink for message delivery
    void addSink(std::unique_ptr<LogSink> sink);
    // Log a message at the given level to all sinks
    void log(LogLevel level, const std::string& msg);

private:
    std::mutex mutex_; // protects sink list
    std::vector<std::unique_ptr<LogSink>> sinks_; // registered log sinks
};
} // namespace logger
