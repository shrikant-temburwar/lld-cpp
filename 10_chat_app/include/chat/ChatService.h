#pragma once
#include "ChatRoom.h"
#include <memory>
#include <string>
#include <unordered_map>

namespace chat {
// Chat service that manages multiple chat rooms
class ChatService {
public:
    // Get existing room or create new one if it doesn't exist
    std::shared_ptr<ChatRoom> getOrCreateRoom(const std::string& roomId);

private:
    std::unordered_map<std::string, std::shared_ptr<ChatRoom>> rooms_; // active chat rooms by ID
};
} // namespace chat
