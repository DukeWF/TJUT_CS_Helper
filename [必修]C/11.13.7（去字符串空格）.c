#include <stdio.h>
#include <string.h>
void del_blanks(char *s);
/*主函数*/ 
void del_blanks(char *s)
	{
		while(1)
			{
				while(*s!='\t'&&*s!=' '&&*s!='\0') 
					s++;
				if(*s==' ')
					{
						char *p;
						for(p=s;*(p+1)!='\0';p++)
							{
								*p = *(p+1);
							}
						*p = '\0';	
					}
				else 
					return;	
			}				
	}
int main()
	{
		char str[200];//声明一个大数组
		
		gets(str);
		
		del_blanks(str);
		
		puts(str);
		
		
	}

