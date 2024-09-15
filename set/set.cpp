#include <iostream>
#include <set>
#include <vector>
#include <ranges>

int main ()
{
    std::vector <int> vector = {7, 3, 9, 12, 1};

    /*
     * Set is a container that contains a sorted
     * set of unique objects.
     * 
     * This container sorts keys at construction
    */
    std::set <int> set (vector.begin(), vector.end());
    

    std::cout << "set: ";
    for (auto &el : set){
        std::cout << el <<  " ";
    }
    std::cout << std::endl;

    std::cout << "vector: ";
    for (auto &el : vector){
        std::cout << el <<  " ";
    }
    std::cout << std::endl;

    return 0;
}