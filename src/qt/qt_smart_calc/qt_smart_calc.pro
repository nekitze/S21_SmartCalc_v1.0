QT       += core gui printsupport

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    ../../calc_functions/calculations.c \
    ../../calc_functions/init.c \
    ../../calc_functions/parser.c \
    ../../calc_functions/stack.c \
    credit_window.cpp \
    graph_window.cpp \
    main.cpp \
    mainwindow.cpp \
    qcustomplot.cpp

HEADERS += \
    ../../calc_functions/calc.h \
    credit_window.h \
    graph_window.h \
    mainwindow.h \
    qcustomplot.h

FORMS += \
    credit_window.ui \
    graph_window.ui \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
