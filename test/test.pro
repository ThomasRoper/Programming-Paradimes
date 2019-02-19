TARGET=TestsProgram


SOURCES+= $$PWD/testTests.cpp \
          $$PWD/test.cpp

HEADERS+= $$PWD/test.h
CONFIG += console
LIBS += -L/public/devel/lib

LIBS+=-lgtest -l gtest_main
