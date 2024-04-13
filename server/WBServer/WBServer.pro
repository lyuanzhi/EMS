QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets network

INCLUDEPATH += "C:\Program Files\MySQL\MySQL Server 8.0\include"
LIBS += -L"C:/Program Files/MySQL/MySQL Server 8.0/lib"
LIBS += -llibmysql

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    database.cpp \
    main.cpp \
    tcpconnect.cpp

HEADERS += \
    database.h \
    structure.h \
    tcpconnect.h

FORMS += \
    tcpconnect.ui

TRANSLATIONS += \
    WBServer_en_US.ts
CONFIG += lrelease
CONFIG += embed_translations

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
