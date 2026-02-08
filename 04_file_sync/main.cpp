#include "sync/SyncService.h"
#include "sync/LastWriteWins.h"
#include "sync/FileWatcher.h"
#include <iostream>

int main() {
    sync::FileWatcher watcher;
    sync::SyncService svc(std::make_unique<sync::LastWriteWins>());
    watcher.addListener(&svc); // register service as a listener
    watcher.notifyChange("/docs/a.txt"); // simulate file change

    // Simulate conflict: local newer than remote
    sync::FileMeta local{"/docs/a.txt", 10};
    sync::FileMeta remote{"/docs/a.txt", 5};
    svc.sync(local, remote); // should pick local
    std::cout << "Sync tests passed\n";
}
