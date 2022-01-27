all: main

main.o: main.cpp function.h
	g++ -c -Wall -Werror main.cpp

function.o: function.cpp function.h
	g++ -c -Wall -Werror function.cpp

range.o: range.cpp function.h
	g++ -c -Wall -Werror range.cpp

main: main.o function.o range.o
	g++ -o main main.o function.o range.o