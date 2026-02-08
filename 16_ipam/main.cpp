#include "ipam/IpManager.h"
#include <cassert>
#include <iostream>

int main() {
    // Create a pool with two IPs
    ipam::IpPool pool("10.0.0.1", "10.0.0.2");
    ipam::IpManager mgr(pool);
    // Allocate IP to client c1
    auto ip1 = mgr.requestIp("c1");
    assert(!ip1.empty());
    // Release c1's IP
    mgr.releaseIp("c1");
    // Allocate IP to client c2 (should reuse the freed IP)
    auto ip2 = mgr.requestIp("c2");
    assert(!ip2.empty());
    std::cout << "IPAM tests passed\n";
}
