QT += gui core

CONFIG += c++11

TARGET = NoiseTexture
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

INCLUDEPATH += $$PWD/../glm/glm

SOURCES += main.cpp \
    NoiseTexture.cpp \
    perlin.cpp \
    vertex.cpp \
    vertexcol.cpp \
    vertextex.cpp \
    vbocube.cpp

HEADERS += \
    NoiseTexture.h \
    perlin.h \
    vertex.h \
    vertexcol.h \
    vertextex.h \
    vbocube.h

OTHER_FILES += \
    fshader.txt \
    vshader.txt

RESOURCES += \
    shaders.qrc

DISTFILES += \
    fshader.txt \
    vshader.txt
