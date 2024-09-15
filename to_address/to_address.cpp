#include <iostream>
#include <memory>
#include <vector>

int main ()
{
    /*
     * std::to_address returns the memory address
     * of a pointer, including smart pointers
     */
    auto printAddress = [](const auto &p){
        std::cout << std::to_address(p) << std::endl;
    };

    auto uniquePtr = std::make_unique<int>(15);
    printAddress(uniquePtr); // heap allocated

    auto value = 12; // stack allocated
    auto *ptr = &value;
    printAddress(ptr);
    printAddress(&value);

    std::vector <int> v {2, 5, 7};
    printAddress(v.begin());
    printAddress(v.end());
    

    return 0;
}