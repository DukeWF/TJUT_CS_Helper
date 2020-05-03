#include <stdio.h>
#include <stdlib.h>
#define pause system("pause")
int main()
	{
		int a, i;
		for(a=1;a<100;a++)
			{
				if(a*a>=1000&&a*a<=9999)
				{
					
					printf("%d, %d\n", a, a*a);
					pause;
				}
			}
		return 0;
	} 
