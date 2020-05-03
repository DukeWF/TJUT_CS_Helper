//键盘上输入n个数,输出最大值最小值.
#include <stdio.h>
#define N 100

int main()
	{
		int n, i, max, min;		//定义变量 
		int A[N] = {0};			//初始化数组A[N] 
		/*	*/ 
		printf("请输入比较数字个数（小于%d）：", N);
		scanf("%d", &n);
		
		for(i=0;i<n;i++)
			{
				printf("\n请输入第%d个数字：", i+1);
				scanf("%d", &A[i]);
			}
		/*	*/ 
		max=min=A[0];//初始化最大值最小值 
		for(i=0;i<n;i++)
			{
				if(A[i]>max)
					max=A[i]; 				
			}
		for(i=0;i<n;i++)
			{
				if(A[i]<min)
					min=A[i]; 				
			}	
		printf("这%d个数中最大的数为：%d\n", n, max); 
		printf("这%d个数中最小的数为：%d\n", n, min);
		
		return 0;		
	}
