ll.exe : main.o LinkedList.o ListElement.o medium.o Iterator.h LinkedList.h ListElement.h ListIterator.h
	g++ -o ll.exe main.o LinkedList.o ListElement.o medium.o

main.o : main.cpp 
	g++ -c main.cpp 

medium.o: medium.cpp
	g++ -c medium.cpp

	
clean : 
	del *.o *.a *.exe