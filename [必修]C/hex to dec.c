#include <stdio.h>
long int hex_to_dec(char *s)
	{
		long int t=0;
		int x;
		while(*s!='\0')
			{
				t*=16;
				if(*s>='0'&&*s<='9')
					x = *s-'0';
				else if(*s>='A'&&*s<='F')
					x = 10 + *s -'A';
				t+=x;
				s++;	
			}
		return t;
	}
int main()
	{
		char hex[100];
		gets(hex);
		printf("%d", hex_to_dec(hex));
	}
