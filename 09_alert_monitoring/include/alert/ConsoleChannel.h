#pragma once
#include "AlertChannel.h"

namespace alert {
// Console channel that prints alert messages to stdout
class ConsoleChannel : public AlertChannel {
public:
    // Print alert message to console
    void send(const std::string& alertMessage) override;
};
} // namespace alert
