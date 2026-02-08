#include "sync/LastWriteWins.h"

namespace sync {
// Resolve conflict by selecting the version with the newer timestamp
FileMeta LastWriteWins::resolve(const FileMeta& local, const FileMeta& remote) {
    return local.modifiedAt >= remote.modifiedAt ? local : remote;
}
} // namespace sync
