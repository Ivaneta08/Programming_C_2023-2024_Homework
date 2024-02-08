#include<stdio.h>

bool prime_num(int a)
{
    if(a==1)return false;
    int prosto=1,del=2;
    while(del<a/2 && prosto)
    {
        if(a%del==0)prosto=0;
        del++;
    }
    return prosto;
}

int main()
{
	/*int n;
    do
    {
        printf("n=? (n>=1):");
        scanf("%d",&n);
    }while(n < 1);

    int arr[n];
    for(int i = 0; i < n; i++)
    {
        scanf("%d",&arr[i]);
    }*/

    int arr[] = {1,7,10,15,16,13,23,30};
    int sum=0;
    for(int i = 0; i < 8; i++)
    {
        if(prime_num(arr[i]))
        {
            sum+=arr[i];
            //printf("%d\n",arr[i]);
        }
    }

    printf("%d",sum);

	return 0;
}
