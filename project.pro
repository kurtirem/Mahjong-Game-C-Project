QT += quick
CONFIG += c++17 console
CONFIG -= app_bundle

TEMPLATE = app
TARGET = mahjong

SOURCES += \
    src/main.cpp 

HEADERS += \
    src/tile.hpp \
    src/tilemodel.hpp \
    src/board.hpp


RESOURCES += src/resources/resources.qrc


QML_FILES += \
    src/qml/main.qml

DISTFILES += src/qml/main.qml

QT += multimedia

