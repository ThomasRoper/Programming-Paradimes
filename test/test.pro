TARGET=TestsProgram


SOURCES+= $$PWD/testTests.cpp \
          $$PWD/test.cpp

HEADERS+= $$PWD/test.h
CONFIG += console
LIBS += -L/public/devel/lib
INCLUDEPATH += ../lib
LIBS+=-lgtest -l gtest_main -L../lib -lLSystems

QMAKE_RPATHDIR += ../lib
