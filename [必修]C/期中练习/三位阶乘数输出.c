//求这样一个三位数，该三位数等于其每位数字的阶乘之和
#include <stdio.h>
int fun(int x);
/*求a的阶乘*/
int fun(int x)
	{
		int fac, i;
		for(i=fac=1;i<=x;i++)
			fac *= i;
		return fac;
	}
int main()
	{
		int n;
		for(n=100;n<1000;n++) 
			{
				if(n==fun(n%10)+fun((n/10)%10)+fun((n/100)))
				printf("%d\n",n);
			}
		return 0;
	}
