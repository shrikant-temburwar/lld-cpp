#include "notify/EmailChannel.h"
#include <iostream>

namespace notify {
// Demo email channel: prints notification to stdout
void EmailChannel::send(const Notification& notification) {
    std::cout << "Email to " << notification.userId << ": " << notification.message << "\n";
}
} // namespace notify
