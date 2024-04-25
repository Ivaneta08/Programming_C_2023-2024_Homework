all: donors.exe

dynarr.o: dynarr_donors.h dynarr_donors.c
	gcc -c dynarr_donors.c -o dynarr_donors.o

donors.exe: dynarr_donors.o donors.c
	gcc donors.c dynarr_donors.o -o donors.exe

clean:
	del -f *.o *.exe