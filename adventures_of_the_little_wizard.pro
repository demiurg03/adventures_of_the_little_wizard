TEMPLATE = app
CONFIG +=  c++17
CONFIG -= app_bundle qt

SOURCES += \
        main.cpp








#config
CONFIG(release, debug|release) {
  DEFINES+=SYS_GAME_RELEASE
    message(type release)
}
CONFIG(debug, debug|release) {
  DEFINES+=SYS_GAME_DEBUG
  message(type debug)
  CONFIG+=console
}

!contains(QMAKE_TARGET.arch, x86_64) {

DEFINES+=SYS_GAME_X32
message(arch x32)

}else{
DEFINES+=SYS_GAME_X64
message(arch x64)

}


contains(DEFINES,SYS_GAME_X32){


contains(DEFINES,SYS_GAME_DEBUG){
win32: LIBS += -L$$PWD/SFML/SFML-2.5.1_x32/lib/ -lsfml-graphics-d -lsfml-window-d -lsfml-system-d

INCLUDEPATH += $$PWD/SFML/SFML-2.5.1_x32/include
DEPENDPATH += $$PWD/SFML/SFML-2.5.1_x32/include
}


contains(DEFINES,SYS_GAME_RELEASE){
win32: LIBS += -L$$PWD/SFML/SFML-2.5.1_x32/lib/ -lsfml-graphics -lsfml-window -lsfml-system

INCLUDEPATH += $$PWD/SFML/SFML-2.5.1_x32/include
DEPENDPATH += $$PWD/SFML/SFML-2.5.1_x32/include
}


}


contains(DEFINES,SYS_GAME_X64){


contains(DEFINES,SYS_GAME_DEBUG){
win32: LIBS += -L$$PWD/SFML/SFML-2.5.1_x64/lib/ -lsfml-graphics-d -lsfml-window-d -lsfml-system-d

INCLUDEPATH += $$PWD/SFML/SFML-2.5.1_x64/include
DEPENDPATH += $$PWD/SFML/SFML-2.5.1_x64/include
}


contains(DEFINES,SYS_GAME_RELEASE){
win32: LIBS += -L$$PWD/SFML/SFML-2.5.1_x64/lib/ -lsfml-graphics -lsfml-window -lsfml-system

INCLUDEPATH += $$PWD/SFML/SFML-2.5.1_x64/include
DEPENDPATH += $$PWD/SFML/SFML-2.5.1_x64/include
}


}
