#pragma once
#include <vector>
#include <ostream>

using Vector2d = std::vector<std::vector<int>>;

class Matrix {
private:
    Vector2d fixJagged(Vector2d& m);

public:
    std::size_t row, col;
    Vector2d _matrix;

    Matrix(Vector2d m) {
        _matrix = fixJagged(m);
    }

    Matrix transpose();
    Matrix& operator=(const Matrix& m);
    Matrix& operator*=(const Matrix& m2);
    Matrix& operator+=(const Matrix& m2);
    Matrix& operator-=(const Matrix& m2);
    Matrix operator-();
};

Matrix operator*(const Matrix& m1, const Matrix& m2);
Matrix operator+(const Matrix& m1, const Matrix& m2);
Matrix operator-(const Matrix& m1, const Matrix& m2);
std::ostream& operator<<(std::ostream& out, const Matrix& m);