#include "ipam/IpManager.h"
#include <unordered_map>

namespace ipam {
// Constructor takes ownership of an IP pool
IpManager::IpManager(IpPool pool) : pool_(std::move(pool)) {}

// Allocate an IP to a client; reuse existing lease if present
std::string IpManager::requestIp(const std::string& clientId) {
    auto it = leases_.find(clientId);
    if (it != leases_.end()) return it->second; // existing lease
    std::string ip = pool_.allocate(); // try to allocate new IP
    if (!ip.empty()) leases_[clientId] = ip; // record lease
    return ip;
}

// Release a client's IP back to the pool and clear the lease
void IpManager::releaseIp(const std::string& clientId) {
    auto it = leases_.find(clientId);
    if (it == leases_.end()) return; // no lease
    pool_.release(it->second); // return IP to pool
    leases_.erase(it); // clear lease
}
} // namespace ipam
