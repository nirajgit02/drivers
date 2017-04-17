#include<stdio.h>
#include<stdlib.h>

struct node
{
	int rollno;
	struct node* next;
};

/**********************************************************************
NAME:merge
PARAMETERS:struct node**,struct node**
RETURN VALUE:struct node*
DESCRIPTION:merge two linklist without repeating duplicate node
 ***********************************************************************/
struct node* merge(struct node** ptr1,struct node** ptr2)
{
	struct node* temp=*ptr1;
	struct node* ptr3=*ptr1;

	while(*ptr2)
	{
		while(temp->next!=0)
		{
			if((temp->rollno)==(*ptr2)->rollno)
			{
				temp=*ptr1;
				if((*ptr2)->next==0)
					break;
				else
					*ptr2=(*ptr2)->next;
			}
			else
			{
				temp=temp->next;
			}
		}

		if((*ptr2)->next!=0)
		{

			if((temp->rollno)!=(*ptr2)->rollno)
			{
				temp->next=*ptr2;
				*ptr2=(*ptr2)->next;
				temp->next->next=0;	
			}
			else
			{
				*ptr2=(*ptr2)->next;
			}
			temp=*ptr1;
		}
		else
		{	
			while(temp->next!=0)
				temp=temp->next;

			temp->next=*ptr2;
			*ptr2=(*ptr2)->next;
			temp->next->next=0;
		}
	}
	return ptr3;

}

/**********************************************************************
NAME:insert
PARAMETERS:struct node**
RETURN VALUE:none
DESCRIPTION:It inserts node in the linklist without duplicates
 ***********************************************************************/

void insert(struct node** ptr)
{
	int roll;
	struct node* new= (struct node*)malloc(sizeof(struct node));//allocating memory for one node

	printf("enter the rollno:\n");
	scanf("%d",&roll);


	if(*ptr==0)
	{
		new->rollno=roll;
		new->next=*ptr;
		*ptr=new;
	}
	else
	{
		struct node* temp=*ptr;
		while(temp->next!=0)
		{
		if(temp->rollno!=roll)
		{
			temp=temp->next;
			continue;
		}
		else
		{
			printf("pls enter non duplicate rollno:\n");
			scanf("%d",&roll);	
			temp=*ptr;
			continue;
		}
		}


			while(1)
			{
				if(temp->rollno!=roll)
				{
		 		new->rollno=roll;
				break;
				}
				else
				{	
					printf("pls enter non duplicate rollno:\n");
					scanf("%d",&roll);
					continue;
				}
			}


			temp=*ptr;
		while(temp->next!=0)
			temp=temp->next;

		new->next=temp->next;
		temp->next=new;

	}

}

/**********************************************************************
NAME:print
PARAMETERS:struct node*
RETURN VALUE:none
DESCRIPTION:To print the data of every node in linklist
 ***********************************************************************/
void print(struct node* ptr)//to display the linklist
{

	while(ptr)
	{
		printf("->%d",ptr->rollno);
		ptr=ptr->next;
	}
	printf("\n");
}
/////////////////////main////////////////////////
int main()
{
	struct node *hptr1=0,*hptr2=0,*ret;
	char ch;
	int num;
	/////////////////inserting 1st ll//////////////////
	printf("enter the 1st linklist values\n");

	do
	{
		insert(&hptr1);
		printf("do u want to add node y/n\n");
		scanf(" %c",&ch);
	}while((ch=='y')||(ch=='Y'));

	print(hptr1);
	printf("----------------------------------\n");

	/////////////////inserting 2nd ll/////////////////////
	printf("enter the 2nd linklist values\n");

	do
	{
		insert(&hptr2);
		printf("do u want to add node y/n\n");
		scanf(" %c",&ch);
	}while((ch=='y')||(ch=='Y'));

	print(hptr2);
	printf("----------------------------------\n");

	ret=merge(&hptr1,&hptr2);

	printf("merged ll is:");
	print(ret);
	printf("----------------------------------\n");
}
