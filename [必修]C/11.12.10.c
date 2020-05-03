#include <stdio.h>
char *pc(char *str)
{
	while(*str != '\0'&& *str != ' ')
		str++;
	if(*str == '\0')
		return NULL;
	else
		return str;
}
int main()
	{
		char str[100];
		gets(str);
		pc(str);
		
		printf("%p", pc(str));
		
	}
