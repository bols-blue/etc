#test is skelton code 
bin_PROGRAMS=InitAccessoryMode\
	     AccessoryDataCom\
	     lsusb
#test_CFLAGS is test package C compiler option
#test_CXXFLAGS is test package C++ compiler option
#InitAccessoryMode_LDADD=libusb-1.0
#AccessoryDataCom_LDADD=libusb-1.0
#libtest_LIBRARIES is libtest package define
#libtest_a_SOURCES is libtest package source files
#test_SOURCES= is test package sourcefiles
InitAccessoryMode_SOURCES=libusb_adk.c InitAccessoryMode.c
lsusb_SOURCES=lsusb.c libusb_adk.c
AccessoryDataCom_SOURCES=libusb_adk.c InitAccessoryMode.c
InitAccessoryMode_LDFULGS=-static-libgcc -static-libusb-1.0
