all: to_do_list.exe

linkedlist.o: linkedlist.h linkedlist.c to_do_tasks.h
	gcc -c linkedlist.c -o linkedlist.o

to_do_list.exe: linkedlist.o to_do_list.c
	gcc to_do_list.c linkedlist.o -o to_do_list.exe

clean:
	del -f *.o *.exe