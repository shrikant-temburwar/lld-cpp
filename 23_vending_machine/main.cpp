#include "vending/VendingMachine.h"
#include <cassert>
#include <iostream>

int main() {
    // Set up inventory with 2 Colas at price 10
    vending::Inventory inv;
    inv.addProduct({"c1", "Cola", 10}, 2);
    vending::VendingMachine vm(inv);

    // Insert exact price and purchase
    vm.insertCoin(10);
    assert(vm.select("c1") == "DISPENSED");
    std::cout << "Vending machine tests passed\n";
}
