#include "logger/Logger.h"

namespace logger {
// Register a log sink (thread-safe)
void Logger::addSink(std::unique_ptr<LogSink> sink) {
    std::lock_guard<std::mutex> lock(mutex_);
    sinks_.push_back(std::move(sink));
}

// Write a log message to all registered sinks
void Logger::log(LogLevel level, const std::string& msg) {
    std::lock_guard<std::mutex> lock(mutex_);
    for (const auto& sink : sinks_) sink->write(level, msg); // broadcast
}
} // namespace logger
