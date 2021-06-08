#include "mainwindow.h"
#include "matrix.h"

QString value = "", total = "";
QString instruct = "";
int fNum, sNum;
bool addBool = false, subtractBool = false, multiplyBool = false, determinantBool = false, inverseBool = false;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    //Создание
     //Первая таблица
     firstTableWidget = new QTableWidget(this);
     firstTableWidget->setGeometry(10, 10, 250, 250);
     firstTableWidget->setMaximumSize(250, 250);
     firstTableWidget->setShowGrid(true);
     firstTableWidget->setRowCount(1);
     firstTableWidget->setColumnCount(1);

     //Заполняем пустую ячейку пробелом, что было, во всех остальных, делаем тоже самое
     firstTableWidget->setItem(0, 0, new QTableWidgetItem(" "));
     firstTableWidget->setColumnWidth(0, 50);
     firstTableWidget->setEditTriggers(QAbstractItemView::DoubleClicked);
     firstTableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
     firstTableWidget->setSelectionMode(QAbstractItemView::SingleSelection);

     //Вторая таблица
     secondTableWidget = new QTableWidget(this);
     secondTableWidget->setGeometry(340, 10, 250, 250);
     secondTableWidget->setMaximumSize(250, 250);
     secondTableWidget->setShowGrid(true);
     secondTableWidget->setRowCount(1);
     secondTableWidget->setColumnCount(1);
     secondTableWidget->setItem(0, 0, new QTableWidgetItem(" "));
     secondTableWidget->setColumnWidth(0,50);
     secondTableWidget->setEditTriggers(QAbstractItemView::DoubleClicked);
     secondTableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
     secondTableWidget->setSelectionMode(QAbstractItemView::SingleSelection);

     //Результативная - третья таблица
     thridTableWidget = new QTableWidget(this);
     thridTableWidget->setGeometry(800, 10, 250, 250);
     thridTableWidget->setMaximumSize(250, 250);
     thridTableWidget->setShowGrid(true);
     thridTableWidget->setRowCount(1);
     thridTableWidget->setColumnCount(1);
     thridTableWidget->setItem(0, 0, new QTableWidgetItem(" "));
     thridTableWidget->item(0,0)->setTextAlignment(Qt::AlignCenter);
     thridTableWidget->setColumnWidth(0,50);


     //Установка и заполнение текста
     label = new QLabel(" ", this);
     label->setStyleSheet("QLabel { font-size : 40px; }");
     label->setGeometry(QRect(QPoint(280,100), QSize(50, 50)));

     det1Label = new QLabel(" ", this);
     det1Label->setMidLineWidth(3);
     det1Label->setFrameStyle(QFrame::Box);
     det1Label->setStyleSheet("QLabel { background-color : white; }");
     det1Label->setGeometry(QRect(QPoint(30, 420), QSize(200, 50)));

     det2Label = new QLabel(" ", this);
     det2Label->setMidLineWidth(3);
     det2Label->setFrameStyle(QFrame::Box);
     det2Label->setStyleSheet("QLabel { background-color : white; }");
     det2Label->setGeometry(QRect(QPoint(360, 420), QSize(200, 50)));


     //Кнопки
     //Сперва для обеих матриц
     add_button = new QPushButton("+", this);
     add_button->setGeometry(QRect(QPoint(670,30), QSize(50,50)));
     connect(add_button, SIGNAL(released()), this, SLOT(add_m()));

     subtract_button = new QPushButton("-", this);
     subtract_button->setGeometry(QRect(QPoint(670,80), QSize(50,50)));
     connect(subtract_button, SIGNAL(released()), this, SLOT(subtract_m()));

     multiply_button = new QPushButton("x", this);
     multiply_button->setGeometry(QRect(QPoint(670,130), QSize(50,50)));
     connect(multiply_button, SIGNAL(released()), this, SLOT(multiply_m()));

     scalar_mult_button = new QPushButton("x число", this);
     scalar_mult_button->setGeometry(QRect(QPoint(670,180), QSize(50,50)));
     connect(scalar_mult_button, SIGNAL(released()), this, SLOT(scalar_mult()));

     //Кнопочки ТОЛЬКО для первой
     add_row_button = new QPushButton("+ Строка", this);
     add_row_button->setGeometry(QRect(QPoint(30, 270), QSize(100,50)));
     connect(add_row_button, SIGNAL(released()), this, SLOT(rowAdd_1()));

     add_col_button = new QPushButton("+ Столбец", this);
     add_col_button->setGeometry(QRect(QPoint(130, 270), QSize(100,50)));
     connect(add_col_button, SIGNAL(released()), this, SLOT(colAdd_1()));

     delete_row_button = new QPushButton("- Строка", this);
     delete_row_button->setGeometry(QRect(QPoint(30, 320), QSize(100,50)));
     connect(delete_row_button, SIGNAL(released()), this, SLOT(rowDelete_1()));

     delete_col_button = new QPushButton("- Столбец", this);
     delete_col_button->setGeometry(QRect(QPoint(130, 320), QSize(100,50)));
     connect(delete_col_button, SIGNAL(released()), this, SLOT(colDelete_1()));

     determinant_button = new QPushButton("Определитель", this);
     determinant_button->setGeometry(QRect(QPoint(30, 370), QSize(100,50)));
     connect(determinant_button, SIGNAL(released()), this, SLOT(determinant_1()));

     transpose_button = new QPushButton("Транспонир.", this);
     transpose_button->setGeometry(QRect(QPoint(130, 370), QSize(100,50)));
     connect(transpose_button, SIGNAL(released()), this, SLOT(transpose_1()));


     //Кнопочки ТОЛЬКО для второй
     add_row_button2 = new QPushButton("+ Строка", this);
     add_row_button2->setGeometry(QRect(QPoint(360, 270), QSize(100,50)));
     connect(add_row_button2, SIGNAL(released()), this, SLOT(rowAdd_2()));

     add_col_button2 = new QPushButton("+ Столбец", this);
     add_col_button2->setGeometry(QRect(QPoint(460, 270), QSize(100,50)));
     connect(add_col_button2, SIGNAL(released()), this, SLOT(colAdd_2()));

     delete_row_button2 = new QPushButton("- Строка", this);
     delete_row_button2->setGeometry(QRect(QPoint(360, 320), QSize(100,50)));
     connect(delete_row_button2, SIGNAL(released()), this, SLOT(rowDelete_2()));

     delete_col_button2 = new QPushButton("- Колонка", this);
     delete_col_button2->setGeometry(QRect(QPoint(460, 320), QSize(100,50)));
     connect(delete_col_button2, SIGNAL(released()), this, SLOT(colDelete_2()));

     determinant_button2 = new QPushButton("Определитель", this);
     determinant_button2->setGeometry(QRect(QPoint(360, 370), QSize(100,50)));
     connect(determinant_button2, SIGNAL(released()), this, SLOT(determinant_2()));

     transpose_button2 = new QPushButton("Транспонир.", this);
     transpose_button2->setGeometry(QRect(QPoint(460, 370), QSize(100,50)));
     connect(transpose_button2, SIGNAL(released()), this, SLOT(transpose_2()));
}

//Основная логика
//СЛОЖЕНИЕ
void MainWindow::add_m() {
     label->setText(tr("+"));

     //Таблицы автоматически подстраиваются под размер друг друга
     if ((secondTableWidget->columnCount() != firstTableWidget->columnCount()) || (secondTableWidget->rowCount() != firstTableWidget->rowCount())) {
         //колонки и ряды установятся одинаковые с дефолтным значением - 0
         secondTableWidget->setColumnCount(firstTableWidget->columnCount());
         secondTableWidget->setRowCount(firstTableWidget->rowCount());
         secondTableWidget->setColumnWidth(secondTableWidget->columnCount()-1, 50);

         for(int i = 0; i < secondTableWidget->rowCount(); i++)
         {
             for(int k = 0; k < secondTableWidget->columnCount(); k++)
             {
                 secondTableWidget->setItem(i, k, new QTableWidgetItem(" "));
                 secondTableWidget->setColumnWidth(k, 50);
             }
         }
     }

     //Размер третьей так же смотрится по размеру исходных
     if((thridTableWidget->columnCount() != firstTableWidget->columnCount()) || (thridTableWidget->rowCount() != firstTableWidget->rowCount())) {
         thridTableWidget->setColumnCount(firstTableWidget->columnCount());
         thridTableWidget->setRowCount(firstTableWidget->rowCount());

         thridTableWidget->setColumnWidth(thridTableWidget->columnCount()-1, 50);

         for(int i = 0; i < thridTableWidget->rowCount(); i++)
         {
             for(int k = 0; k < thridTableWidget->columnCount(); k++)
             {
                 thridTableWidget->setItem(i, k, new QTableWidgetItem(" "));
                 thridTableWidget->setColumnWidth(k, 50);
             }
         }
     }

     //Передаем размеры первой таблицы - первой матриц
     m1.setSize(firstTableWidget->rowCount(), firstTableWidget->columnCount());
     //Передаем размеры второй таблицы - второй матрицу
     m2.setSize(secondTableWidget->rowCount(), secondTableWidget->columnCount());

     //И передаем значения
     for (int i = 0; i < firstTableWidget->rowCount(); i++) {
         for (int k = 0; k < firstTableWidget->columnCount(); k++) {
             QString s = firstTableWidget->item(i, k)->text();
             float value = s.toFloat();
             m1.setValue(i, k, value);
         }
     }

     //Аналогично первой, вытасикиваем со второй таблицы значения и заносим во вторую матрицу
     for (int i = 0; i < secondTableWidget->rowCount(); i++) {
         for(int k = 0; k < secondTableWidget->columnCount(); k++) {
             QString s = secondTableWidget->item(i, k)->text();
             float value = s.toFloat();
             m2.setValue(i, k, value);
         }
     }

     //Размеры третьей матрицы
     m3.setSize(thridTableWidget->rowCount(), thridTableWidget->columnCount());

     //ОСНОВНОЕ ДЕЙСТВИЕ СЛОЖЕНИЕ!
     m3 = m1.add(m2);

     //Пока матрица и таблица третьи равны, выведем полученный результат в таблице третьей
     if ((m3.getRows() == thridTableWidget->rowCount()) && (m3.getCols() == thridTableWidget->columnCount())) {
         for (int rows = 0; rows < m3.getRows(); rows++) {
             for (int cols = 0; cols < m3.getCols(); cols++) {
                 float value = m3.getValue(rows, cols);
                 QString b = QString::number(value);
                 thridTableWidget->item(rows, cols)->setText(b);
             }
         }
     }
}

//ВЫЧИТАНИЕ
void MainWindow::subtract_m() {

    label->setText("-");

    //ВНИМАНИЕ! КАК И В СЛОЖЕНИЕ УСТАНАВЛИВАЮТСЯ РАЗМЕРЫ ВСЕХ ТРЕХ ТАБЛИЦ, А ЗАТЕМ И МАТРИЦ
    if ((secondTableWidget->columnCount() != firstTableWidget->columnCount()) || (secondTableWidget->rowCount() != firstTableWidget->rowCount())) {
        secondTableWidget->setColumnCount(firstTableWidget->columnCount());
        secondTableWidget->setRowCount(firstTableWidget->rowCount());
        secondTableWidget->setColumnWidth(secondTableWidget->columnCount()-1, 50);

        for (int i = 0; i < secondTableWidget->rowCount(); i++) {
            for (int k = 0; k < secondTableWidget->columnCount(); k++) {
                secondTableWidget->setItem(i, k, new QTableWidgetItem(" "));
                secondTableWidget->setColumnWidth(k, 50);
            }
        }
    }

    if ((thridTableWidget->columnCount() != firstTableWidget->columnCount()) || (thridTableWidget->rowCount() != firstTableWidget->rowCount())) {
        thridTableWidget->setColumnCount(firstTableWidget->columnCount());
        thridTableWidget->setRowCount(firstTableWidget->rowCount());

        thridTableWidget->setColumnWidth(thridTableWidget->columnCount()-1, 50);

        for (int i = 0; i < thridTableWidget->rowCount(); i++) {
            for (int k = 0; k < thridTableWidget->columnCount(); k++) {
                thridTableWidget->setItem(i, k, new QTableWidgetItem(" "));
                thridTableWidget->setColumnWidth(k, 50);
            }
        }
    }

    //Перебрасываем значения из таблиц в матрицы
    m1.setSize(firstTableWidget->rowCount(), firstTableWidget->columnCount());
    m2.setSize(secondTableWidget->rowCount(), secondTableWidget->columnCount());
    for (int i = 0; i < firstTableWidget->rowCount(); i++) {
        for (int k = 0; k < firstTableWidget->columnCount(); k++) {
            QString s = firstTableWidget->item(i, k)->text();
            float value = s.toFloat();
            m1.setValue(i, k, value);
        }
    }

    for (int i = 0; i < secondTableWidget->rowCount(); i++) {
        for (int k = 0; k < secondTableWidget->columnCount(); k++) {
            QString s = secondTableWidget->item(i, k)->text();
            float value = s.toFloat();
            m2.setValue(i, k, value);
        }
    }

    m3.setSize(thridTableWidget->rowCount(), thridTableWidget->columnCount());
    m3 = m1.subs(m2);

    if ((m3.getRows() == thridTableWidget->rowCount()) && (m3.getCols() == thridTableWidget->columnCount())) {
        for (int rows = 0; rows < m3.getRows(); rows++) {
            for (int cols = 0; cols < m3.getCols(); cols++) {
                float value = m3.getValue(rows, cols);
                QString b = QString::number(value);
                thridTableWidget->item(rows, cols)->setText(b);
            }
        }
    }
}

//УМНОЖЕНИЕ МАТРИЦ
void MainWindow::multiply_m() {
    label->setText("x");

    //Проверка, ведь просто так не умножить матрицы должны подходить для умножения друг на друга
    //т.е. число колонок первой должно равнять числу строк второй
    //если не подходят, то мы искуственно добавляем
    if ((firstTableWidget->columnCount() != secondTableWidget->rowCount())) {
        secondTableWidget->setRowCount(firstTableWidget->columnCount());
        secondTableWidget->setColumnWidth(secondTableWidget->columnCount()-1, 50);

        for (int i = 0; i < secondTableWidget->rowCount(); i++) {
            for (int k = 0; k < secondTableWidget->columnCount(); k++)
            {
                secondTableWidget->setItem(i, k, new QTableWidgetItem(" "));
                secondTableWidget->setColumnWidth(k, 50);
            }
        }
    }

    //Собираем третью таблицу
    if ((thridTableWidget->rowCount() != firstTableWidget->rowCount()) || (thridTableWidget->columnCount() != secondTableWidget->columnCount())) {
        thridTableWidget->setRowCount(firstTableWidget->rowCount());
        thridTableWidget->setColumnCount(secondTableWidget->columnCount());
        thridTableWidget->setColumnWidth(secondTableWidget->columnCount()-1, 50);

        for(int i = 0; i < thridTableWidget->rowCount(); i++)
        {
            for(int k = 0; k < thridTableWidget->columnCount(); k++)
            {
                thridTableWidget->setItem(i, k, new QTableWidgetItem(" "));
                thridTableWidget->setColumnWidth(k, 50);
            }
        }
    }

    //Инициализируем матрицы по таблицам
    m1.setSize(firstTableWidget->rowCount(), firstTableWidget->columnCount());
    m2.setSize(secondTableWidget->rowCount(), secondTableWidget->columnCount());

    for (int i = 0; i < firstTableWidget->rowCount(); i++) {
        for (int k = 0; k < firstTableWidget->columnCount(); k++) {
            QString s = firstTableWidget->item(i, k)->text();
            float value = s.toFloat();
            m1.setValue(i, k, value);
        }
    }

    for (int i = 0; i < secondTableWidget->rowCount(); i++) {
        for (int k = 0; k < secondTableWidget->columnCount(); k++) {
            QString s = secondTableWidget->item(i, k)->text();
            float value = s.toFloat();
            m2.setValue(i, k, value);
        }
    }

    m3.setSize(thridTableWidget->rowCount(), thridTableWidget->columnCount());

    //ГЛАВНОЕ ДЕЙСТВИЕ - УМНОЖЕНИЕ!
    m3 = m1.multiply(m2);

    for (int rows = 0; rows < m3.getRows(); rows++) {
        for (int cols = 0; cols < m3.getCols(); cols++) {
            float value = m3.getValue(rows, cols);
            QString b = QString::number(value);
            thridTableWidget->item(rows, cols)->setText(b);
        }
    }
}

//СКАЛЯРНОЕ ПРОИЗВЕДЕНИЕ (умножение на число)
void MainWindow::scalar_mult() {
    label->setText("x число");

    //Вторую матрицу устанавливаем в размерность 1х1, чтоб было только одно число
    if ((secondTableWidget->columnCount() != 1) || (secondTableWidget->rowCount() != 1)) {
        secondTableWidget->setColumnCount(1);
        secondTableWidget->setRowCount(1);
        secondTableWidget->setItem(0, 0, new QTableWidgetItem(" "));
        secondTableWidget->setColumnWidth(0, 50);
    }

    //Собираем третью таблицу
    if ((thridTableWidget->columnCount() != firstTableWidget->columnCount()) || (thridTableWidget->rowCount() != firstTableWidget->rowCount())) {
        thridTableWidget->setColumnCount(firstTableWidget->columnCount());
        thridTableWidget->setRowCount(firstTableWidget->rowCount());

        thridTableWidget->setColumnWidth(thridTableWidget->columnCount()-1, 50);

        for (int i = 0; i < thridTableWidget->rowCount(); i++) {
            for (int k = 0; k < thridTableWidget->columnCount(); k++) {
                thridTableWidget->setItem(i, k, new QTableWidgetItem(" "));
                thridTableWidget->setColumnWidth(k, 50);
            }
        }
    }

    //Заполняем первую матрицу по таблице первой
    m1.setSize(firstTableWidget->rowCount(), firstTableWidget->columnCount());

    for (int i = 0; i < firstTableWidget->rowCount(); i++) {
        for (int k = 0; k < firstTableWidget->columnCount(); k++) {
            QString s = firstTableWidget->item(i, k)->text();
            float value = s.toFloat();
            m1.setValue(i, k, value);
        }
    }

    //Получем число и перевод его в тип флоат
    QString s = secondTableWidget->item(0, 0)->text();
    float value = s.toFloat();

    m3.setSize(thridTableWidget->rowCount(), thridTableWidget->columnCount());

    //Главное действие!! УМНОЖАЕМ НА ЧИСЛО
    m3 = m1.multiply(value);

    //Выводим в третью таблицу че получилось
    if ((m3.getRows() == thridTableWidget->rowCount()) && (m3.getCols() == thridTableWidget->columnCount())) {
        for (int rows = 0; rows < m3.getRows(); rows++) {
            for (int cols = 0; cols < m3.getCols(); cols++) {
                float value = m3.getValue(rows, cols);
                QString b = QString::number(value);
                thridTableWidget->item(rows, cols)->setText(b);
            }
        }
    }
}


//Методы ТОЛЬКО для ПЕРВОЙ матрицы
//добавляем строку
void MainWindow::rowAdd_1() {
    firstTableWidget->setRowCount(firstTableWidget->rowCount()+1);
    int row = firstTableWidget->rowCount();

    for (int i = 0; i < firstTableWidget->columnCount(); i++) {
        firstTableWidget->setItem((row-1), i, new QTableWidgetItem(" "));
    }

    m1.setSize(firstTableWidget->rowCount(), firstTableWidget->columnCount());
}

//добавляем колонку
void MainWindow::colAdd_1() {
    firstTableWidget->setColumnCount(firstTableWidget->columnCount()+1);
    int col = firstTableWidget->columnCount();

    for (int i = 0; i < firstTableWidget->rowCount(); i++) {
        firstTableWidget->setItem(i, (col-1), new QTableWidgetItem(" "));
    }

    firstTableWidget->setColumnWidth((col-1), 50);
    m1.setSize(firstTableWidget->rowCount(), firstTableWidget->columnCount());
}

//удаляем строчку
void MainWindow::rowDelete_1() {
    firstTableWidget->removeRow(firstTableWidget->rowCount()-1);
    m1.setSize(firstTableWidget->rowCount(), firstTableWidget->columnCount());
}

//удаляем столбец
void MainWindow::colDelete_1() {
    firstTableWidget->removeColumn(firstTableWidget->columnCount()-1);
    m1.setSize(firstTableWidget->rowCount(), firstTableWidget->columnCount());
}

//определяем определитель!
void MainWindow::determinant_1() {
    if (firstTableWidget->rowCount() == firstTableWidget->columnCount()) {
        if (firstTableWidget->rowCount() > 1) {

            m1.setSize(firstTableWidget->rowCount(), firstTableWidget->columnCount());

            for (int i = 0; i < firstTableWidget->rowCount(); i++) {
                for (int k = 0; k < firstTableWidget->columnCount(); k++) {
                    QString s = firstTableWidget->item(i, k)->text();
                    float value = s.toFloat();
                    m1.setValue(i, k, value);
                }
            }

            float ans = m1.determinant();
            QString b = QString::number(ans);
            det1Label->setText(b);
            det1Label->setAlignment(Qt::AlignCenter);
        }
    }

    else {
        //Ошибка если матрица НЕ КВАДРАТНАЯ
        QMessageBox::critical(this, "Ошибка", "Матрица НЕ КВАДРАТНАЯ!");
    }
}

//транспонируем
void MainWindow::transpose_1() {
    if (firstTableWidget->columnCount() == firstTableWidget->rowCount()) {
        m1.setSize(firstTableWidget->rowCount(), firstTableWidget->columnCount());

        for (int i = 0; i < firstTableWidget->rowCount(); i++) {
            for(int k = 0; k < firstTableWidget->columnCount(); k++) {
                QString s = firstTableWidget->item(i, k)->text();
                float value = s.toFloat();
                m1.setValue(i, k, value);
            }
        }

        matrix temp(firstTableWidget->rowCount(), firstTableWidget->columnCount());
        temp = m1.transpose();

       if ((temp.getRows() == firstTableWidget->rowCount()) && (temp.getCols() == firstTableWidget->columnCount())) {
           for (int rows = 0; rows < temp.getRows(); rows++) {
               for (int cols = 0; cols < temp.getCols(); cols++) {
                   float value = temp.getValue(rows, cols);
                   QString b = QString::number(value);
                   firstTableWidget->item(rows, cols)->setText(b);
               }
           }
       }
    }

    else {
        //Ошибка если матрица НЕ КВАДРАТНАЯ
        QMessageBox::critical(this, "Ошибка", "Матрица НЕ КВАДРАТНАЯ!");
    }
}

//Методы ТОЛЬКО для ВТОРОЙ матрицы
//добавление строки
void MainWindow::rowAdd_2() {
    secondTableWidget->setRowCount(secondTableWidget->rowCount()+1);
    int row = secondTableWidget->rowCount();

    for(int i = 0; i < secondTableWidget->columnCount(); i++) {
        secondTableWidget->setItem((row-1), i, new QTableWidgetItem(" "));
    }
    m2.setSize(secondTableWidget->rowCount(), secondTableWidget->columnCount());
}

//добавление столбца
void MainWindow::colAdd_2() {
    secondTableWidget->setColumnCount(secondTableWidget->columnCount()+1);
    int col = secondTableWidget->columnCount();

    for(int i = 0; i < secondTableWidget->rowCount(); i++) {
        secondTableWidget->setItem(i, (col-1), new QTableWidgetItem(" "));
    }
    secondTableWidget->setColumnWidth((col-1), 50);
    m2.setSize(secondTableWidget->rowCount(), secondTableWidget->columnCount());
}

//удаление строки и ряда
void MainWindow::rowDelete_2() {
    secondTableWidget->removeRow(secondTableWidget->rowCount()-1);
    m2.setSize(secondTableWidget->rowCount(), secondTableWidget->columnCount());
}

void MainWindow::colDelete_2() {
    secondTableWidget->removeColumn(secondTableWidget->columnCount()-1);
    m2.setSize(secondTableWidget->rowCount(), secondTableWidget->columnCount());
}

//Подсчет определителя
void MainWindow::determinant_2() {
    if (secondTableWidget->rowCount() == secondTableWidget->columnCount()) {
        if (secondTableWidget->rowCount() > 1) {

            m2.setSize(secondTableWidget->rowCount(), secondTableWidget->columnCount());

            for (int i = 0; i < secondTableWidget->rowCount(); i++) {
                for (int k = 0; k < secondTableWidget->columnCount(); k++) {
                    QString s = secondTableWidget->item(i, k)->text();
                    float value = s.toFloat();
                    m2.setValue(i, k, value);
                }
            }

            float ans = m2.determinant();
            QString b = QString::number(ans);
            det2Label->setText(b);
            det2Label->setAlignment(Qt::AlignCenter);
        }
    } else {
        //Ошибка если матрица НЕ КВАДРАТНАЯ
        QMessageBox::critical(this, "Ошибка", "Матрица НЕ КВАДРАТНАЯ!");
    }
}

//транспонируем
void MainWindow::transpose_2() {
    if (secondTableWidget->columnCount() == secondTableWidget->rowCount()) {
        m2.setSize(secondTableWidget->rowCount(), secondTableWidget->columnCount());

        for (int i = 0; i < secondTableWidget->rowCount(); i++) {
            for (int k = 0; k < secondTableWidget->columnCount(); k++) {
                QString s = secondTableWidget->item(i, k)->text();
                float value = s.toFloat();
                m2.setValue(i, k, value);
            }
        }

        m3.setSize(secondTableWidget->rowCount(), secondTableWidget->columnCount());
        m3 = m2.transpose();

       if ((m3.getRows() == secondTableWidget->rowCount()) && (m3.getCols() == secondTableWidget->columnCount())) {
           for (int rows = 0; rows < m3.getRows(); rows++) {
               for (int cols = 0; cols < m3.getCols(); cols++) {
                   float value = m3.getValue(rows, cols);
                   QString b = QString::number(value);
                   secondTableWidget->item(rows, cols)->setText(b);
               }
           }
       }
    }

    else {
        //Ошибка если матрица НЕ КВАДРАТНАЯ
        QMessageBox::critical(this, "Ошибка", "Матрица НЕ КВАДРАТНАЯ!");
    }
}

//Деструктор класса
//Так, по приколу написал
// Но вообще важная штука!
MainWindow::~MainWindow() { }
