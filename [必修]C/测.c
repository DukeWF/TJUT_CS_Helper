#include <stdio.h> 	
#define IN	1
#define OUT	0
int main()
{
	printf("请输入一段话吧\1:\n");
	 
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
		printf("2.这里一共有%d个字符\n",nb);
		printf("3.这里一共有%d行\n",nc) ;
		printf("4.这里一共%d个单词！\1\1\1\n",nd);
		printf("\1给学长学姐送来一个迟到的假期快乐！");		
		
		
}
