#pragma once
#include "IpPool.h"
#include <string>
#include <unordered_map>

namespace ipam {
// IP address manager that handles client leases and pool management
class IpManager {
public:
    // Initialize with an IP pool
    explicit IpManager(IpPool pool);
    // Allocate an IP address to a client
    std::string requestIp(const std::string& clientId);
    // Release an IP address back to the pool
    void releaseIp(const std::string& clientId);

private:
    IpPool pool_; // underlying IP address pool
    std::unordered_map<std::string, std::string> leases_; // client ID -> IP address mapping
};
} // namespace ipam
