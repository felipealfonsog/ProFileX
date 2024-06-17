TEMPLATE = app
TARGET = proFileX
INCLUDEPATH += include
QT += core gui widgets

SOURCES += src/main.cpp \
           src/file_operations.cpp

HEADERS += include/main.h \
           include/file_operations.h

FORMS += ui/mainwindow.ui
