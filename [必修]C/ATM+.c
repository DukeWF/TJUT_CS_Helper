/********************ATM��ģ�����********************/ 
/*Copyright 1997-2016 Tony Wang. All Rights Reserved.*/ 
/*****************************************************/
#include <stdio.h>
#include <stdlib.h>
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
		char ch;
		ch = getchar();
/*		while(getchar()!='\n')
			continue;
*/
		return ch;	
	}
char get_choice()
	{
		char ch;
		ch = get_first();
		getchar();
		if(ch!='a'&&ch!='b'&&ch!='c'&&ch!='q')
			{
				printf("������ѡ��a, b, c, �˳�������q\n");
				get_choice();
			}
		return ch;	
	}
int get_int()
	{
		int input;
		scanf("%d",&input);
		if(input%100!=0)
			{
				printf("�������ܲ���100ԪΪ��׼�Ľ�����������:");
				get_int();
			}
		return input;	
	}
	
void get_key()
	{
		int key,i;
		printf("������6λ����:");
		scanf("%d",&key);
	}
int main()
	{
		int input; 
		long int money = 100000;
		get_key();
		show_choice();
		getchar();
		char choice;
		while((choice=get_choice())!='q')
			{
				switch(choice)
					{
						case'a':
								printf("����������ֵ:\n");
								get_int();
								money += input; 
								printf("���ɹ���\n");
								show_choice();
								break;
						case'b':
								printf("������ȡ����ֵ:");
								get_int();
								while(input > money)
								{
									printf("�������㣬���������룡\n");																	
									input = get_int();									
								}
								money -= input;
								printf("ȡ��ɹ���\n");
								show_choice();
								break;
						case'c':
								printf("����ǰ�˻����Ϊ%ld\n", money);
								show_choice();
								break;
					}
					getchar();
			}
		printf("��лʹ�ã��ټ�!");
		return 0;	 
	}

