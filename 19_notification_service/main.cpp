#include "notify/NotificationService.h"
#include "notify/EmailChannel.h"
#include <iostream>

int main() {
    notify::NotificationService service;
    // Register an email channel (demo implementation)
    service.addChannel(std::make_unique<notify::EmailChannel>());
    // Send a notification; it will be printed by the channel
    service.notify({"user1", "Welcome"});
    std::cout << "Notification tests passed\n";
}
