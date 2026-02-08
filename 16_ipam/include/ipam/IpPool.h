#pragma once
#include <set>
#include <string>

namespace ipam {
// IP address pool managing a range of addresses
class IpPool {
public:
    // Initialize with start and end IP addresses
    IpPool(std::string startIp, std::string endIp);

    // Allocate an IP address from the pool
    std::string allocate();
    // Release an IP address back to the pool
    void release(const std::string& ip);

private:
    std::string startIp_; // start of IP range
    std::string endIp_; // end of IP range
    std::set<std::string> free_; // available IP addresses (simple lexicographic for LLD)
};
} // namespace ipam
