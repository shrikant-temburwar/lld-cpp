#include "chat/ChatRoom.h"

namespace chat {
// Add a user (observer) to the room
void ChatRoom::join(ChatObserver* user) {
    std::lock_guard<std::mutex> lock(mutex_);
    observers_.push_back(user);
}

// Remove a user from the room
void ChatRoom::leave(ChatObserver* user) {
    std::lock_guard<std::mutex> lock(mutex_);
    observers_.erase(std::remove(observers_.begin(), observers_.end(), user), observers_.end());
}

// Broadcast a message to all observers in the room
void ChatRoom::send(const Message& message) {
    std::lock_guard<std::mutex> lock(mutex_);
    for (auto* obs : observers_) {
        obs->onMessage(message);
    }
}
} // namespace chat
