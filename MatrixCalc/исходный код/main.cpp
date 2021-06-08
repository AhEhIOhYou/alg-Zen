#include "mainwindow.h"
#include <QtWidgets>

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    MainWindow w;
    w.setFixedSize(1100, 500);
    w.setWindowTitle("Матричный калькулятор");
    w.show();
    return a.exec();
}
