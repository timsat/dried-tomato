include(../common.pri)

TEMPLATE = app
TARGET = tomatl

QT += widgets

DEFINES += SRCDIR=\\\"$$PWD/\\\"

DEPENDPATH += \
  $$PWD/../core \
  $$PWD/../ui

INCLUDEPATH += \
  $$PWD/../core \
  $$PWD/../ui

SOURCES += \
    Main.cpp

win32:CONFIG(release, debug|release): LIBS += \
  -L$$OUT_PWD/../core/release/ -ltomatl-core \
  -L$$OUT_PWD/../ui/release/ -ltomatl-ui

else:win32:CONFIG(debug, debug|release): LIBS += \
  -L$$OUT_PWD/../core/debug/ -ltomatl-core \
  -L$$OUT_PWD/../ui/debug/ -ltomatl-ui

else:unix: LIBS += \
  -L$$OUT_PWD/../core/ -ltomatl-core \
  -L$$OUT_PWD/../ui/ -ltomatl-ui

target.path = /usr/local/bin
INSTALLS += target
