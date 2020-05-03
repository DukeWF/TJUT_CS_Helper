//从键盘输入正整数n,求n！并输出
#include <stdio.h>
int main()
	{
		int sum, i, n;
		sum = 1;
		printf("n=");
		scanf("%d", &n); 
		
		for(i=1;i<=n;i++)
			sum*=i;
		printf("\nn!=%d", sum);
		return 0;
	}
