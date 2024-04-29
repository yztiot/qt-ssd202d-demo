QT += quick network core serialport widgets concurrent serialbus gui virtualkeyboard quickwidgets multimedia

#CONFIG += C++11
CONFIG += link_pkgconfig

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
        bluetooth.cpp \
        folder.cpp \
        gpio.cpp \
        i2c.cpp \
        internetsetting.cpp \
        main.cpp \
        serialfunction.cpp \
        serialthread.cpp \
        sound.cpp \
        systemsetting.cpp \
        wifi.cpp \
        wifithread.cpp

RESOURCES += qml.qrc

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Additional import path used to resolve QML modules just for Qt Quick Designer
QML_DESIGNER_IMPORT_PATH =

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

QTPLUGIN += qlinuxfb
static {
    QT += svg
    QTPLUGIN += qtvirtualkeyboardplugin
}

#QT_PLUGIN_PATH += /home/h/Qt/5.15.2/gcc_64/qml/QtQuick.2


HEADERS += \
    bluetooth.h \
    folder.h \
    gpio.h \
    i2c.h \
    include/audio.h \
    include/mi_ao.h \
    include/mi_common.h \
    include/mi_sys.h \
    internetsetting.h \
    serialfunction.h \
    serialthread.h \
    sound.h \
    systemsetting.h \
    wifi.h \
    wifithread.h

unix:!macx: LIBS += -L$$PWD/lib/ -lwifi

INCLUDEPATH += $$PWD/include
DEPENDPATH += $$PWD/include

unix:!macx: PRE_TARGETDEPS += $$PWD/lib/libwifi.a


unix:!macx: LIBS += -L$$PWD/lib/ -lcjson

INCLUDEPATH += $$PWD/include
DEPENDPATH += $$PWD/include

unix:!macx: LIBS += -L$$PWD/lib/ -lmi_wlan

INCLUDEPATH += $$PWD/include
DEPENDPATH += $$PWD/include

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/lib/release/ -laudio -lmi_sys -lmi_ao -lmad -lmi_common
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/lib/debug/ -laudio -lmi_sys -lmi_ao -lmad -lmi_common
else:unix: LIBS += -L$$PWD/lib/ -laudio -lmi_sys -lmi_ao -lmad -lmi_common

INCLUDEPATH += $$PWD/include
DEPENDPATH += $$PWD/include
