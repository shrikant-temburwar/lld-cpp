#include "upload/UploadManager.h"

namespace upload {
// Create a new upload session and store it by fileId
std::shared_ptr<UploadSession> UploadManager::createSession(const std::string& fileId, int totalChunks) {
    auto session = std::make_shared<UploadSession>(fileId, totalChunks);
    sessions_[fileId] = session;
    return session;
}

// Retrieve an existing session by fileId; nullptr if not found
std::shared_ptr<UploadSession> UploadManager::getSession(const std::string& fileId) const {
    auto it = sessions_.find(fileId);
    if (it == sessions_.end()) return nullptr;
    return it->second;
}
} // namespace upload
