taskmanager.exe: taskmanager.c processes.o
	gcc taskmanager.c processes.o -o taskmanager.exe

processes.o: processes.h processes.c
	gcc -c processes.c -o processes.o

clean:
	del *.exe *.o