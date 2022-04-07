all: main

main.o: main.cpp FileStreamBuf.h
	g++ -c -Wall -Werror main.cpp

FileStreamBuf.o: FileStreamBuf.cpp FileStreamBuf.h
	g++ -c -Wall -Werror FileStreamBuf.cpp

main: main.o FileStreamBuf.o
	g++ -o main main.o FileStreamBuf.o
