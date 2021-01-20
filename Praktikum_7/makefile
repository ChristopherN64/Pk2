all: main.exe main.o medium.o

main.exe : main.o medium.o
	g++ -o main.exe medium.o main.o 

main.o : main.cpp
	g++ -c main.cpp

medium.o : medium.cpp
	g++ -c medium.cpp

clean : 
	del *.o *.a *.exe