#include <stdio.h>
char *string_in(char *p1,char *p2);
int main(void)
{
	char s1[81];
	char s2[81];
	char *p;
	do{
		puts("input string 1:");
		gets(s1);		
		puts("input string 2:");
		gets(s2);
		p = string_in(s1,s2);
		if(p)
		{
			puts("Find!");
			puts(p);
		}
		else
			puts("Can not find!");
		puts("input y to go on (q to guit):");
		gets(s2);
	}while(*s2 != 'q');
	puts("Well done!");
	return 0;
}
char *string_in(char *p1,char *p2)
{
	char *p1_save = p1, *p2_save = p2;
	if(*p1 == '\0' || *p2 == '\0')
		return NULL;
	while(1)
	{
		if(*p1 == *p2)
		{
			if(*++p2 == '\0')
				return p1_save;
			if(*++p1 == '\0')
				return NULL;
		}
		else
		{
			if(*++p1 == '\0')
				return NULL;
			p1_save = p1;
			p2 = p2_save;
		}
	}
}

