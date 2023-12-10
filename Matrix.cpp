#include "Matrix.h"
#include <iostream>
#include <vector>

Matrix& Matrix::operator=(const Matrix& m) {
    if(this != &m) _matrix = m._matrix;
    return *this;
}

std::ostream& operator<<(std::ostream& out, const Matrix& m) {
    for(auto i : m._matrix) {
        for(auto j : i) {
            out << j << " ";
        }
        out << "\n";
    }
    out << "------\n";
    return out;
}

Matrix operator*(const Matrix& m1, const Matrix& m2) {
    std::size_t r1  = m1._matrix.size(),
    c1 = m1._matrix[0].size(),
    r2 = m2._matrix.size(),
    c2 = m2._matrix[0].size();
    Vector2d answer(r1, std::vector<int>(c2));
    if(c1 == r2) {
        for(std::size_t i = 0; i < r1; i++) {
            for(std::size_t j = 0; j < c1; j++) {
                for(std::size_t k = 0; k < c2; k++) {
                    answer[i][k] += m1._matrix[i][j] * m2._matrix[j][k];
                }
            }
        }
    }
    return answer;
}

Matrix operator+(const Matrix& m1, const Matrix& m2) {
    std::size_t r1  = m1._matrix.size(),
    c1 = m1._matrix[0].size(),
    r2 = m2._matrix.size(),
    c2 = m2._matrix[0].size();
    Vector2d answer(r1, std::vector<int>(c2));
    if(r1 == r2 && c1 == c2) {
        for(std::size_t i = 0; i < r1; i++) {
            for(std::size_t j = 0; j < c1; j++) {
                answer[i][j] = m1._matrix[i][j] + m2._matrix[i][j];
            }
            
        }
    }
    return answer;
}
Matrix operator-(const Matrix& m1, const Matrix& m2) {
    std::size_t r1  = m1._matrix.size(),
    c1 = m1._matrix[0].size(),
    r2 = m2._matrix.size(),
    c2 = m2._matrix[0].size();
    Vector2d answer(r1, std::vector<int>(c2));
    if(r1 == r2 && c1 == c2) {
        for(std::size_t i = 0; i < r1; i++) {
            for(std::size_t j = 0; j < c1; j++) {
                answer[i][j] = m1._matrix[i][j] - m2._matrix[i][j];
            }
            
        }
    }
    return answer;
}

Matrix& Matrix::operator*=(const Matrix& m2) {
    *this = *this * m2;
    return *this;
}

Matrix& Matrix::operator+=(const Matrix& m2) {
    *this = *this + m2;
    return *this;
}

Matrix& Matrix::operator-=(const Matrix& m2) {
    *this = *this - m2;
    return *this;
}