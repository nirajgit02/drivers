
//program to inver the bits of given int variable

#include<stdio.h>

int invert(int x,int p,int n)//to inver the bits of given number
{
	while(n--)
	{
		x=x^(1<<p++);//invert the  pth bit of x
	}
	return x;

}

int main()
{
	int num,pos,loc,ret;//number position location respectively
	printf("enter the value position and locations to invert\n");
	scanf("%d%d%d",&num,&pos,&loc);

	ret=invert(num,pos,loc);

	printf("inverted value of %d is %d\n",num,ret);

}
