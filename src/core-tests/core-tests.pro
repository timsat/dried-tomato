include(../common.pri)

TEMPLATE = lib
TARGET = tomatl-core-tests
CONFIG   += console
CONFIG   -= app_bundle

QT       += testlib
QT       -= gui

DEFINES += SRCDIR=\\\"$$PWD/\\\"
DEPENDPATH += \
  $$PWD/../core \
  $$PWD/../core-mock

INCLUDEPATH += \
  $$PWD/../core \
  $$PWD/../core/impl \
  $$PWD/../core-mock

win32:CONFIG(release, debug|release): LIBS += \
  -L$$OUT_PWD/../core/release/ -ltomatl-core \
  -L$$OUT_PWD/../core-mock/release/ -ltomatl-core-mock

else:win32:CONFIG(debug, debug|release): LIBS += \
  -L$$OUT_PWD/../core/debug/ -ltomatl-core \
  -L$$OUT_PWD/../core-mock/debug/ -ltomatl-core-mock

else:unix: LIBS += \
  -L$$OUT_PWD/../core/ -ltomatl-core \
  -L$$OUT_PWD/../core-mock/ -ltomatl-core-mock

HEADERS += \
    TimerTest.h \
    PomodoroEngineTest.h

SOURCES += \
    TimerTest.cpp \
    PomodoroEngineTest.cpp
