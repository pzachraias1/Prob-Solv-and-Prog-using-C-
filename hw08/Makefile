all: main

main.o: main.cpp Planet.h Vector.h
	g++ -c -Wall -Werror -std=c++11 main.cpp

Planet.o: Planet.cpp Planet.h Vector.h
	g++ -c -Wall -Werror -std=c++11 Planet.cpp

Vector.o: Vector.cpp Vector.h
	g++ -c -Wall -Werror -std=c++11 Vector.cpp

Satellite.o: Satellite.cpp Planet.h Vector.h
	g++ -c -Wall -Werror -std=c++11 Satellite.cpp

main: main.o Planet.o Vector.o Satellite.o
	g++ -o main main.o Planet.o Vector.o Satellite.o
