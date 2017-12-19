TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

HEADERS += \
    animate.h \
    planet.h \
    system.h \
    constancts.h

#CONFIG += c++11

#LIBS += -L"..\..\SFML-2.0/bin"
#LIBS += -L"..\..\SFML-2.0/lib"

#CONFIG(release, debug|release): LIBS += -lsfml-audio -lsfml-graphics -lsfml-system -lsfml-network -lsfml-window
#CONFIG(debug, debug|release): LIBS += -lsfml-audio -lsfml-graphics -lsfml-system -lsfml-network -lsfml-window


#INCLUDEPATH += /usr/include/c++/{gcc_version}/
#INCLUDEPATH += "..\..\..\SFML-2.0\include"
#DEPENDPATH += "..\..\..\SFML-2.0\include"

##----------------SFML for MAC OS-----------------:

CONFIG += c++11


LIBS += -L"/usr/local/lib"

CONFIG(release, debug|release): LIBS += -lsfml-audio -lsfml-graphics -lsfml-system -lsfml-network -lsfml-window
CONFIG(debug, debug|release): LIBS += -lsfml-audio -lsfml-graphics -lsfml-system -lsfml-network -lsfml-window

INCLUDEPATH += "/usr/local/include"
DEPENDPATH += "/usr/local/include"

#------------------END OF SFML FOR MAC OS-----------------------/
SOURCES += \
    animate.cpp \
    main.cpp \
    planet.cpp \
    system.cpp

HEADERS += \
    animate.h \
    planet.h \
    system.h
