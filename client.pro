QT       += core gui
QT       += network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17
QT += network
QT += widgets

msvc
{
    QMAKE_CFLAGS += /utf-8
    QMAKE_CXXFLAGS += /utf-8
}

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    ../shared/shared.cpp \
    chatwidget.cpp \
    chatwidgets.cpp \
    client.cpp \
    groupboxwidget.cpp \
    groupchatwidget.cpp \
    groupmemberlist.cpp \
    loginwidget.cpp \
    main.cpp \
    mainwindow.cpp \
    memberboxwidget.cpp \
    registerwidget.cpp \
    userboxwidget.cpp \
    userlistwidget.cpp

HEADERS += \
    ../shared/shared.h \
    chatwidget.h \
    chatwidgets.h \
    client.h \
    groupboxwidget.h \
    groupchatwidget.h \
    groupmemberlist.h \
    loginwidget.h \
    mainwindow.h \
    memberboxwidget.h \
    registerwidget.h \
    userboxwidget.h \
    userlistwidget.h

FORMS += \
    chatwidget.ui \
    groupboxwidget.ui \
    groupchatwidget.ui \
    loginwidget.ui \
    mainwindow.ui \
    memberboxwidget.ui \
    registerwidget.ui \
    userboxwidget.ui \
    userlistwidget.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    ../shared/icon/down.svg \
    ../shared/icon/ranger.jpg \
    ../shared/icon/right.svg

RESOURCES += \
    ../ranger.qrc
