#include<stdio.h>
#include<string.h>

int main(int argc,char** argv)//taking input from command line argument
{
	char str[200],ch;
	int l_size=0,count=0;//l_size is size of longest line
	FILE* file_ptr;

	if(argc!=3)
	{
		printf("usage:./a.out filename string\n");
		return;
	}
	file_ptr=fopen(argv[1],"r");
	
	if(file_ptr==0)
	{
		printf("%s file is not present\n",argv[1]);
		return;
	}
	printf("%s file is present\n",argv[1]);

	while((ch=fgetc(file_ptr))!=EOF)//to count size of largest line
	{
		if(ch!='\n')
			count++;
		else
		{
			if(count>l_size)
				l_size=count;
			count=0;
		}
	}
	
	rewind(file_ptr);

	while(fgets(str,l_size+1,file_ptr))//printing the line with the matching string
		if (strstr(str,argv[2]))
			printf("%s",str);

}
