
//to count the number of 1's bits in given number 
#include<stdio.h>

int main()
{
	int num,count=0;

	printf("enter a value\n");
	scanf("%d",&num);

	while(num)
	{
		if(num&1)//doing bitwise & operation with number to know statut of 0th bit
		{
			count++;
		}
		num=num>>1;
	}

	printf("number of 1's in given value is %d\n",count);


}
