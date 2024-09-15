#include <iostream>
#include <vector>
#include <algorithm>

int main ()
{
    std::vector<int> v = {5, 5, 5, 5, 1, 2, 3, 5, 6, 9, 2};

    std::cout << "Original: ";
    for (auto &el : v){
        std::cout << el <<  " ";
    }
    std::cout << std::endl;

    /*
     * C++20 std::erase has the exact same behavior as:
     * v.erase(std::remove(begin(v), end(v), 5), end(v));
     * 
     * What std::remove does it to simply move the 5s to
     * the end of the container.
    */
    std::erase(v, 5); // does not take pair of iterators

    std::cout << "No 5s: ";
    for (auto &el : v){
        std::cout << el <<  " ";
    }
    std::cout << std::endl;

    return 0;
}