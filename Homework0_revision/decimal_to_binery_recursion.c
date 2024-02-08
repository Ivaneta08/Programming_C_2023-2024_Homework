#include<stdio.h>

long long decimal_to_binery(int a)
{
    if(a == 1)return 1;
    else
    {
        long long done = decimal_to_binery(a/2) * 10 + a%2;
        return done;
    }
}

int main()
{
	int n;
	scanf("%d",&n);
	printf("%ld",decimal_to_binery(n));
	return 0;
}
