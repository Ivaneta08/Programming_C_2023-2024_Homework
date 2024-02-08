main.exe: main.c quadraticroots.o
	gcc main.c quadraticroots.o -o main.exe

quadraticroots.o: quadraticroots.h quadraticroots.c
	gcc -c -lm quadraticroots.c -o quadraticroots.o

clean:
	del *.exe *.o