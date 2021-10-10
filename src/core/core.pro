include(../common.pri)

TEMPLATE = lib
TARGET = tomatl-core

QT += core

SOURCES += \
    Clockwork.cpp \
    PomodoroEngine.cpp \
    Preferences.cpp \
    Interval.cpp \
    Timer.cpp \
    TimerSignalEmitter.cpp \
    impl/StandardPomodoroEngine.cpp \
    impl/StandardTimer.cpp \
    impl/StandardPreferences.cpp

HEADERS += \
    Clockwork.h \
    Interval.h \
    IntervalType.h \
    PomodoroEngine.h \
    Preferences.h \
    Timer.h \
    TimerSignalEmitter.h \
    impl/Clockwork_p.h \
    impl/StandardPomodoroEngine.h \
    impl/StandardTimer.h \
    impl/StandardPreferences.h

target.path = /lib
INSTALLS += target
