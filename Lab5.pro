

QT       += core gui opengl

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Lab5Shader
TEMPLATE = app

LIBS += -lGLU
SOURCES += main.cpp\
        mainwindow.cpp \
    glwidget.cpp

HEADERS  += mainwindow.h \
    glwidget.h

FORMS    += mainwindow.ui

RESOURCES += \
    shader.qrc

DISTFILES +=
