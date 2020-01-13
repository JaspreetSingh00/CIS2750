UNAME := $(shell uname)
CC = gcc
CFLAGS = -Wall -std=c11 -g -Iinclude 
LDFLAGS= -L.

ifeq ($(UNAME), Linux)
	INC_PATH = /usr/include/libxml2
endif
ifeq ($(UNAME), Darwin)
	INC_PATH = /System/Volumes/Data/Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/usr/include/libxml2
endif


all: ./bin/liblist.so
			
./bin/liblist.so: ./bin/LinkedListAPI.o
	$(CC) $(CFLAGS) -shared ./bin/LinkedListAPI.o -o ./bin/liblist.so

./bin/LinkedListAPI.o: ./src/LinkedListAPI.c ./include/LinkedListAPI.h
	$(CC) $(CFLAGS) -c -fpic ./src/LinkedListAPI.c -o ./bin/LinkedListAPI.o

clean:
	rm -rf ./bin/liblist ./bin/*.o ./bin/*.so