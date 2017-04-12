// use of static

//here value of 'i' will be 6 7 8 9 and not 6 6 6 6 as 'i' is static

#include<stdio.h>
/*********************************************************************
NAME:display
PARAMETERS:none
RETURN VALUE:none
DESCRIPTION:prints the value of static variable
*********************************************************************/
void display()
{
	static int i=6;//value of i is initialized only once as it is static
	printf("%d ",i);
	i++;
}

int main()
{
	int num;
	for(num=0;num<4;num++)
		display();
	printf("\n");
}
