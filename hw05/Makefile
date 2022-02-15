all: main

main.o: main.cpp range.h
	g++ -c -Wall -Werror main.cpp

formula.o: formula.cpp formula.h
	g++ -c -Wall -Werror formula.cpp

range.o: range.cpp range.h formula.h
	g++ -c -Wall -Werror range.cpp

main: main.o formula.o range.o
	g++ -o main main.o formula.o range.o

