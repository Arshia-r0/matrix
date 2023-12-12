#pragma once
#include <vector>
#include <ostream>

using Vector2d = std::vector<std::vector<int>>;

class Matrix {
private:
    std::size_t row, col;
    Vector2d _matrix;
    Vector2d fixJagged(Vector2d& m);

public:

    Matrix(Vector2d m) {
        _matrix = fixJagged(m);
    }

    Matrix& setMatrix(Vector2d& m);
    Matrix& setMatrix(Matrix& M);
    Vector2d getMatrix() const;
    std::size_t getRow() const;
    std::size_t getCol() const;

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