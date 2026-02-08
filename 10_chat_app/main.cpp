#include "chat/ChatService.h"
#include "chat/User.h"
#include <cassert>
#include <iostream>

int main() {
    chat::ChatService service;
    auto room = service.getOrCreateRoom("general");

    chat::User alice("alice");
    chat::User bob("bob");

    // Join users to the room
    room->join(&alice);
    room->join(&bob);

    // Alice sends a message
    chat::Message msg{"alice", "hello", std::chrono::system_clock::now()};
    room->send(msg);

    // Both users should have received the message
    assert(!alice.inbox().empty());
    assert(!bob.inbox().empty());
    std::cout << "Chat tests passed\n";
}
