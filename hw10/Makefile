all: main

main.o: main.cpp Pattern.h
	g++ -c -Wall -Werror -std=c++11 main.cpp

Pattern.o: Pattern.cpp Pattern.h
	g++ -c -Wall -Werror -std=c++11 Pattern.cpp
	
main: main.o Pattern.o
	g++ -o main main.o Pattern.o
