#include <stdio.h>

void put_2Darr(int a[][5], int rows)
	{
		int r, c;
		for(r=0;r<rows;r++)
			{
				for(c=0;c<5;c++)
					{
						if(r==0)
							printf("%d   ", a[r][c]);
						else printf("%d  ", a[r][c]);
					}
				printf("\n\n\n");
			}
	}

void double_2Darr(int a[][5], int rows)
	{
		int r, c;
		for(r=0;r<rows;r++)
			{
				for(c=0;c<5;c++)
					a[r][c]*=2;
			}
	}	

int main()
	{
		int aaa[3][5]={
					  {1, 2, 3, 4 ,5},
					  {6, 7, 8, 9, 10},
					  {11, 12, 13, 14, 15}	
					  };
		double_2Darr(aaa, 3);
		put_2Darr(aaa, 3);	  
	}
