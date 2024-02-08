all: help.exe strlength.exe strconcat.exe strcompare.exe

help.exe: help.c mystrings.h mystrings.o
	gcc help.c mystrings.o -o help.exe

mystrings.o: mystrings.h mystrings.c
	gcc -c mystrings.c -o mystrings.o

strlength.exe: strlength.c mystrings.h mystrings.o
	gcc strlength.c mystrings.o -o strlength.exe

strconcat.exe: strconcat.c mystrings.h mystrings.o
	gcc strconcat.c mystrings.o -o strconcat.exe

strcompare.exe: strcompare.c mystrings.h mystrings.o
	gcc strcompare.c mystrings.o -o strcompare.exe

clean:
	del *.exe *.o