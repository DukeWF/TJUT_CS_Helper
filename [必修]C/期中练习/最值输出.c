//����������n����,������ֵ��Сֵ.
#include <stdio.h>
#define N 100

int main()
	{
		int n, i, max, min;		//������� 
		int A[N] = {0};			//��ʼ������A[N] 
		/*	*/ 
		printf("������Ƚ����ָ�����С��%d����", N);
		scanf("%d", &n);
		
		for(i=0;i<n;i++)
			{
				printf("\n�������%d�����֣�", i+1);
				scanf("%d", &A[i]);
			}
		/*	*/ 
		max=min=A[0];//��ʼ�����ֵ��Сֵ 
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
		printf("��%d������������Ϊ��%d\n", n, max); 
		printf("��%d��������С����Ϊ��%d\n", n, min);
		
		return 0;		
	}
