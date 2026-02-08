#include "chat/ChatService.h"

namespace chat {
// Retrieve an existing room or create a new one by roomId
std::shared_ptr<ChatRoom> ChatService::getOrCreateRoom(const std::string& roomId) {
    auto it = rooms_.find(roomId);
    if (it != rooms_.end()) return it->second; // existing room
    // Create and store new room
    auto room = std::make_shared<ChatRoom>();
    rooms_[roomId] = room;
    return room;
}
} // namespace chat
