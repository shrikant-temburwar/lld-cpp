#include "fs/InMemoryFileSystem.h"
#include <cassert>
#include <iostream>

int main() {
    fs::InMemoryFileSystem fs;
    // Create a directory
    assert(fs.createDir("/docs"));
    // Create a file inside the directory
    assert(fs.createFile("/docs/readme.txt"));
    // Write content to the file
    assert(fs.writeFile("/docs/readme.txt", "hello"));
    // Verify read back
    assert(fs.readFile("/docs/readme.txt") == "hello");
    // List directory entries
    auto list = fs.list("/docs");
    assert(!list.empty());
    // Remove the file
    assert(fs.remove("/docs/readme.txt"));
    std::cout << "InMemoryFileSystem tests passed\n";
}
