QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    Contents/homecontent.cpp \
    Contents/newcontent.cpp \
    Contents/opencontent.cpp \
    StartWindow/Buttons/resizebutton.cpp \
    StartWindow/Buttons/windowbutton.cpp \
    StartWindow/mainwidget.cpp \
    StartWindow/menu.cpp \
    StartWindow/startwindow.cpp \
    StartWindow/titlebar.cpp \
    main.cpp \

HEADERS += \
    Contents/homecontent.h \
    Contents/newcontent.h \
    Contents/opencontent.h \
    StartWindow/Buttons/resizebutton.h \
    StartWindow/Buttons/windowbutton.h \
    StartWindow/mainwidget.h \
    StartWindow/menu.h \
    StartWindow/startwindow.h \
    StartWindow/titlebar.h \

FORMS += \
    StartWindow/startwindow.ui \

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    Resources/Icons/Icons.qrc \

DISTFILES +=
