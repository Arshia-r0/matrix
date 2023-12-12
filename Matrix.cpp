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
    Vector2d answer(m1.row, std::vector<int>(m2.col));
    if(m1.col == m2.row) {
        for(std::size_t i = 0; i < m1.row; i++) {
            for(std::size_t j = 0; j < m1.col; j++) {
                for(std::size_t k = 0; k < m2.col; k++) {
                    answer[i][k] += m1._matrix[i][j] * m2._matrix[j][k];
                }
            }
        }
    }
    return answer;
}

Matrix operator+(const Matrix& m1, const Matrix& m2) {
    Vector2d answer(m1.row, std::vector<int>(m2.col));
    if(m1.row == m2.row && m1.col == m2.col) {
        for(std::size_t i = 0; i < m1.row; i++) {
            for(std::size_t j = 0; j < m1.col; j++) {
                answer[i][j] = m1._matrix[i][j] + m2._matrix[i][j];
            }
            
        }
    }
    return answer;
}
Matrix operator-(const Matrix& m1, const Matrix& m2) {
    Vector2d answer(m1.row, std::vector<int>(m2.col));
    if(m1.row == m2.row && m1.col == m2.col) {
        for(std::size_t i = 0; i < m1.row; i++) {
            for(std::size_t j = 0; j < m1.col; j++) {
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

Matrix& Matrix::operator-() {
    for(std::size_t i = 0; i < row; i++) {
        for(std::size_t j = 0; j < col; j++) {
            _matrix[i][j] = -_matrix[i][j];
        }
    }
    return *this;
};

Matrix Matrix::transpose() {
    Vector2d answer(row, std::vector<int>(col));
    for(std::size_t i = 0; i < row; i++) {
        for(std::size_t j = 0; j < col; j++) {
            answer[i][j] = _matrix[j][i];
        }
    }
    return answer;
}