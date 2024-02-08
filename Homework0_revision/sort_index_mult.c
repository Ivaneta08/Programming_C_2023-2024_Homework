#include<stdio.h>

int main()
{
	int a[] = {1,7,3,4,9,2};

	for(int i=1; i < 6; i++)
    {
        int num = a[i];
		int j = i;
		while(j>0 && a[j-1]>num)
		{
			a[j]=a[j-1];
			--j;
		}
		a[j]=num;
	}

	int sum=0;
    for(int i=0; i < 6 ; i++)
    {
         sum += a[i] * i;
    }

    printf("%d",sum);
	return 0;
}
