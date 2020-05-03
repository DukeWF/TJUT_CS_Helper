/********************ATM机模拟程序********************/ 
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
	{	printf("请稍后......\n");
		system("pause");
		system("cls"); 
		printf("欢迎使用TJUT·ATM自助柜员机\n");
		printf("a.存款\tb.取款\n");
		printf("c.查询\tq.退出\n");
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
				printf("请输入选项a, b, c, 退出请输入q\n");
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
					printf("本机仅能操作100元为基准的金额，请重新输入:");
									
			}	
		return input;	
	}	
int get_key()
	{
		int key;
		printf("欢迎使用TJUT·ATM柜员机\n");
		printf("请插入您的卡，并输入密码，完成后请按确认！");
		printf("请输入6位密码:");
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
						printf("请输入存款数值:");
						x = get_int();
						printf("存款成功！\n");
						break;
						case'b':
						printf("请输入取款数值:");
						x = get_int();
						printf("取款成功！\n");
						break;
						case'c':
						printf("您当前账户余额为XXXX\n");
						break;
						case'q':
						printf("感谢使用TJUT·ATM自助柜员机，再见");
						break;
						default:
						printf("您的操作有误，请重试！\n");
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
                     		printf("密码错误，请重新输入!");
                     		system("cls"); 
                     		printf("您还有%d次机会！",2-error);
                     		++error;
                     		//delay(p);
                   			};
						break;
					}
			}
	}
	}
}
