#include <stdio.h>
//������ԭ������ 
void show_choice();
char get_first();
char get_choice();
float get_float();
//����ʵ��ѡ���ӡ/����ַ�/��𸡵��� 
void show_choice()
	{
		printf("Enter the operation of your choice:\n");
		printf("a.add      s.subtract\n");
		printf("m.multiply d.divede\n");
		printf("q.quit\n");		
	}
char get_first()
	{
		int ch;
		ch = getchar();
		while(getchar()!= '\n')
			continue;
		return ch;
	}
char get_choice()
	{
		char ch;
		
		show_choice();//����ʱ��ʾ�˵�
		ch = get_first();
		while(ch!='a'&&ch!='s'&&ch!='m'&&ch!='d'&&ch!='q')
			{
				printf("��������ȷ��ѡ�a��s��m��d��q\n");
				show_choice();//����ʱ��ʾ�˵�
				ch = get_first();
			}
		return ch;
	}
float get_float()
	{
		float input;
		char ch;
		
		while(scanf("%f", &input)!=1)//scanf()����ֵΪ�ɹ���ȡ��Ŀ�ĸ��� 
			{
				while((ch = getchar())!='\n')//��������ַ���ʾ���� ��ֱ������ 
					putchar(ch);//�޳���������
				printf(" ����һ��������.\n������һ��������������1.0��-3.58��");					
			}
			return input;
	}
int main()
	{
		float x,y,z;
		int choice;
		//show_choice();//��ʾ�˵� 
		
		while((choice=get_choice())!='q')
			{
				switch(choice)
					{
						case'a'://�ӷ����� 
						printf("\nEnter first number:");
						x = get_float();
						printf("\nEnter second number:");
						y = get_float();
						z = x+y;
						printf("%f+%f=%f\n", x, y, z);
						break;
								
						case's'://�������� 
						printf("\nEnter first number:");
						x = get_float();
						printf("\nEnter second number:");
						y = get_float();
						z = x-y;
						printf("%f-%f=%f\n", x, y, z);
						break;		
							
						case'm'://�˷����� 
						printf("\nEnter first number:");
						x = get_float();
						printf("\nEnter second number:");
						y = get_float();
						z = x*y;
						printf("%f*%f=%f\n", x, y, z);
						break;		
							
						case'd'://�������� 
						printf("\nEnter first number:");
						x = get_float();
						printf("\nEnter second number:");
						y = get_float();
						while(y==0)//�ж��ڶ������Ƿ�Ϊ�� 
							{
								printf("\nEnter a number other than 0:");
								y = get_float();								
							} 
						z = x/y;
						printf("%f/%f=%f\n", x, y, z);
						//default:printf("WARNING!\a");
						break;		
						
					}
			}
		
	}
	
	
	
	
	
	
	
	
	
	
