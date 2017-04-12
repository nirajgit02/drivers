
#include<stdio.h>
#include"file.c"

extern int count;// only declared

void write_extern(void)
{
	count=5;
	printf("count is %i\n", count);
}


int main()
{
	write_extern();
}
