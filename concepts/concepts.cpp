#include <iostream>
#include <type_traits>

/*
 * Pre-C++20 typename constraint is SFINAE:
 * Substitution Failure Is Not An Error
 *
 * If substitution fails, the function is
 * removed, and another function looked to
 * be used instead
*/
template<typename Float, 
         typename = std::enable_if_t<std::is_floating_point_v<Float>>>
auto sfinae(Float val_1, Float val_2)
{
    return val_1 + val_2;
}

/*
 * C++20 Concept
 * First possible syntax
*/
template<typename Float>
auto conceptsSyntax1(Float val_1, Float val_2) requires std::is_floating_point_v<Float>
{
    return val_1 + val_2;
}

/*
 * C++20 Concept
 * Second possible syntax
*/
template<typename T>
concept floating_point = std::is_floating_point_v<T>;

template<floating_point Float>
auto conceptsSyntax2(Float val_1, Float val_2)
{
    return val_1 + val_2;
}

/*
 * C++20 Concept
 * Third possible syntax
 * 
 * This syntax allows passing different parameter types
 * while both types comply with restriction: floating point
 * 
 * floating_point at the beginning of function definition
 * allows to return any kind of floating point only
*/
template<typename T>
concept floating_point = std::is_floating_point_v<T>;

floating_point auto conceptsSyntax3(floating_point auto val_1, floating_point auto val_2) // auto implicitly creates a template definition
{
    return val_1 + val_2;
}

int main ()
{
    // sfinae (2, 2.5); // COMPILER ERROR: SFINAE implementation requires both parameters to be floating point
    sfinae(2.5, 2.5);

    // conceptsSyntax1 (2, 2.5); // COMPILER ERROR: Concept implementation requires both parameters to be floating point
    conceptsSyntax1(2.5, 2.5);

    // conceptsSyntax2 (2, 2.5); // COMPILER ERROR: Concept implementation requires both parameters to be floating point
    // conceptsSyntax2(2.5, 2.5f);  // COMPILER ERROR: Both parameters shall have the same type
    conceptsSyntax2(2.5, 2.5);

    conceptsSyntax3(2.5, 2.5f);

    floating_point auto val = conceptsSyntax3(2.5, 2.5f); // val is automatically deduced floating point variable
}