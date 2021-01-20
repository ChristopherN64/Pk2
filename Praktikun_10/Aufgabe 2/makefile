all : stack.exe main.cpp stack.h
	stack.exe

stack.exe : main.o stack.o
	g++ -o stack.exe stack.o main.o

main.o : main.cpp stack.o
	g++ -c main.cpp

stack.o : stack.cpp
	g++ -c stack.cpp