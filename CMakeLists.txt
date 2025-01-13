cmake_minimum_required(VERSION 3.16)

project(MedicalImageAnalyzer VERSION 1.0 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 REQUIRED COMPONENTS Core Gui Widgets)

set(SOURCES
    main.cpp
    mainwindow.cpp
    imageanalyzer.cpp
)

set(HEADERS
    mainwindow.h
    imageanalyzer.h
)

set(FORMS
    mainwindow.ui
)

qt_add_executable(MedicalImageAnalyzer
    ${SOURCES}
    ${HEADERS}
    ${FORMS}
)

target_link_libraries(MedicalImageAnalyzer PRIVATE Qt6::Core Qt6::Gui Qt6::Widgets)
