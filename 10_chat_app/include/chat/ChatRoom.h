#pragma once
#include "ChatObserver.h"
#include <mutex>
#include <string>
#include <vector>

namespace chat {
// Chat room that manages users and broadcasts messages (observer pattern)
class ChatRoom {
public:
    // Add a user to the chat room
    void join(ChatObserver* user);
    // Remove a user from the chat room
    void leave(ChatObserver* user);
    // Broadcast a message to all users in the room
    void send(const Message& message);

private:
    std::mutex mutex_; // protects observer list
    std::vector<ChatObserver*> observers_; // users in the room
};
} // namespace chat
