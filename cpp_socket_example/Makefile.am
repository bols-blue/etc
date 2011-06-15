#test is skelton code \n
bin_PROGRAMS=\
	server\
	client
noinst_LIBRARIES = libtest.a
#test_CFLAGS is test package C compiler option
#test_CFLAGS=
#test_CXXFLAGS is test package C++ compiler option
client_CXXFLAGS=-Isrc/
server_CXXFLAGS=-Isrc/
#test_LDADD is test package LOADER option
#libtest_LIBRARIES is libtest package define
#libtest_a_SOURCES is libtest package source files
#test_SOURCES= is test package sourcefiles\n
client_SOURCES= \
src/client_main.cpp 

server_SOURCES= \
src/server_main.cpp

LDADD=$(noinst_LIBRARIES)
libtest_a_SOURCES= \
src/client.cpp \
src/server.cpp \
src/server.h 
