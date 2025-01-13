# MedicalImageAnalyzer.pro

QT += core gui widgets      

TARGET = MedicalImageAnalyzer
TEMPLATE = app

SOURCES += \
    imageanalyzer.cpp \
    main.cpp \
    mainwindow.cpp

HEADERS += \
    imageanalyzer.h \
    mainwindow.h

FORMS += \
    mainwindow.ui

QMAKE_CXXFLAGS += -std=c++17
