#include<stdio.h>

/**********************************************************************
NAME:rightrot
PARAMETERS:int,int
RETURN VALUE:int
DESCRIPTION:It will rotate the given number to right by p positions
 ***********************************************************************/
int rightrot(int num,int p)
{

	while(p--)
	{
		if((num&1)==1)
		{
			num=num>>1;
			num=num|(1<<(((sizeof(int))*8)-1));//set bit
		}
		else
		{

			num=num>>1;
			num=num &~(1<<(((sizeof(int))*8)-1));//clear bit
		}
	}
	return num;//return number after rotation	
}


int main()
{
	int num,pos,ret,i;

	printf("enter the value\n");
	scanf("%d",&num);
	printf("enter the no of position\n");
	scanf("%d",&pos);

	printf("value of %d before rotation:\n",num);
	for(i=sizeof(int)*8-1;i>=0;i--)//printing original binary number
		printf("%d",(num>>i)&1);
	printf("\n");

	ret=rightrot(num,pos);

	printf("value of %d after rotation is %d\n",num,ret);

	for(i=sizeof(int)*8-1;i>=0;i--)//printing binary number after rotation
		printf("%d",(ret>>i)&1);
	printf("\n");

}
