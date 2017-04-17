#include<stdio.h>


int main(int argc,char** argv)
{
	FILE *fp,*fp2;
	char ch;


	if(argc!=2)
	{
		printf("usage:./aout filename\n");
		return;
	}
	fp=fopen(argv[1],"r");
	fp2=fopen("data","w");  

	while((ch=getc(fp))!=EOF)//get character till EOF
	{
		if (ch=='\n')// \n occurs 1st time
		{
			ch=fgetc(fp);
			if(ch=='\n')// \n occurs 2nd time
			{
				while((ch=getc(fp))=='\n')// till \n is there just getchar
				{
				}
	
				fseek(fp,-2,SEEK_CUR);//move fileptr 2 char back and put 2 chars
				ch=fgetc(fp);
				fputc(ch,fp2);
				ch=fgetc(fp);
				fputc(ch,fp2);
				
			}
			else
			{
				fseek(fp,-2,SEEK_CUR);
				ch=fgetc(fp);
				fputc(ch,fp2);
				ch=fgetc(fp);
				fputc(ch,fp2);

			}
		}
		else
		{
			fputc(ch,fp2);
		}
	}

	remove(argv[1]);//remove src file
	rename("data",argv[1]);//rename dest as src
	fclose(fp2);
	fclose(fp);
		
/* same steps for \t and space*/


	fp=fopen(argv[1],"r");
	fp2=fopen("data","w");  

	while((ch=getc(fp))!=EOF)
	{
		if (ch=='\t')
		{
			ch=fgetc(fp);
			if(ch=='\t')
			{
				while((ch=getc(fp))=='\t')
				{
				}
		
				fseek(fp,-2,SEEK_CUR);
				ch=fgetc(fp);
				fputc(ch,fp2);
				ch=fgetc(fp);
				fputc(ch,fp2);
				
			}
			 else
                        {
                                fseek(fp,-2,SEEK_CUR);
                                ch=fgetc(fp);
                                fputc(ch,fp2);
                                ch=fgetc(fp);
                                fputc(ch,fp2);

                        }

		}
		else
		{
			fputc(ch,fp2);
		}
	}

	remove(argv[1]);
	rename("data",argv[1]);
	fclose(fp2);
	fclose(fp);

	 fp=fopen(argv[1],"r");
        fp2=fopen("data","w");

        while((ch=getc(fp))!=EOF)
        {
                if (ch==' ')
                {
                        ch=fgetc(fp);
                        if(ch==' ')
                        {
                                while((ch=getc(fp))==' ')
                                {
                                }

                                fseek(fp,-2,SEEK_CUR);
                                ch=fgetc(fp);
                                fputc(ch,fp2);
                                ch=fgetc(fp);
                                fputc(ch,fp2);

                        }
			 else
                        {
                                fseek(fp,-2,SEEK_CUR);
                                ch=fgetc(fp);
                                fputc(ch,fp2);
                                ch=fgetc(fp);
                                fputc(ch,fp2);

                        }

                }
                else
                {
                        fputc(ch,fp2);
                }
        }

        remove(argv[1]);
        rename("data",argv[1]);
        fclose(fp2);
        fclose(fp);

}

