//������һ����λ��������λ��������ÿλ���ֵĽ׳�֮��
#include <stdio.h>
int fun(int x);
/*��a�Ľ׳�*/
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
