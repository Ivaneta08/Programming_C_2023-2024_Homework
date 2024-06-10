all: work_with_citizen_bin_file.exe

dynarr.o: dynarr.h dynarr.c citizen.h
	gcc -c dynarr.c -o dynarr.o

work_with_citizen_bin_file.exe: dynarr.o work_with_citizen_bin_file.c
	gcc work_with_citizen_bin_file.c dynarr.o -o work_with_citizen_bin_file.exe

clean:
	del -f *.o *.exe