#include <stdio.h>
int strlen(char *str);

int main(void)
{
	char note[100];
	gets(note);
	printf("the length of note is %d\n",strlen(note));
	return 0;
}

int strlen(char *str)
{
	int count = 0; 
	while(*str++)
		{
			count++;
		}
	return count;
}
 
