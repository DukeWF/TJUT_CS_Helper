#include <stdio.h>
#define N 20
float trans(int x, int y);

float trans(int x, int y)
	{
		float z=0;
		int i, t;
		for(i=0;i<N;i++)
			{
				z+=(float)x/y;
				t=x;
				x=x+y;
				y=t;
				printf("x==>%d y==>%d z=%f\n",x,y,z);				
			}
		printf("%f", z);
//		return z;
	}
int main()
	{
		float z;
		int x=2, y=1;
		trans(x, y);
	} 
