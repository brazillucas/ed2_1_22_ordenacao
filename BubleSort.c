#include<stdio.h>

int main()
{
	int i,j,n,a[10],t;
	
	printf("enter the number of elements");
	
	scanf("%d",&n);
	
	printf("enter the elements");
	
	for(i=0;i<n;i++)
	{
		scanf("%d \n",&a[i]);
	}
	for(i=0;i<n-1;i++)
	{
		for(j=0;j<n-i-1;j++)
		{
			if(a[j]>a[j+1])
			{
				t=a[j];
				a[j]=a[j+1];
				a[j+1]=t;
			}
			}
	}
	printf("the sorted array is: \n");
	
	for(i=0;i<n;i++)
	{
		printf("%d \n",a[i]);
	}
}
