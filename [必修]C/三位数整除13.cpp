#include <stdio.h>

int main()
	{
		int i;
		int t=0;
		for(i=100;i<999;i++)
			{
				if(i%17==0)
					t++;
			}
		printf("%d", t);
	} 
