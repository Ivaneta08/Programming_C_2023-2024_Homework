main.exe: main.c maths.h maths.o libmaths.a
	gcc main.c -L. -lmaths -o main.exe

maths.o: maths.c maths.h
	gcc -c maths.c -o maths.o

libmaths.a: maths.o maths.c maths.h
	ar rcs libmaths.a maths.o

clean:
	del *.exe *.o *.a