/********************ATM��ģ�����********************/ 
/*Copyright 1997-2016 Tony Wang. All Rights Reserved.*/ 
/*****************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
void show_choice();
char get_first();
char get_choice();
int get_int();
int get_key();
void show_choice()
	{	printf("���Ժ�......\n");
		system("pause");
		system("cls"); 
		printf("��ӭʹ��TJUT��ATM������Ա��\n");
		printf("a.���\tb.ȡ��\n");
		printf("c.��ѯ\tq.�˳�\n");
	}
char get_first()
	{
		int ch;
		ch = getchar();
		while(getchar()!='\n')
			continue;
		return ch;	
	}
char get_choice()
	{
		int ch;
		ch = get_first();
		while(ch!='a'&&ch!='b'&&ch!='c'&&ch!='q')
			{
				printf("������ѡ��a, b, c, �˳�������q\n");
				ch = get_first(); 
			}
		return ch;	
	}
int get_int()
	{
		int input;
		char ch;
		while(scanf("%d",&input)!=1);
			{
				while((ch=getchar())!='\n'&&input%100!=0)						
					putchar(ch);
					printf("�������ܲ���100ԪΪ��׼�Ľ�����������:");
									
			}	
		return input;	
	}	
int get_key()
	{
		int key;
		printf("��ӭʹ��TJUT��ATM��Ա��\n");
		printf("��������Ŀ������������룬��ɺ��밴ȷ�ϣ�");
		printf("������6λ����:");
		scanf("%d",&key);
		system("pause");
		return key; 
	}
void homepage()
	{
		get_key();
		show_choice();
		int choice, x;
//		system("pause");
		while((choice=get_choice())!='q')
			{
				switch(choice)
					{
						case'a':
						printf("����������ֵ:");
						x = get_int();
						printf("���ɹ���\n");
						break;
						case'b':
						printf("������ȡ����ֵ:");
						x = get_int();
						printf("ȡ��ɹ���\n");
						break;
						case'c':
						printf("����ǰ�˻����ΪXXXX\n");
						break;
						case'q':
						printf("��лʹ��TJUT��ATM������Ա�����ټ�");
						break;
						default:
						printf("���Ĳ������������ԣ�\n");
						break;
					}
			}
int main()
	{
		int error = 0;
		while(1)
			{
				if(error<3)
					{
						system("cls"); 
						switch(choice)
           				{
           				case 123456:
						homepage();
						break;
           				default:
                   			{
                     		system("cls"); 
                     		printf("�����������������!");
                     		system("cls"); 
                     		printf("������%d�λ��ᣡ",2-error);
                     		++error;
                     		//delay(p);
                   			};
						break;
					}
			}
	}
	}
}
