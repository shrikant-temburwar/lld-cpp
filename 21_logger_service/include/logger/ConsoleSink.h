#pragma once
#include "LogSink.h"

namespace logger {
// Console sink that writes log messages to stdout
class ConsoleSink : public LogSink {
public:
    // Write log message to console (ignores log level)
    void write(LogLevel level, const std::string& msg) override;
};
} // namespace logger
