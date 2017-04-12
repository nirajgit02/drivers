
//program for strncpy() strncat() strncmp()

#include<stdio.h>
#include<string.h>
/**********************************************************************
NAME:str_ncpy
PARAMETERS:char*,const char*,int
RETURN VALUE:char*
DESCRIPTION:concates first n bytes from source to destination
***********************************************************************/
char* str_ncat(char* dest,const char *src,int s)//to concate x characters of the strings
{
	char* i=dest;

	while(*dest++);
	--dest;
	while(s--)
		*dest++=*src++;	
	*dest='\0';

	return i;
}

/**********************************************************************
NAME:str_ncpy
PARAMETERS:char*,const char*,int 
RETURN VALUE:char*
DESCRIPTION:copies first n bytes from source string to destination 
***********************************************************************/
char* str_ncpy(char* dest,const char *src,int s)
{
	char *i=dest;
	while(s--)
		*dest++ = *src++;
	*dest='\0';	

	return i;
}

/**********************************************************************
NAME:str_ncmp
PARAMETERS:const char*,const char*,int
RETURN VALUE:none
DESCRIPTION:compares first n bytes of two strings
***********************************************************************/
void str_ncmp(const char* dest,const char* src,int s)//function to compare x characters of string
{

	while(--s)
	{
		if(*dest!=*src)
			break;
		else
		{
			dest++;
			src++;
		}
	}

	if(*dest==*src)
		printf("string is equal\n");
	else
		printf("strint is not equal\n");

}


int main()
{
	char str1[20],str2[20],*ret;
	int n,len1,len2;//length of str1 and str2 respectively

	printf("enter the str1 and str2\n");
	scanf("%s%s",str1,str2);
	printf("enter the number of characters u want to compare\n");
	scanf("%d",&n);

	len1=strlen(str1);
	len2=strlen(str2);

	if(n>len1 || n>len2)//if characters to be compared is more than one of string lengths
	{
		printf("n value exceeds length of string\n");
		return;
	}
	if(n<=0)//if number if characters to be compared is entered negative
	{
		printf("pls enter positive value of n\n");
		return;
	}

	printf("\n");
	printf("string compare:->");
	str_ncmp(str1,str2,n);//to compare two strings

	ret=str_ncpy(str1,str2,n);//to copy src string to dest string
	printf("string copy:->");
	printf("%s\n",ret);

	ret=str_ncat(str1,str2,n);//to concate src string to dest string
	printf("string concate:->");
	printf("%s\n",ret);

}
