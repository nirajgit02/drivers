#include<stdio.h>
#include<string.h>
int main(int argc,char** argv)
{
	FILE *fd;
	int total=0,op=10,diff=0,i=0;
	char arry[10],ch;



	if((argc!=3)&&(argc!=2))
	{
		printf("usage:./a.out -[option] filename\n");
		return;
	}



	if(argv[1][0]=='-')
	{
		fd=fopen(argv[2],"r");

		if(fd==0)
		{
			perror("file");
			return;
		}
		strcpy(arry,argv[1]);

		for(i=0;arry[i];i++)
			arry[i]=arry[i+1];

		op=atoi(arry);//converting string to integer

	}
	else
	{
		fd=fopen(argv[1],"r");

		if(fd==0)
		{
			perror("file");
			return;
		}
	}


	printf("option equals:%d\n",op);


	while((ch=fgetc(fd))!=EOF)//counting total no of lines
	{
		if(ch=='\n')
			total++;
	}	
	rewind(fd);//pointing file pointer to starting of file

	printf("total lines equals:%d\n",total);
	diff=total-op;
	i=0;
	printf("difference equals:%d\n",diff);
	while((ch=fgetc(fd))!=EOF)//printing last n lines
	{
		if(i<diff)
		{
			if(ch=='\n')
				i++;
		}
		else
		{
			printf("%c",ch);
		}

	}
	while(1);

}
