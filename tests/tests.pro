TEMPLATE = app
CONFIG += c++17 console testcase
CONFIG -= app_bundle    # Add this line

QT += testlib multimedia

TARGET = tests

HEADERS += \
    ../src/board.hpp \
    ../src/tile.hpp \
    ../src/tilemodel.hpp \
    test_board.hpp \
    test_tile.hpp

SOURCES += \
    main.cpp \
    test_board.cpp \
    test_tile.cpp \
    ../src/board.cpp \
    ../src/tile.cpp \
    ../src/tilemodel.cpp

INCLUDEPATH += ../src
