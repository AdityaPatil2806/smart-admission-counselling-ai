#include<stdio.h>
main()
{
	int a[100],b[100],c[100],n,x,i,j,k,m;
	printf("enter the size of array \n");
	scanf("%d",&n);
	printf("enter the elements in array A \n");
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	printf("enter the elements in array B \n");
	for(i=0;i<n;i++)
	{
		scanf("%d",&b[i]);
	}
	i=0;j=0;k=0;
	while(i<n && j<n)
	{
		if(a[i]<b[j])
		{
			c[k]=a[i];
			k++;
			i++;
		}
		else if(b[j]<a[i])
		{
			c[k]=b[j];
			j++;
			k++;
		}
		else
		{
			c[k]=a[i];
			k++;
			i++;
			c[k]=b[j];
			k++;
			j++;
		} 
	}
	printf("sorted array is :- \n");
	for(k=0;k<n;k++)
	{
		printf("%d",c[k]);
	}
}
