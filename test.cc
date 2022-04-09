#include "polynomial.h"
#include <iostream>

int main()
{
    polynomial::polynomial p1{{1.0, 0.0}, {1.0, 1.0}}, p2{{1.0, 0.0}, {-1.0, 1.0}};
    polynomial::polynomial p3 = p1 * p2;

    

    return 0;
}