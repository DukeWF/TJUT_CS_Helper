#include <stdio.h> 	
#define IN	1
#define OUT	0
int main()
{
	printf("������һ�λ���\1:\n");
	 
		char a;
		int nb=0;
		int nc=0;
		int nd=0;
		int state=OUT;
				
		while((a=getchar())!=EOF){
				++nb;
			if(a=='\n')
				++nc;	
			if(a ==' ' || a=='\n' ||a=='\t')
				state=OUT;
			else if (state==OUT){
				state =IN;
				++nd;
			}		
		}
		printf("2.����һ����%d���ַ�\n",nb);
		printf("3.����һ����%d��\n",nc) ;
		printf("4.����һ��%d�����ʣ�\1\1\1\n",nd);
		printf("\1��ѧ��ѧ������һ���ٵ��ļ��ڿ��֣�");		
		
		
}
