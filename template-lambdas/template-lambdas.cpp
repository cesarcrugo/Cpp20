#include <iostream>

int main ()
{
    int capturedValue = 12;
    
    // C++17 lambdas
    auto l = [&capturedValue](auto i, auto j){
        return capturedValue + i + j;
    };

    auto result = l(1, 2.7);
    std::cout << result << std::endl;

    /*
     * C++20 template sintax for lambdas
     *
     * This is equivalent to the above as auto already 
     * used template type deduction rules.
     * 
     * However, a possible use case is to constrait
     * input types
     */
    auto l2 = [&capturedValue]<typename T>(T i, T j){
        return capturedValue + i + j;
    };

    // int result2 = l2(1, 2.7); COMPILER ERROR
    auto result2 = l2(1.0, 2.7);
    std::cout << result2 << std::endl;

    return 0;
}