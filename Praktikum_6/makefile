ll.exe : main.o LinkedList.o ListElement.o
	g++ -o ll.exe main.o LinkedList.o ListElement.o

main.o : main.cpp 
	g++ -c main.cpp 

LinkedList.o : LinkedList.cpp
	g++ -c LinkedList.cpp 

ListElement.o : ListElement.cpp
	g++ -c ListElement.cpp
	
clean : 
	del *.o *.a *.exe