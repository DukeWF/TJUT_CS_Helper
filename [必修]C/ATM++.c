/********************ATM机模拟程序********************/ 
/*Copyright 1997-2016 Tony Wang. All Rights Reserved.*/ 
/*********本程序充满BUG，还请老师指点o(^▽^)o*********/
/*目前已知BUG：
1.主菜单切换时可能存在错误 
2.存取款时，数据可能会溢出 
3.密码形同虚设，输入任意数字均能进入
4.本程序初始设定余额为10000元，但是取款时可能存在小于10000元也提示余额不足的情况 
/*****************************************************/
#include <stdio.h>
#include <stdlib.h>
void show_choice()
	{	system("pause");
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
char get_choice()//获取正确输入选项（有BUG） 
	{
		char ch;
		ch = get_first();
		getchar();
		if(ch!='a'&&ch!='b'&&ch!='c'&&ch!='q')
			{
				printf("请输入选项a, b, c, 退卡请输入q\n");
				get_choice();
			}
		return ch;	
	}
int get_int()//获取100倍数的整数 
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
	
int get_key()//密码获取（有BUG，返回key值还没有加入main） 
	{
		int key;
		printf("欢迎使用TJUT·ATM柜员机\n");
		printf("请插入您的银行卡，并输入密码，完成后请按确认！");
		printf("\n请输入6位密码:");
		scanf("%d",&key);
		return key; 
	}
int main()
	{
		int input, key; 
		long int money = 10000;//初始10000元 
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
								printf("您当前账户余额为%ld元\n", money);
								show_choice();
								break;
					}
					getchar();
			}
		printf("请收好您的卡片\n感谢使用，再见!");
		return 0;	 
	}

