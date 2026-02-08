#include "fs/FileSystem.h"
#include <cassert>
#include <iostream>

int main() {
    fsbasic::FileSystem fs;
    // Create a directory
    fs.createDir("/docs");
    // Create a file inside the directory
    fs.createFile("/docs/a.txt");
    // List directory entries
    auto list = fs.list("/docs");
    assert(!list.empty());
    std::cout << "File system tests passed\n";
}
