#pragma once
#include <vector>
#include <ostream>

using Vector2d = std::vector<std::vector<int>>;

class Matrix {
public:
    Vector2d _matrix;

    Matrix(Vector2d m) : _matrix(m){}
    Matrix& operator=(const Matrix& m);

    Matrix& operator*=(const Matrix& m2);
    Matrix& operator+=(const Matrix& m2);
    Matrix& operator-=(const Matrix& m2);
};

Matrix operator*(const Matrix& m1, const Matrix& m2);
Matrix operator+(const Matrix& m1, const Matrix& m2);
Matrix operator-(const Matrix& m1, const Matrix& m2);
std::ostream& operator<<(std::ostream& out, const Matrix& m);