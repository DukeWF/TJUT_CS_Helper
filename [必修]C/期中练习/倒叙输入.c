//�Ӽ�������һ������Ȼ�������
#include <stdio.h>
#define N 200
int main()
	{
		char A[N];
	 	int i;
	 	
		scanf("%s", A);
		
		printf("%s",A[N]);
		for(i=0;;i++)//����ַ������� 
			{	
				if(A[i]=='\0')// \0��ʲô��˼?
					break;				
			} 
		printf("�������Ϊ��");
		for(i=i-1;i>=0;i--) 
			{
				printf("%c",A[i]);
			}
	} 
