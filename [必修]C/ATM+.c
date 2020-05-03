/********************ATM机模拟程序********************/ 
/*Copyright 1997-2016 Tony Wang. All Rights Reserved.*/ 
/*****************************************************/
#include <stdio.h>
#include <stdlib.h>
void show_choice()
	{	printf("请稍后......\n");
		system("pause");
		system("cls"); 
		printf("欢迎使用TJUT·ATM自助柜员机\n");
		printf("a.存款\tb.取款\n");
		printf("c.查询\tq.退出\n");
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
				printf("请输入选项a, b, c, 退出请输入q\n");
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
				printf("本机仅能操作100元为基准的金额，请重新输入:");
				get_int();
			}
		return input;	
	}
	
void get_key()
	{
		int key,i;
		printf("请输入6位密码:");
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
								printf("请输入存款数值:\n");
								get_int();
								money += input; 
								printf("存款成功！\n");
								show_choice();
								break;
						case'b':
								printf("请输入取款数值:");
								get_int();
								while(input > money)
								{
									printf("您的余额不足，请重新输入！\n");																	
									input = get_int();									
								}
								money -= input;
								printf("取款成功！\n");
								show_choice();
								break;
						case'c':
								printf("您当前账户余额为%ld\n", money);
								show_choice();
								break;
					}
					getchar();
			}
		printf("感谢使用，再见!");
		return 0;	 
	}

