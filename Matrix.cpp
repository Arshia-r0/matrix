#include "Matrix.hpp"
#include <iostream>
#include <vector>
#include <algorithm>

Vector2d Matrix::fixJagged(Vector2d& m) {
    row = m.size();
    std::vector<std::size_t> l;
    for(auto i : m) { l.push_back(i.size()); }
    col = *std::max_element(l.begin(), l.end());
    if(std::equal(l.begin()+1, l.end(), l.begin())) return m;
    for(auto it = m.begin(); it != m.end(); it++) {
        if(it->size() < col) {
            for(std::size_t j = (it->size())+1; j != col+1; j++) {
                it->push_back(0);
            }
        }
    }
    return m;
}

Matrix& Matrix::operator=(const Matrix& m) {
    if(this != &m) _matrix = m._matrix;
    return *this;
}

std::ostream& operator<<(std::ostream& out, const Matrix& m) {
    for(auto i : m.getMatrix()) {
        for(auto j : i) {
            out << j << " ";
        }
        out << "\n";
    }
    out << "------\n";
    return out;
}

Matrix operator*(const Matrix& m1, const Matrix& m2) {
    Vector2d answer(m1.getRow(), std::vector<int>(m2.getCol()));
    if(m1.getCol() == m2.getRow()) {
        for(std::size_t i = 0; i < m1.getRow(); i++) {
            for(std::size_t j = 0; j < m1.getCol(); j++) {
                for(std::size_t k = 0; k < m2.getCol(); k++) {
                    answer[i][k] += m1.getMatrix()[i][j] * m2.getMatrix()[j][k];
                }
            }
        }
    }
    return answer;
}

Matrix operator+(const Matrix& m1, const Matrix& m2) {
    Vector2d answer(m1.getRow(), std::vector<int>(m2.getCol()));
    if(m1.getRow() == m2.getRow() && m1.getCol() == m2.getCol()) {
        for(std::size_t i = 0; i < m1.getRow(); i++) {
            for(std::size_t j = 0; j < m1.getCol(); j++) {
                answer[i][j] = m1.getMatrix()[i][j] + m2.getMatrix()[i][j];
            }
            
        }
    }
    return answer;
}
Matrix operator-(const Matrix& m1, const Matrix& m2) {
    Vector2d answer(m1.getRow(), std::vector<int>(m2.getCol()));
    if(m1.getRow() == m2.getRow() && m1.getCol() == m2.getCol()) {
        for(std::size_t i = 0; i < m1.getRow(); i++) {
            for(std::size_t j = 0; j < m1.getCol(); j++) {
                answer[i][j] = m1.getMatrix()[i][j] - m2.getMatrix()[i][j];
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

Matrix Matrix::operator-() {
    Vector2d answer(row, std::vector<int>(col));
    for(std::size_t i = 0; i < row; i++) {
        for(std::size_t j = 0; j < col; j++) {
            answer[i][j] = -_matrix[i][j];
        }
    }
    return answer;
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

Vector2d Matrix::getMatrix() const { return _matrix; }
std::size_t Matrix::getRow() const { return row; }
std::size_t Matrix::getCol() const { return col; }

Matrix& Matrix::setMatrix(Vector2d& m) { 
    _matrix = fixJagged(m);
    return *this;
}

Matrix& Matrix::setMatrix(Matrix& M) {
    _matrix = M.getMatrix();
    return *this;
}