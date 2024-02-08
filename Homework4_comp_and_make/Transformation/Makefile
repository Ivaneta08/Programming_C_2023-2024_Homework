main.exe: main.c transformation.h transformation.o
	gcc main.c transformation.o -o main.exe

transformation.o: transformation.c transformation.h
	gcc -c transformation.c -o transformation.o

clean:
	del *.exe *.o