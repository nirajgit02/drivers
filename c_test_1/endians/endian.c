//program to check system is little endian or big endian

#include<stdio.h>

int main()
{
	int num=10;
	char *ptr;
	ptr=&num;//pointer to int variable

	if(*ptr==10)
		printf("little endian\n");
	else
		printf("big endian\n");

}
