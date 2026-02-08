#pragma once
#include "Message.h"

namespace chat {
// Observer interface for chat message notifications
class ChatObserver {
public:
    virtual ~ChatObserver() = default;
    // Called when a new message is received in the chat room
    virtual void onMessage(const Message& message) = 0;
};
} // namespace chat
