#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node *prev;
	struct node *next;
};
struct node *temp,*start=NULL,*newnode;
void create()
{
	int n,i;
	printf("enter the size of nodes \n");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		printf("enter the data in new node \n");
		newnode=malloc(sizeof(struct node));
		scanf("%d",&newnode->data);
		newnode->prev=NULL;
		newnode->next=NULL;
		if(start==NULL)
		{
			start=newnode;
		}
		else
		{
			for(temp=start;temp->next!=NULL;temp=temp->next)
			{}
			temp->next=newnode;
			newnode->prev=temp;
		}
	}
}

void display()
{
	for(temp=start;temp!=NULL;temp=temp->next)
	{
		printf("%d \n",temp->data);
	}
	reverse();
}

void append()
{
	struct node *nnode;
	printf("enter the data to be appended \n");
	nnode=malloc(sizeof(struct node));
	scanf("%d",&nnode->data);
	nnode->next=nnode->prev=NULL;
	for(temp=start;temp->next!=NULL;temp=temp->next)
	{}
	nnode->prev=temp;
	temp->next=nnode;
	display();
	reverse();
}
void insert()
{
	struct node *nnode1;
	printf("enter the data to be inserted \n");
	nnode1=malloc(sizeof(struct node));
	scanf("%d",&nnode1->data);
	nnode1->next=nnode1->prev=NULL;
	nnode1->next=start;
	start->prev=nnode1;
	start=nnode1;
	display();
	reverse();
}
void insert_between()
{
	int i,x;
	struct node *nnode2;
	printf("enter the data to be inserted \n");
	nnode2=malloc(sizeof(struct node));
	scanf("%d",&nnode2->data);
	printf("enter the data after which you want to insert new node \n");
	scanf("%d",&x);
	nnode2->next=nnode2->prev=NULL;
	for(temp=start;temp->next!=NULL;temp=temp->next)
	{
		if(temp->data==x)
		{
	nnode2->next=temp->next;
	nnode2->prev=temp->next;
	temp->next=nnode2;
	}
	else
	{
		printf("data is not available in node \n");
	}
	display();
}
}
void reverse()
{
	printf("reversed nodes are as follow \n");
	for(temp=start;temp->next!=NULL;temp=temp->next)
	{}
	for(temp;temp!=NULL;temp=temp->prev)
	{
		printf("%d \n",temp->data);
	}
}
void search()
{
	int x,i,flag=0;
	printf("enter the data to be searched \n");
	scanf("%d",&x);
	for(temp=start;temp!=NULL;temp=temp->next)
	{
		if(x==temp->data)
		{
		   flag=1;
		   break;
		}
		
	}
	if(flag==1)
	{
		printf("data is available in node \n");
	}
	else
	{
		printf("data is not available in node \n");
	}
}
int main()
{
	create();
	append();
}
