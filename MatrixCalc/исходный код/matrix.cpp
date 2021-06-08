#include "matrix.h"

//конструкторы
matrix::matrix() { }
matrix::matrix(int r, int c) {
    rows = r;
    cols = c;
}
//деструктор
matrix::~matrix() { }

//Перегрузка оператора помещения в поток  <<
std::ostream& operator<<(std::ostream &s, matrix &c) {
    for (int i = 0; i < c.getRows(); i ++) {
        for (int j = 0; j < c.getCols(); j++) {
          s << "  " << c.getValue(i,j);
        }
        s << std::endl;
    }
    return s;
}

//Основные операции

//Сложение
matrix matrix::add(matrix &B) const {
    matrix defMatrix(rows,cols);
    if (rows == B.rows && cols == B.cols) {
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                defMatrix.setValue(i,j, getValue(i,j)+B.getValue(i,j));
            }
        }
    }
    return defMatrix;
}

//вычитание
matrix matrix::subs(matrix &secondMatrix) const {
    matrix defMatrix = secondMatrix.multiply(-1);
    return add(defMatrix);
}

//умножение
matrix matrix::multiply(matrix &secondMatrix) const {
    matrix defMatrix;
    if (cols == secondMatrix.getRows()) {
        defMatrix.setSize(rows, secondMatrix.getCols());
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < secondMatrix.getCols(); j++) {
               defMatrix.setValue(i,j, dot(secondMatrix, i, j));
            }
        }
    }
    return defMatrix;
}

//Скалярное произведение - строка одной матрицы на столбец другой
float matrix::dot(matrix &secondMatrix, int row, int col)  const {
    float sum = 0;
    for (int i = 0; i < cols; i++) {
            sum = sum + getValue(row,i)*secondMatrix.getValue(i, col);
    }
    return sum;
}

//Умножение на число
matrix matrix::multiply(float Number) const {
    matrix defMatrix;
    defMatrix.setSize(rows,cols);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            defMatrix.setValue(i,j, Number*getValue(i,j));
        }
    }
    return defMatrix;
}

//Транспонирование, только для квадратных
matrix matrix::transpose() const {
    matrix tranMatrix(rows,cols);
    for (int i = 0; i < tranMatrix.rows; i++) {
        for (int j = 0; j < tranMatrix.cols; j++) {
            tranMatrix.setValue(i,j, getValue(j,i));
        }
    }
    return tranMatrix;
}

//Поиск определетиля
float matrix::determinant() const {
    float sum = 0;
    if (rows > 2) {
        for (int j = 0; j < cols; j++) {
            matrix M = minor(0,j);
            if (j % 2 == 0) {
                sum = sum + (getValue(0,j) * M.determinant());
            } else {
                sum = sum - (getValue(0,j) * M.determinant());
            }
        }
    } else {
        sum = sum + ((getValue(0,0) * getValue(1,1)) - (getValue(1,0) * getValue(0,1)));
    }
    return sum;
}

//локальные миноры, необходимы для подсчета определителя
matrix matrix::minor(int i,int j) const {
    matrix minorMatrix(rows-1,cols-1);
    for (int n = 0; n < minorMatrix.getRows();n++) {
        for (int m = 0; m < minorMatrix.getCols(); m++) {
            if (m >= j && n >= i)
                minorMatrix.setValue(n,m, getValue(n + 1,m + 1));
            if (m >= j && n < i)
                    minorMatrix.setValue(n,m, getValue(n, m + 1));
            if (m < j && n >= i)
                minorMatrix.setValue(n,m, getValue(n + 1,m));
            if (n < i && m < j)
                minorMatrix.setValue(n,m, getValue(n, m));
        }
    }
    return minorMatrix;
}
