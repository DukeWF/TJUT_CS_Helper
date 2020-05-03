#include <stdio.h>
int main()
	{
		int r, c;//r––c¡– 
		int a[3][3]=
			{
				{1,2,3}, 
				{4,5,6},
				{7,8,9},
			};
		int b[3][3]=
			{
				{9,8,7},
				{6,5,4},
				{3,2,1},				
			};
		int t[3][3];
		for(r=0;r<3;r++)
			{
				for(c=0;c<3;c++)
					{
						t[r][c]=a[r][c]+b[r][c];
						printf("%d ", t[r][c]);
					}
				printf("\n");
			}
	} 
