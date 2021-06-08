QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = MatrixCalculator
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    matrix.cpp

HEADERS  += mainwindow.h \
    matrix.h

win32 {
        RC_FILE += file.rc
        OTHER_FILES += file.rc
}
