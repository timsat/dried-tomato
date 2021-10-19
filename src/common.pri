CONFIG += c++11
#unix:QMAKE_RPATHDIR += /usr/local/lib:/usr/lib

GIT_HASH="$$system(git -C \""$$_PRO_FILE_PWD_"\" rev-parse --short HEAD)"

DEFINES += GIT_HASH=\\\"$$GIT_HASH\\\"

VERSION_MAJOR = 1
VERSION_MINOR = 0

DEFINES += "VERSION_MAJOR=$$VERSION_MAJOR"\
       "VERSION_MINOR=$$VERSION_MINOR"

#Target version
VERSION = $${VERSION_MAJOR}.$${VERSION_MINOR}.$${GIT_HASH}

DEFINES += VERSION=\\\"$$VERSION\\\"
