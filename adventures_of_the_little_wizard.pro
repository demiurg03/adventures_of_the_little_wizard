TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        main.cpp
unix|win32: LIBS += -L$$PWD adventures_of_the_little_wizard/SFML/lib/ -lsfml-graphics -lsfml-window -lsfml-system

INCLUDEPATH += $$PWD adventures_of_the_little_wizard/SFML/include
DEPENDPATH += $$PWD adventures_of_the_little_wizard/SFML/include
