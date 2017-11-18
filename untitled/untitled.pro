TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

HEADERS += \
    animate.h \
    planet.h \
    system.h \
    constancts.h

CONFIG += c++11

LIBS += -L"..\..\SFML-2.0/bin"
LIBS += -L"..\..\SFML-2.0/lib"

CONFIG(release, debug|release): LIBS += -lsfml-audio -lsfml-graphics -lsfml-system -lsfml-network -lsfml-window
CONFIG(debug, debug|release): LIBS += -lsfml-audio -lsfml-graphics -lsfml-system -lsfml-network -lsfml-window


INCLUDEPATH += /usr/include/c++/{gcc_version}/
INCLUDEPATH += "..\..\..\SFML-2.0\include"
DEPENDPATH += "..\..\..\SFML-2.0\include"

SOURCES += \
    animate.cpp \
    main.cpp \
    planet.cpp \
    system.cpp

<<<<<<< HEAD
HEADERS += \
    animate.h \
    planet.h \
    system.h \
    constants.h
=======
>>>>>>> 2a6153280ffa0b2b196e9bd7e347b300e6a9bd18
