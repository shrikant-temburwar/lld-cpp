#pragma once
#include "LogLevel.h"
#include <string>

namespace logger {
// Abstract sink for writing log messages (Strategy pattern)
class LogSink {
public:
    virtual ~LogSink() = default;
    // Write a log message at the given level
    virtual void write(LogLevel level, const std::string& msg) = 0;
};
} // namespace logger
