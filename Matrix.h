#pragma once
#include <vector>
#include <ostream>

using Vector2d = std::vector<std::vector<int>>;

class Matrix {
public:
    Vector2d _matrix;
    std::size_t row, col;

    Matrix(Vector2d m) : _matrix{m} {
        row = _matrix.size();
        col = _matrix[0].size();
    }

    Matrix transpose();
    Matrix& operator=(const Matrix& m);
    Matrix& operator*=(const Matrix& m2);
    Matrix& operator+=(const Matrix& m2);
    Matrix& operator-=(const Matrix& m2);
    Matrix& operator-();
};

Matrix operator*(const Matrix& m1, const Matrix& m2);
Matrix operator+(const Matrix& m1, const Matrix& m2);
Matrix operator-(const Matrix& m1, const Matrix& m2);
std::ostream& operator<<(std::ostream& out, const Matrix& m);