#pragma once
#include <set>
#include <string>

namespace upload {

enum class UploadState { Init, InProgress, Complete };

// Represents a resumable upload session with state management
class UploadSession {
public:
    // Initialize session with file ID and total chunks
    UploadSession(std::string fileId, int totalChunks);

    // Start the upload process
    void start();
    // Upload a specific chunk by index
    bool uploadChunk(int index);
    // Mark upload as complete
    bool complete();
    // Check if upload is complete
    bool isComplete() const;

private:
    std::string fileId_; // unique file identifier
    int totalChunks_; // total number of chunks to upload
    std::set<int> received_; // indices of uploaded chunks
    UploadState state_; // current upload state
};
} // namespace upload
