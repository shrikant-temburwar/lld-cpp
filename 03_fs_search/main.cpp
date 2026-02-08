#include "search/SearchService.h"
#include "search/NameCriteria.h"
#include "search/ContentCriteria.h"
#include "fs/InMemoryFileSystem.h"
#include <cassert>
#include <iostream>

int main() {
    fs::InMemoryFileSystem fs;
    fs.createDir("/docs");
    fs.createFile("/docs/a.txt");
    fs.writeFile("/docs/a.txt", "hello world");

    search::SearchService svc;
    // Search by filename
    search::NameCriteria nc("a.txt");
    auto byName = svc.search(fs.root(), nc);
    assert(!byName.empty());

    // Search by file content
    search::ContentCriteria cc("hello");
    auto byContent = svc.search(fs.root(), cc);
    assert(!byContent.empty());

    std::cout << "Search tests passed\n";
}
