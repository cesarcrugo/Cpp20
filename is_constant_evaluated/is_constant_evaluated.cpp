#include <iostream>
#include <type_traits>

constexpr int f(){
    if (std::is_constant_evaluated()) { // resolved at compile time?
        return 1;
    } else {
        return 0;
    }
    return 0;
}

void print (int i)
{
    if (i) {
        std::cout << "Resolved at compile time" << std::endl;
    } else {
        std::cout << "Resolved at run time" << std::endl;
    }
}

int main ()
{
    constexpr auto compileTime = f();
    print(compileTime);

    auto runTime = f();
    print(runTime);

    return 0;
}