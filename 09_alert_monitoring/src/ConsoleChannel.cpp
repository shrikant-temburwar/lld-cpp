#include "alert/ConsoleChannel.h"
#include <iostream>

namespace alert {
// Simple channel that prints alert messages to stdout
void ConsoleChannel::send(const std::string& alertMessage) {
    std::cout << alertMessage << "\n";
}
} // namespace alert
