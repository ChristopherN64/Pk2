all : ll.exe
	ll.exe

ll.exe : main.o medium.o Iterator.h LinkedList.h ListElement.h ListIterator.h
	g++ -o ll.exe main.o LinkedList.h ListElement.h medium.o

main.o : main.cpp 
	g++ -c main.cpp 

medium.o: medium.cpp
	g++ -c medium.cpp

clean : 
	del *.o *.a *.exe