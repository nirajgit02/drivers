//to print process id, parent id and group id 

#include<stdio.h>

int main()
{

	printf("parent id is: %d\nprocess id is:%d\ngrp id is:%d\n",getppid(),getpid(),getgid());
}
