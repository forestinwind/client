QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17
QT += network


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
    loginwidget.cpp \
    main.cpp \
    mainwindow.cpp \
    userboxwidget.cpp \
    userlistwidget.cpp

HEADERS += \
    ../shared/shared.h \
    chatwidget.h \
    chatwidgets.h \
    client.h \
    loginwidget.h \
    mainwindow.h \
    userboxwidget.h \
    userlistwidget.h

FORMS += \
    chatwidget.ui \
    chatwidgets.ui \
    loginwidget.ui \
    mainwindow.ui \
    userboxwidget.ui \
    userlistwidget.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES +=
