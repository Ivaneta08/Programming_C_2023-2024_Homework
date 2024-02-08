#include<stdio.h>
int main()
{
	int n;
    do
    {
        printf("n = (n>0)\n");
        scanf("%d",&n);
    }while(n<1);

    int mult=1;
    while(n!=0)
    {
        mult*=n%10;
        n/=10;
    }

    printf("%d",mult);
	return 0;
}
