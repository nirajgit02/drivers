
//program to remove the comments

#include<stdio.h>

int main(int argc,char** argv)
{
	char ch;
	FILE *sp,*dp;//src_ptr and dest_ptr respectively 

	if(argc!=2)
	{
		printf("usage:a.out filename\n");
		return;
	}

	sp=fopen(argv[1],"r");//open target/src file having comments
	if(sp==0)//if file is not present
	{
		printf("%s is not present\n",argv[1]);
		return;
	}
	printf("%s is present\n",argv[1]);	

	dp=fopen("data.c","w");//open destination file

	while((ch=fgetc(sp))!=EOF)//copying the program to another file without comments
	{
		if(ch=='/')
		{
			ch=fgetc(sp);
			if(ch=='/')
			{
				do
				{
					ch=fgetc(sp);
				}while(ch!='\n');
			}
			else
			{
				fseek(sp,-2,SEEK_CUR);
				ch=fgetc(sp);
				fputc(ch,dp);
				ch=fgetc(sp);
				fputc(ch,dp);
			}		
		}
		else
		{
			fputc(ch,dp);
		}

	}
	remove(argv[1]);//removing old file having comments
	printf("comment are removed from %s \n",argv[1]);
	rename( "data.c",argv[1]);//renaming new copied file without comments as olde file name

}
