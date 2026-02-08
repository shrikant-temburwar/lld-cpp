#include "vfs/VersionedFileSystem.h"
#include <cassert>
#include <iostream>

int main() {
    vfs::VersionedFileSystem fs;
    // Write two versions of the same file
    fs.write("/a.txt", "v1");
    fs.write("/a.txt", "v2");
    // Latest version should be 2
    assert(fs.latestVersion("/a.txt") == 2);
    // Read version 1 should return v1
    assert(fs.read("/a.txt", 1) == "v1");
    std::cout << "Versioned FS tests passed\n";
}
