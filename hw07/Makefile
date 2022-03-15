all: main

main.o: main.cpp Vector.h
	g++ -c -Wall -Werror main.cpp

Vector.o: Vector.cpp Vector.h
	g++ -c -Wall -Werror Vector.cpp

main: main.o Vector.o
	g++ -o main main.o Vector.o
