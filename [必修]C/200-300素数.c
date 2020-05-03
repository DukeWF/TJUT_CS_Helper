#include <stdio.h>
#include <math.h>

int main()
	{
		int n, i, k;
		int flag, count=0;
		for(n=201;n<=299;n+=2)
			{
				flag=1;
				k=(int)sqrt(n);
				for(i=2;i<=k;i++)
					if(n%i==0)
						{
							flag=0;
							break;
						}
				if(flag)
					{
						count++;
						printf("%5d", n);
						if(count%4==0)
							printf("\n");
					}		
			}
		printf("\n");	
	} 
	
