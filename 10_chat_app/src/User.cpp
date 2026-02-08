#include "chat/User.h"

namespace chat {
// Constructor stores user identifier
User::User(std::string id) : id_(std::move(id)) {}

// Observer callback: store incoming message in inbox
void User::onMessage(const Message& message) {
    inbox_.push_back(message);
}

// Accessors
const std::vector<Message>& User::inbox() const { return inbox_; }
const std::string& User::id() const { return id_; }
} // namespace chat
