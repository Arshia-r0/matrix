#include "Matrix.hpp"
#include <iostream>

int main() {
    Matrix a1{{
        {1, 2},
        {1, 0, 0},
        {9, 0, 9}
    }},
    a2{{
        {2, 3, 7},
        {2, 0, 7},
        {1, 1, 7}
    }};
    Matrix a3 = a1 * a2;
    Matrix a4 = a1 + a2;
    Matrix a5 = a1 - a2;
    a5 += a1;
    a3 -= a4;
    a1 = -a1.transpose();
    std::cout << a1 << a2 << a3 << a4 << a5;
}