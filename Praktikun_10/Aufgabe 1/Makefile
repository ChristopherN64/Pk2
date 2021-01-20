all : matrix.exe
	matrix.exe

matrix.exe : main.o Matrix.hpp
	g++ -o matrix.exe main.o Matrix.hpp

main.o : Main.cpp Matrix.hpp
	g++ -c main.cpp