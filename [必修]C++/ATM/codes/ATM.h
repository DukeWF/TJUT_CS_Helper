#ifndef ATM_H
#define ATM_H
#define CLS system("cls")
#define PAUSE system("pause")

#include "customer.h"
#include <conio.h>

class ATM{
	public:
//拷贝构造函数：拷贝构造customer，用于操作测试（伪操作）ver 1.0 
		ATM(customer& c):cm(c){
			show_information();
		}
//菜单函数：显示菜单与交互操作
		void welcome();
		void menu();
//功能函数：实现对应功能	
		void deposit();
		void withdraw();
		void transfer();
		void change_pw();
//显示函数：格式化输出对应内容
		void show_deposit();
		void show_deposit(int mo);
		void show_withdraw();
		void show_withdraw(int mo);
		void show_withdraw(int mo, int i);
		void show_transfer(int i);
		void show_transfer(int mo, int id, int i);
		void show_money();
		void show_menu();
		void show_information();
//判断函数：判断逻辑正误		
		int judge_num();//判断整100数字正误，最终获得正确数值 
	protected:
		customer cm;
};

#endif
