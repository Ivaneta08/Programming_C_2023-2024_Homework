all: el_library.exe

dynarr.o: dynarr.h dynarr.c
	gcc -c dynarr.c -o dynarr.o

el_library.exe: dynarr.o el_library.c
	gcc el_library.c dynarr.o -o el_library.exe

clean:
	del -f *.o *.exe