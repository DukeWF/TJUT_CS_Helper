//从键盘输入一整数，然后反向输出
#include <stdio.h>
#define N 200
int main()
	{
		char A[N];
	 	int i;
	 	
		scanf("%s", A);
		
		printf("%s",A[N]);
		for(i=0;;i++)//求得字符串长度 
			{	
				if(A[i]=='\0')// \0是什么意思?
					break;				
			} 
		printf("倒序输出为：");
		for(i=i-1;i>=0;i--) 
			{
				printf("%c",A[i]);
			}
	} 
