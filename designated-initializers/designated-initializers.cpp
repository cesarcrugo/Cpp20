#include <iostream>

struct TestStruct {
    int i;
    float f; // COMPILER WARNING
    double d;
};

void dummyFunction (TestStruct s)
{

}

int main ()
{
    TestStruct j {i:2, d:2.5};
    // TestStruct {d:2.5, i:2}; COMPILER ERROR: initialization shall follow the same declaration order

    dummyFunction({i:2, d:2.5});

    auto s = TestStruct{
        i:2,
        .f = 2.2, // another way of designated initializer
        d:[](){return 7.75;}() // can use self called lambda to avoid move semantics
    };
}