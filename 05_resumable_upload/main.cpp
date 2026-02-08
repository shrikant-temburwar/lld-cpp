#include "upload/UploadManager.h"
#include <cassert>
#include <iostream>

int main() {
    upload::UploadManager mgr;
    auto session = mgr.createSession("file1", 3); // 3-chunk file
    session->start(); // begin upload
    // Upload chunks (could be out of order in real use)
    assert(session->uploadChunk(0));
    assert(session->uploadChunk(1));
    assert(session->uploadChunk(2));
    // Finalize once all chunks are received
    assert(session->complete());
    assert(session->isComplete());
    std::cout << "Upload tests passed\n";
}
