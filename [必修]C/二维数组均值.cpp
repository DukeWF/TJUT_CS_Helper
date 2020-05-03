#include <stdio.h>
int main()
	{
		int r, c, sum;//r行c列 
		double ave;
		sum=0;
		int a[3][3]=
			{
				{1,2,3}, 
				{4,5,6},
				{7,8,9},
			};
		for(r=0;r<3;r++)
			{
				for(c=0;c<3;c++)
					{
						sum+=a[r][c];
					}
				ave=1.0*sum/3;
				sum=0;//初始化sum 
				printf("第%d行均值为%f\n", r+1, ave);
			}
	}
