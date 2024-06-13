all: employee_hierarchy.exe

employee.o: employee.c employee.h
	gcc -c employee.c -o employee.o

fileUtil.o: fileUtil.c fileUtil.h
	gcc -c fileUtil.c -o fileUtil.o

employee_hierarchy.exe: employee_hierarchy.c employee.o fileUtil.o
	gcc fileUtil.o employee.o employee_hierarchy.c -o employee_hierarchy.exe

clean:
	del -f *.o *.exe