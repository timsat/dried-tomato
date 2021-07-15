include(../common.pri)

TEMPLATE = app
TARGET = tomatl-test-runner
CONFIG   += console
CONFIG   -= app_bundle

QT       += testlib
QT       -= gui

DEFINES += SRCDIR=\\\"$$PWD/\\\"

DEPENDPATH += \
  $$PWD/../core-tests \
  $$PWD/../ui-tests

INCLUDEPATH += \
  $$PWD/../core-tests \
  $$PWD/../core-tests/impl \
  $$PWD/../ui-tests \
  $$PWD/../ui-tests/impl

SOURCES += \
    Main.cpp

win32:CONFIG(release, debug|release): LIBS += \
  -L$$OUT_PWD/../core/release/ -ltomatl-core \
  -L$$OUT_PWD/../ui/release/ -ltomatl-ui \
  -L$$OUT_PWD/../core-tests/release/ -ltomatl-core-tests \
  -L$$OUT_PWD/../ui-tests/release/ -ltomatl-ui-tests

else:win32:CONFIG(debug, debug|release): LIBS += \
  -L$$OUT_PWD/../core/debug/ -ltomatl-core \
  -L$$OUT_PWD/../ui/debug/ -ltomatl-ui \
  -L$$OUT_PWD/../core-tests/debug/ -ltomatl-core-tests \
  -L$$OUT_PWD/../ui-tests/debug/ -ltomatl-ui-tests

else:unix: LIBS += \
  -L$$OUT_PWD/../core/ -ltomatl-core \
  -L$$OUT_PWD/../ui/ -ltomatl-ui \
  -L$$OUT_PWD/../core-tests/ -ltomatl-core-tests \
  -L$$OUT_PWD/../core-mock/ -ltomatl-core-mock \
  -L$$OUT_PWD/../ui-tests/ -ltomatl-ui-tests
