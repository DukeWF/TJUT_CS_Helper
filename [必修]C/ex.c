#include <stdio.h>
#include <string.h>
void main()
	{
		int a[4]={0,1,2,3};
		int *p;
		p=a[0];
		printf("%d\n", p);
		printf("%p", a++);
	} 
