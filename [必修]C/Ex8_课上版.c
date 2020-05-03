#include <stdio.h>
//函数的原型声明 
void show_choice();
char get_first();
char get_choice();
float get_float();
//函数实现选项打印/甄别字符/甄别浮点数 
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
		
		show_choice();//错误时显示菜单
		ch = get_first();
		while(ch!='a'&&ch!='s'&&ch!='m'&&ch!='d'&&ch!='q')
			{
				printf("请输入正确的选项：a，s，m，d，q\n");
				show_choice();//错误时显示菜单
				ch = get_first();
			}
		return ch;
	}
float get_float()
	{
		float input;
		char ch;
		
		while(scanf("%f", &input)!=1)//scanf()返回值为成功读取项目的个数 
			{
				while((ch = getchar())!='\n')//将输入的字符显示出来 ，直到换行 
					putchar(ch);//剔除错误输入
				printf(" 不是一个浮点数.\n请输入一个浮点数，例如1.0，-3.58：");					
			}
			return input;
	}
int main()
	{
		float x,y,z;
		int choice;
		//show_choice();//显示菜单 
		
		while((choice=get_choice())!='q')
			{
				switch(choice)
					{
						case'a'://加法运算 
						printf("\nEnter first number:");
						x = get_float();
						printf("\nEnter second number:");
						y = get_float();
						z = x+y;
						printf("%f+%f=%f\n", x, y, z);
						break;
								
						case's'://减法运算 
						printf("\nEnter first number:");
						x = get_float();
						printf("\nEnter second number:");
						y = get_float();
						z = x-y;
						printf("%f-%f=%f\n", x, y, z);
						break;		
							
						case'm'://乘法运算 
						printf("\nEnter first number:");
						x = get_float();
						printf("\nEnter second number:");
						y = get_float();
						z = x*y;
						printf("%f*%f=%f\n", x, y, z);
						break;		
							
						case'd'://除法运算 
						printf("\nEnter first number:");
						x = get_float();
						printf("\nEnter second number:");
						y = get_float();
						while(y==0)//判定第二个数是否为零 
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
	
	
	
	
	
	
	
	
	
	
