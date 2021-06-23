#include <iostream>
#include "geometry.h"

int main(int, char**)
{
    pdelib::point p0(0.20000000000000001110, 0.20000000000000001110, 0.20000000000000001110);
    pdelib::point p1(0.19999999999999998335, 0.19999999999999998335, 0.19999999999999998335);

    std::cout.precision(20);
    std::cout << p0 << std::endl << p1 << std::endl;
    std::cout << std::boolalpha;
    std::cout << (p0 != p1) << std::endl;
    pdelib::point p3 = p1 + p0;
    // pdelib::point p3;
    // p3 -= p1;
    std::cout << p3 << std::endl;
    return 0;
}
