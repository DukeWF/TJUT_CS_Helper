#include <stdio.h>
char *match_str(char *s, char *t)
	{
		while(*s!='\0')
			{
				char *p, *q;
				p=s;
				q=t;
				while(*p==*q&&*p!='\0'&&*q!='\0')
					{
						p++;
						q++;
					}
				if(*q=='\0')
					return s;	
				
				s++;	
			}
		return NULL;	
	}
int main()
	{
		char str1[100];
		char str2[100];
		gets(str1);
		gets(str2);
		
		char *t;
		t = match_str(str1, str2);
		if(t!=NULL)
			puts("found it");
		else puts("None");
		
	}	 
