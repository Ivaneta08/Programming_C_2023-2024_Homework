#include<stdio.h>

struct student
{
    char name[20];
    int num;
    float average;
};

int main()
{
	struct student s1;
	printf("Enter student name:\n");
	gets(s1.name);
    //getch();
	printf("Enter student number:\n");
	scanf("%d",&s1.num);
	printf("Enter student average grade:\n");
	scanf("%f",&s1.average);

	printf("Name: %s\n", s1.name);
	printf("Number: %d\n", s1.num);
	printf("Average grade: %f\n", s1.average);
	return 0;
}
