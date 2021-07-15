include(../common.pri)

TEMPLATE = lib
TARGET = tomatl-ui

QT += widgets
QT += multimedia

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../core/release/ -ltomatl-core
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../core/debug/ -ltomatl-core
else:unix: LIBS += -L$$OUT_PWD/../core/ -ltomatl-core

INCLUDEPATH += $$PWD/../core $$PWD/../core/impl
DEPENDPATH += $$PWD/../core
DEFINES += SRCDIR=\\\"$$PWD/\\\"

HEADERS += \
    Tray.h \
    TrayController.h \
    impl/StandardTrayController.h \
    impl/StandardTray.h \
    TrayIconFiles.h \
    impl/StandardTrayIconFiles.h \
    SoundNotificationController.h \
    SoundClip.h \
    SoundNotifications.h \
    impl/StandardSoundNotifications.h \
    impl/ImmutableSoundClip.h

SOURCES += \
    Tray.cpp \
    TrayController.cpp \
    impl/StandardTrayController.cpp \
    impl/StandardTray.cpp \
    TrayIconFiles.cpp \
    impl/StandardTrayIconFiles.cpp \
    SoundNotificationController.cpp \
    SoundClip.cpp \
    SoundNotifications.cpp \
    impl/StandardSoundNotifications.cpp \
    impl/ImmutableSoundClip.cpp

RESOURCES = resources/tomatl.qrc

target.path = /usr/local/lib
INSTALLS += target
