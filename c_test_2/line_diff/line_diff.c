
// program to compare two files and print the first line where they differ


#include<stdio.h>

int main()
{
	FILE *fd1,*fd2;	
	char ch1,ch2;
	int count=0;
	fd1=fopen("data1","r");//open data1 file in read mode
	if(fd1==0)
	{
		perror("data1");
		return;
	}

	perror("data1");

	fd2=fopen("data2","r");//open data2 file in read mode
	if(fd2==0)
	{
		perror("data2");
		return;
	}

	perror("data2");

	while(((ch1=fgetc(fd1))!=EOF)&&((ch2=fgetc(fd2))!=EOF))//fetching character in ch1 & ch2 from both file resp. till EOF
	{

		if(ch1==ch2)//if both characters are same incriment count
		{
			count++;	  
			if((ch1=='\n')&&(ch2=='\n'))//when new line encounters reset count to 1
			{
				count=1;

			}
		}
		else
		{
			break;
		}


	}
	count=-count;

	fseek(fd1,count,SEEK_CUR);//moving file ptr to starting of present line in data 1
	fseek(fd2,count,SEEK_CUR);//moving file ptr to starting of present line in data 2

	printf("line of %s file:\n","data1");

	while((ch1=fgetc(fd1))!=EOF)//print a line of 1st file where it differs
	{
		if(ch1=='\n')
			break;
		else
			printf("%c",ch1);
	}	
	printf("\n");

	printf("line of %s file:\n","data2");

	while((ch2=fgetc(fd2))!=EOF)//print a line of 2nd file where it differs
	{
		if(ch2=='\n')
			break;	
		else
			printf("%c",ch2);
	}
	printf("\n");

}
