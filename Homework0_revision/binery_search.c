#include<stdio.h>

int find_num(int find, int arr[],int lenght)
{
    int l=0,r=lenght-1,mid;
    while(l <= r)
    {
        mid = (l+r)/2;
        //printf("%d\n",arr[mid]);
        if(arr[mid] == find)return mid;
        else if(arr[mid] < find)l = mid+1;
        else r = mid-1;
    }
    return -1;
}

int main()
{
	int arr[] = {1,2,5,7,8,9};
	int a;
	scanf("%d",&a);
	printf("%d",find_num(a,arr,6));
	return 0;
}
