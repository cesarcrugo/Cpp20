#include <algorithm>
#include <functional>
#include <iostream>
#include <list>
#include <numeric>
#include <random>
#include <vector>

int main ()
{
    std::vector<int> v = {1, 3, 7, 8, 5, 12, 2};    // original vector

    std::vector<int> i_asc (v.size());
    std::iota(i_asc.begin(), i_asc.end(), 0);
    std::ranges::stable_sort(i_asc, [&v](int i, int j){return v[i] < v[j];});

    std::vector<int> i_desc (v.size());
    std::iota(i_desc.begin(), i_desc.end(), 0);
    std::ranges::stable_sort(i_desc, [&v](int i, int j){return v[i] > v[j];});

    std::cout << "original: ";
    for (auto &el : v){
        std::cout << el <<  " ";
    }
    std::cout << std::endl;

    std::cout << "Ascending Sort: ";
    for (auto &el : i_asc){
        std::cout << v[el] <<  " ";
    }
    std::cout << std::endl;

    std::cout << "Descendings Sort: ";
    for (auto &el : i_desc){
        std::cout << v[el] <<  " ";
    }
    std::cout << std::endl;

    return 0;
}