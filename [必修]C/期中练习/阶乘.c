//�Ӽ�������������n,��n�������
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
