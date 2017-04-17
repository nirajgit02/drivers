#include<stdio.h>
#include<stdlib.h>

struct node
{
	int rollno;
	struct node* next;
};

/**********************************************************************
NAME:count
PARAMETERS:struct node*
RETURN VALUE:int
DESCRIPTION:It counts the number of nodes present in a linklist
 ***********************************************************************/
int count(struct node* ptr)//function to count no of nodes using recursion
{
	static int c=0;
	if(ptr)
	{
		c++;
		return count(ptr->next);// calling count function recursively
	}
	else
		return c ;
}

/**********************************************************************
NAME:rev_link
PARAMETERS:struct node**
RETURN VALUE:none
DESCRIPTION:It reverses the link in a given linklist
 ***********************************************************************/
void rev_link(struct node** curr)//to reverse the linklist
{
	struct node *pre=0,*nxt=0;

	while(((*curr)->next)!=NULL)//logic to reverse links
	{
		nxt=(*curr)->next;
		(*curr)->next=pre;
		pre=*curr;
		*curr=nxt;
	}
	(*curr)->next=pre;
}

/**********************************************************************
NAME:insert
PARAMETERS:struct node*
RETURN VALUE:none
DESCRIPTION:It inserts the new node in a linklist
 ***********************************************************************/
void insert(struct node** ptr)//to insert nodes in the linklist
{

	struct node* new= (struct node*)malloc(sizeof(struct node));//allocating memory for one node

	printf("enter the rollno:\n");
	scanf("%d",&new->rollno);


	if(*ptr==0)
	{
		new->next=*ptr;
		*ptr=new;
	}
	else
	{
		struct node* temp=*ptr;
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
DESCRIPTION:It prints the data of every node in a linklist
 ***********************************************************************/
void print(struct node* ptr)//to display the linklist
{

	while(ptr)
	{
		printf("%d ",ptr->rollno);
		ptr=ptr->next;
	}
	printf("\n");
}

int main()//main
{
	struct node *hptr=0;
	char ch;
	int num;

	do
	{
		insert(&hptr);//insert new node
		printf("do u want to add node y/n\n");
		scanf(" %c",&ch);
	}while((ch=='y')||(ch=='Y'));

	print(hptr);
	rev_link(&hptr);//reverse ll

	printf("reversed linklist:\n");
	print(hptr);

	num=count(hptr);

	printf("number is nodes in linklist are:%d\n",num);

}
