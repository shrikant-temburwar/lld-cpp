#pragma once
#include "ChatObserver.h"
#include <string>
#include <vector>

namespace chat {
// Chat user that receives messages (implements observer pattern)
class User : public ChatObserver {
public:
    explicit User(std::string id);
    // Receive a message from the chat room
    void onMessage(const Message& message) override;

    // Get all received messages
    const std::vector<Message>& inbox() const;
    // Get user ID
    const std::string& id() const;

private:
    std::string id_; // unique user identifier
    std::vector<Message> inbox_; // received messages
};
} // namespace chat
