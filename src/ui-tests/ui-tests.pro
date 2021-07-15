include(../common.pri)

TEMPLATE = lib
TARGET = tomatl-ui-tests
CONFIG   += console
CONFIG   -= app_bundle

QT       += testlib
QT       -= gui

DEFINES += SRCDIR=\\\"$$PWD/\\\"

DEPENDPATH += \
  $$PWD/../core \
  $$PWD/../core-mock \
  $$PWD/../ui

INCLUDEPATH += \
  $$PWD/../core \
  $$PWD/../core/impl \
  $$PWD/../core-mock \
  $$PWD/../ui \
  $$PWD/../ui/impl

win32:CONFIG(release, debug|release): LIBS += \
  -L$$OUT_PWD/../core/release/ -ltomatl-core \
  -L$$OUT_PWD/../core-mock/release/ -ltomatl-core-mock \
  -L$$OUT_PWD/../ui/release/ -ltomatl-ui

else:win32:CONFIG(debug, debug|release): LIBS += \
  -L$$OUT_PWD/../core/debug/ -ltomatl-core \
  -L$$OUT_PWD/../core-mock/debug/ -ltomatl-core-mock \
  -L$$OUT_PWD/../ui/debug/ -ltomatl-ui

else:unix: LIBS += \
  -L$$OUT_PWD/../core/ -ltomatl-core \
  -L$$OUT_PWD/../core-mock/ -ltomatl-core-mock \
  -L$$OUT_PWD/../ui/ -ltomatl-ui

HEADERS += \
    mock/MockTray.h \
    mock/MockTrayIconFiles.h \
    mock/MockSoundClip.h \
    mock/MockSoundNotifications.h \
    TrayControllerTest.h \
    SoundNotificationControllerTest.h

SOURCES += \
    mock/MockTray.cpp \
    mock/MockTrayIconFiles.cpp \
    mock/MockSoundClip.cpp \
    mock/MockSoundNotifications.cpp \
    TrayControllerTest.cpp \
    SoundNotificationControllerTest.cpp
