#pragma once
#include "UploadSession.h"
#include <memory>
#include <unordered_map>

namespace upload {
// Manages multiple upload sessions for resumable uploads
class UploadManager {
public:
    // Create a new upload session for a file with given total chunks
    std::shared_ptr<UploadSession> createSession(const std::string& fileId, int totalChunks);
    // Retrieve an existing upload session by file ID
    std::shared_ptr<UploadSession> getSession(const std::string& fileId) const;

private:
    std::unordered_map<std::string, std::shared_ptr<UploadSession>> sessions_; // active upload sessions by file ID
};
} // namespace upload
