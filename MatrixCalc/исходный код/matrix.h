#pragma once
#include <iostream>

#define maxRows 50
#define maxCols 50


class matrix {

public:
    matrix();
    matrix(int n, int m);
    ~matrix();
    //Вспомогательные функции
    inline void setSize(int n, int m) {
        rows = n;
        cols = m;
    }
    inline int getRows() const {
        return rows;
    }
    inline int getCols() const {
        return cols;
    }
    inline float getValue(int n, int m) const {
        return M[n][m];
    }
    inline void setValue(int n, int m, float x) {
        M[n][m] = x;
    }

    //Основные функции
    friend std::ostream& operator<<(std::ostream &s, matrix &c);
    matrix add(matrix &B) const;
    matrix subs(matrix &B) const;
    matrix multiply(matrix &B) const;
    matrix multiply(float c) const;
    matrix inverse() const;
    matrix cofactor() const;
    matrix transpose() const;
    float dot(matrix &B, int row, int col) const;
    float determinant() const;
    matrix minor(int i,int j) const;

private:
    int rows;
    int cols;
    float M[maxRows][maxCols];
};
