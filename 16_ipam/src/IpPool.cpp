#include "ipam/IpPool.h"

namespace ipam {
IpPool::IpPool(std::string startIp, std::string endIp)
    : startIp_(std::move(startIp)), endIp_(std::move(endIp)) {
    free_.insert(startIp_);
    free_.insert(endIp_);
}

std::string IpPool::allocate() {
    if (free_.empty()) return "";
    auto it = free_.begin();
    std::string ip = *it;
    free_.erase(it);
    return ip;
}

void IpPool::release(const std::string& ip) {
    free_.insert(ip);
}
} // namespace ipam
