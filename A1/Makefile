UNAME := $(shell uname)
CC = gcc
CFLAGS = -Wall -std=c11 -g  
LDFLAGS= -L.

ifeq ($(UNAME), Linux)
	INC_PATH = /usr/include/libxml2
endif
ifeq ($(UNAME), Darwin)
	INC_PATH = /System/Volumes/Data/Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/usr/include/libxml2
endif


all: parser

parser: ./src/SVGParser.c ./src/Helper.c ./include/Helper.h ./include/SVGParser.h ./include/LinkedListAPI.h ./src/LinkedListAPI.c
	$(CC) $(CFLAGS) $(LFLAGS) -l -Iinclude -I/usr/include/libxml2  `xml2-config --cflags --libs` ./src/SVGParser.c -o ./bin/svgparser.o
	$(CC) $(CFLAGS) $(LFLAGS) -Iinclude ./src/LinkedListAPI.c -o ./bin/list.o
	$(CC) $(CFLAGS) $(LFLAGS) -l -Iinclude -I/usr/include/libxml2 ./src/Helper.c -o ./bin/Helper.o
	$(CC) $(CFLAGS) -shared ./bin/svgparser.o ./bin/Helper.o ./bin/list.o -o ./bin/libsvgparse.so

clean:
	rm -rf ./bin/*.o ./bin/*.so