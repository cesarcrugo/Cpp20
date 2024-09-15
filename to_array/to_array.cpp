#include <array>
#include <string>

 int main()
 {
    const int c_array [3] = {1, 2, 3};
    const std::array<int, 3> arr = std::to_array(c_array); // std::to_array takes a c array as input

    std::string str = "Hello World"; // this is not a c array
    //const std::array<int, 3> arrStr = std::to_array(str); // COMPILER ERROR

    const auto arrStr = std::to_array("Hello World");
 }
