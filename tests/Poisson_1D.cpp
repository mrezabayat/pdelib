#include <iostream>
#include "geometry.h"

int main(int, char**)
{
    pdelib::point startPoint;
    pdelib::point endPoint(1., 0., 0.);

    pdelib::line lineA(startPoint, endPoint);
    std::cout << lineA.getStartPoint() << std::endl
              << lineA.getEndPoint() << std::endl;
    return 0;
}
