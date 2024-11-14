QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    Scripts/DocumentWindow/Tabs/hometab.cpp \
    Scripts/DocumentWindow/Tabs/tab.cpp \
    Scripts/DocumentWindow/documentwindow.cpp \
    Scripts/DocumentWindow/edittitlebar.cpp \
    Scripts/DocumentWindow/ribbon.cpp \
    Scripts/DocumentWindow/workspace.cpp \
    Scripts/StartWindow/Contents/homecontent.cpp \
    Scripts/StartWindow/Contents/newcontent.cpp \
    Scripts/StartWindow/Contents/opencontent.cpp \
    Scripts/StartWindow/Contents/template.cpp \
    Scripts/StartWindow/mainwidget.cpp \
    Scripts/StartWindow/menu.cpp \
    Scripts/StartWindow/startwindow.cpp \
    Scripts/WindowButtons/resizebutton.cpp \
    Scripts/WindowButtons/windowbutton.cpp \
    Scripts/basewindow.cpp \
    Scripts/main.cpp \
    Scripts/titlebar.cpp \
    Scripts/usersettings.cpp

HEADERS += \
    Scripts/DocumentWindow/Tabs/hometab.h \
    Scripts/DocumentWindow/Tabs/tab.h \
    Scripts/DocumentWindow/documentwindow.h \
    Scripts/DocumentWindow/edittitlebar.h \
    Scripts/DocumentWindow/ribbon.h \
    Scripts/DocumentWindow/workspace.h \
    Scripts/StartWindow/Contents/homecontent.h \
    Scripts/StartWindow/Contents/newcontent.h \
    Scripts/StartWindow/Contents/opencontent.h \
    Scripts/StartWindow/Contents/template.h \
    Scripts/StartWindow/mainwidget.h \
    Scripts/StartWindow/menu.h \
    Scripts/StartWindow/startwindow.h \
    Scripts/WindowButtons/resizebutton.h \
    Scripts/WindowButtons/windowbutton.h \
    Scripts/basewindow.h \
    Scripts/titlebar.h \
    Scripts/usersettings.h

FORMS += \
    Scripts/StartWindow/startwindow.ui \

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    Resources/Icons/Icons.qrc

DISTFILES +=
