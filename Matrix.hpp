#pragma once
#include <vector>
#include <ostream>

using Vector2d = std::vector<std::vector<int>>;

class Matrix {
private:
    std::size_t row, col;
    Vector2d _matrix;
    bool detExists;
    Vector2d fixJagged(Vector2d& m);

public:

    Matrix(Vector2d m) {
        _matrix = fixJagged(m);
    }

    Matrix& setMatrix(Vector2d& m);
    Matrix& setMatrix(Matrix& M);
    auto& getMatrix() const;
    auto& getRow() const;
    auto& getCol() const;

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