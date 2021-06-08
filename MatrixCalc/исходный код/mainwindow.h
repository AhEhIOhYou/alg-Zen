#pragma once

#include <QMainWindow>
#include <QPushButton>
#include <QLabel>
#include <QTextTable>
#include <QTableView>
#include <QTableWidget>
#include <QHBoxLayout>
#include <QMessageBox>
#include "matrix.h"

class MainWindow : public QMainWindow {
    Q_OBJECT
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
private slots:
    //Основные функции для обеих матриц
    void add_m();
    void subtract_m();
    void multiply_m();
    void scalar_mult();

    //Функции только ДЛЯ ОДНОЙ МАТРЦИЫ
    //Функции для первой
    void rowAdd_1();
    void colAdd_1();
    void rowDelete_1();
    void colDelete_1();
    void determinant_1();
    void transpose_1();

    //Функции для второй
    void rowAdd_2();
    void colAdd_2();
    void rowDelete_2();
    void colDelete_2();
    void determinant_2();
    void transpose_2();

private:

    //Сами подопытные матрицы
    matrix m1;
    matrix m2;
    matrix m3;

    //Текстовые окна
    QLabel *label;
    QLabel *det1Label;
    QLabel *det2Label;

    //Кнопки
    //Для обеих матриц
    QPushButton *add_button;
    QPushButton *subtract_button;
    QPushButton *multiply_button;
    QPushButton *scalar_mult_button;

    //ТОЛЬКО для первой матрицы
    QPushButton *add_row_button;
    QPushButton *add_col_button;
    QPushButton *delete_row_button;
    QPushButton *delete_col_button;
    QPushButton *determinant_button;
    QPushButton *transpose_button;

    //ТОЛЬКО для второй матрицы
    QPushButton *add_row_button2;
    QPushButton *add_col_button2;
    QPushButton *delete_row_button2;
    QPushButton *delete_col_button2;
    QPushButton *determinant_button2;
    QPushButton *transpose_button2;

    //Таблицы для ввода/вывода содержимого матрицы
    QTableWidget *firstTableWidget;
    QTableWidget *secondTableWidget;
    QTableWidget *thridTableWidget;
};
