#include <stdio.h>
void input(double a[][5], int rows);
void ave_arr(double a[][5], int rows, double av[]);
double ave(double a[][5], int rows);
double max(double a[][5], int rows);
void output(double a[][5], int rows);

void input(double a[][5], int rows)
	{
		int i, j;
		for(i=0;i<rows;i++)
			for(j=0;j<5;j++)
				scanf("%f", &a[i][j]);
	}
void ave_arr(double a[][5], int rows, double av[])
	{
		int i, j;
		for(i=0; i<rows; i++)
			{
				double sum=0.0;
				for(j=0;j<5;j++)
					sum+=a[i][j];
				av[i]=sum/5;
			}
	}	
double max(double a[][5], int rows)
	{
		int i, j;
		double max=a[0][0];
		for(i=0; i<rows; i++)
			for(j=0; j<5; j++)
				if(max<a[i][j])
					max=a[i][j];				
	}
void output(double a[][5], int rows)
	{
		int i, j;
		for(i=0;i<rows;i++)
			{		
				for(j=0;j<5;j++)
					printf("%d", a[i][j]);
				puts("\n");
	 		}	
	}
int main()
	{
		double value[3][5];
		double ave[3];
		input(value, 3);
		ave_arr(value, 3, ave);
		output(value, 3);
	}
