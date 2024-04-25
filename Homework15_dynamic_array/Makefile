all: tests.exe

dynarr.o: dynarr.h dynarr.c
	gcc -c dynarr.c -o dynarr.o

tests.exe: dynarr.o test.c
	gcc test.c dynarr.o -o tests.exe

clean:
	del -f *.o *.exe