#include <stdio.h>

void fun(int a[][3], int rows)
	{
		int r, c;
		for(r=0; r<rows; r++)
			{
				int sum=0;
				for(c=0; c<3; c++)
					sum+=a[r][c];
				printf("%d\n", sum/3);
			}
	}

int main()
	{
		int aaa[3][3]={
						{1, 2, 3},
						{4, 5, 6},
						{7, 8, 9}
					  };
		fun(aaa, 3);
	}	
