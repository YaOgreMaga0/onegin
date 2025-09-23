all: start

start: main.o IndexFunc.o
	g++ main.o IndexFunc.o -o EvgOneg

main.o: main.cpp
	g++ -c main.cpp  -o main.o

IndexFunc.o: IndexFunc.cpp
	g++ -c IndexFunc.cpp -o IndexFunc.o
