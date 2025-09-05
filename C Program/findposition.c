#include<stdio.h>
int find(int n,int x,int a[100])
{
int i,j,flag=0,l;
for(i=0;i<n;i++)
{
	if(a[i]==x)
	{
	    flag=1;
	    l=i;
		break;
	}
}
	if(flag==1)
{
	printf("element found at position a[%d] \n",l);
}
else
{
printf("element not found \n");
}
}
main()
{
int a[50],n,flag=0,i,j,x,y;
printf("enter the number of arrays \n");
scanf("%d",&n);
printf("enter elements in array \n");
for(i=0;i<n;i++)
{
	scanf("%d",&a[i]);
}
printf("enter the element you want search \n");
scanf("%d",&x);
find(n,x,a);
}

