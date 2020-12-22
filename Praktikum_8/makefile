ll.exe : main.o LinkedList.o ListElement.o Iterator.h LinkedList.h
	g++ -o ll.exe main.o LinkedList.o ListElement.o

main.o : main.cpp 
	g++ -c main.cpp 

LinkedList.o : LinkedList.cpp Iterator.h LinkedList.h
	g++ -c LinkedList.cpp 

ListElement.o : ListElement.cpp
	g++ -c ListElement.cpp
	
clean : 
	del *.o *.a *.exe