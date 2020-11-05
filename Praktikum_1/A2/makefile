prog.exe : main.c libmy.a libmy.h
	gcc -o prog main.c libmy.a

libmy.a : printAsci.o einMalEins.o intToBin.o
	ar r libmy.a intToBin.o einMalEins.o printAsci.o

printAsci.o : ..\A3\printAsci.c
	gcc -c ..\A3\printAsci.c

einMalEins.o : ..\A4\einMalEins.c
	gcc -c ..\A4\einMalEins.c

intToBin.o : ..\A5\intToBin.c
	gcc -c ..\A5\intToBin.c

clean : 
	del *.o *.a *.exe