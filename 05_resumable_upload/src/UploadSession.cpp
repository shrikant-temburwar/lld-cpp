#include "upload/UploadSession.h"

namespace upload {
// Constructor initializes session state and metadata
UploadSession::UploadSession(std::string fileId, int totalChunks)
    : fileId_(std::move(fileId)), totalChunks_(totalChunks), state_(UploadState::Init) {}

// Transition session to InProgress state
void UploadSession::start() { state_ = UploadState::InProgress; }

// Record a chunk as received; validates state and index
bool UploadSession::uploadChunk(int index) {
    if (state_ != UploadState::InProgress) return false; // not started
    if (index < 0 || index >= totalChunks_) return false; // invalid index
    received_.insert(index); // mark chunk received
    return true;
}

// Complete the upload if all chunks have been received
bool UploadSession::complete() {
    if ((int)received_.size() != totalChunks_) return false; // missing chunks
    state_ = UploadState::Complete;
    return true;
}

// Check if the upload is in the Complete state
bool UploadSession::isComplete() const { return state_ == UploadState::Complete; }
} // namespace upload
