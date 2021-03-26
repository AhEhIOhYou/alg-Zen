#include <iostream>
using namespace std;

//вывод системы уравнений (СЛАУ)
void SystemPrint(double** matrix, double* vectB, int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            cout << matrix[i][j] << "*x" << j;
            if (j < size - 1)
                cout << " + ";
        }
        cout << " = " << vectB[i] << endl;
    }
}

//вывод матрицы
void MatrixPrint(double** matrix, double* vectB, int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            cout << matrix[i][j] << "\t";
        }
        cout << "|\t" << vectB[i] << endl;
    }
}


double* gauss(double** matrix, double* vectB, int size) {
    double* x, max;
    int k, index;
    const double eps = 0.00001;
    x = new double[size];
    k = 0;

    //прямой ход -> матрицу к трапецевидному виду приводим
    while (k < size)
    {
        // Поиск строки с максимальным коэффицентом и последущая перестановка строк

        //здесь ищем номер (индекс) этой максимальной строки
        max = abs(matrix[k][k]);
        index = k;
        for (int i = k + 1; i < size; i++)
        {
            if (abs(matrix[i][k]) > max)
            {
                max = abs(matrix[i][k]);
                index = i;
            }
        }

        //проверка на неравенство нулю
        if (max < eps)
        {
            // нет ненулевых диагональных элементов
            cout << "Решение получить невозможно из-за нулевого столбца " << endl;
            cout << "Это доказывает факт того, что вектор b НЕвыражается линейно через систему a(n)" << endl;
            return NULL;

        }
        
        //перестановка строк самой матрицы (без последнего столбца - это вектор б)
        for (int j = 0; j < size; j++)
        {
            double temp = matrix[k][j];
            matrix[k][j] = matrix[index][j];
            matrix[index][j] = temp;
        }

        //перестановка столбца вектора б
        double temp = vectB[k];
        vectB[k] = vectB[index];
        vectB[index] = temp;
       

        //нормализация элементов строк, ориентериуясь на строку, которую (с максимальным) нашли выше

        for (int i = k; i < size; i++)
        {
            double temp = matrix[i][k];
            if (abs(temp) < eps) continue; // для нулевого коэффициента пропустить
            for (int j = 0; j < size; j++)
                matrix[i][j] = matrix[i][j] / temp;
            vectB[i] = vectB[i] / temp;
            if (i == k)  continue; // уравнение не вычитать само из себя
            for (int j = 0; j < size; j++)
                matrix[i][j] = matrix[i][j] - matrix[k][j];
            vectB[i] = vectB[i] - vectB[k];
        }

        //переходим к следующей строке
        k++;
    }

    // обратная подстановка -> получаем еденичную матрицу и заполняем массив ответов
    for (k = size - 1; k >= 0; k--) {
        x[k] = vectB[k];
        for (int i = 0; i < k; i++)
            vectB[i] = vectB[i] - matrix[i][k] * x[k];
    }

    //x - массив ответов возвращаем его
    return x;
}

int main() {

    setlocale(LC_ALL, "ru");

    double** matrix, *vectB;
    int size;

    cout << "Количество векторв a(n): ";
    cin >> size;

    matrix = new double* [size];
    vectB = new double[size];

    cout << "Введи значения векторов a(n):" << endl;
    for (int i = 0; i < size; i++) {

        matrix[i] = new double[size];
        
        //заполняем координаты векторов 
        for (int j = 0; j < size; j++) {
            cout << "a[" << i << "][" << j << "]= ";
            cin >> matrix[i][j];
        }
    }

    cout << "Введи значение вектора b:" << endl;
    for (int i = 0; i < size; i++) {
        cout << "y[" << i << "]= ";
        cin >> vectB[i];
    }

    cout << "Составим ситсему:" << endl;
    SystemPrint(matrix, vectB, size);

    cout << "Составим матрицу векторов:" << endl;
    MatrixPrint(matrix, vectB, size);
    
    vectB = gauss(matrix, vectB, size);

    if (vectB != NULL) {

        cout << "Матрица имеет следующие решения:" << endl;
        for (int i = 0; i < size; i++)
            cout << "x[" << i << "]=" << vectB[i] << endl;
        cout << "Это доказывает факт того, что вектор b линейно выражается через систему a(n)" << endl;
    }

    return 0;
}
