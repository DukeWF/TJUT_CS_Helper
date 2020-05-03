#include <stdio.h>

void del_spaces(char *s)
	{
		while(*s!='\0')
			{
				if(*s==' ')
					{
						char *p=s;
						for(;*(p+1)!='\0';p++)
							{
								*p = *(p+1);
							}
						*p = '\0';		
					}
				s++;
			}
	}
int main()
	{
		char str[200];//声明一个大数组
		
		gets(str);
		
		del_spaces(str);
		
		puts(str);
		
		
	}	
